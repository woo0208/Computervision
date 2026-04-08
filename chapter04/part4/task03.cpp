
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
void event_handler(int event, int x, int y, int flags, void* userdata);
Mat img;
int main() {
	img = imread("lenna.bmp", IMREAD_GRAYSCALE);
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
    // 1. 값 추출 시 (y, x) 순서로 호출해야 함 (또는 Point 객체 사용)
    // 범위를 벗어나는 것을 방지하기 위해 switch 내부에서 처리하는 것이 안전합니다.
    
    switch (event) {
    case EVENT_LBUTTONDOWN: 
    { 
        
        // 2. 안전한 좌표 접근: Point(x, y) 객체를 넘기면 내부적으로 (y, x) 처리를 해줍니다.
        Point pt(x, y);
        uchar value = img.at<uchar>(pt); 

        cout << "좌표: (" << pt.x << ", " << pt.y << "), 화소값: " << (int)value << endl;
        break;
    } 
    
    default:
        break;
    }
}
