#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	cv::Mat dst;
	float angle = -10.0, scale = 1;
	cv::Mat src = cv::imread("1.jpg", 1);
	cv::Point2f center(src.cols / 2.0, src.rows / 2.0);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);
	//��ȡ����ı���
	cv::Rect bbox = cv::RotatedRect(center, src.size(), angle).boundingRect();
	//��������������
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	//����任
	cv::warpAffine(src, dst, rot, bbox.size());
	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey(0);

}