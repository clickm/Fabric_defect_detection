#ifndef DETECT_INDENT_FFT
#define DETECT_INDENT_FFT
#include "HalconCpp.h"
using namespace HalconCpp;

// Procedure declarations
// External procedures
// Chapter: Develop
// Short Description: Switch dev_update_pc, dev_update_var and dev_update_window to 'off'.
void dev_update_off ();
// Chapter: Graphics / Text
// Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen.
void disp_continue_message (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box);
// Chapter: Graphics / Text
// Short Description: This procedure writes a text message.
void disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
    HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS
void set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
    HTuple hv_Slant);


#endif // DETECT_INDENT_FFT

