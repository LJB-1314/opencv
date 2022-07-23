#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
    Mat src,dst;
    src=imread("./data/test5.png");
    if(!src.data)
    {
        cout<<"cannot load image ..."<<endl;
        return -1;
    }
    namedWindow("input image",WINDOW_AUTOSIZE);
    imshow("input image",src);

    Mat gray_src;
    cvtColor(src,gray_src,CV_BGR2GRAY);
    imshow("gray_src",gray_src);

    Mat bin_image;
    adaptiveThreshold(gray_src,bin_image,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,-2);
    imshow("bin_image",bin_image);

    Mat hline=getStructuringElement(MORPH_RECT,Size(src.cols/16,1),Point(-1,-1));
    Mat vline=getStructuringElement(MORPH_RECT,Size(1,src.rows/16),Point(-1,-1));
    Mat kernel=getStructuringElement(MORPH_RECT,Size(9,9),Point(-1,-1));
    Mat temp;
    erode(bin_image,temp,kernel);
    dilate(temp,dst,kernel);//这两步等同于开操作
    bitwise_not(dst,dst);
    //blur(dst,dst,Size(3,3),Point(-1,-1));
    imshow("final image",dst);
    waitKey(0);
    return 0;
}