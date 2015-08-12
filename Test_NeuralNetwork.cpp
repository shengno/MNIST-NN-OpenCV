#include "NeuralNetworksFunctions.h"
#include "MNIST.h"
#include "timer.h"



void Test_NeuralNetwork()
{


    // prepare the training data
    std::string TrainingImageFileName =
            "G:/0.Database_For_Experiment/MNIST/train-images.idx3-ubyte";
    cv::Mat TrainingImages = ReadImages(TrainingImageFileName);
    cv::Mat FloatTrainingImages;
    ConvertToFloatMat(TrainingImages, FloatTrainingImages);

    // normalizing the training samples
    FloatTrainingImages = (255 - FloatTrainingImages) / 255;


    // prepare the training label
    std::string TrainingLabelFileName =
            "G:/0.Database_For_Experiment/MNIST/train-labels.idx1-ubyte";
    cv::Mat TrainingLabels = ReadLabels(TrainingLabelFileName);
    cv::Mat TrainingLabelVector;
    EncodeOutputVector(TrainingLabels, TrainingLabelVector, 10);


    // defining the network
    CvANN_MLP Networks;


    // The number of iteration
    int MaxIte = 2;


    // training
    Utility::Timer NetworksTimer;
    std::cout << "Training is started." << std::endl;
    NetworksTimer.Start();

    NeuralNetworksTraing(Networks, FloatTrainingImages, TrainingLabelVector,
                         MaxIte);

    NetworksTimer.Finish();
    std::cout << "Training is end." << std::endl;
    std::cout << "The training time is " << NetworksTimer.GetDuration()
              << std::endl;


    // save the networks
    Networks.save("NerualNetworks-ite=2-1000hidden.xml");



    // prapare the testing data
    std::string TestingImageFileName =
           "G:/0.Database_For_Experiment/MNIST/t10k-images.idx3-ubyte";
    cv::Mat TestingImages = ReadImages(TestingImageFileName);
    cv::Mat FloatTestingImages;
    ConvertToFloatMat(TestingImages, FloatTestingImages);

    // normalizing the testing samples
    FloatTestingImages = (255 - FloatTestingImages) / 255;


    // predicting
    cv::Mat NetworkOutput;
    NeuralNetworksPredict(Networks, FloatTestingImages, NetworkOutput);


    // the actural output of the testing samples
    std::string TestingLabelFileName =
           "G:/0.Database_For_Experiment/MNIST/t10k-labels.idx1-ubyte";
    cv::Mat TestingLabels = ReadLabels(TestingLabelFileName);



    // calculating the number of the correct testing samples
    int NumberOfCorrect = 0;

    for (cv::MatIterator_<uchar> NetworkOutputIte = NetworkOutput.begin<uchar>(),
         ActuralOutputIte = TestingLabels.begin<uchar>();
         NetworkOutputIte != NetworkOutput.end<uchar>();
         NetworkOutputIte++, ActuralOutputIte++)
    {
        if ((*NetworkOutputIte) == (*ActuralOutputIte))
        {
            NumberOfCorrect++;
        }
    }



    float Rate = 0;
    if (NetworkOutput.rows == 0)
    {
        std::cout << "The testing samples is zero." << std::endl;
    }
    else
    {
        Rate = (float)(NumberOfCorrect) / NetworkOutput.rows;
    }

    std::cout << "The number of correct is " << NumberOfCorrect << std::endl;
    std::cout << "The number of the testing is " << NetworkOutput.rows << std::endl;
    std::cout << "The correct of the network is " << Rate << std::endl;


}
