#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
   Mat cat = imread("/home/fang/forcv/image/cat.jpeg"); 
   double total;
   int rows = cat.rows;
   int columns = cat.cols;
   int cha = cat.channels();
   cout<<cha;
   Mat catclone = cat.clone();
   for(int i=0;i<rows;i++)
    {   for(int j=0;j<columns;j++)
       {
        total = (cat.at<Vec3b>(i,j)[0]+cat.at<Vec3b>(i,j)[1]+cat.at<Vec3b>(i,j)[2])/3;
        catclone.at<Vec3b>(i,j)[0] = total;
        catclone.at<Vec3b>(i,j)[1] = total;
        catclone.at<Vec3b>(i,j)[2] = total;
       }}
   namedWindow("catclone",WINDOW_NORMAL);
    imshow("catclone",catclone);
    waitKey(0);
    return 0;
}