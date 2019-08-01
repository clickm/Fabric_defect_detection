// *****************************************************************************
//
// $Id: CyCameraInterface.h,v 1.65 2009/05/29 14:51:53 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraInterface.h
//
// Description..: Defines the base of a camera class.
//
// *****************************************************************************

#ifndef __CY_CAMERA_INTERFACE_H__
#define __CY_CAMERA_INTERFACE_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyString.h>
#include <CyXMLDocument.h>
#include <CyPersistentRepository.h>

// ===== CyImgLib =====
#include <CyPixelType.h>
#include <CyPixelConverter.h>

// ===== CyComLib =====
#include <CyChannel.h>

// ===== This Project =====
#include "CyCamLib.h"
#include "CyCamLibCDef.h"
#include "CyGrabber.h"
#include "CyImageBuffer.h"
#include "CyCameraLimits.h"
#include "CyCameraInterfaceConstants.h"


// Class CyCameraInterface
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyCameraInterface : public CyPersistentRepository
{
// Construction / Destruction
public:
    CY_CAM_LIB_API            CyCameraInterface( CyGrabber&            aGrabber,
                                                 const CyCameraLimits& aLimits );
    CY_CAM_LIB_API            CyCameraInterface( CyGrabber*            aGrabber,
                                                 const CyCameraLimits& aLimits );
    CY_CAM_LIB_API virtual    ~CyCameraInterface();
private:
    CyResult                  Construct();


// Access to the grabber and camera limits
public:
    CY_CAM_LIB_API virtual CyDevice&             GetDevice( void ) const;
    CY_CAM_LIB_API virtual CyGrabber&            GetGrabber() const;
    CY_CAM_LIB_API virtual const CyCameraLimits& GetLimits() const;


// Update Camera
public:
    CY_CAM_LIB_API virtual CyResult UpdateToCamera( bool aDeviceReset = false ) const;
    CY_CAM_LIB_API virtual CyResult LocalUpdate   ( bool aDeviceReset ) const;


// Save/load settings from XML
public:
    CY_CAM_LIB_API virtual CyResult SaveToXML    ( CyXMLDocument& aDocument ) const;
    CY_CAM_LIB_API virtual CyResult LoadFromXML  ( CyXMLDocument& aDocument );


// Show Configuration Dialog
public:
    // Using void* to avoid windows.h dependency
    CY_CAM_LIB_API virtual CyResult ShowDialog       ( void* aParent = NULL );


// Properties
public:
    // Indicates if the camera supports the specific pixel type at the specified tap quantity
    CY_CAM_LIB_API virtual bool          SupportsPixelType( const CyPixelTypeID& aPixel,
                                                            unsigned char        aTapQuantity ) const;

    // Returns the pixel type after pixel shifting is applied
    CY_CAM_LIB_API virtual CyResult      GetEffectivePixelType( CyPixelTypeID& aPixel ) const;

    // Returns the conversion flags to use, based de-interlacing option and/or bayer flags
    CY_CAM_LIB_API virtual unsigned long GetPixelConversionFlags() const;

    // Sets up an image buffer based on the camera settings
    CY_CAM_LIB_API virtual CyResult      SetupBuffer( CyBufferQueue& aBuffer, unsigned short aChannel = 0 ) const;

    // Returns the RGB Filter to use for this camera
    CY_CAM_LIB_API virtual CyRGBFilter&  GetRGBFilter() const;

    // Resets the camera.
    // NOTE: must be overriden for a specific camera.  The overriden function will then
    // have to send the right command to the camera.  If not, then this method returns
    // CY_RESULT_NOT_SUPPORTED.
    CY_CAM_LIB_API virtual CyResult ResetCamera     ( );

    // ===== Performance =====
    CY_CAM_LIB_API virtual CyPerfMonitor& GetPerformanceMonitor( const CyChannel& aChannel ) const;


// Grabbing, Triggering and recording methods
public:
	CY_CAM_LIB_API virtual CyResult Grab( const CyChannel&            aChannel,
                                          CyBufferQueue&              aBuf,
                                          unsigned long               aFlags );

    CY_CAM_LIB_API virtual CyResult Grab( const CyChannel&            aChannel,
                                          CyUserBuffer&               aBuffer,
                                          unsigned long               aFlags );

	CY_CAM_LIB_API virtual CyResult Grab( const CyChannel           & aChannel,
                                          unsigned char             * aBuffer,
                                          unsigned long               aBufferSize,
                                          CyResultEvent             * aEvent = NULL,
                                          struct DriverSharedMemory * aShared = NULL,
                                          unsigned long               aFlags = NULL,
                                          const DataReceiverSetting * aSettings = NULL );

    CY_CAM_LIB_API virtual CyResult AbortGrab( const CyChannel& aChannel );

	CY_CAM_LIB_API virtual CyResult StartGrabbing( const CyChannel& aChannel,
                                                   CyBufferQueue&   aBuf,
                                                   unsigned long    aFlags = 0 );

	CY_CAM_LIB_API virtual CyResult StopGrabbing ( const CyChannel& aChannel );

    CY_CAM_LIB_API virtual bool     IsGrabbing   ( const CyChannel& aChannel ) const;

    CY_CAM_LIB_API virtual CyResult StartContinuous( const CyChannel& aChannel, 
                                                     bool             aTriggerNow = false,
                                                     unsigned long    aFlags = 0 );

    CY_CAM_LIB_API virtual CyResult StopContinuous( const CyChannel& aChannel );

    CY_CAM_LIB_API virtual CyResult Trigger( const CyChannel& aChannel,
                                             unsigned long    aFlags,
                                             unsigned char    aQuantity = 1 );

    CY_CAM_LIB_API virtual CyResult StartRecording( const CyChannel& aChannel, unsigned long aFlags = 0 );
    CY_CAM_LIB_API virtual CyResult StopRecording ( const CyChannel& aChannel );
    CY_CAM_LIB_API virtual bool     IsRecording   ( const CyChannel& aChannel ) const;

protected:
    CY_CAM_LIB_API virtual CyResult InternalUpdate  ( bool aDeviceReset ) const;
    CY_CAM_LIB_API virtual CyResult InternalSave    ( CyXMLDocument& aDocument ) const;
    CY_CAM_LIB_API virtual CyResult InternalLoad    ( CyXMLDocument& aDocument );
    CY_CAM_LIB_API virtual CyResult AddPropertyPage ( void* aPropertySheet );

    // CyParameterRepository overrides
    CY_CAM_LIB_API virtual CyResult OnParameterSet  ( unsigned long   aParameterIndex,
                                                      unsigned long   aParameterID,
                                                      const CyString& aParameterName,
                                                      bool            aTest,
                                                      const CyString& aValueS,
                                                      CY_INT64        aValueI,
                                                      double          aValueD );
    CY_CAM_LIB_API virtual CyResult OnParameterGet  ( unsigned long   aParameterIndex,
                                                      unsigned long   aParameterID,
                                                      const CyString& aParameterName  );
    CY_CAM_LIB_API virtual CyResult OnParameterChanged( unsigned long   aParameterIndex,
                                                        unsigned long   aParameterID,
                                                        const CyString& aParameterName,
                                                        const CyString& aValueS,
                                                        CY_INT64        aValueI,
                                                        double          aValueD );


//protected: // public for technical reasons, but really protected
public:
    CY_CAM_LIB_API virtual CyResult OnApply         ( void* aPropertyPage );

// Members
private:
#ifdef _MANAGED
	friend ref class NCyCameraInterface;	//.Net wrapper need acccess to protected members
#endif //_MANAGED
    friend struct CyCameraInterfaceInternal;
    struct CyCameraInterfaceInternal* mInternal;

#ifndef CY_CAMERA_NO_BACKWARD_COMPATIBILITY
#include "CyCameraInterfaceBackwardCompatibility.h"
#endif // CY_CAMERA_NO_BACKWARD_COMPATIBILITY
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Destruction
// A camera object can only be obtained from a CyCameraRegistryH objects
CY_CAM_LIB_C_API( void ) CyCameraInterface_Destroy( CyCameraInterfaceH aHandle );

// Access to the grabber
CY_CAM_LIB_C_API( CyGrabberH ) CyCameraInterface_GetGrabber( CyCameraInterfaceH aHandle );

// Returns the limits of the camera
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_GetLimits( CyCameraInterfaceH     aHandle,
                                                          struct CyCameraLimits* aLimits );

// Update settings on camera
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_UpdateToCamera( CyCameraInterfaceH aHandle,
                                                               int                aDeviceReset );
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_LocalUpdate   ( CyCameraInterfaceH aHandle,
                                                               int                aDeviceReset );

// Save/load settings from XML
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_SaveToXML  ( CyCameraInterfaceH aHandle,
                                                            CyXMLDocumentH     aDocument );
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_LoadFromXML( CyCameraInterfaceH aHandle,
                                                            CyXMLDocumentH     aDocument );

// Show Configuration Dialog
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_ShowDialog ( CyCameraInterfaceH aHandle,
                                                            void*              aParent,
                                                            unsigned long      aFlags );

// Properties
CY_CAM_LIB_C_API( int )      CyCameraInterface_SupportsPixelType   ( CyCameraInterfaceH aHandle,
                                                                     CyPixelTypeID      aPixel,
                                                                     unsigned char      aTapQuantity);
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_GetEffectivePixelType( CyCameraInterfaceH aHandle,
                                                                      CyPixelTypeID* aPixel );
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_SetupBuffer       ( CyCameraInterfaceH aHandle,
                                                                   CyBufferQueueH     aBuffer );
CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_SetupBuffer2      ( CyCameraInterfaceH aHandle,
                                                                   CyBufferQueueH     aBuffer,
                                                                   unsigned short     aChannel );
CY_CAM_LIB_C_API( CyRGBFilterH ) CyCameraInterface_GetRGBFilter  ( CyCameraInterfaceH aHandle );

CY_CAM_LIB_C_API( CyResult ) CyCameraInterface_ResetCamera    ( CyCameraInterfaceH aHandle );

#endif  // __CY_CAMERA_INTERFACE_H__

