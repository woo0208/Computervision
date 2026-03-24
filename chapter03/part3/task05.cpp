#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main() {
	Mat img(400, 400, CV_8UC1, Scalar(0));

	char input = ' ';
	int count = 0;
	int checkPoint = 0;
	while (true) {
		if (input == 'q') {
			break;
		}
		if (count == 255) {
			checkPoint = 1;
		}
		else if (count == 0) {
			checkPoint = 0;
		}
		if (checkPoint == 0) {
			img.setTo(Scalar(count));
			count++;
		}
		else if (checkPoint == 1) {
			img.setTo(Scalar(count));
			count--;
		}
		imshow("img", img);

		int key = waitKey(5);

		if (key == 'q' || key == 'Q') {
			break;
		}

		cout << "현재 카운트: " << count << " (종료하려면 이미지 창에서 'q' 입력)" << endl;

	}
	destroyAllWindows();
	return 0;
}
