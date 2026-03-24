#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 소수점 있으므로 double 타입 사용
    double matdata1[] = { 3.5,2.1,-1.5,-6.5 };
    double matdata2[] = { 0,2,-1,5,10,8,6,-7,9 };
    double matdata3[] = { 1,2,3,4 };
    double matdata4[] = { 5,6,7,8 };

    // 원하는 행(세로),열(가로) double 타입과 맞는 CV_64FC1 사용, 객체는 항상 주소에 의한 참조 써야함(객체를 넘기면 메모리 낭비 심함)
    Mat mat1(2, 2, CV_64FC1, &matdata1);
    Mat mat2(3, 3, CV_64FC1, &matdata2);
    Mat mat3(1, 4, CV_64FC1, &matdata3);
    Mat mat4(4, 1, CV_64FC1, &matdata4);
    cout << "mat1:\n" << mat1 << endl;
    cout << "mat2:\n" << mat2 << endl;
    cout << "mat3:\n" << mat3 << endl;
    cout << "mat4:\n" << mat4 << endl;

    return 0;

}
