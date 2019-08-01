// *****************************************************************************
//
// $Id: CyEngineSharedMemory.h,v 1.6 2007/07/04 21:27:06 igors Exp $
//
// cy1h23b1
//
// *****************************************************************************
//
//     Copyright (c) 2004, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyEngineSharedMemory.h
//
// *****************************************************************************

#ifndef _CY_ENGINE_SHARED_MEMORY_H_
#define _CY_ENGINE_SHARED_MEMORY_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyEngineLib =====
#include "CyEngineLib.h"
#include <CyObject.h>

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct EngineSharedMemoryInternal;
class CyEngineSharedMemory : public CyObject
{

public:

    CY_ENGINE_LIB_API CyEngineSharedMemory();

    CY_ENGINE_LIB_API virtual ~CyEngineSharedMemory();

    CY_ENGINE_LIB_API bool IsValid() const;

    CY_ENGINE_LIB_API void Reset();

    CY_ENGINE_LIB_API unsigned long GetConcurrentSize() const;

    CY_ENGINE_LIB_API void SetConcurrentSize( unsigned long aSize );  // Bytes

// Undocumented:
    CY_ENGINE_LIB_API void* GetInternal();

private:
    struct EngineSharedMemoryInternal* mInternal;

    // Disabled
    CyEngineSharedMemory( const CyEngineSharedMemory & );
    const CyEngineSharedMemory operator = ( const CyEngineSharedMemory & );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyEngineSharedMemory Handle
typedef void* CyEngineSharedMemoryH;

// Construction / Destruction
CY_ENGINE_LIB_C_API( CyEngineSharedMemoryH )   CyEngineSharedMemory_Init();
CY_ENGINE_LIB_C_API( void )                    CyEngineSharedMemory_Destroy( CyEngineSharedMemoryH aHandle );

// Functions
CY_ENGINE_LIB_C_API( int )     CyEngineSharedMemory_IsValid          ( CyEngineSharedMemoryH aHandle );
CY_ENGINE_LIB_C_API( void )    CyEngineSharedMemory_Reset            ( CyEngineSharedMemoryH aHandle );
CY_ENGINE_LIB_C_API( void )    CyEngineSharedMemory_SetConcurrentSize( CyEngineSharedMemoryH aHandle,
                                                                       unsigned long         aSize );


#endif // _CY_ENGINE_SHARED_MEMORY_H_
