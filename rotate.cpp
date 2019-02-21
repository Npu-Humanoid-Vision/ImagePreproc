#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
    cv::Mat src = cv::imread("./CodeByOthers/Data-Augmentation-using-Tensorflow/1.jpg");
    cout<<src.size()<<endl;
    cv::Mat dst;
	double angle = -45;
	//输出图像的尺寸与原图一样  
	cv::Size dst_sz(src.cols, src.rows);
 
	//指定旋转中心    
	cv::Point2f center(src.cols / 2., src.rows / 2.);
 
	//获取旋转矩阵（2x3矩阵）    
	cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0);
	//设置选择背景边界颜色：绿色  
	// cv::Scalar borderColor = Scalar(0, 238, 0);
	// cv::warpAffine(src, dst, rot_mat, src.size(), INTER_LINEAR, BORDER_CONSTANT, borderColor);  
	cv::warpAffine(src, dst, rot_mat, dst_sz, INTER_LINEAR, BORDER_REFLECT_101);
 
	//显示旋转效果    
	cv::imshow("src image ", src);
	cv::imshow("Rotation Image", dst);
    cv::imwrite("244.jpg", dst);
	waitKey(0);
    return 0;
}
