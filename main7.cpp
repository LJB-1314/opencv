#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

void MyLines();
void MyRectangule();
void MyEllipse();
void MyCircle();
void Ploygon();
void RandomLineDemo();
Mat src;
int main(int argc,char **argv)
{
    src=imread("./data/test2.jpg");
    if(!src.data){
        cout<<"cannot not load image ..."<<endl;
        return -1;
    }
    /*MyLines();
    MyRectangule();
    MyEllipse();
    MyCircle();
    Ploygon();
    putText(src,"Hello Opencv",Point(300,100),CV_FONT_BLACK,2.0,Scalar(255,12,255),1,8);
    char input_title[]="input image";
    namedWindow(input_title,WINDOW_AUTOSIZE);
    imshow(input_title,src);*/
    RandomLineDemo();
    waitKey(0);
    return 0;
}

void MyLines(){
    Point p1=Point(20,30);
    Point p2;
    p2.x=200;
    p2.y=300;
    Scalar color=Scalar(0,0,255);
    line(src,p1,p2,color,1,8);
}
void MyRectangule()
{
    Rect rect=Rect(200,100,300,300);
    Scalar color=Scalar(255,0,0);
    rectangle(src,rect,color,2,LINE_8);
}
void MyEllipse()
{
    ellipse(src,Point(src.cols/2,src.rows/2),Size(src.cols/4,src.rows/8),90,0,360,LINE_8);
}
void MyCircle()
{
    Scalar color=Scalar(0,255,255);
    Point center=Point(src.rows/2,src.cols/2);
    circle(src,center,150,1,LINE_8);
}
void Ploygon()
{
    Point pts[1][5];
    pts[0][0]=Point(100,100);
    pts[0][1]=Point(100,200);
    pts[0][2]=Point(200,200);
    pts[0][3]=Point(200,100);
    pts[0][4]=Point(100,100);

    const Point* ppts[]={pts[0]};
    int npt[]={5};
    Scalar color=Scalar(255,12,255);
    fillPoly(src,ppts,npt,1,color,8);
}
void RandomLineDemo()
{
    RNG rng(12345);
    Point pt1;
    Point pt2;
    Mat dst=Mat::zeros(src.size(),src.type());
    namedWindow("RandomLine",WINDOW_AUTOSIZE);
    for(int i=0;i<10000;i++){
        pt1.x=rng.uniform(0,dst.cols);
        pt2.x=rng.uniform(0,dst.cols);
        pt1.y=rng.uniform(0,dst.rows);
        pt2.y=rng.uniform(0,dst.rows);
        Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
        if(waitKey(50)>0){
            break;
        }
        line(dst,pt1,pt2,color,1,8);
        imshow("RandomLine",dst);
    }
}