// *****************************************************************************
//
// $Id: CyGrabberExtension.h,v 1.17 2007/11/13 13:42:04 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrabberExtension.h
//
// Description..: Defines the base of a camera class.
//
// *****************************************************************************

#ifndef __CY_GRABBER_EXTENSION_H__
#define __CY_GRABBER_EXTENSION_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include "CyPersistentRepository.h"

// ===== CyComLib =====
#include <CyChannel.h>

// ===== This Project =====
#include "CyCamLib.h"
#include "CyCamLibCDef.h"

// ===== External =====
#include <CyString.h>


// Forward-Declaration
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyGrabber;
#endif // __cplusplus


// class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyGrabberExtensionInternal;
class CyGrabberExtension : public CyPersistentRepository
{
// construction / destruction
public:
    CY_CAM_LIB_API          CyGrabberExtension( CyGrabber&      aGrabber,
                                                const CyString& aName,
                                                unsigned long   aID,
                                                unsigned long   aType,
                                                CyChannelID     aChannelID = 0 );
    CY_CAM_LIB_API virtual  ~CyGrabberExtension();

protected:
    CY_CAM_LIB_API CyResult PostContruct();

// Accessors
public:
    // Returns the type of extension
    CY_CAM_LIB_API virtual unsigned long GetType() const;

    // Returns the grabber to which the extension is associated
    CY_CAM_LIB_API virtual CyGrabber& GetGrabber() const;
    CY_CAM_LIB_API virtual CyResult   SetGrabber( CyGrabber* aGrabber );

    // Resets the extension
    CY_CAM_LIB_API virtual CyResult Reset();

// Methods
public:

    // Load/Save settings from/to the grabber object
    CY_CAM_LIB_API virtual CyResult LoadFromGrabber();
    CY_CAM_LIB_API virtual CyResult SaveToGrabber() const;

    // Loads from XML: makes sure that the XML document is from this version
    // if not invokes the old LoadFromXML_214 version
    CY_CAM_LIB_API virtual CyResult LoadFromXML( CyXMLDocument& aDocument );

protected:
    // NOTE: all the parameter will be accesible through Set/GetParameter from
    // the parent class CyParameterRepository.  These parameter will NOT be 
    // applied to the device until the caller uses the Save method:  

    CY_CAM_LIB_API virtual CyResult ApplyChanges();

    CY_CAM_LIB_API virtual CyResult LoadFromXML_214( CyXMLDocument& aDocument );


    // Display and handle property page
    CY_CAM_LIB_API virtual CyResult OnApply          ( void* aPropertyPage );

    CY_CAM_LIB_API unsigned short GetAddressOffset() const;

private:
    struct CyGrabberExtensionInternal* mInternal;
};

// For backward compatibility
#define CyExtension CyGrabberExtension
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction - Destruction - Extensions are obtained through CyGrabber and must not be
// deleted by the user.
// Note: All the CyParameterRepository_XXX and CyPersistentRepository_XXX functions are
// available on the grabber extensions.

CY_CAM_LIB_C_API( unsigned long ) CyGrabberExtension_GetType( CyGrabberExtensionH aHandle );
CY_CAM_LIB_C_API( CyGrabberH )    CyGrabberExtension_GetGrabber( CyGrabberExtensionH aHandle );
CY_CAM_LIB_C_API( CyResult )      CyGrabberExtension_LoadFromGrabber( CyGrabberExtensionH aHandle);
CY_CAM_LIB_C_API( CyResult )      CyGrabberExtension_SaveToGrabber  ( CyGrabberExtensionH aHandle );

#endif // __CY_GRABBER_EXTENSION_H__

