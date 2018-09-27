#include "opencv2/opencv.hpp"

int main(int argc, char **argv) {

  cv::namedWindow(argv[1], cv::WINDOW_NORMAL);
  cv::Mat img = cv::imread(argv[1]);
  cv::imshow(argv[1], img);

  /*! 一直等待按ESC键退出 */
  while (true) {
    if (cv::waitKey(100) == 27) break;
  }

  cv::destroyWindow(argv[1]);

  return 0;
}
