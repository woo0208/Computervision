#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& img);
void imageLog(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	// 히스토그램 계산
	Mat hist = calcGrayHist(img);

	// 전체 픽셀 수
	int totalPixels = img.rows * img.cols;

	// 최소값, 최대값
	double minVal, maxVal;
	minMaxLoc(img, &minVal, &maxVal);

	// 가장 빈도수가 많은 픽셀값 찾기
	double maxHist;
	Point maxPt;
	minMaxLoc(hist, 0, &maxHist, 0, &maxPt);

	int mostFrequentPixel = maxPt.y; // 히스토그램 index
	int mostFrequentCount = (int)maxHist;

	// 픽셀값 80의 빈도수
	int freq80 = (int)hist.at<float>(80, 0);

	// 출력
	cout << "영상의 전체 픽셀수: " << totalPixels << endl;
	cout << "영상에서 픽셀값의 최소값: " << minVal << endl;
	cout << "영상에서 픽셀값의 최대값: " << maxVal << endl;
	cout << "빈도수가 가장 많은 픽셀값과 빈도수: "
		<< mostFrequentPixel << ", "
		<< mostFrequentCount << endl;
	cout << "픽셀값 80의 빈도수: " << freq80 << endl;
}

int main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	imageLog(src);

	imshow("src", src);
	Mat hist = calcGrayHist(src);
	Mat hist_img = getGrayHistImage(hist);
	imshow("srcHist", hist_img);
	waitKey();
	return 0;
}


Mat calcGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[]{ 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0,256 };
	const float* ranges[] = { graylevel };

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;
}

Mat getGrayHistImage(const Mat& hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(200, 512, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {

		int h = cvRound(hist.at<float>(i, 0) * 200 / histMax);

		line(imgHist,
			Point(i * 2, 200),
			Point(i * 2, 200 - h),
			Scalar(0),
			2);
	}
	return imgHist;
}
