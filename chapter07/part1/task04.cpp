#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flag, void* userdata);

struct Data {
	Mat src;
};

int main() {
	Data data;
	data.src = imread("rose.bmp", IMREAD_GRAYSCALE);
	if (data.src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	namedWindow("src");
	namedWindow("dst");
	imshow("src", data.src);
	imshow("dst", data.src);
	setMouseCallback("src", on_mouse, &data);
	waitKey();

	return 0;
}

void on_mouse(int event, int x, int y, int flag, void* userdata) {
	Data* pdata = (Data*)userdata;
	switch (event) {
	case EVENT_LBUTTONDOWN: {
		float filter[] = {
		1 / 9.f,1 / 9.f,1 / 9.f,
		1 / 9.f,1 / 9.f,1 / 9.f,
		1 / 9.f,1 / 9.f,1 / 9.f
		};
		Mat emboss(3, 3, CV_32FC1, filter);
		Mat dst;
		filter2D(pdata->src, dst, -1, emboss, Point(-1, -1), 0);

		imshow("src", pdata->src);
		imshow("dst", dst);
		waitKey();
		break;
	}
	case EVENT_RBUTTONDOWN: {
		float filter[] = {
		-1,-1,-1,
		-1,9,-1,
		-1,-1,-1,
		};
		Mat emboss(3, 3, CV_32FC1, filter);
		Mat dst;
		filter2D(pdata->src, dst, -1, emboss, Point(-1, -1), 0);

		imshow("src", pdata->src);
		imshow("dst", dst);
		waitKey();
		break;
	}
	case EVENT_LBUTTONDBLCLK: {
		float filter[] = {
		-1,0,1,
		-2,0,2,
		-1,0,1,
		};
		Mat emboss(3, 3, CV_32FC1, filter);
		Mat dst;
		filter2D(pdata->src, dst, -1, emboss, Point(-1, -1), 0);

		imshow("src", pdata->src);
		imshow("dst", dst);
		waitKey();
		break;
	}
	}
}
