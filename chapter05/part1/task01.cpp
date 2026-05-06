// *******************************************
// 제목: 실습 과제1
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
};

int main() {
	Data data;
	data.img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (data.img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse, &data);
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
		pdata->img += Scalar(10);
		break;
	case EVENT_RBUTTONDOWN:
		pdata->img -= Scalar(10);
		break;
	}
}
