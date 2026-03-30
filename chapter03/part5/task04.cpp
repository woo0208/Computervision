// *******************************************
// 제목: 실습 과제4
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat img(400, 400, CV_8UC1, Scalar(255));

    int y = 0;
    for (int x = 0; x < img.cols; x++) {
        int y = 1.0 / 400.0 * x * x;
        img.at<uchar>(y, x) = 0;
    }
    imshow("Line", img);
    waitKey(0);
    return 0;
}
