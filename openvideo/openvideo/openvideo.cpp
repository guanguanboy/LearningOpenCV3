#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	namedWindow("OpenvideoDemo", WINDOW_AUTOSIZE);
	VideoCapture cap;
	string videoName = string("VID_20190124_155232.mp4");
	cap.open(videoName);
	Mat frame;

	while (true)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}

		imshow("showVideo", frame);

		if (waitKey(33) >= 0)
		{
			break;
		}
	}

	return 0;
}