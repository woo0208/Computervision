// *******************************************
// 제목: 실습 과제3
// 날짜: 26년 3월 24일
// 작성자: 2603043 한정우
// *******************************************
#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main() {
	// Mat 객체 생성: 세로 400, 가로 300, 8비트 3채널(BGR) 컬러 타입, 초기 화소값은 White(255, 255, 255)로 설정
	Mat img(400, 300, CV_8UC3, Scalar(255, 255, 255));
	int B, G, R;
	cout << "B값을 입력하라: ";
	cin >> B;
	cout << "G값을 입력하라: ";
	cin >> G;
	cout << "R값을 입력하라: ";
	cin >> R;

	// 입력받은 B,G,R 값 이미지에 setTo 함수로 대입
	img.setTo(Scalar(B, G, R));

	// 이미지 출력 (주의! imshow는 이벤트 처리 안됨, waitkey() 함수 필수!)
	imshow("img-After", img);

	waitKey();

	return 0;
}
