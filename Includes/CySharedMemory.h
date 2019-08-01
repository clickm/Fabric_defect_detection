// *****************************************************************************
//
// $Id: CySharedMemory.h,v 1.12 2007/07/04 21:27:04 igors Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CySharedMemory.h
//
// Description..: Provided for backward-compatibility, points to renamed CyImageInfo.h
//
// *****************************************************************************

#ifndef __CY_SHARED_MEMORY_H__
#define __CY_SHARED_MEMORY_H__

#include "CyImageInfo.h"

#define CySharedMemoryH                         CyImageInfoH                        
#define CySharedMemory_Init                     CyImageInfo_Init                    
#define CySharedMemory_Destroy                  CyImageInfo_Destroy                 
#define CySharedMemory_Reset                    CyImageInfo_Reset                   
#define CySharedMemory_GetStatus                CyImageInfo_GetStatus               
#define CySharedMemory_GetImageStatus           CyImageInfo_GetImageStatus          
#define CySharedMemory_GetTimestamp             CyImageInfo_GetTimestamp            
#define CySharedMemory_GetImageID               CyImageInfo_GetImageID              
#define CySharedMemory_GetSubChannelID          CyImageInfo_GetSubChannelID         
#define CySharedMemory_GetSize                  CyImageInfo_GetSize                 
#define CySharedMemory_GetPayloadType           CyImageInfo_GetPayloadType          
#define CySharedMemory_GetExpectedResendCount   CyImageInfo_GetExpectedResendCount  
#define CySharedMemory_GetIgnoredPacketCount    CyImageInfo_GetIgnoredPacketCount   
#define CySharedMemory_GetLostPacketCount       CyImageInfo_GetLostPacketCount      
#define CySharedMemory_GetResendRequestCount    CyImageInfo_GetResendRequestCount   
#define CySharedMemory_GetStartPacketCount      CyImageInfo_GetStartPacketCount     
#define CySharedMemory_GetUnexpectedResendCount CyImageInfo_GetUnexpectedResendCount

#endif // __CY_SHARED_MEMORY_H__

