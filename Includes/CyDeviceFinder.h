// *****************************************************************************
//
// $Id: CyDeviceFinder.h,v 1.40 2009/05/29 14:46:14 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyDeviceFinder.h
//
// Description..: Utility class that searches for devices on the network, either
//                by UDP or Driver                
//
// *****************************************************************************

#ifndef _CY_DEVICE_FINDER_H_
#define _CY_DEVICE_FINDER_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

#include <CyTypes.h>
#include <CyErrorInterface.h>
#include "CyComLib.h"
#include "CyComLibCDef.h"
#include "CyConfig.h"
#include "CyAdapterID.h"
#include <CyString.h>

// Class
/////////////////////////////////////////////////////////////////////////////

// Device Entry used for the C wrapping functions
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

struct CyDeviceEntry
// This is not working with the CWrapper
//#ifdef __cplusplus
//   : public CyObject
//#endif
{
    // Device Identification
    char          mDeviceName[ 256 ];
    char          mModelName[ 256 ];
    char          mManufacturerName[ 256 ];
    char          mSerialNumber[ 256 ];
    char          mDeviceInformation[ 256 ];
    char          mDeviceVersion[ 256 ];
    CY_UINT8      mDeviceID;
    CY_UINT8      mModuleID;
    CY_UINT8      mSubID;
    CY_UINT8      mVendorID;
    CY_UINT8      mSoftVerMaj;
    CY_UINT8      mSoftVerMin;
    CY_UINT8      mSoftVerSub;

    // Networking
    CY_UINT32     mMode;     // access mode
    CY_UINT8      mProtocolVerMaj;
    CY_UINT8      mProtocolVerMin;
    char          mAdapterID [ 256 ];
    char          mAddressIP [ 256 ];
    char          mSubnetMask[ 256 ];
    char          mGateway   [ 256 ];
    char          mAddressMAC[ 256 ];

    // Data Information
    char          mMulticastAddress[ 256 ];
    CY_UINT8      mChannelCount;
    CY_UINT32     mSendingMode; // CY_DEVICE_DSM_XXX
    
};

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


// Finder callback function for the C Wrapping functions
typedef int (CY_CALLING_CONV * CyDeviceFinderCallback )( struct CyDeviceEntry* aDevice,
                                                         void*                 aContext );


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
    class CyDeviceFinder : public CyErrorInterface
{
// Types
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

    // Data for an entry
    struct DeviceEntry
    {
        // Device Identification
        CyString             mDeviceName;
        CyString             mModelName;
        CyString             mManufacturerName;
        CyString             mSerialNumber;
        CyString             mDeviceInformation;
        CyString             mDeviceVersion;
        CY_UINT8             mDeviceID;
        CY_UINT8             mModuleID;
        CY_UINT8             mSubID;
        CY_UINT8             mVendorID;
        CY_UINT8             mSoftVerMaj;
        CY_UINT8             mSoftVerMin;
        CY_UINT8             mSoftVerSub;

        // Networking
        CY_UINT32            mMode;
        CY_UINT8             mProtocolVerMaj;
        CY_UINT8             mProtocolVerMin;
        CyAdapterID          mAdapterID;
        CyString             mAddressIP;
        CyString             mSubnetMask;
        CyString             mGateway;
        CyString             mAddressMAC;

        // Data Information
        CyString             mMulticastAddress;
        CY_UINT8             mChannelCount;
        CY_UINT32            mSendingMode; // CY_DEVICE_DSM_XXX
        

        CY_COM_LIB_API DeviceEntry();
        CY_COM_LIB_API DeviceEntry( const DeviceEntry& aEntry );
        CY_COM_LIB_API DeviceEntry& operator=( const DeviceEntry& aEntry );
        CY_COM_LIB_API bool operator==( const DeviceEntry& aEntry ) const;
    };
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


    // List of entries found
    struct DeviceListInternal;
    class CY_COM_LIB_API DeviceList : public CyObject
    {
        // Iterator
        public:
            struct IteratorInternal;
            class CY_COM_LIB_API Iterator : public CyObject
            {
                public:
                    typedef DeviceEntry value_type;
                    typedef value_type& reference;
                    typedef value_type* pointer;
                    Iterator();
                    Iterator( const Iterator& aItr );
                    ~Iterator();
                    const Iterator& operator=( const Iterator& aItr ) const;

                    reference operator*() const;
                    Iterator& operator++();
                    Iterator  operator++(int);
                    const Iterator& operator++() const;
                    const Iterator  operator++(int) const;

                    bool operator==( const Iterator& aItr ) const;
                    bool operator!=( const Iterator& aItr ) const;
                    bool operator<( const Iterator& aItr ) const;

