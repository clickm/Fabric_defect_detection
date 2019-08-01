// *****************************************************************************
//
// $Id: CyCameraInterfaceConstants.h,v 1.9 2007/07/04 21:27:05 igors Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraInterfaceConstants.h
//
// Description..: Defines the base of a camera class.
//
// *****************************************************************************

#ifndef __CY_CAMERA_INTERFACE_CONSTANTS_H__
#define __CY_CAMERA_INTERFACE_CONSTANTS_H__

// Image type
enum CyCameraImageType
{

    CY_CAMERA_LINE_SCAN = 0,
    CY_CAMERA_AREA_SCAN = 1,

};

// Synchronization modes
enum CyCameraSynchronizationMode
{

    CY_CAMERA_FREE_RUN_PROGRAMMABLE    = 0,
    CY_CAMERA_FREE_RUN_EDGE_CONTROLLED = 1,
    CY_CAMERA_EX_SYNC_LEVEL_CONTROLLED = 2,
    CY_CAMERA_EX_SYNC_PROGRAMMABLE     = 3,
    CY_CAMERA_EX_SYNC_EDGE_CONTROLLED  = 4,

};

//
// Parameters for the CyCameraInterface object
//     
//  IMPORTANT: The parameter identifiers 0x00000000 - 0x0001000 are reserved.
//             Do not use in your own applications
//
// Each parameter is defined by an identifier and a label, where
//
//  CY_CAMERA_PARAM_name is the identifier
//  CY_CAMERA_PARAM_name_LABEL is the label
//
// These constant can be used with the Set/GetParameter functions (as derived
// from CyParameterRepository).
//
    
#define CY_CAMERA_PARAM_SIZE_X                      0x00000000
#define CY_CAMERA_PARAM_SIZE_X_LABEL                "Size X"
                                                    
#define CY_CAMERA_PARAM_SIZE_Y                      0x00000001
#define CY_CAMERA_PARAM_SIZE_Y_LABEL                "Size Y"
                                                    
#define CY_CAMERA_PARAM_OFFSET_X                    0x00000002
#define CY_CAMERA_PARAM_OFFSET_X_LABEL              "Offset X"
                                                    
#define CY_CAMERA_PARAM_OFFSET_Y                    0x00000003
#define CY_CAMERA_PARAM_OFFSET_Y_LABEL              "Offset Y"
                                                    
#define CY_CAMERA_PARAM_DECIMATION_X                0x00000004
#define CY_CAMERA_PARAM_DECIMATION_X_LABEL          "Decimation X"
                                                    
#define CY_CAMERA_PARAM_DECIMATION_Y                0x00000005
#define CY_CAMERA_PARAM_DECIMATION_Y_LABEL          "Decimation Y"

#define CY_CAMERA_PARAM_DECIMATION_BLOCK_X          0x00000006
#define CY_CAMERA_PARAM_DECIMATION_BLOCK_X_LABEL    "Decimation Block X"
                                                    
#define CY_CAMERA_PARAM_DECIMATION_BLOCK_Y          0x00000007
#define CY_CAMERA_PARAM_DECIMATION_BLOCK_Y_LABEL    "Decimation Block Y"

#define CY_CAMERA_PARAM_BINNING_X                   0x00000008
#define CY_CAMERA_PARAM_BINNING_X_LABEL             "Binning X"

#define CY_CAMERA_PARAM_BINNING_Y                   0x00000009
#define CY_CAMERA_PARAM_BINNING_Y_LABEL             "Binning Y"

#define CY_CAMERA_PARAM_PIXEL_TYPE                  0x0000000A
#define CY_CAMERA_PARAM_PIXEL_TYPE_LABEL            "Pixel Type"

#define CY_CAMERA_PARAM_TAP_QUANTITY                0x0000000B
#define CY_CAMERA_PARAM_TAP_QUANTITY_LABEL          "Tap Quantity"

#define CY_CAMERA_PARAM_IMAGE_TYPE                  0x0000000C
#define CY_CAMERA_PARAM_IMAGE_TYPE_LABEL            "Image Type"

#define CY_CAMERA_PARAM_SYNCHRO_MODE                0x0000000D
#define CY_CAMERA_PARAM_SYNCHRO_MODE_LABEL          "Synchronization Mode"

#define CY_CAMERA_PARAM_EXPOSURE_TIME               0x0000000E
#define CY_CAMERA_PARAM_EXPOSURE_TIME_LABEL         "Exposure Time"

