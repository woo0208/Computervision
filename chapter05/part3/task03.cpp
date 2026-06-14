#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat mycalcGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	Mat hist = Mat::zeros(256, 1, CV_32FC1);
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			uchar pixel = img.at<uchar>(y, x);
			hist.at<float>(pixel, 0)++;
		}
	}
	return hist;
}

Mat mygetGrayHistImage(const Mat& hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 255; i++) {

		int y1 = 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax);
		int y2 = 100 - cvRound(hist.at<float>(i+1, 0) * 100 / histMax);

		line(imgHist, Point(i, y1), Point(i+1, y2), Scalar(0));
	}
	return imgHist;
}

void imageLog(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	Mat hist = mycalcGrayHist(img);

	int total = img.cols * img.rows;

	double gmin, gmax;
	minMaxLoc(img, &gmin, &gmax);

	double maxHist;
	Point maxPt;
	minMaxLoc(hist, 0, &maxHist, 0, &maxPt);

	int freq = (int)hist.at<float>(80, 0);

	cout << "영상의 전체 픽셀수:" << total << endl;
	cout << "영상에서 픽셀값의 최소값:" << gmin << endl;
	cout << "영상에서 픽셀값의 최대값:" << gmax << endl;
	cout << "빈도수가 가장 많은 픽셀값과 빈도수:" << maxPt.y << "," << maxHist << endl;
	cout << "픽셀값 80의 빈도수:" << freq << endl;
}
int main() {
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	imageLog(img);
	imshow("img", img);
	imshow("imgHist", mygetGrayHistImage(mycalcGrayHist(img)));
	waitKey();

	return 0;
}
