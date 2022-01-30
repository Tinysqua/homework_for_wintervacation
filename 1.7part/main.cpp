#include<iostream>
#include<opencv2/opencv.hpp>
//#include<cmath>
using namespace std;
using namespace cv;

void gammachange(Mat& src,Mat& dst,double gamma)
{
    dst = src.clone();
    MatIterator_<Vec3b> it, end;
    for(it = dst.begin<Vec3b>(),end =dst.end<Vec3b>();it != end;it++)
    {
        (*it)[0] = pow((double)(*it)[0],gamma)*pow(255.0,-gamma+1);
        (*it)[1] = pow((double)(*it)[1],gamma)*pow(255.0,-gamma+1);
        (*it)[2] = pow((double)(*it)[2],gamma)*pow(255.0,-gamma+1);
    }
}

int main()
{
    Mat src = imread("/home/fang/forcv/image/gamma.png");
    Mat dst1,dst2,dst3;
    gammachange(src,dst1,0.5);
    gammachange(src,dst2,0.65);
    gammachange(src,dst3,1.25);
    imshow("Effect1_gammapoint:0.5",dst1);
    imshow("Effect2_gammapoint:0.65",dst2);
    imshow("Original_picture",src);
    waitKey(0);
    return 0;
}