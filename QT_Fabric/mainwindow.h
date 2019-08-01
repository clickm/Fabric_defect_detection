#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QProcess>
#include <QTime>
#include <QtConcurrent>
#include "HalconCpp.h"
#include "voice.h"
#include "camerathread.h"
using namespace HalconCpp;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Local iconic variables
    HObject  ho_Image, ho_Image1,ho_GaussFilter1, ho_GaussFilter2;
    HObject  ho_Filter, ho_ImageFFT, ho_ImageConvol, ho_ImageFiltered;
    HObject  ho_ImageResult, ho_RegionDynThresh, ho_ConnectedRegions;
    HObject  ho_SelectedRegions, ho_RegionUnion, ho_RegionClosing;
    HObject  ho_ConnectedRegions1, ho_SelectedRegions1, ho_ContCircle;

    // Local control variables
    HTuple  hv_Path, hv_Width, hv_Height,hv_Width1, hv_Height1, hv_WindowHandle,hv_WindowHandle1;
    HTuple  hv_Sigma1, hv_Sigma2, hv_NumImages, hv_d_Min, hv_d_Max;
    HTuple  hv_m_Max, hv_Index, hv_Min, hv_Max, hv_Range, hv_Area, hv_Threshold;
    HTuple  hv_Row, hv_Column, hv_Number, hv_ResultMessage;
    HTuple  hv_Sum, hv_Index1, hv_DEL, hv_Index2, hv_Distance_Row;
    HTuple  hv_Distance_Col, hv_Color, hv_ImageFiles;

    // Local iconic variables
    HObject  ho_Rectangle, ho_ImageZoomed;
    HObject  ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE;
    HObject  ho_ImageEE, ho_ImageLaws, ho_IamgeTexture, ho_ImageTextureReduced;
    HObject  ho_Correct, ho_Errors, ho_ErrorsOpening, ho_ErrorsCloseing;
    HObject  ho_ErrorsConnected, ho_FinalErrors;

    // Local control variables
    HTuple  hv_ReadPretrainedClassifier;
    HTuple  hv_SaveClassifier;
    HTuple  hv_HalconExamples, hv_GMMHandle, hv_Centers;
    HTuple  hv_Iter, hv_NumErrors;

    HTuple  imgcount = 0;
    int CameraNum = 1;


private slots:

    void on_pushButton_readImage_clicked();

    void on_pushButton_NextImage_clicked();

    void on_pushButton_MethodOK_clicked();

    void deal_process(const int &NumErrors);

    void on_pushButton_Path_clicked();

    void on_waychoose_clicked();

    void on_pushButton_LastImage_clicked();

    void GMM_training(void);

    HTuple defects_laws(HTuple hv_J);

    void on_pushButton_Number_clicked();

    void VoicePlay();

    void setLineEditValue();

    void on_pushButton_clicked();

    void slotdealImage();

    void on_pushButton_startorstop_clicked();

    void ShowInformation();

    void CameraShowChoose();

    void Box1_StateChanged();

    void Box2_StateChanged();

    void Box3_StateChanged();

    void Box4_StateChanged();

    void Box5_StateChanged();

private:
    void Filter(HTuple Width,HTuple Height);

    bool InitCreatwindow = true;
    bool DealState = false;
    QMediaPlayer* player;
    cameraThread *myCThread;
    cameraThread *myCThread2;
    cameraThread *myCThread3;
    Ui::MainWindow *ui;
    mutable QMutex mutex;
    QTime time;
    QProcess *p;
};

#endif // MAINWINDOW_H
