#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main() {
	Mat img(400, 300, CV_8UC3,Scalar(255,255,255));
	// imshow("img-Before", img); 초기 이미지 확인
	waitKey(1);
	int B, G, R;
	cout << "B값을 입력하라: ";
	cin >> B;
	cout << "G값을 입력하라: ";
	cin >> G;
	cout << "R값을 입력하라: ";
	cin >> R;


	img.setTo(Scalar(B, G, R));
	imshow("img-After", img);

	waitKey();

	return 0;
}
