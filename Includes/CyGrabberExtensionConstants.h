// *****************************************************************************
//
// $Id: CyGrabberExtensionConstants.h,v 1.15 2007/07/04 21:27:05 igors Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrabberExtensionConstants.h
//
// Description..: Extension interface for CyGrabber
//
// *****************************************************************************

#ifndef _CY_GRABBER_EXTENSION_CONSTANTS_H_
#define _CY_GRABBER_EXTENSION_CONSTANTS_H_

// Camera Link Grabber Extension
/////////////////////////////////////////////////////////////////////////////

// Identifier of the extensions

#define CY_GRABBER_EXT_CAMERA_LINK          0x00000000

// Parameters of the Camera Link extension

    #define CY_CAMERA_LINK_SERIAL_SELECT                0x0000000
    #define CY_CAMERA_LINK_SERIAL_SELECT_LABEL          "Serial Select"          
                                                        
    #define CY_CAMERA_LINK_DVAL_ENABLED                 0x00000001
    #define CY_CAMERA_LINK_DVAL_ENABLED_LABEL           "Data Valid Enabled"
                                                        
    #define CY_CAMERA_LINK_DVAL_LOW_POLARITY            0x00000002
    #define CY_CAMERA_LINK_DVAL_LOW_POLARITY_LABEL      "Data Valid Polarity"
                                                        
    #define CY_CAMERA_LINK_LVAL_LOW_POLARITY            0x00000003
    #define CY_CAMERA_LINK_LVAL_LOW_POLARITY_LABEL      "Line Valid Polarity"
                                                        
    #define CY_CAMERA_LINK_FVAL_LOW_POLARITY            0x00000004
    #define CY_CAMERA_LINK_FVAL_LOW_POLARITY_LABEL      "Frame Valid Polarity"

    #define CY_CAMERA_LINK_LVAL_EDGE_SENSITIVE          0x00000005
    #define CY_CAMERA_LINK_LVAL_EDGE_SENSITIVE_LABEL    "Line Valid Edge Sensitive"

    #define CY_CAMERA_LINK_FVAL_EDGE_SENSITIVE          0x00000006
    #define CY_CAMERA_LINK_FVAL_EDGE_SENSITIVE_LABEL    "Frame Valid Edge Sensitive"

    // This parameter is read only
    #define CY_CAMERA_LINK_CAMERA_CLOCK_PRESENT         0x00000007
    #define CY_CAMERA_LINK_CAMERA_CLOCK_PRESENT_LABEL   "Clock Present"

    #define CY_CAMERA_LINK_FVAL_FUNCTION_SELECT         0x00000008
    #define CY_CAMERA_LINK_FVAL_FUNCTION_SELECT_LABEL   "Frame Valid Function Select"          

    #define CY_CAMERA_LINK_LVAL_FUNCTION_SELECT         0x00000009
    #define CY_CAMERA_LINK_LVAL_FUNCTION_SELECT_LABEL   "Line Valid Function Select"



// Camera LVDS Grabber Extension
/////////////////////////////////////////////////////////////////////////////

// Identifier of the extensions
// Same identifier as Camera Link

#define CY_GRABBER_EXT_CAMERA_LVDS          0x00000000

