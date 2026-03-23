#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main() {
	Mat img1(400, 300, CV_8UC3,Scalar(255,0,0));
	Mat img2(400, 300, CV_8UC3, Scalar(0, 255, 0));
	Mat img3(400, 300, CV_8UC3, Scalar(0, 0, 255));

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	return 0;
}
