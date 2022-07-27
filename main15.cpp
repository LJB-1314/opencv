#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
    Mat src,dst;
    int ksize=0;
    src=imread("./data/test.jpg");
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return -1;
    }
    char INPUT_WIN[]="input image";
    char OUTPUT_WIN[]="result image";

    namedWindow(INPUT_WIN,WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_WIN,WINDOW_AUTOSIZE);
    imshow(INPUT_WIN,src);
   //可以测试sobel robert 拉普拉斯三个算子
   /* Mat kernel=(Mat_<int>(3,3) <<0,-1,0,-1,4,-1,0,-1,0);
    filter2D(src,dst,-1,kernel,Point(-1,-1),0.0);
    imshow(OUTPUT_WIN,dst);
    waitKey(0);*/

    //自定义模板
    int c=0;
    int index=0;
    while(true){
        c=waitKey(500);
        if((char)c==27){
            break;
        }
        ksize=4+(index%8)*2+1;
        Mat kernel=Mat::ones(Size(ksize,ksize),CV_32F)/float(ksize*ksize);
        filter2D(src,dst,-1,kernel,Point(-1,-1));
        index++;
        imshow(OUTPUT_WIN,dst);
    }
    return 0;
}