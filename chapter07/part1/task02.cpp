#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(void)
{
    // 흑백 이미지로 읽기
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 체크
    if (src.empty())
    {
        cerr << "Image load failed!" << endl;
        return 1;
    }

    // 엠보싱 필터 커널
    float data[] = {
         -1, -1, -1,
         -1,  9, -1,
         -1, -1, -1
    };

    Mat emboss(3, 3, CV_32FC1, data);

    Mat dst;

    // 필터 적용
    filter2D(src, dst, -1, emboss, Point(-1, -1), 0);

    // 결과 출력
    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    return 0;
}
