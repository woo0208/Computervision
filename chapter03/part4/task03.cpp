// *******************************************
// 제목: 실습 과제3
// 날짜: 26년 3월 25일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img1 = imread("dog.bmp");
	if (img1.empty()) {
		cerr << "image load failed" << endl; 
		return -1;
	}

	Mat img2 = img1(Rect(103, 36, 79, 99));
	img2 = Scalar(255, 0, 0);

	imshow("img1", img1);
	waitKey();

	return 0;
}
