/*
 * SPDX-License-Identifier: Apache-2.0
 */
// =============================================================================
//
// This file exposes the entry points to create compiler passes for SMaLL in
// addition to the passes used by ONNX MLIR.
//
//===----------------------------------------------------------------------===//

#pragma once

#include "mlir/Pass/Pass.h"

// namespace onnx_mlir {

// /// Add pass for lowering ONNX ops to ZHigh ops.
// std::unique_ptr<mlir::Pass> createONNXToSMaLLPass();
// std::unique_ptr<mlir::Pass> createONNXToSMaLLPass(
//     mlir::ArrayRef<std::string> execNodesOnCpu);

// /// Add pass for rewriting ONNX ops for ZHigh.
// std::unique_ptr<mlir::Pass> createRewriteONNXForSMaLLPass();
// std::unique_ptr<mlir::Pass> createRewriteONNXForSMaLLPass(
//     mlir::ArrayRef<std::string> execNodesOnCpu);

// /// Pass for folding std.alloc.
// std::unique_ptr<mlir::Pass> createFoldStdAllocPass();

// namespace zhigh {

// /// Pass for layout propagation at ZHighIR.
// std::unique_ptr<mlir::Pass> createZHighLayoutPropagationPass();

// /// Pass for constant propagation at ZHighIR.
// std::unique_ptr<mlir::Pass> createZHighConstPropagationPass();

// /// Pass for instrument the ZHigh ops
// std::unique_ptr<mlir::Pass> createInstrumentZHighPass();

// } // end namespace zhigh

// namespace zlow {

// /// Add pass for rewriting ZLow ops.
// std::unique_ptr<mlir::Pass> createZLowRewritePass();

// /// Add pass for rewriting ZLow ops.
// std::unique_ptr<mlir::Pass> createZLowDummyOpForMultiDerefPass();

// } // namespace zlow
// } // namespace onnx_mlir
