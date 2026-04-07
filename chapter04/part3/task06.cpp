// *******************************************
// 제목: 실습 과제 6
// 날짜: 2026년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // 1. Lenna 영상을 컬러 영상으로 로드
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 2. 출력할 문자열 및 폰트 설정
    string text = "Hello, Lenna";
    int fontFace = FONT_HERSHEY_SIMPLEX; // 폰트 종류
    double fontScale = 1.5;              // 폰트 크기 배율
    int thickness = 3;                   // 선 두께
    Scalar color(0, 255, 255);           // 노란색 (BGR: 0, 255, 255)

    // 3. 문자열이 차지할 실제 크기(Width, Height) 계산
    int baseLine = 0;
    Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseLine);

    // 4. 상단 중앙 위치 계산
    // x 좌표: (영상의 가로 길이 - 문자열의 가로 길이) / 2
    // y 좌표: 상단에 위치시키되, 글자 높이만큼 여백(padding)을 줌
    int x = (img.cols - textSize.width) / 2;
    int y = textSize.height + 30; // 상단에서 30픽셀 정도 내려온 위치

    // 5. 영상에 문자열 출력
    // Point(x, y)는 문자열의 좌측 하단(Bottom-Left) 기준 좌표임
    putText(img, text, Point(x, y), fontFace, fontScale, color, thickness, LINE_AA);

    // 6. 결과 출력
    imshow("Lenna_image", img);
    waitKey(0);

    return 0;
}
