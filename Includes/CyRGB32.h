// *****************************************************************************
//
// $Id: CyRGB32.h,v 1.10 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyRGB32.h
//
// Description..: RGB on 32 bits
//
// *****************************************************************************

#ifndef __CY_RGB32_H__
#define __CY_RGB32_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB32,
                       CY_PT_RGB32_1,
                       32,
                       4,
                       CY_IMG_LIB_API,
                       false );

CY_DECLARE_PIXEL_TYPE_RGB( CyBGR32,
                       CY_PT_BGR32_1,
                       32,
                       4,
                       CY_IMG_LIB_API,
                       false );


CY_DECLARE_PIXEL_TYPE_RGB( CyRGB8_4,
                       CY_PT_RGB8_4_1,
                       8,
                       4,
                       CY_IMG_LIB_API,
                       false );

#endif //__CY_RGB32_H__

