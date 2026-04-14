// *******************************************
// 제목: 실습 과제2
// 날짜: 2026년 4월 13일
// 작성자: 2603043 한정우
// *******************************************

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct Data {
	Mat img;
	int pos = 0;
	Point starP;
};

void on_mouse(int event, int x, int y, int flag, void* userdata);
void on_trackbar(int pos, void* userdata);

int main() {
	Data data;
	data.img = Mat(500, 500, CV_8UC3, Scalar(255, 255, 255));
	namedWindow("img");
	setMouseCallback("img", on_mouse, &data);
	createTrackbar("level", "img", &data.pos, 3, on_trackbar, &data);
	while (true) {
		imshow("img", data.img);
		int key = waitKey(10);
		if (key == 'q') {
			break;
		}
	}
	return 0;
}

void on_mouse(int event, int x, int y, int flag, void* userdata) {
	Data* pdata = (Data*)userdata;
	Point endP;
	switch (event) {
	case EVENT_LBUTTONDOWN:
		pdata->starP = Point(x,y);
		break;
	case EVENT_LBUTTONUP:
		endP = Point(x, y);
		if (pdata->pos == 0) {
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(255,0,0));
		} else if (pdata->pos == 1) {
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(0, 255, 0));
		} else if (pdata->pos == 2) {
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(0, 0, 255));
		} else if (pdata->pos == 3) {
			rectangle(pdata->img, Rect(pdata->starP, endP), Scalar(255,255,255), FILLED);
		}
		break;
	}
}

void on_trackbar(int pos, void* userdata) {
	Data* pdata = (Data*)userdata;
	pdata->pos = pos;
}
