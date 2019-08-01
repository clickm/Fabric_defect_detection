// *****************************************************************************
//
// $Id: CyPixelConverter.h,v 1.22 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyPixelConverter.h
//
// Description..: Pixel converter base class
//
// *****************************************************************************

#ifndef __CY_PIXEL_CONVERTER_H__
#define __CY_PIXEL_CONVERTER_H__

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyAssert.h>
#include <CyGate.h>

// ===== This Project =====
#include "CyImgLib.h"
#include "CyPixelType.h"
#include "CyRGBFilter.h"
#include "CyPixelConverterConstants.h"


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyPixelConverterContext;
class CyPixelConverter : public CyObject
{
    // types
    public:
        // Conversion flags
        static CY_IMG_LIB_API const unsigned long FLAG_INVERT_DEINTERLACER;
        static CY_IMG_LIB_API const unsigned long FLAG_BAYER_GRBG;
        static CY_IMG_LIB_API const unsigned long FLAG_BAYER_GBRG;
        static CY_IMG_LIB_API const unsigned long FLAG_BAYER_RGGB;
        static CY_IMG_LIB_API const unsigned long FLAG_BAYER_BGGR;
        static CY_IMG_LIB_API const unsigned long FLAG_BAYER_INTERPOLATE;

    // construction / destruction
    // NOTE: A converter can only be obtained via the CyPixelType class
    protected:
        CY_IMG_LIB_API  CyPixelConverter( const CyPixelTypeID& aSrc,
                                          const CyPixelTypeID& aDst,
                                          unsigned long        aSourceByteSize,
                                          unsigned long        aDestinationByteSize,
                                          unsigned long        aPipeliningSize = 1,
                                          unsigned long        aLinesPerConvert = 1);
    public:
        CY_IMG_LIB_API  virtual ~CyPixelConverter();


    // accessors
    public:
        CY_IMG_LIB_API virtual const CyPixelTypeID&
                        GetSourceType() const;
        CY_IMG_LIB_API virtual const CyPixelTypeID&
                        GetDestinationType() const;

        CY_IMG_LIB_API virtual unsigned long
                        GetSourceByteSize() const;
        CY_IMG_LIB_API virtual unsigned long
                        GetSourceByteSize( unsigned long aPixelCount ) const;
        CY_IMG_LIB_API virtual unsigned long
                        GetDestinationByteSize() const;
        CY_IMG_LIB_API virtual unsigned long
                        GetDestinationByteSize( unsigned long aPixelCount ) const;


    protected:
        // used by the area converter and can be used by derived classes
        CY_IMG_LIB_API virtual unsigned long GetPipeliningSize() const;
        CY_IMG_LIB_API virtual unsigned long GetLinesPerConvert() const;
                         

    // conversion methods
    public:
        // convert a single pixel
        CY_IMG_LIB_API  virtual CyResult 
                        Convert( const unsigned char * aInput,
                                 unsigned char *       aOutput ) const;

        // Converts a single line
        CY_IMG_LIB_API  virtual CyResult 
                        Convert( const unsigned char * aInput,
                                 unsigned char *       aOutput,
                                 unsigned long         aSize ) const;

        // Converts an area
        CY_IMG_LIB_API  virtual CyResult 
                        Convert( const unsigned char * aInput,
                                 unsigned long         aInputSizeX,
                                 unsigned long         aInputSizeY,
                                 unsigned char *       aOutput,
                                 unsigned long         aOutputSizeX,
                                 unsigned long         aOutputSizeY,
                                 unsigned long         aSizeX,
                                 unsigned long         aSizeY,
                                 unsigned long         aFlags = 0,
                                 unsigned long         aOutputExtraBytes = 0 ) const;

        // Converts an area, using a RGB filter
        CY_IMG_LIB_API  virtual CyResult 
                        Convert( const CyRGBFilter&    aFilter,
                                 const unsigned char * aInput,
                                 unsigned long         aInputSizeX,
                                 unsigned long         aInputSizeY,
                                 unsigned char *       aOutput,
                                 unsigned long         aOutputSizeX,
                                 unsigned long         aOutputSizeY,
                                 unsigned long         aSizeX,
                                 unsigned long         aSizeY,
                                 unsigned long         aFlags = 0,
                                 unsigned long         aOutputExtraBytes = 0 ) const;

    protected:
        CY_IMG_LIB_API CyPixelConverterContext* GetContext() const;

    private:

        // Special access for complex converter
        friend class CyComplexConverter;

        #ifdef _MANAGED        //Needed for .net wrapper
            friend ref class CyPixelConverterNet;
        #endif // _MANAGED
};


#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Note; The CyPixelConverter handle is defined in CyPixelType.h
//       A Pixel converter can only be obtained through the pixel
//       type or the pixel type factory


CY_IMG_LIB_C_API( CyPixelTypeID )
                           CyPixelConverter_GetSourceType     ( CyPixelConverterH aHandle );
CY_IMG_LIB_C_API( CyPixelTypeID )
                           CyPixelConverter_GetDestinationType( CyPixelConverterH aHandle );

CY_IMG_LIB_C_API( unsigned long )
                           CyPixelConverter_GetSourceByteSize     ( CyPixelConverterH aHandle,
                                                                    unsigned long     aPixelCount );
CY_IMG_LIB_C_API( unsigned long )
                           CyPixelConverter_GetDestinationByteSize( CyPixelConverterH aHandle,
                                                                    unsigned long     aPixelCount );

// convert a single pixel
CY_IMG_LIB_C_API( CyResult ) CyPixelConverter_ConvertPixel( CyPixelConverterH     aHandle,
                                                            const unsigned char * aInput,
                                                            unsigned char *       aOutput );
// Converts a single line
CY_IMG_LIB_C_API( CyResult ) CyPixelConverter_ConvertLine ( CyPixelConverterH     aHandle,
                                                            const unsigned char * aInput,
                                                            unsigned char *       aOutput,
                                                            unsigned long         aSize );

// Converts an area
CY_IMG_LIB_C_API( CyResult ) CyPixelConverter_ConvertArea       ( CyPixelConverterH     aHandle,
                                                                  const unsigned char * aInput,
                                                                  unsigned long         aInputSizeX,
                                                                  unsigned long         aInputSizeY,
                                                                  unsigned char *       aOutput,
                                                                  unsigned long         aOutputSizeX,
                                                                  unsigned long         aOutputSizeY,
                                                                  unsigned long         aSizeX,
                                                                  unsigned long         aSizeY,
                                                                  unsigned long         aFlags,
                                                                  unsigned long         aOutputExtraBytes );

CY_IMG_LIB_C_API( CyResult ) CyPixelConverter_ConvertAreaFilter ( CyPixelConverterH     aHandle,
                                                                  CyRGBFilterH          aFilter,
                                                                  const unsigned char * aInput,
                                                                  unsigned long         aInputSizeX,
                                                                  unsigned long         aInputSizeY,
                                                                  unsigned char *       aOutput,
                                                                  unsigned long         aOutputSizeX,
                                                                  unsigned long         aOutputSizeY,
                                                                  unsigned long         aSizeX,
                                                                  unsigned long         aSizeY,
                                                                  unsigned long         aFlags,
                                                                  unsigned long         aOutputExtraBytes );

#endif // __CY_PIXEL_CONVERTER_H__
