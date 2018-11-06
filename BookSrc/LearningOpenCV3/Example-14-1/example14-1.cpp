#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;

cv::Mat g_gray, g_binary;
int g_thresh = 100;

void on_trackbar(int, void*)
{
    cv::threshold(g_gray, g_binary, g_thresh, 255, cv::THRESH_BINARY);
    vector<vector<cv::Point> > contours;
    cv::findContours(g_binary, contours, cv::noArray(), cv::RETR_LIST,
                     cv::CHAIN_APPROX_SIMPLE);
    g_binary = cv::Scalar::all(0);

    cv::drawContours(g_binary, contours, -1, cv::Scalar::all(255));
    cv::imshow("Contours", g_binary);
}

int main(int argc, char** argv)
{

    if (argc != 2 || (g_gray = cv::imread(argv[1], 0)).empty()) {
        cout << "Find threshold depedent contours\nUsage: " << argv[0] << endl;
        return -1;
    }
    cv::namedWindow("Contours", 1);
    cv::createTrackbar("Threhold", "Contours", &g_thresh, 255, on_trackbar);
    on_trackbar(0, 0);

    cv::waitKey();

    return 0;
}
