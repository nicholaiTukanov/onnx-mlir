/*
 * SPDX-License-Identifier: Apache-2.0
 */

//===------- ONNXPreKrnlVerifyPass.cpp - Verification -------------------===//
//
// Copyright 2019-2020 The IBM Research Authors.
//
// =============================================================================
//
// This file implements a Function level pass that verifies whether
// ONNX ops in the function are ready for lowering to Krnl.
//
//===----------------------------------------------------------------------===//

#include <vector>
#include <set>

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/Interfaces/CallInterfaces.h"
#include "mlir/Pass/Pass.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Support/raw_ostream.h"

#include "mlir/IR/OpImplementation.h"


#include "src/Dialect/Krnl/KrnlOps.hpp"
#include "src/Dialect/ONNX/ONNXOps.hpp"
#include "src/Interface/ShapeInferenceOpInterface.hpp"
#include "src/Dialect/ONNX/ShapeInference/ONNXShapeHelper.hpp"
#include "src/Pass/Passes.hpp"

using namespace std;

using namespace mlir;

typedef uint64_t dim_t;


namespace {

/*!
 * This pass verify whether each ONNX op is ready for Krnl
 * The current condition is that all input tensors have to be ranked
 */

class ONNXPrintSMaLLPass : public mlir::PassWrapper<ONNXPrintSMaLLPass,
                                  OperationPass<func::FuncOp>> {

public:
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(ONNXPrintSMaLLPass)

  StringRef getArgument() const override { return "onnx-print-small"; }

  StringRef getDescription() const override { return "Print small equalivalent onnx op calls in C."; }

  std::map<std::string, int> legal_small_ops = {
    {"Conv",0}, 
    {"MaxPool",1}, 
    {"AvgPool",2}, 
    {"Relu",3}
  };
  std::vector<std::string> small_c_funcs = {
    "Conv2D", 
    "Maxpool2D", 
    "Avgpool2D", 
    "ReLUActivation"
  };

  typedef struct {
    dim_t lay_num;
    dim_t k_size;
    dim_t stride;
    std::string pad;
    dim_t out_c;
    dim_t in_c;
    dim_t in_h;
    dim_t in_w;
    float *in_ptr;
    float *filt_ptr;
    float *out_ptr; 
  } SMaLLConv;

  typedef struct {
    dim_t lay_num;
    dim_t k_size;
    dim_t stride;
    std::string pad;
    dim_t in_c;
    dim_t in_h;
    dim_t in_w;
    float *in_ptr;
    float *out_ptr; 
  } SMaLLPooling;

  typedef struct {
    dim_t lay_num;
    dim_t in_c;
    dim_t in_h;
    dim_t in_w;
    float *in_ptr;
    float *out_ptr; 
  } SMaLLRelu;

  
  void runOnOperation() override {
    auto function = getOperation();
    auto &funcBody = function.getBody();

    // Iterate on the operations
    for (Operation &op : funcBody.getOps()) {
      if (isa<mlir::ONNXDialect>(op.getDialect())) {
        print_legal_small_op(op);
      }
    }
    llvm::outs() << "\n\n";
  }

private:

  // returns name of operation without the dialect
  std::string get_op_string(Operation &op) {
    return (std::string) op.getName().stripDialect().data();
  }

  // checks if operation name is a legal SMaLL operation
  bool legal_small_op(Operation &op) {
    std::string opname = get_op_string(op);
    if(this->legal_small_ops.find(opname) != this->legal_small_ops.end())
      return true;
    else
      return false;
  }

  dim_t get_kernel_size(Operation &op) {
    // mlir::Attribute k_size = op.getAttr(StringRef("kernel_shape"));
    // mlir::ONNXConvOp onnx_conv_op = dyn_cast<mlir::ONNXConvOp>(op);
    // // onnx_mlir::ONNXConvOpShapeHelper shapeHelper(&onnx_conv_op);
    // ArrayRef<Attribute> k_shape_attr = onnx_conv_op.kernel_shape().getValue();
    // // llvm::outs() << k_shape_attr.data<dim_t>() << "\n";
    // exit(-1);
    return 0;
  }

  // get all the parameters for a SMaLL conv
  void get_small_conv_params(SMaLLConv* small_conv, Operation &op, dim_t lay_num) {
    small_conv->lay_num = lay_num;
    small_conv->k_size = get_kernel_size(op);
    small_conv->stride = 0;
    small_conv->pad = "na";
    small_conv->out_c = 0;
    small_conv->in_c = 0;
    small_conv->in_h = 0;
    small_conv->in_w = 0;
    small_conv->in_ptr = NULL;
    small_conv->filt_ptr = NULL;
    small_conv->out_ptr = NULL;
  }

  // get all the parameters for a SMaLL pooling
  void get_small_pool_params(SMaLLPooling *small_pool, Operation &op, dim_t lay_num) {
    small_pool->lay_num = lay_num;
    small_pool->k_size = get_kernel_size(op);
    small_pool->stride = 0;
    small_pool->pad = "na";
    small_pool->in_c = 0;
    small_pool->in_h = 0;
    small_pool->in_w = 0;
    small_pool->in_ptr = NULL;
    small_pool->out_ptr = NULL;
  }

  // get all the parameters for a SMaLL relu
  void get_small_relu_params(SMaLLRelu *small_relu, Operation &op, dim_t lay_num) {
    small_relu->lay_num = lay_num;
    small_relu->in_c = 0;
    small_relu->in_h = 0;
    small_relu->in_w = 0;
    small_relu->in_ptr = NULL;
    small_relu->out_ptr = NULL;
  }

  // print the legal SMaLL operation as a c function call
  void print_small_c_func(Operation &op, dim_t lay_num) {
    std::string opname = get_op_string(op);
    // std::string c_func_name = this->small_c_funcs[this->legal_small_ops[opname]];
    std::string small_c_func_name = small_c_funcs[legal_small_ops[opname]];

    if(opname == "Conv") {
      SMaLLConv small_conv;
      get_small_conv_params(&small_conv, op, lay_num);
      
      llvm::outs() << small_c_func_name << "(" <<
          small_conv.lay_num << ", " <<
          small_conv.k_size << ", " <<
          small_conv.stride << ", " <<
          small_conv.pad << ", " <<
          small_conv.out_c << ", " <<
          small_conv.in_c << ", " <<
          small_conv.in_h << ", " <<
          small_conv.in_w << ", " <<
          small_conv.in_ptr << ", " <<
          small_conv.filt_ptr << ", " <<
          small_conv.out_ptr << ");\n\n";  
    }
    else if(opname == "MaxPool" || opname == "AvgPool") {
      SMaLLPooling small_pool;
      get_small_pool_params(&small_pool, op, lay_num);

      llvm::outs() << small_c_func_name << "(" <<
          small_pool.lay_num << ", " <<
          small_pool.k_size << ", " <<
          small_pool.stride << ", " <<
          small_pool.pad << ", " <<
          small_pool.in_c << ", " <<
          small_pool.in_h << ", " <<
          small_pool.in_w << ", " <<
          small_pool.in_ptr << ", " <<
          small_pool.out_ptr << ");\n\n";  
    }
    else if(opname == "Relu") {
      SMaLLRelu small_relu;
      get_small_relu_params(&small_relu, op, lay_num);

      llvm::outs() << small_c_func_name << "(" <<
          small_relu.lay_num << ", " <<
          small_relu.in_c << ", " <<
          small_relu.in_h << ", " <<
          small_relu.in_w << ", " <<
          small_relu.in_ptr << ", " <<
          small_relu.out_ptr << ");\n\n";
    }
  }

  void print_legal_small_op(Operation &op) {

    dim_t lay_num = 0;
    std::string opname = get_op_string(op);

    // print SMaLL c function calls
    if(legal_small_op(op)) {
      llvm::outs() << "// " << op << "\n";
      print_small_c_func(op, lay_num++);
    }
    // make unimplemented operations comments (except for constants)
    else {
      if (opname != "Constant")
        llvm::outs() << "\n\n// [NOT IMPLEMENTED] -- " << opname << "\n\n";
    }
  }
};
} // end anonymous namespace

/*!
 * Create an instrumentation pass.
 */
std::unique_ptr<mlir::Pass> onnx_mlir::createONNXPrintSMaLLPass() {
  return std::make_unique<ONNXPrintSMaLLPass>();
}
