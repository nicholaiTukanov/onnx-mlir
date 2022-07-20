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
#include "src/Pass/Passes.hpp"

using namespace std;



using namespace mlir;


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

 

  // enum SMaLLOps
  // {
  //   Conv = 0,
  //   Conv1x1 = 1,
  //   ConvDW = 2,
  //   MaxPool = 3,
  //   AvgPool = 4,
  //   Relu = 5,
  //   FC = 6
  // };
  
  void runOnOperation() override {
    auto function = getOperation();
    auto &funcBody = function.getBody();

    // Iterate on the operations
    for (Operation &op : funcBody.getOps()) {
      if (isa<mlir::ONNXDialect>(op.getDialect())) {

        print_legal_small_op(op);
        
      }
    }
  }

private:

  static bool legal_small_op(string opname) {
    std::vector<string> legal_small_ops = {"Conv", "Conv1x1", "ConvDW", "MaxPool", "AvgPool", "Relu", "FC"};
    auto it = std::find(legal_small_ops.begin(), legal_small_ops.end(), opname);
    if(it != legal_small_ops.end())
      return true;
    else
      return false;
  }   

  static void print_legal_small_op(Operation &op) {
    const char* opname_ = op.getName().stripDialect().data();
    std::string opname = opname_;
    if(legal_small_op(opname)) {
      llvm::outs() << opname << "\n";
    }
    else {
      llvm::outs() << opname << " Not Implmented" << "\n";
    }
  }

//   static LogicalResult verifyRanked(Operation &op) {
//     for (auto ty : op.getOperandTypes()) {
//       if (ty.isa<SeqType>()) {
//         auto seqTy = ty.cast<SeqType>();
//         if (!seqTy.getElementType().isa<RankedTensorType>()) {
//           op.emitError("SeqType with unranked Sequence Element");
//           return failure();
//         }
//       } else if (!ty.isa<RankedTensorType>() && !ty.isa<NoneType>()) {
//         op.emitError("not ranked");
//         return failure();
//       }
//     }
//     return success();
//   }
};
} // end anonymous namespace

/*!
 * Create an instrumentation pass.
 */
std::unique_ptr<mlir::Pass> onnx_mlir::createONNXPrintSMaLLPass() {
  return std::make_unique<ONNXPrintSMaLLPass>();
}
