#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char ** argv)
{
	namedWindow("Capture", WINDOW_AUTOSIZE);

	VideoCapture cap;
	if (argc == 1)
	{
		cap.open(0);
	}
	else
	{
		cap.open(argv[1]);
	}

	if (!cap.isOpened())
	{
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

	Mat frame;

	while (true)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}

		imshow("CaptureVideo", frame);

		if (waitKey(33) >= 0)
		{
			break;
		}
	}
}

