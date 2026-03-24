// *******************************************
// 제목: 실습 과제1
// 날짜: 26년 3월 24일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    int b, g, r;

    // uchar 타입에 직접 cin >> 을 사용하면 문자로 인식 
    // int형 변수로 먼저 입력받은 후 형변환(Casting)
    cout << "Blue값(0~255)을 입력하시오: ";
    cin >> b;
    cout << "Green값(0~255)을 입력하시오: ";
    cin >> g;
    cout << "Red값(0~255)을 입력하시오: ";
    cin >> r;

    // Vec3b 객체 생성 및 값 할당 (uchar 타입으로 다시 변형)
    Vec3b color((uchar)b, (uchar)g, (uchar)r);

    // Vec3b 내부 원소는 uchar이므로, 숫자로 출력하기 위해 다시 int로 형변환
    cout << "입력한 컬러값은  ["
        << (int)color[0] << ", "
        << (int)color[1] << ", "
        << (int)color[2] << "] 입니다." << endl;

    return 0;
}
