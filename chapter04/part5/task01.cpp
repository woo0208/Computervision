// *******************************************
// 제목: 실습 과제1
// 날짜: 2026년 4월 09일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct Data {
    Mat src;
    int pos = 0;
    int count = 0;
};

void on_change(int pos, void* userdata);

int main() {
    Data data;
    data.src = imread("lenna.bmp");
    if (data.src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("src");
    createTrackbar("level", "src", 0, 100, on_change, &data);
    while (true) {
        imshow("src", data.src);
        waitKey(10);
    }
    return 0;
}

void on_change(int pos, void* userdata) {
    Data* pdata = (Data*)userdata;
    pdata->pos = pos;
    cout << "트랙바 위치: " << pdata->pos << endl;
    circle(pdata->src, Point(pdata->src.rows / 2, pdata->src.cols / 2), pdata->pos, Scalar(0, 255, 0), 2);
}
