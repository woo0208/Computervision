// *******************************************
// 제목: 실습 과제 4
// 날짜: 26년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("lenna.bmp");

	int X_face = 270;
	int Y_top_face = 173;
	int Y_bottom_face = 394;
	int Y_center_face = (Y_top_face + Y_bottom_face) / 2;

	circle(img, Point(X_face, Y_center_face), 130, Scalar(255, 50, 0), 2, LINE_AA);
	imshow("img", img);
	waitKey();
	return 0;
}
