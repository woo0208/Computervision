#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	VideoWriter outputVideo("VideoCheck.avi", fourcc, 30, Size(w, h));


	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		outputVideo.write(frame);

		imshow("frame", frame);
		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			break;
		}
	}

	return 0;
}
