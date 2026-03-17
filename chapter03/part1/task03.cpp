// *******************************************
// 제목: 실습 과제3
// 날짜: 26년 3월 17일
// 작성자: 2603043 한정우
// *******************************************



#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Rect r1(10, 10, 20, 20);	  // x,y,width,height 순서
	Point p1(15,15);

	bool check = r1.contains(p1);
	if (check) {
		cout << "사각형 내부에 점" << p1 << "이 존재합니다." << endl;			 // p1(15,15)는 범위안에 들어가서 이렇게 출력
																				 // 그 이유는 영역 내부에 존재하는건 시작점(x,y) ~ 끝점([x+width],[y+height])
																				 // 따라서 내부에 존재하는 값은 [10,10] ~ [30,30]
																				 // 이 부분 꼭 유의할 것 영역의 내부는 시작점~끝점
	}
	else {
		cout << "사각형 내부에 점 " << p1 << "이 존재하지 않습니다." << endl;
	}

	return 0;
}
