// *******************************************
// 제목: 실습 과제4
// 날짜: 26년 4월 02일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {

	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}
	Mat frame, cross;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}
		cross = frame.clone();

		int centerX = cross.cols / 2;
		int centerY = cross.rows / 2;

		
		line(cross, Point(0, centerY), Point(cross.cols, centerY), Scalar(0, 0, 255), 2);

		line(cross, Point(centerX, 0), Point(centerX, cross.rows), Scalar(0, 0, 255), 2);

		imshow("frame", frame);
		imshow("cross", cross);

		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			break;
		}
	}



	return 0;
}
