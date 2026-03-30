// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 영상 불러오기
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    for (int y = 0; y < img.rows; y += 128) { // 512x512이므로 4등분선 위치 128로 설정
        for (int x = 0; x < img.cols; x++) {
            img.at<uchar>(y, x) = 255;
        }
    }

    
    for (int x = 0; x < img.cols; x += 128) { // 512x512이므로 4등분선 위치 128로 설정
        for (int y = 0; y < img.rows; y++) {
            img.at<uchar>(y, x) = 255;
        }
    }

    imshow("Line", img);
    waitKey(0);
    return 0;
}

