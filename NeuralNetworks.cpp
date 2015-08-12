#include <opencv2/opencv.hpp>
#include <iostream>

#include "NeuralNetworksFunctions.h"

/**
 * @brief NeuralNetworksTraing Training the neural networks
 * @param NeuralNetworks   The neural network
 * @param InputMat         Floating-point matrix of input vectors, one vector
 *                         per row.
 * @param OutputMat        Floating-point matrix of the corresponding output
 *                         vectors, one vector per row.
 * @param MaxIte           The number of the iteration
 *
 *
 * @author sheng
 * @version 1.0.0
 * @date  2014-04-17
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 *
 */

void NeuralNetworksTraing(CvANN_MLP& NeuralNetworks, const cv::Mat& InputMat,
                          const cv::Mat& OutputMat, int MaxIte)
{
    // Network architecture
    std::vector<int> LayerSizes;
    LayerSizes.push_back(InputMat.cols);    // input layer
    LayerSizes.push_back(1000);             // hidden layer has 1000 neurons
    LayerSizes.push_back(OutputMat.cols);   // output layer


    // Activate function
    int ActivateFunc = CvANN_MLP::SIGMOID_SYM;
    double Alpha = 1;
    double Beta = 1;


    // create the network
    NeuralNetworks.create(cv::Mat(LayerSizes), ActivateFunc, Alpha, Beta);



    // Training Params
    CvANN_MLP_TrainParams TrainParams;
    TrainParams.train_method = CvANN_MLP_TrainParams::BACKPROP;
    TrainParams.bp_dw_scale = 0.0001;
    TrainParams.bp_moment_scale = 0;

    // iteration number
    CvTermCriteria TermCrlt;
    TermCrlt.type = CV_TERMCRIT_ITER | CV_TERMCRIT_EPS;
    TermCrlt.epsilon = 0.0001f;
    TermCrlt.max_iter = MaxIte;
    TrainParams.term_crit = TermCrlt;


    // Training the networks
    NeuralNetworks.train(InputMat, OutputMat, cv::Mat(), cv::Mat(), TrainParams);

}




/**
 * @brief NeuralNetworksPredict
 * @param NeuralNetworks
 * @param Input
 * @param Output
 */
void NeuralNetworksPredict(const CvANN_MLP& NeuralNetworks, const cv::Mat& Input,
                           cv::Mat& Output)
{
    // Neural network predict
    cv::Mat OutputVector;
    NeuralNetworks.predict(Input, OutputVector);

    // change the output vector
    DecodeOutputVector(OutputVector, Output, OutputVector.cols);


}
