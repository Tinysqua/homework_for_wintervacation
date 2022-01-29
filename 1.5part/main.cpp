#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
  Mat init = Mat(1000,1000,CV_8UC3,Scalar(255,255,255));
  circle(init,Point(500,150),100,Scalar(0,0,0),20);
  line(init,Point(400,300),Point(600,300),Scalar(0,0,0),20);
  rectangle(init,Point(400,500),Point(700,700),Scalar(100,201,23),20);
  imshow("init",init);
  waitKey(0);
  return 0;  
}