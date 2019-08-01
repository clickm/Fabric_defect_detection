// *****************************************************************************
//
// $Id: CyHighMemoryManager.h,v 1.14 2007/11/13 13:42:02 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyHighMemoryManager.h
//
// Description..: Manages memory access for buffers
//
// *****************************************************************************

#ifndef _CY_HIGH_MEMORY_MANAGER_
#define _CY_HIGH_MEMORY_MANAGER_

// Includes
/////////////////////////////////////////////////////////////////////////////

#include <CyGate.h>
#include "CyMemoryManager.h"
#include "CyBufferQueue.h"

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyHighMemoryManagerInternal;
class CyHighMemoryManager : public CyMemoryManager
{
// Constants
public:

    static const unsigned long INVALID_ID;

// Constructors / Destructor
public:

    CY_COM_LIB_API CyHighMemoryManager( unsigned long aFirstId
                                      , unsigned long aLastId
                                      , bool aDelete = true );

    CY_COM_LIB_API virtual ~CyHighMemoryManager( void );

// CyMemoryManager function
public:
    CY_COM_LIB_API virtual bool     IsValid() const;

    CY_COM_LIB_API virtual CyResult Acquire( unsigned char ** aBuffer,
                                             unsigned long    aSize );

    CY_COM_LIB_API virtual CyResult DeleteBuffers();

    CY_COM_LIB_API virtual CyResult Release( unsigned char *  aBuffer,
                                             unsigned long    aSize);

    CY_COM_LIB_API virtual CyResult Flush( void );

    CY_COM_LIB_API virtual CyResult Lock( unsigned char     ** aBuffer,
                                          bool                 aWrite,
                                          DriverSharedMemory * aShared );

    CY_COM_LIB_API virtual CyResult Unlock( unsigned char           ** aBuffer,
                                            bool                       aWrite,
                                            const DriverSharedMemory * aShared );

    CY_COM_LIB_API virtual unsigned long GetMaximumBufferCount() const;

// Methods
public:

    CY_COM_LIB_API CyResult Rescue( CyBufferQueue * aBuffer );


// Data
private:
    struct CyHighMemoryManagerInternal* mInternal;
};
#endif __cplusplus

// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyHighMemoryManagerH handle, can be used with the CyMemoryManager_XXX functions

// Constructor
CY_COM_LIB_C_API( CyHighMemoryManagerH ) CyHighMemoryManager_Init( unsigned long aFirstID,
                                                                   unsigned long aLastID );
CY_COM_LIB_C_API( int )                  CyHighMemoryManager_IsValid( CyHighMemoryManagerH aHandle );

// "Rescue" buffers currently in the High memory.
CY_COM_LIB_C_API( CyResult ) CyHighMemoryManager_Rescue( CyHighMemoryManagerH aHandle,
                                                         CyBufferQueueH       aBuffer );

// Delete the buffers associated with this high memory manager
CY_COM_LIB_C_API( CyResult ) CyHighMemoryManager_DeleteBuffers( CyHighMemoryManagerH aHandle );

#endif // _CY_HIGH_MEMORY_MANAGER_
