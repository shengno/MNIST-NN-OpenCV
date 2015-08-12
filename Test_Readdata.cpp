#include <MNIST.h>
#include "NeuralNetworksFunctions.h"

void Test_ReadData()
{
//    // test the ReadImages function.
//    std::string TrainingImageFileName =
//            //"E:/Z_PKU_sz/8.Database/MNIST/train-images.idx3-ubyte";
//            "E:/Z_PKU_sz/8.Database/MNIST/t10k-images.idx3-ubyte";

//    cv::Mat TrainingImages = ReadImages(TrainingImageFileName);
//    std::cout << "The rows of the TrainingImages is " << TrainingImages.rows
//              << std::endl
//              << "The cols of the TrainingImages is " << TrainingImages.cols
//              << std::endl;


//    // test the ReadLabel function.
//    std::string TrainingLabelFileName =
//            //"E:/Z_PKU_sz/8.Database/MNIST/train-labels.idx1-ubyte";
//            "E:/Z_PKU_sz/8.Database/MNIST/t10k-labels.idx1-ubyte";
//    cv::Mat TrainingLabels = ReadLabels(TrainingLabelFileName);
//    std::cout << "The rows of the TrainingLabels is " << TrainingLabels.rows
//              << std::endl
//              << "The cols of the TrainingLabels is " << TrainingLabels.cols
//              << std::endl;

//    cv::FileStorage OutputFile;
//    OutputFile.open("MNIST_Training.xml", cv::FileStorage::WRITE);
//    OutputFile << "samples" << TrainingImages;
//    OutputFile << "labels" << TrainingLabels;
//    OutputFile.release();



    cv::FileStorage OutputFile;
    OutputFile.open("MNIST_Training.xml", cv::FileStorage::READ);

    cv::Mat TrainingImages;
    OutputFile["samples"] >> TrainingImages;

    cv::Mat TrainingLabels;
    OutputFile["labels"] >> TrainingLabels;
    OutputFile.release();

//    CvFileStorage* cfile = (*OutputFile);


    // t
    for (int i = 0; i < TrainingImages.rows; i++)
    {
        cv::Mat Tmp(28, 28, CV_8UC1, TrainingImages.row(i).data);
        cv::namedWindow("test");
        cv::imshow("test", Tmp);
        std::cout << "The label is" << int(TrainingLabels.data[i]) << std::endl;
        cv::waitKey();
        cv::destroyAllWindows();
    }


}
