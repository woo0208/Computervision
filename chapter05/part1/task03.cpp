// *******************************************
// 제목: 실습 과제3
// 날짜: 2026년 5월 06일
// 작성자: 2603043 한정우
// ******************************************
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flag, void* userdata);

struct Data {
	Mat img;
	int pos;
};

void on_trackbar(int pos, void* userdata);
void on_mouse(int event, int x, int y, int flag, void* userdata);

int main() {
	Data data;
	data.img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (data.img.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse, &data);
	createTrackbar("level", "img", 0, 1, on_trackbar, &data);
	while (true) {
		imshow("img", data.img);
		int key = waitKey(33);
		if (key == 'q') {
			break;
		}
	}
}


void on_trackbar(int pos, void* userdata) {
	Data* pdata = (Data*)userdata;
	pdata->pos = pos;
}


void on_mouse(int event, int x, int y, int flag, void* userdata) {
	Data* pdata = (Data*)userdata;
	int bri = 0;
	if (pdata->pos == 0) {
		bri = 10;
	}
	else if (pdata->pos == 1) {
		bri = -10;
	}
	switch (event) {
	case EVENT_LBUTTONDOWN:
		pdata->img += bri;
		break;
	}
}
