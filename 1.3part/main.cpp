#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
   Mat srccat = imread("/home/fang/forcv/image/cat.jpeg"); 
   double total;
   int rows = srccat.rows;
   int columns = srccat.cols;
   uchar threshold = 100;
   Mat shallowcopy = srccat;//This is shallow copy
   Mat deepcopy = srccat.clone();//This is deep copy
   for(int i=0;i<rows;i++)
    {   for(int j=0;j<columns;j++)
       {
        total = (srccat.at<Vec3b>(i,j)[0]+srccat.at<Vec3b>(i,j)[1]+srccat.at<Vec3b>(i,j)[2])/3;
        if(total>threshold)
            total = 255;
        else
            total = 0;
        srccat.at<Vec3b>(i,j)[0] = total;
        srccat.at<Vec3b>(i,j)[1] = total;
        srccat.at<Vec3b>(i,j)[2] = total;
       }}
   namedWindow("shallowcopy",WINDOW_NORMAL);
   namedWindow("deepcopy",WINDOW_NORMAL);
   imshow("shallowcopy",shallowcopy);
    imshow("deepcopy",deepcopy);
    waitKey(0);
    return 0;
}