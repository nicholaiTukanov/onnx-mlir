// SPDX-License-Identifier: Apache-2.0

//===----- SMaLL.td -- SMaLL Dialect Operation Definitions -*- tablegen ----==//
//
// Copyright 2019-2020 The IBM Research Authors
//
// =============================================================================
//
// Defines SMaLL Dialect operations.
//
//===----------------------------------------------------------------------===//

#ifndef SMALL_OPS
#define SMALL_OPS

include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/OpBase.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "src/Interface/ShapeHelperOpInterface.td"
include "src/Interface/ShapeInferenceOpInterface.td"
include "src/IR/AttrBase.td"

//===----------------------------------------------------------------------===//
// SMaLL Dialect
//===----------------------------------------------------------------------===//

def SMaLL_Dialect : Dialect {
  let name = "small";
  let summary = "A high-level dialect for the SMaLL Framework.";
  let cppNamespace = "::onnx_mlir::small";
  let useDefaultAttributePrinterParser = 1;  
}

//===----------------------------------------------------------------------===//
// SMaLL Attribute 
//===----------------------------------------------------------------------===//

// All of the Tensor attributes will extend this class.
class SMaLL_Attr<string name, list<Trait> traits = []>
	: BaseLayoutAttr<SMaLL_Dialect, name, traits>;

// ztensor encoding attribute.
def STensorEncodingAttr : SMaLL_Attr<"STensorEncoding"> {
  let hasCustomAssemblyFormat = 1;

  let description = [{
    An attribute to encode information on properties of stensors. A tensor with
    this encoding attribute indicates that it is a ztensor whose type is
    the original type of the pre-stickified data.

    `dataLayout` indicates the data layout of the pre-stickified data.

    TODO: should we add an affine_map to describe how the data is stickified?

    Example:

    ```mlir
    #ZAIU_NHWC= #small.encoding<{
      dataLayout = "nhwc"
    }>

    ... tensor<8x8xf64, #ZAIU_NHWC> ...
    ```
  }];

  // Data in ztensor encoding.
  let parameters = (ins
    // A original data layout of the pre-stickified data.
    "STensorEncodingAttr::DataLayout":$dataLayout
  );

  let extraClassDeclaration = [{
    enum class DataLayout {
      UNDEFINED, _1D, _2D, _2DS, _3D, _3DS, _4D, _4DS,
      NCHW, NHWC, HWCK,
      FICO, ZRH, BFICO, BZRH
    };
  }];

  let cppNamespace = "::onnx_mlir::small";
}

// Whether a ztensor type has the specified layout.
class DataLayoutOfPred<string layout> : And<[
  CPred<"($_self.cast<::mlir::RankedTensorType>()) &&"
        "($_self.cast<::mlir::RankedTensorType>()."
        "getEncoding().dyn_cast_or_null<STensorEncodingAttr>()) &&"
        "($_self.cast<::mlir::RankedTensorType>()."
        "getEncoding().cast<STensorEncodingAttr>().getDataLayout()"
        " == STensorEncodingAttr::DataLayout::" # layout # ")"> 
]>;

