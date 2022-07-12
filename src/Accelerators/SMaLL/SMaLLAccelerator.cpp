// /*
//  * SPDX-License-Identifier: Apache-2.0
//  */

// Add accelerator support for the SMaLL ML framework
//
//===----------------------------------------------------------------------===//

#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/Transforms/Passes.h"
#include "llvm/Support/Debug.h"

#include "src/Accelerators/SMaLL/Compiler/NNPACompilerUtils.hpp"
#include "src/Accelerators/SMaLL/Conversion/SMaLLToTiNY/SMaLLToTiNY.hpp"
#include "src/Accelerators/SMaLL/Conversion/TiNYToSMaLL/TiNYToSMaLL.hpp"
#include "src/Accelerators/SMaLL/Dialect/SMaLL/SMaLLOps.hpp"
#include "src/Accelerators/SMaLL/SMaLLAccelerator.hpp"
#include "src/Accelerators/SMaLL/Pass/SMaLLPasses.hpp"
#include "src/Compiler/CompilerOptions.hpp"
#include "small.h"

#include <memory>

#define DEBUG_TYPE "SMaLLAccelerator"

extern llvm::cl::OptionCategory OMNNPAPassOptions;

namespace onnx_mlir {
namespace accel {

Accelerator *createSMaLL() { return SMaLLAccelerator::getInstance(); }

SMaLLAccelerator *SMaLLAccelerator::instance = nullptr;

SMaLLAccelerator *SMaLLAccelerator::getInstance() {
  if (instance == nullptr)
    instance = new SMaLLAccelerator();
  return instance;
}

SMaLLAccelerator::SMaLLAccelerator() : Accelerator(Accelerator::Kind::NNPA) {
  LLVM_DEBUG(llvm::dbgs() << "Creating an SMaLL accelerator\n");
  acceleratorTargets.push_back(this);
  // Order is important! libRuntimeNNPA depends on libzdnn
  // TODO: fix dependencies (we know small lib is needed but what else?)
  addCompilerConfig(CCM_SHARED_LIB_DEPS, {"small"});
};

SMaLLAccelerator::~SMaLLAccelerator() { delete instance; }

uint64_t SMaLLAccelerator::getVersionNumber() const { return SMALL_VERNUM; }

void SMaLLAccelerator::getOrLoadDialects(mlir::MLIRContext &context) const {
  LLVM_DEBUG(llvm::dbgs() << "Loading dialects for SMaLL accelerator\n");
  context.getOrLoadDialect<small::SMaLLDialect>();
  context.getOrLoadDialect<tiny::TiNYDialect>();
}

void SMaLLAccelerator::addPasses(mlir::OwningOpRef<mlir::ModuleOp> &module,
    mlir::PassManager &pm,
    onnx_mlir::EmissionTargetType &emissionTarget) const {
  LLVM_DEBUG(llvm::dbgs() << "Adding passes for SMaLL accelerator\n");
  addPassesSMaLL(module, pm, emissionTarget);
}

void SMaLLAccelerator::registerDialects(mlir::DialectRegistry &registry) const {
  LLVM_DEBUG(llvm::dbgs() << "Registering dialects for SMaLL accelerator\n");
  registry.insert<small::SMaLLDialect>();
  registry.insert<tiny::TiNYDialect>();
}

void SMaLLAccelerator::initPasses(int optLevel) const {
  LLVM_DEBUG(llvm::dbgs() << "Initializing passes for SMaLL accelerator\n");

  // this pass will convert ONNX models to the SMaLL ML framework
  mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
    return onnx_mlir::createONNXToSMaLLPass();
  });


  mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
    return onnx_mlir::createRewriteONNXForSMaLLPass();
  });

  mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
    return onnx_mlir::tiny::createTiNYRewritePass();
  });


    // * commented out pass seem to be unnecessary
//   mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
//     return onnx_mlir::zlow::createTiNYDummyOpForMultiDerefPass();
//   });

//   mlir::registerPass(
//       []() -> std::unique_ptr<mlir::Pass> { return createFoldStdAllocPass(); });

//   mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
//     return onnx_mlir::zhigh::createZHighConstPropagationPass();
//   });

//   mlir::registerPass([]() -> std::unique_ptr<mlir::Pass> {
//     return onnx_mlir::zhigh::createZHighLayoutPropagationPass();
//   });
}

mlir::MemRefType SMaLLAccelerator::convertTensorTypeToMemRefType(
    const mlir::TensorType tensorType) const {
  assert(tensorType.hasRank() && "expected only ranked shapes");
  if (tensorType.cast<mlir::RankedTensorType>()
          .getEncoding()
          .dyn_cast_or_null<onnx_mlir::zhigh::ZTensorEncodingAttr>()) {
    onnx_mlir::zhigh::ZMemRefType zMemRefType =
        onnx_mlir::zhigh::convertZTensorToMemRefType(tensorType);
    return zMemRefType.value;
  }
  return nullptr;
}

// lowering?
void SMaLLAccelerator::conversionTargetONNXToKrnl(
    mlir::ConversionTarget &target) const {
  target.addLegalDialect<tiny::TiNYDialect>();
}


void SMaLLAccelerator::rewritePatternONNXToKrnl(
    mlir::RewritePatternSet &patterns, mlir::TypeConverter &typeConverter,
    mlir::MLIRContext *ctx) const {
  onnx_mlir::small::populateSMaLLToTiNYConversionPattern(
      patterns, typeConverter, ctx);
}

void SMaLLAccelerator::conversionTargetKrnlToLLVM(
    mlir::ConversionTarget &target) const {}

void SMaLLAccelerator::rewritePatternKrnlToLLVM(
    mlir::RewritePatternSet &patterns, mlir::LLVMTypeConverter &typeConverter,
    mlir::MLIRContext *ctx) const {
  onnx_mlir::tiny::populateTiNYToLLVMConversionPattern(
      patterns, typeConverter, ctx);
}

} // namespace accel
} // namespace onnx_mlir
