/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include "src/Accelerators/SMaLL/Dialect/SMaLL/SMaLLOps/ShapeHelper.hpp"

using namespace mlir;
using namespace onnx_mlir;

namespace onnx_mlir {
namespace small {

//===----------------------------------------------------------------------===//
// ReluOp

LogicalResult SMaLLReluOp::inferShapes(
    std::function<void(mlir::Region &)> doShapeInference) {
  return inferShapeForUnaryOps(this->getOperation());
}

} // namespace small
} // namespace onnx_mlir
