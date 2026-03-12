#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    int count = 0;
    cout << "Hello OpenCV" << CV_VERSION << endl;  // 버전 정보 확인
    Mat img0,img1,img2;
    img0 = imread("img0.png");                     // 이미지1 가져오기
    img1 = imread("img1.png");                     // 이미지2 가져오기
    img2 = imread("img2.png");                     // 이미지3 가져오기

    if (img0.empty() || img1.empty() || img2.empty()) {  // 하나의 이미지라도 비어있다면 에러 반환
        cerr << "Image load failed" << endl;
        return -1;
    }
    namedWindow("image");
    while (true) {
        if (count == 0) imshow("image", img0);      // count 가 0이면 이미지1을
        if (count == 1) imshow("image", img1);      // count 가 1이면 이미지2를
        if (count == 2) imshow("image", img2);      // count 가 2이면 이미지3을
        if (waitKey(1000) == 27) break;             // ESC 를 누르면 종료하도록 설정
        count = (count + 1) % 3;                    // count 가 계속 0,1,2 를 반복하도록 수식 설정
    }

    return 0;
}