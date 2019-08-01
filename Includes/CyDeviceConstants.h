// *****************************************************************************
//
// $Id: CyDeviceConstants.h,v 1.35 2009/06/16 16:40:06 jwhitwill Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyDeviceConstants.h
//
// Description..: 
//
// *****************************************************************************

#ifndef _CY_DEVICE_CONSTANTS_H_
#define _CY_DEVICE_CONSTANTS_H_

// Callback Identifiers
/////////////////////////////////////////////////////////////////////////////

enum CyDeviceCallbackIDs
{

    CY_DEVICE_CB_ON_DEVICE_RESET   = 0,
    CY_DEVICE_CB_ON_INTERRUPT_GPIO = 1,

    CY_DEVICE_CB_ON_GEV_EVENT      = 2,
    CY_DEVICE_CB_ON_GEV_EVENT_DATA = 3,

	CY_DEVICE_CB_QUANTITY = 4
};


// Port Identifiers
/////////////////////////////////////////////////////////////////////////////

enum CyDevicePorts
{

    CY_DEVICE_PORT_INTERNAL = 0,
    CY_DEVICE_PORT_SERIAL_0 = 1,
    CY_DEVICE_PORT_SERIAL_1 = 2,
    CY_DEVICE_PORT_I2C      = 3,
    CY_DEVICE_PORT_USRT_0   = 4, // deprecated, replaced with BULK_0
    CY_DEVICE_PORT_BULK_0   = 4,
    CY_DEVICE_PORT_BUS_0    = 5,
    CY_DEVICE_PORT_BULK_1   = 6,
    CY_DEVICE_PORT_BULK_2   = 7,
    CY_DEVICE_PORT_BULK_3   = 8,

};



// Flags
/////////////////////////////////////////////////////////////////////////////

enum CyDeviceFlags
{

    CY_DEVICE_FLAG_COMMAND_ONLY                 = 0x00000001,
    CY_DEVICE_FLAG_SET_IP_ON_CONNECT            = 0x00000002,
    CY_DEVICE_FLAG_BAD_IMAGE_PASSTHROUGH        = 0x00000004,
    CY_DEVICE_FLAG_DATA_ONLY                    = 0x00000008,
    CY_DEVICE_FLAG_NO_RESEND_PACKETS            = 0x00000010,
    CY_DEVICE_FLAG_MULTICAST_NO_DATA            = 0x00000020,
    CY_DEVICE_FLAG_NO_DATA_LINK_CHECK_ON_ERROR  = 0x00000040,
    CY_DEVICE_FLAG_NO_LOAD_EXTENSION_ON_CONNECT = 0x00000100,
    CY_DEVICE_FLAG_NO_INTERRUPT_PORT_KEEP_ALIVE = 0x00000200,

};


// Device Access modes
/////////////////////////////////////////////////////////////////////////////

enum CyDeviceAccessModes
{

    CY_DEVICE_ACCESS_MODE_DRV      = 0,
    CY_DEVICE_ACCESS_MODE_UDP      = 1,
    CY_DEVICE_ACCESS_MODE_TCP      = 2, // deprecated
    CY_DEVICE_ACCESS_MODE_FILTER   = 3, // deprecated
    CY_DEVICE_ACCESS_MODE_EBUS     = 4,
    CY_DEVICE_ACCESS_MODE_GEV      = 5,
    CY_DEVICE_ACCESS_MODE_GEV_EBUS = 6,

};

// Data Sending Modes
/////////////////////////////////////////////////////////////////////////////

enum CyDeviceDataSendingModes
{

    CY_DEVICE_DSM_UNICAST       = 0,
    CY_DEVICE_DSM_MULTICAST	    = 1,
    CY_DEVICE_DSM_MULTI_UNICAST = 2,
    CY_DEVICE_DSM_ROUND_ROBIN   = 3,
    CY_DEVICE_DSM_TRIGGER_QUEUE = 4,

};


