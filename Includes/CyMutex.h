// *****************************************************************************
//
// $Id: CyMutex.h,v 1.18 2007/12/17 15:00:10 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyMutex.h
//
// Description..: Base synchronization object.
//
// *****************************************************************************

#ifndef _CY_MUTEX_H_
#define _CY_MUTEX_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

#ifdef _UNIX_
#include <pthread.h>
#endif // _UNIX_

#include "CySynchro.h"
#include "CyUtilsLib.h"
#include "CyTypes.h"
#include "CyString.h"
#include "CyUtilsLibCDef.h"

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyMutexInternal;
class CyMutex : public CySynchro
{
// Constructors / Destructor
public:

    // Create an unnamed event
	CY_UTILS_LIB_API CyMutex( bool aSignaled );

#ifdef WIN32
    // Create a named event
    CY_UTILS_LIB_API CyMutex( const CyString& aName,
                              bool            aSignaled );

#ifndef UNDER_CE
    // Create an event that already exists under name
	CY_UTILS_LIB_API CyMutex( const CyString& aName );
#endif // UNDER_CE
#endif // WIN32

	CY_UTILS_LIB_API virtual ~CyMutex( void );

// Methods
public:
    // Release the mutex for other threads
    CY_UTILS_LIB_API virtual CyResult Release ( void );

    // Wrapper in order to use CyLockScope template
    CY_UTILS_LIB_API virtual CyResult Enter( void );
    CY_UTILS_LIB_API virtual CyResult Leave( void );
    
#ifdef _UNIX_
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long aTime ); // miliseconds
#endif // _UNIX_
    

// Data
private:
    struct CyMutexInternal* mInternal;
    
private:
    CyMutex( const CyMutex& );
    CyMutex& operator=( const CyMutex& );
};
#endif // __cplusplus

// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction Destruction
CY_UTILS_LIB_C_API( CyMutexH )   CyMutex_Init( const char * aName,
                                               int          aSignaled );
                                               
#ifndef UNDER_CE
#ifndef _UNIX_
CY_UTILS_LIB_C_API( CyMutexH )   CyMutex_Open( const char * aName );
#endif /* _UNIX_ */
#endif // UNDER_CE

CY_UTILS_LIB_C_API( void )       CyMutex_Destroy( CyMutexH aHandle );

// Mutex specific functions
CY_UTILS_LIB_C_API( CyResult )   CyMutex_Release( CyMutexH aHandle );

#endif // _CY_MUTEX_H_
