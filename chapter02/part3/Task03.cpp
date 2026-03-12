// *********************************
// 제 목  : 실습과제3 - C-스타일 배열을 이용한 초시계
// 날 짜  : 2026년 3월 12일
// 작성자 : 2603043 한정우
// *********************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 1. Mat 클래스의 배열 선언 (0부터 9까지 저장할 공간 10개)
    Mat imgs[10];

    // 2. 반복문을 이용한 영상 로드 및 배열 저장
    for (int i = 0; i < 10; i++) {
        // format을 사용하여 "0.png", "1.png" 등의 이름을 생성하여 로드
        imgs[i] = imread(format("%d.png", i));

        if (imgs[i].empty()) {
            cerr << i << ".png load failed!" << endl;
            return -1;
        }
    }

    // 3. 출력 및 반복 (배열의 인덱스를 사용하여 코드를 단축)
    namedWindow("timer");
    for (int i = 0; i < 10; i++) {
        // if문 대신 배열의 인덱스 i를 직접 사용 (코드 최적화)
        imshow("timer", imgs[i]);

        // 1000ms 대기 (1초 간격 출력)
        if (waitKey(1000) == 27) break;
    }

    return 0;
}