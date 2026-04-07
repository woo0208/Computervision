// *******************************************
// 제목: 실습 과제1
// 날짜: 26년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));


	int X_4_1 = img.rows / 4;
	int Y_4_1 = img.cols / 4;

	int X_4_3 = img.rows - (img.rows / 4);
	int Y_4_3 = img.cols - (img.cols / 4);

	line(img, Point(X_4_1, Y_4_1), Point(X_4_3, Y_4_1), Scalar(0, 0, 0), 1);
	line(img, Point(X_4_1, Y_4_3), Point(X_4_3, Y_4_3), Scalar(0, 0, 0), 1);
	line(img, Point(X_4_1, Y_4_1), Point(X_4_1, Y_4_3), Scalar(0, 0, 0), 1);
	line(img, Point(X_4_3, Y_4_1), Point(X_4_3, Y_4_3), Scalar(0, 0, 0), 1);
	line(img, Point(X_4_1, Y_4_1), Point(X_4_3, Y_4_3), Scalar(0, 0, 0), 1);
	line(img, Point(X_4_1, Y_4_3), Point(X_4_3, Y_4_1), Scalar(0, 0, 0), 1);

	imshow("img", img);
	waitKey();

	return 0;
}
