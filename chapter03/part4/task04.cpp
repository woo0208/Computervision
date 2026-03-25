// *******************************************
// 제목: 실습 과제4
// 날짜: 26년 3월 25일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("dog.bmp");
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }


    Mat img_original;
    img.copyTo(img_original);
    Mat copybon = img(Rect(103, 36, 79, 99));

    copybon = Scalar(255, 0, 0);

    int count = 0;
    while (true) {
        if (count % 2 == 0) {
            imshow("img", img_original);
        }
        else {
            imshow("img", img);
        }

        count++;
        int key = waitKey(1000);

        if (key == 'q' || key == 'Q') {
            break;
        }

        cout << "현재 카운트: " << count << " (종료하려면 이미지 창에서 'q' 입력)" << endl;
    }

    destroyAllWindows();

    return 0;
}
