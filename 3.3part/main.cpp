#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("/home/fang/forcv/image/colorful.png");
    Mat dst,gray,morpho;
    Mat stats,centoids,labels;
    cvtColor(src,gray,COLOR_BGR2HSV);
    inRange(gray,Scalar(0,43,46),Scalar(10,255,255),dst);
    Mat element = getStructuringElement(MORPH_RECT,Size(5,5));
    Mat element2 = getStructuringElement(MORPH_RECT,Size(6,6));
    morphologyEx(dst,morpho,MORPH_OPEN,element);
    morphologyEx(morpho,morpho,MORPH_DILATE,element,Point(-1,-1),4);
    connectedComponentsWithStats(morpho,labels,stats,centoids);
    int x,y,width,height;
    x= stats.at<int>(2,0);
    y = stats.at<int>(2,1);
    width = stats.at<int>(2,2);
    height = stats.at<int>(2,3);
    rectangle(src,Point(x,y),Point(x+width,y+height),Scalar(0,255,0),3);
    imshow("source",src);
    /*imshow("Effect",dst);
    imshow("Result",morpho);*/
    waitKey(0);
    return 0;
}