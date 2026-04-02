// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
	// 기본 카메라(Index 0) 장치를 열기 위한 VideoCapture 객체 생성
	VideoCapture cap(0);

	// 카메라 장치가 정상적으로 열렸는지 확인 (예외 처리)
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}

	Mat frame, bright_100;
	while (true) {
		// 카메라로부터 현재 프레임을 받아와 frame 객체에 저장 (복호화 및 캡처)
		cap >> frame;

		// 프레임이 제대로 읽히지 않았을 경우 루프 탈출
		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}

		// [실시간 화소 처리: 밝기 증가]
		// 모든 픽셀의 B, G, R 채널에 각각 100을 더함
		// OpenCV의 포화 연산(Saturate Operation) 덕분에 255를 넘는 값은 자동으로 255(흰색)로 고정됨
		bright_100 = frame + Scalar(100, 100, 100);

		// 원본 프레임과 밝기가 조절된 프레임을 각각의 창에 출력
		imshow("frame", frame);
		imshow("bright_100", bright_100);

		// 10ms 동안 키 입력을 대기
		// 입력된 키의 아스키(ASCII) 값이 27(ESC 키)이면 루프를 종료
		if (waitKey(10) == 27) break;
	}

	// 사용된 모든 창을 닫고 시스템 자원 해제
	destroyAllWindows();

	return 0;
}
