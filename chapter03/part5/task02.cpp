// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 1. 그레이스케일 모드로 영상 로드 (1채널 8비트 데이터 구조)
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 2. 가로선(Horizontal Lines) 생성 루프
    // img.rows/4를 증감식(Step)으로 사용하여 이미지 높이의 1/4 간격마다 반복
    for (int y = 0; y < img.rows; y += img.rows/4) { 
        for (int x = 0; x < img.cols; x++) {
            // 해당 행(y)의 모든 열(x) 화소값을 255(흰색)로 설정
            img.at<uchar>(y, x) = 255;
        }
    }

    // 3. 세로선(Vertical Lines) 생성 루프
    // img.cols/4를 증감식(Step)으로 사용하여 이미지 너비의 1/4 간격마다 반복
    for (int x = 0; x < img.cols; x += img.cols/4) { 
        for (int y = 0; y < img.rows; y++) {
            // 해당 열(x)의 모든 행(y) 화소값을 255(흰색)로 설정
            img.at<uchar>(y, x) = 255;
        }
    }

    // 4. 결과 출력 및 대기
    imshow("Line", img);
    waitKey(0);
    return 0;
}
