#include "opencv2/opencv.hpp"
#include <iostream>

#include "MyNNFucntions.h"
#include "NeuralNetworksFunctions.h"



void MyNN(const cv::Mat& InputSamples, const cv::Mat& SamplesOutput,
          const cv::Mat& TestSamples, const cv::Mat& TestOutputs)
{
    std::cout << "Nunber of the training is " << InputSamples.rows << std::endl;

    // number of every layer
    const int NumberOfInputNeurals = InputSamples.cols;
    const int NumberOfOutputNeurals = SamplesOutput.cols;
    const int NumberOfHiddenNeurals = 300;


    // params
    cv::Mat Weight_2(NumberOfHiddenNeurals, NumberOfInputNeurals, CV_32FC1);
    cv::Mat Bias_2(NumberOfHiddenNeurals, 1, CV_32FC1);
    cv::Mat Weight_3(NumberOfOutputNeurals, NumberOfHiddenNeurals, CV_32FC1);
    cv::Mat Bias_3(NumberOfOutputNeurals, 1, CV_32FC1);


    // random initialise the params
    cv::randu(Weight_2, -1, 1);
    cv::randu(Bias_2, -1, 1);
    cv::randu(Weight_3, -1, 1);
    cv::randu(Bias_3, -1, 1);


    // The input and the output of the networks
    cv::Mat y_1;
    cv::Mat x_2;
    cv::Mat y_2;
    cv::Mat x_3;
    cv::Mat y_3;


    // training
    int NumberOfIte = 1;
    int LearningRate = 0.05;
    int NumberOfBatch = 50;
    while (NumberOfIte)
    {
        // Delta
        cv::Mat DelWeigh_2 = Weight_2 * 0.0;
        cv::Mat DelBias_2  = Bias_2 * 0.0;
        cv::Mat DelWeigh_3 = Weight_3 * 0.0;
        cv::Mat DelBias_3  = Bias_3 * 0.0;

        for (int RowNumber = 0; RowNumber < InputSamples.rows; RowNumber++)
        {

            // forward
            y_1 = InputSamples.row(RowNumber).t();
            x_2 = Weight_2 * y_1 + Bias_2;
            Sigmod(x_2, y_2);
            x_3 = Weight_3 * y_2 + Bias_3;
            Sigmod(x_3, y_3);

//            std::cout << "The acutral vector is" << SamplesOutput.row(RowNumber)
//                      << std::endl;
//            std::cout << "The nn output vector is " << y_3 << std::endl;

//            int inputint = 0;
//            std::cin >> inputint;


            // backforward
            // Output layer
            cv::Mat x_3_de;
            DeSigmod(x_3, x_3_de);
            cv::Mat Delta_3 = y_3 - SamplesOutput.row(RowNumber).t();

            DelWeigh_3 = Delta_3 * y_2.t();
            DelBias_3 = Delta_3;

            // hidden layer
            cv::Mat x_2_de;
            DeSigmod(x_2, x_2_de);
            cv::Mat Delta_2 = (Weight_3.t() * Delta_3).mul(x_2_de);

            DelWeigh_2 = Delta_2 * y_1.t();
            DelBias_2  = Delta_2;

            std::cout << "No." << RowNumber << " sample" << std::endl;


            // grandient check
            float delta_weight2_2 = 0.001;



            if ((RowNumber + 1) % NumberOfBatch == 0)
            {
                Weight_2 = Weight_2 - DelWeigh_2 * LearningRate / NumberOfBatch;
                Bias_2   = Bias_2   - DelBias_2  * LearningRate / NumberOfBatch;
                Weight_3 = Weight_3 - DelWeigh_3 * LearningRate / NumberOfBatch;
                Bias_3   = Bias_3   - DelBias_3  * LearningRate / NumberOfBatch;

                std::cout << "Updating the params." << std::endl;

                DelWeigh_2 = DelWeigh_2 * 0;
                DelBias_2 = DelBias_2 * 0;
                DelWeigh_3 = DelWeigh_3 * 0;
                DelBias_3 = DelBias_3 * 0;

            }

//            Weight_2 = Weight_2 - (DelWeigh_2 * LearningRate);
//            Bias_2   = Bias_2   - (DelBias_2  * LearningRate);
//            Weight_3 = Weight_3 - (DelWeigh_3 * LearningRate);
//            Bias_3   = Bias_3   - (DelBias_3  * LearningRate);


        }

        std::cout << "No." << NumberOfIte << "is ended" << std::endl;
        NumberOfIte--;
    }


    int NumberOfCorrect = 0;
    // predict
    for (int i = 0; i < TestSamples.rows; i++)
    {
        // forward
        y_1 = TestSamples.row(i).t();
        x_2 = Weight_2 * y_1 + Bias_2;
        Sigmod(x_2, y_2);
        x_3 = Weight_3 * y_2 + Bias_3;

//        x_2 = Weight_2 * y_1 + Bias_2;
//        Sigmod(x_2, y_2);
//        x_3 = Weight_3 * y_2 + Bias_3;
//        Sigmod(x_3, y_3);

        Sigmod(x_3, y_3);


        std::cout << "No. " << i << "testing samples" << std::endl;
        std::cout << "The output vector is " << y_3 << std::endl;
        std::cout << "The acutural vector is" << TestOutputs.row(i) << std::endl;
        cv::waitKey();
        cv::destroyAllWindows();

        cv::Mat NNOutput;
        DecodeOutputVector(y_3.t(), NNOutput, 10);

        cv::Mat DierOutput;
        DecodeOutputVector(TestOutputs.row(i), DierOutput, 10);


        float NNOut = NNOutput.at<uchar>(0);
        float DirOut = DierOutput.at<uchar>(0);

        if (NNOut == DirOut)
        {
            std::cout << "No." << i << "Sample is matched." << std::endl;
            NumberOfCorrect++;
        }


//        std::cout << "The output vector decode is" << NNOutput << std::endl;
//        std::cout << "The output nn decode is"     << DierOutput << std::endl;
//        std::cout << "The output of the neural network is " << NNOut << std::endl;
//        std::cout << "The actual output is " << DirOut << std::endl;
//        std::cout << std::endl;

//        cv::Mat img(28, 28, y_1.type(), y_1.data);
//        cv::namedWindow("test");
//        cv::imshow("test", img);
//        cv::waitKey();
//        cv::destroyAllWindows();

    }

    float Rate = float(NumberOfCorrect) / TestSamples.rows;
    std::cout << "The number of correct is " << NumberOfCorrect << std::endl;
    std::cout << "The total number of correct is " << TestSamples.rows << std::endl;
    std::cout << "The rate is " << Rate << std::endl;

}
