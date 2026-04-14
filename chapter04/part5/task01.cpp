#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 사용자 정의 데이터 구조체: 콜백 함수로 여러 데이터를 전달하기 위함
struct Data {
    Mat src;    // 입력 영상(Matrix 객체)
    int pos = 0;
    int count = 0;
};

// 트랙바 이벤트 발생 시 호출되는 콜백 함수 선언
void on_change(int pos, void* userdata);

int main() {
    Data data;
    data.src = imread("lenna.bmp"); // 이미지 파일 읽기
    if (data.src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("src"); // "src"라는 이름의 윈도우 생성

    // 트랙바 생성: 이름, 윈도우명, 범위, 콜백 함수, 사용자 데이터 전달
    createTrackbar("level", "src", 0, 100, on_change, &data);

    while (true) {
        imshow("src", data.src); // 루프를 돌며 계속 화면 갱신 (원을 그린 결과 반영)
        if (waitKey(10) == 27) break; // ESC 키 누르면 종료 (대기 시간 10ms)
    }
    return 0;
}

// 트랙바의 슬라이더를 움직일 때마다 실행되는 구현부
void on_change(int pos, void* userdata) {
    // void* 타입으로 전달된 주소값을 다시 Data* 타입으로 역변환(Type Casting)
    Data* pdata = (Data*)userdata;
    pdata->pos = pos; // 현재 트랙바의 위치값 업데이트
    
    cout << "트랙바 위치: " << pdata->pos << endl;

    // 영상 중앙에 원 그리기: 대상, 중심점(x, y), 반지름, 색상(BGR), 두께
    // 주의: src.rows(높이)와 src.cols(너비)를 Point(x, y)에 대입할 때 순서 유의
    circle(pdata->src, Point(pdata->src.cols / 2, pdata->src.rows / 2), pdata->pos, Scalar(0, 255, 0), 2);
}
