

// [NOT IMPLEMENTED] -- NoValue

// %2 = "onnx.Conv"(%arg0, %0, %1) {dilations = [1, 1], group = 1 : si64, kernel_shape = [7, 7], onnx_node_name = "resnetv15_conv0_fwd", pads = [3, 3, 3, 3], strides = [2, 2]} : (tensor<?x3x224x224xf32>, tensor<64x3x7x7xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %8 = "onnx.Relu"(%7) {onnx_node_name = "resnetv15_relu0_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- MaxPoolSingleOut



// [NOT IMPLEMENTED] -- NoValue

// %12 = "onnx.Conv"(%9, %10, %11) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage1_conv0_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<64x64x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %18 = "onnx.Relu"(%17) {onnx_node_name = "resnetv15_stage1_relu0_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %21 = "onnx.Conv"(%18, %19, %20) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage1_conv1_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<64x64x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %28 = "onnx.Relu"(%27) {onnx_node_name = "resnetv15_stage1_activation0"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %31 = "onnx.Conv"(%28, %29, %30) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage1_conv2_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<64x64x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %37 = "onnx.Relu"(%36) {onnx_node_name = "resnetv15_stage1_relu1_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %40 = "onnx.Conv"(%37, %38, %39) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage1_conv3_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<64x64x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %47 = "onnx.Relu"(%46) {onnx_node_name = "resnetv15_stage1_activation1"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %50 = "onnx.Conv"(%47, %48, %49) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "resnetv15_stage2_conv2_fwd", pads = [0, 0, 0, 0], strides = [2, 2]} : (tensor<*xf32>, tensor<128x64x1x1xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- NoValue

// %58 = "onnx.Conv"(%47, %56, %57) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage2_conv0_fwd", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<*xf32>, tensor<128x64x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %64 = "onnx.Relu"(%63) {onnx_node_name = "resnetv15_stage2_relu0_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %67 = "onnx.Conv"(%64, %65, %66) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage2_conv1_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<128x128x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %74 = "onnx.Relu"(%73) {onnx_node_name = "resnetv15_stage2_activation0"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %77 = "onnx.Conv"(%74, %75, %76) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage2_conv3_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<128x128x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %83 = "onnx.Relu"(%82) {onnx_node_name = "resnetv15_stage2_relu1_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %86 = "onnx.Conv"(%83, %84, %85) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage2_conv4_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<128x128x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %93 = "onnx.Relu"(%92) {onnx_node_name = "resnetv15_stage2_activation1"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %96 = "onnx.Conv"(%93, %94, %95) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "resnetv15_stage3_conv2_fwd", pads = [0, 0, 0, 0], strides = [2, 2]} : (tensor<*xf32>, tensor<256x128x1x1xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- NoValue

// %104 = "onnx.Conv"(%93, %102, %103) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage3_conv0_fwd", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<*xf32>, tensor<256x128x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %110 = "onnx.Relu"(%109) {onnx_node_name = "resnetv15_stage3_relu0_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %113 = "onnx.Conv"(%110, %111, %112) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage3_conv1_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<256x256x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %120 = "onnx.Relu"(%119) {onnx_node_name = "resnetv15_stage3_activation0"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %123 = "onnx.Conv"(%120, %121, %122) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage3_conv3_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<256x256x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %129 = "onnx.Relu"(%128) {onnx_node_name = "resnetv15_stage3_relu1_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %132 = "onnx.Conv"(%129, %130, %131) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage3_conv4_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<256x256x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %139 = "onnx.Relu"(%138) {onnx_node_name = "resnetv15_stage3_activation1"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %142 = "onnx.Conv"(%139, %140, %141) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "resnetv15_stage4_conv2_fwd", pads = [0, 0, 0, 0], strides = [2, 2]} : (tensor<*xf32>, tensor<512x256x1x1xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- NoValue

// %150 = "onnx.Conv"(%139, %148, %149) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage4_conv0_fwd", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<*xf32>, tensor<512x256x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %156 = "onnx.Relu"(%155) {onnx_node_name = "resnetv15_stage4_relu0_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %159 = "onnx.Conv"(%156, %157, %158) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage4_conv1_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<512x512x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %166 = "onnx.Relu"(%165) {onnx_node_name = "resnetv15_stage4_activation0"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %169 = "onnx.Conv"(%166, %167, %168) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage4_conv3_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<512x512x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode

// %175 = "onnx.Relu"(%174) {onnx_node_name = "resnetv15_stage4_relu1_fwd"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- NoValue

// %178 = "onnx.Conv"(%175, %176, %177) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "resnetv15_stage4_conv4_fwd", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<512x512x3x3xf32>, none) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- BatchNormalizationInferenceMode



// [NOT IMPLEMENTED] -- Add

// %185 = "onnx.Relu"(%184) {onnx_node_name = "resnetv15_stage4_activation1"} : (tensor<*xf32>) -> tensor<*xf32>
ReLUActivation(0, 0, 0, 0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- GlobalAveragePool



// [NOT IMPLEMENTED] -- Flatten



// [NOT IMPLEMENTED] -- Gemm
