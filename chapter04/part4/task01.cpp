#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // 1. 영상 로드 및 예외 처리
    Mat img = imread("lenna.bmp");
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // [튜터의 교정 포인트: 좌표계 매칭]
    // 수학의 x축은 가로(너비)이므로 img.cols, y축은 세로(높이)이므로 img.rows를 써야 합니다.
    int lineX_start = img.cols / 6;
    int lineY_start = img.rows / 6;
    int lineX_end = img.cols - (img.cols / 6);
    int lineY_end = img.rows - (img.rows / 6);
    
    // 화면 정중앙 좌표 계산
    int centerX = img.cols / 2;
    int centerY = img.rows / 2;

    // 2. 텍스트 렌더링 설정 및 좌표 계산 (상단 중앙 정렬)
    string text = "Hello, Lenna";
    int fontFace = FONT_HERSHEY_SIMPLEX; 
    double fontScale = 1.5;              
    int thickness = 3;                   
    Scalar color(0, 255, 255);           // BGR: 노란색

    int baseLine = 0;
    Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseLine);
    int x = (img.cols - textSize.width) / 2;
    int y = textSize.height + 30;

    // 3. 이벤트 루프 (사용자 상호작용)
    while (true) {
        imshow("img", img);
        
        // 무한 대기하며 키 입력값(아스키 코드) 수신
        int key = waitKey(); 

        if (key == 'l' || key == 'L') {
            // [L] 하단에 가로 직선 그리기
            line(img, Point(lineX_start, lineY_end), Point(lineX_end, lineY_end), Scalar(255, 255, 255), 2);
        }
        else if (key == 'c' || key == 'C') {
            // [C] 정중앙에 빨간색 원 그리기 (LINE_AA로 부드러운 곡선 처리)
            circle(img, Point(centerX, centerY), 150, Scalar(0, 0, 255), 1, LINE_AA);
        }
        else if (key == 't' || key == 'T') {
            // [T] 미리 계산된 좌표(x, y)에 텍스트 렌더링
            putText(img, text, Point(x, y), fontFace, fontScale, color, thickness, LINE_AA);
        }
        else if (key == 'q' || key == 'Q') {
            // [Q] 무한 루프 탈출 및 프로그램 종료
            break;
        }
    }
    
    return 0;
}
