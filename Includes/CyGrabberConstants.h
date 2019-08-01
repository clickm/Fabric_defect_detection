// *****************************************************************************
//
// $Id: CyGrabberConstants.h,v 1.15 2007/09/10 15:55:04 jwhitwill Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrabberConstants.h
//
// Description..: Defines the base of a camera class.
//
// *****************************************************************************

#ifndef __CY_GRABBER_CONSTANTS_H__
#define __CY_GRABBER_CONSTANTS_H__

// Constants
/////////////////////////////////////////////////////////////////////////////

// Flags used when grabbing from the CyGrabber
enum CyGrabberFlags
{
    CY_GRABBER_FLAG_NO_WAIT             = 0x00010000,
    CY_GRABBER_FLAG_NO_FLUSH            = 0x00020000,
    CY_GRABBER_FLAG_REUSE_SETTINGS      = 0x00040000,
    CY_GRABBER_FLAG_GRAB_RECORDING      = 0x00080000,
    CY_GRABBER_FLAG_NO_ABORT_ON_TIMEOUT = 0x00100000,
    CY_GRABBER_FLAG_NO_TRIGGER          = 0x00200000
};


//
// Continous Pipe Count
// When using StartContinuous or StartGrabbing, WITHOUT SetForceSingleShot, the pipe
// count determines the number of requests that the device can handle.  A request is
// from the start of the frame up to the sending of the last byte of data.  So a new
// frame can start even if a previous frame is not completely sent.
//
// Values:
//      PC_CONTINUOUS: The grabber will acquired new frames up to the limit of the
//                     onboard memory.  USE THIS SETTING CAREFULLY!
//
//      PC_ONE: The grabber can only process one request at a time.  The grabber will
//              ignore all new frames until a request is completed.
//
//      PC_TWO (default): Same as above, but with two requests.
//

enum CyGrabberPipeCount
{

    CY_GRABBER_PC_CONTINUOUS = 0,
    CY_GRABBER_PC_ONE        = 1,
    CY_GRABBER_PC_TWO        = 2,
};


//
// Parameters for the CyGrabber object
//     
//  IMPORTANT: The parameter identifiers 0x00000000 - 0x0000FFF are reserved.
//             Do not use in your own applications
//
// Each parameter is defined by an identifier and a label, where
//
//  CY_GRABBER_PARAM_name is the identifier
//  CY_GRABBER_PARAM_name_LABEL is the label
//
// These constant can be used with the Set/GetParameter functions (as derived
// from CyParameterRepository).
//

#define CY_GRABBER_PARAM_SIZE_X                                     0x00000000
#define CY_GRABBER_PARAM_SIZE_X_LABEL                               "Size X"
                                                                    
#define CY_GRABBER_PARAM_SIZE_Y                                     0x00000001
#define CY_GRABBER_PARAM_SIZE_Y_LABEL                               "Size Y"
                                                                    
#define CY_GRABBER_PARAM_UNDEFINED_SIZE_X                           0x00000002
#define CY_GRABBER_PARAM_UNDEFINED_SIZE_X_LABEL                     "Undefined Size X"
                                                                    
#define CY_GRABBER_PARAM_UNDEFINED_SIZE_Y                           0x00000003
#define CY_GRABBER_PARAM_UNDEFINED_SIZE_Y_LABEL                     "Undefined Size Y"
                                                                    
#define CY_GRABBER_PARAM_OFFSET_X                                   0x00000004
#define CY_GRABBER_PARAM_OFFSET_X_LABEL                             "Offset X"
                                                                    
#define CY_GRABBER_PARAM_OFFSET_Y                                   0x00000005
#define CY_GRABBER_PARAM_OFFSET_Y_LABEL                             "Offset Y"
                                                                    
#define CY_GRABBER_PARAM_DECIMATION_X                               0x00000006
#define CY_GRABBER_PARAM_DECIMATION_X_LABEL                         "Decimation X"
                                                                    
#define CY_GRABBER_PARAM_DECIMATION_Y                               0x00000007
#define CY_GRABBER_PARAM_DECIMATION_Y_LABEL                         "Decimation Y"
                                                                    
#define CY_GRABBER_PARAM_DECIMATION_BLOCK_X                         0x00000008
#define CY_GRABBER_PARAM_DECIMATION_BLOCK_X_LABEL                   "Decimation Block X"
                                                                    
#define CY_GRABBER_PARAM_DECIMATION_BLOCK_Y                         0x00000009
#define CY_GRABBER_PARAM_DECIMATION_BLOCK_Y_LABEL                   "Decimation Block Y"
                                                                    
