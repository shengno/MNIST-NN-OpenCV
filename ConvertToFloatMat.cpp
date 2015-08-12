#include <opencv2/opencv.hpp>

#include "NeuralNetworksFunctions.h"

/**
 * @brief ConvertToFloatMat
 * @param InputMat
 * @param OutputMat
 */
void ConvertToFloatMat(const cv::Mat& InputMat, cv::Mat& OutputMat)
{
    int DstType = 0;
    if (InputMat.channels() == 3)
    {
        DstType = CV_32FC3;
    }
    else
    {
        DstType = CV_32FC1;
    }

    InputMat.convertTo(OutputMat, DstType);
}
