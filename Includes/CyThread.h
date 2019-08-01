// *****************************************************************************
//
// $Id: CyThread.h,v 1.15 2007/07/04 21:27:06 igors Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyThread.h
//
// Description..: Thread encapsulation
//
// *****************************************************************************

#ifndef _CY_THREAD_H_
#define _CY_THREAD_H_

#ifdef _UNIX_
#include <pthread.h>
#endif // _UNIX_

#include "CySynchro.h"
#include "CyUtilsLib.h"
#include "CyTypes.h"


// Constants
/////////////////////////////////////////////////////////////////////////////

#define CY_THREAD_LOWEST           0
#define CY_THREAD_BELOW_NORMAL     1
#define CY_THREAD_IDLE             2
#define CY_THREAD_NORMAL           3
#define CY_THREAD_ABOVE_NORMAL     4
#define CY_THREAD_HIGHEST          5
#define CY_THREAD_TIME_CRITICAL    6


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyThreadInternal;
class CyThread : public CySynchro
{
// Data Types
public:
    typedef enum
    {
        LOWEST          = CY_THREAD_LOWEST,
        BELOW_NORMAL    = CY_THREAD_BELOW_NORMAL,
        IDLE            = CY_THREAD_IDLE,
        NORMAL          = CY_THREAD_NORMAL,
        ABOVE_NORMAL    = CY_THREAD_ABOVE_NORMAL,
        HIGHEST         = CY_THREAD_HIGHEST,
        TIME_CRITICAL   = CY_THREAD_TIME_CRITICAL
    }
    Priority;

// Constructors / Destructor
public:
    CY_UTILS_LIB_API         CyThread( const Priority& aPriority = NORMAL );
    CY_UTILS_LIB_API virtual ~CyThread( void );

protected:
    // Protected constructor for derived classes
    CY_UTILS_LIB_API        CyThread( const Priority& aPriority,
                                      bool            aRunning, 
                                      unsigned long   aThreadID );

// Methods
public:
    // Thread Control
    CY_UTILS_LIB_API virtual CyResult   StartThread( void );
    CY_UTILS_LIB_API virtual CyResult   StopThread( void );

    CY_UTILS_LIB_API virtual CyResult   SuspendThread( void );
    CY_UTILS_LIB_API virtual CyResult   ResumeThread( void );
    
    CY_UTILS_LIB_API virtual bool       IsRunning( void ) const;
    CY_UTILS_LIB_API virtual bool       IsStopping( void ) const;

    // Thread Priority
    CY_UTILS_LIB_API virtual CyResult   SetPriority( const Priority& aPriority );
    CY_UTILS_LIB_API virtual Priority   GetPriority( void ) const;

    // accessors
    CY_UTILS_LIB_API virtual unsigned long
                                        GetThreadID() const;

    // Returns the thread exit code
    CY_UTILS_LIB_API virtual CyResult    GetExitCode() const;

    // Thread Implementation
    CY_UTILS_LIB_API virtual CyResult   Run() = 0;

    // Thread utilities
    CY_UTILS_LIB_API static unsigned long CY_CALLING_CONV GetCurrentThreadID( void );
    CY_UTILS_LIB_API static CySysHandle   CY_CALLING_CONV GetCurrentThreadHandle( void );
    CY_UTILS_LIB_API static void          CY_CALLING_CONV Sleep( unsigned long aTime );

    // ===== CySynchro =====

#ifdef _UNIX_
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( void );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long aTime );
#endif // _UNIX_

// Data
private:
    struct CyThreadInternal* mInternal;

// Private Methods
public: // for pratical reasons
    CyResult                ThreadFunction( );  
    friend class CyCurrentThread;

private:
    CyThread( const CyThread& );
    CyThread& operator=( const CyThread& );
};
#endif // __cplusplus

#endif // _CY_THREAD_H_
