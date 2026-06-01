#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("tekapo.bmp");
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	Point2f srcPts[3], dstPts[3];
	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols, 0);
	srcPts[2] = Point2f(src.cols, src.rows);
	dstPts[0] = Point2f(0, 0);
	dstPts[1] = Point2f(src.cols / 2, 0);
	dstPts[2] = Point2f(src.cols/2,src.rows/2);


	Mat M = getAffineTransform(srcPts, dstPts);
	cout << M << endl;
	Mat dst;
	warpAffine(src, dst, M, Size());

	transform(
		Mat(3, 1, CV_32FC2, srcPts),
		Mat(3, 1, CV_32FC2, dstPts),
		M);
	
	for (int i = 0; i < 3; i++) {
		cout << "P" << i << " : "
			<< dstPts[i].x << ", "
			<< dstPts[i].y << endl;
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();

	return 0;
}
