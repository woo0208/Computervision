// *******************************************
// 제목: 실습 과제4
// 날짜: 26년 3월 17일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Rect re;
	Point p;
	cout << "사각형의 좌측상단의 좌표를 입력하시오(x,y):";
	cin >> re.x >> re.y;
	cout << "사각형의 폭,높이를 입력하시오(width,height): ";
	cin >> re.width >> re.height;
	cout << "점 P의 좌표를 입력하시오: ";
	cin >> p.x >> p.y;

	bool check = re.contains(p);

	if (check) {
		cout << "점 " << p << "는 사각형 안에 있다." << endl;						 // 정답 출력 => 시작[10,20] ~ 끝점[60,50]
																					 // 따라서 P의 좌표 [50,40]은 위 사이에 존재한다.
	}
	else {
		cout << "점 " << p << "는 사각형 안에 존재하지 않는다." << endl;
	}




}

