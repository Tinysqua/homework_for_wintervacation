#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    VideoCapture capture(0);
    namedWindow("meanblur",WINDOW_AUTOSIZE);
    namedWindow("blur",WINDOW_AUTOSIZE);
    namedWindow("Gaosi0.2",WINDOW_AUTOSIZE);
    namedWindow("Gaosi10",WINDOW_AUTOSIZE);
    while(true)
    {
        Mat frame,frame1,frame2;
        capture>>frame;
        medianBlur(frame,frame1,9);
        imshow("meanblur",frame1);
        if(waitKey(20)==27)
            break;
    }
    while(true)
    {
        Mat frame,frame1,frame2;
        capture>>frame;
        blur(frame,frame1,Size(3,3));
        imshow("blur",frame1);
        if(waitKey(20)==27)
            break;
    }
    while(true)
    {
        Mat frame,frame1,frame2;
        capture>>frame;
        GaussianBlur(frame,frame1,Size(3,3),0.2);
        GaussianBlur(frame,frame2,Size(3,3),50);
        imshow("Gaosi0.2",frame1);
        imshow("Gaosi10",frame2);
        if(waitKey(20)==27)
            break;
    }
 
}