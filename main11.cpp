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
    namedWindow("input image",WINDOW_AUTOSIZE);
    imshow("input image",src);

    char output_image[]="morphology demo";
    namedWindow(output_image,WINDOW_AUTOSIZE);
    
    Mat kernel=getStructuringElement(MORPH_RECT,Size(25,25),Point(-1,-1));
    morphologyEx(src,dst,CV_MOP_GRADIENT,kernel);
    imshow(output_image,dst);
    waitKey(0);
    return 0;
}