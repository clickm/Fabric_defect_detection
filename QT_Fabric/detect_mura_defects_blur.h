#ifndef DETECT_MURA_DEFECTS_BLUR
#define DETECT_MURA_DEFECTS_BLUR
#include "HalconCpp.h"
#include "HDevThread.h"

using namespace HalconCpp;

// Procedure declarations
// External procedures
// Chapter: Filters / Lines
// Short Description: Calculates the parameters Sigma, Low, and High for lines_gauss from the maximum width and the contrast of the lines to be extracted.
void calculate_lines_gauss_parameters (HTuple hv_MaxLineWidth, HTuple hv_Contrast,
    HTuple *hv_Sigma, HTuple *hv_Low, HTuple *hv_High);
// Chapter: Develop
// Short Description: Open a new graphics window that preserves the aspect ratio of the given image size.
void dev_open_window_fit_size (HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
    HTuple hv_Height, HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle);


#endif // DETECT_MURA_DEFECTS_BLUR

