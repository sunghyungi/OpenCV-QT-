#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void filter(Mat img, Mat& dst, Mat mask)		// 회선 수행 함수
{
    dst = Mat(img.size(), CV_32F, Scalar(0));			// 회선 결과 저장 행렬
    Point h_m = mask.size() / 2;							// 마스크 중심 좌표

    for (int i = h_m.y; i < img.rows - h_m.y; i++) {		// 입력 행렬 반복 순회
        for (int j = h_m.x; j < img.cols - h_m.x; j++)
        {
            float sum = 0;
            for (int u = 0; u < mask.rows; u++) {	// 마스크 원소 순회
                for (int v = 0; v < mask.cols; v++)
                {
                    int y = i + u - h_m.y;
                    int x = j + v - h_m.x;
                    sum += mask.at<float>(u, v) * img.at<uchar>(y, x);	// 회선 수식
                }
            }
            dst.at<float>(i, j) = sum;				// 회선 누적값 출력화소 저장
        }
    }
}

int main()
{
    Mat image = imread("../image/filter_blur.jpg", IMREAD_GRAYSCALE);
    CV_Assert(image.data);						// 영상파일 예외 처리

    float data[] = {							// 사프닝 마스크 원소 지정
        1/9.f, 1/9.f, 1/9.f,
        1/9.f, 1/9.f, 1/9.f,
        1/9.f, 1/9.f, 1/9.f,
    };


    Mat mask(3, 3, CV_32F, data);			// 마스크 행렬 선언

    Mat sharpen1;
    filter(image, sharpen1, mask);				// 회선 수행
    sharpen1.convertTo(sharpen1, CV_8U);		// 자료형 변환

    imshow("blur", sharpen1);				// 결과 행렬 윈도우에 표시
    imshow("image", image);
    waitKey();
    return 0;
}
