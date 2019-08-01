// *****************************************************************************
//
// $Id: CyEngine.h,v 1.18 2009/06/04 17:20:18 sbouchard Exp $
//
// cy1h23b1
//
// *****************************************************************************
//
//     Copyright (c) 2004, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyEngine.h
//
// *****************************************************************************

#ifndef _CY_ENGINE_H_
#define _CY_ENGINE_H_

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyThread.h>
#include <CyResultEvent.h>

// ===== CyComLib =====
#include <CyAdapterID.h>

// ===== This Project =====
#include "CyEngineLib.h"


// Forward declaration
/////////////////////////////////////////////////////////////////////////////

// ===== CyEngineLib =====
#ifdef __cplusplus
class CyEngineExtension;
class CyEngineSharedMemory;
#endif // __cplusplus


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct EngineInternal;
class CyEngine : public CyThread
{

// ===== Construction / Destruction =====
public:
    CY_ENGINE_LIB_API CyEngine();
    CY_ENGINE_LIB_API virtual ~CyEngine();


// ===== Accessors =====
public:
    // Indicates if the engine is connected or not
    CY_ENGINE_LIB_API virtual bool IsConnected() const;

    // Sets or Gets the maximum bandwidth of the engine (in bytes)
    CY_ENGINE_LIB_API virtual CyResult SetMaximumBandwidth( unsigned long aMaxBandwidth );
    CY_ENGINE_LIB_API virtual unsigned long  GetMaximumBandwidth() const;

    // Sets the new starting block ID.  The block ID is used as the image sequence
    // number 
    CY_ENGINE_LIB_API virtual void SetBlockID ( unsigned long aBlockId  );
    CY_ENGINE_LIB_API virtual unsigned long GetBlockID() const;

    // Sets the module ID and sub-module ID that receivers will see.  The default
    // is 255.0, which is mapped to the "Hydra Receiver" in this SDK.
    CY_ENGINE_LIB_API virtual void          SetModuleID( unsigned char aModuleId );
    CY_ENGINE_LIB_API virtual unsigned char GetModuleID() const;
    CY_ENGINE_LIB_API virtual void          SetSubID   ( unsigned char aSubId    );
    CY_ENGINE_LIB_API virtual unsigned char GetSubID   () const;
    
	// Sets the module software version that the receivers will see.
	CY_ENGINE_LIB_API virtual void          SetVersionMajor   ( unsigned char aVersionMajor );
    CY_ENGINE_LIB_API virtual unsigned char GetVersionMajor   () const;
    CY_ENGINE_LIB_API virtual void          SetVersionMinor   ( unsigned char aVersionMinor );
    CY_ENGINE_LIB_API virtual unsigned char GetVersionMinor   () const;

    // Once a client is connected, it is possible to get information about the
    // connection.
    // NOTE: It is not possible, at the moment, to know if there is a connected
    //       client attached to the engine.

    // If the client set the connection as multicast, the group will be non-zero
    CY_ENGINE_LIB_API virtual unsigned short GetMulticastGroup()   const;

    // Returns the expected packet size (in bytes) of the connection.
    CY_ENGINE_LIB_API virtual unsigned short GetPacketSize()       const;


// ===== Connection control =====
public:
    // Connects the engine to the specified Hydra adapter ID.  The Hydra enabled
    // adapters can be obtained using CyEngineDriver::GetAdapterID
    CY_ENGINE_LIB_API virtual CyResult Connect( const CyAdapterID & aAdapterId ) = 0;

    // Connects the engine to the Hydra enabled adapter with the specified index
    CY_ENGINE_LIB_API virtual CyResult Connect( unsigned long       aAdapterIndex );

    // Disconnects the engine
    CY_ENGINE_LIB_API virtual CyResult Disconnect();


// ===== Data sending =====
public:
    CY_ENGINE_LIB_API virtual CyResult SendData( const void           * aBuffer,
                                                 unsigned long          aBufferSize,
                                                 unsigned long          aDstAddr,
                                                 unsigned short         aDstPort,
                                                 CyResultEvent        * aEvent,
                                                 CyEngineSharedMemory * aSharedMemory = 0,
                                                 bool                   aConcurrent   = false ) = 0;


// ===== Extensions =====
public:
    CY_ENGINE_LIB_API virtual CyResult ConnectExtension   ( CyEngineExtension * aExtension );
    CY_ENGINE_LIB_API virtual CyResult DisconnectExtension( CyEngineExtension * aExtension );


// ===== Undocumented =====
public:
    CY_ENGINE_LIB_API virtual CyResult ReadConfig   ( CY_UINT32   aAddress,
                                                      CY_UINT32 * aValue );
    CY_ENGINE_LIB_API virtual CyResult ReadConfig   ( CY_UINT32   aAddress,
                                                      CY_UINT16 * aValue );
    CY_ENGINE_LIB_API virtual CyResult WriteConfig  ( CY_UINT32   aAddress,
                                                      CY_UINT32   aValue );
    CY_ENGINE_LIB_API virtual CyResult WriteConfig  ( CY_UINT32   aAddress,
                                                      CY_UINT16   aValue );
    CY_ENGINE_LIB_API virtual CyResult ReadRegister ( CY_UINT32   aAddress,
                                                      CY_UINT32 * aValue );
    CY_ENGINE_LIB_API virtual CyResult ReadRegister ( CY_UINT32   aAddress,
                                                      CY_UINT16 * aValue );
    CY_ENGINE_LIB_API virtual CyResult WriteRegister( CY_UINT32   aAddress,
                                                      CY_UINT32   aValue );
    CY_ENGINE_LIB_API virtual CyResult WriteRegister( CY_UINT32   aAddress,
                                                      CY_UINT16   aValue );

