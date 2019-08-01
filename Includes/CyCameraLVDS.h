// *****************************************************************************
//
// $Id: CyCameraLVDS.h,v 1.11 2007/07/04 21:27:05 igors Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraLVDS.h
//
// Description..: Defines the interface of a LVDS camera.
//
// *****************************************************************************

#ifndef __CY_CAMERA_LVDS_H__
#define __CY_CAMERA_LVDS_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== This Project =====
#include "CyCamLib.h"
#include "CyCameraLink.h"


// Class CyCameraLink
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyCameraLVDS : public CyCameraLink
{
// Construction / Destruction
protected:
    CY_CAM_LIB_API            CyCameraLVDS( CyGrabber* aGrabber );
    CY_CAM_LIB_API virtual    ~CyCameraLVDS();

// For derived classes
    CY_CAM_LIB_API            CyCameraLVDS( CyGrabber*                  aGrabber,
                                            const CyCameraLimits&       aLimits );

    // Deprecated
    CY_CAM_LIB_API            CyCameraLVDS( CyGrabber*                  aGrabber,
                                            const CyCameraLimits&       aLimits,
                                            bool                        aDataValidEnabled,
                                            bool                        aCanChangeDataValid,
                                            const SerialSelectFunction& aSSF,
                                            bool                        aCanChangeSerialSelectFunction,
                                            bool                        aDVALPolarity,
                                            bool                        aCanChangeDVALPolarity,
                                            bool                        aLVALPolarity,
                                            bool                        aCanChangeLVALPolarity,
                                            bool                        aFVALPolarity,
                                            bool                        aCanChangeFVALPolarity,
                                            bool                        aLVALEdgeSensitve,
                                            bool                        aCanChangeLVALSensitive,
                                            bool                        aFVALEdgeSensitve,
                                            bool                        aCanChangeFVALSensitive,
                                            bool                        aShowFreeFormTab );

// LVDS Specific parameters
public:
    // Deprecated - These function use the Camera LVDS extension on the grabber object
    CY_CAM_LIB_API virtual CyResult SetGPIOOutputEnabled( bool  aEnabled );
    CY_CAM_LIB_API virtual CyResult GetGPIOOutputEnabled( bool& aEnabled ) const;


// Support of extra parameters
public:
    CY_CAM_LIB_API virtual CyResult SetParameter     ( const CyString& aName,
                                                       unsigned char      aValue );
    CY_CAM_LIB_API virtual CyResult SetParameter     ( const CyString& aName,
                                                       bool               aValue );
    CY_CAM_LIB_API virtual CyResult GetParameter     ( const CyString& aName,
                                                       unsigned char&     aValue ) const;
    CY_CAM_LIB_API virtual CyResult GetParameter     ( const CyString& aName,
                                                       bool&              aValue ) const;


// Returns the list of module IDs and sub-IDs that support Camera Link
public:
    // For RS644
    CY_CAM_LIB_API static  CyResult CY_CALLING_CONV GetSupportedModules( CyCameraRegistry::CameraIDList& aList );

    // For RS422 version
    CY_CAM_LIB_API static  CyResult CY_CALLING_CONV GetSupportedModulesRS422( CyCameraRegistry::CameraIDList& aList );

    friend struct CyCameraLVDSCreator;
};
#endif // __cplusplus

#endif //__CY_CAMERA_LVDS_H__
