#include "MyNNFucntions.h"

void Sigmod(const cv::Mat& Input, cv::Mat& Output)
{
    cv::Mat ExpTmp;
    cv::exp(-Input, ExpTmp);
    Output = 1 / (ExpTmp  + 1);

}



void DeSigmod(const cv::Mat& Input, cv::Mat& Output)
{
    cv::Mat Tmp;
    Sigmod(Input, Tmp);
    Output = Tmp.mul(-Tmp + 1);
}
