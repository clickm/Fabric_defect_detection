// *****************************************************************************
//
// $Id: CyBayerRGB8.h,v 1.11 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyBayerRGB8.h
//
// Description..: Bayer RGB on 8 bits
//
// *****************************************************************************

#ifndef __CY_BAYER_RGB8_H__
#define __CY_BAYER_RGB8_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE_RGB( CyBayerRGB8,
                       CY_PT_BAYER_RGB8_1,
                       8,
                       1,
                       CY_IMG_LIB_API,
                       true );

// for backward compatibility
CY_DECLARE_PIXEL_TYPE_RGB( CyBayerRGGB8,
                       0x00000013 | CY_PIXEL_FLAG_RGB_COLOUR,
                       8,
                       1,
                       CY_IMG_LIB_API,
                       true );


#endif //__CY_BAYER_RGB8_H__
