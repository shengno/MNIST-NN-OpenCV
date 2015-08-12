QT       = core
# QT += network
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += main.cpp \
    ConvertCharArrayToInt.cpp \
    Test_ConvertCharArrayToInt.cpp \
    Test_Readdata.cpp \
    ReadMNISTData.cpp \
    NeuralNetworks.cpp \
    ConvertToFloatMat.cpp \
    EncodeOutputVector.cpp \
    Test_NeuralNetwork.cpp \
    timer.cpp \
    DecodeOutputVector.cpp \
    Test_Decode.cpp \
    MyNN.cpp \
    SigmodFunction.cpp \
    TestRND.cpp \
    Test_MyNN.cpp \
    Test_sigmod.cpp


INCLUDEPATH += D:/OpenCV2.4.9/include

LIBS += D:/OpenCV2.4.9/lib/libopencv_calib3d249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_contrib249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_core249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_features2d249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_flann249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_gpu249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_highgui249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_imgproc249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_legacy249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_ml249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_nonfree249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_objdetect249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_ocl249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_photo249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_stitching249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_superres249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_ts249.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_video249.dll.a
LIBS += D:/OpenCV2.4.9/lib/libopencv_videostab249.dll.a

HEADERS += \
    MNIST.h \
    NeuralNetworksFunctions.h \
    timer.h \
    MyNNFucntions.h

