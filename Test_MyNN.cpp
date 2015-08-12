#include <iostream>
#include "opencv2/opencv.hpp"
#include "MyNNFucntions.h"
#include "MNIST.h"
#include "NeuralNetworksFunctions.h"

void MyNN(const cv::Mat& InputSamples, const cv::Mat& SamplesOutput,
          const cv::Mat& TestSamples, const cv::Mat& TestOutputs);

void Test_Mynn()
{
    std::string TrainingImageFileName =
            "E:/Z_PKU_sz/8.Database/MNIST/train-images.idx3-ubyte";
    cv::Mat TrainingImages = ReadImages(TrainingImageFileName);

    std::string TrainingLabelFileName =
            "E:/Z_PKU_sz/8.Database/MNIST/train-labels.idx1-ubyte";
    cv::Mat TrainingLabels = ReadLabels(TrainingLabelFileName);

    cv::Mat FloatTrainingImages;
    ConvertToFloatMat(TrainingImages, FloatTrainingImages);

    cv::Mat TrainingLabelVector;
    EncodeOutputVector(TrainingLabels, TrainingLabelVector, 10);

    std::string TestingImageFileName =
                "E:/Z_PKU_sz/8.Database/MNIST/t10k-images.idx3-ubyte";
    cv::Mat TestingImages = ReadImages(TestingImageFileName);
    cv::Mat FloatTestingImages;
    ConvertToFloatMat(TestingImages, FloatTestingImages);

    std::string TestingLabelFileName =
            "E:/Z_PKU_sz/8.Database/MNIST/t10k-labels.idx1-ubyte";
    cv::Mat TestingLabels = ReadLabels(TestingLabelFileName);
    cv::Mat TestingLabelVector;
    EncodeOutputVector(TestingLabels, TestingLabelVector, 10);

    std::cout << "Testing is begining." << std::endl;


    MyNN( -FloatTrainingImages / 255 + 1, TrainingLabelVector, - FloatTestingImages / 255 + 1,
         TestingLabelVector);
//    MyNN( TrainingLabelVector, TrainingLabelVector, TestingLabelVector,
//         TestingLabelVector);
//    MyNN(FloatTestingImages / 255 ,
//         TestingLabelVector,
//         FloatTrainingImages / 255,
//         TrainingLabelVector);
    std::cout << "Testing is ending." << std::endl;


}
