#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

int main(void)
{
    // 시간 측정의 변별력을 높이기 위해 어느 정도 크기가 있는 영상을 로드하거나 생성합니다.
    // 여기서는 1000x1000 크기의 가상 그레이스케일 영상을 생성하여 사용합니다.
    Mat src = Mat::zeros(1000, 1000, CV_8UC1);
    randu(src, Scalar(0), Scalar(255)); // 무작위 노이즈로 채움

    Mat dst;
    int mask_sizes[] = { 3, 10, 30 };

    cout << "===== [방법 1] std::chrono 이용 실행시간 측정 =====" << endl;
    for (int ksize : mask_sizes) {
        Mat kernel = Mat::ones(ksize, ksize, CV_32F) / static_cast<float>(ksize * ksize);

        // 측정 시작
        auto startTime = std::chrono::steady_clock::now();

        filter2D(src, dst, -1, kernel);

        // 측정 종료
        auto endTime = std::chrono::steady_clock::now();
        float totalTime = std::chrono::duration<float, std::milli>(endTime - startTime).count();

        cout << "Mask Size " << ksize << "x" << ksize << " -> Execution Time: " << totalTime << " ms" << endl;
    }

    cout << "\n===== [방법 2] cv::TickMeter 이용 실행시간 측정 =====" << endl;
    for (int ksize : mask_sizes) {
        Mat kernel = Mat::ones(ksize, ksize, CV_32F) / static_cast<float>(ksize * ksize);

        TickMeter tm;

        // 측정 시작
        tm.start();

        filter2D(src, dst, -1, kernel);

        // 측정 종료
        tm.stop();

        cout << "Mask Size " << ksize << "x" << ksize << " -> Execution Time: " << tm.getTimeMilli() << " ms" << endl;
    }

    return 0;
}
