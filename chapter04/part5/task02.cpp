#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 사용자 정의 데이터 구조체: 마우스와 트랙바 콜백 간의 데이터 공유를 위한 컨테이너
struct Data {
	Mat img;        // 캔버스 역할을 할 영상 객체
	int pos = 0;    // 트랙바에서 설정된 현재 색상/모드 인덱스
	Point starP;    // 사각형 그리기를 시작할 좌표 (마우스 클릭 지점)
};

// 콜백 함수 선언 (마우스 및 트랙바 이벤트 처리용)
void on_mouse(int event, int x, int y, int flag, void* userdata);
void on_trackbar(int pos, void* userdata);

int main() {
	Data data;
	// 500x500 사이즈, 8비트 3채널(BGR) 컬러 영상 생성 (초기 배경색: 흰색)
	data.img = Mat(500, 500, CV_8UC3, Scalar(255, 255, 255));
	
	namedWindow("img");

	// 마우스 콜백 등록: "img" 윈도우에서 발생하는 이벤트를 on_mouse 함수로 전달
	setMouseCallback("img", on_mouse, &data);

	// 트랙바 생성: "level"이라는 이름으로 0~3까지의 범위를 가짐
	createTrackbar("level", "img", &data.pos, 3, on_trackbar, &data);

	while (true) {
		imshow("img", data.img);
		int key = waitKey(10);
		if (key == 'q') { // 'q' 키를 누르면 루프 종료
			break;
		}
	}
	return 0;
}

// 마우스 이벤트 처리 함수 (이벤트 종류, x좌표, y좌표, 플래그, 사용자 데이터)
void on_mouse(int event, int x, int y, int flag, void* userdata) {
	Data* pdata = (Data*)userdata;
	Point endP; // 사각형이 끝날 좌표 (마우스 떼는 지점)

	switch (event) {
	case EVENT_LBUTTONDOWN: // 마우스 왼쪽 버튼을 눌렀을 때
		pdata->starP = Point(x, y); // 시작 좌표 저장
		break;

	case EVENT_LBUTTONUP: // 마우스 왼쪽 버튼을 뗐을 때
		endP = Point(x, y); // 끝 좌표 저장
		
		// 트랙바 위치(pdata->pos)에 따른 분기 처리 (색상 및 채우기 설정)
		if (pdata->pos == 0) { // Blue 사각형
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(255, 0, 0));
		} else if (pdata->pos == 1) { // Green 사각형
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(0, 255, 0));
		} else if (pdata->pos == 2) { // Red 사각형
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(0, 0, 255));
		} else if (pdata->pos == 3) { // 흰색으로 채워진 사각형 (지우개 효과)
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(255, 255, 255), FILLED);
		}
		break;
	}
}

// 트랙바 수치 변경 시 호출되는 함수
void on_trackbar(int pos, void* userdata) {
	Data* pdata = (Data*)userdata;
	pdata->pos = pos; // 현재 선택된 모드값을 업데이트
}
