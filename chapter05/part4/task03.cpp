// *******************************************
// 제목: 실습 과제3
// 날짜: 2026년 5월 14일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);

int main(void)
{
    Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    double gmin, gmax;
    minMaxLoc(src, &gmin, &gmax);
    cout << "Gmin:" << gmin << endl;
    cout << "Gmax:" << gmax << endl;

    // 원본 코드: Mat dst = (src - gmin) * 255 / (gmax - gmin);
    // 수정된 코드: 입력 영상과 동일한 크기, 타입의 빈 결과 영상 행렬 생성
    Mat dst(src.rows, src.cols, src.type());

    // 이중 for문을 이용한 픽셀 직접 접근 및 히스토그램 스트레칭 연산
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            // Mat::at 함수를 이용하여 현재 픽셀 값(uchar) 참조
            uchar p = src.at<uchar>(y, x);

            // 스트레칭 공식 적용 후 saturate_cast를 이용하여 0~255 사이의 값으로 포화 연산
            dst.at<uchar>(y, x) = saturate_cast<uchar>((p - gmin) * 255.0 / (gmax - gmin));
        }
    }

    imshow("src", src);
    imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
    imshow("dst", dst);
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

    waitKey();
    return 0;
}

Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);
    Mat hist;
    int channels[] = { 0 };
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = { graylevel };
    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
    return hist;
}

Mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));
    double histMax;
    minMaxLoc(hist, 0, &histMax);
    Mat imgHist(100, 256, CV_8UC1, Scalar(255));
    for (int i = 0; i < 256; i++) {
        // 실제 컴파일을 위해 hist.at<float>(i, 0)으로 템플릿 인자를 추가하는 것이 안전합니다.
        line(imgHist,
            Point(i, 100),
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
            Scalar(0));
    }
    return imgHist;
}
