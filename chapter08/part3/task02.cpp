#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("lenna.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src", src);

    while (true) {
        string input;
        cout << "회전각도를 입력하시오(q 입력 시 종료): ";
        cin >> input;

        if (input == "q" || input == "Q") {
            break;
        }

        double angle = stod(input);

        Point2f center(src.cols / 2.0f, src.rows / 2.0f);

        double scale = 1.0;

        Mat M = getRotationMatrix2D(center, angle, scale);

        Mat dst;

        warpAffine(
            src,                    // 원본 영상
            dst,                    // 결과 영상
            M,                      // 회전 변환 행렬
            src.size(),             // 결과 영상 크기
            INTER_LINEAR,           // 보간법
            BORDER_CONSTANT,        // 빈 영역 처리 방식
            Scalar(0, 0, 0)         // 빈 영역을 검은색으로 채움
        );

        imshow("dst", dst);
        waitKey(1);
    }

    destroyAllWindows();

    return 0;
}
