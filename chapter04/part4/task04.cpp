
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
void event_handler(int event, int x, int y, int flags, void* userdata);
Mat img;
int main() {
	img = imread("lenna.bmp", IMREAD_COLOR);
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", event_handler);
	int key;
	while (true) {
		imshow("img", img);
		key = waitKey(10);
		if (key == 'q') break;
	}
	return 0;
}



void event_handler(int event, int x, int y, int flags, void* userdata)
{
    
    switch (event) {
    case EVENT_LBUTTONDOWN: 
    { 
        
        Point pt(x, y);
        Vec3b value = img.at<Vec3b>(pt);

        cout << "좌표: (" << pt.x << ", " << pt.y << "), 화소값(B,G,R): " << value << endl;
        break;
    } 
    
    default:
        break;
    }
}
