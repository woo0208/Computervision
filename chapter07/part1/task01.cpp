#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
	}
	float data[] = {
		1/9.f,1 / 9.f,1 / 9.f,
		1 / 9.f,1 / 9.f,1 / 9.f,
		1 / 9.f,1 / 9.f,1 / 9.f
	};
	Mat emboss(3, 3, CV_32FC1, data);
	Mat dst;
	filter2D(src, dst, -1, emboss, Point(-1, -1), 0);

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	return 0;
}
