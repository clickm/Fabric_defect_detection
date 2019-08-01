// *****************************************************************************
//
// $Id: CyCameraRegistry.h,v 1.20 2007/12/07 15:50:05 jwhitwill Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraRegistry.h
//
// Description..: Registry of cameras installed on the system
//
// *****************************************************************************

#ifndef __CY_CAMERA_REGISTRY_H__
#define __CY_CAMERA_REGISTRY_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include "CyErrorInterface.h"

// ===== This Project =====
#include "CyTypes.h"
#include "CyCamLib.h"
#include "CyCamLibCDef.h"
#include "CyGrabber.h"
#include "CyCameraInterface.h"

// ===== External =====
#include <CyString.h>


// Types
/////////////////////////////////////////////////////////////////////////////

typedef unsigned long CyCameraID;


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyCameraCreator
{
public:
    CY_CAM_LIB_API virtual ~CyCameraCreator();
    virtual CyCameraInterface* Create( CyGrabber* aGrabber ) const = 0;
};

struct CyCameraRegistryInternal;
class CyCameraRegistry : public CyErrorInterface
{
// types
public:
    typedef CyCameraID CameraID;

    struct CameraIDListInternal;
    class CameraIDList
    {
        public:
            CY_CAM_LIB_API CameraIDList();
            CY_CAM_LIB_API ~CameraIDList();

            CY_CAM_LIB_API void clear();
            CY_CAM_LIB_API void push_back( CameraID aID );

        private:
            friend class CyCameraRegistry;
            CameraIDListInternal* mInternal;
    };

// construction / destruction
public:
    CY_CAM_LIB_API      CyCameraRegistry();
    CY_CAM_LIB_API      ~CyCameraRegistry();

public:
    // creates a camera id from the module and sub-module IDs
    static CY_CAM_LIB_API
        CameraID CY_CALLING_CONV GetCameraID   ( unsigned char aModuleID,
                                                 unsigned char aSubModuleID );

    // Displays the camera selection dialog
    CY_CAM_LIB_API
        CyResult SelectCamera( void*    aParent = 0,
                               CameraID aID = 0 );
    
    // Find camera based on camera information
    CY_CAM_LIB_API
        unsigned long
                 CountCameras   ( ) const;
    CY_CAM_LIB_API
        unsigned long
                 CountCameras   ( CameraID aID ) const;
    CY_CAM_LIB_API
        unsigned long
                 CountCameras   ( const CyString& aName ) const;
    CY_CAM_LIB_API
        CyResult FindCamera     ( CameraID aID );
    CY_CAM_LIB_API
        CyResult FindCamera     ( const CyString& aName );
    CY_CAM_LIB_API  
        CyResult FindNextCamera ( CameraID aID );
    CY_CAM_LIB_API
        CyResult FindNextCamera ( const CyString& aName );

    // Parsing all cameras
    CY_CAM_LIB_API
        CyResult GotoFirstCamera       ( );
    CY_CAM_LIB_API
        CyResult GotoNextCamera        ( );

    // Information about the current found camera 
    CY_CAM_LIB_API
        CyResult GetName        ( CyString& aName ) const;
    CY_CAM_LIB_API
        CyResult GetCompanyName ( CyString& aName ) const;
    CY_CAM_LIB_API
        CyResult GetID          ( CameraID& aID ) const;
    CY_CAM_LIB_API
        CyResult GetModuleID    ( unsigned char& aID ) const;
    CY_CAM_LIB_API
        CyResult GetSubModuleID ( unsigned char& aID ) const;


    // Create a camera from the currently found entry
    CY_CAM_LIB_API
        CyResult CreateCamera   ( CyCameraInterface** aCamera,
                                  CyGrabber*          aGrabber ) const;
    CY_CAM_LIB_API
        CyResult CreateCamera   ( const CyString&  aName,
                                  CyCameraInterface** aCamera,
                                  CyGrabber*          aGrabber );
    CY_CAM_LIB_API
        CyResult DestroyCamera( CyCameraInterface* aCamera );


// methods to add a camera to the registry
    static CY_CAM_LIB_API
        CyResult CY_CALLING_CONV AddCamera   ( const CameraID     aID,
                                               const CyString&    aName,
                                               CyCameraCreator*   aCreator,
                                               int                aVendorID = -1 );
    static CY_CAM_LIB_API
        CyResult CY_CALLING_CONV AddCamera   ( const CameraID     aID,
                                               const CyString&    aName,
                                               const CyString&    aCompany,
                                               CyCameraCreator*   aCreator,
                                               int                aVendorID = -1);