// Miscellaneous
/////////////////////////////////////////////////////////////////////////////

    // Maximum pending receive data
    #define CY_DEVICE_MAX_PENDING_RECEIVE_DATA      4


// Parameters for the CyDevice object
/////////////////////////////////////////////////////////////////////////////

//     
//  IMPORTANT: The parameter identifiers 0x00000000 - 0x0000fff are reserved.
//             Do not use in your own applications
//
// Each parameter is defined by an identifier and a label, where
//
//  CY_DEVICE_PARAM_name is the identifier
//  CY_DEVICE_PARAM_name_LABEL is the label
//
// These constant can be used with the Set/GetParameter functions (as derived
// from CyParameterRepository).
//

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_DEVICE_ID                           0x00000000
    #define CY_DEVICE_PARAM_DEVICE_ID_LABEL                     "Device ID"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_MODULE_ID                           0x00000001
    #define CY_DEVICE_PARAM_MODULE_ID_LABEL                     "Module ID"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_SUB_MODULE_ID                       0x00000002
    #define CY_DEVICE_PARAM_SUB_MODULE_ID_LABEL                 "Sub Module ID"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_VENDOR_ID                           0x00000003
    #define CY_DEVICE_PARAM_VENDOR_ID_LABEL                     "Vendor ID"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_VERSION_MAJ                         0x00000004
    #define CY_DEVICE_PARAM_VERSION_MAJ_LABEL                   "Firmware version (major)"
    #define CY_DEVICE_PARAM_VERSION_MAJ_ALIAS_0                 "Version Major"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_VERSION_MIN                         0x00000005
    #define CY_DEVICE_PARAM_VERSION_MIN_LABEL                   "Firmware version (minor)"
    #define CY_DEVICE_PARAM_VERSION_MIN_ALIAS_0                 "Version Minor"

    #define CY_DEVICE_PARAM_ANSWER_TIMEOUT                      0x00000006
    #define CY_DEVICE_PARAM_ANSWER_TIMEOUT_LABEL                "Answer timeout (ms)"
    #define CY_DEVICE_PARAM_ANSWER_TIMEOUT_ALIAS_0              "Answer Timeout"

    #define CY_DEVICE_PARAM_FIRST_PACKET_TIMEOUT                0x00000007
    #define CY_DEVICE_PARAM_FIRST_PACKET_TIMEOUT_LABEL          "First packet timeout (ms)"
    #define CY_DEVICE_PARAM_FIRST_PACKET_TIMEOUT_ALIAS_0        "First Packet Timeout"

    #define CY_DEVICE_PARAM_PACKET_TIMEOUT                      0x00000008
    #define CY_DEVICE_PARAM_PACKET_TIMEOUT_LABEL                "Packet timeout (ms)"
    #define CY_DEVICE_PARAM_PACKET_TIMEOUT_ALIAS_0              "Packet Timeout"

    #define CY_DEVICE_PARAM_REQUEST_TIMEOUT                     0x00000009
    #define CY_DEVICE_PARAM_REQUEST_TIMEOUT_LABEL               "Request timeout (ms)"
    #define CY_DEVICE_PARAM_REQUEST_TIMEOUT_ALIAS_0             "Request Timeout"

    #define CY_DEVICE_PARAM_COMMAND_RETRY_COUNT                 0x0000000A
    #define CY_DEVICE_PARAM_COMMAND_RETRY_COUNT_LABEL           "Command retry count"
    #define CY_DEVICE_PARAM_COMMAND_RETRY_COUNT_ALIAS_0         "Command Retry Count"

    #define CY_DEVICE_PARAM_PACKET_SIZE                         0x0000000B
    #define CY_DEVICE_PARAM_PACKET_SIZE_LABEL                   "Packet size"
    #define CY_DEVICE_PARAM_PACKET_SIZE_ALIAS_0                 "Packet Size"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_ADAPTER_ID                          0x0000000C
    #define CY_DEVICE_PARAM_ADAPTER_ID_LABEL                    "MAC address (NIC)"
    #define CY_DEVICE_PARAM_ADAPTER_ID_ALIAS_0                  "Adapter ID"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_IP                                  0x0000000D
    #define CY_DEVICE_PARAM_IP_LABEL                            "IP Address"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_MAC                                 0x0000000E
    #define CY_DEVICE_PARAM_MAC_LABEL                           "MAC Address (IP Engine)"
    #define CY_DEVICE_PARAM_MAC_ALIAS_0                         "MAC Address"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_DEVICE_MODE                         0x0000000F
    #define CY_DEVICE_PARAM_DEVICE_MODE_LABEL                   "IP Engine communication mode"
    #define CY_DEVICE_PARAM_DEVICE_MODE_ALIAS_0                 "Device Mode"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_DEVICE_NAME                         0x00000010
    #define CY_DEVICE_PARAM_DEVICE_NAME_LABEL                   "IP Engine device name"
    #define CY_DEVICE_PARAM_DEVICE_NAME_ALIAS_0                 "Device Name"
    
    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_DEVICE_TYPE                         0x00000011
    #define CY_DEVICE_PARAM_DEVICE_TYPE_LABEL                   "Camera type"
    #define CY_DEVICE_PARAM_DEVICE_TYPE_ALIAS_0                 "Device Type"

    // This parameter is read-only and indicates if the device supports
    // a hearbeat or not
    #define CY_DEVICE_PARAM_SUPPORTS_HEARTBEAT                  0x00000012
    #define CY_DEVICE_PARAM_SUPPORTS_HEARTBEAT_LABEL            "Supports Heartbeat"

    #define CY_DEVICE_PARAM_ENABLE_HEARTBEAT                    0x00000013
    #define CY_DEVICE_PARAM_ENABLE_HEARTBEAT_LABEL              "Enable Heartbeat"
                                                        
    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_HEARTBEAT_INTERVAL                  0x00000014
    #define CY_DEVICE_PARAM_HEARTBEAT_INTERVAL_LABEL            "Heartbeat interval (ms)"
    #define CY_DEVICE_PARAM_HEARTBEAT_INTERVAL_ALIAS_0          "Heartbeat Interval"
                                                        
    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_HEARTBEAT_EXPIRATION                0x00000015
    #define CY_DEVICE_PARAM_HEARTBEAT_EXPIRATION_LABEL          "Heartbeat expiration (ms)"
    #define CY_DEVICE_PARAM_HEARTBEAT_EXPIRATION_ALIAS_0        "Heartbeat Expiration"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE                   0x00000017
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_LABEL             "Data sending mode"
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_ALIAS_0           "Data Sending Mode"    

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_MASTER            0x00000018
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_MASTER_LABEL      "Data sending mode master"
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_MASTER_ALIAS_0    "Data Sending Mode Master"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_ADDRESS           0x00000019
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_ADDRESS_LABEL     "Data sending mode address"
    #define CY_DEVICE_PARAM_DATA_SENDING_MODE_ADDRESS_ALIAS_0   "Data Sending Mode Address"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_CHANNEL_COUNT                       0x0000001A
    #define CY_DEVICE_PARAM_CHANNEL_COUNT_LABEL                 "Channel count"
    #define CY_DEVICE_PARAM_CHANNEL_COUNT_ALIAS_0               "Channel Count"

    #define CY_DEVICE_PARAM_DATA_GENERATOR_0                    0x0000001B
    #define CY_DEVICE_PARAM_DATA_GENERATOR_0_LABEL              "Emit test pattern - channel 0"
    #define CY_DEVICE_PARAM_DATA_GENERATOR_0_ALIAS_0            "Data Generator"
    #define CY_DEVICE_PARAM_DATA_GENERATOR                      CY_DEVICE_PARAM_DATA_GENERATOR_0
    #define CY_DEVICE_PARAM_DATA_GENERATOR_LABEL                CY_DEVICE_PARAM_DATA_GENERATOR_0_LABEL

    #define CY_DEVICE_PARAM_RECEIVE_ANSWER_BEHAVIOUR            0x0000001C
    #define CY_DEVICE_PARAM_RECEIVE_ANSWER_BEHAVIOUR_LABEL      "ReceiveAnswer behavior"
    #define CY_DEVICE_PARAM_RECEIVE_ANSWER_BEHAVIOUR_ALIAS_0    "ReceiveAnswer Behaviour"

    // Read-only parameter that indicates if the device supports the static config
    #define CY_DEVICE_PARAM_SUPPORTS_STATIC_CONFIG              0x0000001D
    #define CY_DEVICE_PARAM_SUPPORTS_STATIC_CONFIG_LABEL        "Save to flash feature supported"
    #define CY_DEVICE_PARAM_SUPPORTS_STATIC_CONFIG_ALIAS_0      "Supports Static Configuration"

    #define CY_DEVICE_PARAM_DATA_GENERATOR_1                    0x0000001E
    #define CY_DEVICE_PARAM_DATA_GENERATOR_1_LABEL              "Emit test pattern - channel 1"

    // The following parameters controls the socket ports used when using the
    // Netword Stack.  There are 3 ports to configure: command, interrupt and
    // data.  A value of 0 indicates that the network stack can use any 
    // available port
    #define CY_DEVICE_PARAM_STACK_COMMAND_PORT                  0x00000020
    #define CY_DEVICE_PARAM_STACK_COMMAND_PORT_LABEL            "Network stack UDP command port"
    #define CY_DEVICE_PARAM_STACK_COMMAND_PORT_ALIAS_0          "Network Stack UDP Command Port"
    #define CY_DEVICE_PARAM_STACK_INTERRUPT_PORT                0x00000021
    #define CY_DEVICE_PARAM_STACK_INTERRUPT_PORT_LABEL          "Network stack UDP interrupt port"
    #define CY_DEVICE_PARAM_STACK_INTERRUPT_PORT_ALIAS_0        "Network Stack UDP Interrupt Port"
    #define CY_DEVICE_PARAM_STACK_DATA_PORT                     0x00000022
    #define CY_DEVICE_PARAM_STACK_DATA_PORT_LABEL               "Network stack UDP data port"
    #define CY_DEVICE_PARAM_STACK_DATA_PORT_ALIAS_0             "Network Stack UDP Data Port"

    #define CY_DEVICE_PARAM_MULTICAST_MASTER_NO_JOIN            0x00000023
    #define CY_DEVICE_PARAM_MULTICAST_MASTER_NO_JOIN_LABEL      "Multicast master joins group"
    #define CY_DEVICE_PARAM_MULTICAST_MASTER_NO_JOIN_ALIAS_0    "Multicast Master Joins Group"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_SUBNET_MASK                         0x00000024
    #define CY_DEVICE_PARAM_SUBNET_MASK_LABEL                   "Subnet mask"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_GATEWAY                             0x00000025
    #define CY_DEVICE_PARAM_GATEWAY_LABEL                       "Gateway"

    // This parameter is read-only when the device is connected
    #define CY_DEVICE_PARAM_AUTO_PACKET_SIZE                    0x00000026
    #define CY_DEVICE_PARAM_AUTO_PACKET_SIZE_LABEL              "Automatic packet size"

    #define CY_DEVICE_PARAM_VERSION_SUB                         0x00000027
    #define CY_DEVICE_PARAM_VERSION_SUB_LABEL                   "Firmware version (sub-minor)"
    #define CY_DEVICE_PARAM_VERSION_SUB_ALIAS_0                 "Version Sub"

#endif // _CY_DEVICE_CONSTANTS_H_


