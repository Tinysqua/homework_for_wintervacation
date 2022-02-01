#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("/home/fang/forcv/image/yellow.jpg");
    Mat dst;
    cvtColor(src,dst,COLOR_RGB2GRAY);
    imshow("src",src);
    imshow("greyone",dst);
    waitKey(0);
    return 0;

}