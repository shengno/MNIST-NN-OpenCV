#include <iostream>

#include "opencv2/opencv.hpp"

void Test_RND()
{
    cv::Mat Rand_Mat(4, 4, CV_32FC1, cv::Scalar(0));

    cv::randu(Rand_Mat, -0.5, 0.5);

    std::cout << "The rand mat is" << Rand_Mat << std::endl;

    cv::RNG rand_constructor;
    std::cout << "The rand number is" << float(rand_constructor) << std::endl;
}
