#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    // 테스트용 영상 불러오기 (그레이스케일)
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 1. filter2D를 이용한 사용자 정의 가우시안 필터 구현
    // 슬라이드에 제시된 5x5 마스크 데이터를 1차원 배열로 선언
    float mask_data[] = {
        1,  4,  7,  4, 1,
        4, 16, 26, 16, 4,
        7, 26, 41, 26, 7,
        4, 16, 26, 16, 4,
        1,  4,  7,  4, 1
    };

    // 5x5 크기의 부동소수점(CV_32F) 행렬로 변환 후 273.0으로 나누어 정규화
    Mat custom_kernel = Mat(5, 5, CV_32F, mask_data) / 273.0f;

    Mat dst_filter2D;
    // -1을 지정하여 출력 영상의 깊이를 입력 영상과 동일하게 설정
    filter2D(src, dst_filter2D, -1, custom_kernel);

    // 2. OpenCV 내장 GaussianBlur 함수를 이용한 필터링
    Mat dst_gaussianBlur;
    // ksize를 5x5로 설정, sigmaX는 0으로 두어 커널 크기에 따라 자동 계산되도록 설정
    GaussianBlur(src, dst_gaussianBlur, Size(5, 5), 0);

    // 3. 결과 출력 및 비교
    imshow("Original", src);
    imshow("Custom Gaussian (filter2D)", dst_filter2D);
    imshow("OpenCV GaussianBlur", dst_gaussianBlur);

    // 두 결과 영상 간의 픽셀 값 차이 계산 (옵션: 결과가 얼마나 유사한지 확인)
    Mat diff;
    absdiff(dst_filter2D, dst_gaussianBlur, diff);
    imshow("Difference", diff);

    waitKey();
    return 0;
}
