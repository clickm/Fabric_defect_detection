// *****************************************************************************
//
// $Id: CyBayerRGB14.h,v 1.3 2009/06/08 12:52:25 jwhitwill Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyBayerRGB14.h
//
// Description..: Bayer RGB on 14 bits
//
// *****************************************************************************

#ifndef __CY_BAYER_RGB14_H__
#define __CY_BAYER_RGB14_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE_RGB( CyBayerRGB14,
						  CY_PT_BAYER_RGB14_1,
                       14,
                       2,
                       CY_IMG_LIB_API,
                       true );

#endif //__CY_BAYER_RGB14_H__
