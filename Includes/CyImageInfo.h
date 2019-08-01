// *****************************************************************************
//
// $Id: CyImageInfo.h,v 1.4 2007/11/13 13:42:02 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyImageInfo.h
//
// Description..: Contains information that is place by the driver/udp link when
//                data is being received
//
// *****************************************************************************

#ifndef __CY_IMAGE_INFO_H__
#define __CY_IMAGE_INFO_H__

// Include
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyObject.h>

// ===== This project =====
#include "CyComLib.h"
#include "CyComLibCDef.h"
#include "CyBufferQueue.h"


// Forward declaration
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct DriverSharedMemory;
#endif // __cplusplus


// Types
/////////////////////////////////////////////////////////////////////////////

enum CyImagePayloadType
{
    CY_IMAGE_INFO_PAYLOAD_TYPE_IMAGE             = 0x0001,
    CY_IMAGE_INFO_PAYLOAD_TYPE_RAW_DATA          = 0x0002,
    CY_IMAGE_INFO_PAYLOAD_TYPE_FILE              = 0x0003,
    CY_IMAGE_INFO_PAYLOAD_TYPE_CHUNK             = 0x0004,
    CY_IMAGE_INFO_PAYLOAD_TYPE_DEVICE_SPECIFIC   = 0x8000,
};


// class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyImageInfo : public CyObject
{
// Construction / Destruction
public:
    CY_COM_LIB_API CyImageInfo();
    CY_COM_LIB_API ~CyImageInfo();

// Accessors
    // returns the internal DriverSharedMemory object.  Used internally by the SDK
    CY_COM_LIB_API DriverSharedMemory& GetSharedMemory() const;
    CY_COM_LIB_API operator DriverSharedMemory* () const;

    // Reset the shared memory
    CY_COM_LIB_API void Reset();

    // Returns the status of the operation.
    CY_COM_LIB_API CyResult GetStatus() const;

    // Returns the status of the frame.  Available only when the buffer has been
    // received completely, which is out of the scope of this class
#ifndef _QNX_
    CY_COM_LIB_API CyBufferQueue::ImageStatus GetImageStatus() const;
#else
    CY_COM_LIB_API unsigned long GetImageStatus() const;
#endif

    // Returns the time stamp of the frame.  Also only applies to a
    // completely received frame
    CY_COM_LIB_API unsigned long GetTimestamp() const;

    // Returns the ID of the frame and the sub-channel it comes from, if applicable.
    // Also only applies to a completely received frame
    CY_COM_LIB_API unsigned long GetImageID() const;
    CY_COM_LIB_API unsigned char GetSubChannelID() const;

    // Returns the current of the image, may be update by the driver
    CY_COM_LIB_API unsigned long GetSize() const;

    // Returns the payload type
    CY_COM_LIB_API unsigned long GetPayloadType() const;

    // Returns acquisition information 
    CY_COM_LIB_API unsigned long GetExpectedResendCount() const;
    CY_COM_LIB_API unsigned long GetIgnoredPacketCount() const;
    CY_COM_LIB_API unsigned long GetLostPacketCount() const;
    CY_COM_LIB_API unsigned long GetResendRequestCount() const;
    CY_COM_LIB_API unsigned long GetStartPacketCount() const;
    CY_COM_LIB_API unsigned long GetUnexpectedResendCount() const;

private:
    DriverSharedMemory* mSharedMemory;
};

#define CySharedMemory CyImageInfo

#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction / Destruction
CY_COM_LIB_C_API( CyImageInfoH ) CyImageInfo_Init();
CY_COM_LIB_C_API( void )            CyImageInfo_Destroy( CyImageInfoH aHandle );

// Reset the shared memory
CY_COM_LIB_C_API( void )          CyImageInfo_Reset( CyImageInfoH aHandle );

// Accessors
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetStatus( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetImageStatus( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetTimestamp( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetImageID( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetSubChannelID( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetSize( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetPayloadType( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetExpectedResendCount( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetIgnoredPacketCount( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetLostPacketCount( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetResendRequestCount( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetStartPacketCount( CyImageInfoH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyImageInfo_GetUnexpectedResendCount( CyImageInfoH aHandle );

#endif // __CY_IMAGE_INFO_H__

