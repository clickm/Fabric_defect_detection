// *****************************************************************************
//
// $Id: CyObject.h,v 1.9 2009/05/29 14:55:27 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyObject.h
//
// Description..: Defines the top level object of any object in this SDK
//
// *****************************************************************************

#ifndef _CY_OBJECT_H_
#define _CY_OBJECT_H_

// Headers
/////////////////////////////////////////////////////////////////////////////

#include "CyUtilsLib.h"
#include "CyTypes.h"


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyObject
{
#ifndef UNDER_CE

public:
    // new operator overrides
    CY_UTILS_LIB_API void* CY_CALLING_CONV operator new  ( size_t aSize, const char* aUser, int aLine );
    CY_UTILS_LIB_API void* CY_CALLING_CONV operator new[]( size_t aSize, const char* aUser, int aLine );
    CY_UTILS_LIB_API void* CY_CALLING_CONV operator new  ( size_t aSize );
    CY_UTILS_LIB_API void* CY_CALLING_CONV operator new[]( size_t aSize );
    CY_UTILS_LIB_API void* CY_CALLING_CONV operator new  ( size_t aSize, void* aPtr );

    // delete operator overrides
    CY_UTILS_LIB_API void  CY_CALLING_CONV operator delete  ( void* aPtr, const char* aUser, int aLine );
    CY_UTILS_LIB_API void  CY_CALLING_CONV operator delete[]( void* aPtr, const char* aUser, int aLine );
    CY_UTILS_LIB_API void  CY_CALLING_CONV operator delete  ( void* aPtr );
    CY_UTILS_LIB_API void  CY_CALLING_CONV operator delete[]( void* aPtr );
    CY_UTILS_LIB_API void  CY_CALLING_CONV operator delete  ( void* aPtr, void* );

    // Enable/Disable memory leak checking
    CY_UTILS_LIB_API static void CY_CALLING_CONV EnableMemoryLeakChecking( bool aEnabled );
    CY_UTILS_LIB_API static bool CY_CALLING_CONV MemoryLeakCheckingEnabled();

#endif // UNDER_CE
};

//#if defined( _DEBUG ) && !defined( UNDER_CE )
//#define CY_NEW new( __FILE__,__LINE__ )
//#else
#define CY_NEW new
//#endif

#endif // __cplusplus

#endif // _CY_OBJECT_H_

