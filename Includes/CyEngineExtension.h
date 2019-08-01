// *****************************************************************************
//
// $Id: CyEngineExtension.h,v 1.5 2007/07/04 21:27:06 igors Exp $
//
// cy1h23b1
//
// *****************************************************************************
//
//     Copyright (c) 2004, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyEngineExtension.h
//
// *****************************************************************************

#ifndef _CY_ENGINE_EXTENSION_H_
#define _CY_ENGINE_EXTENSION_H_

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyErrorInterface.h>

// ===== CyEngineLib =====
#include "CyEngineLib.h"

// Forward declaration
/////////////////////////////////////////////////////////////////////////////

// ===== CyEngineLib =====
#ifdef __cplusplus
class CyEngine;
#endif // __cplusplus

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyEngineExtensionInternal;
class CyEngineExtension : public CyErrorInterface
{

// ===== Construction / Destruction =====
public:
    CY_ENGINE_LIB_API CyEngineExtension();
    CY_ENGINE_LIB_API virtual ~CyEngineExtension() = 0;

// ===== Accessors =====
public:
    // Indicates if the object is valid or not after construction
    CY_ENGINE_LIB_API virtual bool IsValid() const;

// ===== Connection Control =====
public:
    CY_ENGINE_LIB_API virtual CyResult Connect( CyEngine * aEngine );
    CY_ENGINE_LIB_API virtual CyResult Disconnect();


// ===== event handlers =====
public:
    CY_ENGINE_LIB_API virtual bool OnAction       ( const unsigned char * aData,
                                                    unsigned long         aDataSize,
                                                    unsigned long         aSrcAddr,
                                                    unsigned short        aSrcPort );
    CY_ENGINE_LIB_API virtual void OnConfigRead   (  unsigned long        aAddr );
    CY_ENGINE_LIB_API virtual void OnConfigWrite  ( unsigned long         aAddr );
    CY_ENGINE_LIB_API virtual void OnModuleReset  ( );
    CY_ENGINE_LIB_API virtual void OnRegisterRead ( unsigned long         aAddr );
    CY_ENGINE_LIB_API virtual void OnRegisterWrite( unsigned long         aAddr );
    CY_ENGINE_LIB_API virtual void OnUnknownAction( const unsigned char * aData,
                                                    unsigned long         aDataSize,
                                                    unsigned long         aSrcAddr,
                                                    unsigned short        aSrcPort );

protected:
    
    // When connected to an engine, this member will hold the pointer
    // to the engine.
    CyEngine * mEngine;

private:
    struct CyEngineExtensionInternal * mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyEngineExtension Handle
typedef void* CyEngineH;
typedef void* CyEngineExtensionH;

// Construction: Use the init function of the specific extension
// Destruction: This function can be used to destroy all types of extensions
CY_ENGINE_LIB_C_API( void ) CyEngineExtension_Destroy( CyEngineExtensionH aHandle );

// Indicates if the object is valid or not after construction
CY_ENGINE_LIB_C_API( int ) CyEngineExtension_IsValid( CyEngineExtensionH aHandle );

// ===== Connection Control =====
CY_ENGINE_LIB_C_API( CyResult ) CyEngineExtension_Connect   ( CyEngineExtensionH aHandle,
                                                              CyEngineH          aEngine );
CY_ENGINE_LIB_C_API( CyResult ) CyEngineExtension_Disconnect( CyEngineExtensionH aHandle );


#endif // _CY_ENGINE_EXTENSION_H_
