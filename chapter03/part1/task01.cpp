// *******************************************
// 제목: 실습 과제1
// 날짜: 26년 3월 17일
// 작성자: 2603043 한정우
// *******************************************


#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;
int main() {
	Point pt1(0, 0);
	Point pt2(0, 0);
	cout << "첫번째 점의 x,y좌표를 입력: ";;
	cin >> pt1.x >> pt1.y;
	cout << "두번째 점의 x,y좌표를 입력: ";
	cin >> pt2.x >> pt2.y;
	double dist;										// 거리는 실수이기 때문에 double 사용

	dist = norm(pt1 - pt2);								// 거리공식 내장함수 사용
	cout << "pt1:" << pt1 << "\n";						// 메모리 관점에서 endl 대신 "\n" 사용 
	cout << "pt2:" << pt2 << "\n";
	cout << "두점사이의 거리: " << dist << endl;		// 맨 마지막엔 다음 입력을 위해 버퍼를 비움





	return 0;
}
