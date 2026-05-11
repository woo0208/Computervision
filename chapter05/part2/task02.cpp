// *******************************************
// 제목: 실습 과제2
// 날짜: 2026년 5월 11일
// 작성자: 2603043 한정우
// ******************************************
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	Mat dst = src.clone();


	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			int pixel = src.at<uchar>(y, x);
			int copy = pixel + (pixel - 128) * 1.f;
			dst.at<uchar>(y, x) = copy > 255 ? 255 : copy < 0 ? 0 : copy;
		}
	}
	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	return 0;
}
