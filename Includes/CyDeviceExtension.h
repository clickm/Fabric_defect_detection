// *****************************************************************************
//
// $Id: CyDeviceExtension.h,v 1.13 2007/11/13 13:42:02 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyDeviceExtension.h
//
// Description..: Extension interface for CyDevice
//
// *****************************************************************************

#ifndef _CY_DEVICE_EXTENSION_H_
#define _CY_DEVICE_EXTENSION_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyPersistentRepository.h>
#include <CyXMLDocument.h>

// ===== This project =====
#include "CyComLib.h"
#include "CyComLibCDef.h"


// Forward Declaration
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyDevice;
#endif // __cplusplus


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyDeviceExtensionInternal;
class CyDeviceExtension : public CyPersistentRepository
{
// Constructor / Destruction
protected:
    CY_COM_LIB_API CyDeviceExtension( CyDevice&       aDevice,
                                      const CyString& aName,
                                      unsigned long   aID,
                                      unsigned long   aType );
    CY_COM_LIB_API CyResult PostContruct();
public:
    CY_COM_LIB_API virtual ~CyDeviceExtension() = 0;

// Accessors
public:
    // Returns the type of extension
    CY_COM_LIB_API virtual unsigned long   GetType() const;

    // Returns the device to which the extension is associated
    CY_COM_LIB_API virtual CyDevice&       GetDevice() const;

// Methods
public:
    // Loads from XML: makes sure that the XML document is from this version
    // if not invokes the old LoadFromXML_214 version
    CY_COM_LIB_API virtual CyResult LoadFromXML( CyXMLDocument& aDocument );

    // Load and save the settings from the device
    CY_COM_LIB_API virtual CyResult LoadFromDevice();
    CY_COM_LIB_API virtual CyResult SaveToDevice  () const;

protected:
    CY_COM_LIB_API virtual CyResult OnApply          ( void* aPropertyPage );

    CY_COM_LIB_API virtual CyResult LoadFromXML_214( CyXMLDocument& aDocument );

    // NOTE: all the parameter will be accesible through Set/GetParameter from
    // the parent class CyParameterRepository.  These parameter willNOT be 
    // applied to the device until the caller uses the SaveToDevice method:  
    CY_COM_LIB_API virtual CyResult ApplyChanges();

    CY_COM_LIB_API unsigned short GetAddressOffset() const;

private:
    struct CyDeviceExtensionInternal* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction - Destruction - Extensions are obtained through CyDevice and must not be
// deleted by the user.
// Note: All the CyParameterRepository_XXX and CyPersistentRepository_XXX functions are
// available on the device extensions.

CY_COM_LIB_C_API( unsigned long ) CyDeviceExtension_GetType( CyDeviceExtensionH aHandle );
CY_COM_LIB_C_API( CyDeviceH )     CyDeviceExtension_GetDevice( CyDeviceExtensionH aHandle );
CY_COM_LIB_C_API( CyResult )      CyDeviceExtension_LoadFromDevice( CyDeviceExtensionH aHandle);
CY_COM_LIB_C_API( CyResult )      CyDeviceExtension_SaveToDevice  ( CyDeviceExtensionH aHandle );

#endif // _CY_DEVICE_EXTENSION_H_


