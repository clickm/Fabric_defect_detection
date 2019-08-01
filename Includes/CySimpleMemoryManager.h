// *****************************************************************************
//
// $Id: CySimpleMemoryManager.h,v 1.10 2007/11/13 13:42:02 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CySimpleMemoryManager.h
//
// Description..: Simple Memory managers that keeps a pool of free memory 
//
// *****************************************************************************

#ifndef _CY_SIMPLE_MEMORY_MANAGER_H_
#define _CY_SIMPLE_MEMORY_MANAGER_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyGate.h>

// ===== This Project =====
#include "CyComLib.h"
#include "CyMemoryManager.h"


// class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CySimpleMemoryManagerInternal;
class CySimpleMemoryManager : public CyMemoryManager
{
    // Construction / Destruction
    public:
        CY_COM_LIB_API CySimpleMemoryManager( unsigned long aMaximumPoolSize = 8 );
        CY_COM_LIB_API virtual ~CySimpleMemoryManager();


    // Memory access
    public:
        CY_COM_LIB_API virtual CyResult Acquire( unsigned char ** aBuffer,
                                                 unsigned long    aSize );

        CY_COM_LIB_API virtual CyResult Release( unsigned char *  aBuffer,
                                                 unsigned long    aSize );

        CY_COM_LIB_API virtual CyResult Flush();

        CY_COM_LIB_API virtual unsigned long GetMaximumBufferCount() const;

    private:
        struct CySimpleMemoryManagerInternal* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Constructor - Use the CyMemoryManager_XXX functions.
CY_COM_LIB_C_API( CySimpleMemoryManagerH ) CySimpleMemoryManager_Init( unsigned long aMaximumPoolSize );

#endif // _CY_SIMPLE_MEMORY_MANAGER_H_

