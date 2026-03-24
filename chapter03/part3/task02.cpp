// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 3월 24일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main() {
	// 이미지 규격 설정, 컬러&흑백 결정, 어떤 색 출력할지 결정
	Mat img1(400, 300, CV_8UC3, Scalar(255, 0, 0));
	Mat img2(400, 300, CV_8UC3, Scalar(0, 255, 0));
	Mat img3(400, 300, CV_8UC3, Scalar(0, 0, 255));

	// 주의! imshow 함수는 실제로 픽셀을 화면에 렌더링(Rendering)하는 작업까지 완료하진 않음 (waitkey() 함수 필수!)
	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	//운영체제로부터 쌓여있던 메시지 큐를 처리하며 이벤트를 처리
	waitKey();  
	return 0;
}
