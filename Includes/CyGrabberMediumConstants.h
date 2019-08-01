// *****************************************************************************
//
//     Copyright (c) 2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyGrabberMediumConstants.h
//
// *****************************************************************************

#ifndef __CY_GRABBER_MEDIUM_CONSTANT_H__
#define __CY_GRABBER_MEDIUM_CONSTANT_H__

enum CyMediumMode
{
    MEDIUM_MODE_HALF_FRAME = 0,
    MEDIUM_MODE_HALF_LINE  = 1,
    MEDIUM_MODE_INTERLACED = 2,
};

// Constants
/////////////////////////////////////////////////////////////////////////////

enum CyMediumGrabberFlags
{
    CY_GRABBER_MEDIUM_CONNECT_AS_TWO_BASE = 0x01000000,
};


// Parameters
/////////////////////////////////////////////////////////////////////////////

#define CY_MEDIUM_GRABBER_PARAM_MODE                    0x00000200
#define CY_MEDIUM_GRABBER_PARAM_MODE_LABEL              "Medium Mode"

#define CY_MEDIUM_GRABBER_PARAM_SYNC_GROUP              0x00000201
#define CY_MEDIUM_GRABBER_PARAM_SYNC_GROUP_LABEL        "Synchronization Group"

#define CY_MEDIUM_GRABBER_PARAM_PORT_MAPPING           0x00000202
#define CY_MEDIUM_GRABBER_PARAM_PORT_MAPPING_LABEL     "First Grabber Port Mapping"

#define CY_MEDIUM_GRABBER_PARAM_PORT_MAPPING_2            0x00000203
#define CY_MEDIUM_GRABBER_PARAM_PORT_MAPPING_2_LABEL      "Second Grabber Port Mapping"

#endif // __CY_GRABBER_MEDIUM_CONSTANT_H__

