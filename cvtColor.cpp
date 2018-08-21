#include<opencv2/opencv.hpp>
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
int  main()
{
    Mat srcImage = imread ("33.jpg",1),dstImage;
    cvtColor(srcImage,dstImage,CV_BGR2HSV_FULL);
    imshow("dss",dstImage);
    waitKey(0);
    return 0;
}