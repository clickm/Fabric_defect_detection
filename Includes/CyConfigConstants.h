// *****************************************************************************
//
// $Id: CyConfigConstants.h,v 1.5 2007/07/04 21:27:04 igors Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyConfigConstants.h
//
// Description..: 
//
// *****************************************************************************

#ifndef _CY_CONFIG_CONSTANTS_H_
#define _CY_CONFIG_CONSTANTS_H_

// Enumerations
/////////////////////////////////////////////////////////////////////////////

// Access modes, use the same values are in CyDeviceConstants
enum CyConfigAccessModes
{

    CY_CONFIG_MODE_DRV      = CY_DEVICE_ACCESS_MODE_DRV,
    CY_CONFIG_MODE_UDP      = CY_DEVICE_ACCESS_MODE_UDP,
    CY_CONFIG_MODE_TCP      = CY_DEVICE_ACCESS_MODE_TCP,
    CY_CONFIG_MODE_FILTER   = CY_DEVICE_ACCESS_MODE_FILTER,
    CY_CONFIG_MODE_EBUS     = CY_DEVICE_ACCESS_MODE_EBUS,
    CY_CONFIG_MODE_GEV      = CY_DEVICE_ACCESS_MODE_GEV,
    CY_CONFIG_MODE_GEV_EBUS = CY_DEVICE_ACCESS_MODE_GEV_EBUS,

};

// Data Sending Modes, use the same values are in CyDeviceConstants
enum CyConfigDataSendingModes
{

    CY_CONFIG_DSM_UNICAST       = CY_DEVICE_DSM_UNICAST,
    CY_CONFIG_DSM_MULTICAST	    = CY_DEVICE_DSM_MULTICAST,
    CY_CONFIG_DSM_MULTI_UNICAST = CY_DEVICE_DSM_MULTI_UNICAST,
    CY_CONFIG_DSM_ROUND_ROBIN   = CY_DEVICE_DSM_ROUND_ROBIN,
    CY_CONFIG_DSM_TRIGGER_QUEUE = CY_DEVICE_DSM_TRIGGER_QUEUE,

};


// CyConfig Parameter Definitions
/////////////////////////////////////////////////////////////////////////////

#define CY_CONFIG_PARAM_DEVICE_COUNT                    0x00000000
#define CY_CONFIG_PARAM_DEVICE_COUNT_LABEL              "Device Count"
                                                        
#define CY_CONFIG_PARAM_CURRENT_INDEX                   0x00000001
#define CY_CONFIG_PARAM_CURRENT_INDEX_LABEL             "Current Index"
                                                        
#define CY_CONFIG_PARAM_ANSWER_TIMEOUT                  0x00000002   
#define CY_CONFIG_PARAM_ANSWER_TIMEOUT_LABEL            "Answer Timeout"
                                                        
#define CY_CONFIG_PARAM_FIRST_PACKET_TIMEOUT            0x00000003
#define CY_CONFIG_PARAM_FIRST_PACKET_TIMEOUT_LABEL      "First Packet Timeout"
                                                        
#define CY_CONFIG_PARAM_PACKET_TIMEOUT                  0x00000004
#define CY_CONFIG_PARAM_PACKET_TIMEOUT_LABEL            "Packet Timeout"
                                                        
#define CY_CONFIG_PARAM_REQUEST_TIMEOUT                 0x00000005
#define CY_CONFIG_PARAM_REQUEST_TIMEOUT_LABEL           "Request Timeout"
                                                        
#define CY_CONFIG_PARAM_PACKET_SIZE                     0x00000006
#define CY_CONFIG_PARAM_PACKET_SIZE_LABEL               "Packet Size"
                                                        
#define CY_CONFIG_PARAM_COMMAND_RETRY_COUNT             0x00000007
#define CY_CONFIG_PARAM_COMMAND_RETRY_COUNT_LABEL       "Command Retry Count"
                                                        
#define CY_CONFIG_PARAM_ACCESS_MODE                     0x00000008
#define CY_CONFIG_PARAM_ACCESS_MODE_LABEL               "Access Mode"
                                                        
#define CY_CONFIG_PARAM_ADAPTER_ID                      0x00000009
#define CY_CONFIG_PARAM_ADAPTER_ID_LABEL                "Adapter ID"
                                                        
#define CY_CONFIG_PARAM_ADDRESS_IP                      0x0000000A
#define CY_CONFIG_PARAM_ADDRESS_IP_LABEL                "IP Address"     
                                                        
#define CY_CONFIG_PARAM_ADDRESS_MAC                     0x0000000B
#define CY_CONFIG_PARAM_ADDRESS_MAC_LABEL               "MAC Address"     
                                                        
#define CY_CONFIG_PARAM_DEVICE_NAME                     0x0000000C
#define CY_CONFIG_PARAM_DEVICE_NAME_LABEL               "Device Name"
                                                        
#define CY_CONFIG_PARAM_DEVICE_TYPE                     0x0000000D
#define CY_CONFIG_PARAM_DEVICE_TYPE_LABEL               "Device Type"
                                                        
#define CY_CONFIG_PARAM_HEARTBEAT_INTERVAL              0x0000000E
#define CY_CONFIG_PARAM_HEARTBEAT_INTERVAL_LABEL        "Heartbeat Interval"
                                                        
#define CY_CONFIG_PARAM_HEARTBEAT_EXPIRATION            0x0000000F
#define CY_CONFIG_PARAM_HEARTBEAT_EXPIRATION_LABEL      "Heartbeat Expiration"
                                                        
#define CY_CONFIG_PARAM_DATA_SENDING_MODE               0x00000010
#define CY_CONFIG_PARAM_DATA_SENDING_MODE_LABEL         "Data Sending Mode"

#define CY_CONFIG_PARAM_DATA_SENDING_MODE_MASTER        0x00000011
#define CY_CONFIG_PARAM_DATA_SENDING_MODE_MASTER_LABEL  "Data Sending Mode Master"

#define CY_CONFIG_PARAM_DATA_SENDING_MODE_ADDRESS       0x00000012
#define CY_CONFIG_PARAM_DATA_SENDING_MODE_ADDRESS_LABEL "Data Sending Mode Address"

#define CY_CONFIG_PARAM_SUBNET_MASK                     0x00000013
#define CY_CONFIG_PARAM_SUBNET_MASK_LABEL               "Subnet mask"     
                                                        
#define CY_CONFIG_PARAM_GATEWAY                         0x00000014
#define CY_CONFIG_PARAM_GATEWAY_LABEL                   "Gateway"     

#endif // _CY_CONFIG_CONSTANTS_H_
