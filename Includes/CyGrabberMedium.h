// *****************************************************************************
//
// $Id: CyGrabberMedium.h,v 1.22 2007/07/04 21:27:06 igors Exp $
//
// cy1h24b1
//
// *****************************************************************************
//
//     Copyright (c) 2004, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrabberMedium.h
//
// Description..: Define interface for medium camera link grabber.
//
// *****************************************************************************

#ifndef _CY_GRABBER_MEDIUM_H_
#define _CY_GRABBER_MEDIUM_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyComLib =====
#include <CyConfig.h>

// ===== CyCamLib =====
#include <CyGrabber.h>

// ===== This Project =====
#include "CyMediumLib.h"
#include "CyGrabberMediumConstants.h"


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyGrabberMediumInternal;
class CyGrabberMedium : public CyGrabber
{
// Data types and constants
public:
    // ===== Flags =====
    CY_MEDIUM_LIB_API static const unsigned long FLAG_CONNECT_AS_TWO_BASE;


// Constructors / Destructor
public:
    CY_MEDIUM_LIB_API CyGrabberMedium();
    CY_MEDIUM_LIB_API virtual ~CyGrabberMedium();

public:
    // Returns the performance monitor
    CY_MEDIUM_LIB_API virtual CyPerfMonitor& GetPerformanceMonitor( const CyChannel& aChannel = CyChannel( 0 ) ) const;

	// ===== Connection =====

    // Uses current index as the first device and current index + 1 as the second device
	CY_MEDIUM_LIB_API virtual CyResult Connect( const CyConfig& aConfig,
                                                unsigned long   aFlags = 0 );

    // Uses the current index of each config for the first and second devices respectively
    CY_MEDIUM_LIB_API virtual CyResult Connect( const CyConfig& aConfig0,
                                                const CyConfig& aConfig1,
                                                unsigned long   aFlags = 0 );

    // Disconnect
    CY_MEDIUM_LIB_API virtual CyResult Disconnect( );


    // ===== CyGrabber Overrides =====

    // ----- Read/Write changes on Grabber -----
    CY_MEDIUM_LIB_API virtual CyResult SaveConfig();
    CY_MEDIUM_LIB_API virtual CyResult LoadConfig();

    // ----- Internal Grabbers & Devices -----
    // Returns the first device
	CY_MEDIUM_LIB_API virtual CyDevice&  GetDevice( void ) const;

    // Returns the device or grabber with the specified index
    CY_MEDIUM_LIB_API virtual CyDevice&  GetDevice( unsigned int aIndex ) const;
    CY_MEDIUM_LIB_API virtual CyGrabber& GetGrabber( unsigned int aIndex ) const;

	// ----- Grabbing Operation -----
	CY_MEDIUM_LIB_API virtual CyResult Grab( const CyChannel    & aChannel,
                                             unsigned char      * aBuffer,
                                             unsigned long        aSize,
                                             CyResultEvent      * aEvent,
                                             DriverSharedMemory * aShared,
                                             unsigned long        aFlags,
                                             const DataReceiverSetting * aSettings = NULL );

    CY_MEDIUM_LIB_API virtual CyResult AbortGrab( const CyChannel& aChannel );

    CY_MEDIUM_LIB_API virtual CyResult StartContinuous( const CyChannel& aChannel, 
                                                        bool             aTriggerNow = false,
                                                        unsigned long    aFlags = 0 );
    CY_MEDIUM_LIB_API virtual CyResult StopContinuous ( const CyChannel& aChannel );

    CY_MEDIUM_LIB_API virtual CyResult Trigger        ( const CyChannel& aChannel,
                                                        unsigned long    aFlags,
                                                        unsigned char    aQuantity = 1 );

    // ----- Recording Mode -----

    CY_MEDIUM_LIB_API virtual CyResult StartRecording( const CyChannel& aChannel, unsigned long aFlags = 0 );
    CY_MEDIUM_LIB_API virtual CyResult StopRecording ( const CyChannel& aChannel );
    CY_MEDIUM_LIB_API virtual bool     IsRecording   ( const CyChannel& aChannel ) const;


    // ===== Extensions =====
    // Extensions are set on both internal grabbers, but read from the first one
    CY_MEDIUM_LIB_API virtual CyResult SetExtension( const CyGrabberExtension& aExtension );

protected:
    // CyGrabberMedium related interfaces
    CY_MEDIUM_LIB_API virtual CyResult AddPropertyPage  ( void* aPropertySheet );

    // Will load/save the extensions of the two sub-grabbers
    CY_MEDIUM_LIB_API virtual CyResult InternalSave ( CyXMLDocument& aDocument ) const;
    CY_MEDIUM_LIB_API virtual CyResult InternalLoad ( CyXMLDocument& aDocument );

private:
    struct CyGrabberMediumInternal* mInternal;

private:
    // Disabled
    CyGrabberMedium( const CyGrabberMedium & );
    const CyGrabberMedium & operator=( const CyGrabberMedium );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyGrabberMedium Handle
typedef void* CyGrabberMediumH;

// Construction
// Destruction is done using CyGrabber_Destroy
CY_MEDIUM_LIB_C_API( CyGrabberMediumH ) CyGrabberMedium_Init();

// Connection.  Use CyGrabber_Connect for a single config connection or
// the following when using two configurations
CY_MEDIUM_LIB_C_API( CyResult )      CyGrabberMedium_Connect( CyGrabberMediumH aHandle,
                                                              CyConfigH        aConfig0,
                                                              CyConfigH        aConfig1,
                                                              unsigned long    aFlags );

// IMPORTANT: All the other functions are overrides to CyGrabber.  You can use any of
// the CyGrabber_XXX functions with a medium grabber handle.

#endif // _CY_GRABBER_MEDIUM_H_
