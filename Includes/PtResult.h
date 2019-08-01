// *****************************************************************************
//
//     Copyright (c) 2008, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: PtResult.h
//
// *****************************************************************************

#ifndef __PTRESULT_H__
#define __PTRESULT_H__


#include <PtPublic.h>
#include <PtTypes.h>


class PT_PUBLIC_API PtResult
{

public:

    PtResult();
    PtResult( PtUInt32 aCode );

    // The destructor is not virtual to make as much efficient as possible using
    // the object as return value.
	~PtResult();

    operator const char  * () const;
    bool operator == ( const PtUInt32 aCode ) const;
    bool operator != ( const PtUInt32 aCode ) const;

    const char * GetCodeString() const;

    bool IsOK() const;

	struct PT_PUBLIC_API Code
	{
		static const PtUInt32 OK;
		static const PtUInt32 NOT_INITIALIZED;
        static const PtUInt32 STATE_ERROR;
        static const PtUInt32 INVALID_PARAMETER;
        static const PtUInt32 NOT_FOUND;
        static const PtUInt32 GENERIC_ERROR;
        static const PtUInt32 REBOOT_NEEDED;
        static const PtUInt32 REBOOT_AND_RECALL;
	};

private:

	PtUInt32 mCode;

};


#endif // __PTRESULT_H__
