// *****************************************************************************
//
//     Copyright (c) 2003-2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyBufferConstants.h
//
// Description..: Multi-thread buffer implementation. Support queuing of write 
//                requests.
//
// *****************************************************************************

#ifndef _CY_BUFFER_CONSTANTS_H_
#define _CY_BUFFER_CONSTANTS_H_

enum CyBufferFlags
{

    CY_BUFFER_FLAG_ERROR_IF_EMPTY   = 0x00000001,
    CY_BUFFER_FLAG_NO_WAIT          = 0x00000002,
    CY_BUFFER_FLAG_NO_DOUBLE_BUFFER = 0x00000004,

};

#endif // _CY_BUFFER_CONSTANTS_H_

