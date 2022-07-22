#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat src,dst;
char OUTPUT_WIN[]="output window";
int element_size=3;
int max_size=21;
void CallBack_Demo(int,void*);    
int main(int argc,char** argv)
{
    src=imread("./data/test2.jpg");
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return -1;
    }
    namedWindow("input image",WINDOW_AUTOSIZE);
    imshow("input image",src);
    
    namedWindow(OUTPUT_WIN,WINDOW_AUTOSIZE);
    createTrackbar("element size",OUTPUT_WIN,&element_size,max_size,CallBack_Demo);
    CallBack_Demo(0,0);
    waitKey(0);
    return 0;
}
void CallBack_Demo(int,void*)
{
    int s=element_size*2+1;
    Mat structureElenment=getStructuringElement(MORPH_RECT,Size(s,s),Point(-1,-1));
    //dilate(src,dst,structureElenment,Point(-1,-1),1);
    erode(src,dst,structureElenment);
    imshow(OUTPUT_WIN,dst);
    return;
}