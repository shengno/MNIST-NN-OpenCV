#include <iostream>
#include "MNIST.h"
#include "opencv2/opencv.hpp"
#include <opencv2/ml/ml.hpp>
#include <fstream>

void Test_ReadData();
void Test_ConvertCharArrayToInt();
void Test_NeuralNetwork();
void Test_Decode();
void Test_RND();

void Test_Mynn();
void Test_Sigmod();

int main(int argc, char** argv)
{

//    Test_ReadData();


//    Test_Decode();



    Test_NeuralNetwork();
//    Test_Mynn();

    return 0;
}

