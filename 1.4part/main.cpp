#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat picture =  imread("/home/fang/forcv/image/three.png",1);
    vector<Mat> channels ;
    Mat channelblue,channelgreen,channelred;
    split(picture,channels);
    channelblue = channels.at(0);
    channelgreen = channels.at(1);
    channelred = channels.at(2);
    imshow("blue",channelblue);
    imshow("green",channelgreen);
    imshow("red",channelred);
    waitKey(0);
    return 0;
}