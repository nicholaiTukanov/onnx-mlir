/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/Transforms/Passes.h"
#include "llvm/Support/Debug.h"

#include "src/Accelerators/SMaLL/Compiler/SMaLLCompilerUtils.hpp"
#include "src/Accelerators/SMaLL/Conversion/ZHighToZLow/ZHighToZLow.hpp"
#include "src/Accelerators/SMaLL/Conversion/ZLowToLLVM/ZLowToLLVM.hpp"
#include "src/Accelerators/SMaLL/Dialect/ZHigh/ZHighOps.hpp"
#include "src/Accelerators/SMaLL/Dialect/ZLow/ZLowOps.hpp"
#include "src/Accelerators/SMaLL/SMaLLAccelerator.hpp"
#include "src/Accelerators/SMaLL/Pass/SMaLLPasses.hpp"
#include "src/Compiler/CompilerOptions.hpp"

// TODO: replace with small header
// #include "zdnn.h"

#include <memory>

#define DEBUG_TYPE "SMaLLAccelerator"

extern llvm::cl::OptionCategory OMSMaLLPassOptions;

namespace onnx_mlir {
namespace accel {

Accelerator *createSMaLL() { return SMaLLAccelerator::getInstance(); }

SMaLLAccelerator *SMaLLAccelerator::instance = nullptr;

SMaLLAccelerator *SMaLLAccelerator::getInstance() {
  if (instance == nullptr)
    instance = new SMaLLAccelerator();
  return instance;
}

SMaLLAccelerator::SMaLLAccelerator() : Accelerator(Accelerator::Kind::SMaLL) {
  LLVM_DEBUG(llvm::dbgs() << "Creating an SMaLL accelerator\n");
  acceleratorTargets.push_back(this);
  // TODO: need to ensure that small lib is loaded correctly
//   addCompilerConfig(CCM_SHARED_LIB_DEPS, {"RuntimeSMaLL", "zdnn"});
};

SMaLLAccelerator::~SMaLLAccelerator() { delete instance; }

uint64_t SMaLLAccelerator::getVersionNumber() const { return SMALL_VERNUM; }

void SMaLLAccelerator::getOrLoadDialects(mlir::MLIRContext &context) const {
  LLVM_DEBUG(llvm::dbgs() << "Loading dialects for SMaLL accelerator\n");
  context.getOrLoadDialect<small::SMaLLDialect>();
}

void SMaLLAccelerator::addPasses(mlir::OwningOpRef<mlir::ModuleOp> &module,
    mlir::PassManager &pm, onnx_mlir::EmissionTargetType &emissionTarget,
    std::string outputNameNoExt) const {
  LLVM_DEBUG(llvm::dbgs() << "Adding passes for SMaLL accelerator\n");
  addPassesSMaLL(module, pm, emissionTarget, outputNameNoExt);
}

void SMaLLAccelerator::registerDialects(mlir::DialectRegistry &registry) const {
  LLVM_DEBUG(llvm::dbgs() << "Registering dialects for SMaLL accelerator\n");
  registry.insert<small::SMaLLDialect>();
}

void SMaLLAccelerator::initPasses(int optLevel) const {
  LLVM_DEBUG(llvm::dbgs() << "Initializing passes for SMaLL accelerator\n");
  // TODO: implement conversion pass
//   mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
//     return onnx_mlir::createONNXToSMaLLPass();
//   });
}

// TODO: figure out what the rest of this means

// mlir::MemRefType SMaLLAccelerator::convertTensorTypeToMemRefType(
//     const mlir::TensorType tensorType) const {
//   assert(tensorType.hasRank() && "expected only ranked shapes");
//   if (tensorType.cast<mlir::RankedTensorType>()
//           .getEncoding()
//           .dyn_cast_or_null<onnx_mlir::zhigh::ZTensorEncodingAttr>()) {
//     onnx_mlir::zhigh::ZMemRefType zMemRefType =
//         onnx_mlir::zhigh::convertZTensorToMemRefType(tensorType);
//     return zMemRefType.value;
//   }
//   return nullptr;
// }

// int64_t SMaLLAccelerator::getDefaultAllocAlignment(
//     const mlir::TensorType tensorType) const {
//   assert(tensorType.hasRank() && "expected only ranked shapes");
//   if (tensorType.cast<mlir::RankedTensorType>()
//           .getEncoding()
//           .dyn_cast_or_null<onnx_mlir::zhigh::ZTensorEncodingAttr>())
//     return gAlignment;
//   return -1;
// }

// void SMaLLAccelerator::conversionTargetONNXToKrnl(
//     mlir::ConversionTarget &target) const {
//   target.addLegalDialect<zlow::ZLowDialect>();
// }

// void SMaLLAccelerator::rewritePatternONNXToKrnl(
//     mlir::RewritePatternSet &patterns, mlir::TypeConverter &typeConverter,
//     mlir::MLIRContext *ctx) const {
//   onnx_mlir::zhigh::populateZHighToZLowConversionPattern(
//       patterns, typeConverter, ctx);
// }

// void SMaLLAccelerator::conversionTargetKrnlToLLVM(
//     mlir::ConversionTarget &target) const {}

// void SMaLLAccelerator::rewritePatternKrnlToLLVM(
//     mlir::RewritePatternSet &patterns, mlir::LLVMTypeConverter &typeConverter,
//     mlir::MLIRContext *ctx) const {
//   onnx_mlir::zlow::populateZLowToLLVMConversionPattern(
//       patterns, typeConverter, ctx);
// }

} // namespace accel
} // namespace onnx_mlir
