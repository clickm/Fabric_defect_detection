// *****************************************************************************
//
// $Id: CyGrabber.h,v 1.71 2009/05/29 14:51:55 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrabber.h
//
// Description..: Class that encapsulates the grabber module of the IP Engine.
//
// *****************************************************************************

#ifndef _CY_GRABBER_H_
#define _CY_GRABBER_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyPersistentRepository.h>
#include <CyThread.h>
#include <CyAssert.h>

// ===== CyComLib =====
#include <CyDevice.h>
#include <CyChannel.h>
#include <CyUserBuffer.h>
#include <CyPerfMonitor.h>

// ===== This project =====
#include "CyImageBuffer.h"
#include "CyCamLib.h"
#include "CyCamLibCDef.h"
#include "CyGrabberConstants.h"
#include "CyGrabberExtension.h"
#include "CyGrabberExtensionConstants.h"


// Forward Declarations
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyCameraInterface;
struct ChannelInfo;
#endif
struct DriverSharedMemory;


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus

struct CyGrabberInternal;
class CyGrabber : public CyPersistentRepository
{
// Constructors / Destructor
public:
	CY_CAM_LIB_API CyGrabber();
    CY_CAM_LIB_API CyGrabber( CyDevice& aDevice );
	CY_CAM_LIB_API virtual ~CyGrabber( void );

// Linking / Unlinking from camera objects
public:
    CY_CAM_LIB_API virtual CyResult LinkTo    ( CyCameraInterface& aCamera, unsigned short aChannel = 0 );
    CY_CAM_LIB_API virtual CyResult UnlinkFrom( const CyCameraInterface& aCamera, unsigned short aChannel = 0 );
    CY_CAM_LIB_API virtual bool     IsLinkedTo( const CyCameraInterface& aCamera, unsigned short aChannel = 0 ) const;
    CY_CAM_LIB_API virtual bool     HasLinkedCamera( unsigned short aChannel = 0 ) const;
    CY_CAM_LIB_API virtual CyCameraInterface& GetLinkedCamera( unsigned short aChannel = 0 ) const;


    // ===== Grabber Extensions =====

    // Get the number of extensions on the Grabber
public:
    CY_CAM_LIB_API unsigned long GetExtensionCount() const;
    CY_CAM_LIB_API unsigned long GetExtensionCountByType( unsigned long aTypeExtensionID ) const;


    // Returns the index of an extension
    CY_CAM_LIB_API unsigned long GetExtensionIndex( unsigned long   aExtensionID ) const;

    // Indicates if an extension exist
    CY_CAM_LIB_API bool HasExtensionByIndex( unsigned long   aIndex ) const;
    CY_CAM_LIB_API bool HasExtension       ( unsigned long   aExtensionID ) const;

    // returns an extension
    CY_CAM_LIB_API CyGrabberExtension& GetExtensionByIndex( unsigned long   aIndex ) const;
    CY_CAM_LIB_API CyGrabberExtension& GetExtension       ( unsigned long   aExtensionID ) const;

    // Save or load an extension on the grabber device
    // Deprecated
    CY_CAM_LIB_API virtual CyResult SetExtension( const CyGrabberExtension& aExtension );
    CY_CAM_LIB_API virtual CyResult GetExtension( CyGrabberExtension& aExtension );


public:
    // Read/Write changes on Grabber
    CY_CAM_LIB_API virtual CyResult SaveConfig();
    CY_CAM_LIB_API virtual CyResult LoadConfig();


    // ===== Device =====
	CY_CAM_LIB_API virtual CyDevice& GetDevice( void ) const;


    // ===== Performance =====
    CY_CAM_LIB_API virtual CyPerfMonitor& GetPerformanceMonitor( const CyChannel& aChannel = CyChannel( 0 ) ) const;


// Methods
public:

	// ===== Connection =====
	CY_CAM_LIB_API virtual CyResult Connect   ( const CyConfig& aConfig,
                                                unsigned long   aFlags = 0 );
	CY_CAM_LIB_API virtual CyResult Disconnect();


	// ===== Operation =====
	CY_CAM_LIB_API virtual CyResult Grab         ( const CyChannel&            aChannel,
                                                   CyBufferQueue&              aBuf,
                                                   unsigned long               aFlags );

    CY_CAM_LIB_API virtual CyResult Grab         ( const CyChannel&            aChannel,
                                                   CyUserBuffer&             aBuffer,
                                                   unsigned long               aFlags );

