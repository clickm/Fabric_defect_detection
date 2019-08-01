// *****************************************************************************
//
// $Id: CyCameraLinkExtensionBackwardCompatibility.h,v 1.3 2009/05/29 14:51:55 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraLinkExtensionBackwardCompatibility.h
//
// Description..: Defines the base of a camera class.
//
// *****************************************************************************

// Types
public:
    enum
    {
        SS_UNUSED,
        SS_UART0
    };
    typedef unsigned long SerialSelectFunction;

// Accessors
public:
    CyResult SetSerialSelectFunction ( CY_UINT32 aFunction )
    {
        return SetParameter( CY_CAMERA_LINK_SERIAL_SELECT, aFunction );
    }

    CyResult GetSerialSelectFunction ( CY_UINT32& aFunction ) const
    {
        return GetParameter( CY_CAMERA_LINK_SERIAL_SELECT, aFunction );
    }


    CyResult SetDataValidEnabled ( bool  aEnable )
    {
        return SetParameter( CY_CAMERA_LINK_DVAL_ENABLED, aEnable );
    }
    CyResult GetDataValidEnabled ( bool& aEnable ) const
    {
        return GetParameter( CY_CAMERA_LINK_DVAL_ENABLED, aEnable );
    }


    CyResult SetDataValidPolarity( bool  aLow )
    {
        return SetParameter( CY_CAMERA_LINK_DVAL_LOW_POLARITY, aLow );
    }
    CyResult GetDataValidPolarity( bool& aLow ) const
    {
        return GetParameter( CY_CAMERA_LINK_DVAL_LOW_POLARITY, aLow );
    }


    CyResult SetLineValidPolarity( bool  aLow )
    {
        return SetParameter( CY_CAMERA_LINK_LVAL_LOW_POLARITY, aLow );
    }

    CyResult GetLineValidPolarity( bool& aLow ) const
    {
        return GetParameter( CY_CAMERA_LINK_LVAL_LOW_POLARITY, aLow );
    }


    CyResult SetFrameValidPolarity( bool  aLow )
    {
        return SetParameter( CY_CAMERA_LINK_FVAL_LOW_POLARITY, aLow );
    }

    CyResult GetFrameValidPolarity( bool& aLow ) const
    {
        return GetParameter( CY_CAMERA_LINK_FVAL_LOW_POLARITY, aLow );
    }


    CyResult SetLineValidEdgeSensitive( bool  aEnabled )
    {
        return SetParameter( CY_CAMERA_LINK_LVAL_EDGE_SENSITIVE, aEnabled );
    }

    CyResult GetLineValidEdgeSensitive( bool& aEnabled ) const
    {
        return GetParameter( CY_CAMERA_LINK_LVAL_EDGE_SENSITIVE, aEnabled );
    }


    CyResult SetFrameValidEdgeSensitive( bool  aEnabled )
    {
        return SetParameter( CY_CAMERA_LINK_FVAL_EDGE_SENSITIVE, aEnabled );
    }

    CyResult GetFrameValidEdgeSensitive( bool& aEnabled ) const
    {
        return GetParameter( CY_CAMERA_LINK_FVAL_EDGE_SENSITIVE, aEnabled );
    }


    CyResult SetFrameValidFunctionSelect( CY_UINT8  aFunction )
    {
        return SetParameter( CY_CAMERA_LINK_FVAL_FUNCTION_SELECT, aFunction );
    }

    CyResult GetFrameValidFunctionSelect( CY_UINT8& aFunction ) const
    {
        return GetParameter( CY_CAMERA_LINK_FVAL_FUNCTION_SELECT, aFunction );
    }


    CyResult SetLineValidFunctionSelect( CY_UINT8  aFunction )
    {
        return SetParameter( CY_CAMERA_LINK_LVAL_FUNCTION_SELECT, aFunction );
    }

    CyResult GetLineValidFunctionSelect( CY_UINT8& aFunction ) const
    {
        return GetParameter( CY_CAMERA_LINK_LVAL_FUNCTION_SELECT, aFunction );
    }


    CyResult SetGPIOOutputEnabled( bool  aEnabled )
    {
        return SetParameter( CY_CAMERA_LVDS_GPIO_OUTPUT_ENABLED, aEnabled );
    }

    CyResult GetGPIOOutputEnabled( bool& aEnabled ) const
    {
        return GetParameter( CY_CAMERA_LVDS_GPIO_OUTPUT_ENABLED, aEnabled );
    }

    CyResult GetClockPresence( bool & aPresent, CyGrabber* aGrabber = 0 ) const
    {
        return GetParameter( CY_CAMERA_LINK_CAMERA_CLOCK_PRESENT, aPresent );
    }

