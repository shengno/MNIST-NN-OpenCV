/**
 * @file ReadData.cpp The file contains the functions used to read image data
 *                    and label data from the origin mnist file
 * @author sheng
 * @version 1.0.0
 * @date  2014-04-09
 *
 * @function
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-09      1.0.0      build the module
 */

#include <MNIST.h>


/**
 * @brief IsImageDataFile  Check the input MagicNumber is equal to
 *                         MAGICNUMBEROFIMAGE
 * @param MagicNumber      The array of the magicnumber to be checked
 * @param LengthOfArray    The length of the array
 * @return true, if the magcinumber is mathed;
 *         false, otherwise.
 *
 * @author sheng
 * @version 1.0.0
 * @date  2014-04-08
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 */
bool IsImageDataFile(unsigned char* MagicNumber, int LengthOfArray)
{
    int MagicNumberOfImage = ConvertCharArrayToInt(MagicNumber, LengthOfArray);
    if (MagicNumberOfImage == MAGICNUMBEROFIMAGE)
    {
        return true;
    }

    return false;
}




/**
 * @brief IsImageDataFile  Check the input MagicNumber is equal to
 *                         MAGICNUMBEROFLABEL
 * @param MagicNumber      The array of the magicnumber to be checked
 * @param LengthOfArray    The length of the array
 * @return true, if the magcinumber is mathed;
 *         false, otherwise.
 *
 * @author sheng
 * @version 1.0.0
 * @date  2014-04-08
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 */
bool IsLabelDataFile(unsigned char *MagicNumber, int LengthOfArray)
{
    int MagicNumberOfLabel = ConvertCharArrayToInt(MagicNumber, LengthOfArray);
    if (MagicNumberOfLabel == MAGICNUMBEROFLABEL)
    {
        return true;
    }

    return false;
}




/**
 * @brief ReadData  Read the data in a opened file
 * @param DataFile  The file which the data is read from.
 * @param NumberOfData  The number of the data
 * @param DataSizeInBytes  The size fo the every data
 * @return The Mat which rows is a data,
 *         Return a empty Mat if the file is not opened or the some flag was
 *                 seted when reading the  data.
 *
 * @author sheng
 * @version 1.1.0
 * @date  2014-04-17
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 *               sheng      2014-04-17      1.1.0       after reading the data,close the file.
 */

cv::Mat ReadData(std::fstream& DataFile, int NumberOfData, int DataSizeInBytes)
{
    cv::Mat DataMat;


    // read the data if the file is opened.
    if (DataFile.is_open())
    {


        int AllDataSizeInBytes = DataSizeInBytes * NumberOfData;
        unsigned char* TmpData = new unsigned char[AllDataSizeInBytes];
        DataFile.read((char *)TmpData, AllDataSizeInBytes);

        //        // If the state is good, convert the array to a mat.
        //        if (!DataFile.fail())
        //        {
        //            DataMat = cv::Mat(NumberOfData, DataSizeInBytes, CV_8UC1,
        //                              TmpData).clone();
        //        }

        DataMat = cv::Mat(NumberOfData, DataSizeInBytes, CV_8UC1,
                          TmpData).clone();
        delete [] TmpData;
        DataFile.close();

    }

    return DataMat;
}




/**
 * @brief ReadImageData  Read the Image data from the MNIST file.
 * @param ImageDataFile  The file which contains the Images.
 * @param NumberOfImages The number of the images.
 * @return The mat contains the image and each row of the mat is a image.
 *         Return empty mat is the file is closed or the data is not matching
 *                the number.
 *
 * @author sheng
 * @version 1.0.0
 * @date  2014-04-08
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 */
cv::Mat ReadImageData(std::fstream& ImageDataFile, int NumberOfImages)
{
    int ImageSizeInBytes = 28 * 28;

    return ReadData(ImageDataFile, NumberOfImages, ImageSizeInBytes);
}



/**
 * @brief ReadLabelData Read the label data from the MNIST file.
 * @param LabelDataFile The file contained the labels.
 * @param NumberOfLabel The number of the labels.
 * @return The mat contains the labels and each row of the mat is a label.
 *         Return empty mat is the file is closed or the data is not matching
 *                the number.
 *
 * @author sheng
 * @version 1.0.0
 * @date  2014-04-08
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 */
cv::Mat ReadLabelData(std::fstream& LabelDataFile, int NumberOfLabel)
{
    int LabelSizeInBytes = 1;

    return ReadData(LabelDataFile, NumberOfLabel, LabelSizeInBytes);
}




/**
 * @brief ReadImages Read the Training images.
 * @param FileName  The name of the file.
 * @return The mat contains the image and each row of the mat is a image.
 *         Return empty mat is the file is closed or the data is not matched.
 *
 * @author sheng
 * @version 1.1.0
 * @date  2014-04-17
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 *               sheng      2014-04-17      1.1.0       change the open mode
 */
cv::Mat ReadImages(std::string& FileName)
{
    std::fstream File(FileName.c_str(), std::ios_base::in | std::ios_base::binary);

    if (!File.is_open())
    {
        return cv::Mat();
    }

    MNISTImageFileHeader FileHeader;
    File.read((char *)(&FileHeader), sizeof(FileHeader));

    if (!IsImageDataFile(FileHeader.MagicNumber, 4))
    {
        return cv::Mat();
    }

    int NumberOfImage = ConvertCharArrayToInt(FileHeader.NumberOfImages, 4);

    return ReadImageData(File, NumberOfImage);
}




/**
 * @brief ReadLabels  Read the label from the MNIST file.
 * @param FileName  The name of the file.
 * @return The mat contains the image and each row of the mat is a image.
 *         Return empty mat is the file is closed or the data is not matched.
 *
 * @author sheng
 * @version 1.1.0
 * @date  2014-04-17
 *
 * @histroy     <author>      <date>      <version>      <description>
 *               sheng      2014-04-08      1.0.0      build the function
 *               sheng      2014-04-17      1.1.0      change the open mode
 */
cv::Mat ReadLabels(std::string& FileName)
{
    std::fstream File(FileName.c_str(), std::ios_base::in | std::ios_base::binary);

    if (!File.is_open())
    {
        return cv::Mat();
    }

    MNISTLabelFileHeader FileHeader;
    File.read((char *)(&FileHeader), sizeof(FileHeader));

    if (!IsLabelDataFile(FileHeader.MagicNumber, 4))
    {
        return cv::Mat();
    }

    int NumberOfImage = ConvertCharArrayToInt(FileHeader.NumberOfLabels, 4);

    return ReadLabelData(File, NumberOfImage);
}



