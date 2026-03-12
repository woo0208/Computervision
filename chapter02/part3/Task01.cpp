// *********************************
// 제 목  : 실습과제1 - 영상의 밝기 조절 및 입출력
// 날 짜  : 2026년 3월 12일
// 작성자 : 2603043 한정우
// *********************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; // OpenCV 네임스페이스 사용 (cv:: 생략 가능)
using namespace std;

int main()
{
    // 현재 설치된 OpenCV의 버전을 확인하여 라이브러리 로드 상태 점검
    cout << "Hello OpenCV " << CV_VERSION << endl;

    // 영상을 저장할 Mat 클래스 객체 생성
    Mat img;

    // imread 함수를 통해 영상 파일을 읽어옴
    // IMREAD_GRAYSCALE: 영상을 1채널 8비트 그레이스케일 형식으로 변환하여 로드
    img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 예외 처리: 파일이 없거나 경로가 잘못되어 데이터를 읽지 못한 경우(img.data == NULL)
    if (img.empty()) {
        cerr << "Image load failed" << endl;
        return -1;
    }

    // 시각화를 위한 윈도우 생성
    namedWindow("image");  // 원본(수정 전) 영상 출력용
    namedWindow("image2"); // 밝기 수정 후 영상 출력용

    // 수정 전 영상을 "image" 윈도우에 출력
    imshow("image", img);

    // [핵심 연산] 영상의 밝기 조절 (산술 연산자 오버로딩 활용)
    // 원리: f(x, y) = saturate(src(x, y) + 100)
    // OpenCV의 Mat 연산은 '포화 연산(Saturation Arithmetic)'을 수행함.
    // 255를 초과하는 값은 모두 255(흰색)로 클램핑(Clamping)되어 데이터 오버플로우를 방지함.
    img += 100;

    // 수정된 영상을 "image2" 윈도우에 출력
    imshow("image2", img);

    // 처리된 결과 영상을 파일로 저장 (JPEG 포맷, 인코딩 과정 포함)
    imwrite("bright.jpg", img);

    // 사용자로부터 키보드 입력이 있을 때까지 프로그램을 대기시킴 (화면 유지) => waitKey() 함수를 한번만 사용하는 것이 메모리 관점에서 좋다
    waitKey();

    return 0;
}