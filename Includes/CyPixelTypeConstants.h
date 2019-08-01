// *****************************************************************************
// 
// CyPixelTypeConstants.h
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyPixelType.h
//
// Description..: Pixel type base class
//
// *****************************************************************************

#ifndef __CY_PIXEL_TYPE_CONSTANTS_H__
#define __CY_PIXEL_TYPE_CONSTANTS_H__

// Flags
/////////////////////////////////////////////////////////////////////////////

//
// Flag format (64-bits)
//

#define CY_PIXEL_FLAG_IDENTIFIER        0x000000000000ffff

//
// Colour spaces
//

#define CY_PIXEL_FLAG_GRAYSCALE         0x0000000000010000
#define CY_PIXEL_FLAG_RGB_COLOUR        0x0000000000020000
#define CY_PIXEL_FLAG_YUV_COLOUR        0x0000000000040000

#define CY_PIXEL_FLAG_COLOUR_SPACE_MASK 0x0000000000070000

//
// Pixel packing and organization
//

#define CY_PIXEL_FLAG_NORMALIZED        0x0000000000100000
#define CY_PIXEL_FLAG_INTERLACED        0x0000000000200000
#define CY_PIXEL_FLAG_PACKED            0x0000000000400000
#define CY_PIXEL_FLAG_PLANAR            0x0000000000800000

//
// Pixel output format
//

#define CY_PIXEL_FLAG_DUAL_L_R          0x0000000001000000
#define CY_PIXEL_FLAG_DUAL_L_RINV       0x0000000002000000
#define CY_PIXEL_FLAG_DUAL_LINV_R       0x0000000004000000
#define CY_PIXEL_FLAG_DUAL_LINV_RINV    0x0000000008000000
#define CY_PIXEL_FLAG_DUAL_LINES        0x0000000010000000

#define CY_PIXEL_FLAG_OUTPUT_MASK       0x000000001f000000


//
// Pixel Type identifiers
//

enum {
  CY_PT_GRAY4_1        = 0x0000000000010400,

  CY_PT_GRAY8_1        = 0x0000000000010001,
  CY_PT_GRAY8_2        = 0x0000000000010006,

  CY_PT_GRAY10_1       = 0x0000000000010002,
  CY_PT_GRAY10_2       = 0x0000000000010007,
  CY_PT_GRAY10_3       = 0x0000000000010008,

  CY_PT_GRAY12_1       = 0x0000000000010003,
  CY_PT_GRAY12_2       = 0x0000000000010009,

  CY_PT_GRAY14_1       = 0x0000000000010004,

  CY_PT_GRAY16_1       = 0x0000000000010005,

  CY_PT_BAYER_RGB8_1   = 0x0000000000020010,
  CY_PT_BAYER_RGB10_1  = 0x0000000000020011,
  CY_PT_BAYER_RGB12_1  = 0x0000000000020012,
  CY_PT_BAYER_RGB14_1  = 0x0000000000020016,

  CY_PT_RGB16_1        = 0x0000000000020001,
  CY_PT_RGB24_1        = 0x0000000000020002,
  CY_PT_BGR24_1        = 0x0000000000020006,
  CY_PT_RGB8_3_1       = 0x000000000002000a,
  CY_PT_RGB32_1        = 0x0000000000020003,
  CY_PT_BGR32_1        = 0x0000000000020007,
  CY_PT_RGB8_4_1       = 0x000000000002000b,

  CY_PT_RGB48_1        = 0x0000000000020004,
  CY_PT_RGB48_2        = 0x0000000000020008,
  CY_PT_RGB48_3        = 0x000000000002000c,
  
  CY_PT_RGB64_1        = 0x0000000000020005,
  CY_PT_RGB64_2        = 0x0000000000020009,
  CY_PT_RGB64_3        = 0x000000000002000d,

  CY_PT_YUV8_1         = 0x0000000000040001,
  CY_PT_YUV8_444_1     = 0x0000000000040003,
  CY_PT_YCRCB_1        = 0x0000000000040005,
  CY_PT_YUV8_411_1     = 0x0000000000040006,
  CY_PT_YUV10_1        = 0x0000000000040002,
};

#endif // __CY_PIXEL_TYPE_CONSTANTS_H__


