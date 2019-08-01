// *****************************************************************************
//
// $Id: CyRGB48.h,v 1.9 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyRGB48.h
//
// Description..: RGB on 48 bits
//
// *****************************************************************************

#ifndef __CY_RGB48_H__
#define __CY_RGB48_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB48,
                       CY_PT_RGB48_1,
                       48,
                       6,
                       CY_IMG_LIB_API,
                       false );

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB48_10Bits,
                       CY_PT_RGB48_2,
                       10,
                       6,
                       CY_IMG_LIB_API,
                       false );

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB48_12Bits,
                       CY_PT_RGB48_3,
                       12,
                       6,
                       CY_IMG_LIB_API,
                       false );



#endif //__CY_RGB48_H__
