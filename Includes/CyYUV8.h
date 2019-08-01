// *****************************************************************************
//
// $Id: CyYUV8.h,v 1.10 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyYUV8.h
//
// Description..: YUV on 8 bits
//
// *****************************************************************************

#ifndef __CY_YUV8_H__
#define __CY_YUV8_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE( CyYUV8,
                       CY_PT_YUV8_1,
                       16,
                       2,
                       CY_IMG_LIB_API );


CY_DECLARE_PIXEL_TYPE( CyYUV8_444,
                       CY_PT_YUV8_444_1,
                       24,
                       3,
                       CY_IMG_LIB_API );

CY_DECLARE_PIXEL_TYPE( CyYCrCb,
                       CY_PT_YCRCB_1,
                       24,
                       3,
                       CY_IMG_LIB_API );

CY_DECLARE_PIXEL_TYPE( CyYUV8_411,
                       CY_PT_YUV8_411_1,
                       12,
                       2,
                       CY_IMG_LIB_API );

#ifdef __cplusplus
typedef CyYUV8 CyYUV8_422;
typedef CyYUV8_444 CyYCbCr;
#endif // __cplusplus

#endif //__CY_YUV8_H__

