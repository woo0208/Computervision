#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Mat dst;

    int mask_sizes[] = { 3, 10, 30, 100, 300 };

    cout << "===== [방법 1] std::chrono 이용 실행시간 측정 =====" << endl;

    for (int ksize : mask_sizes) {
        // 평균값 필터 마스크 생성
        // 모든 원소가 1 / (ksize * ksize) 값을 가짐
        float value = 1.f / (ksize * ksize);
        Mat kernel(ksize, ksize, CV_32FC1, Scalar(value));

        // 실행시간 측정 시작
        auto startTime = chrono::steady_clock::now();

        filter2D(src, dst, -1, kernel, Point(-1, -1), 0);

        // 실행시간 측정 종료
        auto endTime = chrono::steady_clock::now();

        float totalTime =
            chrono::duration<float, milli>(endTime - startTime).count();

        cout << "Mask Size " << ksize << "x" << ksize
             << " -> Execution Time: " << totalTime << " ms" << endl;
    }

    cout << endl;
    cout << "===== [방법 2] cv::TickMeter 이용 실행시간 측정 =====" << endl;

    for (int ksize : mask_sizes) {
        // 평균값 필터 마스크 생성
        float value = 1.f / (ksize * ksize);
        Mat kernel(ksize, ksize, CV_32FC1, Scalar(value));

        TickMeter tm;

        // 실행시간 측정 시작
        tm.start();

        filter2D(src, dst, -1, kernel, Point(-1, -1), 0);

        // 실행시간 측정 종료
        tm.stop();

        cout << "Mask Size " << ksize << "x" << ksize
             << " -> Execution Time: " << tm.getTimeMilli() << " ms" << endl;
    }

    return 0;
}
