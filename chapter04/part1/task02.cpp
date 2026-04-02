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
	Mat frame, bright_100;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}
		bright_100 = frame + Scalar(100,100,100);
		imshow("frame", frame);
		imshow("bright_100", bright_100);
		if (waitKey(10) == 27) break;
	}



	return 0;
}
