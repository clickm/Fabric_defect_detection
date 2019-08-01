// *****************************************************************************
//
// $Id: CyVideoControllerExtension.h,v 1.5 2007/07/04 21:27:05 igors Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyVideoControllerExtension.h
//
// Description..: Defines the base of a camera class.
//
// *****************************************************************************

#ifndef __CY_VIDEO_CONTROLLER_EXTENSION_H__
#define __CY_VIDEO_CONTROLLER_EXTENSION_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include "CyErrorInterface.h"

// ===== This Project =====
#include "CyCamLib.h"
#include "CyGrabberExtension.h"


// class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyGrabber;
class CyVideoControllerExtension : public CyGrabberExtension
{
// types
public:


// construction / destruction
public:
    CY_CAM_LIB_API          CyVideoControllerExtension();
    CY_CAM_LIB_API          CyVideoControllerExtension( CyGrabber& aGrabber );
    CY_CAM_LIB_API virtual  ~CyVideoControllerExtension();


// Accessors
public:
    CY_CAM_LIB_API virtual CyResult SetData   ( unsigned char  aData );
    CY_CAM_LIB_API virtual CyResult GetData   ( unsigned char& aData ) const;

    CY_CAM_LIB_API virtual CyResult SetAddress( unsigned char  aAddress );
    CY_CAM_LIB_API virtual CyResult GetAddress( unsigned char& aAddress ) const;

    CY_CAM_LIB_API virtual CyResult SetVideoReset( bool  aEnable );
    CY_CAM_LIB_API virtual CyResult GetVideoReset( bool& aEnable ) const;

    CY_CAM_LIB_API virtual CyResult SetRead( bool  aEnable );
    CY_CAM_LIB_API virtual CyResult GetRead( bool& aEnable ) const;

    CY_CAM_LIB_API virtual CyResult SetWrite( bool  aEnable );
    CY_CAM_LIB_API virtual CyResult GetWrite( bool& aEnable ) const;


// Methods
public:
    CY_CAM_LIB_API virtual CyResult Load( CyGrabber& aGrabber );
    CY_CAM_LIB_API virtual CyResult Save( CyGrabber& aGrabber ) const;


// Members
private:
    unsigned char   mData;
    unsigned char   mAddress;
    bool            mVideoReset;
    bool            mRead;
    bool            mWrite;
};
#endif // __cplusplus

#endif // __CY_VIDEO_CONTROLLER_EXTENSION_H__
