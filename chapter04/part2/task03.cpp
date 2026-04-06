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

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	VideoWriter outputVideo("output.avi", fourcc, 30, Size(w, h));


	Mat frame, outline;
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		outline = frame.clone();

		
		int centerX = outline.cols / 2;
		int centerY = outline.rows / 2;
		line(outline, Point(0, centerY), Point(outline.cols, centerY), Scalar(0, 0, 255), 2);

		line(outline, Point(centerX, 0), Point(centerX, outline.rows), Scalar(0, 0, 255), 2);
		imshow("frame", frame);
		imshow("outline", outline);
		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			break;
		}
	}

	return 0;
}
