#include "detect_mura_defects_blur.h"

using namespace HalconCpp;
// Procedures
// External procedures
// Chapter: Filters / Lines
// Short Description: Calculates the parameters Sigma, Low, and High for lines_gauss from the maximum width and the contrast of the lines to be extracted.
void calculate_lines_gauss_parameters (HTuple hv_MaxLineWidth, HTuple hv_Contrast,
    HTuple *hv_Sigma, HTuple *hv_Low, HTuple *hv_High)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_ContrastHigh, hv_ContrastLow, hv_HalfWidth;
  HTuple  hv_Help;

  //Check control parameters
  if (0 != ((hv_MaxLineWidth.TupleLength())!=1))
  {
    throw HalconCpp::HException("Wrong number of values of control parameter: 1");
  }
  if (0 != ((hv_MaxLineWidth.TupleIsNumber()).TupleNot()))
  {
    throw HalconCpp::HException("Wrong type of control parameter: 1");
  }
  if (0 != (hv_MaxLineWidth<=0))
  {
    throw HalconCpp::HException("Wrong value of control parameter: 1");
  }
  if (0 != (HTuple((hv_Contrast.TupleLength())!=1).TupleAnd((hv_Contrast.TupleLength())!=2)))
  {
    throw HalconCpp::HException("Wrong number of values of control parameter: 2");
  }
  if (0 != (((hv_Contrast.TupleIsNumber()).TupleMin())==0))
  {
    throw HalconCpp::HException("Wrong type of control parameter: 2");
  }
  //Set and check ContrastHigh
  hv_ContrastHigh = ((const HTuple&)hv_Contrast)[0];
  if (0 != (hv_ContrastHigh<0))
  {
    throw HalconCpp::HException("Wrong value of control parameter: 2");
  }
  //Set or derive ContrastLow
  if (0 != ((hv_Contrast.TupleLength())==2))
  {
    hv_ContrastLow = ((const HTuple&)hv_Contrast)[1];
  }
  else
  {
    hv_ContrastLow = hv_ContrastHigh/3.0;
  }
  //Check ContrastLow
  if (0 != (hv_ContrastLow<0))
  {
    throw HalconCpp::HException("Wrong value of control parameter: 2");
  }
  if (0 != (hv_ContrastLow>hv_ContrastHigh))
  {
    throw HalconCpp::HException("Wrong value of control parameter: 2");
  }
  //
  //Calculate the parameters Sigma, Low, and High for lines_gauss
  if (0 != (hv_MaxLineWidth<(HTuple(3.0).TupleSqrt())))
  {
    //Note that LineWidthMax < sqrt(3.0) would result in a Sigma < 0.5,
    //which does not make any sense, because the corresponding smoothing
    //filter mask would be of size 1x1.
    //To avoid this, LineWidthMax is restricted to values greater or equal
    //to sqrt(3.0) and the contrast values are adapted to reflect the fact
    //that lines that are thinner than sqrt(3.0) pixels have a lower contrast
    //in the smoothed image (compared to lines that are sqrt(3.0) pixels wide).
    hv_ContrastLow = (hv_ContrastLow*hv_MaxLineWidth)/(HTuple(3.0).TupleSqrt());
    hv_ContrastHigh = (hv_ContrastHigh*hv_MaxLineWidth)/(HTuple(3.0).TupleSqrt());
    hv_MaxLineWidth = HTuple(3.0).TupleSqrt();
  }
  //Convert LineWidthMax and the given contrast values into the input parameters
  //Sigma, Low, and High required by lines_gauss
  hv_HalfWidth = hv_MaxLineWidth/2.0;
  (*hv_Sigma) = hv_HalfWidth/(HTuple(3.0).TupleSqrt());
  hv_Help = ((-2.0*hv_HalfWidth)/((HTuple(6.283185307178).TupleSqrt())*((*hv_Sigma).TuplePow(3.0))))*((-0.5*((hv_HalfWidth/(*hv_Sigma)).TuplePow(2.0))).TupleExp());
  (*hv_High) = (hv_ContrastHigh*hv_Help).TupleFabs();
  (*hv_Low) = (hv_ContrastLow*hv_Help).TupleFabs();
  return;
}

