// *****************************************************************************
//
// $Id: CyGrayscale10.h,v 1.8 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrayscale10.h
//
// Description..: Raw Grayscale on 10 bits
//
// *****************************************************************************

#ifndef __CY_GRAYSCALE10_H__
#define __CY_GRAYSCALE10_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE( CyGrayscale10,
                       CY_PT_GRAY10_1,
                       10,
                       2,
                       CY_IMG_LIB_API );

CY_DECLARE_PIXEL_TYPE( CyGrayscale10_DualQuadMultiplexed,
                       CY_PT_GRAY10_2,
                       10,
                       2,
                       CY_IMG_LIB_API );

CY_DECLARE_PIXEL_TYPE( CyGrayscale10_Packed_GEV,
                       CY_PT_GRAY10_3,
                       10,
                       2,
                       CY_IMG_LIB_API );

#endif //__CY_GRAYSCALE10_H__
