#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void on_mouse(int event, int x, int y, int flag, void* userdata);
void on_trackbar(int pos, void* userdata);

struct Data {
    int pos = 0;   // alpha 초기값
    Point sp;
};

int main() {
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Data data;
    data.pos = 0;

    Mat blurred;
    Mat dst;

    // 가우시안 필터 대신 평균값 필터 사용
    blur(src, blurred, Size(5, 5));

    imshow("src", src);

    // 트랙바를 붙일 결과 창을 먼저 생성
    namedWindow("dst");

    // alpha 값 0~50
    createTrackbar("alpha", "dst", &data.pos, 50, on_trackbar, &data);

    while (true) {
        int alpha = data.pos;

        // 선명화 공식
        // dst = (1 + alpha) * src - alpha * blurred
        dst = (1 + alpha) * src - alpha * blurred;

        String desc = format("Alpha: %d", alpha);

        putText(dst, desc, Point(10, 30),
            FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        imshow("dst", dst);

        int key = waitKey(30);
        if (key == 'q')
            break;
    }

    return 0;
}


void on_mouse(int event, int x, int y, int flag, void* userdata) {
    Data* pdata = (Data*)userdata;

}


void on_trackbar(int pos, void* userdata) {
    Data* pdata = (Data*)userdata;
    pdata->pos = pos;
}