#define CY_GRABBER_PARAM_PIXEL_DEPTH                                0x0000000A
#define CY_GRABBER_PARAM_PIXEL_DEPTH_LABEL                          "Pixel Depth"
                                                                    
#define CY_GRABBER_PARAM_TAP_QUANTITY                               0x0000000B
#define CY_GRABBER_PARAM_TAP_QUANTITY_LABEL                         "Tap Quantity"
                                                                    
#define CY_GRABBER_PARAM_RGB_ENABLED                                0x0000000C
#define CY_GRABBER_PARAM_RGB_ENABLED_LABEL                          "RGB Enabled"
#define CY_GRABBER_PARAM_RGB_ENABLED_ALIAS_0                        "RGN Enabled"
                                                                    
#define CY_GRABBER_PARAM_LINE_SCAN                                  0x0000000D
#define CY_GRABBER_PARAM_LINE_SCAN_LABEL                            "Line Scan"
                                                                    
#define CY_GRABBER_PARAM_INTERLACED                                 0x0000000E
#define CY_GRABBER_PARAM_INTERLACED_LABEL                           "Interlaced"
                                                                    
#define CY_GRABBER_PARAM_NORMALIZED                                 0x0000000F
#define CY_GRABBER_PARAM_NORMALIZED_LABEL                           "Normalized"
                                                                    
#define CY_GRABBER_PARAM_PACKED                                     0x00000010
#define CY_GRABBER_PARAM_PACKED_LABEL                               "Packed"
                                                                    
#define CY_GRABBER_PARAM_INTERLACED_FIELD_MODE                      0x00000011
#define CY_GRABBER_PARAM_INTERLACED_FIELD_MODE_LABEL                "Interlaced Field Mode"

#define CY_GRABBER_PARAM_INSERT_METADATA                            0x00000012
#define CY_GRABBER_PARAM_INSERT_METADATA_LABEL                      "Insert metadata"
#define CY_GRABBER_PARAM_INSERT_METADATA_ALIAS_0                    "Image Sequence In Data"
#define CY_GRABBER_PARAM_IMAGE_SEQUENCE_IN_DATA                     CY_GRABBER_PARAM_INSERT_METADATA
#define CY_GRABBER_PARAM_IMAGE_SEQUENCE_IN_DATA_LABEL               CY_GRABBER_PARAM_INSERT_METADATA_LABEL
                                                                    
#define CY_GRABBER_PARAM_WATER_LEVEL                                0x00000013
#define CY_GRABBER_PARAM_WATER_LEVEL_LABEL                          "Water Level"
                                                                    
#define CY_GRABBER_PARAM_BAD_IMAGE_PASSTHROUGH                      0x00000014
#define CY_GRABBER_PARAM_BAD_IMAGE_PASSTHROUGH_LABEL                "Bad Image Passthrough"
                                                                    
#define CY_GRABBER_PARAM_IGNORE_MISSING_PACKETS                     0x00000015
#define CY_GRABBER_PARAM_IGNORE_MISSING_PACKETS_LABEL               "Ignore Missing Packets"
                                                                    
#define CY_GRABBER_PARAM_MAXIMUM_PENDING_REQUESTS                   0x00000016
#define CY_GRABBER_PARAM_MAXIMUM_PENDING_REQUESTS_LABEL             "Maximum Pending Requests"
                                                                    
#define CY_GRABBER_PARAM_PIXEL_SHIFTING                             0x00000017
#define CY_GRABBER_PARAM_PIXEL_SHIFTING_LABEL                       "Pixel Shifting"
                                                                    
#define CY_GRABBER_PARAM_PIXEL_INVERSION                            0x00000018
#define CY_GRABBER_PARAM_PIXEL_INVERSION_LABEL                      "Pixel Inversion"
                                                                    
#define CY_GRABBER_PARAM_PORT_MAPPING                               0x00000019
#define CY_GRABBER_PARAM_PORT_MAPPING_LABEL                         "Port Mapping"

#define CY_GRABBER_PARAM_IMAGE_SIZE                                 0x00000020
#define CY_GRABBER_PARAM_IMAGE_SIZE_LABEL                           "Image Size"

#define CY_GRABBER_PARAM_CHANNEL_COUNT                              0x00000021
#define CY_GRABBER_PARAM_CHANNEL_COUNT_LABEL                        "Channel Count"
                                                                    
#define CY_GRABBER_PARAM_MULTI_CHANNEL                              0x00000022
#define CY_GRABBER_PARAM_MULTI_CHANNEL_LABEL                        "Multi Channel"

