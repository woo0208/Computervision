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
    // 1. 500x500 크기의 3채널 컬러 영상 생성 및 배경을 흰색으로 초기화
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));

    // 1회의 키 입력당 이동할 보폭(Stride) 설정 (50픽셀)
    int step = 50;

    // 2. 초기 좌표 설정 (영상의 정중앙)
    int x = img.cols / 2, y = img.rows / 2; // 현재 선이 끝나는 목표 좌표
    int prev_x = x, prev_y = y;           // 선이 시작되는 이전 좌표 (상태 보존용)

    // 3. 이벤트 루프 실행
    while (true) {
        // 현재까지 그려진 img 상태를 윈도우 창에 출력
        imshow("line", img);

        int key = waitKey(0);

        // 'q' 입력 시 프로그램 종료 루틴
        if (key == 'q' || key == 'Q') {
            cout << "프로그램 종료" << endl;
            break;
        }

        // [상태 백업] 이동을 계산하기 전, 현재 위치를 시작점(prev)으로 저장
        prev_x = x;
        prev_y = y;

        // [좌표 갱신] 키 입력에 따른 x, y 목표 좌표 계산
        if (key == 'l' || key == 'L') {
            cout << "왼쪽 이동" << endl;
            x -= step;
        }
        else if (key == 'r' || key == 'R') {
            cout << "오른쪽 이동" << endl;
            x += step;
        }
        else if (key == 'u' || key == 'U') {
            cout << "위쪽 이동" << endl;
            y -= step;
        }
        else if (key == 'd' || key == 'D') {
            cout << "아래쪽 이동" << endl;
            y += step;
        }

        // 선의 끝점이 영상 크기(500x500)를 벗어나는지 확인 (클리핑 방지)
        if (x < 0 || x > 500 || y < 0 || y > 500) {
            cout << "더 이상 갈 수 없습니다." << endl;
            // 화면을 벗어나면 이동을 취소하고 원래 위치로 롤백(Rollback)
            x = prev_x;
            y = prev_y;
        }

        // 좌표가 변경되었을 때만 이전 위치(prev)에서 새 위치(현재 x, y)로 직선을 그림
        if (x != prev_x || y != prev_y) {
            line(img, Point(prev_x, prev_y), Point(x, y), Scalar(0, 0, 0), 1);
        }
    }

    // 메모리 누수 방지를 위해 생성된 모든 윈도우 창 파괴
    destroyAllWindows();
    return 0;
}
