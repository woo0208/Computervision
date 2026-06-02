#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("lenna.bmp");
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Point2f center(src.cols / 2.0f, src.rows / 2.0f);

    double angle = -45.0;
    double scale = 2.0;
    Mat M = getRotationMatrix2D(center, angle, scale);

    M.at<double>(0, 2) += (src.cols * 2.0f / 2.0f) - center.x;
    M.at<double>(1, 2) += (src.rows * 2.0f / 2.0f) - center.y;

    Mat dst;
    Size dstSize(src.cols * 2, src.rows * 2);
    warpAffine(src, dst, M, dstSize, INTER_CUBIC, BORDER_CONSTANT, Scalar(0, 0, 0));

    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    return 0;
}
