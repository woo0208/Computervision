
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
Mat img;
int main() {
	img = imread("lenna.bmp");
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", on_mouse);


	int lineX_start = img.rows / 6;
	int lineY_start = img.cols / 6;
	int lineX_end = img.rows - (img.rows / 6);
	int lineY_end = img.cols - (img.cols / 6);
	int centerX = img.rows / 2;
	int centerY = img.cols / 2;

	string text = "Hello, Lenna";
	int fontFace = FONT_HERSHEY_SIMPLEX; // 폰트 종류
	double fontScale = 1.5;              // 폰트 크기 배율
	int thickness = 3;                   // 선 두께
	Scalar color(0, 255, 255);           // 노란색 (BGR: 0, 255, 255)

	int baseLine = 0;
	Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseLine);

	int x = (img.cols - textSize.width) / 2;
	int y = textSize.height + 30; // 상단에서 30픽셀 정도 내려온 위치

	while (true) {

		imshow("img", img);
		int key = waitKey();
		if (key == 'l' || key == 'L') {
			line(img, Point(lineX_start, lineY_end), Point(lineX_end, lineY_end), Scalar(255, 255, 255), 2);
		}
		else if (key == 'c' || key == 'C') {
			circle(img, Point(centerX, centerY), 150, Scalar(0, 0, 255), 1, LINE_AA);
		}
		else if (key == 't' || key == 'T') {
			putText(img, text, Point(x, y), fontFace, fontScale, color, thickness, LINE_AA);
		}
		else if (key == 'q' || key == 'Q') {
			break;
		}
	}
	return 0;
}

