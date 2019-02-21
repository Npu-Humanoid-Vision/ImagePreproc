#!/bin/sh
rm ./demo.out
# command="g++ main.cpp `pkg-config --cflags --libs opencv` -std=c++11 -o demo.out"
command="g++ main.cpp -o demo -std=c++11 -IC:\\opencv\\build\\include -LC:\\opencv\\build\\bin -llibopencv_calib3d249 -llibopencv_contrib249 -llibopencv_core249 -llibopencv_features2d249 -llibopencv_flann249 -llibopencv_gpu249 -llibopencv_highgui249 -llibopencv_imgproc249 -llibopencv_legacy249 -llibopencv_ml249 -llibopencv_nonfree249 -llibopencv_objdetect249 -llibopencv_ocl249 -llibopencv_photo249 -llibopencv_stitching249 -llibopencv_superres249 -llibopencv_video249 -llibopencv_videostab249"
result=`$command`
if [ ! -f "demo.out" ];
then 
    echo "compile error"
else   
    echo "build succeed"
    ./demo.out
fi