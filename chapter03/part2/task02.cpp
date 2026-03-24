#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    int b, g, r;

    cout << "Blue값(0~255)을 입력하시오: ";
    cin >> b;
    cout << "Green값(0~255)을 입력하시오: ";
    cin >> g;
    cout << "Red값(0~255)을 입력하시오: ";
    cin >> r;

    // Scalar 객체 생성. 
    // 4번째 원소는 자동으로 0.0으로 초기화
    Scalar color(b, g, r);

    // Scalar는 double 타입 => 형변환 X
    cout << "입력한 컬러값은  ["
        << color[0] << ", "
        << color[1] << ", "
        << color[2] << ", "
        << color[3] << "] 입니다." << endl;

    return 0;
}
