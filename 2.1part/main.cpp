#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("/home/fang/forcv/image/yellow.jpg");
    int row = src.rows;
    int colu = src.cols;
    Mat dst = src.clone();
    Mat hsvImage;
    cvtColor(src,hsvImage,COLOR_BGR2HSV);
    inRange(hsvImage,Scalar(11,43,46),Scalar(25,255,255),dst);
    //namedWindow("take_out_yellow",WINDOW_NORMAL);
    //namedWindow("src",WINDOW_NORMAL);
    imshow("src",src);
    imshow("take_out_yellow",dst);
    waitKey(0);
    return 0;

}