// *******************************************
// 제목: 실습 과제2
// 날짜: 2026년 4월 09일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct metadata {
    Mat img;
    // 초기화 리스트를 통해 0으로 초기화
    int mousemove = 0;
    int upbtn = 0;
    int downbtn = 0;
};

void on_mouse(int event, int x, int y, int flag, void* userdata) {
    metadata* count = (metadata*)userdata;
    
    // 이미지가 비어있는지 확인 (방어적 프로그래밍)
    if (count->img.empty()) return;

    switch (event)
    {
    case EVENT_MOUSEMOVE:
        count->mousemove++;
        cout << "EVENT_MOUSEMOVE: " << count->mousemove << endl;
        break;

    case EVENT_LBUTTONDOWN:
        count->downbtn++;
        cout << "EVENT_LBUTTONDOWN: " << count->downbtn << endl;
        break;

    case EVENT_LBUTTONUP:
        count->upbtn++;
        cout << "EVENT_LBUTTONUP: " << count->upbtn << endl;
        break;
    }

    // 마우스 이벤트가 발생할 때마다 윈도우 갱신
    imshow("img", count->img);
}

int main() {
    metadata data;
    data.img = imread("lenna.bmp");

    // 이미지 로드 확인
    if (data.img.empty()) {
        cout << "이미지를 찾을 수 없습니다." << endl;
        return -1;
    }

    // 1. 먼저 윈도우를 생성해야 함
    namedWindow("img");

    // 2. 초기 이미지를 먼저 보여줌
    imshow("img", data.img);

    // 3. 그 후에 콜백 함수 등록
    setMouseCallback("img", on_mouse, &data);

    while (true) {
        if (waitKey(10) == 'q') break;
    }

    destroyAllWindows();
    return 0;
}