                private:
                    friend class DeviceList;
                    struct IteratorInternal* mInternal;
            };


        // types
            typedef Iterator iterator;
            typedef const Iterator const_iterator;


        // Construction/Destruction
        public:
            DeviceList();
            ~DeviceList();

        // clear the list
            void clear();

        // Iterating the list
            iterator begin();
            iterator end();
            const_iterator begin() const;
            const_iterator end() const;

        // entry access
            bool empty() const;
            unsigned long size() const;
            const DeviceEntry& operator[]( int aIndex ) const;

        // Entry addition
            void push_back( const DeviceEntry& aEntry );

        private:
            friend class CyDeviceFinder;
            struct DeviceListInternal* mInternal;
    };

    // Callback when a device is found
    typedef bool (CY_CALLING_CONV * Callback )( const DeviceEntry&   aDevice,
                                                void*                aContext );

// Construction/Destruction
public:
    CY_COM_LIB_API CyDeviceFinder( );
    CY_COM_LIB_API virtual ~CyDeviceFinder();


// Select a device, using a user interface
public:
    CY_COM_LIB_API virtual  CyResult SelectDevice( DeviceEntry& aEntry,
                                                   void*        aParent = NULL,
                                                   const char*  aTitle = NULL );

    CY_COM_LIB_API virtual  CyResult SelectDevice( DeviceEntry& aEntry,
                                                   Callback     aCallback,
                                                   void*        aContext,
                                                   void*        aParent = NULL,
                                                   const char*  aTitle = NULL );


// methods
public:

    // Find the devices
    CY_COM_LIB_API virtual  CyResult Find( unsigned long        aAccessMode,
                                           DeviceList&          aList,
                                           unsigned int         aTimeOut,
                                           bool                 aFlushList,
                                           Callback             aCallback = 0,
                                           void*                aContext = 0 ) const;

    // Apply an IP to a device
    CY_COM_LIB_API virtual  CyResult SetIP( unsigned long        aAccessMode,
                                            const CyAdapterID&   aAdapterID,
                                            const CyString&      aMAC,
                                            unsigned long        aIP,
                                            unsigned long        aSubnetMask = 0,
                                            unsigned long        aGateway  = 0 ) const;
    CY_COM_LIB_API virtual  CyResult SetIP( unsigned long        aAccessMode,
                                            const CyAdapterID&   aAdapterID,
                                            const CyString&      aMAC,
                                            const CyString&      aIP,
                                            const CyString&      aSubnetMask = CyString(),
                                            const CyString&      aGateway  = CyString() ) const;

    // Give a local device name to a device based on MAC address
    CY_COM_LIB_API virtual  CyResult SetName( const CyString& aMAC,
                                              const CyString& aName ) const;
    CY_COM_LIB_API virtual  CyResult GetName( const CyString& aMAC,
                                              CyString&       aName ) const;

private:
    friend struct CyDeviceFinderInternal;
    struct CyDeviceFinderInternal* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Constructor/Destructor
CY_COM_LIB_C_API( CyDeviceFinderH ) CyDeviceFinder_Init();
CY_COM_LIB_C_API( void ) CyDeviceFinder_Destroy( CyDeviceFinderH aHandle );

// Select a device using the built-in UI.  The aParent is used as a HWND internally on Windows
CY_COM_LIB_C_API( CyResult ) CyDeviceFinder_SelectDevice( CyDeviceFinderH        aHandle,
                                                          struct CyDeviceEntry*  aEntry,
                                                          void*                  aParent );

// Find available devices and invokes the specified callback for each item that is found
CY_COM_LIB_C_API( CyResult ) CyDeviceFinder_Find( CyDeviceFinderH        aHandle,
                                                  unsigned long          aAccessMode,
                                                  unsigned int           aTimeOut,
                                                  CyDeviceFinderCallback aCallback,
                                                  void*                  aContext );

// Changes the IP of a device
CY_COM_LIB_C_API( CyResult ) CyDeviceFinder_SetIP  ( CyDeviceFinderH  aHandle,
                                                     unsigned long    aAccessMode,
                                                     CyAdapterIDH     aAdapterID,
                                                     const char*      aMAC,
                                                     const char*      aIP,
                                                     const char*      aSubnetMask,
                                                     const char*      aGateway );

// Changes or gets the name of a device
CY_COM_LIB_C_API( CyResult ) CyDeviceFinder_SetName( CyDeviceFinderH  aHandle,
                                                     const char*      aMAC,
                                                     const char*      aName );
CY_COM_LIB_C_API( CyResult ) CyDeviceFinder_GetName( CyDeviceFinderH  aHandle,
                                                     const char*      aMAC,
                                                     char*            aBuffer,
                                                     unsigned long    aBufferSize );
#endif
