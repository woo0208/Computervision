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
	// 8-bit unsigned char 배열 정의
	uchar matdata[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	// 외부 데이터를 참조하는 3행 5열의 Mat 객체 생성
	// 배열 이름은 첫 번째 원소의 주소값을 의미하므로 포인터로 전달됨
	Mat img1(3, 5, CV_8UC1, matdata);

	// 여기서는 (2열, 1행) 위치부터 가로 3개, 세로 2개 영역을 참조(Shallow Copy)
	Mat img2 = img1(Rect(2, 1, 3, 2));

	cout << "img1:\n" << img1 << endl;
	cout << "img2:\n" << img2 << endl;

	return 0;
}
