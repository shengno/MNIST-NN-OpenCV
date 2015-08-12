#ifndef NEURALNETWORKSFUNCTIONS_H
#define NEURALNETWORKSFUNCTIONS_H

#include <iostream>
#include "opencv2/opencv.hpp"

void NeuralNetworksTraing(CvANN_MLP& NeuralNetworks, const cv::Mat& InputMat,
                          const cv::Mat& OutputMat, int MaxIte);

void NeuralNetworksPredict(const CvANN_MLP& NeuralNetworks, const cv::Mat& Input,
                           cv::Mat& Output);


void ConvertToFloatMat(const cv::Mat& InputMat, cv::Mat& OutputMat);

bool ConvertIntToVector(int Input, cv::Mat& Vector, int NumberOfClasses);

void EncodeOutputVector(const cv::Mat& OriginVector, cv::Mat& DstVector,
                        int NumberOfClasses);

int ConvertVectorToInt(const cv::Mat& Vector, int NumberOfClass);

void DecodeOutputVector(const cv::Mat& OriginVector, cv::Mat& DstVector,
                        int NumberOfClass);




#endif // NEURALNETWORKSFUNCTIONS_H
