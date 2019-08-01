// *****************************************************************************
//
// $Id: CyDeviceList.h,v 1.11 2008/03/10 20:05:21 jwhitwill Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: Device.h
//
// Description..: List of opened devices, for use internally for sharing
//                Devices.
//
// *****************************************************************************

#ifndef _CY_DEVICE_LIST_
#define _CY_DEVICE_LIST_

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyComLib.h"
#include "CyDevice.h"
#include <CyString.h>

// Class  
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyDeviceList
{
    public:
    // Add / Remove devices from list.  Used only internally
        static CyResult CY_CALLING_CONV AddDevice( CyDevice& aDevice );
        static CyResult CY_CALLING_CONV RemoveDevice( CyDevice& aDevice );


    // Obtain a device index
        CY_COM_LIB_API static CyResult CY_CALLING_CONV FindDevice( CyDevice&       aDevice,
                                                                   unsigned short& aIndex );

    // returns the number of devices in the list
        CY_COM_LIB_API static unsigned short CY_CALLING_CONV GetDeviceCount();

    // Obtain a device from index
        CY_COM_LIB_API static CyDevice& CY_CALLING_CONV GetDevice( unsigned short aIndex );

    // Get information on a device, module and sub-module based on identifiers
        CY_COM_LIB_API static CyResult CY_CALLING_CONV 
                GetInformation( unsigned char  aDeviceID,
                                unsigned char  aModuleID,
                                unsigned char  aSubID,
                                CyString&      aDeviceDesc,
                                CyString&      aModuleDesc,
                                CyString&      aSubDesc,
                                unsigned long* aOnboardRAM = NULL );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

CY_COM_LIB_C_API( CyResult )       CyDeviceList_FindDevice     ( CyDeviceH       aDevice,
                                                                 unsigned short* aIndex );
CY_COM_LIB_C_API( unsigned short ) CyDeviceList_GetDeviceCount ();
CY_COM_LIB_C_API( CyDeviceH )      CyDeviceList_GetDevice      ( unsigned short aIndex );
CY_COM_LIB_C_API( CyResult )       CyDeviceList_GetInformation ( unsigned char  aDeviceID,
                                                                 unsigned char  aModuleID,
                                                                 unsigned char  aSubID,
                                                                 char*          aDeviceDesc,
                                                                 unsigned long  aDeviceDescSize,
                                                                 char*          aModuleDesc,
                                                                 unsigned long  aModuleDescSize,
                                                                 char*          aSubDesc,
                                                                 unsigned long  aSubDescSize,
                                                                 unsigned long* aOnboardRAM );

#endif // _CY_DEVICE_LIST_

