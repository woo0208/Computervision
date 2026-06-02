#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("tekapo.bmp");
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Point2f srcPts[3] = {
        Point2f(0, 0),
        Point2f(src.cols - 1, 0),
        Point2f(0, src.rows - 1)
    };


    Point2f dstPts[3] = {
        Point2f(0, 0),
        Point2f((src.cols - 1), 0),
        Point2f((src.cols - 1) * 0.2, src.rows - 1)
    };

    Mat M = getAffineTransform(srcPts, dstPts);
    cout << M << endl;
    Mat dst;
    warpAffine(src, dst, M, Size(src.cols * 1.2, src.rows));

    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    return 0;
}
