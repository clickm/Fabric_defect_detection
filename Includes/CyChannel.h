// *****************************************************************************
//
// $Id: CyChannel.h,v 1.9 2007/07/04 21:27:04 igors Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyChannel.h
//
// Description..: CyChannel represents a channel of the IP Engine.
//
// *****************************************************************************

#ifndef _CY_CHANNEL_H_
#define _CY_CHANNEL_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

#include "CyComLib.h"
#include <CyString.h>


// Types
/////////////////////////////////////////////////////////////////////////////

typedef unsigned long CyChannelID;


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyChannelInternal;
class CyChannel : public CyObject
{
// Constructor / Destructor
public:
    CY_COM_LIB_API CyChannel( );
    CY_COM_LIB_API CyChannel( CyChannelID        aID,
                              const CyString& aName = "" );
    CY_COM_LIB_API CyChannel( const CyChannel& aObj );
    CY_COM_LIB_API virtual ~CyChannel();

    // copy operator
    CY_COM_LIB_API CyChannel& operator=( const CyChannel& aObj );


// Accessors
public:

    // Returns the channel ID
    CY_COM_LIB_API CyChannelID
                    GetID() const;

    // Get the channel name
    CY_COM_LIB_API const CyString&
                    GetName() const;


private:
    struct CyChannelInternal* mInternal;
};
#endif // __cplusplus

#endif
