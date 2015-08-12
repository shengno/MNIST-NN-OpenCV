#include "MNIST.h"

int ConvertCharArrayToInt(unsigned char* array, int LengthOfArray)
{
    if (LengthOfArray < 0)
    {
        return -1;
    }

    int result = static_cast<signed int>(array[0]);

    for (int i = 1; i < LengthOfArray; i++)
    {
        result = (result << 8) + array[i];
    }

    return result;

}
