#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    FileStorage fs_r("test.xml", FileStorage::READ);
    CV_Assert(fs_r.isOpened());

    FileNode node_pic = fs_r["picture"];			// 시퀀스 노드
    vector<Mat> images;
    for (int i = 0; i < node_pic.size(); i++)
    {
        cout << (string)node_pic[i] << endl;
        Mat tmp = imread("./" + (string)node_pic[i], IMREAD_UNCHANGED);
        CV_Assert(tmp.data);
        images.push_back(tmp);
        imshow(node_pic[i], images[i]);
    }


    FileStorage fs_w("result.xml", FileStorage::WRITE);
    CV_Assert(fs_w.isOpened());

    vector<double> mean, dev;
    Mat image_temp;

    for (int i = 0; i < images.size(); i++) {
        cout << node_pic.size();
        string pic_name = ((string)node_pic[i]).substr(0,5);

        meanStdDev(images[i], mean, dev);
        fs_w << pic_name + "_mean" << "[";
        for (int j = 0; j < (int)mean.size(); j++) {
            fs_w << mean[i];
        }
        fs_w << "]";
        fs_w << pic_name + "_dev" << dev;

        fs_w << "Image_temp" << "[";
//        for (int j = 0; j < (int)images.size(); j++) {
//            fs_w << images[i];
//        }
        fs_w << "]";

    }

    waitKey();
    fs_r.release();
    fs_w.release();
    return 0;
}
