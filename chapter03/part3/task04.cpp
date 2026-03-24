// *******************************************
// 제목: 실습 과제4
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
	
	// 조건문 변수
	int count = 0;
	while (true) {

		// count % 3 으로 인덱스를 0, 1, 2로 순환시켜 BGR 색상을 차례로 할당
		if (count % 3 == 0) img.setTo(Scalar(255, 0, 0));
		else if (count % 3 == 1) img.setTo(Scalar(0, 255, 0));
		else if (count % 3 == 2) img.setTo(Scalar(0, 0, 255));
		count++;
		imshow("img", img);

		// 1000ms(1초) 동안 키 입력을 대기하며 이벤트를 처리 , 'q','Q' 입력시 반환된 아스키(ASCII) 값을 체크하여 종료 조건 판별
		int key = waitKey(1000);

		if (key == 'q' || key == 'Q') {
			break;
		}

		cout << "현재 카운트: " << count << " (종료하려면 이미지 창에서 'q' 입력)" << endl;

	}
	// 종료되면 모든 창 정리
	destroyAllWindows();
	return 0;
}
