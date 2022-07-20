#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void saltAndPepper(cv::Mat image, int n)
{
	for (int k = 0; k < n / 2; k++)
	{
		// 随机确定图像中添加椒盐噪声的位置
		int i, j;
		i = std::rand() % image.cols;       // 取余数运算，保证在图像的列数内 
		j = std::rand() % image.rows;       // 取余数运算，保证在图像的行数内 
		int write_black = std::rand() % 2;  // 判定为白色噪声还是黑色噪声的变量
		// 添加白色噪声
		if (write_black == 0)               
		{
			image.at<cv::Vec3b>(j, i)[0] = 255; //cv::Vec3b为opencv定义的一个3个值的向量类型  
			image.at<cv::Vec3b>(j, i)[1] = 255; //[]指定通道，B:0，G:1，R:2  
			image.at<cv::Vec3b>(j, i)[2] = 255;

		}
		// 添加黑色噪声
		else  
		{
			image.at<cv::Vec3b>(j, i)[0] = 0; //cv::Vec3b为opencv定义的一个3个值的向量类型  
			image.at<cv::Vec3b>(j, i)[1] = 0; //[]指定通道，B:0，G:1，R:2  
			image.at<cv::Vec3b>(j, i)[2] = 0;
		}
	}

}

int main(int argc,char** argv)
{
    Mat src,dst;
    src=imread("./data/test2.jpg");
    if(!src.data){
        cout<<"cannot load image ..."<<endl;
        return -1;
    }
    saltAndPepper(src,10000);
    namedWindow("input image",WINDOW_AUTOSIZE);
    imshow("input image",src);

    //medianBlur(src,dst,3);
    bilateralFilter(src,dst,15,150,3);
    namedWindow("median filter result",WINDOW_AUTOSIZE);
    imshow("median filter result",dst);
    Mat gb;
    GaussianBlur(src,gb,Size(15,15),3,3);
    imshow("gussian filter",gb);

    Mat resultImg;
    Mat kernel=(Mat_<int>(3,3)<<0,-1,0,-1,5,-1,0,-1,-0);
    filter2D(src,resultImg,-1,kernel,Point(-1,-1),0);
    imshow("final result",resultImg);
    waitKey(0);
    return 0;
}