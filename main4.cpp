#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    Mat src;
    src=imread("./data/test.jpg");
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return  -1;
    }
    namedWindow("input image",WINDOW_AUTOSIZE);
    imshow("input image",src);
    
   /* Mat src_gray;
    int gray=0;
    cvtColor(src,src_gray,CV_BGR2GRAY);
    namedWindow("output image",WINDOW_AUTOSIZE);
    imshow("output image",src_gray);

    int height=src_gray.rows;
    int width=src_gray.cols;
    for(int row=0;row<height;row++){
        for(int col=0;row<width;col++){
            gray=src_gray.at<uchar>(row,col);
            src_gray.at<uchar>(row,col)=255-gray;
        }
       
    }
    namedWindow("opposite of src_gray",WINDOW_AUTOSIZE);
    imshow("opposite of src_gray",src_gray);*/
    waitKey(0);
    return 0;
}