    static CY_CAM_LIB_API
        CyResult CY_CALLING_CONV AddCamera   ( const CameraIDList& aIDList,
                                               const CyString& aName,
                                               CyCameraCreator*   aCreator,
                                               int                aVendorID = -1);
    static CY_CAM_LIB_API
        CyResult CY_CALLING_CONV AddCamera   ( const CameraIDList& aIDList,
                                               const CyString&     aName,
                                               const CyString&     aCompany,
                                               CyCameraCreator*    aCreator,
                                               int                aVendorID = -1 );

    static CY_CAM_LIB_API
        CyResult CY_CALLING_CONV RemoveCamera( const CyCameraCreator* aCreator );


// Members
private:
    struct CyCameraRegistryInternal* mInternal;
};
#endif // __cplusplus

// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction/Destruction
CY_CAM_LIB_C_API( CyCameraRegistryH ) CyCameraRegistry_Init   ();
CY_CAM_LIB_C_API( void )              CyCameraRegistry_Destroy( CyCameraRegistryH aHandle );

// Functions
CY_CAM_LIB_C_API( CyCameraID )     CyCameraRegistry_GetCameraID            ( CyCameraRegistryH aHandle,
                                                                             unsigned char     aModuleID,
                                                                             unsigned char     aSubModuleID );
                                                                        
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_SelectCamera           ( CyCameraRegistryH   aHandle,
                                                                             void*               aParent, 
                                                                             CyCameraID          aID );
CY_CAM_LIB_C_API( unsigned long )  CyCameraRegistry_CountCameras           ( CyCameraRegistryH   aHandle );
CY_CAM_LIB_C_API( unsigned long )  CyCameraRegistry_CountCamerasByID       ( CyCameraRegistryH   aHandle,
                                                                             CyCameraID          aID );
CY_CAM_LIB_C_API( unsigned long )  CyCameraRegistry_CountCamerasByName     ( CyCameraRegistryH   aHandle,
                                                                             const char*         aName );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_FindCameraByID         ( CyCameraRegistryH   aHandle,
                                                                             CyCameraID          aID );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_FindCameraByName       ( CyCameraRegistryH   aHandle,
                                                                             const char*         aName );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_FindNextCameraByID     ( CyCameraRegistryH   aHandle,
                                                                             CyCameraID          aID );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_FindNextCameraByName   ( CyCameraRegistryH   aHandle,
                                                                             const char*         aName );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_GotoFirstCamera        ( CyCameraRegistryH   aHandle );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_GotoNextCamera         ( CyCameraRegistryH   aHandle );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_GetName                ( CyCameraRegistryH   aHandle,
                                                                             char*               aBuffer,
                                                                             unsigned long       aBufferSize );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_GetCompanyName         ( CyCameraRegistryH   aHandle,
                                                                             char*               aBuffer,
                                                                             unsigned long       aBufferSize );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_GetID                  ( CyCameraRegistryH   aHandle,
                                                                             CyCameraID*         aID );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_GetModuleID            ( CyCameraRegistryH   aHandle,
                                                                             unsigned char*      aID );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_GetSubModuleID         ( CyCameraRegistryH   aHandle,
                                                                             unsigned char*      aID );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_CreateCamera           ( CyCameraRegistryH   aHandle,
                                                                             CyCameraInterfaceH* aCamera,
                                                                             CyGrabberH          aGrabber );
CY_CAM_LIB_C_API( CyResult )       CyCameraRegistry_CreateCameraEx         ( CyCameraRegistryH   aHandle,
                                                                             const char*         aName,
                                                                             CyCameraInterfaceH* aCamera,
                                                                             CyGrabberH          aGrabber );

#endif  // __CY_CAMERA_INTERFACE_H__
