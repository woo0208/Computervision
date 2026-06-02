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

    float scale = 0.5f;

    float tx = (src.cols - (src.cols * scale)) / 2.0f;
    float ty = (src.rows - (src.rows * scale)) / 2.0f;

    Point2f dstPts[3] = {
        Point2f(tx, ty),                                      
        Point2f((src.cols - 1) * scale + tx, ty),            
        Point2f(tx, (src.rows - 1) * scale + ty)            
    };

    Mat M = getAffineTransform(srcPts, dstPts);

    cout << M << endl;

    Mat dst;
    warpAffine(src, dst, M, src.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));

    imshow("src", src);
    imshow("dst", dst);
    waitKey();

    return 0;
}
