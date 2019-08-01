// *****************************************************************************
//
// $Id: CyMemoryManager.h,v 1.12 2007/11/13 13:42:02 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....:   CyMemoryManager.h
//
// Description..: Manages memory access for buffers
//
// *****************************************************************************

#ifndef _CY_MEMORY_MANAGER_H_
#define _CY_MEMORY_MANAGER_H_

// Headers
/////////////////////////////////////////////////////////////////////////////

#include <CyTypes.h>
#include "CyComLib.h"
#include "CyComLibCDef.h"

// Forward
/////////////////////////////////////////////////////////////////////////////

struct DriverSharedMemory;


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyMemoryManager : public CyObject
{
    public:
        CY_COM_LIB_API virtual ~CyMemoryManager() {};

        virtual CyResult Acquire( unsigned char ** aBuffer,
                                  unsigned long    aSize ) = 0;

        virtual CyResult Release( unsigned char *  aBuffer,
                                  unsigned long    aSize) = 0;

        virtual CyResult Flush() = 0;

        CY_COM_LIB_API virtual CyResult Lock( unsigned char     ** aBuffer,
                               bool                 aWrite,
                               DriverSharedMemory * aShared )
        { 
            (void)aBuffer;
            (void)aWrite;
            (void)aShared;
            return CY_RESULT_OK;
        };

        CY_COM_LIB_API virtual CyResult Unlock( unsigned char           ** aBuffer,
                                 bool                       aWrite,
                                 const DriverSharedMemory * aShared )
        {
            (void)aBuffer;
            (void)aWrite;
            (void)aShared;
            return CY_RESULT_OK;
        };

        virtual unsigned long GetMaximumBufferCount() const = 0;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Destructor - A memory manager needs to be created using the _Init function of the actual
// manager type.  See CyHighMemoryManager.h or CySimpleMemoryManager.h.
CY_COM_LIB_C_API( void )     CyMemoryManager_Destroy( CyMemoryManagerH aHandle );

// Functions
CY_COM_LIB_C_API( CyResult ) CyMemoryManager_Acquire ( CyMemoryManagerH aHandle,
                                                       unsigned char**  aBuffer,
                                                       unsigned long    aSize );

CY_COM_LIB_C_API( CyResult ) CyMemoryManager_Release ( CyMemoryManagerH aHandle,
                                                       unsigned char*   aBuffer,
                                                       unsigned long    aSize );

CY_COM_LIB_C_API( CyResult ) CyMemoryManager_Flush   ( CyMemoryManagerH    aHandle );

CY_COM_LIB_C_API( CyResult ) CyMemoryManager_Lock    ( CyMemoryManagerH           aHandle,
                                                       unsigned char**            aBuffer,
                                                       int                        aWrite,
                                                       struct DriverSharedMemory* aShared );

CY_COM_LIB_C_API( CyResult ) CyMemoryManager_Unlock  ( CyMemoryManagerH           aHandle,
                                                       unsigned char**            aBuffer,
                                                       int                        aWrite,
                                                       struct DriverSharedMemory* aShared );

CY_COM_LIB_C_API( unsigned long ) CyMemoryManager_GetMaximumBufferCount( CyMemoryManagerH aHandle );

#endif // _CY_MEMORY_MANAGER_H_

