// *******************************************
// 제목: 실습 과제 8 
// 날짜: 2026년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // 1. 500x500 3채널 컬러 영상 생성 (배경: 흰색)
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));
    int step = 100; // 한 칸의 크기 (500픽셀 / 5칸 = 100)

    // 2. 초기 바둑판 모양 격자 그리기
    for (int i = 0; i <= 500; i += step) {
        line(img, Point(i, 0), Point(i, 500), Scalar(0, 0, 0), 1); // 수직선
        line(img, Point(0, i), Point(500, i), Scalar(0, 0, 0), 1); // 수평선
    }

    // 3. 버튼의 초기 위치 설정 (정중앙 칸: x=200, y=200)
    int x = 200, y = 200;
    int prev_x = x, prev_y = y;

    // 초기 파란색 버튼 출력
    rectangle(img, Rect(x, y, step, step), Scalar(255, 0, 0), -1); // 파란색으로 채우기 (-1)
    rectangle(img, Rect(x, y, step, step), Scalar(0, 0, 0), 1);    // 테두리는 검은색 유지

    // 4. 이벤트 루프
    while (true) {
        imshow("Game", img);

        // 무한 대기하며 사용자 키보드 입력 수신
        int key = waitKey(0);

        // 'q' 입력 시 프로그램 종료
        if (key == 'q' || key == 'Q') {
            cout << "프로그램 종료" << endl;
            break;
        }

        // 이동하기 전 현재 위치를 이전 위치 변수에 백업
        prev_x = x;
        prev_y = y;

        // 키 입력에 따른 좌표 이동 계산 (l, r, u, d)
        if (key == 'l' || key == 'L') {
            cout << "왼쪽 이동" << endl;
            x -= step;      // 왼쪽
        }
        else if (key == 'r' || key == 'R') {
            cout << "오른쪽 이동" << endl;
            x += step; // 오른쪽
        }
        else if (key == 'u' || key == 'U') {
            cout << "위쪽 이동" << endl;
            y -= step; // 위쪽
        }
        else if (key == 'd' || key == 'D') {
            cout << "아래쪽 이동" << endl;
            y += step; // 아래쪽
        }

        // 윈도우 창(500x500)을 벗어나는지 확인
        // 한 칸의 크기가 100이므로, x나 y가 400보다 크면 화면을 벗어난 것임
        if (x < 0 || x > 400 || y < 0 || y > 400) {
            // 벗어났다면 이동을 취소하고 이전 위치 유지
            cout << "더 이상 갈 수 없습니다." << endl;
            x = prev_x;
            y = prev_y;
        }

        // 위치가 변경되었을 때만 화면 다시 그리기
        if (x != prev_x || y != prev_y) {
            // 이전 위치 지우기 (흰색으로 채운 뒤, 검은색 테두리 복구)
            rectangle(img, Rect(prev_x, prev_y, step, step), Scalar(255, 255, 255), -1);
            rectangle(img, Rect(prev_x, prev_y, step, step), Scalar(0, 0, 0), 1);

            // 새로운 위치에 파란색 버튼 그리기
            rectangle(img, Rect(x, y, step, step), Scalar(255, 0, 0), -1);
            rectangle(img, Rect(x, y, step, step), Scalar(0, 0, 0), 1);
        }
    }

    destroyAllWindows();
    return 0;
}
