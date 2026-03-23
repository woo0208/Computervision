#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main() {
	Mat img(400, 300, CV_8UC3, Scalar(255, 255, 255));

	char input = ' ';
	int count = 0;
	while(true) {
		if (input == 'q') {
			break;
		}
		if (count % 3 == 0) img.setTo(Scalar(255, 0, 0));
		else if (count % 3 == 1) img.setTo(Scalar(0, 255, 0));
		else if (count % 3 == 2) img.setTo(Scalar(0, 0, 255));
		count++;
		imshow("img", img);
		
		int key = waitKey(1000);

		if (key == 'q' || key == 'Q') {
			break;
		}

		cout << "현재 카운트: " << count << " (종료하려면 이미지 창에서 'q' 입력)" << endl;

	}
	destroyAllWindows();
	return 0;
}
