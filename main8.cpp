#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
    Mat src,dst;
    src=imread("./data/test2.jpg");
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return -1;
    }
    char input_title[]="input image";
    char output_title[]="blur demo";
    namedWindow(input_title,WINDOW_AUTOSIZE);
    namedWindow(output_title,WINDOW_AUTOSIZE);
    imshow(input_title,src);
    blur(src,dst,Size(1,15),Point(-1,-1));
    imshow(output_title,dst);
    Mat dbblur;
    GaussianBlur(src,dbblur,Size(11,11),11,11);
    imshow("gussian_blur",dbblur);
    waitKey(0);
    return 0;
}