    // CyThread override, should be private, but needs to be public for technical reasons
    virtual CyResult Run();


// ===== Protected methods =====
protected:
    CY_ENGINE_LIB_API virtual unsigned short GetCmdPort()  const;
    CY_ENGINE_LIB_API virtual unsigned short GetDataPort() const;
    CY_ENGINE_LIB_API virtual unsigned short GetIrqPort()  const;
    CY_ENGINE_LIB_API virtual unsigned long  GetNextBlockID(
        unsigned long aBufferSize ) const;

    CY_ENGINE_LIB_API virtual CyResult GetAddresses( unsigned char * aEth,
                                                     unsigned char * aIp ) = 0;

    CY_ENGINE_LIB_API virtual void OnRegisterWrite( unsigned long aAddress );

    CY_ENGINE_LIB_API virtual CyResult ReceivePacket( unsigned char  * aData,
                                                      unsigned long  * aDataSize,
                                                      unsigned short * aDstPort,
                                                      unsigned long  * aSrcAddr,
                                                      unsigned short * aSrcPort ) = 0;
    CY_ENGINE_LIB_API virtual CyResult ReceivePacket( unsigned char  * aData,
                                                      unsigned long  * aDataSize,
                                                      unsigned short * aDstPort,
                                                      unsigned char  * aSrcAddrEth,
                                                      unsigned long  * aSrcAddr,
                                                      unsigned short * aSrcPort ) = 0;
    CY_ENGINE_LIB_API virtual void ResetModule( unsigned short aRequestId,
                                                unsigned long  aSrcAddr,
                                                unsigned short aSrcPort );
    CY_ENGINE_LIB_API virtual CyResult SendPacket( const unsigned char * aData,
                                                   unsigned long   aDataSize,
                                                   unsigned long   aDstAddr,
                                                   unsigned short  aDstPort,
                                                   unsigned short  aSrcPort ) = 0;
    CY_ENGINE_LIB_API virtual CyResult SendPacket( const unsigned char * aData,
                                                   unsigned long   aDataSize,
                                                   const unsigned char * aDstAddrEth,
                                                   unsigned long   aDstAddr,
                                                   unsigned short  aDstPort,
                                                   unsigned short  aSrcPort ) = 0;

private:

    void ProcessCmdAction( const unsigned char * aData,
                                 unsigned long   aDataSize,
                           const unsigned char * aSrcAddrEth,
                                 unsigned long   aSrcAddr,
                                 unsigned short  aSrcPort );
    void ProcessCmdConfigRead( const unsigned char * aData,
                                     unsigned long   aDataSize,
                                     unsigned long   aSrcAddr,
                                     unsigned short  aSrcPort );
    void ProcessCmdConfigWrite( const unsigned char * aData,
                                      unsigned long   aDataSize,
                                      unsigned long   aSrcAddr,
                                      unsigned short  aSrcPort );
    void ProcessCmdPacket( const unsigned char * aData,
                                 unsigned long   aDataSize,
                           const unsigned char * aSrcAddrEth,
                                 unsigned long   aSrcAddr,
                                 unsigned short  aSrcPort );
    void ProcessCmdRegisterRead( const unsigned char * aData,
                                       unsigned long   aDataSize,
                                       unsigned long   aSrcAddr,
                                       unsigned short  aSrcPort );
    void ProcessCmdRegisterWrite( const unsigned char * aData,
                                        unsigned long   aDataSize,
                                        unsigned long   aSrcAddr,
                                        unsigned short  aSrcPort );
    void ProcessDataPacket( const unsigned char * aData,
                                  unsigned long   aDataSize,
                            const unsigned char * aSrcAddrEth,
                                  unsigned long   aSrcAddr,
                                  unsigned short  aSrcPort );
    void ProcessIrqPacket( const unsigned char * aData,
                                 unsigned long   aDataSize,
                                 unsigned long   aSrcAddr,
                                 unsigned short  aSrcPort );

