#include "MyNNFucntions.h"

void Test_Sigmod()
{
    cv::Mat tmp = (cv::Mat_<float>(2,2) << 0, 1, -1, 20);
    cv::Mat sig;
    Sigmod(tmp, sig);
    std::cout << "sigmod is " << sig << std::endl;

    cv::Mat DeSig;
    DeSigmod(tmp, DeSig);
    std::cout << "Desigmod is " << DeSig << std::endl;
}
