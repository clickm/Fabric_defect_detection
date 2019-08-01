#include "HalconCpp.h"
#include "HDevThread.h"
#include "detect_indent_fft.h"
#include "defects_laws.h"
#include "mainwindow.h"
using namespace HalconCpp;

/*void defects_laws()
{

  //hv_Path = "C:/Users/Public/Documents/MVTec/HALCON-12.0/examples/images/Fabric/fabric1/Image_";
  //关闭更新
  dev_update_off();

  //直方图均衡化
  //equ_histo_image (srcImage, Image)
  //*获得图像大小
  GetImageSize(ho_Image, &hv_Width, &hv_Height);

  //打开窗口
  SetWindowAttr("background_color","black");
  OpenWindow(0,0,hv_Width,hv_Height,0,"visible","",&hv_WindowHandle);
  HDevWindowStack::Push(hv_WindowHandle);
  //*设置输出颜色字体
  if (HDevWindowStack::IsOpen())
    SetColor(HDevWindowStack::GetActive(),"red");
  //设置字体
  set_display_font(hv_WindowHandle, 16, "mono", "true", "false");

  //*********以下为瑕疵检测************
  for (hv_J=1; hv_J<=14; hv_J+=1)
  {
    //读取图像
    ReadImage(&ho_Image, hv_Path+(hv_J.TupleString("02")));
    //直方图均衡化
    //equ_histo_image (srcImage, Image)
    //图片放缩，缩短运行时间
    ZoomImageFactor(ho_Image, &ho_ImageZoomed, 0.5, 0.5, "constant");
    //显示缩放后的图像
    if (HDevWindowStack::IsOpen())
      DispObj(ho_ImageZoomed, HDevWindowStack::GetActive());
    //Laws纹理滤波提取，组合五幅为纹理图像
    //‘el’模板Laws纹理滤波卷积
    TextureLaws(ho_ImageZoomed, &ho_ImageEL, "el", 5, 5);
    //'le'模板Laws纹理滤波卷积
    TextureLaws(ho_ImageZoomed, &ho_ImageLE, "le", 5, 5);
    //'es'模板Laws纹理滤波卷积
    TextureLaws(ho_ImageZoomed, &ho_ImageES, "es", 1, 5);
    //'se'模板Laws纹理滤波卷积
    TextureLaws(ho_ImageZoomed, &ho_ImageSE, "se", 1, 5);
    //'ee'模板Laws纹理滤波卷积
    TextureLaws(ho_ImageZoomed, &ho_ImageEE, "ee", 2, 5);
    //组合五幅图像为5通道图像
    Compose5(ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE, ho_ImageEE, &ho_ImageLaws
        );
    //对图像进行光滑处理
    SmoothImage(ho_ImageLaws, &ho_IamgeTexture, "gauss", 5);
    //获得制定区域的图像
    ReduceDomain(ho_IamgeTexture, ho_Rectangle, &ho_ImageTextureReduced);
    //使用分类器对图像进行分类，获得同类的正确区域
    ClassifyImageClassGmm(ho_ImageTextureReduced, &ho_Correct, hv_GMMHandle, 0.001);
    //*原来的ROI区域减去同类正确的区域得到瑕疵区域
    Difference(ho_Rectangle, ho_Correct, &ho_Errors);
    //通过开闭运算去掉无关紧要的部分区域
    OpeningCircle(ho_Errors, &ho_ErrorsOpening, 3.5);
    ClosingCircle(ho_ErrorsOpening, &ho_ErrorsCloseing, 10.5);
    //连通区域
    Connection(ho_ErrorsCloseing, &ho_ErrorsConnected);
    //区域选择面积大于300的
    SelectShape(ho_ErrorsConnected, &ho_FinalErrors, "area", "and", 300, 1000000);
    //最后瑕疵区域计数
    CountObj(ho_FinalErrors, &hv_NumErrors);
    //设置颜色
    if (HDevWindowStack::IsOpen())
      SetColor(HDevWindowStack::GetActive(),"red");
    //设置区域填充方式
    if (HDevWindowStack::IsOpen())
      SetDraw(HDevWindowStack::GetActive(),"margin");
    //设置线宽
    if (HDevWindowStack::IsOpen())
      SetLineWidth(HDevWindowStack::GetActive(),3);
    //显示瑕疵区域
    if (HDevWindowStack::IsOpen())
      DispObj(ho_FinalErrors, HDevWindowStack::GetActive());
    //根据判断瑕疵部分是否大于零，判断图像是否ok
    if (0 != (hv_NumErrors>0))
    {
      //产品有瑕疵
      disp_message(hv_WindowHandle, "not OK", "window", 10, 10, "black", "true");
    }
    else
    {
      //产品无瑕疵
      disp_message(hv_WindowHandle, "OK", "window", 10, 10, "black", "true");
    }
    //小于14幅图像屏幕右下角：出现按F5继续
    if (0 != (hv_J<14))
    {
      disp_continue_message(hv_WindowHandle, "black", "true");
    }
    // stop(...); only in hdevelop
  }
  //清除分类器
  ClearClassGmm(hv_GMMHandle);
}*/



