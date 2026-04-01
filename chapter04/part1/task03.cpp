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
	int fileCount = 1;
	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}

		imshow("frame", frame);

		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			break;
		} else if (key == 's' || key == 'S') {
			string fileName = format("frame%02d.jpg", fileCount);
			bool isSuccess = imwrite(fileName, frame);

			if (isSuccess) {
				cout << fileName << " 저장 성공!" << endl;
				fileCount++;
			}
			else {
				cout << "저장 실패!" << endl;
			}
		}
	}

	return 0;
}
