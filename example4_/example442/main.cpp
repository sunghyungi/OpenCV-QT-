#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat img8 = imread("read_color.jpg", IMREAD_COLOR);
    CV_Assert(img8.data);

    vector<int> params_jpg, params_png;
    params_jpg.push_back(IMWRITE_JPEG_QUALITY);
    params_jpg.push_back(50);
    params_png.push_back(IMWRITE_PNG_COMPRESSION);
    params_png.push_back(9);

    imwrite("write_test1.jpg", img8);
    imwrite("write_test2.jpg", img8, params_jpg);
    imwrite("write_test.png", img8, params_png);
    imwrite("write_test.bmp", img8);
    return 0;
}