// Parameters of the camera lvds extension

    #define CY_CAMERA_LVDS_SERIAL_SELECT                0x0000000
    #define CY_CAMERA_LVDS_SERIAL_SELECT_LABEL          "Serial Select"          

    #define CY_CAMERA_LVDS_DVAL_ENABLED                 0x00000001
    #define CY_CAMERA_LVDS_DVAL_ENABLED_LABEL           "Data Valid Enabled"
                                                        
    #define CY_CAMERA_LVDS_DVAL_LOW_POLARITY            0x00000002
    #define CY_CAMERA_LVDS_DVAL_LOW_POLARITY_LABEL      "Data Valid Polarity"
                                                        
    #define CY_CAMERA_LVDS_LVAL_LOW_POLARITY            0x00000003
    #define CY_CAMERA_LVDS_LVAL_LOW_POLARITY_LABEL      "Line Valid Polarity"
                                                        
    #define CY_CAMERA_LVDS_FVAL_LOW_POLARITY            0x00000004
    #define CY_CAMERA_LVDS_FVAL_LOW_POLARITY_LABEL      "Frame Valid Polarity"

    #define CY_CAMERA_LVDS_LVAL_EDGE_SENSITIVE          0x00000005
    #define CY_CAMERA_LVDS_LVAL_EDGE_SENSITIVE_LABEL    "Line Valid Edge Sensitive"

    #define CY_CAMERA_LVDS_FVAL_EDGE_SENSITIVE          0x00000006
    #define CY_CAMERA_LVDS_FVAL_EDGE_SENSITIVE_LABEL    "Frame Valid Edge Sensitive"

    // This parameter is read only
    #define CY_CAMERA_LVDS_CAMERA_CLOCK_PRESENT         0x00000007
    #define CY_CAMERA_LVDS_CAMERA_CLOCK_PRESENT_LABEL   "Clock Present"

    #define CY_CAMERA_LVDS_FVAL_FUNCTION_SELECT         0x00000008
    #define CY_CAMERA_LVDS_FVAL_FUNCTION_SELECT_LABEL   "Frame Valid Function Select"          

    #define CY_CAMERA_LVDS_LVAL_FUNCTION_SELECT         0x00000009
    #define CY_CAMERA_LVDS_LVAL_FUNCTION_SELECT_LABEL   "Line Valid Function Select"
 
    #define CY_CAMERA_LVDS_GPIO_OUTPUT_ENABLED          0x0000000A
    #define CY_CAMERA_LVDS_GPIO_OUTPUT_ENABLED_LABEL    "GPIO Output Enabled"

    // read-only
    #define CY_CAMERA_LVDS_CHANNEL1_CLOCK_PRESENT       0x0000000B
    #define CY_CAMERA_LVDS_CHANNEL1_CLOCK_PRESENT_LABEL "Channel 1 Clock Present"

    // read-only
    #define CY_CAMERA_LVDS_CHANNEL0_MODE                0x0000000C
    #define CY_CAMERA_LVDS_CHANNEL0_MODE_LABEL          "Channel 0 Mode"

    // read-only
    #define CY_CAMERA_LVDS_CHANNEL1_MODE                0x0000000D
    #define CY_CAMERA_LVDS_CHANNEL1_MODE_LABEL          "Channel 1 Mode"


//
// Grabber metadata extension
////////////////////////////////////////////////////////////////////////////////

#define CY_GRABBER_METADATA_EXTENSION          0x00000001
#define CY_GRABBER_METADATA_EXTENSION_LABEL    "Grabber metadata"

    #define CY_GRABBER_METADATA_INSERTION_MODE          0x00000000
    #define CY_GRABBER_METADATA_INSERTION_MODE_LABEL    "Metadata insertion mode"

    #define CY_GRABBER_METADATA_SOURCE_SELECTION        0x00000001
    #define CY_GRABBER_METADATA_SOURCE_SELECTION_LABEL  "Metadata source selection"

    #define CY_GRABBER_METADATA_MSB_OVERRIDE            0x000000002
    #define CY_GRABBER_METADATA_MSB_OVERRIDE_LABEL      "Metadata MSB override"


// Video Decoder Source
// ID: 0x00000010 - 0x0000001F (one per channel)
/////////////////////////////////////////////////////////////////////////////  

