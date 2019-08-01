// *****************************************************************************
//
// $Id: CyGate.h,v 1.14 2007/11/13 13:42:06 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGate.h
//
// Description..: Used to thread-protect a section of code
//
// *****************************************************************************

#ifndef _CY_GATE_H_
#define _CY_GATE_H_

#ifdef _UNIX_
#include <pthread.h>
#endif // _UNIX_

#include "CyUtilsLib.h"
#include "CyTypes.h"
#include "CyObject.h"
#include "CyUtilsLibCDef.h"

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyGateInternal;
class CyGate : public CyObject
{
public:
    // Constructors / Destructor
    CY_UTILS_LIB_API    CyGate( void );
    CY_UTILS_LIB_API    ~CyGate( void );


// Gate access methods
public:

    CY_UTILS_LIB_API void Enter( void );
    CY_UTILS_LIB_API void Leave( void );
    CY_UTILS_LIB_API bool Try  ( void );

// accessors
public:
    CY_UTILS_LIB_API unsigned long
                          GetOwner() const;

    CY_UTILS_LIB_API unsigned int
                          GetLockCount() const;

// Data
private:
    struct CyGateInternal* mInternal;

private:
    CyGate( const CyGate& );
    CyGate& operator=( const CyGate& );
};

#include "CyLockScope.h"
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction Destruction
CY_UTILS_LIB_C_API( CyGateH )    CyGate_Init();
CY_UTILS_LIB_C_API( void )       CyGate_Destroy( CyGateH aHandle );

// cyGate functions
CY_UTILS_LIB_C_API( void )       CyGate_Enter( CyGateH aHandle );
CY_UTILS_LIB_C_API( void )       CyGate_Leave( CyGateH aHandle );

CY_UTILS_LIB_C_API( unsigned long ) CyGate_GetOwner( CyGateH aHandle );
CY_UTILS_LIB_C_API( unsigned int )  CyGate_GetLockCount( CyGateH aHandle );

#endif // _CY_GATE_H_
