// *****************************************************************************
//
// $Id: CyImageBuffer.h,v 1.15 2007/11/30 21:45:40 aviel Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyImageBuffer.h
//
// Description..: Image specific implement of CyBufferQueue (CyComLib)
//
// *****************************************************************************

#ifndef _CY_IMAGE_BUFFER_H_
#define _CY_IMAGE_BUFFER_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyBufferQueue.h"
#include "CyCamLib.h"
#include "CyCamLibCDef.h"

#include "CyPixelType.h"
#include "CyGrayscale8.h"
#include "CyRGBFilter.h"
#include "CyErrorInterface.h"
#include <stdio.h>
#include "CyImageBufferConstants.h"



// Class
/////////////////////////////////////////////////////////////////////////////

/* ==========================================================================
@since	2002-09-03
========================================================================== */
#ifdef __cplusplus
struct CyImageBufferInternal;
class CyImageBuffer : public CyBufferQueue
{
// Constants
public:
    CY_CAM_LIB_API static const unsigned long FLAG_BITMAP;

// Constructors / Destructor
public:

	CY_CAM_LIB_API CyImageBuffer( unsigned int         aSizeX = 1,
							      unsigned int         aSizeY = 1, 
                                  const CyPixelTypeID& aType  = CyGrayscale8::ID );

	CY_CAM_LIB_API virtual ~CyImageBuffer( void );

private:

	CyImageBuffer( const CyImageBuffer & );

// Operators
private:

	const CyImageBuffer &operator=( const CyImageBuffer & );

// Accessors
public:

    CY_CAM_LIB_API unsigned int GetSizeX( void )              const;
    CY_CAM_LIB_API unsigned int GetSizeY( void )              const;
    CY_CAM_LIB_API const CyPixelType&           
                                GetFormat( void)              const;

	CY_CAM_LIB_API CyResult     SetCapacity( unsigned int aX,
                                             unsigned int aY,
                                             const CyPixelTypeID& aType );

    // overrides of CyBufferQueue.  Do not use
    CY_CAM_LIB_API virtual CyResult SetCapacity( unsigned int aSize );


// Methods
public:

	// ===== I/O =====
    CY_CAM_LIB_API CyResult     Load( const char *aFilename,
                                      const CyPixelTypeID& aType,
                                      unsigned long aFlag );
	CY_CAM_LIB_API CyResult     Save( const char *aFilename,
								      const CyPixelTypeID& aType,
                                      unsigned long aFlags = 0 );

    // ===== Utility I/O functions =====

    // Saves a buffer of bytes as a raw binary file.
    CY_CAM_LIB_API static CyResult CY_CALLING_CONV
                                SaveRaw   ( const CyString&       aFileName,
                                            const unsigned char*  aBuffer,
                                            unsigned long         aBufferSize );

    // Loads a buffer from a raw binary file.
    // The actual pixel type, width and height are anyboby's guess
    CY_CAM_LIB_API static CyResult CY_CALLING_CONV
                                LoadRaw   ( const CyString& aFileName,
                                            unsigned char*  aBuffer,
                                            unsigned long*  aBufferSize );

    // Saves a buffer of pixels to a Windows Bitmap file.
    // If the image is a colour image, it is saved as a 32-bit bitmap
    // If the image is grayscale, it is saved as a 8-bit bitmap.
    CY_CAM_LIB_API static CyResult CY_CALLING_CONV
                                SaveBitmap( const CyString&       aFileName,
                                            const unsigned char*  aBuffer,
                                            unsigned long         aBufferSize,
                                            unsigned long         aWidth,
                                            unsigned long         aHeight,
                                            CyPixelTypeID         aPixelType,
                                            unsigned long         aConvertFlags = 0,
                                            const CyRGBFilter*    aFilter = 0 );


// Data
private:
    struct CyImageBufferInternal* mInternal;

#ifdef _MANAGED	//.Net wrapper need to access mInternal
	friend ref class NCyImageBuffer;
#endif //_MANAGED
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction
// Use CyBuffer_Destroy to destroy an image buffer
CY_CAM_LIB_C_API( CyImageBufferH ) CyImageBuffer_Init();

// Functions
CY_CAM_LIB_C_API( unsigned int ) CyImageBuffer_GetSizeX   ( CyImageBufferH aHandle );
CY_CAM_LIB_C_API( unsigned int ) CyImageBuffer_GetSizeY   ( CyImageBufferH aHandle );
CY_CAM_LIB_C_API( CyPixelTypeH ) CyImageBuffer_GetFormat  ( CyImageBufferH aHandle );
CY_CAM_LIB_C_API( CyResult )     CyImageBuffer_SetCapacity( CyImageBufferH aHandle,
                                                            unsigned int   aX,
                                                            unsigned int   aY,
                                                            CyPixelTypeID  aType );

CY_CAM_LIB_C_API( CyResult )     CyImageBuffer_Load       ( CyImageBufferH aHandle,
                                                            const char *   aFilename,
                                                            CyPixelTypeID  aType,
                                                            unsigned long  aFlags );
CY_CAM_LIB_C_API( CyResult )     CyImageBuffer_Save       ( CyImageBufferH aHandle,
                                                            const char *   aFilename,
                                                            CyPixelTypeID  aType,
                                                            unsigned long  aFlags );

CY_CAM_LIB_C_API( CyResult )     CyImageBuffer_SaveRaw   ( const char*           aFileName,
                                                           const unsigned char*  aBuffer,
                                                           unsigned long         aBufferSize );
CY_CAM_LIB_C_API( CyResult )     CyImageBuffer_LoadRaw   ( const char*           aFileName,
                                                           unsigned char*        aBuffer,
                                                           unsigned long*        aBufferSize );
CY_CAM_LIB_C_API( CyResult )     CyImageBuffer_SaveBitmap( const char*           aFileName,
                                                           const unsigned char*  aBuffer,
                                                           unsigned long         aBufferSize,
                                                           unsigned long         aWidth,
                                                           unsigned long         aHeight,
                                                           CyPixelTypeID         aPixelType,
                                                           unsigned long         aConvertFlags,
                                                           CyRGBFilterH          aFilter );

#endif // _CY_IMAGE_BUFFER_H_
