#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src", src);

    Mat dst;

    for (int ksize = 3; ksize <= 7; ksize += 2) {
        // 평균값 필터 마스크 생성
        // ksize x ksize 크기의 모든 원소를 1 / (ksize * ksize)로 설정
        Mat kernel(ksize, ksize, CV_32FC1, Scalar(1.f / (ksize * ksize)));

        // blur(src, dst, Size(ksize, ksize))와 같은 역할
        filter2D(src, dst, -1, kernel, Point(-1, -1), 0);

        String desc = format("Mean: %dx%d", ksize, ksize);

        putText(dst, desc, Point(10, 30),
            FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);

        waitKey();
    }

    return 0;
}
