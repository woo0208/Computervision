#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }
    imshow("src", src);

    Mat dst;
    for (int ksize = 3; ksize <= 7; ksize += 2) {
        // 1. 모든 원소의 값이 1인 ksize x ksize 크기의 실수형(CV_32F) 행렬을 생성합니다.
        // 2. 이를 전체 원소 개수인 (ksize * ksize)로 나누어 정규화된 평균값 필터 커널을 만듭니다.
        Mat kernel = Mat::ones(ksize, ksize, CV_32F) / static_cast<float>(ksize * ksize);

        // 3. filter2D 함수에 생성한 커널을 전달하여 컨볼루션 연산을 수행합니다.
        // ddepth 매개변수에 -1을 지정하면 입력 영상(src)과 같은 데이터 타입을 사용합니다.
        filter2D(src, dst, -1, kernel);

        String desc = format("Mean: %dx%d", ksize, ksize);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
            Scalar(255), 1, LINE_AA);
        imshow("dst", dst);
        waitKey();
    }
    return 0;
}
