// *****************************************************************************
//
//     Copyright (c) 2003-2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyBuffer.h
//
// Description..: For backward compatibility, points to renamed CyBufferQueue
//
// *****************************************************************************

#ifndef _CY_BUFFER_H_
#define _CY_BUFFER_H_

#include "CyBufferQueue.h"

// The older CyBuffer class has been renamed CyBufferQueue to avoid confusion
// about what is is.  This file is meant to enable older applications to compile
// even if they are still using the older name of the class

#define CyBufferH                               CyBufferQueueH
#define CyBuffer_Init                           CyBufferQueue_Init                        
#define CyBuffer_Destroy                        CyBufferQueue_Destroy                     
#define CyBuffer_GetCapacity                    CyBufferQueue_GetCapacity                 
#define CyBuffer_SetCapacity                    CyBufferQueue_SetCapacity                 
#define CyBuffer_GetReadImageStatus             CyBufferQueue_GetReadImageStatus          
#define CyBuffer_GetReadSubChannelID            CyBufferQueue_GetReadSubChannelID         
#define CyBuffer_GetReadTimestamp               CyBufferQueue_GetReadTimestamp            
#define CyBuffer_GetReadSize                    CyBufferQueue_GetReadSize                 
#define CyBuffer_GetReadImageID                 CyBufferQueue_GetReadImageID              
#define CyBuffer_GetPayloadType                 CyBufferQueue_GetPayloadType              
#define CyBuffer_GetReadExpectedResendCount     CyBufferQueue_GetReadExpectedResendCount  
#define CyBuffer_GetReadIgnoredPacketCount      CyBufferQueue_GetReadIgnoredPacketCount   
#define CyBuffer_GetReadLostPacketCount         CyBufferQueue_GetReadLostPacketCount      
#define CyBuffer_GetReadResendRequestCount      CyBufferQueue_GetReadResendRequestCount   
#define CyBuffer_GetReadStartPacketCount        CyBufferQueue_GetReadStartPacketCount     
#define CyBuffer_GetReadUnexpectedResendCount   CyBufferQueue_GetReadUnexpectedResendCount
#define CyBuffer_GetWriteSize                   CyBufferQueue_GetWriteSize                
#define CyBuffer_SetWriteSize                   CyBufferQueue_SetWriteSize                
#define CyBuffer_GetWriteImageID                CyBufferQueue_GetWriteImageID             
#define CyBuffer_SetMemoryManager               CyBufferQueue_SetMemoryManager            
#define CyBuffer_ResetMemoryManager             CyBufferQueue_ResetMemoryManager          
#define CyBuffer_GetMemoryManager               CyBufferQueue_GetMemoryManager            
#define CyBuffer_SetQueueSize                   CyBufferQueue_SetQueueSize                
#define CyBuffer_GetQueueSize                   CyBufferQueue_GetQueueSize                
#define CyBuffer_GetQueueItemCount              CyBufferQueue_GetQueueItemCount           
#define CyBuffer_ClearQueue                     CyBufferQueue_ClearQueue                  
#define CyBuffer_SetQueueMode                   CyBufferQueue_SetQueueMode                
#define CyBuffer_GetQueueMode                   CyBufferQueue_GetQueueMode                
#define CyBuffer_LockForRead                    CyBufferQueue_LockForRead                 
#define CyBuffer_SignalReadEnd                  CyBufferQueue_SignalReadEnd               
#define CyBuffer_AbortRead                      CyBufferQueue_AbortRead                   
#define CyBuffer_LockForWrite                   CyBufferQueue_LockForWrite                
#define CyBuffer_SignalWriteEnd                 CyBufferQueue_SignalWriteEnd              
#define CyBuffer_AbortWrite                     CyBufferQueue_AbortWrite                  
#define CyBuffer_GetSharedMemory                CyBufferQueue_GetSharedMemory             
                                                
#endif // _CY_BUFFER_H_
