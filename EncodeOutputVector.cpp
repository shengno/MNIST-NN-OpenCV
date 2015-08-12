#include <opencv2/opencv.hpp>

#include "NeuralNetworksFunctions.h"



bool ConvertIntToVector(int Input, cv::Mat& Vector, int NumberOfClasses)
{
    //
    if ((Input > NumberOfClasses) || (Input < 0))
    {
        return false;
    }


    //
    if ((Vector.cols != NumberOfClasses) || (Vector.type() != CV_32FC1))
    {
        return false;
    }

    //
    cv::MatIterator_<float> it = Vector.begin<float>();
    *(it + Input) = 1;

//    std::cout << "The int is " << Input << "  ";
//    std::cout << "The vector is " << Vector << std::endl;

    return true;
}



/**
 * @brief EncodeOutputVector
 * @param OriginVector
 * @param DstVector
 */
void EncodeOutputVector(const cv::Mat& OriginVector, cv::Mat& DstVector,
                        int NumberOfClasses)
{
    int NumberOfVectors = OriginVector.rows;

    DstVector = cv::Mat::zeros(NumberOfVectors, NumberOfClasses, CV_32FC1);

    cv::Mat Tmp;
    int Row = 0;
    for (cv::MatConstIterator_<uchar> it = OriginVector.begin<uchar>();
         it != OriginVector.end<uchar>();
         it++)
    {
        Tmp = DstVector.row(Row);
        ConvertIntToVector(*it, Tmp, NumberOfClasses);
        Row++;
    }

}





