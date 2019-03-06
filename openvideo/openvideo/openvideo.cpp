#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	namedWindow("OpenvideoDemo", WINDOW_AUTOSIZE);
	VideoCapture cap;
	//string videoName = string("../saveVideo/my_video.avi");
	cap.open("../saveVideo/my_video.avi");
	Mat frame;

	if (cap.isOpened() == false)
	{
		return 0;
	}

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