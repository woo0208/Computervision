#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 마우스 이벤트 핸들러 함수 선언
void on_mouse(int event, int x, int y, int flags, void* userdata);

int main() {
    // 1. 400x200 크기, 백색(White) 배경의 컬러 영상 생성
    // Size(width, height)이므로 400, 200 순서
    Mat img(200, 400, CV_8UC3, Scalar(255, 255, 255));

    if (img.empty()) return -1;

    namedWindow("img");

    // 2. 마우스 콜백 설정 (img 객체의 주소를 마지막 인자로 전달)
    setMouseCallback("img", on_mouse, &img);

    while (true) {
        imshow("img", img);
        if (waitKey(10) == 'q') break;
    }

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
    // void* 타입의 userdata를 Mat* 타입으로 형변환(Casting)
    Mat& image = *(Mat*)userdata;

    switch (event) {
    case EVENT_LBUTTONDOWN:
        // 왼쪽 버튼 클릭 시 Red로 변경 (BGR: 0, 0, 255)
        image.setTo(Scalar(0, 0, 255));
        cout << "Left button clicked: Background -> Red" << endl;
        break;

    case EVENT_RBUTTONDOWN:
        // 오른쪽 버튼 클릭 시 Blue로 변경 (BGR: 255, 0, 0)
        image.setTo(Scalar(255, 0, 0));
        cout << "Right button clicked: Background -> Blue" << endl;
        break;
    }
}
