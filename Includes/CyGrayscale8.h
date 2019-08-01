// *****************************************************************************
//
// $Id: CyGrayscale8.h,v 1.8 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrayscale8.h
//
// Description..: Raw Grayscale on 8 bits
//
// *****************************************************************************

#ifndef __CY_GRAYSCALE8_H__
#define __CY_GRAYSCALE8_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE( CyGrayscale8,
                       CY_PT_GRAY8_1,
                       8,
                       1,
                       CY_IMG_LIB_API );

CY_DECLARE_PIXEL_TYPE( CyGrayscale8_DualQuadMultiplexed,
                       CY_PT_GRAY8_2,
                       8,
                       1,
                       CY_IMG_LIB_API );

#endif //__CY_GRAYSCALE8_H__