#define CY_GRABBER_EXT_ANALOG_SOURCE           0x00000010

    // Input Selection Parameters
    /////////////////////////////////////////////////////////////////////////////  

    #define CY_GRABBER_ANALOG_VS_INPUT                      0x00000000
    #define CY_GRABBER_ANALOG_VS_INPUT_LABEL                "Input Selection"


    // Progressive mode (BW only)
    //
    // The progressive mode depends on the model and firmware, if it is not
    // supported the following three parameters will not be available
    /////////////////////////////////////////////////////////////////////////////  

    #define CY_GRABBER_ANALOG_VS_PROGRESSIVE                    0x00000001
    #define CY_GRABBER_ANALOG_VS_PROGRESSIVE_LABEL              "Black and White Progressive Mode"
                                                                
    #define CY_GRABBER_ANALOG_VS_PROG_OUTPUT_LEVEL              0x00000002
    #define CY_GRABBER_ANALOG_VS_PROG_OUTPUT_LEVEL_LABEL        "Progressive Mode Output Level"
                                                                
    #define CY_GRABBER_ANALOG_VS_PROG_BLACK_LEVEL               0x00000003
    #define CY_GRABBER_ANALOG_VS_PROG_BLACK_LEVEL_LABEL         "Progressive IRE Black Level"


    // Field Selection
    /////////////////////////////////////////////////////////////////////////////  

    #define CY_GRABBER_ANALOG_VS_AUTO_FIELD_SELECTION           0x00000004
    #define CY_GRABBER_ANALOG_VS_AUTO_FIELD_SELECTION_LABEL     "Automatic Field Selection"
                                                                
    #define CY_GRABBER_ANALOG_VS_FIELD_SELECTION                0x00000005
    #define CY_GRABBER_ANALOG_VS_FIELD_SELECTION_LABEL          "Field Selection"


    // Miscellaneous
    ////////////////////////////////////////////////////////////////////////////////

    #define CY_GRABBER_ANALOG_VS_HOR_TIME_CONSTANT              0x00000006
    #define CY_GRABBER_ANALOG_VS_HOR_TIME_CONSTANT_LABEL        "Horizontal Time Constant"

    #define CY_GRABBER_ANALOG_VS_VERTICAL_NOISE_REDUCTION       0x00000007
    #define CY_GRABBER_ANALOG_VS_VERTICAL_NOISE_REDUCTION_LABEL "Vertical Noise Reduction"

    #define CY_GRABBER_ANALOG_VS_FAST_COLOR_TIME_CONSTANT       0x00000008
    #define CY_GRABBER_ANALOG_VS_FAST_COLOR_TIME_CONSTANT_LABEL "Fast Color Time Constant"

    #define CY_GRABBER_ANALOG_VS_CHROMA_DETECTION_STANDARD       0x00000009
    #define CY_GRABBER_ANALOG_VS_CHROMA_DETECTION_STANDARD_LABEL "Chroma Detection Standard"

    // For 7115 only
    #define CY_GRABBER_ANALOG_VS_AUTO_CHROMA_DETECTION          0x0000000A
    #define CY_GRABBER_ANALOG_VS_AUTO_CHROMA_DETECTION_LABEL    "Automatic Chroma Detection"

    // Input switching
    #define CY_GRABBER_ANALOG_VS_AUTO_INPUT_SWITCHING_MASK       0x0000000B
    #define CY_GRABBER_ANALOG_VS_AUTO_INPUT_SWITCHING_MASK_LABEL "Auto Input Switching Mask"

    // Square Pixel mode
    ////////////////////////////////////////////////////////////////////////////////

    #define CY_GRABBER_ANALOG_VS_PIXEL_SAMPLING                 0x0000000C
    #define CY_GRABBER_ANALOG_VS_PIXEL_SAMPLING_LABEL           "Pixel sampling rate"


// Video Decoder Image Settings
// ID: 0x00000020 - 0x0000002F (one per channel)
/////////////////////////////////////////////////////////////////////////////  

#define CY_GRABBER_EXT_ANALOG_IMAGE_SETTINGS        0x00000020

    #define CY_GRABBER_EXT_ANALOG_IS_BRIGHTNESS                 0x00000000
    #define CY_GRABBER_EXT_ANALOG_IS_BRIGHTNESS_LABEL           "Brightness"

    #define CY_GRABBER_EXT_ANALOG_IS_CONTRAST                   0x00000001
    #define CY_GRABBER_EXT_ANALOG_IS_CONTRAST_LABEL             "Contrast"

    #define CY_GRABBER_EXT_ANALOG_IS_SATURATION                 0x00000002
    #define CY_GRABBER_EXT_ANALOG_IS_SATURATION_LABEL           "Saturation"

    #define CY_GRABBER_EXT_ANALOG_IS_HUE                        0x00000003
    #define CY_GRABBER_EXT_ANALOG_IS_HUE_LABEL                  "Hue"



