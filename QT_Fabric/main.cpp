#include "mainwindow.h"
#include "detect_indent_fft.h"
#include <QApplication>
#include <QDebug>
#define printf qDebug
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);
    printf("Number of processors: %d.\n", SystemInfo.dwNumberOfProcessors);
    //qt5 中的信号注册
    qRegisterMetaType<cameraThread::AcquisitionState>("cameraThread::AcquisitionState");
    MainWindow w;
    w.setWindowOpacity(1);
    w.show();

    return a.exec();
}
