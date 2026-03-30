// *******************************************
// 제목: 실습 과제4
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 1. 400x400 크기의 8비트 단일 채널(Grayscale) 행렬 생성 및 배경을 흰색(255)으로 초기화
    Mat img(400, 400, CV_8UC1, Scalar(255));

    // 2. 포물선 궤적 계산 및 화소값 투사
    // x축(열, Column)을 기준으로 루프를 수행하며 대응하는 y축(행, Row) 값을 계산
    for (int x = 0; x < img.cols; x++) {
        // 이차함수 y = (1/400) * x^2 수식을 적용하여 좌표 산출
        // 정수 나눗셈에 의한 데이터 손실을 방지하기 위해 실수형(double) 리터럴 사용
        int y = 1.0 / 400.0 * x * x;

        // 계산된 y값이 이미지 해상도(행의 수) 범위 내에 있는지 확인하며 화소를 검은색(0)으로 변경
        // OpenCV의 at<uchar>(y, x)는 행(y), 열(x) 순서로 접근함
        if (y < img.rows) {
            img.at<uchar>(y, x) = 0;
        }
    }

    // 3. 결과 영상 렌더링 및 대기
    imshow("Line", img);
    waitKey(0);
    return 0;
}
