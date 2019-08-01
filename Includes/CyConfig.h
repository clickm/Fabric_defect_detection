// *****************************************************************************
//
// $Id: CyConfig.h,v 1.33 2009/05/29 14:46:14 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyConfig.cpp
//
// Description..: CyConfig object define interface to create and modify device
//                list.
//
// *****************************************************************************

#ifndef _CY_CONFIG_H_
#define _CY_CONFIG_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyPersistentRepository.h>
#include <CyXMLDocument.h>
#include <CyAssert.h>

// ===== This project =====
#include "CyComLib.h"
#include "CyComLibCDef.h"
#include "CyAdapterID.h"
#include "CyDeviceConstants.h"
#include "CyConfigConstants.h"


// Class
/////////////////////////////////////////////////////////////////////////////

/* ==========================================================================
@class	CyConfig

@since	2002-09-04
========================================================================== */
#ifdef __cplusplus
struct CyConfigInternal;
class CyConfig : public CyPersistentRepository
{
#ifndef CY_CONFIG_NO_BACKWARD_COMPATIBILITY
#include "CyConfigBackwardCompatibility.h"
#endif // CY_CONFIG_NO_BACKWARD_COMPATIBILITY

// Constructors / Destructor
public:

	CY_COM_LIB_API CyConfig( void );
	CY_COM_LIB_API virtual ~CyConfig( void );

// Operators
public:
    static CY_COM_LIB_API CyResult CY_CALLING_CONV Copy( const CyConfig& aSrc, CyConfig &aDest );

    // Deprecated
	static CY_COM_LIB_API CyResult CY_CALLING_CONV CopyConfig( const CyConfig& aSrc, CyConfig *aDest );

// Methods
public:
    // Add a new device at the end of the internal device list
	CY_COM_LIB_API CyResult AddDevice();

    // Remove the currently selected device from the internal device list
	CY_COM_LIB_API CyResult DeleteDevice();

    // Move in the internal device list
	CY_COM_LIB_API CyResult GoFirst();
	CY_COM_LIB_API CyResult GoLast();
	CY_COM_LIB_API CyResult GoNext();
	CY_COM_LIB_API CyResult GoPrevious();

    // Find a device based on its name
	CY_COM_LIB_API CyResult FindDeviceByName( const CyString& aName );

    // CyParameterRepository overrides
protected:
    CY_COM_LIB_API virtual CyResult OnParameterGet( unsigned long   aParameterIndex,
                                                    unsigned long   aParameterID,
                                                    const CyString& aParameterName );
    CY_COM_LIB_API virtual CyResult OnParameterSet( unsigned long   aParameterIndex,
                                                    unsigned long   aParameterID,
                                                    const CyString& aParameterName,
                                                    bool            aTest,
                                                    const CyString& aValueS,
                                                    CY_INT64        aValueI,
                                                    double          aValueD );

public:
	CY_COM_LIB_API virtual CyResult LoadFromXML ( CyXMLDocument& aDocument );
    CY_COM_LIB_API virtual CyResult SaveToXML   ( CyXMLDocument& aDocument ) const;
	CY_COM_LIB_API virtual CyResult SaveToXML   ( CyXMLDocument& aDocument, bool aAdapterAsIndex ) const;
	
// Data
private:
    friend class DeviceInfo;
    struct CyConfigInternal* mInternal;

private:
    // Disabled
	CyConfig( const CyConfig& );
    CyConfig& operator=( const CyConfig& );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Constructor/Destructor and copy operator
CY_COM_LIB_C_API( CyConfigH ) CyConfig_Init();
CY_COM_LIB_C_API( void )      CyConfig_Destroy( CyConfigH aHandle );
CY_COM_LIB_C_API( CyResult )  CyConfig_Copy   ( CyConfigH aSrc, CyConfigH aDest );

// Add/Remove an entry
CY_COM_LIB_C_API( CyResult ) CyConfig_AddDevice        ( CyConfigH      aHandle );
CY_COM_LIB_C_API( CyResult ) CyConfig_DeleteDevice     ( CyConfigH      aHandle );

// Search for a device by its name
CY_COM_LIB_C_API( CyResult ) CyConfig_FindDeviceByName ( CyConfigH      aHandle,
                                                         const char*    aName );

// Move through the entries
CY_COM_LIB_C_API( CyResult ) CyConfig_GoFirst          ( CyConfigH      aHandle );
CY_COM_LIB_C_API( CyResult ) CyConfig_GoLast           ( CyConfigH      aHandle );
CY_COM_LIB_C_API( CyResult ) CyConfig_GoNext           ( CyConfigH      aHandle );
CY_COM_LIB_C_API( CyResult ) CyConfig_GoPrevious       ( CyConfigH      aHandle );

// Save or load from XML
CY_COM_LIB_C_API( CyResult ) CyConfig_LoadFromXML      ( CyConfigH      aHandle,
                                                         CyXMLDocumentH aDocument );
CY_COM_LIB_C_API( CyResult ) CyConfig_SaveToXML        ( CyConfigH      aHandle,
                                                         CyXMLDocumentH aDocument,
                                                         int            aAdapterAsIndex );

#endif // _CY_CONFIG_H_