	CY_CAM_LIB_API virtual CyResult Grab         ( const CyChannel           & aChannel,
                                                   unsigned char             * aBuffer,
                                                   unsigned long               aBufferSize,
                                                   CyResultEvent             * aEvent = NULL,
                                                   struct DriverSharedMemory * aShared = NULL,
                                                   unsigned long               aFlags = NULL,
                                                   const DataReceiverSetting * aSetting = NULL );

    CY_CAM_LIB_API virtual CyResult AbortGrab( const CyChannel& aChannel );

	CY_CAM_LIB_API virtual CyResult StartGrabbing ( const CyChannel& aChannel,
                                                    CyBufferQueue&   aBuf,
                                                    CY_UINT32        aFlags = 0 );
	CY_CAM_LIB_API virtual CyResult StopGrabbing ( const CyChannel& aChannel );
    CY_CAM_LIB_API virtual bool     IsGrabbing   ( const CyChannel& aChannel ) const;

    CY_CAM_LIB_API virtual CyResult StartContinuous( const CyChannel& aChannel, 
                                                     bool             aTriggerNow = false,
                                                     unsigned long    aFlags = 0 );
    CY_CAM_LIB_API virtual CyResult StopContinuous ( const CyChannel& aChannel );

    CY_CAM_LIB_API virtual CyResult Trigger        ( const CyChannel& aChannel,
                                                     unsigned long    aFlags,
                                                     unsigned char    aQuantity = 1 );


    // Recording mode.
    //
    // When recording mode is enabled, the Grabber will grab every frame and store
    // them in memory, until the memory is full or recording mode is disabled.
    //
    // Then, the use can grab the frames, at whatever the pace, with the FLAG_GRAB_RECORDING
    // flag.
    //
    // It is important to Stop the recording before grabbing the frames from memory
    //

    CY_CAM_LIB_API virtual CyResult StartRecording( const CyChannel& aChannel, unsigned long aFlags = 0 );
    CY_CAM_LIB_API virtual CyResult StopRecording ( const CyChannel& aChannel );
    CY_CAM_LIB_API virtual bool     IsRecording   ( const CyChannel& aChannel ) const;


    // Grab an image based on its image sequence ID
    //
    // This can be used to acquire an image that was lost, but still available in the
    // device's onboard memory.
    //
    // Note that it only works in single grab mode

    CY_CAM_LIB_API virtual CyResult GetAvailableSequenceID( const CyChannel& aChannel,
                                                            unsigned long&   aFirstImageSeqId,
                                                            unsigned long&   aLastImageSeqId ) const;

	CY_CAM_LIB_API virtual CyResult Grab         ( const CyChannel&            aChannel,
                                                   unsigned long               aImageSeqId,
                                                   CyBufferQueue&              aBuf,
                                                   unsigned long               aFlags );

    CY_CAM_LIB_API virtual CyResult Grab         ( const CyChannel&            aChannel,
                                                   unsigned long               aImageSeqId,
                                                   CyUserBuffer&               aBuffer,
                                                   unsigned long               aFlags );

	CY_CAM_LIB_API virtual CyResult Grab         ( const CyChannel           & aChannel,
                                                   unsigned long               aImageSeqId,
                                                   unsigned char             * aBuffer,
                                                   unsigned long               aBufferSize,
                                                   CyResultEvent             * aEvent = NULL,
                                                   struct DriverSharedMemory * aShared = NULL,
                                                   unsigned long               aFlags = NULL,
                                                   const DataReceiverSetting * aSetting = NULL );


    // Pixel type support
    //

    // Returns the pixel type after pixel shifting or tap reconstruction are applied
    CY_CAM_LIB_API virtual CyResult GetEffectivePixelType( CyPixelTypeID& aPixel, unsigned short aChannel = 0 ) const;

    // Sets up an image buffer based on the camera settings
    CY_CAM_LIB_API virtual CyResult SetupBuffer( CyBufferQueue& aBuffer, unsigned short aChannel = 0 ) const;



// Show Configuration Dialog
public:
    // Using void* to avoid windows.h dependency
    CY_CAM_LIB_API virtual CyResult ShowDialog       ( void* aParent = NULL );

// Save/load settings from XML
public:
    CY_CAM_LIB_API virtual CyResult SaveToXML    ( CyXMLDocument& aDocument ) const;
    CY_CAM_LIB_API virtual CyResult LoadFromXML  ( CyXMLDocument& aDocument );


public: // should really be protected, but are public for technical reasons
    CY_CAM_LIB_API virtual CyResult AddPropertyPage  ( void* aPropertySheet );
    CY_CAM_LIB_API virtual CyResult InternalSave ( CyXMLDocument& aDocument ) const;
    CY_CAM_LIB_API virtual CyResult InternalLoad ( CyXMLDocument& aDocument );
protected:
    CY_CAM_LIB_API virtual CyResult OnParameterGet( unsigned long   aParameterIndex,
                                                    unsigned long   aParameterID,
                                                    const CyString& aParameterName );

