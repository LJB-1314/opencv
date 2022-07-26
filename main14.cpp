#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

Mat src,gray_src,dst;
int threshold_value=127;
int threshold_max=255;
char output_title[]="output image";
void Threshold_Demo(int);
int type_value=2;
int type_max=4;
int main(int argc,char** argv)
{
    
    src=imread("./data/test.jpg");
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return -1;
    }
    namedWindow("input image",WINDOW_AUTOSIZE);
    namedWindow(output_title,WINDOW_AUTOSIZE);
    imshow("input image",src);
    cvCreateTrackbar("threshold_value",output_title,&threshold_value,threshold_max,Threshold_Demo);
    cvCreateTrackbar("type_value",output_title,&type_value,type_max,Threshold_Demo);
    Threshold_Demo(0);
    waitKey(0);
    return 0;
}
void Threshold_Demo(int)
{
    cvtColor(src,gray_src,CV_BGR2GRAY);
    threshold(gray_src,dst,threshold_value,threshold_max,type_value);
    imshow(output_title,dst);
    return;
}