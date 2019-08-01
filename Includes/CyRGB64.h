// *****************************************************************************
//
// $Id: CyRGB64.h,v 1.9 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyRGB64.h
//
// Description..: RGB on 64 bits
//
// *****************************************************************************

#ifndef __CY_RGB64_H__
#define __CY_RGB64_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB64,
                       CY_PT_RGB64_1,
                       64,
                       8,
                       CY_IMG_LIB_API,
                       false );

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB64_10Bits,
                       CY_PT_RGB64_2,
                       10,
                       8,
                       CY_IMG_LIB_API,
                       false );

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB64_12Bits,
                       CY_PT_RGB64_3,
                       12,
                       8,
                       CY_IMG_LIB_API,
                       false );



#endif //__CY_RGB64_H__
