// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}


	int endX = img.rows;
	int endY = img.cols;

	int X_4_1 = img.rows / 4;
	int Y_4_1 = img.cols / 4;

	int X_4_2 = img.rows / 2;
	int Y_4_2 = img.cols / 2;

	int X_4_3 = img.rows - (img.rows / 4);
	int Y_4_3 = img.cols - (img.cols / 4);

	line(img, Point(0, Y_4_1), Point(endX, Y_4_1), Scalar(255, 255, 255), 1);
	line(img, Point(0, Y_4_2), Point(endX, Y_4_2), Scalar(255, 255, 255), 1);
	line(img, Point(0, Y_4_3), Point(endX, Y_4_3), Scalar(255, 255, 255), 1);
	line(img, Point(0, endY), Point(endX, endY), Scalar(255, 255, 255), 1); // 생략 가능
	line(img, Point(X_4_1, 0), Point(X_4_1, endY), Scalar(255, 255, 255), 1);
	line(img, Point(X_4_2, 0), Point(X_4_2, endY), Scalar(255, 255, 255), 1);
	line(img, Point(X_4_3, 0), Point(X_4_3, endY), Scalar(255, 255, 255), 1);
	line(img, Point(endX, 0), Point(endX, endY), Scalar(255, 255, 255), 1); // 생략 가능
	

	imshow("LineLenna", img);
	waitKey();

	return 0;
}
