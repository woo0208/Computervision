#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat img(200, 600, CV_8UC3, Scalar(255, 255, 255));

    Mat blue_roi = img(Rect(0, 0, 200, 200));   // 첫 번째 칸
    Mat green_roi = img(Rect(200, 0, 200, 200)); // 두 번째 칸
    Mat red_roi = img(Rect(400, 0, 200, 200)); // 세 번째 칸

    // 얕은 복사(Shallow Copy)이므로 roi를 수정하면 원본 img가 바뀝니다.
    blue_roi.setTo(Scalar(255, 0, 0));  // Blue
    green_roi.setTo(Scalar(0, 255, 0)); // Green
    red_roi.setTo(Scalar(0, 0, 255));   // Red

    // 각 ROI 내부에 흰색 도형 그리기

    // [Blue ROI] 흰색 사각형
    rectangle(blue_roi, Rect(50, 50, 100, 100), Scalar(255, 255, 255), 5);

    // [Green ROI] 흰색 원
    circle(green_roi, Point(100, 100), 60, Scalar(255, 255, 255), 5, LINE_AA);

    // [Red ROI] 흰색 X자 (두 개의 선)
    line(red_roi, Point(50, 50), Point(150, 150), Scalar(255, 255, 255), 5, LINE_AA);
    line(red_roi, Point(150, 50), Point(50, 150), Scalar(255, 255, 255), 5, LINE_AA);

    imshow("img", img);
    waitKey(0);

    return 0;
}
