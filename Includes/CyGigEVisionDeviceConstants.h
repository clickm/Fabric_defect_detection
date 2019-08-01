// *****************************************************************************
//
//     Copyright (c) 2006, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGigEVisionDeviceConstants.h
//
// Description..: 
//
// *****************************************************************************

#pragma once

#ifndef __CY_GIGE_VISION_DEVICE_CONSTANTS_H__
#define __CY_GIGE_VISION_DEVICE_CONSTANTS_H__

#define CY_GIGE_VISION_DEVICE_PARAM_CONVERSION_FLAGS                    0x00000000
#define CY_GIGE_VISION_DEVICE_PARAM_CONVERSION_FLAGS_LABEL              "Conversion Flags"

#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_RED_GAIN                     0x00000001
#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_RED_GAIN_LABEL               "RGB Filter Red Gain"

#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_GREEN_GAIN                   0x00000002
#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_GREEN_GAIN_LABEL             "RGB Filter Green Gain"

#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_BLUE_GAIN                    0x00000003
#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_BLUE_GAIN_LABEL              "RGB Filter Blue Gain"

#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_RED_OFFSET                   0x00000004
#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_RED_OFFSET_LABEL             "RGB Filter Red Offset"

#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_GREEN_OFFSET                 0x00000005
#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_GREEN_OFFSET_LABEL           "RGB Filter Green Offset"

#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_BLUE_OFFSET                  0x00000006
#define CY_GIGE_VISION_DEVICE_PARAM_FILTER_BLUE_OFFSET_LABEL            "RGB Filter Blue Offset"

#define CY_GIGE_VISION_DEVICE_PARAM_GENICAM_XML_SOURCE                  0x00000007
#define CY_GIGE_VISION_DEVICE_PARAM_GENICAM_XML_SOURCE_LABEL            "GenICam XML Source"

#define CY_GIGE_VISION_DEVICE_PARAM_BAD_IMAGE_PASSTHROUGH               0x00000008
#define CY_GIGE_VISION_DEVICE_PARAM_BAD_IMAGE_PASSTHROUGH_LABEL         "Bad Image Passthrough"

#define CY_GIGE_VISION_DEVICE_PARAM_BAD_IGNORE_MISSING_PACKETS          0x00000009
#define CY_GIGE_VISION_DEVICE_PARAM_BAD_IGNORE_MISSING_PACKETS_LABEL    "Ignore Missing Packets"
                                                                    
#define CY_GIGE_VISION_DEVICE_PARAM_MAXIMUM_PENDING_REQUESTS            0x00000010
#define CY_GIGE_VISION_DEVICE_PARAM_MAXIMUM_PENDING_REQUESTS_LABEL      "Maximum Pending Requests"

#endif // __CY_GIGE_VISION_DEVICE_CONSTANTS_H__
