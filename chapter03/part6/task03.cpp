// *******************************************
// 제목: 실습 과제3
// 날짜: 2026년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    int bright = 0;

    cout << "밝기변화량을 입력:";
    cin >> bright;

    Mat bright_img = img + Scalar(bright, bright, bright);

    imshow("img", img);
    imshow("bright_img", bright_img);
    waitKey(0);


    return 0;
}
