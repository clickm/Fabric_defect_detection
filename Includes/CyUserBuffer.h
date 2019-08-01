// *****************************************************************************
//
// $Id: CyUserBuffer.h,v 1.6 2007/11/13 13:42:02 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyUserBuffer.h
//
// Description..: Simple buffer class.  The actuel creation of the buffer is
//                up to the application using the buffer.
//
// *****************************************************************************

#ifndef _CY_USER_BUFFER_H_
#define _CY_USER_BUFFER_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyEvent.h>
#include <CyResultEvent.h>
#include <CyThread.h>
#include <CyTypes.h>


// ===== This Project =====
#include "CyImageInfo.h"
#include "CyComLib.h"
#include "CyComLibCDef.h"

// CyUserBuffer class
// 
// NOTE: This buffer class does not own the enclosed buffer, so it is the user's
// responsibility to create and delete the memory.
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyUserBufferInternal;
class CyUserBuffer : public CyObject
{
// Construction / Destruction
public:
    CY_COM_LIB_API CyUserBuffer( unsigned char * aBuffer,
                                   unsigned long   aBufferSize,
                                   unsigned long   aID = 0xffffffff );
    CY_COM_LIB_API virtual ~CyUserBuffer();

// Accessors
    // Returns the buffer ID.  The ID is purely application specific and
    // can be used to identify the buffer, if needed.
    CY_COM_LIB_API virtual unsigned long   GetID() const;

    // Returns a pointer to the buffer.
    CY_COM_LIB_API virtual unsigned char*  GetBuffer() const;
    CY_COM_LIB_API virtual unsigned long   GetBufferSize() const;

    // Change the pointer of the buffer
    // IMPORTANT: it is the responsibility of the user to release the buffer, if needed
    CY_COM_LIB_API virtual CyResult        SetBuffer( unsigned char* aBuffer,
                                                      unsigned long  aBufferSize );

    // Returns the event used to signal that a request using this buffer is
    // complete
    CY_COM_LIB_API virtual CyResultEvent&  GetCompletionEvent() const;

    // Returns the image information associated with this buffer
    CY_COM_LIB_API virtual CyImageInfo& GetImageInfo() const;

    CyImageInfo& GetSharedMemory() const
    {
        return GetImageInfo();
    }


private:
    struct CyUserBufferInternal* mInternal;
};

// For backward compatibility, we map the older CySimpleBuffer to the 
// renamed CyUserBuffer
#define CySimpleBuffer CyUserBuffer

// CyMonitoredBuffer class
// 
//  Since there is now way, at the moment, to have the driver signal us when
//  there is new data available.  This CyMonitoredBuffer class also acts as a thread.
//  The thread, which is sleeping, unless a grab is taking place, simply verifies
//  if the amount of data received in the shared memory (mMemory) has changed.
//  If so, it signals the event for the acquisition thread to handle
////////////////////////////////////////////////////////////////////////////////

struct CyMonitoredBufferInternal;
class CyMonitoredBuffer : public CyUserBuffer
{
// Construction / Destruction
public:
    CY_COM_LIB_API CyMonitoredBuffer( unsigned char * aBuffer,
                                      unsigned long   aBufferSize,
                                      unsigned long   aID = 0xffffffff );
    CY_COM_LIB_API virtual ~CyMonitoredBuffer();


// Accessors
    // returns the event associated with new data available for this
    // buffer
    CY_COM_LIB_API virtual CyResultEvent&  GetDataAvailableEvent() const;

// Monitoring thread control
    CY_COM_LIB_API virtual void StartMonitoring();
    CY_COM_LIB_API virtual void StopMonitoring();

private:
    struct CyMonitoredBufferInternal* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Constructors/Destructor
CY_COM_LIB_C_API( CyUserBufferH )      CyUserBuffer_Init   ( unsigned char * aBuffer,
                                                             unsigned long   aBufferSize,
                                                             unsigned long   aID );
CY_COM_LIB_C_API( CyMonitoredBufferH ) CyMonitoredBuffer_Init( unsigned char * aBuffer,
                                                               unsigned long   aBufferSize,
                                                               unsigned long   aID );
CY_COM_LIB_C_API( void )               CyUserBuffer_Destroy( CyUserBufferH aHandle );

// CyUserBuffer functions
CY_COM_LIB_C_API( unsigned long )   CyUserBuffer_GetID             ( CyUserBufferH aHandle );
CY_COM_LIB_C_API( unsigned char* )  CyUserBuffer_GetBuffer         ( CyUserBufferH aHandle );
CY_COM_LIB_C_API( unsigned long )   CyUserBuffer_GetBufferSize     ( CyUserBufferH aHandle );
CY_COM_LIB_C_API( CyResultEventH )  CyUserBuffer_GetCompletionEvent( CyUserBufferH aHandle );
CY_COM_LIB_C_API( CyImageInfoH )    CyUserBuffer_GetImageInfo      ( CyUserBufferH aHandle );
#define CyUserBuffer_GetSharedMemory CyUserBuffer_GetImageInfo
CY_COM_LIB_C_API( CyResult )        CyUserBuffer_SetBuffer         ( CyUserBufferH aHandle,
                                                                     unsigned char*  aBuffer,
                                                                     unsigned long   aBufferSize );

// CyMonitoredBuffer functions
CY_COM_LIB_C_API( CyResultEventH )  CyMonitoredBuffer_GetDataAvailableEvent( CyMonitoredBufferH aHandle );
CY_COM_LIB_C_API( void )            CyMonitoredBuffer_StartMonitoring      ( CyMonitoredBufferH aHandle );
CY_COM_LIB_C_API( void  )           CyMonitoredBuffer_StopMonitoring       ( CyMonitoredBufferH aHandle );

#endif // _CY_USER_BUFFER_H_

