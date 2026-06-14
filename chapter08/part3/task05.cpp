#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("eastsea.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Mat dst = src.clone();

    imshow("src", src);
    imshow("dst", dst);

    while (true) {
        int key = waitKey(0);

        if (key == 'q' || key == 27) {
            break;
        }

        if (key == 'a') {
            // 좌우대칭
            flip(src, dst, 1);

            putText(
                dst,
                "flipCode: 1",
                Point(10, 30),
                FONT_HERSHEY_SIMPLEX,
                1.0,
                Scalar(255, 0, 0),
                1,
                LINE_AA
            );
        }
        else if (key == 'b') {
            // 상하대칭
            flip(src, dst, 0);

            putText(
                dst,
                "flipCode: 0",
                Point(10, 30),
                FONT_HERSHEY_SIMPLEX,
                1.0,
                Scalar(255, 0, 0),
                1,
                LINE_AA
            );
        }
        else if (key == 'c') {
            // 좌우대칭 + 상하대칭
            flip(src, dst, -1);

            putText(
                dst,
                "flipCode: -1",
                Point(10, 30),
                FONT_HERSHEY_SIMPLEX,
                1.0,
                Scalar(255, 0, 0),
                1,
                LINE_AA
            );
        }
        else {
            continue;
        }

        imshow("dst", dst);
    }

    destroyAllWindows();

    return 0;
}
