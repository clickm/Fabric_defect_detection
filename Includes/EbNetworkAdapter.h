// *****************************************************************************
//
//     Copyright (c) 2008, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: EbNetworkAdapter.h
//
// *****************************************************************************

#ifndef __EBNETWORKADAPTER_H__
#define __EBNETWORKADAPTER_H__

#include <EbSetupLib.h>

#include <PtTypes.h>
#include <EbDriver.h>

namespace EbSetupLib
{
    class AdapterInfo;
    class Installer;
};

class EbInstaller;

class EB_SETUP_LIB_API EbNetworkAdapter
{
public:
    PtString GetName() const;
    PtString GetMACAddress() const;
    const EbDriver* GetCurrentDriver() const;
    bool IsDriverSupported( const EbDriver* aDriver ) const;
    bool IsRebootNeeded() const;

protected:

    ~EbNetworkAdapter();
    EbNetworkAdapter();

    EbSetupLib::AdapterInfo* mThis;

};


#endif //__EBNETWORKADAPTER_H__