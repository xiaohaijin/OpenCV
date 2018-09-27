#include <iostream>

#include "opencv2/opencv.hpp"

int main(int argc, char **argv) {

  if (argc != 7) {
    std::cout << "Usage: " << argv[0] << " fixed_threshold invert(0=off | 1 = true) "
              << "adaptive_type(0=mean | 1=gaussian) block_size offset image\n"
              << " Example: " << argv[0] << "100 1 0 15 10 test.png\n";
    return -1;
  }

  double fixed_threshold = static_cast<double>(atof(argv[1]));
  int threshold_type = atoi(argv[2]) ? cv::THRESH_BINARY : cv::THRESH_BINARY_INV;
  int adaptive_method =
      atoi(argv[3]) ? cv::ADAPTIVE_THRESH_MEAN_C : cv::ADAPTIVE_THRESH_GAUSSIAN_C;

  int block_size = atoi(argv[4]);
  double offset = static_cast<double>(atof(argv[5]));
  cv::Mat Igray = cv::imread(argv[6], cv::IMREAD_GRAYSCALE);

  if (Igray.empty()) {
    std::cout << "Can not load " << argv[6] << std::endl;
    return -1;
  }

  cv::Mat It, Iat;

  cv::threshold(Igray, It, fixed_threshold, 255, threshold_type);
  cv::adaptiveThreshold(Igray, Iat, 255, adaptive_method, threshold_type, block_size,
                        offset);

  cv::imshow("Rawf", Igray);
  cv::imwrite("raw.png", Igray);
  cv::imshow("Threshold", It);
  cv::imwrite("Threshold.png", It);
  cv::imshow("Adaptive Threshold", Iat);
  cv::imwrite("AdaptiveThreshold.png", Iat);

  cv::waitKey(0);
  return 0;
}
