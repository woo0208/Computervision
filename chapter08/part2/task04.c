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

    Point2f srcPts[3] = {
        Point2f(0, 0),
        Point2f(src.cols - 1, 0),
        Point2f(0, src.rows - 1)
    };

    float shearAmount = (src.rows - 1) * 1.0f;

    Point2f dstPts[3] = {
        Point2f(0, 0),
        Point2f(src.cols - 1, 0),
        Point2f(shearAmount, src.rows - 1)
    };

    Mat M = getAffineTransform(srcPts, dstPts);


    Mat dst;
    resize(src, dst, Size(), 2.0, 2.0);

    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    return 0;
}
