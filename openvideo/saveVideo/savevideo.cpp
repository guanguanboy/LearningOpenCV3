#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char* argv[])
{
	namedWindow("Example2_11", WINDOW_AUTOSIZE);

	namedWindow("logpolar", WINDOW_AUTOSIZE);

	VideoCapture capture(argv[1]);

	double fps = capture.get(CAP_PROP_FPS);

	Size size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;

	writer.open(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

	Mat log_polarFrame, bgr_frame;

	while (true)
	{
		capture >> bgr_frame;
		if (bgr_frame.empty())
		{
			break;
		}

		imshow("Example2_11", bgr_frame);

		logPolar(bgr_frame, log_polarFrame, Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40, WARP_FILL_OUTLIERS);

		imshow("logpolar", log_polarFrame);

		writer << log_polarFrame;

		char c = waitKey(10);

		if (c == 27)
		{
			break;
		}

	}

	capture.release();

	return 0;
}