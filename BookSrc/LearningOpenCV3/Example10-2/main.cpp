#include <vector>

#include "opencv2/opencv.hpp"

void sumRGB(const cv::Mat &src, cv::Mat &dst) {
  std::vector<cv::Mat> planes;
  cv::split(src, planes);

  cv::Mat b = planes[0];
  cv::Mat g = planes[1];
  cv::Mat r = planes[2];

  cv::Mat s = cv::Mat::zeros(b.size(), CV_32F);
  cv::accumulate(b, s);
  cv::accumulate(g, s);
  cv::accumulate(r, s);
  
  cv::threshold(s, dst, 100, 100, cv::THRESH_TRUNC);
  s.convertTo(dst, b.type());
}

void help() {
  std::cout << "Call: ./Example10-1 ../../../pictures/avtar.png" << std::endl;
  std::cout << "Shows use of alpha blending (addWeighted) and threshold" << std::endl;
}

int main(int argc, char **argv) {

  help();
  if (argc < 2) {
    std::cout << "specify input image" << std::endl;
    return -1;
  }

  cv::Mat src = cv::imread(argv[1]);
  cv::Mat dst;

  if (src.empty()) {
    std::cout << "Can not load " << argv[1] << std::endl;
    return -1;
  }

  sumRGB(src, dst);

  cv::namedWindow(argv[1], cv::WINDOW_NORMAL);
  cv::imshow(argv[1], dst);

  cv::waitKey(0);

  return 0;
}
