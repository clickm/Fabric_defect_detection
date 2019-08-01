// *****************************************************************************
//
//     Copyright (c) 2006, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGigEVisionDevice.h
//
// Description..: 
//
// *****************************************************************************

#pragma once

#ifndef __CY_GIGE_VISION_DEVICE_H__
#define __CY_GIGE_VISION_DEVICE_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyAssert.h>
#include <CyPersistentRepository.h>

// ===== CyComLib =====
#include <CyDevice.h>
#include <CyChannel.h>
#include <CyBufferQueue.h>
#include <CyUserBuffer.h>
#include <CyPerfMonitor.h>

// ===== CyImgLib =====
#include <CyRGBFilter.h>

// ===== This project =====
#include <CyGigEVisionLib.h>
#include <CyGigEVisionDeviceConstants.h>


// Forward-Declaration
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
namespace GenApi
{
	class CNodeMapRef;
}
#endif // __cplusplus


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyGigEVisionDeviceImpl;
class CyGigEVisionDevice : public CyPersistentRepository
{
public:
    // This method indicates if the GigEVisionDevice is available.
    // Depends on the availability of the GeniCam API
    CY_GEV_LIB_API static bool CY_CALLING_CONV IsAvailable();

	// Construction and destruction
	CY_GEV_LIB_API CyGigEVisionDevice();
	CY_GEV_LIB_API virtual ~CyGigEVisionDevice();

	// Connection
	CY_GEV_LIB_API virtual CyResult Connect( const CyConfig &aConfig, unsigned long aFlags = 0 );
	CY_GEV_LIB_API virtual CyResult Disconnect();

	// Save or load settings from XML
	CY_GEV_LIB_API virtual CyResult SaveToXML( CyXMLDocument &aDocument ) const;
	CY_GEV_LIB_API virtual CyResult LoadFromXML( CyXMLDocument &aDocument );

	// Device access
	CY_GEV_LIB_API virtual CyDevice &GetDevice() const;

	// Show configuration dialog - using void* to avoid exposing windows.h dependencies
	CY_GEV_LIB_API virtual CyResult ShowDialog( void *aParent = NULL );

    // Updates the currently cached settings to the camera
    CY_GEV_LIB_API virtual CyResult UpdateToCamera( bool aDeviceReset = false ) const;

	// Resets the camera - can return CY_RESULT_NOT_SUPPORTED
	CY_GEV_LIB_API virtual CyResult ResetCamera();

    // Returns the conversion flags to use, based de-interlacing option and/or bayer flags
    CY_GEV_LIB_API virtual unsigned long GetPixelConversionFlags() const;

	// Sets up an image buffer based on the camera settings
	CY_GEV_LIB_API virtual CyResult SetupBuffer( CyBufferQueue &aBuffer, unsigned short aChannel = 0 ) const;

    // Returns the RGB Filter to use for this camera
    CY_GEV_LIB_API virtual CyRGBFilter& GetRGBFilter() const;

	// Grabbing interface - will have to evolve in GEV compliant interface
	CY_GEV_LIB_API virtual CyResult Grab( const CyChannel &aChannel, CyBufferQueue &aBuf, unsigned long aFlags );
	CY_GEV_LIB_API virtual CyResult Grab( const CyChannel &aChannel, CyUserBuffer &aBuffer, unsigned long aFlags );
	CY_GEV_LIB_API virtual CyResult Grab( const CyChannel &aChannel, unsigned char *aBuffer, unsigned long aBufferSize, CyResultEvent *aEvent = NULL, struct DriverSharedMemory *aShared = NULL, unsigned long aFlags = 0, const DataReceiverSetting *aSettings = NULL );
	CY_GEV_LIB_API virtual CyResult AbortGrab( const CyChannel &aChannel );
	CY_GEV_LIB_API virtual CyResult StartGrabbing( const CyChannel &aChannel, CyBufferQueue &aBuf, unsigned long aFlags = 0 );
	CY_GEV_LIB_API virtual CyResult StopGrabbing( const CyChannel &aChannel );
	CY_GEV_LIB_API virtual bool IsGrabbing( const CyChannel &aChannel ) const;
	CY_GEV_LIB_API virtual CyResult StartContinuous( const CyChannel &aChannel, bool aTriggerNow = false, unsigned long aFlags = 0 );
	CY_GEV_LIB_API virtual CyResult StopContinuous( const CyChannel &aChannel );
	CY_GEV_LIB_API virtual CyResult Trigger( const CyChannel &aChannel, unsigned long aFlags, unsigned char aQuantity = 1 );

    // Recording mode.
    CY_GEV_LIB_API virtual CyResult StartRecording( const CyChannel& aChannel, unsigned long aFlags = 0 );
    CY_GEV_LIB_API virtual CyResult StopRecording ( const CyChannel& aChannel );
    CY_GEV_LIB_API virtual bool     IsRecording   ( const CyChannel& aChannel ) const;

	// Performance
	CY_GEV_LIB_API virtual CyPerfMonitor &GetPerformanceMonitor( const CyChannel &aChannel = CyChannel( 0 ) ) const;

	// Saves a GenICam XML file from the device
    CY_GEV_LIB_API CyResult SaveGenICamXML( CyString &aFileName );

    // Returns the GenICam node map
    CY_GEV_LIB_API CyResult GetNodeMap( GenApi::CNodeMapRef **aNodeMap );
    CY_GEV_LIB_API CyResult GetNodeMap( const GenApi::CNodeMapRef **aNodeMap ) const;

    // returns the type of a node in the node map, because GenApi
    // does not do it.  Types will be returns as enum CyParameterType values
    CY_GEV_LIB_API unsigned long GetNodeType( const CyString& aNodeName ) const;

protected:
	// Base classes behavior override
    CY_GEV_LIB_API virtual CyResult OnParameterSet( unsigned long   aParameterIndex,
                                                    unsigned long   aParameterID,
                                                    const CyString& aParameterName,
                                                    bool            aTest,
                                                    const CyString& aValueS,
                                                    __int64         aValueI,
                                                    double          aValueD );

private:

	// Not implemented
	CyGigEVisionDevice( const CyGigEVisionDevice & );
	const CyGigEVisionDevice &operator=( const CyGigEVisionDevice & );

	// Hidden implementation
	struct CyGigEVisionDeviceImpl *mThis;
	friend CyGigEVisionDeviceImpl;
};
#endif // __cplusplus

#endif // __CY_GIGE_VISION_DEVICE_H__
