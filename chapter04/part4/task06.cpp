#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// [함수 선언] 마우스 콜백 함수 프로토타입 선언
void on_mouse(int event, int x, int y, int flags, void* userdata);

int main() {
	// [STEP 1] Mat 객체 생성: 400x200, CV_8UC3, 초기색(White)
	Mat img(200, 400, CV_8UC3, Scalar(255, 255, 255));

	// [예외 처리] 이미지 생성 확인
	if (img.empty()) return -1;

	// [STEP 2] 윈도우 생성: 이름은 "img"로 설정

	namedWindow("img");

	// [STEP 3] 마우스 콜백 등록: "img" 창, on_mouse 함수 연결, img 주소 전달

	setMouseCallback("img", on_mouse, &img);

	// [STEP 4] 루프 구현: imshow 실행 및 waitKey(10)로 'q' 입력 시 종료 로직 작성

	while (true) {
		imshow("img", img);
		if (waitKey(10) == 'q' || waitKey(10) == 'Q') break;
	}

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
	// [STEP 5] 전달받은 userdata를 Mat& image로 형변환(Casting)
	Mat& image = *(Mat*)userdata;

	// [STEP 6] event 종류에 따른 switch문 시작
	switch (event) {

	// [STEP 7-1] case EVENT_LBUTTONDOWN:
	// image를 Red로 setTo 하고 로그 출력 후 break

	case EVENT_LBUTTONDOWN:
		image.setTo(Scalar(0, 0, 255));
		cout << "left button click" << endl;
		break;


	// [STEP 7-2] case EVENT_RBUTTONDOWN:
	// image를 Blue로 setTo 하고 로그 출력 후 break
	case EVENT_RBUTTONDOWN:
		image.setTo(Scalar(255, 0, 0));
		cout << "Right button click" << endl;
		break;
	}
}
