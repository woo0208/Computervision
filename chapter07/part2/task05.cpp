#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flags, void* userdata);

struct Data {
    Mat img;     // 실제 출력 및 수정할 이미지
    Point sp;    // 드래그 시작점
};

int main() {
    Data data;

    // lenna 영상을 그레이스케일로 읽기
    data.img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (data.img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 마우스 이벤트를 받을 창 생성
    namedWindow("img");

    // img 창에 마우스 콜백 함수 등록
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
        // 마우스 왼쪽 버튼을 누른 위치 저장
        pdata->sp = Point(x, y);
        break;

    case EVENT_LBUTTONUP:
    {
        // 마우스 왼쪽 버튼을 뗀 위치
        Point ep(x, y);

        // 드래그 방향과 관계없이 정상적인 사각형 영역 생성
        int x1 = min(pdata->sp.x, ep.x);
        int y1 = min(pdata->sp.y, ep.y);
        int x2 = max(pdata->sp.x, ep.x);
        int y2 = max(pdata->sp.y, ep.y);

        // 선택 영역의 폭과 높이 계산
        int w = x2 - x1;
        int h = y2 - y1;

        // 너무 작은 영역이면 처리하지 않음
        if (x1 == x2 || y1 == y2) break;

        // 이미지 범위를 벗어나지 않도록 영역 제한
        Rect rect(Point(x1,y1), Point(x2,y2));
        rect &= Rect(0, 0, pdata->img.cols, pdata->img.rows);

        // 선택 영역 ROI 생성
        Mat roi = pdata->img(rect);

        // ROI에만 가우시안 블러 적용
        // 표준편차 sigma = 5
        Mat blurred;
        GaussianBlur(roi, blurred, Size(0, 0), 5.0);

        // 블러 처리된 결과를 원본 이미지의 해당 영역에 복사
        blurred.copyTo(roi);

        // 결과 출력
        imshow("img", pdata->img);

        break;
    }
    }
}