// Video Decoder Analog Gains
// ID: 0x00000030 - 0x0000003F (one per channel)
/////////////////////////////////////////////////////////////////////////////  

#define CY_GRABBER_EXT_ANALOG_GAIN                  0x00000030

    #define CY_GRABBER_EXT_ANALOG_GAIN_AUTO_GAIN_CONTROL        0x00000000
    #define CY_GRABBER_EXT_ANALOG_GAIN_AUTO_GAIN_CONTROL_LABEL  "Automatic Gain Control"

    #define CY_GRABBER_EXT_ANALOG_GAIN_PROGRAMMABLE_GAIN        0x00000001
    #define CY_GRABBER_EXT_ANALOG_GAIN_PROGRAMMABLE_GAIN_LABEL  "Programmable Gain"

    #define CY_GRABBER_EXT_ANALOG_GAIN_GAIN_CONTROL_1           0x00000002
    #define CY_GRABBER_EXT_ANALOG_GAIN_GAIN_CONTROL_1_LABEL     "Gain Control 1"

    #define CY_GRABBER_EXT_ANALOG_GAIN_GAIN_CONTROL_2           0x00000003
    #define CY_GRABBER_EXT_ANALOG_GAIN_GAIN_CONTROL_2_LABEL     "Gain Control 2"

    #define CY_GRABBER_EXT_ANALOG_GAIN_AUTO_CHROMA_GAIN_CONTROL         0x00000004
    #define CY_GRABBER_EXT_ANALOG_GAIN_AUTO_CHROMA_GAIN_CONTROL_LABEL   "Automatic Chroma Gain Control"

    #define CY_GRABBER_EXT_ANALOG_GAIN_CHROMA_GAIN              0x00000005
    #define CY_GRABBER_EXT_ANALOG_GAIN_CHROMA_GAIN_LABEL        "Chroma Gain Control"



// Video Decoder Analog Filtering (7115)
// ID: 0x00000040 - 0x0000004F (one per channel)
/////////////////////////////////////////////////////////////////////////////  

#define CY_GRABBER_EXT_ANALOG_FILTERING_7115        0x00000040

    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_LUMINANCE_FILTER          0x00000000
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_LUMINANCE_FILTER_LABEL    "Lumicance Filter"
                                                                        
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_CHROMA_COMB_BYPASS        0x00000001    
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_CHROMA_COMB_BYPASS_LABEL  "Bypass Chrominance Trap/Comb Filter"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_LUMA_COMB_FILTER          0x00000002
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_LUMA_COMB_FILTER_LABEL    "Adaptive Luminance Comb Filter"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_CHROMA_COMB_FILTER        0x00000003
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_CHROMA_COMB_FILTER_LABEL  "Adaptive Chrominance Comb Filter"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_LARGE_BANDWIDTH           0x00000004
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_LARGE_BANDWIDTH_LABEL     "Enable Large Luma/Chroma Bandwidth"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_BANDWIDTH_ADJUST          0x00000005
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_BANDWIDTH_ADJUST_LABEL    "Chroma/Luma Bandwidth Adjustement"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_SECAM_COLOR_KILLER        0x00000006
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_SECAM_COLOR_KILLER_LABEL  "SECAM Color Killer"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_PAL_NTSC_COLOR_KILLER         0x00000007
    #define CY_GRABBER_EXT_ANALOG_FILTER_7115_PAL_NTSC_COLOR_KILLER_LABEL   "PAL/NTSC Color Killer"



// Video Decoder Analog Filtering (7113)
// ID: 0x00000050 - 0x0000005F (one per channel)
/////////////////////////////////////////////////////////////////////////////  

