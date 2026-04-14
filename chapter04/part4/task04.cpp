#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 마우스 콜백 함수 선언
void event_handler(int event, int x, int y, int flags, void* userdata);

// 전역 변수로 영상 객체 선언 (콜백 함수에서 접근 가능하도록 설정)
Mat img;

int main() {
	// 이미지를 BGR 3채널 컬러 모드로 로드
	img = imread("lenna.bmp", IMREAD_COLOR);
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");

	// 마우스 콜백 설정: "img" 윈도우에서 마우스 이벤트 발생 시 event_handler 실행
	setMouseCallback("img", event_handler);

	int key;
	while (true) {
		imshow("img", img); // 현재 영상을 화면에 출력
		key = waitKey(10);
		if (key == 'q') break; // 'q' 키 입력 시 무한 루프 탈출
	}
	return 0;
}

// 마우스 이벤트 처리 구현부
void event_handler(int event, int x, int y, int flags, void* userdata)
{
    switch (event) {
    case EVENT_LBUTTONDOWN: // 마우스 왼쪽 버튼을 눌렀을 때 실행
    { 
        // 클릭된 좌표를 Point 객체로 생성
        Point pt(x, y);

        // .at<Vec3b>(y, x) 또는 .at<Vec3b>(Point): 
        // 해당 좌표의 화소값(BGR)을 가져옴. Vec3b는 uchar 3개로 구성된 벡터형.
        Vec3b value = img.at<Vec3b>(pt);

        // 콘솔창에 좌표와 해당 위치의 B, G, R 색상 정보를 출력
        cout << "좌표: (" << pt.x << ", " << pt.y << "), 화소값(B,G,R): " << value << endl;
        break;
    } 
    
    default:
        break;
    }
}
