// *****************************************************************************
//
//     Copyright (c) 2008, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: EbInstaller.h
//
// *****************************************************************************

#ifndef __EBINSTALLER_H__
#define __EBINSTALLER_H__

#include <EbSetupLib.h>

#include <PtResult.h>
#include <EbNetworkAdapter.h>

class EbInstallerEventSink;
class ProgressTranslator;
namespace EbSetupLib
{
    class Installer;
};

class EB_SETUP_LIB_API EbInstaller
{
public:

    const EbNetworkAdapter* GetNetworkAdapter(PtUInt32 aIndex) const;
    PtUInt32 GetNetworkAdapterCount() const;

    const EbDriver* GetDriver(PtUInt32 aIndex) const;
    PtUInt32 GetDriverCount() const;

    PtResult Initialize();

    PtResult Install( const EbNetworkAdapter* aNetworkAdapter, const EbDriver* aDriver );
    
    PtResult UninstallAll();
    
    PtResult UpdateAll();

    PtResult RegisterEventSink( EbInstallerEventSink *aEventSink );
    PtResult UnregisterEventSink( EbInstallerEventSink *aEventSink );

    bool IsRebootNeeded() const;

    EbInstaller();
    ~EbInstaller();

private:
    EbSetupLib::Installer* mThis;
    ProgressTranslator* mProgressTranslator;

};


class EbInstallerEventSink
{
public:
    virtual void OnUpdateProgress( PtUInt32 aProgress ) = 0;
    virtual void OnStatusMessage( PtString aMsg ) = 0;

};


#endif //__EBINSTALLER_H__