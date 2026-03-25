// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 3월 25일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	uchar matdata[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	Mat img1(3, 5, CV_8UC1, &matdata);
	Mat img2 = img1(Rect(2, 1, 3, 2));

	cout << "img1:\n" << img1 << endl;
	cout << "img2:\n" << img2 << endl;

	return 0;
}
