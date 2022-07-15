#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
    Mat src;
    src=imread("./data/test.jpg");
    if(!src.data){
        cout<<"could not load image"<<endl;
        return -1;
    }
    namedWindow("input image",CV_WINDOW_AUTOSIZE);
    imshow("input image",src);

    namedWindow("output window",WINDOW_AUTOSIZE);

    

    Mat output_image;
    cvtColor(src,output_image,CV_BGR2HLS);
    imshow("output window",output_image);
    imwrite("./data/hlstest.jpg",output_image);
    waitKey(0);
    return 0;
}