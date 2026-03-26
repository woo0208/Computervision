// *******************************************
// 제목: 실습 과제5
// 날짜: 26년 3월 26일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 높이 200, 폭 600 이미지 생성
    Mat img(200, 600, CV_8UC3);

    int count = 0;

    while (true) {
        // 매 프레임마다 흰색 배경 초기화
        img = Scalar(255, 255, 255);

        // 0,1,2로 나누어 200씩 좌표 이동
        int x_offset = (count % 3) * 200;

        // Rect(x, y, width, height)를 사용해 빨간색 사각형의 위치를 동적으로 이동
        img(Rect(x_offset, 0, 200, 200)) = Scalar(0, 0, 255);

        // imshow 한번만 사용
        imshow("img", img);

        // 1초마다 갱신 & q 입력시 종료
        int key = waitKey(1000);
        if (key == 'q' || key == 'Q') {
            break;
        }

        count++;
        cout << "현재 카운트: " << count << " (종료하려면 이미지 창에서 'q' 입력)" << endl;

    }

    // 모든 윈도우 창 종료
    destroyAllWindows();
    return 0;
}
