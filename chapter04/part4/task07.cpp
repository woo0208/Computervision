#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 버튼 영역 정의 (폭 200, 높이 100)
Rect btnRed(0, 0, 200, 100);
Rect btnGreen(0, 100, 200, 100);
Rect btnBlue(0, 200, 200, 100);

Mat img(300, 500, CV_8UC3);
string msg = " ";

// 화면을 그리는 함수 (중복 코드를 방지하기 위해 분리)
void drawMenu(int pressedBtn = -1) {
    img.setTo(Scalar(255, 255, 255)); // 배경 흰색 초기화

    // 버튼 3개 그리기
    rectangle(img, btnRed, Scalar(0, 0, 0), 2);
    rectangle(img, btnGreen, Scalar(0, 0, 0), 2);
    rectangle(img, btnBlue, Scalar(0, 0, 0), 2);

    // 클릭된 버튼 배경 채우기
    if (pressedBtn == 0) rectangle(img, btnRed, Scalar(0, 0, 0), -1);
    if (pressedBtn == 1) rectangle(img, btnGreen, Scalar(0, 0, 0), -1);
    if (pressedBtn == 2) rectangle(img, btnBlue, Scalar(0, 0, 0), -1);

    // 버튼 텍스트 (배경이 검은색이면 글자를 흰색으로)
    putText(img, "Red", Point(70, 60), FONT_HERSHEY_SIMPLEX, 1, (pressedBtn == 0 ? Scalar(255, 255, 255) : Scalar(0, 0, 0)), 2);
    putText(img, "Green", Point(50, 160), FONT_HERSHEY_SIMPLEX, 1, (pressedBtn == 1 ? Scalar(255, 255, 255) : Scalar(0, 0, 0)), 2);
    putText(img, "Blue", Point(65, 260), FONT_HERSHEY_SIMPLEX, 1, (pressedBtn == 2 ? Scalar(255, 255, 255) : Scalar(0, 0, 0)), 2);

    // 우측 메시지 출력
    putText(img, msg, Point(220, 160), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 0), 2);

    imshow("Menu", img);
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_LBUTTONDOWN) {
        Point pt(x, y);

        if (btnRed.contains(pt)) {
            msg = "Red pressed.";
            drawMenu(0);
        }
        else if (btnGreen.contains(pt)) {
            msg = "Green pressed.";
            drawMenu(1);
        }
        else if (btnBlue.contains(pt)) {
            msg = "Blue pressed.";
            drawMenu(2);
        }
    }
}

int main() {
    drawMenu(); // 초기 화면 구성
    setMouseCallback("Menu", on_mouse);

    while (waitKey(10) != 'q');
    return 0;
}
