#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    int degree =0;
    while(degree<360)
    {
        vector<Point3f> rect_pt1, rect_pt2;
        rect_pt1.push_back(Point3f(200, 50, 1));
        rect_pt1.push_back(Point3f(400, 50, 1));
        rect_pt1.push_back(Point3f(400, 250, 1));
        rect_pt1.push_back(Point3f(200, 250, 1));
        degree +=1;
        float theta = degree * CV_PI / 180;
        cout << degree << endl;


        Matx33f m( cos(theta), -sin(theta), 0, sin(theta), cos(theta),0,0,0,1);

        Mat t1 = Mat::eye(3,3,CV_32F);
        Mat t2 = Mat::eye(3,3,CV_32F);

        Point3f delta = (rect_pt1[2]-rect_pt1[0]) / 2.0f;
        Point3f center = rect_pt1[0] + delta;

        t1.at<float>(0,2) = center.x;
        t1.at<float>(1,2) = center.y;
        t2.at<float>(0,2) = -center.x;
        t2.at<float>(1,2) = -center.y;

        Mat m2 = t1 * (Mat)m * t2;


        transform(rect_pt1, rect_pt2, m2);


        Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));
        for (int i = 0; i < 4; i++)
        {
            Point pt1(rect_pt1[i].x, rect_pt1[i].y);
            Point pt2(rect_pt1[(i+1) % 4].x, rect_pt1[(i+1)%4].y);
            Point pt3(rect_pt2[i].x, rect_pt2[i].y);
            Point pt4(rect_pt2[(i+1) % 4].x, rect_pt2[(i+1)%4].y);

            line(image, pt1, pt2, Scalar(0, 0, 0), 1);
            line(image, pt3, pt4, Scalar(255, 0, 0), 2);
            cout << "rect_pt1[" + to_string(i) + "]=" << rect_pt1[i] << "\t";
            cout << "rect_pt2[" + to_string(i) + "]=" << rect_pt2[i] << endl;
        }
        imshow("image", image);
        waitKey(10);

    }

    waitKey();
    return 0;
}
