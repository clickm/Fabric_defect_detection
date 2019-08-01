// *****************************************************************************
//
// $Id: CyAdapterID.h,v 1.17 2007/11/13 13:42:01 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2004, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyAdapterID.h
//
// Description..: Adapter Identifier.  Uses to select which adapter to use when
//                connecting or using a device.
//
// *****************************************************************************

#ifndef _CY_ADAPTER_ID_
#define _CY_ADAPTER_ID_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== This project =====
#include "CyComLib.h"
#include "CyComLibCDef.h"
#include "CyDeviceConstants.h"

// ===== Miscellaneous =====
#include <CyString.h>


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyAdapterIDInternal;
class CyAdapterID : public CyObject
{
// Constructor / Destructor
public:
    CY_COM_LIB_API CyAdapterID();
    CY_COM_LIB_API CyAdapterID( const CyAdapterID& aID );
    CY_COM_LIB_API CyAdapterID( unsigned char      aID1,
                                unsigned char      aID2,
                                unsigned char      aID3,
                                unsigned char      aID4,
                                unsigned char      aID5,
                                unsigned char      aID6 );
    CY_COM_LIB_API CyAdapterID( const CyString& aID );
    CY_COM_LIB_API ~CyAdapterID();

    // indicates if the adapter ID is valid or not
    CY_COM_LIB_API bool IsValid() const;

// copy operator
    CY_COM_LIB_API CyAdapterID& operator=( const CyAdapterID& aID );
    CY_COM_LIB_API CyAdapterID& operator=( const CyString& aID );

// comparison operators
    CY_COM_LIB_API int  Compare   ( const CyAdapterID& aID ) const;
    CY_COM_LIB_API bool operator==( const CyAdapterID& aID ) const;
    CY_COM_LIB_API bool operator!=( const CyAdapterID& aID ) const;
    CY_COM_LIB_API bool operator< ( const CyAdapterID& aID ) const;
    CY_COM_LIB_API bool operator<=( const CyAdapterID& aID ) const;
    CY_COM_LIB_API bool operator> ( const CyAdapterID& aID ) const;
    CY_COM_LIB_API bool operator>=( const CyAdapterID& aID ) const;

    CY_COM_LIB_API bool operator==( const CyString& aID ) const;
    CY_COM_LIB_API bool operator!=( const CyString& aID ) const;
    CY_COM_LIB_API bool operator< ( const CyString& aID ) const;
    CY_COM_LIB_API bool operator<=( const CyString& aID ) const;
    CY_COM_LIB_API bool operator> ( const CyString& aID ) const;
    CY_COM_LIB_API bool operator>=( const CyString& aID ) const;

// Accessors
    CY_COM_LIB_API const CyString& GetIdentifier() const;
    CY_COM_LIB_API unsigned char   GetIdentifier( unsigned int aIndex ) const;

// Utilities
    // Enumerate the adapter for any given access mode.
    CY_COM_LIB_API static bool CY_CALLING_CONV 
                                   GetIdentifier( unsigned long  aMode, // CY_DEVICE_ACCESS_MODE_xxx in CyDeviceConstants
                                                  unsigned long  aIndex,
                                                  CyAdapterID&   aID );

    // Returns the IP of an adapter, based on index or ID
    CY_COM_LIB_API static bool CY_CALLING_CONV 
                                   GetAdapterIP( unsigned long      aMode, // CY_DEVICE_ACCESS_MODE_xxx in CyDeviceConstants
                                                 unsigned long      aIndex,
                                                 CyString&          aIP );
    CY_COM_LIB_API static bool CY_CALLING_CONV 
                                   GetAdapterIP( unsigned long      aMode, // CY_DEVICE_ACCESS_MODE_xxx in CyDeviceConstants
                                                 const CyAdapterID& aID,
                                                 CyString&          aIP );

    // Returns the Netmask of an adapter, based on index or ID
    CY_COM_LIB_API static bool CY_CALLING_CONV 
                                   GetAdapterSubnetMask( unsigned long      aMode, // CY_DEVICE_ACCESS_MODE_xxx in CyDeviceConstants
                                                         unsigned long      aIndex,
                                                         CyString&          aNetMask );
    CY_COM_LIB_API static bool CY_CALLING_CONV 
                                   GetAdapterSubnetMask( unsigned long      aMode, // CY_DEVICE_ACCESS_MODE_xxx in CyDeviceConstants
                                                         const CyAdapterID& aID,
                                                         CyString&          aNetMask );

private:
    struct CyAdapterIDInternal* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction/Destruction
CY_COM_LIB_C_API( CyAdapterIDH ) CyAdapterID_Init   ();
CY_COM_LIB_C_API( CyAdapterIDH ) CyAdapterID_Init2  ( CyAdapterIDH  aID );
CY_COM_LIB_C_API( CyAdapterIDH ) CyAdapterID_Init3  ( unsigned char aID1,
                                                      unsigned char aID2,
                                                      unsigned char aID3,
                                                      unsigned char aID4,
                                                      unsigned char aID5,
                                                      unsigned char aID6 );
CY_COM_LIB_C_API( CyAdapterIDH ) CyAdapterID_Init4  ( const char *  aID );
CY_COM_LIB_C_API( void )         CyAdapterID_Destroy( CyAdapterIDH aHandle );

CY_COM_LIB_C_API( int )          CyAdapterID_IsValid( CyAdapterIDH aHandle );

// Copy and compare functions
CY_COM_LIB_C_API( void ) CyAdapterID_Copy   ( CyAdapterIDH aHandle,
                                              CyAdapterIDH aID );
CY_COM_LIB_C_API( int )  CyAdapterID_Compare( CyAdapterIDH aHandle,
                                              CyAdapterIDH aID );

// returns the identifier: as string or individual items
CY_COM_LIB_C_API( const char* )   CyAdapterID_GetIdentifier ( CyAdapterIDH aHandle );
CY_COM_LIB_C_API( unsigned char ) CyAdapterID_GetIdentifier2( CyAdapterIDH aHandle,
                                                              unsigned int aIndex );

// Enumerates the available adapters for a particular access mode
CY_COM_LIB_C_API( int ) CyAdapterID_Enumerate( unsigned long  aMode,
                                               unsigned long  aIndex,
                                               CyAdapterIDH   aID );

// Returns the IP Addresses of the adapters
CY_COM_LIB_C_API( int ) CyAdapterID_GetAdapterIP ( unsigned long  aMode,
                                                   unsigned long  aIndex,
                                                   char*          aBuffer,
                                                   unsigned long  aBufferSize );
CY_COM_LIB_C_API( int ) CyAdapterID_GetAdapterIP2( unsigned long  aMode,
                                                   CyAdapterIDH   aID,
                                                   char*          aBuffer,
                                                   unsigned long  aBufferSize );

// Enumerates the Net Masks of the adapters
CY_COM_LIB_C_API( int ) CyAdapterID_GetAdapterSubnetMask ( unsigned long  aMode,
                                                           unsigned long  aIndex,
                                                           char*          aBuffer,
                                                           unsigned long  aBufferSize );
CY_COM_LIB_C_API( int ) CyAdapterID_GetAdapterSubnetMask2( unsigned long  aMode,
                                                           CyAdapterIDH   aID,
                                                           char*          aBuffer,
                                                           unsigned long  aBufferSize );

#endif // _CY_ADAPTER_ID_



