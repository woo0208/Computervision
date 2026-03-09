// OpenCV의 핵심 모듈 및 클래스(Mat 등) 선언을 포함하여 컴파일러가 인식할 수 있게 합니다.
#include <opencv2/opencv.hpp>

// 콘솔 창에 문자열이나 에러 메시지를 출력하기 위해 C++ 표준 입출력 스트림을 포함합니다.
#include <iostream>

// 'cv::' 접두사 없이 OpenCV의 클래스와 함수를 바로 사용할 수 있도록 이름 공간을 개방합니다.
using namespace cv;

// 'std::' 접두사 없이 C++ 표준 라이브러리의 기능을 바로 사용할 수 있도록 이름 공간을 개방합니다.
using namespace std;

int main()
{
    // 현재 링크된 OpenCV 라이브러리의 버전을 런타임에 콘솔 창에 출력하여 환경 설정을 확인합니다.
    cout << "Hello OpenCV " << CV_VERSION << endl;

    // 영상의 화소(Pixel) 데이터와 메타정보를 메모리에 저장하기 위한 빈 2차원 행렬 객체를 생성합니다.
    Mat img;

    // 디스크의 이미지 파일을 디코딩하여 화소 데이터를 추출하고, 앞서 만든 img 행렬에 할당합니다.
    img = imread("myphoto.jpg");

    // 영상 데이터가 정상적으로 메모리에 적재되지 않았을 때 메모리 참조 오류를 막기 위해 프로그램을 종료하는 예외 처리 구문입니다.
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 렌더링된 영상을 화면에 띄우기 위해 운영체제에 'image'라는 고유 식별자를 가진 GUI 창 생성을 요청합니다.
    namedWindow("image");

    // 메모리에 적재된 img 행렬의 화소 데이터를 앞서 생성한 'image' 창에 시각적으로 렌더링합니다.
    imshow("image", img);

    // 창이 바로 닫히거나 응답 없음 상태가 되지 않도록, 사용자의 키보드 입력이 발생할 때까지 GUI 이벤트 루프를 대기시킵니다.
    waitKey();

    // 프로그램이 오류 없이 성공적으로 실행을 마쳤음을 운영체제에 알리고 메인 함수를 종료합니다.
    return 0;
}