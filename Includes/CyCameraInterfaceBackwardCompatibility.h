// *****************************************************************************
//
// $Id: CyCameraInterfaceBackwardCompatibility.h,v 1.15 2009/05/29 14:51:54 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCameraInterfaceBackwardCompatibility.h
//
// Description..: The present file contains symbol that are defined for 
//                backward-compatibility with a previous version of the SDK
//
// *****************************************************************************

#ifndef _CY_CAMERA_BACKWARD_COMPATIBILITY_H_
#define _CY_CAMERA_BACKWARD_COMPATIBILITY_H_

public:
// Types
    enum
    {
        LINE_SCAN   = CY_CAMERA_LINE_SCAN,
        AREA_SCAN   = CY_CAMERA_AREA_SCAN
    };
    typedef unsigned long ImageType;

    enum
    {
        FREE_RUN_PROGRAMMABLE    = CY_CAMERA_FREE_RUN_PROGRAMMABLE,
        FREE_RUN_EDGE_CONTROLLED = CY_CAMERA_FREE_RUN_EDGE_CONTROLLED,
        EX_SYNC_LEVEL_CONTROLLED = CY_CAMERA_EX_SYNC_LEVEL_CONTROLLED,
        EX_SYNC_PROGRAMMABLE     = CY_CAMERA_EX_SYNC_PROGRAMMABLE,
        EX_SYNC_EDGE_CONTROLLED  = CY_CAMERA_EX_SYNC_EDGE_CONTROLLED 
    };
    typedef unsigned long SynchronizationMode;

    enum
    {
        STRING_PARAMETER  = CY_PARAMETER_STRING,
        BYTE_PARAMETER    = CY_PARAMETER_BYTE,
        CHAR_PARAMETER    = CY_PARAMETER_CHAR,
        SHORT_PARAMETER   = CY_PARAMETER_SHORT,
        USHORT_PARAMETER  = CY_PARAMETER_USHORT,
        INT_PARAMETER     = CY_PARAMETER_INT,
        UINT_PARAMETER    = CY_PARAMETER_UINT,
        LONG_PARAMETER    = CY_PARAMETER_LONG,
        ULONG_PARAMETER   = CY_PARAMETER_ULONG,
        FLOAT_PARAMETER   = CY_PARAMETER_FLOAT,
        DOUBLE_PARAMETER  = CY_PARAMETER_DOUBLE,
        BOOL_PARAMETER    = CY_PARAMETER_BOOL,
        ENUM_PARAMETER    = CY_PARAMETER_ENUM,
        INVALID_PARAMETER = CY_PARAMETER_INVALID
    };
    typedef unsigned long ParameterType;

    // These parameters are not part of the camera interface any more, but can
    // be obtain throurh the parameter repository instead.
    //
    // Instead we define inline functions for the old functions that automatically search
    // in the repository.
    /////////////////////////////////////////////////////////////////////////////

#define CAMERA_BACKWARD_COMPATIBILITY_SET( aName, aID, aType ) \
    CyResult Set##aName( aType  aValue )       { return SetParameter( aID, aValue ); }

#define CAMERA_BACKWARD_COMPATIBILITY_GET( aName, aID, aType ) \
    CyResult Get##aName( aType& aValue ) const { return GetParameter( aID, aValue ); }

#define CAMERA_BACKWARD_COMPATIBILITY( aName, aID, aType ) \
    CAMERA_BACKWARD_COMPATIBILITY_SET( aName, aID, aType ) \
    CAMERA_BACKWARD_COMPATIBILITY_GET( aName, aID, aType )

#define CAMERA_BACKWARD_COMPATIBILITY_SET_GAIN( aName, aID, aType ) \
    CyResult Set##aName( unsigned short aIndex, aType aValue )       { return SetParameter( aID + aIndex, aValue ); }

#define CAMERA_BACKWARD_COMPATIBILITY_GET_GAIN( aName, aID, aType ) \
    CyResult Get##aName( unsigned short aIndex, aType& aValue ) const { return GetParameter( aID + aIndex, aValue ); }

#define CAMERA_BACKWARD_COMPATIBILITY_GAIN( aName, aID, aType ) \
    CAMERA_BACKWARD_COMPATIBILITY_SET_GAIN( aName, aID, aType ) \
    CAMERA_BACKWARD_COMPATIBILITY_GET_GAIN( aName, aID, aType )


