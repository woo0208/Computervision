#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("lenna.bmp");

    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    Mat dst = src.clone();

    Point2f center(src.cols / 2.0f, src.rows / 2.0f);

    int step = 0;        // 10도 단위 회전 횟수
    double scale = 1.0;  // 확대/축소 없음

    imshow("dst", dst);

    while (true) {
        int key = waitKey(0);   // 키 입력 대기

        if (key == 'q' || key == 27) {  // q 또는 ESC 종료
            break;
        }

        if (key == 'r') {
            // 시계방향 10도
            step--;

            if (step < 0) {
                step += 36;
            }
        }
        else if (key == 'b') {
            // 반시계방향 10도
            step++;

            if (step >= 36) {
                step -= 36;
            }
        }
        else {
            continue;
        }

        double angle = step * 10.0;

        if (step == 0) {
            dst = src.clone();  // 360도 회전 시 원본 그대로 표시
        }
        else {
            Mat M = getRotationMatrix2D(center, angle, scale);

            warpAffine(
                src,                    // 항상 원본 기준으로 회전
                dst,
                M,
                src.size(),
                INTER_LINEAR,
                BORDER_CONSTANT,
                Scalar(0, 0, 0)
            );
        }

        cout << "현재 회전 각도: " << angle << "도" << endl;
        imshow("dst", dst);
    }

    destroyAllWindows();

    return 0;
}