#define CY_GRABBER_PARAM_SINGLE_CHANNEL_ID                          0x00000023
#define CY_GRABBER_PARAM_SINGLE_CHANNEL_ID_LABEL                    "Single Mode Channel ID"

#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_ENABLED                 0x00000024
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_ENABLED_LABEL           "Enable Hardware Tap Reconstruction"

#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_SEGMENTED               0x00000025
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_SEGMENTED_LABEL         "Tap Reconstruction Segmented"

#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_TIME_MULTIPLEXED        0x00000026
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_TIME_MULTIPLEXED_LABEL  "Tap Reconstruction Time Multiplexed"

#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_TAPS_PER_ROW            0x00000027
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_TAPS_PER_ROW_LABEL      "Tap Reconstruction Taps Per Row"

#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_TAPS_PER_COLUMN         0x00000028
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_TAPS_PER_COLUMN_LABEL   "Tap Reconstruction Taps Per Column"

#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_SENSOR_WIDTH            0x00000029
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_SENSOR_WIDTH_LABEL      "Tap Reconstruction Sensor Width"

#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_SENSOR_HEIGHT           0x0000002A
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_SENSOR_HEIGHT_LABEL     "Tap Reconstruction Sensor Height"

#define CY_GRABBER_PARAM_PIXEL_TYPE                                 0x00000030
#define CY_GRABBER_PARAM_PIXEL_TYPE_LABEL                           "Pixel Type"

#define CY_GRABBER_PARAM_STARTING_BAYER_FLAG                        0x00000031
#define CY_GRABBER_PARAM_STARTING_BAYER_FLAG_LABEL                  "Starting Bayer Flag"

#define CY_GRABBER_PARAM_STARTING_BAYER_ADJUST_WITH_OFFSET          0x00000032
#define CY_GRABBER_PARAM_STARTING_BAYER_ADJUST_WITH_OFFSET_LABEL    "Adjust Bayer Flag with offsets"

#define CY_GRABBER_PARAM_CONVERSION_FLAGS                           0x00000033
#define CY_GRABBER_PARAM_CONVERSION_FLAGS_LABEL                     "Conversion Flags"

#define CY_GRABBER_PARAM_INTERLACED_INVERSION                       0x00000034
#define CY_GRABBER_PARAM_INTERLACED_INVERSION_LABEL                 "Interlaced Inversion"

#define CY_GRABBER_PARAM_FORCE_SINGLE_SHOT                          0x00000040
#define CY_GRABBER_PARAM_FORCE_SINGLE_SHOT_LABEL                    "Force Single Shot"
                                                                    
#define CY_GRABBER_PARAM_FRAME_SKIP                                 0x00000050
#define CY_GRABBER_PARAM_FRAME_SKIP_LABEL                           "Frame Skip"
                                                                    
#define CY_GRABBER_PARAM_PLC_TRIGGER                                0x00000060
#define CY_GRABBER_PARAM_PLC_TRIGGER_LABEL                          "PLC Trigger"
#define CY_GRABBER_PARAM_PLC_TRIGGER_ALIAS_0                        "GPIO Trigger"
#define CY_GRABBER_PARAM_GPIO_TRIGGER                               CY_GRABBER_PARAM_PLC_TRIGGER
#define CY_GRABBER_PARAM_GPIO_TRIGGER_LABEL                         CY_GRABBER_PARAM_PLC_TRIGGER_LABEL
                                                                   
#define CY_GRABBER_PARAM_AUTO_INTERNAL_RETRIGGER                    0x00000070
#define CY_GRABBER_PARAM_AUTO_INTERNAL_RETRIGGER_LABEL              "Automatic Internal Retrigger"
                                                                    
#define CY_GRABBER_PARAM_PIPE_COUNT                                 0x00000080
#define CY_GRABBER_PARAM_PIPE_COUNT_LABEL                           "Pipe Count"

// The following parameters are tap specific, so we reserve a 16-item count for each
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_RIGHT_TO_LEFT           0x00000090 // to 0x0000009F is reserved for multiple taps
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_RIGHT_TO_LEFT_LABEL     "Tap Right To Left"
                                                                    
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_BOTTOM_TO_TOP           0x000000A0 // to 0x000000AF is reserved for multiple taps
#define CY_GRABBER_PARAM_TAP_RECONSTRUCTION_BOTTOM_TO_TOP_LABEL     "Tap Bottom To Top"

#endif // __CY_GRABBER_CONSTANTS_H__


