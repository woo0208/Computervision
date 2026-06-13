#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flags, void* userdata);
void on_trackbar(int pos, void* userdata);

struct Data {
    Mat img;
    Point sp;
    int sigma = 1;   // 표준편차 초기값 1
};

int main() {
    Data data;

    data.img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (data.img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");

    // 트랙바 범위: 0~9
    // 초기값은 data.sigma = 1
    createTrackbar("sigma", "img", &data.sigma, 9, on_trackbar, &data);
    setTrackbarPos("sigma", "img", 1);

    setMouseCallback("img", on_mouse, &data);

    imshow("img", data.img);

    while (true) {
        int key = waitKey(30);

        if (key == 'q') {
            break;
        }
    }

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
    Data* pdata = (Data*)userdata;

    switch (event) {
    case EVENT_LBUTTONDOWN:
        pdata->sp = Point(x, y);
        break;

    case EVENT_LBUTTONUP:
    {
        Point ep(x, y);

        int x1 = min(pdata->sp.x, ep.x);
        int y1 = min(pdata->sp.y, ep.y);
        int x2 = max(pdata->sp.x, ep.x);
        int y2 = max(pdata->sp.y, ep.y);

        // 가로 또는 세로가 0이면 정상적인 영역이 아니므로 처리하지 않음
        if (x1 == x2 || y1 == y2)
            break;

        Rect rect(Point(x1, y1), Point(x2, y2));

        // 이미지 범위를 벗어나지 않도록 제한
        rect &= Rect(0, 0, pdata->img.cols, pdata->img.rows);

        if (rect.width <= 0 || rect.height <= 0)
            break;

        Mat roi = pdata->img(rect);

        // 트랙바 값이 0이면 블러를 적용하지 않음
        // Size(0,0)에서 sigma=0을 넣으면 오류가 날 수 있음
        if (pdata->sigma == 0) {
            imshow("img", pdata->img);
            break;
        }

        Mat blurred;

        // 선택한 ROI 영역에만 GaussianBlur 적용
        GaussianBlur(roi, blurred, Size(0, 0), pdata->sigma);

        // 블러 처리된 결과를 원본 영상의 해당 영역에 복사
        blurred.copyTo(roi);

        imshow("img", pdata->img);
        break;
    }
    }
}

void on_trackbar(int pos, void* userdata) {
    Data* pdata = (Data*)userdata;

    // 트랙바 위치값을 표준편차 값으로 저장
    pdata->sigma = pos;
}
