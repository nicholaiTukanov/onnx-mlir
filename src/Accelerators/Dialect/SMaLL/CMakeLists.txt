add_subdirectory(SMaLLOps)

add_onnx_mlir_dialect(SMaLL small)
add_onnx_mlir_dialect_doc(small SMaLL.td)

add_onnx_mlir_library(OMSMaLLOps
  # Top files for SMaLL dialect.
  SMaLLOps.cpp
  SMaLLOps/OpHelper.cpp

  # Support for shape inference, verifier, and canonicalization.
  # Please list in the alphabetical order.
  # SMaLLOps/Conv2D/Conv2D.cpp
  SMaLLOps/Elementwise/Elementwise.cpp
  # SMaLLOps/Pooling/Pooling.cpp

  DEPENDS
  OMLayoutHelper
  OMSMaLLIncGen
  OMONNXSMaLLStickIncGen
  OMONNXSMaLLUnstickIncGen
  OMShapeInferenceOpInterfaceIncGen

  LINK_LIBS PRIVATE
  OMDiagnostic

  LINK_LIBS PUBLIC
  OMONNXOps # Use ONNXShapeHelper 
  OMLayoutHelper
  OMShapeHelperOpInterface
  MLIRIR

  ACCEL_INCLUDE_DIRS PRIVATE
  ${SMaLL_INCLUDE_PATH}
  )
