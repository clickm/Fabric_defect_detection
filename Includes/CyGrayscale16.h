// *****************************************************************************
//
// $Id: CyGrayscale16.h,v 1.6 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrayscale16.h
//
// Description..: Raw Grayscale on 16 bits
//
// *****************************************************************************

#ifndef __CY_GRAYSCALE16_H__
#define __CY_GRAYSCALE16_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"


// Class
/////////////////////////////////////////////////////////////////////////////

CY_DECLARE_PIXEL_TYPE( CyGrayscale16,
                       CY_PT_GRAY16_1,
                       16,
                       2,
                       CY_IMG_LIB_API );


#endif //__CY_GRAYSCALE16_H__
