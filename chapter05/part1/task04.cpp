#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flag, void* userdata);
struct Data {
	Mat img;
	Point pt;
	int pos = 0;
};
int main() {
	Data data;
	data.img = imread("lenna.bmp",IMREAD_GRAYSCALE);
	if (data.img.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse,&data);
	while (true) {
		imshow("img", data.img);
		int key = waitKey(30);
		if (key == 'q') {
			break;
		}
	}
	return 0;
}

void on_mouse(int event, int x, int y, int flag, void* userdata) {
	Data* pdata = (Data*)userdata;

	switch (event) {
	case EVENT_LBUTTONDOWN:
		pdata->pos = 1;
		break;

	case EVENT_MOUSEMOVE:
		if (pdata->pos == 1) {
			int r = 1;

			Rect roi(x - r, y - r, 2 * r + 1, 2 * r + 1);
			Rect imgRect(0, 0, pdata->img.cols, pdata->img.rows);

			roi = roi & imgRect; // 이미지 영역 밖으로 나가지 않게 제한

			pdata->img(roi) += 100;
		}
		break;

	case EVENT_LBUTTONUP:
		pdata->pos = 0;
		break;
	}
}

