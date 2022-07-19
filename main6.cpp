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
    char input_title[]="input_image";
    namedWindow(input_title,WINDOW_AUTOSIZE);
    imshow(input_title,src);

    //contrast and brightness change
    Mat m1;
    src.convertTo(m1,CV_32F);
    dst=Mat::zeros(src.size(),src.type());
    int height=src.rows;
    int width=src.cols;
    float alpha=1.5;
    float beta=100;
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(src.channels()==3){
                float b=m1.at<Vec3f>(row,col)[0];
                float g=m1.at<Vec3f>(row,col)[1];
                float r=m1.at<Vec3f>(row,col)[2];

                dst.at<Vec3f>(row,col)[0]=saturate_cast<uchar>(alpha*b+beta);
                dst.at<Vec3f>(row,col)[1]=saturate_cast<uchar>(alpha*g+beta);
                dst.at<Vec3f>(row,col)[2]=saturate_cast<uchar>(alpha*r+beta);
            }else if(src.channels()==1){
                float v=m1.at<uchar>(row,col);

                dst.at<uchar>(row,col)=saturate_cast<uchar>(v*alpha+beta);
            }
        }
    }
    char output_title[]="contrast and brightness change demo";
    namedWindow(output_title,WINDOW_AUTOSIZE);
    imshow(output_title,dst);
    waitKey(0);
    return 0;
}