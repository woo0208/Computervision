// *******************************************
// 제목: 실습 과제4
// 날짜: 26년 3월 25일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 영상 불러오기
    Mat img = imread("dog.bmp");

    // 예외 처리
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 깊은 복사 (Deep Copy)를 통한 원본 데이터 보존
    Mat img_original;
    img.copyTo(img_original);

    // 얕은 복사 (Shallow Copy)
    // Rect(x, y, width, height)를 사용 => x=103, y=36 위치에서 가로 79, 세로 99 크기의 영역을 지정.
    // 이때 copybon은 새로운 메모리를 할당받는 것이 아니라, img의 해당 영역 데이터 메모리 주소(Pointer)만 공유
    Mat bluePoint = img(Rect(103, 36, 79, 99));

    // 화소값 일괄 변경 (마스킹/채우기)
    // copybon의 모든 픽셀 값을'파란색(Blue)'
    // copybon은 img와 메모리를 공유하는 '얕은 복사' 상태이므로, 이 연산은 원본 img 영상의 해당 사각형 영역을 파랗게 변형
    bluePoint = Scalar(255, 0, 0);

    int count = 0;

    Mat loop_img[2] = { img_original, img };

    // 무한 루프를 통한 영상 교차 출력 (깜빡임 효과)
    while (true) {
        
        imshow("img", loop_img[count]);

        count = (count + 1) % 2;

        // 키보드 입력 대기 및 딜레이 제어(1초)
        int key = waitKey(1000);

        // 'q' 또는 'Q'를 누르면 반복 종료
        if (key == 'q' || key == 'Q') {
            break;
        }

        cout << "현재 카운트: " << count << " (종료하려면 이미지 창에서 'q' 입력)" << endl;
    }

    // 프로그램 종료 전, OS에 할당된 모든 GUI 윈도우 리소스를 명시적으로 반환합니다.
    destroyAllWindows();

    return 0;
}