    void SendDeviceInfo( unsigned short aRequestId,
                         const unsigned char * aSrcAddrEth,
                         unsigned long  aSrcAddr,
                         unsigned short aSrcPort );

// ===== Disabled =====
    CyEngine( const CyEngine & );
    const CyEngine & operator=( const CyEngine & );


// ===== Attributes =====
    struct EngineInternal* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyEngine Handle
typedef void* CyEngineH;
typedef void* CyEngineSharedMemoryH;
typedef void* CyEngineExtensionH;

// Construction: Use the constructor of the type of specific engine (ex: CyEngineDriver)
// Destruction: All CyEngine derived classes can be destroyed using this function
CY_ENGINE_LIB_C_API( void ) CyEngine_Destroy( CyEngineH aHandle );

// Indicates if the engine is connected or not
CY_ENGINE_LIB_C_API( int ) CyEngine_IsConnected( CyEngineH aHandle );

// Sets or Gets the maximum bandwidth of the engine (in bytes)
CY_ENGINE_LIB_C_API( CyResult )       CyEngine_SetMaximumBandwidth( CyEngineH     aHandle,
                                                                    unsigned long aMaxBandwidth );
CY_ENGINE_LIB_C_API( unsigned long )  CyEngine_GetMaximumBandwidth( CyEngineH aHandle );

// Sets the new starting block ID.  The block ID is used as the image sequence
// number 
CY_ENGINE_LIB_C_API( void )          CyEngine_SetBlockID( CyEngineH     aHandle,
                                                          unsigned long aBlockId  );
CY_ENGINE_LIB_C_API( unsigned long ) CyEngine_GetBlockID( CyEngineH aHandle );

// Sets the module ID and sub-module ID that receivers will see.  The default
// is 255.0, which is mapped to the "Hydra Receiver" in this SDK.
CY_ENGINE_LIB_C_API( void )         CyEngine_SetModuleID( CyEngineH     aHandle,
                                                        unsigned char aModuleId );
CY_ENGINE_LIB_C_API( unsigned char ) CyEngine_GetModuleID( CyEngineH     aHandle );
CY_ENGINE_LIB_C_API( void )          CyEngine_SetSubID   ( CyEngineH     aHandle,
                                                           unsigned char aSubId  );
CY_ENGINE_LIB_C_API( unsigned char ) CyEngine_GetSubID   ( CyEngineH     aHandle );

	// Sets the module software version that the receivers will see.
CY_ENGINE_LIB_C_API( void )          CyEngine_SetVersionMajor( CyEngineH     aHandle,
                                                               unsigned char aVersionMajor );
CY_ENGINE_LIB_C_API( unsigned char ) CyEngine_GetVersionMajor( CyEngineH     aHandle );
CY_ENGINE_LIB_C_API( void )          CyEngine_SetVersionMinor   ( CyEngineH     aHandle,
                                                                  unsigned char aVersionMinor  );
CY_ENGINE_LIB_C_API( unsigned char ) CyEngine_GetVersionMinor   ( CyEngineH     aHandle );

// If the client set the connection as multicast, the group will be non-zero
CY_ENGINE_LIB_C_API( unsigned short ) CyEngine_GetMulticastGroup( CyEngineH aHandle );

// Returns the expected packet size (in bytes) of the connection.
CY_ENGINE_LIB_C_API( unsigned short ) CyEngine_GetPacketSize( CyEngineH aHandle );


// Connects the engine to the specified Hydra adapter ID.  The Hydra enabled
// adapters can be obtained using CyEngineDriver::GetAdapterID
CY_ENGINE_LIB_C_API( CyResult ) CyEngine_Connect( CyEngineH    aHandle,
                                                  CyAdapterIDH aAdapterId );

// Connects the engine to the Hydra enabled adapter with the specified index
CY_ENGINE_LIB_C_API( CyResult ) CyEngine_ConnectIndex( CyEngineH     aHandle,
                                                       unsigned long aAdapterIndex );

// Disconnects the engine
CY_ENGINE_LIB_C_API( CyResult ) CyEngine_Disconnect( CyEngineH aHandle );


// ===== Data sending =====
CY_ENGINE_LIB_C_API( CyResult ) CyEngine_SendData( CyEngineH             aHandle,
                                                   void*                 aBuffer,
                                                   unsigned long         aBufferSize,
                                                   unsigned long         aDstAddr,
                                                   unsigned short        aDstPort,
                                                   CyResultEventH        aEvent,
                                                   CyEngineSharedMemoryH aSharedMemory,
                                                   int                   aConcurrent );

// ===== Extensions =====
CY_ENGINE_LIB_C_API( CyResult ) CyEngine_ConnectExtension   ( CyEngineH          aHandle,
                                                              CyEngineExtensionH aExtension );
CY_ENGINE_LIB_C_API( CyResult ) CyEngine_DisconnectExtension( CyEngineH          aHandle,
                                                              CyEngineExtensionH aExtension );

#endif // _CY_ENGINE_H_
