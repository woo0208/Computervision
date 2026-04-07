// *******************************************
// 제목: 실습 과제 7
// 날짜: 2026년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // 1. 300x300 크기의 컬러 영상 생성
    Mat img(300, 300, CV_8UC3);

    int count = 0;            // 초시계 카운트 변수
    bool isRunning = false;   // 현재 타이머가 동작 중인지 확인하는 상태 플래그

    while (true) {
        // 매 루프마다 배경을 흰색으로 초기화
        img.setTo(Scalar(255, 255, 255));

        // format 함수를 사용하여 정수를 문자열로 변환 (조건 충족)
        String text = format("%d", count);

        // 정중앙 좌표 계산
        int baseLine = 0;
        Size textSize = getTextSize(text, FONT_HERSHEY_DUPLEX, 4.0, 5, &baseLine);
        int x = (img.cols - textSize.width) / 2;
        int y = (img.rows + textSize.height) / 2;

        // putText와 imshow는 루프 내에서 오직 1번만 호출됨 (조건 충족)
        putText(img, text, Point(x, y), FONT_HERSHEY_DUPLEX, 4.0, Scalar(0, 0, 0), 5, LINE_AA);
        imshow("Stopwatch", img);

        // 동작 중이면 1000ms(1초) 대기, 정지 중이면 10ms(빠른 반응) 대기
        int delay = isRunning ? 1000 : 10;

        // waitKey를 이용한 시간 제어 및 문자 입력 (조건 충족)
        int key = waitKey(delay);

        // 상태(State) 전이 로직
        if (key == 'q' || key == 'Q') {
            break; // 프로그램 종료
        }
        else if (key == 's' || key == 'S') {
            isRunning = true; // 카운트 시작
        }
        else if (key == 't' || key == 'T') {
            isRunning = false; // 카운트 정지
        }
        else if (key == 'r' || key == 'R') {
            isRunning = false; // 리셋 시 정지 상태로 전환
            count = 0;         // 카운트 0으로 초기화
        }

        // 타이머가 작동 중이고, 1초(1000ms) 동안 아무 키도 눌리지 않아 타임아웃(-1 반환)이 발생했을 때만 1초 증가
        if (isRunning && key == -1) {
            count++;
        }
    }

    destroyAllWindows();
    return 0;
}
