// *****************************************************************************
//
// $Id: CyCurrentThread.h,v 1.7 2007/07/04 21:27:05 igors Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCurrentThread.h
//
// Description..: Encapsulation of the current thread.
//
// *****************************************************************************

#ifndef _CY_CURRENT_THREAD_H_
#define _CY_CURRENT_THREAD_H_

#include "CyUtilsLib.h"
#include "CyThread.h"

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyCurrentThread : public CyThread
{
// Constructors / Destructor
public:
    CY_UTILS_LIB_API         CyCurrentThread(  );
    CY_UTILS_LIB_API virtual ~CyCurrentThread( void );


// Methods
public:
    // Thread Control (disabled)
    CY_UTILS_LIB_API virtual CyResult StartThread( void );
    CY_UTILS_LIB_API virtual CyResult StopThread( void );
    CY_UTILS_LIB_API virtual CyResult Run();

    // ===== CySynchro =====

#ifdef _UNIX_
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( void );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long aTime );
#endif // _UNIX_
    
private:
    CyCurrentThread( const CyCurrentThread& );
    CyCurrentThread& operator=( const CyCurrentThread& );
};
#endif // __cplusplus

#endif // _CY_CURRENT_THREAD_H_
