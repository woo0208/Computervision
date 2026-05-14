// *******************************************
// 제목: 실습 과제2
// 날짜: 2026년 5월 13일
// 작성자: 2603043 한정우
// *******************************************

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// 함수 선언 변경
Mat mycalcGrayHist(const Mat& img);
Mat mygetGrayHistImage(const Mat& hist);

void imageLog(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	// 히스토그램 계산
	Mat hist = mycalcGrayHist(img);

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
	Mat hist = mycalcGrayHist(src);

	// 수정된 함수 호출
	Mat hist_img = mygetGrayHistImage(hist);
	imshow("srcHist", hist_img);
	waitKey();
	return 0;
}


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

	Mat imgHist(200, 512, CV_8UC1, Scalar(255));

	// 이미지 경계 밖으로 선이 잘리는 클리핑(Clipping) 현상을 방지하기 위해 
	// 유효한 최대 y좌표 인덱스(199)를 기준값으로 설정합니다.
	int maxHeight = imgHist.rows - 1;

	for (int i = 0; i < 255; i++) {
		// 비율 계산 시 200이 아닌 maxHeight(199)를 곱해줍니다.
		int h1 = cvRound(hist.at<float>(i, 0) * maxHeight / histMax);
		int h2 = cvRound(hist.at<float>(i + 1, 0) * maxHeight / histMax);

		line(imgHist,
			Point(i * 2, maxHeight - h1),
			Point((i + 1) * 2, maxHeight - h2),
			Scalar(0), 
			1,        
			LINE_AA);  // 안티앨리어싱을 적용하여 선을 부드럽게 렌더링
	}
	return imgHist;
}
