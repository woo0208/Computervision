// *******************************************
// 제목: 실습 과제3
// 날짜: 2026년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // lenna.bmp 파일을 BGR 컬러 모드로 불러와 Mat 객체 img에 저장
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    // 이미지 로드 실패 시 예외 처리
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    int bright = 0;
    cout << "밝기변화량을 입력:";
    cin >> bright; // 사용자로부터 정수형 밝기 조절 값 입력받음

    // [밝기 조절 연산]
    // 1. Scalar(bright, bright, bright)를 통해 B, G, R 모든 채널에 같은 값을 생성
    // 2. 행렬 + 스칼라 연산은 각 픽셀(화소)에 해당 값을 더하며, 
    //    OpenCV 내부적으로 255를 넘으면 255로 고정하는 '포화 연산(Saturate Cast)'이 수행됨
    Mat bright_img = img + Scalar(bright, bright, bright);

    // 원본 영상과 밝기가 조절된 결과 영상을 각각 별도의 창에 출력
    imshow("img", img);
    imshow("bright_img", bright_img);
    
    // 키보드 입력이 있을 때까지 대기하며 창을 유지
    waitKey(0);

    return 0;
}
