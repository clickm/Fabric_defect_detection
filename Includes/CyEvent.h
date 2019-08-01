// *****************************************************************************
//
// $Id: CyEvent.h,v 1.26 2008/07/24 20:55:54 igors Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyEvent.h
//
// Description..: Base synchronization object.
//
// *****************************************************************************

#ifndef _CY_EVENT_H_
#define _CY_EVENT_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

#ifdef _UNIX_
#include <pthread.h>
#endif // _UNIX_

#include "CySynchro.h"
#include "CyUtilsLib.h"
#include "CyTypes.h"
#include "CyUtilsLibCDef.h"

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyEventInternal;
class CyEvent : public CySynchro
{

// Constructors / Destructor
public:

    // Create an unnamed event
	CY_UTILS_LIB_API CyEvent( bool aManualReset,
                              bool aSignaled = false );

#ifdef WIN32

    // Create a named event
    CY_UTILS_LIB_API CyEvent( const CyString& aName,
                              bool aManualReset,
                              bool aSignaled = false );

    // Create an event that already exists under name
	CY_UTILS_LIB_API CyEvent( const CyString& aName );

#endif // WIN32

	CY_UTILS_LIB_API virtual ~CyEvent( void );

// Methods
public:
    // Overlapped operations (override of WaitUntilSignaled)
    CY_UTILS_LIB_API virtual void*    GetOverlapped( CySysHandle aHandle );
    CY_UTILS_LIB_API virtual void     Lock();
    CY_UTILS_LIB_API virtual void     Unlock();
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled();
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long   aTime ); // miliseconds
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long * aInfo );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long   aTime, // miliseconds
                                                         unsigned long * aInfo );

    CY_UTILS_LIB_API virtual bool     IsSignaled();

    CY_UTILS_LIB_API virtual CyResult Reset ( void );
	CY_UTILS_LIB_API virtual CyResult Signal( void );

    CY_UTILS_LIB_API virtual CyResult Pulse ( void );

    // Wrapper in order to use CyLockScope template
    CY_UTILS_LIB_API virtual CyResult Enter( void );
    CY_UTILS_LIB_API virtual CyResult Leave( void );

protected:
    CY_UTILS_LIB_API virtual CySysHandle GetDeviceHandle() const;

#ifdef _UNIX_
    CyResult OverlappedOperation( unsigned long *aInfo );
    CyResult WaitUsingCondition( void );
    CyResult WaitUsingCondition( unsigned long aTime );
#endif // _UNIX_

protected:

// Members
private:
    struct CyEventInternal* mInternal;

private:
    CyEvent( const CyEvent& );
    CyEvent& operator=( const CyEvent& );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction Destruction
CY_UTILS_LIB_C_API( CyEventH )   CyEvent_Init( const char * aName,
                                               int          aManualReset,
                                               int          aSignaled );
                                          
#ifdef WIN32                                          
CY_UTILS_LIB_C_API( CyEventH )   CyEvent_Open( const char * aName );
#endif /* WIN32 */

CY_UTILS_LIB_C_API( void )       CyEvent_Destroy( CyEventH aHandle );

// Event specific functions
CY_UTILS_LIB_C_API( int )        CyEvent_IsSignaled( CyEventH aHandle );
CY_UTILS_LIB_C_API( CyResult )   CyEvent_Reset ( CyEventH aHandle );
CY_UTILS_LIB_C_API( CyResult )   CyEvent_Signal( CyEventH aHandle );
CY_UTILS_LIB_C_API( CyResult )   CyEvent_Pulse ( CyEventH aHandle );

#endif // _CY_EVENT_H_
