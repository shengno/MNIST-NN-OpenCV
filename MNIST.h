#ifndef MNIST_H
#define MNIST_H

#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

struct MNISTImageFileHeader
{
    unsigned char MagicNumber[4];
    unsigned char NumberOfImages[4];
    unsigned char NumberOfRows[4];
    unsigned char NumberOfColums[4];
};


struct MNISTLabelFileHeader
{
    unsigned char MagicNumber[4];
    unsigned char NumberOfLabels[4];
};

const int MAGICNUMBEROFIMAGE = 2051;
const int MAGICNUMBEROFLABEL = 2049;

int ConvertCharArrayToInt(unsigned char* array, int LengthOfArray);

bool IsImageDataFile(unsigned char* MagicNumber, int LengthOfArray);

bool IsLabelDataFile(unsigned char* MagicNumber, int LengthOfArray);

cv::Mat ReadData(std::fstream& DataFile, int NumberOfData, int DataSizeInBytes);

cv::Mat ReadImageData(std::fstream& ImageDataFile, int NumberOfImages);

cv::Mat ReadLabelData(std::fstream& LabelDataFile, int NumberOfLabel);

cv::Mat ReadImages(std::string& FileName);

cv::Mat ReadLabels(std::string& FileName);




#endif // MNIST_H