    CY_CAM_LIB_API virtual CyResult OnParameterSet( unsigned long   aParameterIndex,
                                                    unsigned long   aParameterID,
                                                    const CyString& aParameterName,
                                                    bool            aTest,
                                                    const CyString& aValueS,
                                                    CY_INT64        aValueI,
                                                    double          aValueD );

protected:
    CY_CAM_LIB_API virtual CyResult RegisterConditionalParameters();

// Members
private:
    CyResult CommonConstruct();
    struct CyGrabberInternal* mInternal;
    friend struct CyGrabberInternal;

    // Utilities
    CyResult UpdateCamera();
    CyResult UpdateCache();

// Disabled Operators
private:
    CyGrabber( const CyGrabber& );
	const CyGrabber &operator=( const CyGrabber& );

// The following files adds symbols that we available in previous version for
// backward compatibility.
#ifndef CY_GRABBER_NO_BACKWARD_COMPATIBILITY
#include "CyGrabberBackwardCompatibility.h"
#endif // CY_GRABBER_NO_BACKWARD_COMPATIBILITY
};

#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction/Destruction
CY_CAM_LIB_C_API( CyGrabberH ) CyGrabber_Init    ( int aIgnored1, CyChannelID aIgnored2 );
CY_CAM_LIB_C_API( CyGrabberH ) CyGrabber_Init2   ( CyDeviceH aDevice, int aIgnored1, CyChannelID aIgnored2 );
CY_CAM_LIB_C_API( void )       CyGrabber_Destroy ( CyGrabberH aHandle );

// Linking / Unlinking from camera objects
CY_CAM_LIB_C_API( CyResult )   CyGrabber_LinkTo    ( CyGrabberH         aHandle,
                                                     CyCameraInterfaceH aCamera );
CY_CAM_LIB_C_API( CyResult )   CyGrabber_UnlinkFrom( CyGrabberH         aHandle,
                                                     CyCameraInterfaceH aCamera );
CY_CAM_LIB_C_API( int )        CyGrabber_IsLinkedTo( CyGrabberH         aHandle,
                                                     CyCameraInterfaceH aCamera );

// Extension functions
CY_CAM_LIB_C_API( unsigned long )      CyGrabber_GetExtensionCount      ( CyGrabberH     aHandle );
CY_CAM_LIB_C_API( unsigned long )      CyGrabber_GetExtensionCountByType( CyGrabberH     aHandle,
                                                                          unsigned long aTypeExtensionID );
CY_CAM_LIB_C_API( unsigned long )      CyGrabber_GetExtensionIndex      ( CyGrabberH     aHandle,
                                                                          unsigned long aExtensionID );
CY_CAM_LIB_C_API( int )                CyGrabber_HasExtensionByIndex    ( CyGrabberH     aHandle,
                                                                          unsigned long aIndex );
CY_CAM_LIB_C_API( int )                CyGrabber_HasExtension           ( CyGrabberH     aHandle,
                                                                          unsigned long aExtensionID );
CY_CAM_LIB_C_API( CyGrabberExtensionH ) CyGrabber_GetExtensionByIndex    ( CyGrabberH     aHandle,
                                                                           unsigned long aIndex );
CY_CAM_LIB_C_API( CyGrabberExtensionH ) CyGrabber_GetExtension           ( CyGrabberH     aHandle,
                                                                           unsigned long aExtensionID );

// ===== Read/Write changes on Grabber =====
CY_CAM_LIB_C_API( CyResult )       CyGrabber_SaveConfig( CyGrabberH aHandle );
CY_CAM_LIB_C_API( CyResult )       CyGrabber_LoadConfig( CyGrabberH aHandle );

// ===== Status =====
CY_CAM_LIB_C_API( int )            CyGrabber_IsConnected     ( CyGrabberH  aHandle );

// ===== Performance & Device =====
CY_CAM_LIB_C_API( CyPerfMonitorH ) CyGrabber_GetPerformanceMonitor( CyGrabberH  aHandle,
                                                                    CyChannelID aChannel );
