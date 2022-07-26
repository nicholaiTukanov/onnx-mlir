// %2 = "onnx.Conv"(%arg0, %0, %1) {dilations = [1, 1], group = 1 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_0", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<?x3x224x224xf32>, tensor<32x3x3x3xf32>, tensor<32xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %8 = "onnx.Conv"(%5, %6, %7) {dilations = [1, 1], group = 32 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_2", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<32x1x3x3xf32>, tensor<32xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %14 = "onnx.Conv"(%11, %12, %13) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_4", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<16x32x1x1xf32>, tensor<16xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);

// %17 = "onnx.Conv"(%14, %15, %16) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_5", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<96x16x1x1xf32>, tensor<96xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %23 = "onnx.Conv"(%20, %21, %22) {dilations = [1, 1], group = 96 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_7", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<*xf32>, tensor<96x1x3x3xf32>, tensor<96xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %29 = "onnx.Conv"(%26, %27, %28) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_9", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<24x96x1x1xf32>, tensor<24xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);

// %32 = "onnx.Conv"(%29, %30, %31) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_10", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<144x24x1x1xf32>, tensor<144xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %38 = "onnx.Conv"(%35, %36, %37) {dilations = [1, 1], group = 144 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_12", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<144x1x3x3xf32>, tensor<144xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %44 = "onnx.Conv"(%41, %42, %43) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_14", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<24x144x1x1xf32>, tensor<24xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %48 = "onnx.Conv"(%45, %46, %47) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_16", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<144x24x1x1xf32>, tensor<144xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %54 = "onnx.Conv"(%51, %52, %53) {dilations = [1, 1], group = 144 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_18", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<*xf32>, tensor<144x1x3x3xf32>, tensor<144xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %60 = "onnx.Conv"(%57, %58, %59) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_20", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<32x144x1x1xf32>, tensor<32xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);

// %63 = "onnx.Conv"(%60, %61, %62) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_21", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<192x32x1x1xf32>, tensor<192xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %69 = "onnx.Conv"(%66, %67, %68) {dilations = [1, 1], group = 192 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_23", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<192x1x3x3xf32>, tensor<192xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %75 = "onnx.Conv"(%72, %73, %74) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_25", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<32x192x1x1xf32>, tensor<32xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %79 = "onnx.Conv"(%76, %77, %78) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_27", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<192x32x1x1xf32>, tensor<192xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %85 = "onnx.Conv"(%82, %83, %84) {dilations = [1, 1], group = 192 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_29", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<192x1x3x3xf32>, tensor<192xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %91 = "onnx.Conv"(%88, %89, %90) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_31", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<32x192x1x1xf32>, tensor<32xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %95 = "onnx.Conv"(%92, %93, %94) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_33", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<192x32x1x1xf32>, tensor<192xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %101 = "onnx.Conv"(%98, %99, %100) {dilations = [1, 1], group = 192 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_35", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<*xf32>, tensor<192x1x3x3xf32>, tensor<192xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %107 = "onnx.Conv"(%104, %105, %106) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_37", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<64x192x1x1xf32>, tensor<64xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);

// %110 = "onnx.Conv"(%107, %108, %109) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_38", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<384x64x1x1xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %116 = "onnx.Conv"(%113, %114, %115) {dilations = [1, 1], group = 384 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_40", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<384x1x3x3xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %122 = "onnx.Conv"(%119, %120, %121) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_42", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<64x384x1x1xf32>, tensor<64xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %126 = "onnx.Conv"(%123, %124, %125) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_44", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<384x64x1x1xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %132 = "onnx.Conv"(%129, %130, %131) {dilations = [1, 1], group = 384 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_46", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<384x1x3x3xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %138 = "onnx.Conv"(%135, %136, %137) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_48", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<64x384x1x1xf32>, tensor<64xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %142 = "onnx.Conv"(%139, %140, %141) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_50", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<384x64x1x1xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %148 = "onnx.Conv"(%145, %146, %147) {dilations = [1, 1], group = 384 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_52", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<384x1x3x3xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %154 = "onnx.Conv"(%151, %152, %153) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_54", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<64x384x1x1xf32>, tensor<64xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %158 = "onnx.Conv"(%155, %156, %157) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_56", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<384x64x1x1xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %164 = "onnx.Conv"(%161, %162, %163) {dilations = [1, 1], group = 384 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_58", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<384x1x3x3xf32>, tensor<384xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %170 = "onnx.Conv"(%167, %168, %169) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_60", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<96x384x1x1xf32>, tensor<96xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);

