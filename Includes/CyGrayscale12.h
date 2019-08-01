// *****************************************************************************
//
// $Id: CyGrayscale12.h,v 1.7 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrayscale12.h
//
// Description..: Raw Grayscale on 12 bits
//
// *****************************************************************************

#ifndef __CY_GRAYSCALE12_H__
#define __CY_GRAYSCALE12_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE( CyGrayscale12,
                       CY_PT_GRAY12_1,
                       12,
                       2,
                       CY_IMG_LIB_API );


CY_DECLARE_PIXEL_TYPE( CyGrayscale12_Packed_GEV,
                       CY_PT_GRAY12_2,
                       12,
                       2,
                       CY_IMG_LIB_API );


#endif //__CY_GRAYSCALE12_H__
