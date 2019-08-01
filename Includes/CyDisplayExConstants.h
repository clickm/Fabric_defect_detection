// *****************************************************************************
//
//     Copyright (c) 2002-2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyDisplayExConstants.h
//
// Description..: Display window class
//
// *****************************************************************************

#ifndef __CY_DISPLAY_EX_CONSTANTS_H__
#define __CY_DISPLAY_EX_CONSTANTS_H__

enum CyDisplayExFlags
{

    CY_DISPLAY_EX_FLAG_WAIT                 = 0x00000002,
    CY_DISPLAY_EX_FLAG_KEEP_CONVERTER       = 0x00000004,
    CY_DISPLAY_EX_FLAG_INVERT_DEINTERLACING = 0x00000001,
    CY_DISPLAY_EX_FLAG_BAYER_GRBG           = 0x00000010,
    CY_DISPLAY_EX_FLAG_BAYER_GBRG           = 0x00000020,
    CY_DISPLAY_EX_FLAG_BAYER_RGGB           = 0x00000040,
    CY_DISPLAY_EX_FLAG_BAYER_BGGR           = 0x00000080,
    CY_DISPLAY_EX_FLAG_BAYER_INTERPOLATE    = 0x00000100,
    CY_DISPLAY_EX_FLAG_VSYNC                = 0x00000200,

};

#define CY_DISPLAY_EX_DEFAULT_POSITION 0xffff
#define CY_DISPLAY_EX_DEFAULT_SIZE     0xffff

enum CyDisplayExRGBModes
{

    CY_DISPLAY_EX_MODE_BGR = 0,
    CY_DISPLAY_EX_MODE_RGB = 1,

};

enum CyDisplayMemoryTypes
{
    CY_DISPLAY_MEMORY_VIDEO  = 0,
    CY_DISPLAY_MEMORY_SYSTEM = 1,
};

#endif // __CY_DISPLAY_EX_CONSTANTS_H__
