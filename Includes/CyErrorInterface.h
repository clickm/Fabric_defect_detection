// *****************************************************************************
//
// $Id: CyErrorInterface.h,v 1.15 2007/11/13 13:42:06 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyErrorInterface.h
//
// Description..: Provides a mechanism for GetErrorInfo
//
// *****************************************************************************

#ifndef _CY_ERROR_INFO_H_
#define _CY_ERROR_INFO_H_

#ifdef _UNIX_
#include <stdlib.h>
#endif // _UNIX_

#include "CyUtilsLib.h"
#include "CyTypes.h"
#include "CyObject.h"
#include "CyUtilsLibCDef.h"

#ifdef __cplusplus
struct CyErrorInterfaceInternal;
class CY_UTILS_LIB_API CyErrorInterface : public CyObject
{
public:
    // Construction / Destruction
             CyErrorInterface();
    virtual ~CyErrorInterface();

// Setting the last error
    virtual CyResult    SetErrorInfo( const char *  aMessage,
                                      CyResult      aResult,
                                      const char *  aSourceFile,
                                      unsigned long aSourceLine,
                                      unsigned long aSystemCode ) const;
    virtual CyResult    SetErrorInfo( const CyErrorInterface& aError ) const;
    virtual CyResult    SetErrorInfo( const CyErrorInfo& aInfo ) const;

// Getting the error Info
    virtual CyResult    GetErrorInfo( CyErrorInfo * aInfo = 0 ) const;

// Clearing the error
    virtual CyResult    ClearErrorInfo() const;

// Returns a human readable version of the error information
    virtual CyString    GetInfoString() const;

// Members
private:
    struct CyErrorInterfaceInternal* mInternal;
};
#endif


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction Destruction
CY_UTILS_LIB_C_API( CyErrorInterfaceH ) CyErrorInterface_Init();
CY_UTILS_LIB_C_API( void )              CyErrorInterface_Destroy( CyErrorInterfaceH aHandle );

// SetErrorInfo methods
CY_UTILS_LIB_C_API( CyResult ) CyErrorInterface_SetErrorInfo ( CyErrorInterfaceH aHandle,
                                                               const char *      aMessage,
                                                               CyResult          aResult,
                                                               const char *      aSourceFile,
                                                               unsigned long     aSourceLine,
                                                               unsigned long     aSystemCode );
CY_UTILS_LIB_C_API( CyResult ) CyErrorInterface_SetErrorInfo2( CyErrorInterfaceH aHandle,
                                                               CyErrorInterfaceH aSource );
CY_UTILS_LIB_C_API( CyResult ) CyErrorInterface_SetErrorInfo3( CyErrorInterfaceH  aHandle,
                                                               struct CyErrorInfo aInfo );

// GetErrorInfo Method
CY_UTILS_LIB_C_API( CyResult ) CyErrorInterface_GetErrorInfo ( CyErrorInterfaceH   aHandle,
                                                               struct CyErrorInfo* aInfo );

// ClearErrorInfo method
CY_UTILS_LIB_C_API( CyResult ) CyErrorInterface_ClearErrorInfo( CyErrorInterfaceH aHandle );

// GetInfoString method
CY_UTILS_LIB_C_API( CyResult ) CyErrorInterface_GetInfoString( CyErrorInterfaceH aHandle,
                                                               char*             aBuffer,
                                                               unsigned long     aBufferSize );

#endif // _CY_ERROR_INFO_H_
