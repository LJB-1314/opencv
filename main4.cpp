#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    Mat src;
    src=imread("./data/test.jpg");
    Mat src_gray;
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return  -1;
    }
    namedWindow("input image",WINDOW_AUTOSIZE);
    imshow("input image",src);
    
    
    cvtColor(src,src_gray,COLOR_BGR2GRAY);
    namedWindow("output image",CV_WINDOW_AUTOSIZE);
    imshow("output image",src_gray);
    
    //单通道
    int height=src_gray.rows;
    int width=src_gray.cols;
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            int gray=src_gray.at<uchar>(row,col);
            src_gray.at<uchar>(row,col)=255-gray;
        }
       
    }
    namedWindow("opposite of src_gray",CV_WINDOW_AUTOSIZE);
    imshow("opposite of src_gray",src_gray);


    //三通道
    Mat dst;
    dst.create(src.size(),src.type());
    height=src.rows;
    width=src.cols;
    int nc=src.channels();
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(nc==1){
                int gray=src.at<uchar>(row,col);
                src.at<uchar>(row,col)=255-gray;
            }else if(nc==3){
                int b=src.at<Vec3b>(row,col)[0];
                int g=src.at<Vec3b>(row,col)[1];
                int r=src.at<Vec3b>(row,col)[2];
                dst.at<Vec3b>(row,col)[0]=255-b;
                dst.at<Vec3b>(row,col)[1]=255-g;
                dst.at<Vec3b>(row,col)[2]=255-r;
            }
        }
    }
    namedWindow("彩色取反操作",WINDOW_AUTOSIZE);
    imshow("彩色取反操作",dst);
    //在彩色取反操作中，bitwise_not(src,dst);有同样的效果
    waitKey(0);
    return 0;
}
/*#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv) {
	Mat srcImage = imread("./data/test.jpg");
	Mat gray_src;
	if (!srcImage.data) {
		printf("没有找到图片");
		return -1;
	}
	namedWindow("input image",WINDOW_AUTOSIZE);
	imshow("input image", srcImage);

	cvtColor(srcImage, gray_src, COLOR_BGR2GRAY);
	namedWindow("input gray", WINDOW_AUTOSIZE);
	imshow("input gray", gray_src);

	int heigth = gray_src.rows;
	int width = gray_src.cols;

	for (int row = 0; row < heigth; row++) {
		for (int col = 0; col < width; col++) {
			int gray = gray_src.at<uchar>(row,col);    //获取像素值
			gray_src.at<uchar>(row,col) = 255-gray; //像素值取反赋值
		}
	}

	namedWindow("取反操作",WINDOW_AUTOSIZE);
	imshow("取反操作", gray_src);
	waitKey(0);
	return 0;
}
*/
