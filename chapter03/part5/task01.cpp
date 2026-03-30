// *******************************************
// 제목: 실습 과제1
// 날짜: 26년 3월 30일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp> 
#include <iostream>           

using namespace std;
using namespace cv;

int main() {
    // 1. 영상 로드 (이미지 파일을 Mat 객체에 할당)
    Mat img = imread("lenna.bmp");

    // 2. 예외 처리 (파일 로드 실패 시 프로세스 종료)
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 3. 화소(Pixel) 값 참조
    // Vec3b: 8비트 부호 없는 정수(uchar) 3개로 구성된 벡터 (B, G, R 채널 순서)
    // at<Vec3b>(y, x): 행(row)과 열(column) 좌표를 통해 해당 위치의 데이터 반환
    Vec3b p1 = img.at<Vec3b>(50, 50);   // 좌표 (50, 50)의 BGR 화소값
    Vec3b p2 = img.at<Vec3b>(100, 100); // 좌표 (100, 100)의 BGR 화소값
    Vec3b p3 = img.at<Vec3b>(150, 150); // 좌표 (150, 150)의 BGR 화소값

    // 4. 화소 정보 출력
    cout << "좌표 (50,50)의 화소값(B,G,R):" << p1 << endl;
    cout << "좌표 (100,100)의 화소값(B,G,R):" << p2 << endl;
    cout << "좌표 (150,150)의 화소값(B,G,R):" << p3 << endl;

    // 5. 영상 출력 및 대기
    imshow("img", img); 
    waitKey();          // 사용자 키 입력 시까지 대기
    return 0;
}
