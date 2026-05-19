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
    imshow("src", src);

    Mat dst;

    cout << "===== GaussianBlur 실행시간 측정 결과 =====" << endl;

    for (int sigma = 1; sigma <= 5; sigma++) {
        TickMeter tm; // 시간 측정 객체 생성

        tm.start(); // 시간 측정 시작

        // Size(0, 0)을 입력하면 sigma 값에 따라 마스크 크기가 자동으로 결정됩니다.
        GaussianBlur(src, dst, Size(0, 0), (double)sigma);

        tm.stop(); // 시간 측정 종료

        // 콘솔 창에 sigma 값에 따른 밀리초 단위 실행 시간 출력
        cout << "Sigma = " << sigma << " -> Execution Time: "
            << tm.getTimeMilli() << " ms" << endl;

        String desc = format("Gaussian: sigma = %d", sigma);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
            Scalar(255), 1, LINE_AA);
        imshow("dst", dst);
        waitKey(); // 아무 키나 누르면 다음 sigma 값으로 넘어감
    }
    return 0;
}
