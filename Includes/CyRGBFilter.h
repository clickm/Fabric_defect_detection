// *****************************************************************************
//
// $Id: CyRGBFilter.h,v 1.17 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyRGBFilter.h
//
// Description..: Filter for RGB data
//
// *****************************************************************************

#ifndef __CY_RGB_FILTER_H__
#define __CY_RGB_FILTER_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyObject.h>
#include <CyAssert.h>

// ===== This Project =====
#include "CyImgLib.h"

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus

class CyPixelConverterImpl;

class CY_IMG_LIB_API CyRGBFilter : public CyObject
{
    // construction / destruction
    public:
                CyRGBFilter( unsigned long aBitSize );
        virtual ~CyRGBFilter();

        // returns the size in bits of each channel
        virtual unsigned long GetBitSize() const;

        // returns the number of entries in each channel table
        virtual unsigned long GetEntryCount() const;

        // Returns the entry for a channel entry
        CY_UINT8  GetRedValue8 ( unsigned long aIndex ) const;
        CY_UINT8  GetGreenValue8 ( unsigned long aIndex ) const;
        CY_UINT8  GetBlueValue8 ( unsigned long aIndex ) const;
        CY_UINT16 GetRedValue16( unsigned long aIndex ) const;
        CY_UINT16 GetGreenValue16( unsigned long aIndex ) const;
        CY_UINT16 GetBlueValue16( unsigned long aIndex ) const;

        // Changes the internal look-up tables based on a multiplier
        // for each channel (R, G or B )
        virtual CyResult SetMultipliers( double         aRedGain,
                                         double         aGreenGain,
                                         double         aBlueGain );
        virtual CyResult SetMultipliers( double         aRedGain,
                                         double         aGreenGain,
                                         double         aBlueGain,
                                         unsigned short aRedOffset,
                                         unsigned short aGreenOffset,
                                         unsigned short aBlueOffset);

        // Changes a single value of the look-up table
        virtual CyResult        SetRedValue    ( unsigned long aIndex, CY_UINT16 aValue );
        virtual CyResult        SetGreenValue  ( unsigned long aIndex, CY_UINT16 aValue );
        virtual CyResult        SetBlueValue   ( unsigned long aIndex, CY_UINT16 aValue );

private:
        void *mPTRGBFilter;
        
        // Used for internal management in the pixel converter
        friend class CyPixelConverterImpl;
};

#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyRGBFilter Handle
typedef void* CyRGBFilterH;

// Construction / Destruction
CY_IMG_LIB_C_API( CyRGBFilterH )   CyRGBFilter_Init( unsigned long aBitSize );
CY_IMG_LIB_C_API( void )           CyRGBFilter_Destroy( CyRGBFilterH aHandle );

// CyRGBFilter functions
CY_IMG_LIB_C_API( unsigned long )  CyRGBFilter_GetBitSize   ( CyRGBFilterH aHandle );
CY_IMG_LIB_C_API( unsigned long )  CyRGBFilter_GetEntryCount( CyRGBFilterH aHandle );

// Returns the 8-bit value or 16-bits value of an entry
// Note: these functions will not be as efficient as their C++ counterpart.
// The C++ methods are inlined and does not create a function call.
// The filter, when used INSIDE the wrapper functions WILL be as efficient as C++
CY_IMG_LIB_C_API( CY_UINT8 )  CyRGBFilter_GetRedValue8   ( CyRGBFilterH  aHandle,
                                                           unsigned long aIndex );
CY_IMG_LIB_C_API( CY_UINT8 )  CyRGBFilter_GetGreenValue8 ( CyRGBFilterH  aHandle,
                                                           unsigned long aIndex );
CY_IMG_LIB_C_API( CY_UINT8 )  CyRGBFilter_GetBlueValue8  ( CyRGBFilterH  aHandle,
                                                           unsigned long aIndex );
CY_IMG_LIB_C_API( CY_UINT16 ) CyRGBFilter_GetRedValue16  ( CyRGBFilterH  aHandle,
                                                           unsigned long aIndex );
CY_IMG_LIB_C_API( CY_UINT16 ) CyRGBFilter_GetGreenValue16( CyRGBFilterH  aHandle,
                                                           unsigned long aIndex );
CY_IMG_LIB_C_API( CY_UINT16 ) CyRGBFilter_GetBlueValue16 ( CyRGBFilterH  aHandle,
                                                           unsigned long aIndex );

// Set the values of the filter's entries
CY_IMG_LIB_C_API( CyResult ) CyRGBFilter_SetRedValue  ( CyRGBFilterH   aHandle,
                                                        unsigned long  aIndex,
                                                        CY_UINT16      aValue );
CY_IMG_LIB_C_API( CyResult ) CyRGBFilter_SetGreenValue( CyRGBFilterH   aHandle,
                                                        unsigned long  aIndex,
                                                        CY_UINT16      aValue );
CY_IMG_LIB_C_API( CyResult ) CyRGBFilter_SetBlueValue ( CyRGBFilterH   aHandle,
                                                        unsigned long  aIndex,
                                                        CY_UINT16      aValue );

// Utility functions to apply gains and offsets to the filter
CY_IMG_LIB_C_API( CyResult ) CyRGBFilter_SetMultipliers( CyRGBFilterH   aHandle,
                                                         double         aRedGain,
                                                         double         aGreenGain,
                                                         double         aBlueGain,
                                                         unsigned short aRedOffset,
                                                         unsigned short aGreenOffset,
                                                        unsigned short aBlueOffset );

#endif // __CY_RGB_FILTER_H__


