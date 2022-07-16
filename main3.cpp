#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
    Mat src;
    src=imread("./data/test.jpg");
    if(src.empty()){
        cout<<"can't load image..."<<endl;
        return -1;    }
    namedWindow("input",WINDOW_AUTOSIZE);
    imshow("input",src);
    /*Mat dst=Mat(src.size(),src.type());
    dst=Scalar(127,0,255);*/

    //*Mat dst=src.clone();//copyTo也有这个效果
    
    Mat dst;
    cvtColor(src,dst,CV_BGR2GRAY);
    cout<<"The input channel is "<<src.channels()<<endl;
    cout<<"The ouput channel is "<<dst.channels()<<endl;

    const uchar* firstrow=dst.ptr<uchar>(0);
    cout<<"The first pixel is "<<(firstrow[1]/2)<<endl;

    namedWindow("ouput",WINDOW_AUTOSIZE);
    imshow("ouput",dst);
    waitKey(0);
    return 0;
}