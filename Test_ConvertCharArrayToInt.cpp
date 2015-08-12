#include "MNIST.h"

void Test_ConvertCharArrayToInt()
{
    std::fstream file;
    file.open("E:/Z_PKU_sz/8.Database/MNIST/train-images.idx3-ubyte", std::ios_base::in);
    if (file)
    {
        MNISTImageFileHeader FileHeader;
        file.read((char *)(&FileHeader), sizeof(FileHeader));
        int MagicNumber = ConvertCharArrayToInt(FileHeader.MagicNumber, 4);
        std::cout << "The magic number of the MNIST is " << MagicNumber
                  << std::endl;
    }

}
