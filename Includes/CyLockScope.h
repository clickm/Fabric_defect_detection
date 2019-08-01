// *****************************************************************************
//
// $Id: CyLockScope.h,v 1.7 2007/07/04 21:27:06 igors Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyLockScope.h
//
// Description..: Lockscope class for automatic lock/unlock
//
// *****************************************************************************

#ifndef _CY_LOCKSCOPE_H_
#define _CY_LOCKSCOPE_H_

// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
template <class T>
class CyLockScope
{

// Constructors / Destructor
public:

    CyLockScope( void )
        : mLock( 0 )
    {
    }

    CyLockScope( T& aLock )
        : mLock( &aLock )
    {
        mLock->Enter();
    }

    ~CyLockScope( void )
    {
        Cancel();
    }

// Methods
public:

    void Assign( T& aLock, bool aCancelCurrent = true )
    {
        if ( aCancelCurrent )
            Cancel();

        mLock = &aLock;
        mLock->Enter();
    }

    void Cancel( bool aKeepLock = false )
    {
        if ( !aKeepLock && mLock != 0 )
        {
            mLock->Leave();
        }

        mLock = 0;
    }

// Data
private:

    T* mLock;

private:
    CyLockScope( const CyLockScope& );
    CyLockScope& operator=( const CyLockScope& );

    // The new operator is disable, since we do not want this object to be created
    // on the heap, only on the stack
    void* CY_CALLING_CONV operator new  ( size_t aSize );
    void* CY_CALLING_CONV operator new[]( size_t aSize );
    void* CY_CALLING_CONV operator new  ( size_t aSize, void* aPtr );
};
#endif // __cplusplus

#endif // _CY_LOCKSCOPE_H_
