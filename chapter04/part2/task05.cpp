// *******************************************
// 제목: 실습 과제5
// 날짜: 26년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    VideoCapture cap(0); // 카메라 장치 오픈
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    // 카메라의 프레임 해상도 정보 획득 및 정수형 변환
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    
    // 비디오 코덱(DIVX) 및 저장을 위한 VideoWriter 객체 생성
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo("task05.avi", fourcc, 30, Size(w, h));

    Mat frame;
    bool isRecording = false; // [핵심] 현재 녹화 중인지 여부를 저장하는 상태 플래그

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        int key = waitKey(33); // 약 30 FPS 프레임 간격 유지 및 키 입력 대기
        
        if (key == 'e' || key == 'E') {
            cout << "녹화&프로그램 종료" << endl;
            break; // 루프 탈출을 통해 녹화 및 프로그램 종료
        }
        else if (key == 's' || key == 'S') {
            // 's' 키 입력 시 녹화 상태를 true로 전환 (트리거 역할)
            if (!isRecording) {
                isRecording = true;
                cout << "녹화 시작" << endl;
            }
        }

        // [핵심 로직] isRecording 상태가 true인 동안 매 프레임을 파일에 기록
        if (isRecording) {
            outputVideo.write(frame); 
        }

        imshow("frame", frame);
    }

    return 0; // 객체 소멸 시 자동으로 파일 및 카메라 리소스 해제
}
