// *******************************************
// 제목: 실습 과제 5
// 날짜: 2026년 3월 24일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Mat 객체 생성: 세로 400, 가로 300, 8비트 1채널(Gray) 흑백 타입, 초기 화소값은 Black(0)로 설정
    Mat img(400, 400, CV_8UC1, Scalar(0));

    int brightness = 0;        // 현재 픽셀의 밝기
    int checkPoint = 0;        // 증감 상태를 결정하는 플래그 (0: 증가, 1: 감소)

    while (true) {

        // 밝기값이 최대치(255)에 도달하면 감소 상태(1)로 전환
        if (brightness == 255) {
            checkPoint = 1;
        }
        // 밝기값이 최소치(0)에 도달하면 증가 상태(0)로 전환
        else if (brightness == 0) {
            checkPoint = 0;
        }

        if (checkPoint == 0) {
            // 현재 밝기를 1씩 증가
            img.setTo(Scalar(brightness));
            brightness++;
        }
  
        else if (checkPoint == 1) {
            // 현재 밝기를 1씩 감소
            img.setTo(Scalar(brightness));
            brightness--;
        }

        // 영상 출력
        imshow("img", img);

        // 5ms 동안 대기하며 사용자 키 입력을 처리
        int key = waitKey(5);

        // 'q' 또는 'Q' 입력 시 무한 루프 종료
        if (key == 'q' || key == 'Q') {
            break;
        }

        cout << "현재 밝기: " << brightness << " (종료: 이미지 창에서 'q' 입력)" << endl;
    }

    // 모든 윈도우 닫기 및 메모리 해제
    destroyAllWindows();
    return 0;
}
