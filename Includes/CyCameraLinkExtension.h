// *****************************************************************************
//
// $Id: CyCameraLinkExtension.h,v 1.16 2009/05/29 14:51:55 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraLinkExtension.h
//
// Description..: Defines the base of a camera class.
//
// *****************************************************************************

#ifndef __CY_CAMERA_LINK_EXTENSION_H__
#define __CY_CAMERA_LINK_EXTENSION_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include "CyErrorInterface.h"

// ===== CyComLib =====
#include <CyChannel.h>

// ===== This Project =====
#include "CyCamLib.h"
#include "CyGrabberExtension.h"
#include "CyGrabberExtensionConstants.h"


// class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyCameraLinkExtensionInternal;
class CyCameraLinkExtension : public CyGrabberExtension
{
#ifndef CY_CAMERALINK_EXTENSION_NO_BACKWARD_COMPATIBILITY
#include "CyCameraLinkExtensionBackwardCompatibility.h"
#endif // CY_CAMERALINK_EXTENSION_NO_BACKWARD_COMPATIBILITY

    // construction / destruction
public:
    CY_CAM_LIB_API          CyCameraLinkExtension( CyGrabber&     aGrabber,
                                                   unsigned short aIndex,
                                                   CyChannelID    aChannelID,
                                                   unsigned char  aModuleID );
    CY_CAM_LIB_API virtual  ~CyCameraLinkExtension();

    // Deprecated - for backward compatibility
    CY_CAM_LIB_API          CyCameraLinkExtension();

// Methods
public:
    CY_CAM_LIB_API virtual CyResult LoadFromGrabber();
    CY_CAM_LIB_API virtual CyResult SaveToGrabber() const;

    // Deprecated - for backward compatibility
    CY_CAM_LIB_API virtual CyResult Load( CyGrabber& aGrabber );
    CY_CAM_LIB_API virtual CyResult Save( CyGrabber& aGrabber ) const;

    // Load from the a XML
    CY_CAM_LIB_API virtual CyResult LoadFromXML_214( CyXMLDocument& aDocument );

protected:
    CY_CAM_LIB_API virtual CyResult OnParameterSet( unsigned long   aParameterIndex,
                                                    unsigned long   aParameterID,
                                                    const CyString& aParameterName,
                                                    bool            aTest,
                                                    const CyString& aValueS,
                                                    CY_INT64        aValueI,
                                                    double          aValueD );
    CY_CAM_LIB_API virtual CyResult OnParameterGet( unsigned long   aParameterIndex,
                                                    unsigned long   aParameterID,
                                                    const CyString& aParameterName  );

private:
    struct CyCameraLinkExtensionInternal* mInternal;
};
#endif // cplusplus

#endif // __CY_CAMERA_LINK_EXTENSION_H__