// So far STensor supports only F32 for pre-stickified data.
class STensorOf<string layout, list<int> ranks> :
    Type<And<[TensorOf<[F32]>.predicate, HasAnyRankOfPred<ranks>,
              DataLayoutOfPred<layout>]>,
         !interleave(!foreach(rank, ranks, rank # "D"), "/") # " " #
         TensorOf<[F32]>.summary # " with layout " # layout,
         "::mlir::TensorType">;

def UnrankedSTensor : UnrankedTensorOf<[F32]>;

def STensor_1D: AnyTypeOf<[UnrankedSTensor, STensorOf<"_1D", [1]>]>;
def STensor_2D: AnyTypeOf<[UnrankedSTensor, STensorOf<"_2D", [2]>]>;
def STensor_2DS: AnyTypeOf<[UnrankedSTensor, STensorOf<"_2DS", [2]>]>;
def STensor_3D: AnyTypeOf<[UnrankedSTensor, STensorOf<"_3D", [3]>]>;
def STensor_3DS: AnyTypeOf<[UnrankedSTensor, STensorOf<"_3DS", [3]>]>;
def STensor_4D: AnyTypeOf<[UnrankedSTensor, STensorOf<"_4D", [4]>]>;
def STensor_4DS: AnyTypeOf<[UnrankedSTensor, STensorOf<"_4DS", [4]>]>;
def STensor_NHWC: AnyTypeOf<[UnrankedSTensor, STensorOf<"NHWC", [4]>]>;
def STensor_NCHW: AnyTypeOf<[UnrankedSTensor, STensorOf<"NCHW", [4]>]>;
def STensor_HWCK: AnyTypeOf<[UnrankedSTensor, STensorOf<"HWCK", [4]>]>;
def STensor_FICO: AnyTypeOf<[UnrankedSTensor, STensorOf<"FICO", [2, 3]>]>;
def STensor_ZRH: AnyTypeOf<[UnrankedSTensor, STensorOf<"ZRH", [2, 3]>]>;
def STensor_BFICO: AnyTypeOf<[UnrankedSTensor, STensorOf<"BFICO", [2, 3]>]>;
def STensor_BZRH: AnyTypeOf<[UnrankedSTensor, STensorOf<"BZRH", [2, 3]>]>;

def AnySTensor: AnyTypeOf<[STensor_1D, STensor_2D, STensor_3D, STensor_4D,
      STensor_2DS, STensor_3DS, STensor_4DS,
      STensor_NCHW, STensor_NHWC, STensor_HWCK,
      STensor_FICO, STensor_ZRH, STensor_BFICO, STensor_BZRH]>;

//===----------------------------------------------------------------------===//
// SMaLL Operations
//===----------------------------------------------------------------------===//

// Op has the same operand and result layout.
def SameOperandsAndResultLayout: NativeOpTrait<"SameOperandsAndResultLayout">;

//===----------------------------------------------------------------------===//
// Base class for SMaLL dialect operations. This operation inherits from the
// base `Op` class in OpBase.td, and provides:
//   * The parent dialect of the operation.
//   * The mnemonic for the operation, or the name without the dialect prefix.
//   * A list of traits for the operation.

class SMaLL_Op<string mnemonic, list<Trait> traits = []> :
    Op<SMaLL_Dialect, mnemonic, traits>;

// def SMaLLAddOp:SMaLL_Op<"Add", [Pure, SameOperandsAndResultLayout,
//     DeclareOpInterfaceMethods<ShapeInferenceOpInterface>,
//     DeclareOpInterfaceMethods<ShapeHelperOpInterface>]> {
//   let summary = "SMaLL Add operation";
//   let description = [{
//     SMaLL operation to perform an Add.
//     This operation does not support broadcasting.
//   }];
//   let arguments = (ins AnyTypeOf<[AnySTensor]>:$X,
//                        AnyTypeOf<[AnySTensor]>:$Y);
//   let results = (outs AnyTypeOf<[AnySTensor]>:$Out);
//   let extraClassDefinition = [{
//     onnx_mlir::ONNXOpShapeHelper * SMaLLAddOp::getShapeHelper(mlir::Operation *op, mlir::ArrayRef<mlir::Value> oper, 
//         onnx_mlir::IndexExprBuilder *ieb, onnx_mlir::IndexExprScope *scope) {
//       onnx_mlir::ONNXOpShapeHelper *sh = new SMaLLBinaryOpShapeHelper(op, oper, ieb, scope);
//       assert(sh && "failed to allocate shape helper");
//       return sh;
//     }
//   }];
// }

def SMaLLReluOp:SMaLL_Op<"Relu", [Pure, SameOperandsAndResultLayout,
    DeclareOpInterfaceMethods<ShapeInferenceOpInterface>,
    DeclareOpInterfaceMethods<ShapeHelperOpInterface>]> {
  let summary = "SMaLL Relu operation";
  let description = [{
    "SMaLL operation to perform a Relu."
  }];
  let arguments = (ins AnyTypeOf<[AnySTensor]>:$X);
  let results = (outs AnyTypeOf<[AnySTensor]>:$Out);
  let extraClassDefinition = [{
    onnx_mlir::ONNXOpShapeHelper * SMaLLReluOp::getShapeHelper(mlir::Operation *op, mlir::ArrayRef<mlir::Value> oper, 
        onnx_mlir::IndexExprBuilder *ieb, onnx_mlir::IndexExprScope *scope) {
      onnx_mlir::ONNXOpShapeHelper *sh = new SMaLLUnaryOpShapeHelper(op, oper, ieb, scope);
      assert(sh && "failed to allocate shape helper");
      return sh;
    }
  }];
}

// def SMaLLMaxPool2DOp:SMaLL_Op<"MaxPool2D", [Pure,
//     DeclareOpInterfaceMethods<ShapeInferenceOpInterface>,
//     DeclareOpInterfaceMethods<ShapeHelperOpInterface>]> {
//   let summary = "SMaLL 2D max pooling operation";
//   let description = [{
//     SMaLL operation to perform 2D max pooling.
//   }];
//   let arguments = (ins STensor_NHWC:$input,
//                        I64ArrayAttr:$kernel_shape,
//                        I64ArrayAttr:$strides,
//                        DefaultValuedStrAttr<StrAttr, "SAME_PADDING">:$padding_type
//   );
//   let results = (outs STensor_NHWC:$output);
//   let builders = [
//     OpBuilder<(ins "::mlir::Value":$input, "::mlir::ArrayAttr":$kernel_shape,
//                    "::mlir::ArrayAttr":$strides, "::mlir::StringAttr":$padding_type), [{
//       Type elementType = input.getType().cast<ShapedType>().getElementType();
//       UnrankedTensorType resType = UnrankedTensorType::get(elementType);
//       build($_builder, $_state, resType, input, kernel_shape, strides, padding_type);
//     }]>
//   ];
//   let extraClassDefinition = [{
//     onnx_mlir::ONNXOpShapeHelper * SMaLLMaxPool2DOp::getShapeHelper(mlir::Operation *op, mlir::ArrayRef<mlir::Value> oper, 
//         onnx_mlir::IndexExprBuilder *ieb, onnx_mlir::IndexExprScope *scope) {
//       onnx_mlir::ONNXOpShapeHelper *sh = new SMaLLPoolingOpShapeHelper<SMaLLMaxPool2DOp>(op, oper, ieb, scope);
//       assert(sh && "failed to allocate shape helper");
//       return sh;
//     }
//   }];
// }

// def SMaLLConv2DOp:SMaLL_Op<"Conv2D", [Pure,
//     DeclareOpInterfaceMethods<ShapeInferenceOpInterface>,
//     DeclareOpInterfaceMethods<ShapeHelperOpInterface>]> {
//   let summary = "SMaLL 2D convolution operation";
//   let description = [{
//     SMaLL operation to perform 2D convolution. 
//     * input: `[num_batches, height_in, width_in, channels_in]`
//     * input_kernel: `[kernel_height, kernel_width, channels_in, channels_out]` 
//     * input_bias: `[channels_out] `
//     * kernel_shape: 1D array of kernel height and width 
//     * strides: 1D array of stride height and width 
//     * padding_type: SAME_PADDING or VALID_PADDING 
//     * act_func: ACT_NONE or ACT_RELU 
//     * output: `[num_batches, height_out, width_out, channels_out]`
//   }];
//   let arguments = (ins STensor_NHWC:$input,
//                        STensor_HWCK:$input_kernel,
//                        AnyTypeOf<[STensor_1D, NoneType]>:$input_bias,
//                        I64ArrayAttr:$kernel_shape,
//                        I64ArrayAttr:$strides,
//                        DefaultValuedStrAttr<StrAttr, "SAME_PADDING">:$padding_type,
//                        DefaultValuedStrAttr<StrAttr, "ACT_NONE">:$act_func
//   );
//   let results = (outs STensor_NHWC:$output);
//   let builders = [
//     OpBuilder<(ins "::mlir::Value":$input, "::mlir::Value":$input_kernel, "::mlir::Value":$input_bias,
//                    "::mlir::ArrayAttr":$kernel_shape, "::mlir::ArrayAttr":$strides,
//                    "::mlir::StringAttr":$padding_type, "::mlir::StringAttr":$act_func), [{
//       Type elementType = input.getType().cast<ShapedType>().getElementType();
//       UnrankedTensorType resType = UnrankedTensorType::get(elementType);
//       build($_builder, $_state, resType, input, input_kernel, input_bias,
//             kernel_shape, strides, padding_type, act_func);
//     }]>
//   ];
//   let hasVerifier = 1;
//   let extraClassDefinition = [{
//     onnx_mlir::ONNXOpShapeHelper * SMaLLConv2DOp::getShapeHelper(mlir::Operation *op, mlir::ArrayRef<mlir::Value> oper, 
//         onnx_mlir::IndexExprBuilder *ieb, onnx_mlir::IndexExprScope *scope) {
//       onnx_mlir::ONNXOpShapeHelper *sh = new SMaLLConv2DOpShapeHelper(op, oper, ieb, scope);
//       assert(sh && "failed to allocate shape helper");
//       return sh;
//     }
//   }];
// }

// def SMaLLBatchNormOp:SMaLL_Op<"BatchNorm", [Pure,
//     DeclareOpInterfaceMethods<ShapeInferenceOpInterface>,
//     DeclareOpInterfaceMethods<ShapeHelperOpInterface>]> {
//   let summary = "SMaLL batchnorm operation";
//   let description = [{
//     SMaLL operation to perform batchnorm.
//   }];
//   let arguments = (ins STensor_NHWC:$input,
//                        STensor_1D:$a,
//                        STensor_1D:$b
//                   );
//   let results = (outs STensor_NHWC:$output);
//   let builders = [
//     OpBuilder<(ins "::mlir::Value":$input, "::mlir::Value":$a, "::mlir::Value":$b), [{
//       build($_builder, $_state, input.getType(), input, a, b);
//     }]>
//   ];
//   let extraClassDefinition = [{
//     onnx_mlir::ONNXOpShapeHelper * SMaLLBatchNormOp::getShapeHelper(mlir::Operation *op, mlir::ArrayRef<mlir::Value> oper, 
//         onnx_mlir::IndexExprBuilder *ieb, onnx_mlir::IndexExprScope *scope) {
//       onnx_mlir::ONNXOpShapeHelper *sh = new SMaLLUnaryOpShapeHelper(op, oper, ieb, scope);
//       assert(sh && "failed to allocate shape helper");
//       return sh;
//     }
//   }];
// }

#endif // SMALL_OPS
