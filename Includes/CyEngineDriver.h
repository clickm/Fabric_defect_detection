// *****************************************************************************
//
// $Id: CyEngineDriver.h,v 1.11 2007/07/04 21:27:06 igors Exp $
//
// cy1h23b1
//
// *****************************************************************************
//
//     Copyright (c) 2004, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyEngineDriver.h
//
// *****************************************************************************

#ifndef _CY_ENGINE_DRIVER_H_
#define _CY_ENGINE_DRIVER_H_

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyComLib =====
#include <CyAdapterID.h>

// ===== CyEngineLib =====
#include "CyEngine.h"


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyEngineDriverInternal;
class CyEngineDriver : public CyEngine
{
// Utilites
public:
    // enumerate High-Performance IP Device Drivers with the Hydra extensions enabled
    CY_ENGINE_LIB_API static CyResult CY_CALLING_CONV
                        GetAdapterID( unsigned long aIndex,
                                      CyAdapterID * aId,
                                      bool*         aEngineSupported = NULL );

    // Returns the index of a specified adapter ID
    CY_ENGINE_LIB_API static CyResult CY_CALLING_CONV
                        GetAdapterIndex( const CyAdapterID & aId,
                                         unsigned long     * aIndex,
                                         bool*         aEngineSupported = NULL );

// Construction / Destruction
public:
    CY_ENGINE_LIB_API CyEngineDriver();
    CY_ENGINE_LIB_API virtual ~CyEngineDriver();

// CyEngine overrides
public:
    CY_ENGINE_LIB_API virtual CyResult SetMaximumBandwidth( unsigned long aMaxBandwidth );
    CY_ENGINE_LIB_API virtual CyResult Connect( const CyAdapterID & aAdapterId );
    CY_ENGINE_LIB_API virtual CyResult Connect( unsigned long       aAdapterIndex );
    CY_ENGINE_LIB_API virtual CyResult Disconnect();

    CY_ENGINE_LIB_API virtual CyResult SendData( const void           * aBuffer,
                                                 unsigned long          aBufferSize,
                                                 unsigned long          aDstAddr,
                                                 unsigned short         aDstPort,
                                                 CyResultEvent        * aEvent,
                                                 CyEngineSharedMemory * aSharedMemory = NULL,
                                                 bool                   aConcurrent   = false );

protected:

    CY_ENGINE_LIB_API virtual CyResult GetAddresses( unsigned char * aEth,
                                                     unsigned char * aIp );

    CY_ENGINE_LIB_API virtual void OnRegisterWrite( unsigned long aAddress );

    CY_ENGINE_LIB_API virtual CyResult ReceivePacket( unsigned char  * aData,
                                                      unsigned long  * aDataSize,
                                                      unsigned short * aDstPort,
                                                      unsigned long  * aSrcAddr,
                                                      unsigned short * aSrcPort );
    CY_ENGINE_LIB_API virtual CyResult ReceivePacket( unsigned char  * aData,
                                                      unsigned long  * aDataSize,
                                                      unsigned short * aDstPort,
                                                      unsigned char  * aSrcAddrEth,
                                                      unsigned long  * aSrcAddr,
                                                      unsigned short * aSrcPort );
    CY_ENGINE_LIB_API virtual CyResult SendPacket( const unsigned char * aData,
                                                   unsigned long   aDataSize,
                                                   unsigned long   aDstAddr,
                                                   unsigned short  aDstPort,
                                                   unsigned short  aSrcPort );
    CY_ENGINE_LIB_API virtual CyResult SendPacket( const unsigned char * aData,
                                                   unsigned long   aDataSize,
                                                   const unsigned char * aDstAddrEth,
                                                   unsigned long   aDstAddr,
                                                   unsigned short  aDstPort,
                                                   unsigned short  aSrcPort );

private:

    CyEngineDriver( const CyEngineDriver & );

    const CyEngineDriver & operator=( const CyEngineDriver & );

    CyResult DeviceIoControl(       unsigned long   aCode,
                              const void          * aInput,
                                    unsigned long   aInputSize,
                                    void          * aOutput,
                                    unsigned long   aOutputSize,
                                    unsigned long * aInfo );
    CyResult DeviceIoControl(       unsigned long   aCode,
                              const void          * aInput,
                                    unsigned long   aInputSize,
                                    void          * aOutput,
                                    unsigned long   aOutputSize,
                                    unsigned long * aInfo,
                                    CyResultEvent * aEvent );

    struct CyEngineDriverInternal * mInternal;
    
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyEngineDriver Handle
typedef void* CyEngineDriverH;

// Construction
CY_ENGINE_LIB_C_API( CyEngineDriverH ) CyEngineDriver_Init();

// Utilities
CY_ENGINE_LIB_C_API( CyResult ) CyEngineDriver_GetAdapterID   ( unsigned long  aIndex,
                                                                CyAdapterIDH   aId,
                                                                int*           aEngineSupported );
CY_ENGINE_LIB_C_API( CyResult) CyEngineDriver_GetAdapterIndex( CyAdapterIDH   aId,
                                                               unsigned long* aIndex,
                                                               int*           aEngineSupported );


#endif // _CY_ENGINE_DRIVER_H_
