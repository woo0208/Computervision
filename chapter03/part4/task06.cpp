// *******************************************
// 제목: 실습 과제6
// 날짜: 26년 3월 26일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 이미지 불러오기
    Mat img = imread("lenna.bmp");

    // 이미지 불러오기 실패시 예외처리
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 사용자 좌표 및 폭&높이 입력 받기
    int x, y, width, height, value;
    cout << "관심영역의 좌측상단좌표(x, y): ";
    cin >> x >> y;
    cout << "관심영역의 폭,높이(width, height): ";
    cin >> width >> height;
    cout << "픽셀변화량: ";
    cin >> value;

    Rect img_area(0, 0, img.cols, img.rows); // 원본 영상의 전체 크기
    Rect input_rect(x, y, width, height);      // 사용자가 입력한 영역

    // 얕은 복사로 메모리 절약
    Mat result = img(input_rect);

    // 밝기 조절 = 3채널(BGR) 컬러 영상이므로, 동일하게 value 값 추가
    result += Scalar(value, value, value);

    imshow("img", img);
    waitKey();
    destroyAllWindows();

    return 0;
}
