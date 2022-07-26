#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
    Mat src,dst;
    src=imread("./data/test.jpg");
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return -1;
    }
    char INPUT_WIN[]="input image";
    char OUTPUT_WIN[]="sample up";
    namedWindow(INPUT_WIN,WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_WIN,WINDOW_AUTOSIZE);
    imshow(INPUT_WIN,src);
    //上采样
    pyrUp(src,dst,Size(src.cols*2,src.rows*2));
    imshow(OUTPUT_WIN,dst);
    //降采样
    Mat src_down;
    pyrDown(src,src_down,Size(src.cols/2,src.rows/2));
    imshow("sample down",src_down);

    //高斯不同
    Mat gray_src,g1,g2,DOG_img;
    cvtColor(src,gray_src,CV_BGR2GRAY);
    GaussianBlur(gray_src,g1,Size(3,3),0,0);
    GaussianBlur(g1,g2,Size(3,3),0,0);
    subtract(g1,g2,DOG_img,Mat());

    //归一化显示
    normalize(DOG_img,DOG_img,255,0,NORM_MINMAX);
    imshow("DOG_IMG",DOG_img);
    waitKey(0);
    return 0;
}