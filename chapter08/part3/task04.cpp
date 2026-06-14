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

    imshow("src", src);

    Mat dst;
    int flipCode[] = { 1, 0, -1 };

    for (int i = 0; i < 3; i++) {
        Mat M;

        if (flipCode[i] == 1) {
            // 좌우 반전
            M = (Mat_<double>(2, 3) <<
                -1, 0, src.cols - 1,
                 0, 1, 0
            );
        }
        else if (flipCode[i] == 0) {
            // 상하 반전
            M = (Mat_<double>(2, 3) <<
                 1,  0, 0,
                 0, -1, src.rows - 1
            );
        }
        else if (flipCode[i] == -1) {
            // 좌우 + 상하 반전
            M = (Mat_<double>(2, 3) <<
                -1,  0, src.cols - 1,
                 0, -1, src.rows - 1
            );
        }

        warpAffine(
            src,
            dst,
            M,
            src.size(),
            INTER_NEAREST,
            BORDER_CONSTANT,
            Scalar(0, 0, 0)
        );

        String desc = format("flipCode: %d", flipCode[i]);

        putText(
            dst,
            desc,
            Point(10, 30),
            FONT_HERSHEY_SIMPLEX,
            1.0,
            Scalar(255, 0, 0),
            1,
            LINE_AA
        );

        imshow("dst", dst);
        waitKey();
    }

    return 0;
}
