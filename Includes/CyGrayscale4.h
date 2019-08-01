// *****************************************************************************
//
// $Id: CyGrayscale4.h,v 1.3 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrayscale4.h
//
// Description..: Raw Grayscale on 4 bits
//
// *****************************************************************************

#ifndef __CY_GRAYSCALE4_H__
#define __CY_GRAYSCALE4_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE( CyGrayscale4,
                       CY_PT_GRAY4_1,
                       4,
                       1,
                       CY_IMG_LIB_API );

#endif //__CY_GRAYSCALE4_H__
