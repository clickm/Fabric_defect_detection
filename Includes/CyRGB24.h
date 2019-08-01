// *****************************************************************************
//
// $Id: CyRGB24.h,v 1.11 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyRGB24.h
//
// Description..: RGB on 24 bits
//
// *****************************************************************************

#ifndef __CY_RGB24_H__
#define __CY_RGB24_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB24,
                       CY_PT_RGB24_1,
                       24,
                       3,
                       CY_IMG_LIB_API,
                       false );

CY_DECLARE_PIXEL_TYPE_RGB( CyBGR24,
                       CY_PT_BGR24_1,
                       24,
                       3,
                       CY_IMG_LIB_API,
                       false );

CY_DECLARE_PIXEL_TYPE_RGB( CyRGB8_3,
                       CY_PT_RGB8_3_1,
                       8,
                       3,
                       CY_IMG_LIB_API,
                       false );

#endif //__CY_RGB24_H__
