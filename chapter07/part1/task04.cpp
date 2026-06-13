#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flags, void* userdata);

struct Data {
    Mat src;              // 원본 이미지
    string dstWindow;     // 결과 출력 창 이름
};

int main() {
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Data data;
    data.src = src;
    data.dstWindow = "dst";

    // 입력 영상 창 생성
    namedWindow("src");

    // 결과 출력 창 생성
    namedWindow("dst");

    // 입력 영상 출력
    imshow("src", src);

    // 처음에는 결과 창에도 원본 영상을 출력
    imshow("dst", src);

    // src 창에서 마우스 이벤트를 받도록 설정
    setMouseCallback("src", on_mouse, &data);

    waitKey();
    return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
    Data* pdata = (Data*)userdata;

    Mat mask;
    Mat dst;

    switch (event) {
    case EVENT_LBUTTONDOWN:
    {
        // 실습과제 1: 평균값 필터
        float data1[] = {
            1 / 9.f, 1 / 9.f, 1 / 9.f,
            1 / 9.f, 1 / 9.f, 1 / 9.f,
            1 / 9.f, 1 / 9.f, 1 / 9.f
        };

        mask = Mat(3, 3, CV_32FC1, data1);

        filter2D(pdata->src, dst, -1, mask, Point(-1, -1), 0);

        imshow(pdata->dstWindow, dst);
        break;
    }

    case EVENT_RBUTTONDOWN:
    {
        // 실습과제 2: 샤프닝 필터
        float data2[] = {
            -1, -1, -1,
            -1,  9, -1,
            -1, -1, -1
        };

        mask = Mat(3, 3, CV_32FC1, data2);

        filter2D(pdata->src, dst, -1, mask, Point(-1, -1), 0);

        imshow(pdata->dstWindow, dst);
        break;
    }

    case EVENT_LBUTTONDBLCLK:
    {
        // 실습과제 3: 소벨 필터, x방향 에지 검출
        float data3[] = {
            -1, 0, 1,
            -2, 0, 2,
            -1, 0, 1
        };

        mask = Mat(3, 3, CV_32FC1, data3);

        filter2D(pdata->src, dst, -1, mask, Point(-1, -1), 0);

        imshow(pdata->dstWindow, dst);
        break;
    }
    }
}
