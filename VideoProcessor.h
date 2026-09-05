#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H
#include <string>
#include <opencv2/opencv.hpp>
#include "LinkedList.h"
class VideoProcessor{
 double threshold;
 double difference(const cv::Mat&a,const cv::Mat&b);
public:
 explicit VideoProcessor(double t=15.0):threshold(t){}
 void processVideo(const std::string&path,LinkedList&slides);
};
#endif
