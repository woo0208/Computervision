// *******************************************
// 제목: 실습 과제3
// 날짜: 26년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	int X_0 = img.rows / 4;
	int Y_0 = img.cols / 4;

	int X_1 = img.rows - (img.rows / 4);
	int Y_1 = img.cols - (img.cols / 4);

	int centerX = img.rows/2;
	int centerY = img.cols/2;


	line(img, Point(X_0, Y_0), Point(X_1, Y_0), Scalar(0, 0, 0), 1);
	line(img, Point(X_0, Y_1), Point(X_1, Y_1), Scalar(0, 0, 0), 1);
	line(img, Point(X_0, Y_0), Point(X_0, Y_1), Scalar(0, 0, 0), 1);
	line(img, Point(X_1, Y_0), Point(X_1, Y_1), Scalar(0, 0, 0), 1);
	circle(img, Point(centerX, centerY), 100, Scalar(0, 0, 0), 1, LINE_AA);
	imshow("img",img);
	waitKey();
	return 0;
}
