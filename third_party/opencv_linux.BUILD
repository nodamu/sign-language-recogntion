# Description:
#   OpenCV libraries for video/image processing on Linux

licenses(["notice"])  # BSD license

exports_files(["LICENSE"])

# The following build rule assumes that OpenCV is installed by
# 'apt-get install libopencv-core-dev libopencv-highgui-dev \'
# '                libopencv-calib3d-dev libopencv-features2d-dev \'
# '                libopencv-imgproc-dev libopencv-video-dev' on Debian/Ubuntu.
# If you install OpenCV separately, please modify the build rule accordingly.
cc_library(
    name = "opencv",
    srcs = glob(
        [
            "local/lib/libopencv_core.so",
            "local/lib/libopencv_calib3d.so",
            "local/lib/libopencv_features2d.so",
            "local/lib/libopencv_optflow.so*",
            "local/lib/libopencv_highgui.so",
            "local/lib/libopencv_imgcodecs.so",
            "local/lib/libopencv_imgproc.so",
            "local/lib/libopencv_video.so",
            "local/lib/libopencv_videoio.so",
        ],
    ),
   hdrs = glob(["local/include/opencv4/**/*.h*"]),
   includes = ["local/include/opencv4/"],
    linkstatic = 1,
    visibility = ["//visibility:public"],
)
