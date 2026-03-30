// *******************************************
// 제목: 실습 과제3
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 영상 불러오기
    Mat img = imread("lenna.bmp", IMREAD_COLOR);


    for (int y = 0; y < img.rows; y += img.rows/4) { // 4등분이기 때문에 rows/4
        for (int x = 0; x < img.cols; x++) {
            img.at<Vec3b>(y, x)[0] = 255;
            img.at<Vec3b>(y, x)[1] = 255;
            img.at<Vec3b>(y, x)[2] = 255;
        }
    }


    for (int x = 0; x < img.cols; x += img.cols / 4) { // 4등분이기 때문에 cols/4
        for (int y = 0; y < img.rows; y++) {
            img.at<Vec3b>(y, x)[0] = 255;
            img.at<Vec3b>(y, x)[1] = 255;
            img.at<Vec3b>(y, x)[2] = 255;
        }
    }

    imshow("Line", img);
    waitKey(0);
    return 0;
}
