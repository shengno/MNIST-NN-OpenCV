#include "NeuralNetworksFunctions.h"
#include "MNIST.h"

#include "opencv2/opencv.hpp"

void Test_Decode()
{
    std::string TrainingLabelFileName =
            "E:/Z_PKU_sz/8.Database/MNIST/train-labels.idx1-ubyte";
    cv::Mat TrainingLabels = ReadLabels(TrainingLabelFileName);

    cv::Mat TrainingLabelVector;
    EncodeOutputVector(TrainingLabels, TrainingLabelVector, 10);

    cv::Mat TraingingDecode;
    DecodeOutputVector(TrainingLabelVector, TraingingDecode, 10);

    for (int i = 0; i< TraingingDecode.rows; i++)
    {
        std::cout << "The actural is " << (int)TrainingLabels.at<uchar>(i) << std::endl;
        std::cout << "The encode vector is" << TrainingLabelVector.row(i) << std::endl;
        std::cout << "The decode int is" << (int)TraingingDecode.at<uchar>(i) << std::endl;
        cv::namedWindow("hello");
        cv::imshow("hello", cv::Mat(50, 50, CV_8UC1, cv::Scalar(0)));
        cv::waitKey();
        cv::destroyAllWindows();
    }
}
