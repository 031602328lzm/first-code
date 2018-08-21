#include <opencv2/opencv.hpp>
#include<vector>
using namespace cv;
using namespace std;
void createAlphaMat(Mat &mat)
{
    for(int i=0;i<mat.rows;++i){
        for(int j=0;j<mat.cols;++j){
		Vec4b&rgba =mat.at<Vec4b>(i,j);
		rgba[0]=UCHAR_MAX;
		rgba[1]=saturate_cast<uchar>((float(mat.cols-j))/((float)mat.cols)*UCHAR_MAX);
		rgba[2]=saturate_cast<uchar>((float(mat.rows-i))/((float)mat.rows)*UCHAR_MAX);
		rgba[3]=saturate_cast<uchar>(0.5*(rgba[1]+rgba[2]));
		}
		
	}
}
int main()
{
	Mat mat(480,640,CV_8UC4);
	createAlphaMat(mat);
	vector<int>compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	
    try{
		imwrite("touming.png",mat,compression_params);
		imshow("shengcheng",mat);
		fprintf(stdout,"baocun\n");
		waitKey(0);
	}
	catch(runtime_error& ex){
		fprintf(stderr,"cuowu:%s\n",ex.what());
		return 1;
	}
	return 0;
}

/*int main() {
      Mat img=imread("33.jpg",1);
      namedWindow("窗口名",0);//创建窗口

      cvResizeWindow("窗口名", 500, 500); //创建一个500*500大小的窗口

      imshow("窗口名",img);//在创建的窗口中显示图片
      //imshow("yuantu",img);
      waitKey(0);
      return 0;
 }*/
