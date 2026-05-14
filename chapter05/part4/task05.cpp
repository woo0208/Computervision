#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 히스토그램 계산 및 그리기 함수 선언
Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);

int main(void)
{
    // 1. 영상을 그레이스케일로 불러오기
    Mat src = imread("crayfish.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl; 
        return -1; 
    }

    Mat dst;

    // 2. 히스토그램 평활화 수행
    equalizeHist(src, dst);

    // 3. 결과 출력
    imshow("src", src); // 원본 영상
    imshow("srcHist", getGrayHistImage(calcGrayHist(src))); // 원본 히스토그램

    imshow("dst", dst); // 평활화 결과 영상
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst))); // 평활화 결과 히스토그램

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

Mat getGrayHistImage(const Mat & hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));
    
    double histMax;
    minMaxLoc(hist, 0, &histMax);
    
    Mat imgHist(100, 256, CV_8UC1, Scalar(255)); // 흰색 배경 생성
    
    for (int i = 0; i < 256; i++) {
        line(imgHist,
            Point(i, 100),
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
            Scalar(0)); // 검은색 선으로 그래프 그리기
    }
    return imgHist;
}
