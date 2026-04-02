// *******************************************
// 제목: 실습 과제3 (실시간 영상 스냅샷 저장)
// 날짜: 26년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    // 시스템의 기본 카메라(Index 0) 장치를 호출하여 VideoCapture 객체 생성
    VideoCapture cap(0);

    // 카메라 장치가 정상적으로 활성화되었는지 확인 (예외 처리)
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    int fileCount = 1; // 저장될 파일의 일련번호를 관리하는 변수
    Mat frame;         // 카메라로부터 한 프레임을 담을 행렬 객체

    while (true) {
        // 카메라 장치로부터 현재 시점의 프레임을 받아와 frame에 저장
        cap >> frame;

        // 스트리밍 중 프레임 데이터가 유효하지 않을 경우 루프 중단
        if (frame.empty()) {
            cerr << "frame empty!" << endl;
            break;
        }

        // 현재 받아온 프레임을 "frame"이라는 이름의 윈도우 창에 출력
        imshow("frame", frame);

        // 약 30 FPS(Frames Per Second) 속도로 화면을 갱신하며 키 입력을 대기
        int key = waitKey(33);

        // 'q' 또는 'Q' 입력 시 프로그램 종료 (루프 탈출)
        if (key == 'q' || key == 'Q') {
            break;
        } 
        // 's' 또는 'S' 입력 시 현재 프레임을 이미지 파일로 저장 (Snapshot)
        else if (key == 's' || key == 'S') {
            // cv::format을 사용하여 파일 이름을 "frame01.jpg", "frame02.jpg" 형태로 자동 생성
            string fileName = format("frame%02d.jpg", fileCount);

            // imwrite: 지정된 파일 이름과 확장자에 맞춰 현재 frame 데이터를 인코딩하여 디스크에 저장
            bool isSuccess = imwrite(fileName, frame);

            if (isSuccess) {
                // 저장이 성공하면 콘솔에 메시지를 출력하고 다음 저장을 위해 카운트 증가
                cout << fileName << " 저장 성공!" << endl;
                fileCount++;
            }
            else {
                // 경로 권한 문제 등으로 저장 실패 시 경고 메시지 출력
                cout << "저장 실패!" << endl;
            }
        }
    }

    // 카메라 리소스를 해제하고 모든 창을 닫음
    destroyAllWindows();

    return 0;
}
