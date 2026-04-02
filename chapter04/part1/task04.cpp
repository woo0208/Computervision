// *******************************************
// 제목: 실습 과제4
// 날짜: 26년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
	// 시스템 기본 카메라(ID: 0) 장치를 열기 위한 VideoCapture 객체 초기화
	VideoCapture cap(0);

	// 카메라 연결 상태 확인 (예외 처리)
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}

	Mat frame, cross;
	while (true) {
		// 카메라로부터 새로운 프레임 획득
		cap >> frame;

		// 프레임 데이터 유효성 검사
		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}

		// [중요: 깊은 복사(Deep Copy)] 
		// 원본 영상 frame의 데이터를 보존하기 위해 별도의 메모리 공간에 복제본 생성
		cross = frame.clone();

		// 영상의 정중앙 좌표 계산 (Center Coordinate)
		int centerX = cross.cols / 2;
		int centerY = cross.rows / 2;

		// [가이드라인 그리기 - cv::line]
		// 1. 수평선(Horizontal Line): 좌측 끝(0)에서 우측 끝(cols)까지 centerY 높이로 그림
		line(cross, Point(0, centerY), Point(cross.cols, centerY), Scalar(0, 0, 255), 2);

		// 2. 수직선(Vertical Line): 상단 끝(0)에서 하단 끝(rows)까지 centerX 위치에 그림
		line(cross, Point(centerX, 0), Point(centerX, cross.rows), Scalar(0, 0, 255), 2);

		// 원본 영상(frame)과 가이드라인이 추가된 영상(cross)을 각각 다른 창에 출력
		imshow("frame", frame);
		imshow("cross", cross);

		// 약 30 FPS를 유지하며 사용자의 'q' 키 입력을 대기
		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			break;
		}
	}

	// 모든 리소스 해제
	destroyAllWindows();

	return 0;
}
