// *****************************************************************************
//
// $Id: CySynchro.h,v 1.25 2007/12/17 13:24:49 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CySynchro.h
//
// Description..: Encapsulates synchronization objects, such as Event, Mutex,
//                Semaphores, threads, processes.
//
//                This interfaces defines a common method for waiting for one
//                or more "objects".  Signaling of the actual objects is done
//                by specific implementation.
//
// *****************************************************************************

#ifndef _CY_SYNCHRO_H_
#define _CY_SYNCHRO_H_

#include "CyUtilsLib.h"
#include "CyTypes.h"
#include "CyErrorInterface.h"
#include "CyUtilsLibCDef.h"

#ifdef __cplusplus
class CySynchro : public CyErrorInterface
{
// Types
public:

    // Class containing several synchro objects for multiple wait
    struct VectorInternal;
    class Vector : public CyObject
    {
        friend class CySynchro;
    public:
        CY_UTILS_LIB_API Vector();
        CY_UTILS_LIB_API ~Vector();

        // add/remove from vector
        CY_UTILS_LIB_API bool AddSynchro( CySynchro& aObject );
        CY_UTILS_LIB_API bool RemoveSynchro( CySynchro& aObject );
        CY_UTILS_LIB_API void Clear();

        CY_UTILS_LIB_API unsigned long GetHandleCount() const;

#ifdef WIN32
        // returns an array of handles to use in OS multiple waiting
        CY_UTILS_LIB_API const CySysHandle* GetHandles() const;
#endif // WIN32

    private:
        struct VectorInternal * mInternal;

    private:
        Vector( const Vector& );
        Vector& operator=( const Vector& );
    };

    // constant that represents successful waiting on a group of objects
    CY_UTILS_LIB_API static const unsigned long OBJECT_0;

    // constant that represents an abandonned object on a multiple wait
    CY_UTILS_LIB_API static const unsigned long ABANDONNED_0;

// Construction/Destruction
protected:

    friend class Vector;

    CY_UTILS_LIB_API         CySynchro();

#ifdef _UNIX_
    CY_UTILS_LIB_API virtual ~CySynchro();
#else
    // In Windows, we do not have a pure virtual WaitUntisignaled,
    // so we can declared the constructor as pure virtual so that
    // nobody will create a CySynchro.
    //
    // The = 0 is removed for UNIX because for some platform it can
    // create problems, since the destructor function actually exists
    // even if it is pure virtual.
    CY_UTILS_LIB_API virtual ~CySynchro() = 0;
#endif


// Waiting methods
public:

#ifdef _UNIX_

    // Wait for a single object (this) to be signaled
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( void ) = 0;
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long aTime ) = 0;

#endif // _UNIX_

#ifdef WIN32

    // Wait for a single object (this) to be signaled
    CY_UTILS_LIB_API virtual CyResult   WaitUntilSignaled( void );
    CY_UTILS_LIB_API virtual CyResult   WaitUntilSignaled( unsigned long aTime );

    // Returns the internal handle
    CY_UTILS_LIB_API virtual CySysHandle GetHandle() const;

#endif // WIN32

    // Wait for multiple objects.
    CY_UTILS_LIB_API static  CyResult CY_CALLING_CONV WaitUntilSignaled( const Vector& aObjects,
                                                                         bool aWaitAll = false );
    CY_UTILS_LIB_API static  CyResult CY_CALLING_CONV WaitUntilSignaled( const Vector& aObjects,
                                                                         unsigned long aTime,
                                                                         bool aWaitAll = false );
                                                           
protected:

#ifdef WIN32

    // The handle to the actual OS object.  Protected so
    // that derived classes may use it.
    CySysHandle mSystemObject;
    
#endif // WIN32

private:
    CySynchro( const CySynchro& );
    CySynchro& operator=( const CySynchro& );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Contants for CySynchro
#define CY_SYNCHRO_OBJECT_0     ( CY_RESULT_MAX + 1000 )
#define CY_SYNCHRO_ABANDONNED_0 ( CY_RESULT_MAX + 2000 )

// Synchro vector Construction - Destruction
CY_UTILS_LIB_C_API( CySynchroVectorH ) CySynchroVector_Init();
CY_UTILS_LIB_C_API( void )             CySynchroVector_Destroy( CySynchroVectorH aHandle );

// CySynchro vector functions
CY_UTILS_LIB_C_API( int )              CySynchroVector_AddSynchro   ( CySynchroVectorH aHandle,
                                                                      CySynchroH       aObject );
CY_UTILS_LIB_C_API( int )              CySynchroVector_RemoveSynchro( CySynchroVectorH aHandle,
                                                                      CySynchroH       aObject );

CY_UTILS_LIB_C_API( unsigned long )    CySynchroVector_GetHandleCount( CySynchroVectorH aHandle );

CY_UTILS_LIB_C_API( void )             CySynchroVector_Clear( CySynchroVectorH aHandle );

CY_UTILS_LIB_C_API( CyResult )   CySynchro_MultipleWaitUntilSignaled  ( CySynchroVectorH aObjects,
                                                                        int              aWaitAll );
CY_UTILS_LIB_C_API( CyResult )   CySynchro_MultipleWaitUntilSignaledEx( CySynchroVectorH aObjects,
                                                                        unsigned long    aTime,
                                                                        int              aWaitAll );

// CySynchro functions ( there is no constructor or destructor )
// See: CyEvent, CyResultEvent, CySemaphore and CyMutex
CY_UTILS_LIB_C_API( CyResult )   CySynchro_WaitUntilSignaled  ( CySynchroH    aHandle );
CY_UTILS_LIB_C_API( CyResult )   CySynchro_WaitUntilSignaledEx( CySynchroH    aHandle,
                                                                unsigned long aTime );

#ifdef WIN32
CY_UTILS_LIB_C_API( CySysHandle ) CySynchro_GetHandle();
#endif /* WIN32 */

#endif // _CY_SYNCHRO_H_