// Chapter: Develop
// Short Description: Open a new graphics window that preserves the aspect ratio of the given image size.
void dev_open_window_fit_size (HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
    HTuple hv_Height, HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_MinWidth, hv_MaxWidth, hv_MinHeight;
  HTuple  hv_MaxHeight, hv_ResizeFactor, hv_TempWidth, hv_TempHeight;
  HTuple  hv_WindowWidth, hv_WindowHeight;

  //This procedure open a new graphic window
  //such that it fits into the limits specified by WidthLimit
  //and HeightLimit, but also maintains the correct aspect ratio
  //given by Width and Height.
  //
  //If it is impossible to match the minimum and maximum extent requirements
  //at the same time (f.e. if the image is very long but narrow),
  //the maximum value gets a higher priority.
  //
  //Parse input tuple WidthLimit
  if (0 != (HTuple((hv_WidthLimit.TupleLength())==0).TupleOr(hv_WidthLimit<0)))
  {
    hv_MinWidth = 500;
    hv_MaxWidth = 800;
  }
  else if (0 != ((hv_WidthLimit.TupleLength())==1))
  {
    hv_MinWidth = 0;
    hv_MaxWidth = hv_WidthLimit;
  }
  else
  {
    hv_MinWidth = ((const HTuple&)hv_WidthLimit)[0];
    hv_MaxWidth = ((const HTuple&)hv_WidthLimit)[1];
  }
  //Parse input tuple HeightLimit
  if (0 != (HTuple((hv_HeightLimit.TupleLength())==0).TupleOr(hv_HeightLimit<0)))
  {
    hv_MinHeight = 400;
    hv_MaxHeight = 600;
  }
  else if (0 != ((hv_HeightLimit.TupleLength())==1))
  {
    hv_MinHeight = 0;
    hv_MaxHeight = hv_HeightLimit;
  }
  else
  {
    hv_MinHeight = ((const HTuple&)hv_HeightLimit)[0];
    hv_MaxHeight = ((const HTuple&)hv_HeightLimit)[1];
  }
  //
  //Test, if window size has to be changed.
  hv_ResizeFactor = 1;
  //First, expand window to the minimum extents (if necessary).
  if (0 != (HTuple(hv_MinWidth>hv_Width).TupleOr(hv_MinHeight>hv_Height)))
  {
    hv_ResizeFactor = (((hv_MinWidth.TupleReal())/hv_Width).TupleConcat((hv_MinHeight.TupleReal())/hv_Height)).TupleMax();
  }
  hv_TempWidth = hv_Width*hv_ResizeFactor;
  hv_TempHeight = hv_Height*hv_ResizeFactor;
  //Then, shrink window to maximum extents (if necessary).
  if (0 != (HTuple(hv_MaxWidth<hv_TempWidth).TupleOr(hv_MaxHeight<hv_TempHeight)))
  {
    hv_ResizeFactor = hv_ResizeFactor*((((hv_MaxWidth.TupleReal())/hv_TempWidth).TupleConcat((hv_MaxHeight.TupleReal())/hv_TempHeight)).TupleMin());
  }
  hv_WindowWidth = hv_Width*hv_ResizeFactor;
  hv_WindowHeight = hv_Height*hv_ResizeFactor;
  //Resize window
  SetWindowAttr("background_color","black");
  OpenWindow(hv_Row,hv_Column,hv_WindowWidth,hv_WindowHeight,0,"visible","",&(*hv_WindowHandle));
  HDevWindowStack::Push((*hv_WindowHandle));
  if (HDevWindowStack::IsOpen())
    SetPart(HDevWindowStack::GetActive(),0, 0, hv_Height-1, hv_Width-1);
  return;
}


