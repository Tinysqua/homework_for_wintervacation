#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main()
{
    Mat src = imread("/home/fang/forcv/image/coin.png");
    Mat gray,dst1,dst2,labels,centroids;
    cvtColor(src,gray,COLOR_BGR2GRAY);
    threshold(gray,dst1,90,255,0);
    //Mat element = getStructuringElement(MORPH_RECT,Size(3,3));
    //morphologyEx(dst1,dst2,MORPH_CLOSE,element,Point(-1,-1),5);
    connectedComponentsWithStats(dst1,labels,dst2,centroids);
    for(int i=1;i<dst2.rows;i++)
    {
        int x,y,width,height;
        x = dst2.at<int>(i,0);
        y = dst2.at<int>(i,1);
        width = dst2.at<int>(i,2);
        height = dst2.at<int>(i,3);
        rectangle(src,Point(x,y),Point(x+width,y+height),Scalar(0,0,255),5);
    }
    imshow("Effect1",src);
    waitKey(0);
    return 0;


}