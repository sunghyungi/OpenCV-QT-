#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat image1 = imread("../image/add2.jpg", IMREAD_GRAYSCALE);
    Mat image2 = imread("../image/add1.jpg", IMREAD_GRAYSCALE);
    CV_Assert(!(image1.empty() || image2.empty()));


    double alpha = 0, beta = 0;

    for(int i =0; i<100; i++)
    {


        alpha = alpha + 0.01;
        beta = beta + 0.01;

        Mat add_img4;
        cout << alpha << endl;
        addWeighted(image1, alpha, image2, beta, 0, add_img4);
        imshow("add_img4", add_img4);
        waitKey(50);
    }


    waitKey(0);
    return 0;
}
