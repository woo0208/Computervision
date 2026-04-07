// *******************************************
// 제목: 실습 과제2
// 날짜: 26년 4월 07일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("stopwatch.avi");
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}


	Mat frame, bright;
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		bright = frame + (Scalar(100, 100, 100));
		imshow("frame", frame);
		imshow("bright", bright);
		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			break;
		}
	}

	return 0;
}