// %173 = "onnx.Conv"(%170, %171, %172) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_61", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<576x96x1x1xf32>, tensor<576xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %179 = "onnx.Conv"(%176, %177, %178) {dilations = [1, 1], group = 576 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_63", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<576x1x3x3xf32>, tensor<576xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %185 = "onnx.Conv"(%182, %183, %184) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_65", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<96x576x1x1xf32>, tensor<96xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %189 = "onnx.Conv"(%186, %187, %188) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_67", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<576x96x1x1xf32>, tensor<576xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %195 = "onnx.Conv"(%192, %193, %194) {dilations = [1, 1], group = 576 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_69", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<576x1x3x3xf32>, tensor<576xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %201 = "onnx.Conv"(%198, %199, %200) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_71", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<96x576x1x1xf32>, tensor<96xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %205 = "onnx.Conv"(%202, %203, %204) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_73", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<576x96x1x1xf32>, tensor<576xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %211 = "onnx.Conv"(%208, %209, %210) {dilations = [1, 1], group = 576 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_75", pads = [1, 1, 1, 1], strides = [2, 2]} : (tensor<*xf32>, tensor<576x1x3x3xf32>, tensor<576xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %217 = "onnx.Conv"(%214, %215, %216) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_77", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<160x576x1x1xf32>, tensor<160xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);

// %220 = "onnx.Conv"(%217, %218, %219) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_78", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<960x160x1x1xf32>, tensor<960xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %226 = "onnx.Conv"(%223, %224, %225) {dilations = [1, 1], group = 960 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_80", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<960x1x3x3xf32>, tensor<960xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %232 = "onnx.Conv"(%229, %230, %231) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_82", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<160x960x1x1xf32>, tensor<160xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %236 = "onnx.Conv"(%233, %234, %235) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_84", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<960x160x1x1xf32>, tensor<960xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %242 = "onnx.Conv"(%239, %240, %241) {dilations = [1, 1], group = 960 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_86", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<960x1x3x3xf32>, tensor<960xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %248 = "onnx.Conv"(%245, %246, %247) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_88", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<160x960x1x1xf32>, tensor<160xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- Add

// %252 = "onnx.Conv"(%249, %250, %251) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_90", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<960x160x1x1xf32>, tensor<960xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %258 = "onnx.Conv"(%255, %256, %257) {dilations = [1, 1], group = 960 : si64, kernel_shape = [3, 3], onnx_node_name = "Conv_92", pads = [1, 1, 1, 1], strides = [1, 1]} : (tensor<*xf32>, tensor<960x1x3x3xf32>, tensor<960xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12

// %264 = "onnx.Conv"(%261, %262, %263) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_94", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<320x960x1x1xf32>, tensor<320xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);

// %267 = "onnx.Conv"(%264, %265, %266) {dilations = [1, 1], group = 1 : si64, kernel_shape = [1, 1], onnx_node_name = "Conv_95", pads = [0, 0, 0, 0], strides = [1, 1]} : (tensor<*xf32>, tensor<1280x320x1x1xf32>, tensor<1280xf32>) -> tensor<*xf32>
Conv2D(0, 18446744073709551615, 0, na, 0, 0, 0, 0, 0x0, 0x0, 0x0);



// [NOT IMPLEMENTED] -- ClipV12



// [NOT IMPLEMENTED] -- GlobalAveragePool



// [NOT IMPLEMENTED] -- Shape



// [NOT IMPLEMENTED] -- Gather



// [NOT IMPLEMENTED] -- UnsqueezeV11



// [NOT IMPLEMENTED] -- Concat



// [NOT IMPLEMENTED] -- Reshape



// [NOT IMPLEMENTED] -- Gemm

