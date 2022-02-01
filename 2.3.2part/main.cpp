#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("/home/fang/forcv/image/connect.png");
    Mat dst0,dst1,dst2,dst3,gray;
    cvtColor(src,gray,COLOR_BGR2GRAY);
    threshold(gray,dst1,125,255,1);
    imshow("dst1",dst1);
    Mat element = getStructuringElement(MORPH_RECT,Size(2,2));
    //erode(dst1,dst0,element,Point(-1,-1),5);
    morphologyEx(dst1,dst2,MORPH_CLOSE,element,Point(-1,-1),5);
    Mat stats,centoids;
    imshow("dst2",dst2);
    connectedComponentsWithStats(dst2,dst3,stats,centoids);
    for(int i=2;i<centoids.rows;i++)
    {
        int x1,y1,width,height;
        x1 = stats.at<int>(i,0);
        y1 = stats.at<int>(i,1);
        width = stats.at<int>(i,2);
        height = stats.at<int>(i,3);
        rectangle(src,Point(x1,y1),Point(x1+width,y1+height),Scalar(0,0,255),3);
    }
    imshow("Effect",src);
    cout<<"the number of the flips is: "<<centoids.rows-2<<endl;
    waitKey(0);
    return 0;
}