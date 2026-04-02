// *******************************************
// 제목: 실습 과제2
// 날짜: 2026년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 외부 데이터를 이용한 행렬 원소 초기화 (Double 타입 배열)
    // 데이터 손실을 방지하기 위해 정수형 대신 부동소수점(double) 타입을 사용함
    double A[] = { 1, 3, -4, 2 };
    double B[] = { 2, 3, 0, 5 };
    double C[] = { -2, -2, -2, -3 };

    // Mat 객체 생성 및 외부 메모리 참조
    Mat matA(2, 2, CV_64FC1, A);
    Mat matB(2, 2, CV_64FC1, B);
    Mat matC(2, 2, CV_64FC1, C);

    // [행렬 수식 연산]
    Mat X = 3 * matA + matB.inv() + 10 * matC - 5;

    // 표준 출력 스트림을 통한 최종 행렬 X의 원소값 출력
    cout << "X:\n" << X << endl;

    return 0;
}
