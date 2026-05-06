// *******************************************
// 제목: 실습 과제2
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
	Mat img2;
	Point spt;
};

int main() {
	Data data;
	data.img = imread("lenna.bmp",IMREAD_GRAYSCALE);
	data.img2 = data.img;
	namedWindow("img");
	setMouseCallback("img", on_mouse, &data);
	while (true) {
		imshow("img", data.img);
		int key = waitKey(33);
		if (key == 'q') {
			break;
		}
	}
}


void on_mouse(int event, int x, int y, int flag, void* userdata) {
	Data* pdata = (Data*)userdata;
	switch (event) {
	case EVENT_LBUTTONDOWN:
		pdata->spt = Point(x, y);
		break;
	case EVENT_LBUTTONUP:
		Point pt(x, y);
		pdata->img2 = pdata->img(Rect(pdata->spt, pt));
		pdata->img2 += 100;
		break;
	}
}
