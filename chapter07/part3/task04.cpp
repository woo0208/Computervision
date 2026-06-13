#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void on_mouse(int event, int x, int y, int flags, void* userdata);

struct Data {
    Mat img;     // 마우스로 선택한 영역을 직접 수정할 영상
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

    // 영상 출력 창 생성
    namedWindow("img");

    // 마우스 이벤트 등록
    setMouseCallback("img", on_mouse, &data);

    // 원본 영상 출력
    imshow("img", data.img);

    while (true) {
        int key = waitKey(30);

        if (key == 'q')
            break;
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

        // 드래그 방향과 관계없이 왼쪽 위, 오른쪽 아래 좌표 계산
        int x1 = min(pdata->sp.x, ep.x);
        int y1 = min(pdata->sp.y, ep.y);
        int x2 = max(pdata->sp.x, ep.x);
        int y2 = max(pdata->sp.y, ep.y);

        // 영역의 가로 또는 세로가 0이면 처리하지 않음
        if (x1 == x2 || y1 == y2)
            break;

        // 선택 영역 생성
        Rect rect(Point(x1, y1), Point(x2, y2));

        // 이미지 범위를 벗어나지 않도록 제한
        rect &= Rect(0, 0, pdata->img.cols, pdata->img.rows);

        if (rect.width <= 0 || rect.height <= 0)
            break;

        // 선택 영역 ROI
        Mat roi = pdata->img(rect);

        // 샤프닝 마스크
        float data[] = {
            -1, -1, -1,
            -1,  9, -1,
            -1, -1, -1
        };

        Mat mask(3, 3, CV_32FC1, data);

        // 선택 영역에만 샤프닝 필터 적용
        Mat sharp;
        filter2D(roi, sharp, -1, mask, Point(-1, -1), 0);

        // 필터링 결과를 원본 영상의 선택 영역에 복사
        sharp.copyTo(roi);

        // 결과 출력
        imshow("img", pdata->img);

        break;
    }
    }
}
