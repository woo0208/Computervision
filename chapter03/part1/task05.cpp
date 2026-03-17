// *******************************************
// 제목: 실습 과제5
// 날짜: 26년 3월 17일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {

	String str;

	for (int i = 1; i < 16; i+=2) {			 // 2씩 증가하므로 반복문에 아예 2씩 증가로 변환 & 조건문 사용하는 것보다 메모리관점에서 절약
		str = format("실행결과%2d.bmp", i);	 // 출력결과에 0이 없으므로 %02가 아닌 %2 사용
		if (i == 15) {
			cout << str << endl;			//메모리관점에서 endl 을 남발하는것보단 마지막에 한번 사용하는 것이 좋음
			break;
		}
		cout << str <<"\n";
	}
	return 0;
}
