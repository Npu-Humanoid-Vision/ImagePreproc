#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

#ifdef __linux__
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#endif

#ifdef __WIN32
#include <io.h>
#include <windows.h>
#endif

#define POS_LABLE 1
#define NEG_LABLE 0

#define POS_COUNTER_INIT_NUM 0
#define NEG_COUNTER_INIT_NUM 0
#define SAVE_PATH "../../BackUpSource/BigBall/Rotated/"

void GetImgNames(string root_path, std::vector<std::string>& names);
cv::Mat Rotate(cv::Mat& input_image, double angle);
string GetPath(string save_path, int lable);

int main(int argc, char const *argv[]) {

    string raw_data_path = "../../BackUpSource/BigBall/Raw/";
    string data_dst_path = "../../BackUpSource/BigBall/Rotated";

    double rotate_angle[3] = {0, 120, 240};

    std::vector<string> pos_names;
    std::vector<string> neg_names;

    GetImgNames(raw_data_path+"Pos/", pos_names);
    GetImgNames(raw_data_path+"Neg/", neg_names);
    
    cv::namedWindow("233", CV_WINDOW_NORMAL);
    for (auto i = pos_names.begin(); i != pos_names.end(); i++) {
        cv::Mat t_image = cv::imread(raw_data_path+"Pos/"+*i);
        if (t_image.empty()) {
            continue;
        }
        for (auto j = 0; j < 3; j++) {
            cv::Mat dst = Rotate(t_image, rotate_angle[j]);
            cv::imshow("233", dst);
            cv::waitKey(1);
            cv::imwrite(GetPath(SAVE_PATH, POS_LABLE), dst);
        }
    }
    for (auto i = pos_names.begin(); i != pos_names.end(); i++) {
        cv::Mat t_image = cv::imread(raw_data_path+"Neg/"+*i);
        if (t_image.empty()) {
            continue;
        }
        for (auto j = 0; j < 3; j++) {
            cv::Mat dst = Rotate(t_image, rotate_angle[j]);
            cv::imshow("233", dst);
            cv::waitKey(1);
            cv::imwrite(GetPath(SAVE_PATH, NEG_LABLE), dst);
        }
    }
    return 0;
}


// 获得某文件夹下所有图片的名字
void GetImgNames(string root_path, std::vector<std::string>& names) {
#ifdef __linux__
    struct dirent* filename;
    DIR* dir;
    dir = opendir(root_path.c_str());  
    if(NULL == dir) {  
        return;  
    }  

    int iName=0;
    while((filename = readdir(dir)) != NULL) {  
        if( strcmp( filename->d_name , "." ) == 0 ||
            strcmp( filename->d_name , "..") == 0)
            continue;

        string t_s(filename->d_name);
        names.push_back(t_s);
    }
#endif

#ifdef __WIN32
    intptr_t hFile = 0;
    struct _finddata_t fileinfo;
    string p;

    hFile = _findfirst(p.assign(root_path).append("/*").c_str(), &fileinfo);

    if (hFile != -1) {
        do {
            if (strcmp(fileinfo.name, ".") == 0 || 
				strcmp(fileinfo.name, "..") == 0) {
                continue;
            }
            names.push_back(fileinfo.name); 
        } while (_findnext(hFile, &fileinfo) == 0);
    }
#endif
}


cv::Mat Rotate(cv::Mat& src, double angle) {
	cv::Mat dst;
	cv::Size dst_sz(src.cols, src.rows);    
	cv::Point2f center(src.cols / 2., src.rows / 2.);
 
	cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0);
	cv::warpAffine(src, dst, rot_mat, dst_sz, INTER_LINEAR, BORDER_REPLICATE);
    return dst;
}



int pos_counter = POS_COUNTER_INIT_NUM;
int neg_counter = NEG_COUNTER_INIT_NUM;

string GetPath(string save_path, int lable) {
    stringstream t_ss;
    string t_s;

    if (lable == POS_LABLE) {
        save_path += "Pos/";
        t_ss << pos_counter++;
        t_ss >> t_s;
        t_s = save_path + t_s;
        t_s += ".jpg";
        cout<<t_s<<endl;
    }
    else {
        save_path += "Neg/";
        t_ss << neg_counter++;
        t_ss >> t_s;
        t_s = save_path + t_s;
        t_s += ".jpg";
        cout<<t_s<<endl;   
    }
    return t_s;
}