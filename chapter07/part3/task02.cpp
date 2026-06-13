#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src", src);

    Mat blurred;
    Mat dst;

    // 가우시안 필터 대신 평균값 필터 사용
    // 평균값 필터의 크기는 고정
    blur(src, blurred, Size(5, 5));

    for (int alpha = 10; alpha <= 50; alpha += 10) {
        // dst = (1 + alpha) * src - alpha * blurred
        addWeighted(src, 1 + alpha, blurred, -alpha, 0, dst);

        String desc = format("Alpha: %d", alpha);

        putText(dst, desc, Point(10, 30),
            FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }

    return 0;
}
