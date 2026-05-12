// *******************************************
// 제목: 실습 과제4
// 날짜: 2026년 5월 11일
// 작성자: 2603043 한정우
// ******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Mat dst = src.clone();

    // 명암비 개선 정도
    float alpha = 1.0f;

    // 입력 영상의 평균값 구하기
    Scalar avg = mean(src);
    double meanValue = avg[0];

    cout << "평균값: " << meanValue << endl;

    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            int pixel = src.at<uchar>(y, x);

            float result = pixel + (pixel - meanValue) * alpha;

            dst.at<uchar>(y, x) = saturate_cast<uchar>(result);
        }
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
