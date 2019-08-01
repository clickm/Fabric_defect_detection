// *****************************************************************************
//
// $Id: CyResultEvent.h,v 1.14 2007/11/13 13:42:07 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyResultEvent.h
//
// Description..: Event that passes results from signaler to waiter
//
// *****************************************************************************

#ifndef _CY_RESULT_EVENT_H_
#define _CY_RESULT_EVENT_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyEvent.h"
#include "CyUtilsLibCDef.h"

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyResultEventInternal;
class CyResultEvent : public CyEvent
{
// Constructors / Destructor
public:

    // Create an unnamed event
	CY_UTILS_LIB_API CyResultEvent( bool aManualReset,
                                    bool aSignaled = false );

	CY_UTILS_LIB_API virtual ~CyResultEvent( void );

// Methods
public:

    // Override waiting in order to return the given result
    CY_UTILS_LIB_API virtual void*    GetOverlapped( CySysHandle aHandle );
    CY_UTILS_LIB_API virtual void*    GetOverlapped( CySysHandle    aHandle,
                                                     unsigned long* aResult );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long   aTime );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long * aInfo );
    CY_UTILS_LIB_API virtual CyResult WaitUntilSignaled( unsigned long   aTime,
                                                         unsigned long * aInfo );

    CY_UTILS_LIB_API virtual CyResult Reset ( void );
    CY_UTILS_LIB_API virtual CyResult Signal( CyResult aResult = CY_RESULT_OK );
    CY_UTILS_LIB_API virtual CyResult Pulse ( CyResult aResult = CY_RESULT_OK );
    CY_UTILS_LIB_API virtual CyResult Abort ( void );

    CY_UTILS_LIB_API virtual CyResult GetResult() const;

// Members
private:
    struct CyResultEventInternal* mInternal;

private:
    CyResultEvent( const CyResultEvent& );
    CyResultEvent& operator=( const CyResultEvent& );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction - Destruction
CY_UTILS_LIB_C_API( CyResultEventH ) CyResultEvent_Init( int aManualResult,
                                                         int aSignaled );
CY_UTILS_LIB_C_API( void )           CyResultEvent_Destroy( CyResultEventH aHandle );

// Signal, pulse and abort with results, the non-result version can
// by uses with the CyEvent_XXX functions.
CY_UTILS_LIB_C_API( CyResult )       CyResultEvent_Signal( CyResultEventH aHandle,
                                                           CyResult       aResult );
CY_UTILS_LIB_C_API( CyResult )       CyResultEvent_Pulse ( CyResultEventH aHandle,
                                                           CyResult       aResult );
CY_UTILS_LIB_C_API( CyResult )       CyResultEvent_Abort ( CyResultEventH aHandle );


// Returns the result of a signalled event
CY_UTILS_LIB_C_API( CyResult )       CyResultEvent_GetResult( CyResultEventH aHandle );

#endif // _CY_RESULT_EVENT_H_
