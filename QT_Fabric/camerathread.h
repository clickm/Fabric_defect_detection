#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H
#include <QThread>
#include <QTimer>
#include <QTime>
#include <QApplication>
#include <CyDisplayEx.h>
#include <CyXMLDocument.h>
#include <CyConfig.h>
#include <CyGrabber.h>
#include <CyImageBuffer.h>
#include <CyDeviceFinder.h>
#include <CyPixelTypeFactory.h>
#include <CyPixelConverter.h>
#include <CyRGB32.h>
#include <iostream>
#include <sstream>
#include <string>

#define completed    1
#define uncompleted  0

//运行模式定义
#define ReadMode   0
#define CameraMode 1
#define StopMode   2

class cameraThread : public QThread
{
    Q_OBJECT
public:
    cameraThread();
    ~cameraThread();
    void run();
    void stop();
    int cameraInit(char * path);
    //bool AcquisitionState = uncompleted;
    enum AcquisitionState{
        Uncompleted = 0,
        Completed
    };
    enum DealState{
        Unfinished = 0,
        Finished
    };

    bool Dealcompleted = true;
    int Running_State = StopMode;
    DealState dealState;
    char *ConfigPath;
    char *ConfigPath2 = "D:/config/config0814.xml";
    int pid = 0;
signals:
    void stateChanged(cameraThread::AcquisitionState);
    void DealStateChanged();
protected:

private:
    mutable QMutex mutex;
    CyConfig lConfig;
    CyGrabber lGrabber;
    CY_UINT32   lWidth, lHeight, lPixelDepth;
    CY_UINT32   lImageSize;
    CyPixelTypeID lPixelTypeID;
    CyDisplayEx lDisplay;
    AcquisitionState curState;
    QTime time;

};




class ImageprocessThread:public QThread
{
    Q_OBJECT
public:
    ImageprocessThread();
    ~ImageprocessThread();
    void run();
    void stop();
protected:

private:

};
#endif // CAMERATHREAD_H
