// *****************************************************************************
//
// $Id: CyPixelTypeFactory.h,v 1.26 2009/05/29 14:53:57 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyPixelTypeFactory.h
//
// Description..: Pixel type base class
//
// *****************************************************************************

#ifndef __CY_PIXEL_TYPE_FACTORY_H__
#define __CY_PIXEL_TYPE_FACTORY_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

#include "CyImgLib.h"
#include "CyPixelType.h"
#include "CyPixelConverter.h"


// class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyPixelTypeFactoryInternal;
class CyPixelTypeFactory
{
public:

    // Registers a new pixel type for CreatePixelType
    CY_IMG_LIB_API static CyResult CY_CALLING_CONV
                           RegisterPixelType( const CyPixelTypeID& aID, 
                                              const CyPixelType*   aType,
                                              const char*          aName = 0 );

    // Create a pixel type based on ID
    CY_IMG_LIB_API static CyPixelType* CY_CALLING_CONV
                           CreatePixelType( const CyPixelTypeID& aID );

    // Returns a constant reference to the factory's pixel type
    CY_IMG_LIB_API static const CyPixelType& CY_CALLING_CONV
                           GetPixelType( const CyPixelTypeID& aID );

    // Indicates if a pixel type exists
    CY_IMG_LIB_API static bool CY_CALLING_CONV
                           HasPixelType( const CyPixelTypeID& aID );

    // Return the name of a pixel type
    CY_IMG_LIB_API static const char* CY_CALLING_CONV
                           GetPixelTypeName( const CyPixelTypeID& aID );

    // Create a pixel type based on wanted characteristics
    //
    //  aDepth: the number of bits per pixel
    //
    //  aColour:
    //      CyPixelType::GRAYSCALE
    //      CyPixelType::RGB_COLOUR
    //      CyPixelType::YUV_COLOUR
    //
    //  aPacked, aNormalized, aInterlaced
    //
    //  aOutput:
    //      0
    //      CyPixelType::DUAL_L_R      
    //      CyPixelType::DUAL_L_RINV   
    //      CyPixelType::DUAL_LINV_R   
    //      CyPixelType::DUAL_LINV_RINV
    //      CyPixelType::DUAL_LINES
    //
    //  aIndex: If there is more than one, specify the index
    //
    CY_IMG_LIB_API static unsigned long CY_CALLING_CONV
                           CountPixelTypes( unsigned long aDepth,
                                            CyPixelTypeID aColour,
                                            bool          aNormalized,
                                            bool          aPacked,
                                            bool          aInterlaced,
                                            bool          aPlanar,
                                            CyPixelTypeID aOutput,
                                            bool          aBayerPattern );
    CY_IMG_LIB_API static CyPixelType* CY_CALLING_CONV
                           CreatePixelType( unsigned long aDepth,
                                            CyPixelTypeID aColour,
                                            bool          aNormalized,
                                            bool          aPacked,
                                            bool          aInterlaced,
                                            bool          aPlanar,
                                            CyPixelTypeID aOutput,
                                            bool          aBayerPattern,
                                            unsigned long aIndex = 0 );

    // Register a new pixel converter
    CY_IMG_LIB_API static CyResult CY_CALLING_CONV
                           RegisterPixelConverter( const CyPixelTypeID&    aSrcID,
                                                   const CyPixelTypeID&    aDstID,
                                                   const CyPixelConverter* aConverter );
    CY_IMG_LIB_API static CyResult CY_CALLING_CONV
                           RegisterPixelConverter( const CyPixelConverter& aConverter );

    CY_IMG_LIB_API static CyResult CY_CALLING_CONV
                           ReplacePixelConverter( const CyPixelConverter&  aConverter,
                                                  const CyPixelConverter** aPrevious );

    // Copies the converters for a pixel type for another pixel type.
    CY_IMG_LIB_API static CyResult CY_CALLING_CONV
                           ClonePixelConverters( const CyPixelTypeID& aSrcID,
                                                 const CyPixelTypeID& aDstID );

