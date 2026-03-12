// *********************************
// 제 목  : 실습과제2 - 기초 배열을 이용한 영상 출력
// 날 짜  : 2026년 3월 12일
// 작성자 : 2603043 한정우
// *********************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 1. Mat 객체 배열 선언 (수업 진도에 맞춘 C-스타일 배열)
    Mat imgs[3];

    // 2. 반복문을 이용한 영상 로드 (최대한 짧게 구현)
    for (int i = 0; i < 3; i++) {
        // format을 사용하여 img0.png, img1.png, img2.png를 차례로 읽음
        imgs[i] = imread(format("img%d.png", i));

        if (imgs[i].empty()) {
            cerr << "Image load failed!" << endl;
            return -1;
        }
    }

    // 3. 하나의 윈도우에 1초 간격으로 무한 반복 출력
    namedWindow("image");
    int idx = 0; // 현재 출력할 배열의 인덱스

    while (true) {
        imshow("image", imgs[idx]);

        // [핵심] waitKey 1회 호출로 1000ms(1초) 대기 및 키 입력 확인
        if (waitKey(1000) == 27) break; // ESC 키를 누르면 종료

        // 인덱스 순환 연산: 0 -> 1 -> 2 -> 0 ...
        idx = (idx + 1) % 3;
    }

    return 0;
}
