#ifndef MYNNFUCNTIONS_H
#define MYNNFUCNTIONS_H

#include <iostream>
#include "opencv2/opencv.hpp"
#include <math.h>

void Sigmod(const cv::Mat& Input, cv::Mat& Output);

void DeSigmod(const cv::Mat& Input, cv::Mat& Output);

#endif // MYNNFUCNTIONS_H
