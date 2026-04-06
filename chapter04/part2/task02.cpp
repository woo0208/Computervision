#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("stopwatch.avi");
	if(!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}


	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		inversed = frame + (Scalar(100, 100, 100));
		imshow("frame", frame);
		imshow("inversed", inversed);
		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			break;
		}
	}

	return 0;
}
