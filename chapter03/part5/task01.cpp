// *******************************************
// 제목: 실습 과제1
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 영상 불러오기
    Mat img = imread("lenna.bmp");

    // 예외 처리
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Vec3b p1 = img.at<Vec3b>(50, 50);
    Vec3b p2 = img.at<Vec3b>(100, 100);
    Vec3b p3 = img.at<Vec3b>(150, 150);

    cout << "좌표 (50,50)의 화소값(B,G,R):" << p1 << endl;
    cout << "좌표 (100,100)의 화소값(B,G,R):" << p2 << endl;
    cout << "좌표 (150,150)의 화소값(B,G,R):" << p3 << endl;

    imshow("img", img);
    waitKey();
    return 0;
}
