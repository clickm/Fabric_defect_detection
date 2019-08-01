// *****************************************************************************
//
// $Id: CyCameraLink.h,v 1.18 2009/05/29 14:51:54 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraLink.h
//
// Description..: Defines the interface of a CameraLink camera.
//
// *****************************************************************************

#ifndef __CY_CAMERA_LINK_H__
#define __CY_CAMERA_LINK_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== This Project =====
#include "CyCamLib.h"
#include "CyCameraInterface.h"
#include "CyCameraLinkExtension.h"
#include "CyCameraRegistry.h"

// Class CyCameraLink
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyCameraLinkInternal;
class CyCameraLink : public CyCameraInterface
{
// Types
public:
    enum SerialSelect
    {
        SS_UNUSED,
        SS_UART0,
    };
    typedef CY_UINT32 SerialSelectFunction;

// Construction / Destruction
protected:
    CY_CAM_LIB_API            CyCameraLink( CyGrabber* aGrabber );
    CY_CAM_LIB_API virtual    ~CyCameraLink();

// For derived classes
    CY_CAM_LIB_API            CyCameraLink( CyGrabber*                  aGrabber,
                                            const CyCameraLimits&       aLimits );
    // Deprecated
    CY_CAM_LIB_API            CyCameraLink( CyGrabber*                  aGrabber,
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
                                            bool                        aShowFreeFormTab,
                                            unsigned char               aFVALFunctionSelect = 0,
                                            bool                        aCanChangeFVALFunctionSelect = true,
                                            unsigned char               aLVALFunctionSelect = 0,
                                            bool                        aCanChangeLVALFunctionSelect = true );



// Properties
public:
    // Deprecated - These function use the Camera Link extension on the grabber object
    CY_CAM_LIB_API virtual CyResult SetDataValidEnabled ( bool  aEnable );
    CY_CAM_LIB_API virtual CyResult GetDataValidEnabled ( bool& aEnable ) const;
    CY_CAM_LIB_API virtual CyResult SetSerialSelectFunction ( SerialSelectFunction  aFunction );
    CY_CAM_LIB_API virtual CyResult GetSerialSelectFunction ( SerialSelectFunction& aFunction ) const;
    CY_CAM_LIB_API virtual CyResult SetDataValidPolarity( bool  aLow );
    CY_CAM_LIB_API virtual CyResult GetDataValidPolarity( bool& aLow ) const;
    CY_CAM_LIB_API virtual CyResult SetLineValidPolarity( bool  aLow );
    CY_CAM_LIB_API virtual CyResult GetLineValidPolarity( bool& aLow ) const;
    CY_CAM_LIB_API virtual CyResult SetFrameValidPolarity( bool  aLow );
    CY_CAM_LIB_API virtual CyResult GetFrameValidPolarity( bool& aLow ) const;
    CY_CAM_LIB_API virtual CyResult SetLineValidEdgeSensitive( bool  aEnabled );
    CY_CAM_LIB_API virtual CyResult GetLineValidEdgeSensitive( bool& aEnabled ) const;
    CY_CAM_LIB_API virtual CyResult SetFrameValidEdgeSensitive( bool  aEnabled );
    CY_CAM_LIB_API virtual CyResult GetFrameValidEdgeSensitive( bool& aEnabled ) const;
    CY_CAM_LIB_API virtual CyResult SetFrameValidFunctionSelect( unsigned char  aFunction );
    CY_CAM_LIB_API virtual CyResult GetFrameValidFunctionSelect( unsigned char& aFunction ) const;
    CY_CAM_LIB_API virtual CyResult SetLineValidFunctionSelect( unsigned char  aFunction );
    CY_CAM_LIB_API virtual CyResult GetLineValidFunctionSelect( unsigned char& aFunction ) const;
    CY_CAM_LIB_API virtual CyResult GetClockPresence( bool & aPresent, bool aRecheck ) const;

    // Support of extra parameters
    CY_CAM_LIB_API virtual CyResult SetParameter     ( const CyString& aName,
                                                       unsigned char   aValue );
    CY_CAM_LIB_API virtual CyResult SetParameter     ( const CyString& aName,
                                                       bool            aValue );
    CY_CAM_LIB_API virtual CyResult GetParameter     ( const CyString& aName,
                                                       unsigned char&  aValue ) const;
    CY_CAM_LIB_API virtual CyResult GetParameter     ( const CyString& aName,
                                                       bool&           aValue ) const;

// Returns the list of module IDs and sub-IDs that support Camera Link
    CY_CAM_LIB_API static  CyResult CY_CALLING_CONV GetSupportedModules( CyCameraRegistry::CameraIDList& aList );


// members
private:
    friend struct CyCameraLinkCreator;
    friend class CyCameraLinkPage;
    friend class CameraLink;
    struct CyCameraLinkInternal* mInternal;
};
#endif // __cplusplus

#endif // __CY_CAMERA_LINK_H__
