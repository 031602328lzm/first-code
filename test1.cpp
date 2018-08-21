#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
int main()

{
	Mat img1=imread("home.jpg",199);
	Mat img2=imread("33.jpg");
	namedWindow("fish");
	imshow("fish",img1);
	namedWindow("logo");
	imshow("logo",img2);
	Mat imgROI;
	imgROI=img2(Rect(100,90,img1.cols,img1.rows));
	addWeighted(imgROI,0.5,img1,0.3,0.,imgROI);
	namedWindow("roi");
	imshow("roi",img2);
	imwrite("shengchenghunhe.jpg",img2);
	waitKey();
	return 0;
	
}