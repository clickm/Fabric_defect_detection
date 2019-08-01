// *****************************************************************************
//
// $Id: CyPerfMonitor.h,v 1.14 2007/11/13 13:42:02 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyPerfMonitor.h
//
// Description..: Performance monitor classes that stores acquisition statistics.
//
// *****************************************************************************

#ifndef _CY_PERF_MONITOR_H_
#define _CY_PERF_MONITOR_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyGate.h>
#include <CyObject.h>

// ===== This project =====
#include "CyComLib.h"
#include "CyComLibCDef.h"

// Forward Declaration
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyPerfMonitorInternal;
#endif // __cplusplus


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyPerfMonitor : public CyObject
{
// Constructors / Destructor
public:
    CY_COM_LIB_API CyPerfMonitor( void );

    CY_COM_LIB_API virtual ~CyPerfMonitor( void );

private:

    CyPerfMonitor( const CyPerfMonitor & );

// Operators
private:

    const CyPerfMonitor &operator=( const CyPerfMonitor & );

// Accessors
public:

    CY_COM_LIB_API double        GetAverageFrameRate( void );
    CY_COM_LIB_API unsigned long GetBadImageCount( void )    const;
    CY_COM_LIB_API double        GetFrameRate( void );
    CY_COM_LIB_API unsigned long GetImageCount( void )       const;
    CY_COM_LIB_API double        GetRunningTime( void );

    CY_COM_LIB_API void Reset( void );
    CY_COM_LIB_API void ResetBadImageCount( void );
    CY_COM_LIB_API void ResetImageCount( void );

// Methods
public:

    CY_COM_LIB_API void StartContinuous( void );
    CY_COM_LIB_API void StopContinuous( void );
    CY_COM_LIB_API bool IsRunning( void ) const;

    CY_COM_LIB_API void AddImage( bool aOK );

// Data
private:
#ifdef _MANAGED //Needed for managed wrapper
    friend ref class CyPerfMonitorNet;
#endif //_MANAGED
    struct CyPerfMonitorInternal* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Constructor / Destructor
CY_COM_LIB_C_API( CyPerfMonitorH ) CyPerfMonitor_Init();
CY_COM_LIB_C_API( void ) CyPerfMonitor_Destroy( CyPerfMonitorH aHandle );

// Accessors
CY_COM_LIB_C_API( double )        CyPerfMonitor_GetAverageFrameRate( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyPerfMonitor_GetBadImageCount( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( double )        CyPerfMonitor_GetFrameRate( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( unsigned long ) CyPerfMonitor_GetImageCount( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( double )        CyPerfMonitor_GetRunningTime( CyPerfMonitorH aHandle );


// Resets
CY_COM_LIB_C_API( void ) CyPerfMonitor_Reset( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( void ) CyPerfMonitor_ResetBadImageCount( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( void ) CyPerfMonitor_ResetImageCount( CyPerfMonitorH aHandle );

// Functions
CY_COM_LIB_C_API( void ) CyPerfMonitor_StartContinuous( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( void ) CyPerfMonitor_StopContinuous( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( int )  CyPerfMonitor_IsRunning( CyPerfMonitorH aHandle );
CY_COM_LIB_C_API( void ) CyPerfMonitor_AddImage( int aOK );

#endif // _CY_PERF_MONITOR_H_

