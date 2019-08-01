// *****************************************************************************
//
// $Id: CyCameraLimits.h,v 1.9 2007/07/04 21:27:05 igors Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraLimits.h
//
// Description..: 
//
// *****************************************************************************

#ifndef __CY_CAMERA_LIMITS_H__
#define __CY_CAMERA_LIMITS_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyString.h>

// ===== CyImgLib =====
#include <CyPixelType.h>

// ===== This Project =====
#include "CyCamLib.h"


// Class CyCameraLimits
/////////////////////////////////////////////////////////////////////////////

#ifdef WIN32
#pragma pack( push, 8 )
#endif // WIN32
struct CyCameraLimits
#ifdef __cplusplus
    : public CyObject
#endif // __cplusplus
{
#ifdef __cplusplus
public:
    CY_CAM_LIB_API CyCameraLimits();
    CY_CAM_LIB_API CyCameraLimits( const CyCameraLimits& aSource );
    CY_CAM_LIB_API ~CyCameraLimits();
    CY_CAM_LIB_API CyCameraLimits& operator=( const CyCameraLimits& aSource );

    // Deprecated, not used anymore
    CY_CAM_LIB_API void AddPixelTypeInfo( const CyString& aName,
                                          CyPixelTypeID   aType,
                                          unsigned char   aTaps );
    CY_CAM_LIB_API void ClearPixelTypes();
    CY_CAM_LIB_API unsigned long   GetPixelTypeCount() const;
    CY_CAM_LIB_API const CyString& GetPixelTypeName( unsigned long aIndex ) const;
    CY_CAM_LIB_API CyPixelTypeID GetPixelTypeID( unsigned long aIndex ) const;
    CY_CAM_LIB_API unsigned char GetPixelTypeTaps( unsigned long aIndex ) const;

    // Replaces with AddPixelInfo, which tells at each call, one colour space, one depth and one tap quantity
    CY_CAM_LIB_API void AddPixelTypeInfo( CyPixelTypeID aColourSpace,
                                          unsigned long aDepth,
                                          unsigned char aTaps,
                                          bool          aBayerRGB = false );

    // Indicates if a pixel type is supported or not
    CY_CAM_LIB_API bool SupportsPixelType( const CyPixelTypeID& aPixelID, unsigned char aTapQuantity ) const;

#endif // __cplusplus

// Members
    // Image Type
    int             mSupportLineScan;
    int             mSupportAreaScan;

    // Windowing
    unsigned long   mMinSizeX;
    unsigned long   mMaxSizeX;
    unsigned long   mMinSizeY;
    unsigned long   mMaxSizeY;
    unsigned long   mMinOffsetX;
    unsigned long   mMaxOffsetX;
    unsigned long   mMinOffsetY;
    unsigned long   mMaxOffsetY;
    unsigned short  mMinBinningX;
    unsigned short  mMaxBinningX;
    unsigned short  mMinBinningY;
    unsigned short  mMaxBinningY;
    unsigned short  mMinDecimationX;
    unsigned short  mMaxDecimationX;
    unsigned short  mMinDecimationY;
    unsigned short  mMaxDecimationY;

    // Pixel Information   
    unsigned char   mMinTaps;
    unsigned char   mMaxTaps;
    unsigned short  mMinBlackLevel;
    unsigned short  mMaxBlackLevel;

    // Sensor gain and offset limits
    unsigned short  mGainQuantity;
    long            mMinGain;
    long            mMaxGain;
    long            mMinOffset;
    long            mMaxOffset;

    // Digital Shift
    unsigned short  mMinDigitalShift;
    unsigned short  mMaxDigitalShift;

    // Exposure Control Mode and timing
    int             mSupportsFreeRunProgrammable;
    int             mSupportsFreeRunEdgeControlled;
    int             mSupportsExSyncLevelControlled;
    int             mSupportsExSyncProgrammable;
    int             mSupportsExSyncEdgeControlled;
    unsigned long   mMinExposureTime;
    unsigned long   mMaxExposureTime;
    double          mMinFrameRate;
    double          mMaxFrameRate;

    // Test Pattern & Image Flip
    unsigned short  mTestPatternCount;
    int             mSupportsImageFlip;

    // Diplay or not the grabber tab, not used anymore (always handle like TRUE)
    int             mDisplayGrabberTab;
    int             mDisplayImageTab;
    int             mDisplayGPIOTabs;

#ifdef __cplusplus
private:
    friend class CyGrabber;
    friend class CyCameraInterface;
    friend struct CyCameraLimitsInternal;
    friend class CyPixelTypePage;
    struct CyCameraLimitsInternal* mInternal;
#endif // __cplusplus
};
#ifdef WIN32
#pragma pack( pop )
#endif // WIN32

#endif  // __CY_CAMERA_LIMITS_H__