#define CY_CAMERA_PARAM_FRAME_RATE                  0x0000000F
#define CY_CAMERA_PARAM_FRAME_RATE_LABEL            "Frame Rate"

#define CY_CAMERA_PARAM_DIGITAL_SHIFT               0x00000010
#define CY_CAMERA_PARAM_DIGITAL_SHIFT_LABEL         "Digital Shift"

#define CY_CAMERA_PARAM_TEST_PATTERN                0x00000011
#define CY_CAMERA_PARAM_TEST_PATTERN_LABEL          "Test Pattern"

#define CY_CAMERA_PARAM_IMAGE_FLIP                  0x00000012
#define CY_CAMERA_PARAM_IMAGE_FLIP_LABEL            "Image Flip"

#define CY_CAMERA_PARAM_BLACK_LEVEL                 0x00000013
#define CY_CAMERA_PARAM_BLACK_LEVEL_LABEL           "Black Level"

#define CY_CAMERA_PARAM_VENDOR                      0x00000014
#define CY_CAMERA_PARAM_VENDOR_LABEL                "Vendor Name"

#define CY_CAMERA_PARAM_MODEL                       0x00000015
#define CY_CAMERA_PARAM_MODEL_LABEL                 "Camera Model"

#define CY_CAMERA_PARAM_PRODUCT_ID                  0x00000016
#define CY_CAMERA_PARAM_PRODUCT_ID_LABEL            "Product ID"

#define CY_CAMERA_PARAM_SERIAL_NUMBER               0x00000017
#define CY_CAMERA_PARAM_SERIAL_NUMBER_LABEL         "Serial Number"

#define CY_CAMERA_PARAM_INTERLACED_INVERSION        0x00000018
#define CY_CAMERA_PARAM_INTERLACED_INVERSION_LABEL  "Interlaced Inversion"

#define CY_CAMERA_PARAM_AUTO_PARAM_IMPL             0x00000019
#define CY_CAMERA_PARAM_AUTO_PARAM_IMPL_LABEL       "Auto Parameter Implementation"

#define CY_CAMERA_PARAM_STARTING_BAYER_FLAG         0x00000020
#define CY_CAMERA_PARAM_STARTING_BAYER_FLAG_LABEL   "Starting Bayer Flag"

#define CY_CAMERA_PARAM_STARTING_BAYER_ADJUST_WITH_OFFSET       0x00000021
#define CY_CAMERA_PARAM_STARTING_BAYER_ADJUST_WITH_OFFSET_LABEL "Adjust Bayer Flag with offsets"

#define CY_CAMERA_PARAM_CONVERSION_FLAGS                    0x00000022
#define CY_CAMERA_PARAM_CONVERSION_FLAGS_LABEL              "Conversion Flags"

#define CY_CAMERA_PARAM_FILTER_RED_GAIN                     0x00000023
#define CY_CAMERA_PARAM_FILTER_RED_GAIN_LABEL               "RGB Filter Red Gain"

#define CY_CAMERA_PARAM_FILTER_GREEN_GAIN                   0x00000024
#define CY_CAMERA_PARAM_FILTER_GREEN_GAIN_LABEL             "RGB Filter Green Gain"

#define CY_CAMERA_PARAM_FILTER_BLUE_GAIN                    0x00000025
#define CY_CAMERA_PARAM_FILTER_BLUE_GAIN_LABEL              "RGB Filter Blue Gain"

#define CY_CAMERA_PARAM_FILTER_RED_OFFSET                   0x00000026
#define CY_CAMERA_PARAM_FILTER_RED_OFFSET_LABEL             "RGB Filter Red Offset"

#define CY_CAMERA_PARAM_FILTER_GREEN_OFFSET                 0x00000027
#define CY_CAMERA_PARAM_FILTER_GREEN_OFFSET_LABEL           "RGB Filter Green Offset"

#define CY_CAMERA_PARAM_FILTER_BLUE_OFFSET                  0x00000028
#define CY_CAMERA_PARAM_FILTER_BLUE_OFFSET_LABEL            "RGB Filter Blue Offset"

#define CY_CAMERA_PARAM_GAIN                        0x00000040
#define CY_CAMERA_PARAM_GAIN_LABEL                  "Gain"

#define CY_CAMERA_PARAM_OFFSET                      0x00000060
#define CY_CAMERA_PARAM_OFFSET_LABEL                "Offset"

#endif // __CY_CAMERA_INTERFACE_CONSTANTS_H__

