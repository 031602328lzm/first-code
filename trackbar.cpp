#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

#define WINDOW_NAME "线性混合实例"
const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSilder;
double g_dAlphaValue;
double g_dBetaValue;

Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

void on_Trackbar(int ,void*)
{
	g_dAlphaValue = (double)g_nAlphaValueSilder/g_nMaxAlphaValue;
    g_dBetaValue = (1.0-g_dAlphaValue);
    addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);
    imshow(WINDOW_NAME,g_dstImage);
}

int main(int argc,char** argv)
{
	g_srcImage1 = imread("surf_icon1.jpg");
	g_srcImage2 = imread("sift_icon.jpg");
    if(!g_srcImage1.data){printf("读取错误\n");return -1;}
    if(!g_srcImage2.data){printf("读取错误\n");return -1;}
    g_nAlphaValueSilder = 70;
    namedWindow(WINDOW_NAME,0);
	cvResizeWindow(WINDOW_NAME,500,500);
    char TrackbarName[50];
    sprintf(TrackbarName,"透明值%d",g_nMaxAlphaValue);
	
    createTrackbar(TrackbarName,WINDOW_NAME,&g_nAlphaValueSilder,g_nMaxAlphaValue,on_Trackbar);
    on_Trackbar(g_nAlphaValueSilder,0);
    waitKey(0);
    return 0;

}