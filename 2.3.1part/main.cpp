#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat src1 =  imread("/home/fang/forcv/image/one.png");
    Mat src2 =  imread("/home/fang/forcv/image/two.png");
    //Put in the picture after thresholding
    Mat dst1,dst2;
    Mat element = getStructuringElement(MORPH_RECT,Size(10,10));
    erode(src1,dst1,element);
    dilate(dst1,src1,element);
    dilate(src2,dst2,element);
    erode(dst2,src2,element);
    imshow("src",src1);
    imshow("Effect1",dst1);
    imshow("Effect2",dst2);
    waitKey(0);
    return 0;
}