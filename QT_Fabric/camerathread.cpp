#include "camerathread.h"
#include <qdebug.h>
using namespace std;

cameraThread::cameraThread()
{

}

cameraThread::~cameraThread()
{

}
int cameraThread::cameraInit(char * path)
{
    // Step 1:  Read the configuration file already saved in default folder
    //

    CyXMLDocument lDocument(path);
    if (lDocument.LoadDocument() != CY_RESULT_OK)
    {
        return 1;
    }

    //
    // Step 2: Create a configuration object from the CyXMLDocument object.
    //
    if (lConfig.LoadFromXML(lDocument) != CY_RESULT_OK)
    {
        return 1;
    }

    //
    // Step 3: We are using the first configuration in the CyConfig object.
    //         It's good practice to use one configuration per CyConfig object.
    //

    lConfig.GoFirst();
    //
    // Step 4: Create and connect a CyGrabber object to the IP Engine.
    //
    if (lGrabber.Connect(lConfig) != CY_RESULT_OK)
    {
        return 1;
    }
    // **Step 5**: Create a CyCameraInterface object on top of the grabber.
    // **Note**:  This step was deprecated in version 3.0.0 and above
    // as CyCamera related classes and parameters were removed

    // **Step 5.1**: Retrieve the camera model from the CyConfig object (deprecated)

    // **Step 5.2**: Search for the camera model in the camera registry (deprecated)

    // **Step 5.3**: Ask the registry to create the CyCameraInterface object (deprecated).
    //

    //
    // Step 6: Load the grabber parameters from the CyXMLDocument object.
    //

    if (lGrabber.LoadFromXML(lDocument) != CY_RESULT_OK)
    {
        return 1;
    }

    //
    // Step 7: Apply the the grabber parameters to the IP engine grabber
    //

    if (lGrabber.SaveConfig() != CY_RESULT_OK)
    {
        return 1;
    }
    //
    // Step 8: Create a buffer for grabbing images.
    //

    // Step 8.1: Retrieve the buffer size
    lGrabber.GetParameter(CY_GRABBER_PARAM_SIZE_X, lWidth);
    lGrabber.GetParameter(CY_GRABBER_PARAM_SIZE_Y, lHeight);
    lGrabber.GetParameter(CY_GRABBER_PARAM_PIXEL_DEPTH, lPixelDepth);
    lImageSize = lWidth * lHeight * ((lPixelDepth + 7) / 8);

    // Step 8.2: Retrieve the buffer's pixel type
    lGrabber.GetEffectivePixelType(lPixelTypeID);

    // Step 8.3: Create the buffer object.

    //CyUserBuffer lBuffer(new unsigned char[lImageSize], lImageSize);
//    CyDisplayEx lDisplay;
//    lDisplay.Open(
//        NULL,
//        CyDisplayEx::DEFAULT_POSITION,
//        CyDisplayEx::DEFAULT_POSITION,
//        (unsigned short)lWidth,
//        (unsigned short)lHeight);
    return 0;
}



void cameraThread::run()
{

#if 0
    //测试线程是否可以正常运行
    while(1)
    {
        qDebug()<<1<<2<<3<<1<<3<<2<<1<<1;
        Sleep(50);
        curState = Uncompleted;
        stateChanged(curState);
    }


#else
    QMutexLocker locker(&mutex);
    if(cameraInit(ConfigPath) == 1)//初始化失败
    {
        return;
    }

    CyUserBuffer lBuffer(new unsigned char[lImageSize], lImageSize);
    while (1)
    {
        if (lGrabber.Grab(CyChannel(0), // First channel
                          lBuffer,
                          0) != CY_RESULT_OK)
        {
            printf("Application could not grab an image\n");
            return ;
        }
        else if(Running_State == CameraMode)
        {

            //time.start();
            //saves raw and bmp image under application folder
            //CyImageBuffer::SaveRaw(CyString("myrawimage.raw"), lBuffer.GetBuffer(), lBuffer.GetBufferSize());

            //                string name;
            //                ostringstream stream;
            //                stream  << "mybitmap" << "01" << ".bmp";
            //                name = stream.str();
            if(pid == 1)
            {
                 CyImageBuffer::SaveBitmap(CyString("mybitmap01.bmp"), lBuffer.GetBuffer(), lBuffer.GetBufferSize(), lWidth, lHeight, lPixelTypeID);
            }
            else if(pid == 2)
            {
                 CyImageBuffer::SaveBitmap(CyString("mybitmap02.bmp"), lBuffer.GetBuffer(), lBuffer.GetBufferSize(), lWidth, lHeight, lPixelTypeID);
            }
            else if(pid == 3)
            {
                 CyImageBuffer::SaveBitmap(CyString("mybitmap03.bmp"), lBuffer.GetBuffer(), lBuffer.GetBufferSize(), lWidth, lHeight, lPixelTypeID);
            }
            curState = Completed;
            stateChanged(curState);
            Dealcompleted = false;
            while(Dealcompleted != true);
            // qDebug()<<time.elapsed()<<"ms";

        }
    }
#endif
}



