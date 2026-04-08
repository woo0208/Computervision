
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
void event_handler(int event, int x, int y, int flags, void* userdata);
Mat img;
int main() {
	img = imread("lenna.bmp");
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", event_handler);
	int key;
	while (true) {
		imshow("img", img);
		key = waitKey(10);
		if (key == 'q') break;
	}
	return 0;
}



void event_handler(int event, int x, int y, int flags, void* userdata)
{
	static int downCount;
	static int upCount;
	static int moveCount;
	static Point ptOld;
	switch (event) {
	case EVENT_LBUTTONDOWN:
		downCount++;
		cout << "EVENT_LBUTTONDOWN: " << downCount << endl;
		break;
	case EVENT_LBUTTONUP:
		upCount++;
		cout << "EVENT_LBUTTONUP: " << upCount << endl;
		break;
	case EVENT_MOUSEMOVE:
		moveCount++;
		cout << "EVENT_MOUSEMOVE: " << moveCount << endl;
		break;
	default:
		break;
	}
}
