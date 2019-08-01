// *****************************************************************************
//
// $Id: CySocketUDP.h,v 1.14 2009/05/29 14:46:14 sbouchard Exp $
//
// cy1d02a1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CySocketUDP.cpp
//
// *****************************************************************************

#ifndef _CY_SOCKET_UDP_H_
#define _CY_SOCKET_DDP_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include "CyTypes.h"

#include "CyErrorInterface.h"

// ===== This project =====
#include "CyComLib.h"
#include "CyConfig.h"
#include "CyDeviceFinder.h"

// Forward
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyDevice;
#endif // __cplusplus

// Class
/////////////////////////////////////////////////////////////////////////////

/* ==========================================================================
@class	CySocketUDP

@since	2003-06-23
========================================================================== */
#ifdef __cplusplus
struct CySocketUDPInternal;
class CySocketUDP : public CyErrorInterface
{
// Data type
public:

#if defined( _SUNOS_ ) 
#  pragma pack( 8 ) 
#  define __CY_ATTR_PACKED
#elif defined( _QNX_ ) && defined( _QNX_6_3_2 )
#  define __CY_ATTR_PACKED __attribute ((__packed__))
#elif defined( WIN32 )
#  pragma pack( push, Header, 8 )
#  define __CY_ATTR_PACKED
#else
#  pragma pack( push, 8 )
#  define __CY_ATTR_PACKED
#endif

	typedef struct
	{
            union
            {
                CY_UINT8 mIPAddress[ 4 ];
                CY_UINT32 mIPAddressInt;
            };

	    CY_UINT16 mUDPPort;
	}
	Address;
	
#if defined( _SUNOS_ ) 
#  pragma pack( 8 )
#elif defined( _QNX_ ) && defined( _QNX_6_3_2 )
	// Nothing to be done
#elif defined( WIN32 )
#  pragma pack( pop, Header )
#else
#  pragma pack( pop )
#endif

#ifdef __CY_ATTR_PACKED
#undef __CY_ATTR_PACKED
#endif /* __CY_ATTR_PACKED */


// Constants
public:
	static const unsigned short ANY_PORT;

// Constructors / Destructor
public:
	CY_COM_LIB_API CySocketUDP( void );

	CY_COM_LIB_API virtual ~CySocketUDP( void );

	CY_COM_LIB_API CyResult Initialize( const CyConfig & aConfig );
	CY_COM_LIB_API CyResult Initialize( const unsigned long aMode, const CyAdapterID& aDeviceID );
	CY_COM_LIB_API CyResult Initialize( const CyDevice & aDevice );
	CY_COM_LIB_API CyResult Initialize( const CyDeviceFinder::DeviceEntry & aInfo );
	CY_COM_LIB_API CyResult Initialize( const CySocketUDP & aSocket );

private:
    // Disabled
    CySocketUDP( const CySocketUDP& );
	const CySocketUDP & operator=( const CySocketUDP & aSocket );

// Accessors
public:
	bool IsBound( void ) const;
	bool IsConnected( void ) const;
	bool IsInitialized( void ) const;

	unsigned long GetAccessMode( void ) const;
	const CyAdapterID& GetAdapterID( void ) const;

// Methods
public:
	CY_COM_LIB_API int Bind( unsigned short aPort );
	CY_COM_LIB_API int CloseSocket( void );
	CY_COM_LIB_API int Connect( const Address * aName );
	CY_COM_LIB_API int Recv( char * aBuffer, int aLen, int aFlags );
	CY_COM_LIB_API int RecvFrom( char * aBuffer, int aLen, int aFlags, Address * aFrom );
	CY_COM_LIB_API int Send( const char * aBuffer, int aLen, int aFlags );
	CY_COM_LIB_API int SendTo( const char * aBuffer, int aLen, int aFlags, const Address * aTo );

// Data
private:
    struct CySocketUDPInternal* mInternal;
};
#endif // __cplusplus

#endif // _CY_SOCKET_UDP_H_