    // Indicates if a converter exists between 2 pixel types
    CY_IMG_LIB_API static bool CY_CALLING_CONV
                           HasConverter( const CyPixelTypeID& aSrcID,
                                         const CyPixelTypeID& aDstID );

    // Returns a converter exists between 2 pixel types
    CY_IMG_LIB_API static const CyPixelConverter& CY_CALLING_CONV
                           GetConverter( const CyPixelTypeID& aSrcID,
                                         const CyPixelTypeID& aDstID );

    // Enumerates converters from/to a pixel type
    CY_IMG_LIB_API static bool CY_CALLING_CONV
                           EnumConverters( unsigned long        aIndex,
                                           CyPixelTypeID&       aFrom,
                                           CyPixelTypeID&       aTo );
    CY_IMG_LIB_API static bool CY_CALLING_CONV
                           EnumConverterFrom( unsigned long        aIndex,
                                              const CyPixelTypeID& aRef,
                                              CyPixelTypeID&       aTo );
    CY_IMG_LIB_API static bool CY_CALLING_CONV
                           EnumConverterTo  ( unsigned long        aIndex,
                                              const CyPixelTypeID& aRef,
                                              CyPixelTypeID&       aFrom );

private:
    void *mPTFPtr;
};

#endif // __cplusplus

// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Create a pixel type based on ID, the user is reponsible for deleting the returned pixel type
CY_IMG_LIB_C_API( CyPixelTypeH ) CyPixelTypeFactory_CreatePixelType( CyPixelTypeID aID );

// Indicates if a pixel type exists
CY_IMG_LIB_C_API( int ) CyPixelTypeFactory_HasPixelType( CyPixelTypeID aID );

// Returns the name of a pixel type
CY_IMG_LIB_C_API( const char* )
                     CyPixelTypeFactory_GetPixelTypeName( CyPixelTypeID aID );

// Returns the number of pixel types that matches the criteria
CY_IMG_LIB_C_API( unsigned long )
                     CyPixelTypeFactory_CountPixelTypes( unsigned long aDepth,
                                                         CyPixelTypeID aColour,
                                                         int           aNormalized,
                                                         int           aPacked,
                                                         int           aInterlaced,
                                                         int           aPlanar,
                                                         CyPixelTypeID aOutput,
                                                         int           aBayerPattern );

// Creates a pixel type based on criteria and index
CY_IMG_LIB_C_API( CyPixelTypeH )
                     CyPixelTypeFactory_CreatePixelType2( unsigned long aDepth,
                                                          CyPixelTypeID aColour,
                                                          int           aNormalized,
                                                          int           aPacked,
                                                          int           aInterlaced,
                                                          int           aPlanar,
                                                          CyPixelTypeID aOutput,
                                                          int           aBayerPattern,
                                                          unsigned long aIndex );

// Enumerate pixel type converters to/from a pixel type
CY_IMG_LIB_C_API( int ) CyPixelTypeFactory_EnumConverterFrom( unsigned long        aIndex,
                                                              CyPixelTypeID        aRef,
                                                              CyPixelTypeID*       aTo );
CY_IMG_LIB_C_API( int ) CyPixelTypeFactory_EnumConverterTo  ( unsigned long        aIndex,
                                                              CyPixelTypeID        aRef,
                                                              CyPixelTypeID*       aFrom );

// Indicates if a converter exists between 2 pixel types
CY_IMG_LIB_C_API( int ) CyPixelTypeFactory_HasConverter( CyPixelTypeID aSrcID,
                                                         CyPixelTypeID aDstID );

// Returns a converter exists between 2 pixel types
CY_IMG_LIB_C_API( CyPixelConverterH ) CyPixelTypeFactory_GetConverter( CyPixelTypeID aSrcID,
                                                                       CyPixelTypeID aDstID );

#endif // __CY_PIXEL_TYPE_FACTORY_H__
