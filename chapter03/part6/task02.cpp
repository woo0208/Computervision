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
    double A[] = { 1,3,-4, 2 };
    double B[] = { 2,3,0,5 };
    double C[] = { -2,-2,-2,-3 };

    Mat matA(2, 2, CV_64FC1, A);
    Mat matB(2, 2, CV_64FC1, B);
    Mat matC(2, 2, CV_64FC1, C);

    Mat X = 3 * matA + matB.inv() + 10 * matC - 5;

    cout << "X:\n" << X << endl;

    return 0;
}