CY_CAM_LIB_C_API( CyDeviceH )      CyGrabber_GetDevice( CyGrabberH aHandle );

// ===== Connection =====
CY_CAM_LIB_C_API( CyResult ) CyGrabber_Connect   ( CyGrabberH    aHandle,
                                                   CyConfigH     aConfig,
                                                   unsigned long aFlags );
CY_CAM_LIB_C_API( CyResult ) CyGrabber_Disconnect( CyGrabberH    aHandle );

// ===== Grabbing =====
CY_CAM_LIB_C_API( CyResult ) CyGrabber_Grab         ( CyGrabberH           aHandle,
                                                      CyChannelID         	aChannel,
                                                      CyBufferQueueH  	aBuf,
                                                      unsigned long        aFlags );

CY_CAM_LIB_C_API( CyResult ) CyGrabber_GrabUserBuffer   ( CyGrabberH           aHandle,
                                                      CyChannelID         	aChannel,
                                                      CyUserBufferH       	aBuffer,
                                                      unsigned long       	aFlags );

// Will be obselete in the next Major release
CY_CAM_LIB_C_API( CyResult ) CyGrabber_GrabSimple   ( CyGrabberH           aHandle,
                                                      CyChannelID         	aChannel,
                                                      CyUserBufferH       	aBuffer,
                                                      unsigned long       	aFlags );

CY_CAM_LIB_C_API( CyResult ) CyGrabber_GrabUser     ( CyGrabberH           aHandle,
                                                      CyChannelID          aChannel,
                                                      unsigned char*       aBuffer,
                                                      unsigned long        aBufferSize,
                                                      CyResultEventH       aEvent,
                                                      struct DriverSharedMemory* aShared,
                                                      unsigned long        aFlags,
                                                      void*                aSetting );
                                                
CY_CAM_LIB_C_API( CyResult ) CyGrabber_AbortGrab     ( CyGrabberH           aHandle,
                                                       CyChannelID          aChannel );

CY_CAM_LIB_C_API( CyResult ) CyGrabber_StartGrabbing( CyGrabberH           aHandle,
                                                      CyChannelID          aChannel,
                                                      CyBufferQueueH       aBuf,
                                                      CY_UINT32            aFlags );
CY_CAM_LIB_C_API( CyResult ) CyGrabber_StopGrabbing ( CyGrabberH           aHandle,
                                                      CyChannelID          aChannel );

CY_CAM_LIB_C_API( int )      CyGrabber_IsGrabbing   ( CyGrabberH  aHandle,
                                                      CyChannelID aChannel );

CY_CAM_LIB_C_API( CyResult ) CyGrabber_StartContinuous( CyGrabberH    aHandle,
                                                        CyChannelID   aChannel,
                                                        int           aTriggerNow,
                                                        unsigned long aFlags );
CY_CAM_LIB_C_API( CyResult ) CyGrabber_StopContinuous ( CyGrabberH    aHandle,
                                                        CyChannelID   aChannel );
CY_CAM_LIB_C_API( CyResult ) CyGrabber_Trigger        ( CyGrabberH    aHandle,
                                                        CyChannelID   aChannel,
                                                        unsigned long aFlags,
                                                        unsigned char aQuantity );


// ===== Recording mode =====
CY_CAM_LIB_C_API( CyResult ) CyGrabber_StartRecording( CyGrabberH    aHandle,
                                                       CyChannelID   aChannel,
                                                       unsigned long aFlags );
CY_CAM_LIB_C_API( CyResult ) CyGrabber_StopRecording ( CyGrabberH    aHandle,
                                                       CyChannelID   aChannel );
CY_CAM_LIB_C_API( int )      CyGrabber_IsRecording   ( CyGrabberH    aHandle,
                                                       CyChannelID   aChannel );

// Save/load settings from XML
CY_CAM_LIB_C_API( CyResult ) CyGrabber_SaveToXML  ( CyGrabberH      aHandle,
                                                    CyXMLDocumentH  aDocument );
CY_CAM_LIB_C_API( CyResult ) CyGrabber_LoadFromXML( CyGrabberH      aHandle,
                                                    CyXMLDocumentH  aDocument );

// Show Configuration Dialog
CY_CAM_LIB_C_API( CyResult ) CyGrabber_ShowDialog ( CyGrabberH aHandle,
                                                    void*      aParent );

#endif // _CY_GRABBER_H_