#define CY_GRABBER_EXT_ANALOG_FILTERING_7113        0x00000050

    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_APERTURE_FACTOR           0x00000000
    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_APERTURE_FACTOR_LABEL     "Aperture Factor"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_APERTURE_BAND_PASS        0x00000001
    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_APERTURE_BAND_PASS_LABEL  "Aperture Band Pass"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_PREFILTER_ACTIVE          0x00000002
    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_PREFILTER_ACTIVE_LABEL    "Prefilter Active"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_CHROMA_TRAP_BYPASS        0x00000003
    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_CHROMA_TRAP_BYPASS_LABEL  "Chroma Trap Bypass"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_CHROMA_BANDWIDTH          0x00000004
    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_CHROMA_BANDWIDTH_LABEL    "Chrominance Bandwidth"

    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_AUTO_COLOR_KILLER         0x00000005
    #define CY_GRABBER_EXT_ANALOG_FILTER_7113_AUTO_COLOR_KILLER_LABEL   "Automatic Color Killer"


// Video Decoder Analog Windowing (SAA 7115 only )
// ID: 0x00000060 - 0x0000006F (one per channel)
/////////////////////////////////////////////////////////////////////////////  

#define CY_GRABBER_EXT_ANALOG_WINDOWING             0x00000060

    #define CY_GRABBER_EXT_ANALOG_WINDOWING_ENABLED             0x00000000
    #define CY_GRABBER_EXT_ANALOG_WINDOWING_ENABLED_LABEL       "Analog Windowing Enabled"

    #define CY_GRABBER_EXT_ANALOG_WINDOWING_VSTART              0x00000001
    #define CY_GRABBER_EXT_ANALOG_WINDOWING_VSTART_LABEL        "Vertical Start"

    #define CY_GRABBER_EXT_ANALOG_WINDOWING_VEND                0x00000002
    #define CY_GRABBER_EXT_ANALOG_WINDOWING_VEND_LABEL          "Vertical End"
    


// Video Decoder Status
// ID: 0x00000070 - 0x0000007F (one per channel)
/////////////////////////////////////////////////////////////////////////////  

#define CY_GRABBER_EXT_ANALOG_STATUS           0x00000070

    // All the parameters of this extension are read-only

    #define CY_GRABBER_EXT_ANALOG_STATUS_COLOR_STANDARD                 0x00000000
    #define CY_GRABBER_EXT_ANALOG_STATUS_COLOR_STANDARD_LABEL           "Color Standard"

    #define CY_GRABBER_EXT_ANALOG_STATUS_FREQUENCY                      0x00000001
    #define CY_GRABBER_EXT_ANALOG_STATUS_FREQUENCY_LABEL                "Detected Input Frequency"

    #define CY_GRABBER_EXT_ANALOG_STATUS_STANDARD_FIELD_LENGTH          0x00000002
    #define CY_GRABBER_EXT_ANALOG_STATUS_STANDARD_FIELD_LENGTH_LABEL    "Standard Field Length"

    #define CY_GRABBER_EXT_ANALOG_STATUS_READY_FOR_CAPTURE              0x00000003
    #define CY_GRABBER_EXT_ANALOG_STATUS_READY_FOR_CAPTURE_LABEL        "Ready for Capture"

    #define CY_GRABBER_EXT_ANALOG_STATUS_STABLE_TIMEBASE                0x00000004
    #define CY_GRABBER_EXT_ANALOG_STATUS_STABLE_TIMEBASE_LABEL          "Stable Time Base"

    #define CY_GRABBER_EXT_ANALOG_STATUS_HORIZ_FREQ_LOCKED              0x00000005
    #define CY_GRABBER_EXT_ANALOG_STATUS_HORIZ_FREQ_LOCKED_LABEL        "Horizontal Frequency Locked"

    #define CY_GRABBER_EXT_ANALOG_STATUS_HV_UNLOCKED                    0x00000006
    #define CY_GRABBER_EXT_ANALOG_STATUS_HV_UNLOCKED_LABEL              "Horizontal and Vertical Loops unlocked"
    
    #define CY_GRABBER_EXT_ANALOG_STATUS_INTERLACED                     0x00000007
    #define CY_GRABBER_EXT_ANALOG_STATUS_INTERLACED_LABEL               "Interlaced"

    #define CY_GRABBER_EXT_ANALOG_STATUS_RECHECK_INTERVAL               0x00000008
    #define CY_GRABBER_EXT_ANALOG_STATUS_RECHECK_INTERVAL_LABEL         "Status Recheck Interval"

#endif // _CY_GRABBER_EXTENSION_CONSTANTS_H_
