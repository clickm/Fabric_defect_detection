// *****************************************************************************
//
//     Copyright (c) 2008, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: PtString.h
//
// *****************************************************************************

#ifndef __PTSTRING_H__
#define __PTSTRING_H__


#include <PtPublic.h>
#include <PtTypes.h> 


// Forward declaration 
namespace PtUserLib
{
	class String; 
}


class PT_PUBLIC_API PtString
{
public:

    PtString();
    PtString( const PtString & aValue );
    PtString( const char * aValue );
    PtString( const PtUnicodeChar * aValue );

    virtual ~PtString();

    const PtString &operator = ( const PtString & aValue );
    const PtString &operator += ( const PtString & aValue );

    bool operator == ( const char *aValue ) const;
    bool operator != ( const char *aValue ) const;

	bool operator == ( const PtUnicodeChar *aValue ) const;
    bool operator != ( const PtUnicodeChar *aValue ) const;

    bool operator == ( const PtString & aValue ) const;
    bool operator != ( const PtString & aValue ) const;

	operator const char *() const;
    operator const PtUnicodeChar *() const;

    const char *GetAscii() const;
    const PtUnicodeChar *GetUnicode() const;

    unsigned int GetLength() const;

private:

	mutable PtUserLib::String *mThis;
};


#endif //__PTSTRING_H__