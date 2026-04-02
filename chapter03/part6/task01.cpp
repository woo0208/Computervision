// *******************************************
// 제목: 실습 과제1
// 날짜: 2026년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 1. IMREAD_COLOR 옵션으로 이미지 로드
    Mat img = imread("frame.jpg", IMREAD_COLOR);

    if (img.empty()) {
        cerr << "Image load failed! 이미지를 찾을 수 없습니다." << endl;
        return -1;
    }

    // 2. 행(세로)과 열(가로) 출력 -> 멤버 변수이므로 괄호 없음
    cout << "열의 수 (Width, cols): " << img.cols << endl;
    cout << "행의 수 (Height, rows): " << img.rows << endl;

    // 3. 채널 수와 타입 출력 -> 멤버 함수이므로 괄호() 필수!
    cout << "채널 수 (Channels): " << img.channels() << endl;

    // 4. type 기호상수 출력
    // OpenCV 4에서 제공하는 typeToString() 함수를 사용하여 정수를 기호상수 문자열로 변환
    cout << "타입 (Type): " << typeToString(img.type()) << endl;

    imshow("img", img);
    waitKey(0);
    return 0;
}
