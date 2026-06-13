#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    float data[] = {
        1,  4,  7,  4, 1,
        4, 16, 26, 16, 4,
        7, 26, 41, 26, 7,
        4, 16, 26, 16, 4,
        1,  4,  7,  4, 1
    };

    // 슬라이드에 제시된 5x5 가우시안 마스크 생성
    // 전체 합이 273이므로 273으로 나누어 정규화
    Mat kernel = Mat(5, 5, CV_32FC1, data) / 273.f;

    Mat dst1, dst2;

    // filter2D를 이용한 사용자 정의 가우시안 필터
    filter2D(src, dst1, -1, kernel, Point(-1, -1), 0);

    // OpenCV 내장 GaussianBlur 함수 사용
    GaussianBlur(src, dst2, Size(5, 5), 0);

    imshow("src", src);
    imshow("filter2D Gaussian", dst1);
    imshow("GaussianBlur", dst2);

    waitKey();
    return 0;
}
