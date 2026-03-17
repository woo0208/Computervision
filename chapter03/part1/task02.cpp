// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 3월 17일
// 작성자: 2603043 한정우
// *******************************************


#include <opencv2//opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main() {
	Size s1(0, 0);
	Size s2(0, 0);
	cout << "첫번째 사각형의 폭,높이 입력: ";
	cin >> s1.width >> s1.height;							   // Point 는 x,y지만 Size는 width,height 다. 이 부분 기억하자
	cout << "두번째 사각형의 폭,높이 입력: ";
	cin >> s2.width >> s2.height;

	cout << "s1: " << s1;
	cout << "\ns2: " << s2;
	cout << "\ns1의 면적" << s1.area();						   // int 라는 변수를 생성하지 않고 바로 함수로 출력 => 메모리 절감
	cout << "\ns2의 면적" << s2.area() << endl;				   // 마지막 출력은 항상 버퍼 초기화


	return 0;
}
