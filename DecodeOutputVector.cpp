#include "NeuralNetworksFunctions.h"
#include <iostream>
#include <opencv2/opencv.hpp>


/**
 * @brief ConvertVectorToInt
 * @param Vector
 * @param NumberOfClass
 * @return
 */
int ConvertVectorToInt(const cv::Mat& Vector, int NumberOfClass)
{
    int Output = -1;

    if (Vector.cols > NumberOfClass)
    {
        return Output;
    }

    float  MaxOutput = -2;


    for (cv::MatConstIterator_<float> it = Vector.begin<float>();
         it != Vector.end<float>();
         it++)
    {
        if ((*it) > MaxOutput)
        {
            MaxOutput = (*it);
            Output = it - Vector.begin<float>();
        }
    }

//    std::cout << "The vecotr is " << Vector
//              << " The int is " << Output << std::endl;

    return Output;
}



/**
 * @brief DecodeOutputVector
 * @param OriginVector
 * @param DstVector
 * @param NumberOfClasses
 */
void DecodeOutputVector(const cv::Mat& OriginVector, cv::Mat& DstVector,
                        int NumberOfClass)
{
    DstVector = cv::Mat::zeros(OriginVector.rows, 1, CV_8UC1);

    int IndexOfRow = 0;


    for (cv::MatIterator_<uchar> it = DstVector.begin<uchar>();
         it != DstVector.end<uchar>();
         it++)
    {
        (*it) = ConvertVectorToInt(OriginVector.row(IndexOfRow), NumberOfClass);
        IndexOfRow++;

//        std::cout << "The int is " << int(*it) << std::endl;

    }

}
