// *****************************************************************************
//
// $Id: CySimpleBuffer.h,v 1.10 2006/10/06 16:18:59 stardif Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CySimpleBuffer.h
//
// Description..: For Backward-compatibility, points to renamed CyUserBuffer.h
//
// *****************************************************************************

#ifndef _CY_SIMPLE_BUFFER_H_
#define _CY_SIMPLE_BUFFER_H_

#include "CyUserBuffer.h"

#define CySimpleBufferH                     CyUserBufferH                  
#define CySimpleBuffer_Init                 CyUserBuffer_Init              
#define CySimpleBuffer_Destroy              CyUserBuffer_Destroy           
#define CySimpleBuffer_GetID                CyUserBuffer_GetID             
#define CySimpleBuffer_GetBuffer            CyUserBuffer_GetBuffer         
#define CySimpleBuffer_GetBufferSize        CyUserBuffer_GetBufferSize     
#define CySimpleBuffer_GetCompletionEvent   CyUserBuffer_GetCompletionEvent
#define CySimpleBuffer_GetSharedMemory      CyUserBuffer_GetSharedMemory   
#define CySimpleBuffer_SetBuffer            CyUserBuffer_SetBuffer         

#endif // _CY_SIMPLE_BUFFER_H_

