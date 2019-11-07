// 예제 3.1.1

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int  main()
{
    // Point_ 객체 선언 방식
    Point_<int> pt1(100, 200);
    Point_<float> pt2(92.3f, 125.23f);
    Point_<double> pt3(100.2, 300.9);

    // Point_ 객체 간결 선언 방식
    Point2i  pt4(120, 69);
    Point2f  pt5(0.3f, 0.f), pt6(0.f, 0.4f);
    Point2d  pt7(0.25, 0.6);

    // Point_ 객체 연산
    Point    pt8 = pt1 + (Point) pt2;
    Point2f  pt9 = pt6 * 3.14f;
    Point2d  pt10 = (pt3 + (Point2d) pt6) * 10;

    cout << "pt8 = " << pt8.x << " , " << pt8.y << std::endl;
    cout << "[pt9] = " << pt9 << std::endl;
    cout << (pt2 == pt6) << std::endl;
    cout << "pt7과 pt8의 내적 : " << pt7.dot(pt8) << std::endl;
    return 0;
}
