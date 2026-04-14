// *******************************************
// 제목: 실습 과제5
// 날짜: 2026년 4월 09일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void event_handler(int event, int x, int y, int flags, void* userdata);

Mat img; // 원본 영상
Point ptOld; // 시작 좌표를 기억하기 위한 전역/정적 변수

int main() {
    img = imread("lenna.bmp"); // 컬러로 읽기
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("img");
    setMouseCallback("img", event_handler);

    while (true) {
        imshow("img", img);
        if (waitKey(10) == 'q') break;
    }
    return 0;
}

void event_handler(int event, int x, int y, int flags, void* userdata) {
    switch (event) {
    case EVENT_LBUTTONDOWN:
        // 마우스 왼쪽 버튼을 누르는 순간의 좌표를 저장
        ptOld = Point(x, y);
        cout << "시작점: " << ptOld << endl;
        break;


    case EVENT_LBUTTONUP:
    {
        // 마우스를 떼는 순간의 좌표
        Point ptEnd(x, y);
        cout << "종료점: " << ptEnd << endl;

        // 드래그한 영역의 사각형 객체 생성
        Rect roi_rect(ptOld, ptEnd);

        // 예외 처리: 드래그를 반대로 하거나 영역이 0일 경우 대비
        // (width나 height가 0보다 커야 함)
        if (roi_rect.width > 0 && roi_rect.height > 0) {
            // 원본 영상(img)에서 ROI 추출 (얕은 복사)
            Mat roi = img(roi_rect);

            // 추출된 영역을 새 창에 출력
            namedWindow("ROI");
            imshow("ROI", roi);

            // (옵션) 원본에 사각형 그리기 - 시각적 확인용
            rectangle(img, roi_rect, Scalar(0, 255, 0), 2);
        }
        break;
    }
    }
}