public:
    CAMERA_BACKWARD_COMPATIBILITY( SizeX, CY_CAMERA_PARAM_SIZE_X, CY_UINT32 );
    CAMERA_BACKWARD_COMPATIBILITY( SizeY, CY_CAMERA_PARAM_SIZE_Y, CY_UINT32 );
    CAMERA_BACKWARD_COMPATIBILITY( OffsetX, CY_CAMERA_PARAM_OFFSET_X, CY_UINT32 );
    CAMERA_BACKWARD_COMPATIBILITY( OffsetY, CY_CAMERA_PARAM_OFFSET_Y, CY_UINT32 );
    CAMERA_BACKWARD_COMPATIBILITY( DecimationX, CY_CAMERA_PARAM_DECIMATION_X, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( DecimationY, CY_CAMERA_PARAM_DECIMATION_Y, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( DecimationBlockX, CY_CAMERA_PARAM_DECIMATION_BLOCK_X, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( DecimationBlockY, CY_CAMERA_PARAM_DECIMATION_BLOCK_Y, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( BinningX, CY_CAMERA_PARAM_BINNING_X, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( BinningY, CY_CAMERA_PARAM_BINNING_Y, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( PixelType,   CY_CAMERA_PARAM_PIXEL_TYPE, CY_INT64 );
    CAMERA_BACKWARD_COMPATIBILITY( TapQuantity, CY_CAMERA_PARAM_TAP_QUANTITY, CY_UINT8 );
    CAMERA_BACKWARD_COMPATIBILITY( ImageType, CY_CAMERA_PARAM_IMAGE_TYPE, CY_UINT32 );
    CAMERA_BACKWARD_COMPATIBILITY( SynchronizationMode, CY_CAMERA_PARAM_SYNCHRO_MODE, CY_UINT32 );
    CAMERA_BACKWARD_COMPATIBILITY( ExposureTime, CY_CAMERA_PARAM_EXPOSURE_TIME, CY_UINT32 );
    CAMERA_BACKWARD_COMPATIBILITY( FrameRate,    CY_CAMERA_PARAM_FRAME_RATE,    double );
    CAMERA_BACKWARD_COMPATIBILITY( DigitalShift, CY_CAMERA_PARAM_DIGITAL_SHIFT, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( TestPattern,  CY_CAMERA_PARAM_TEST_PATTERN,  CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( ImageFlip,    CY_CAMERA_PARAM_IMAGE_FLIP,    bool );
    CAMERA_BACKWARD_COMPATIBILITY( BlackLevel,   CY_CAMERA_PARAM_BLACK_LEVEL,   CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY( InterlacedInversion, CY_CAMERA_PARAM_INTERLACED_INVERSION, bool );
    CAMERA_BACKWARD_COMPATIBILITY( AutoParameterImplementation, CY_CAMERA_PARAM_AUTO_PARAM_IMPL, bool );

    CAMERA_BACKWARD_COMPATIBILITY_GET( SizeX, CY_CAMERA_PARAM_SIZE_X, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY_GET( SizeY, CY_CAMERA_PARAM_SIZE_Y, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY_GET( OffsetX, CY_CAMERA_PARAM_OFFSET_X, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY_GET( OffsetY, CY_CAMERA_PARAM_OFFSET_Y, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY_GET( Vendor, CY_CAMERA_PARAM_VENDOR, CyString );
    CAMERA_BACKWARD_COMPATIBILITY_GET( CameraModel, CY_CAMERA_PARAM_MODEL, CyString );
    CAMERA_BACKWARD_COMPATIBILITY_GET( ProductID, CY_CAMERA_PARAM_PRODUCT_ID, CyString );
    CAMERA_BACKWARD_COMPATIBILITY_GET( SerialNumber, CY_CAMERA_PARAM_SERIAL_NUMBER, CyString );

    bool IsStarted( const CyChannel& aChannel )
        { return IsGrabbing( aChannel ); }
    bool IsStopped( const CyChannel& aChannel )
        { return !IsGrabbing( aChannel ); }

    // Gains & offsets
    CAMERA_BACKWARD_COMPATIBILITY_GAIN    ( Gain, CY_CAMERA_PARAM_GAIN, CY_INT32 );
    CAMERA_BACKWARD_COMPATIBILITY_GET_GAIN( Gain, CY_CAMERA_PARAM_GAIN, CY_INT16 );
    CAMERA_BACKWARD_COMPATIBILITY_GET_GAIN( Gain, CY_CAMERA_PARAM_GAIN, CY_UINT16 );
    CAMERA_BACKWARD_COMPATIBILITY_GAIN    ( Offset, CY_CAMERA_PARAM_OFFSET, CY_INT32 );
    CAMERA_BACKWARD_COMPATIBILITY_GET_GAIN( Offset, CY_CAMERA_PARAM_OFFSET, CY_INT16 );
    CAMERA_BACKWARD_COMPATIBILITY_GET_GAIN( Offset, CY_CAMERA_PARAM_OFFSET, CY_UINT16 );


    // Set the name, min and max of a gain or offset
    CyResult SetGainInformation( unsigned short     aIndex,
                                 const CyString&    aName,
                                 CY_INT64           aMinValue,
                                 CY_INT64           aMaxValue )
    {
        CyResult lResult = SetParameterRange( CY_CAMERA_PARAM_GAIN + aIndex, aMinValue, aMaxValue );
        if ( lResult != CY_RESULT_OK )
            return lResult;
        return SetParameterDescription( CY_CAMERA_PARAM_GAIN + aIndex, aName );
    }
    CyResult GetGainInformation  ( unsigned short     aIndex,
                                   CyString&          aName,
                                   long&              aMinValue,
                                   long&              aMaxValue ) const
    {
        aName = GetParameterDescription( CY_CAMERA_PARAM_GAIN + aIndex );

        CY_INT64 lMin, lMax;
        CyResult lResult = GetParameterRange( CY_CAMERA_PARAM_GAIN + aIndex, lMin, lMax );
        aMinValue = static_cast<long>( lMin );
        aMaxValue = static_cast<long>( lMax );
        return lResult;        
    }
    CyResult SetOffsetInformation( unsigned short     aIndex,
                                   const CyString&    aName,
                                   CY_INT64           aMinValue,
                                   CY_INT64           aMaxValue )
    {
        CyResult lResult = SetParameterRange( CY_CAMERA_PARAM_OFFSET + aIndex, aMinValue, aMaxValue );
        if ( lResult != CY_RESULT_OK )
            return lResult;
        return SetParameterDescription( CY_CAMERA_PARAM_OFFSET + aIndex, aName );
    }
 /*   CyResult GetOffsetInformation( unsigned short     aIndex,
                                   CyString&          aName,
                                   long&              aMinValue,
                                   long&              aMaxValue ) const
    {
        aName = GetParameterDescription( CY_CAMERA_PARAM_OFFSET + aIndex );

        CY_INT64 lMin, lMax;
        CyResult lResult = GetParameterRange( CY_CAMERA_PARAM_OFFSET + aIndex, lMin, lMax );
        aMinValue = static_cast<long>( lMin );
        aMaxValue = static_cast<long>( lMax );
        return lResult;
    }*/

    // Returns the module ID and sub-module ID of the device
    unsigned char GetModuleID() const
    {
        return GetGrabber().GetDevice().GetModuleID();
    }
    unsigned char GetSubModuleID() const
    {
        return GetGrabber().GetDevice().GetSubModuleID();
    }

    // Bayer pattern information.
    // The camera can return the bayer pattern to use when converting bayer format.
    // It uses the starting pattern and the X,Y offset to determine which pattern to use.
    // Application can override the starting bayer formet if required 
    CyResult SetStartingBayerFlag( CY_UINT32 aFlag, bool aAdjustWithOffsets )
    {
        CyAssert( ( aFlag & CyPixelConverter::FLAG_BAYER_GRBG ) ||
                  ( aFlag & CyPixelConverter::FLAG_BAYER_GBRG ) ||
                  ( aFlag & CyPixelConverter::FLAG_BAYER_RGGB ) ||
                  ( aFlag & CyPixelConverter::FLAG_BAYER_BGGR ) );

        if ( SetParameter( CY_CAMERA_PARAM_STARTING_BAYER_FLAG, aFlag ) != CY_RESULT_OK )
            return GetErrorInfo();
        if ( SetParameter( CY_CAMERA_PARAM_STARTING_BAYER_ADJUST_WITH_OFFSET, aAdjustWithOffsets ) != CY_RESULT_OK )
            return GetErrorInfo();

        return CY_RESULT_OK;
    }

    unsigned long GetStartingBayerFlag() const
    {
        return GetParameterUInt( CY_CAMERA_PARAM_STARTING_BAYER_FLAG );
    }
    bool GetBayerFlagOffsetAdjustable() const
    {
        return GetParameterBool( CY_CAMERA_PARAM_STARTING_BAYER_ADJUST_WITH_OFFSET );
    }

    // Enabling the serial free form panel in the configuration dialog
    void SetSerialFreeForm( bool aEnabled ) { (void)aEnabled; }
    bool GetSerialFreeForm() const { return true; }

    CyResult GetParameterInfo ( unsigned short aIndex,
                                CyString&      aName,
                                ParameterType& aType ) const
    {
        aName = GetParameterNameByIndex( aIndex );
        aType = GetParameterTypeByIndex( aIndex );
        if ( ( aName.empty() ) ||
             ( aType == CY_PARAMETER_INVALID ) )
             return CY_RESULT_NOT_FOUND;

        return CY_RESULT_OK;
    }
    CyResult GetParameterInfo ( const CyString& aName,
                                ParameterType&  aType ) const
    {
        aType = GetParameterType( aName );
        if ( aType == CY_PARAMETER_INVALID )
             return CY_RESULT_NOT_FOUND;

        return CY_RESULT_OK;
    }


#undef CAMERA_BACKWARD_COMPATIBILITY_SET
#undef CAMERA_BACKWARD_COMPATIBILITY_GET
#undef CAMERA_BACKWARD_COMPATIBILITY
#undef CAMERA_BACKWARD_COMPATIBILITY_SET_GAIN
#undef CAMERA_BACKWARD_COMPATIBILITY_GET_GAIN
#undef CAMERA_BACKWARD_COMPATIBILITY_GAIN

#endif // _CY_CAMERA__BACKWARD_COMPATIBILITY_H_
