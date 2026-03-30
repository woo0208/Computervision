// *******************************************
// 제목: 실습 과제3
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 1. 컬러 영상 로드 (3채널 BGR 구조의 Mat 객체 생성)
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    // 2. 가로선 주사 및 화소 값 수정 (Row-wise Scan)
    // 이미지 전체 높이를 4등분한 간격으로 특정 행(Row)에 접근
    for (int y = 0; y < img.rows; y += img.rows/4) { 
        for (int x = 0; x < img.cols; x++) {
            // Vec3b 배열 인덱스(0:Blue, 1:Green, 2:Red)를 각각 255로 설정하여 흰색 구현
            img.at<Vec3b>(y, x)[0] = 255;
            img.at<Vec3b>(y, x)[1] = 255;
            img.at<Vec3b>(y, x)[2] = 255;
        }
    }

    // 3. 세로선 주사 및 화소 값 수정 (Column-wise Scan)
    // 이미지 전체 너비를 4등분한 간격으로 특정 열(Column)에 접근
    for (int x = 0; x < img.cols; x += img.cols / 4) { 
        for (int y = 0; y < img.rows; y++) {
            // 해당 좌표의 모든 색상 채널을 최대 강도(Full Saturation)로 할당
            img.at<Vec3b>(y, x)[0] = 255;
            img.at<Vec3b>(y, x)[1] = 255;
            img.at<Vec3b>(y, x)[2] = 255;
        }
    }

    // 4. 처리된 영상 렌더링 및 출력
    imshow("Line", img);
    waitKey(0);
    return 0;
}
