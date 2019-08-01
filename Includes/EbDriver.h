// *****************************************************************************
//
//     Copyright (c) 2008, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: EbDriver.h
//
// *****************************************************************************

#ifndef __EBDRIVER_H__
#define __EBDRIVER_H__

#include <PtTypes.h>
#include <PtString.h>
#include <EbSetupLib.h>
#include <EbDriverNames.h>

namespace EbSetupLib
{
    class PackageInfo;
};



class EB_SETUP_LIB_API EbDriver
{
public:
    PtString GetName() const;
    PtString GetDisplayName() const;
    PtString GetDescription() const;
    PtString GetAvailableVersion() const;
    PtString GetInstalledVersion() const;

protected:

    EbDriver();
    ~EbDriver();

    EbSetupLib::PackageInfo* mThis;
};


#endif //__EBDRIVER_H__
