// *****************************************************************************
//
// $Id: CyDeviceBackwardCompatibility.h,v 1.38 2009/05/29 14:46:14 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//unsigned char
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyDeviceBackwardCompatibility.h
//
// Description..: The present file contains symbol that are defined for 
//                backward-compatibility with a previous version of the SDK
//
// *****************************************************************************

#ifndef _CY_DEVICE_BACKWARD_COMPATIBILITY_H_
#define _CY_DEVICE_BACKWARD_COMPATIBILITY_H_

// Type:
public:
    enum
    {
        CB_ON_DEVICE_RESET   = CY_DEVICE_CB_ON_DEVICE_RESET,
        CB_ON_INTERRUPT_GPIO = CY_DEVICE_CB_ON_INTERRUPT_GPIO,

		CB_LAST = 1,
		CB_QTY  = 2
    };
	enum
	{
		PORT_INTERNAL = CY_DEVICE_PORT_INTERNAL, 
		PORT_SERIAL_0 = CY_DEVICE_PORT_SERIAL_0,
		PORT_SERIAL_1 = CY_DEVICE_PORT_SERIAL_1,
        PORT_I2C      = CY_DEVICE_PORT_I2C,
        PORT_USRT_0   = CY_DEVICE_PORT_USRT_0, // deprecated, replace with BULK_0
        PORT_BULK_0   = CY_DEVICE_PORT_BULK_0,
        PORT_BUS_0    = CY_DEVICE_PORT_BUS_0,
        PORT_BULK_1   = CY_DEVICE_PORT_BULK_1,
        PORT_BULK_2   = CY_DEVICE_PORT_BULK_2,
        PORT_BULK_3   = CY_DEVICE_PORT_BULK_3,

		PORT_LAST = 8,
		PORT_QTY  = 9
	};

    typedef unsigned long CallbackTypes;

// Constants
public:
	CY_COM_LIB_API static const unsigned long FLAG_COMMAND_ONLY;
    CY_COM_LIB_API static const unsigned long FLAG_SET_IP_ON_CONNECT;
    CY_COM_LIB_API static const unsigned long FLAG_BAD_IMAGE_PASSTHROUGH;
    CY_COM_LIB_API static const unsigned long FLAG_DATA_ONLY;
    CY_COM_LIB_API static const unsigned long FLAG_NO_RESEND_PACKETS;
    CY_COM_LIB_API static const unsigned long FLAG_MULTICAST_NO_DATA;
    CY_COM_LIB_API static const unsigned long FLAG_NO_DATA_LINK_CHECK_ON_ERROR;
    CY_COM_LIB_API static const unsigned long FLAG_NO_LOAD_EXTENSION_ON_CONNECT;


#define DEVICE_BACKWARD_COMPATIBILITY_SET( aName, aID, aType ) \
    CyResult Set##aName( aType  aValue ) \
    { \
        return SetParameter( aID, aValue ); \
    }

#define DEVICE_BACKWARD_COMPATIBILITY_GET( aName, aID, aType ) \
    aType Get##aName() const \
    { \
        aType lTemp; \
        GetParameter( aID, lTemp ); \
        return lTemp; \
    }

#define DEVICE_BACKWARD_COMPATIBILITY_GET_RESULT( aName, aID, aType ) \
    CyResult Get##aName( aType& aValue ) const \
    { \
        return GetParameter( aID, aValue ); \
    }


#define DEVICE_BACKWARD_COMPATIBILITY( aName, aID, aType ) \
    DEVICE_BACKWARD_COMPATIBILITY_GET( aName, aID, aType ) \
    DEVICE_BACKWARD_COMPATIBILITY_SET( aName, aID, aType )

#define DEVICE_BACKWARD_COMPATIBILITY_RESULT( aName, aID, aType ) \
    DEVICE_BACKWARD_COMPATIBILITY_GET_RESULT( aName, aID, aType ) \
    DEVICE_BACKWARD_COMPATIBILITY_SET( aName, aID, aType )


    bool IsMulticastEnabled() const
    {
        return GetParameterInt( CY_DEVICE_PARAM_DATA_SENDING_MODE ) == CY_CONFIG_DSM_MULTICAST;
    }

    bool IsMulticastSlave() const
    {
        return GetParameterInt( CY_DEVICE_PARAM_DATA_SENDING_MODE_MASTER ) == 0;
    }

    DEVICE_BACKWARD_COMPATIBILITY_GET( MulticastAddress, CY_DEVICE_PARAM_DATA_SENDING_MODE_ADDRESS, CyString );

    DEVICE_BACKWARD_COMPATIBILITY_GET( DeviceID, CY_DEVICE_PARAM_DEVICE_ID, CY_UINT8 );
    DEVICE_BACKWARD_COMPATIBILITY_GET( ModuleID, CY_DEVICE_PARAM_MODULE_ID, CY_UINT8 );
    DEVICE_BACKWARD_COMPATIBILITY_GET( SubModuleID, CY_DEVICE_PARAM_SUB_MODULE_ID, CY_UINT8 );
    DEVICE_BACKWARD_COMPATIBILITY_GET( VendorID, CY_DEVICE_PARAM_VENDOR_ID, CY_UINT8 );
    DEVICE_BACKWARD_COMPATIBILITY_GET( VersionMajor, CY_DEVICE_PARAM_VERSION_MAJ, CY_UINT8 );
    DEVICE_BACKWARD_COMPATIBILITY_GET( VersionMinor, CY_DEVICE_PARAM_VERSION_MIN, CY_UINT8 );

    // ===== Time-out control =====
    DEVICE_BACKWARD_COMPATIBILITY( AnswerTimeOut, CY_DEVICE_PARAM_ANSWER_TIMEOUT, CY_UINT32 );
    DEVICE_BACKWARD_COMPATIBILITY( FirstPacketTimeOut, CY_DEVICE_PARAM_FIRST_PACKET_TIMEOUT, CY_UINT32 );
    DEVICE_BACKWARD_COMPATIBILITY( PacketTimeOut, CY_DEVICE_PARAM_PACKET_TIMEOUT, CY_UINT32 );
    DEVICE_BACKWARD_COMPATIBILITY( RequestTimeOut, CY_DEVICE_PARAM_REQUEST_TIMEOUT, CY_UINT32 );
    DEVICE_BACKWARD_COMPATIBILITY( CommandRetryCount, CY_DEVICE_PARAM_COMMAND_RETRY_COUNT, CY_UINT32 );

    // ===== Packet Size =====
    DEVICE_BACKWARD_COMPATIBILITY( PacketSize, CY_DEVICE_PARAM_PACKET_SIZE, CY_UINT32 );
    CyResult GetPacketSize( CY_UINT32 *aVal )
    {
        if ( aVal == NULL )
            return SetErrorInfo( "aVal can not be NULL!", CY_RESULT_INVALID_ARGUMENT, __FILE__, __LINE__, 0 );
        *aVal = (CY_INT32) GetPacketSize();
        return CY_RESULT_OK;
    }


    CY_UINT32 GetPulseGeneratorCount()
    {
        return GetExtensionCountByType( CY_DEVICE_EXT_PULSE_GENERATOR );
    };
    CY_UINT32 GetRescalerCount()
    {
        return GetExtensionCountByType( CY_DEVICE_EXT_RESCALER );
    };
    CY_UINT32 GetRescalerSize()
    {
        CY_INT64 lResult = 0;
        CY_INT64 lDummy = 0;
        if ( HasExtension( CY_DEVICE_EXT_RESCALER ) )
            GetExtension( CY_DEVICE_EXT_RESCALER ).GetParameterRange( CY_RESCALER_PARAM_DIVIDER, lDummy, lResult );
        return static_cast<unsigned long>( lResult );
    };
    CY_UINT32 GetCounterCount()
    {
        return GetExtensionCountByType( CY_DEVICE_EXT_COUNTER );
    };
    CY_UINT32 GetDelayerCount()
    {
        return GetExtensionCountByType( CY_DEVICE_EXT_DELAYER );
    };


    bool SupportsDebouncing() const
    {
        return HasExtension( CY_DEVICE_EXT_DEBOUNCING );
    }
    bool SupportsGPIOFunctionSelect() const
    {
        return HasExtension( CY_DEVICE_EXT_GPIO_FUNCTION_SELECT );
    }
    bool SupportsTimestampCounter() const
    {
        return HasExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER );
    }
    bool SupportsTimestampTriggers() const
    {
        return HasExtension( CY_DEVICE_EXT_TIMESTAMP_TRIGGERS );
    }


    DEVICE_BACKWARD_COMPATIBILITY_GET( AdapterID, CY_DEVICE_PARAM_ADAPTER_ID, CyString );
    DEVICE_BACKWARD_COMPATIBILITY_GET( AddressIP, CY_DEVICE_PARAM_IP, CyString );
    DEVICE_BACKWARD_COMPATIBILITY_GET( AddressMAC, CY_DEVICE_PARAM_MAC, CyString );
    DEVICE_BACKWARD_COMPATIBILITY_GET( DeviceMode, CY_DEVICE_PARAM_DEVICE_MODE, CY_UINT32 );


    DEVICE_BACKWARD_COMPATIBILITY_GET( ChannelCount, CY_DEVICE_PARAM_CHANNEL_COUNT, CY_UINT16 );

    CyResult SetInterPacketDelay( CY_UINT16 aValue )
    {
        if ( GetParameterInt( CY_DEVICE_PARAM_DEVICE_MODE ) >= CY_DEVICE_ACCESS_MODE_GEV )
        {
            // Set the same IPD for all steam channels
            for ( unsigned short i = 0; i < GetChannelCount(); ++i )
            {
                CyAssert( HasExtension( CY_DEVICE_GEV_EXT_STREAM_CHANNEL + i ) );
                CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_GEV_EXT_STREAM_CHANNEL + i );

                if ( lExtension.SetParameter( CY_DEVICE_GEV_STREAM_PACKET_DELAY, aValue ) != CY_RESULT_OK )
                     return SetErrorInfo( lExtension );
            }
        }
        else
        {
            CyAssert( HasExtension( CY_DEVICE_EXT_FLOW_CONTROL ) );
            CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_FLOW_CONTROL );

            if ( lExtension.SetParameter( CY_DEVICE_FLOW_INTER_PACKET_DELAY, aValue ) != CY_RESULT_OK )
                 return SetErrorInfo( lExtension );
        }

        return CY_RESULT_OK;
    }

    CyResult GetInterPacketDelay( CY_UINT16& aValue ) const
    {
        if ( GetParameterInt( CY_DEVICE_PARAM_DEVICE_MODE ) >= CY_DEVICE_ACCESS_MODE_GEV )
        {
            // Just read the IPD of the first stream channel
            CyAssert( HasExtension( CY_DEVICE_GEV_EXT_STREAM_CHANNEL + 0 ) );
            CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_GEV_EXT_STREAM_CHANNEL + 0 );

            if ( lExtension.GetParameter( CY_DEVICE_GEV_STREAM_PACKET_DELAY, aValue ) != CY_RESULT_OK )
                 return SetErrorInfo( lExtension );
        }
        else
        {
            CyAssert( HasExtension( CY_DEVICE_EXT_FLOW_CONTROL ) );
            CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_FLOW_CONTROL );

            if ( lExtension.GetParameter( CY_DEVICE_FLOW_INTER_PACKET_DELAY, aValue ) != CY_RESULT_OK )
                 return SetErrorInfo( lExtension );
        }

        return CY_RESULT_OK;
    }

    CyResult SetGPIOLookUpTable( const CyString& aValue )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_LUT ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_LUT );
        if ( ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_GPIO_LUT_PROGRAM, aValue ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

    CyResult GetGPIOLookUpTable( CyString& aValue ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_LUT ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_LUT );
        if ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_GPIO_LUT_PROGRAM, aValue ) != CY_RESULT_OK )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

    // ===== Channel information =====
    CyChannel GetChannel( unsigned short aIndex ) const
    {
        CyAssert( aIndex < GetChannelCount() );
        return CyChannel( aIndex );
    }


    DEVICE_BACKWARD_COMPATIBILITY_RESULT( DataGenEnable, CY_DEVICE_PARAM_DATA_GENERATOR, bool );
    CyResult GetDataGenEnable( bool *aVal )
    {
        if ( aVal == NULL )
            return SetErrorInfo( "aVal can not be NULL!", CY_RESULT_INVALID_ARGUMENT, __FILE__, __LINE__, 0 );
        return GetDataGenEnable( *aVal );
    }

    CyResult SetPulseGenerator( unsigned short aIndex,
                                CY_UINT32  aDelay,
                                CY_UINT32  aWidth,
                                CY_UINT32  aGranularity,
                                bool           aPeriodic,
                                bool           aLevelTriggered )
    {
        return SetPulseGenerator( aIndex,
                                  aDelay,
                                  aWidth,
                                  aGranularity,
                                  aPeriodic,
                                  static_cast<unsigned char>( aLevelTriggered ) );
    }
    CyResult GetPulseGenerator( unsigned short  aIndex,
                                CY_UINT16& aDelay,
                                CY_UINT16& aWidth,
                                CY_UINT8&  aGranularity,
                                bool&           aPeriodic,
                                bool&           aLevelTriggered ) const
    {
        CY_UINT8 lTriggerMode;
        CY_UINT32 lDelay, lWidth, lGranularity;
        CyResult lResult = GetPulseGenerator( aIndex,
                                              lDelay,
                                              lWidth,
                                              lGranularity,
                                              aPeriodic,
                                              lTriggerMode );
        if ( lResult == CY_RESULT_OK )
        {
            aLevelTriggered = ( lTriggerMode == 0x01 );
            aDelay = static_cast<CY_UINT16>( lDelay );
            aWidth = static_cast<CY_UINT16>( lWidth );
            aGranularity = static_cast<CY_UINT8>( lGranularity );
        }

        return lResult;
    }


    CyResult SetPulseGenerator( unsigned short aIndex,
                                CY_UINT32 aDelay,
                                CY_UINT32 aWidth,
                                CY_UINT32  aGranularity,
                                bool           aPeriodic,
                                CY_UINT8  aTriggerMode )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_PULSE_GENERATOR + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_PULSE_GENERATOR + aIndex );
        if ( ( lExtension.SetParameter( CY_PULSE_GEN_PARAM_WIDTH, aWidth ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_PULSE_GEN_PARAM_DELAY, aDelay ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_PULSE_GEN_PARAM_GRANULARITY, aGranularity ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_PULSE_GEN_PARAM_PERIODIC, aPeriodic ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_PULSE_GEN_PARAM_TRIGGER_MODE, aTriggerMode ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult GetPulseGenerator( unsigned short  aIndex,
                                CY_UINT16& aDelay,
                                CY_UINT16& aWidth,
                                CY_UINT8&  aGranularity,
                                bool&           aPeriodic,
                                CY_UINT8&  aTriggerMode ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_PULSE_GENERATOR + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_PULSE_GENERATOR + aIndex );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_WIDTH, aWidth ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_DELAY, aDelay ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_GRANULARITY, aGranularity ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_PERIODIC, aPeriodic ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_TRIGGER_MODE, aTriggerMode ) != CY_RESULT_OK )  )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult GetPulseGenerator( unsigned short aIndex,
                                CY_UINT32& aDelay,
                                CY_UINT32& aWidth,
                                CY_UINT32& aGranularity,
                                bool&          aPeriodic,
                                CY_UINT8& aTriggerMode ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_PULSE_GENERATOR + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_PULSE_GENERATOR + aIndex );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_WIDTH, aWidth ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_DELAY, aDelay ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_GRANULARITY, aGranularity ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_PERIODIC, aPeriodic ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_PULSE_GEN_PARAM_TRIGGER_MODE, aTriggerMode ) != CY_RESULT_OK )  )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }


    CyResult SetGPIOConfiguration( CY_UINT8  aLI0,
                                   CY_UINT8  aLI1,
                                   CY_UINT8  aLI2,
                                   CY_UINT8  aLI3,
                                   CY_UINT8  aLI4,
                                   CY_UINT8  aLI5,
                                   CY_UINT8  aLI6,
                                   CY_UINT8  aLI7 )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_LUT ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_LUT );
        if ( ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG0, aLI0 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG1, aLI1 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG2, aLI2 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG3, aLI3 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG4, aLI4 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG5, aLI5 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG6, aLI6 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG7, aLI7 ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult GetGPIOConfiguration( CY_UINT8& aLI0,
                                   CY_UINT8& aLI1,
                                   CY_UINT8& aLI2,
                                   CY_UINT8& aLI3,
                                   CY_UINT8& aLI4,
                                   CY_UINT8& aLI5,
                                   CY_UINT8& aLI6,
                                   CY_UINT8& aLI7 ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_LUT ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_LUT );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG0, aLI0 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG1, aLI1 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG2, aLI2 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG3, aLI3 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG4, aLI4 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG5, aLI5 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG6, aLI6 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_LUT_PARAM_INPUT_CONFIG7, aLI7 ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
                                               
    
    CyResult SetDebouncing( CY_UINT16  aInput0,
                            CY_UINT16  aInput1,
                            CY_UINT16  aInput2 = 0,
                            CY_UINT16  aInput3 = 0 )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_DEBOUNCING ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_DEBOUNCING );
        if ( ( lExtension.SetParameter( CY_DEBOUNCING_PARAM_INPUT0, aInput0 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DEBOUNCING_PARAM_INPUT1, aInput1 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DEBOUNCING_PARAM_INPUT2, aInput2 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DEBOUNCING_PARAM_INPUT3, aInput3 ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult GetDebouncing( CY_UINT16& aInput0,
                            CY_UINT16& aInput1,
                            CY_UINT16& aInput2,
                            CY_UINT16& aInput3 ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_DEBOUNCING ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_DEBOUNCING );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_DEBOUNCING_PARAM_INPUT0, aInput0 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_DEBOUNCING_PARAM_INPUT1, aInput1 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_DEBOUNCING_PARAM_INPUT2, aInput2 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_DEBOUNCING_PARAM_INPUT3, aInput3 ) != CY_RESULT_OK )  )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult GetDebouncing( CY_UINT16& aInput0,
                            CY_UINT16& aInput1 ) const
    {
        unsigned short lDummy;
        return GetDebouncing( aInput0, aInput1, lDummy, lDummy );
    }

                                               
    // GPIO Functions select ( Device firmware version > 3.x )
    //
    // The possible values and meaning of each parameter depends on the
    // actual device.  Please contact Pleora Technologies for more information

    CyResult SetGPIOFunction( CY_UINT8  aGPIO0,
                              CY_UINT8  aGPIO1,
                              CY_UINT8  aGPIO2,
                              CY_UINT8  aGPIO3,
                              CY_UINT8  aGPIO4 = 0,
                              CY_UINT8  aGPIO5 = 0,
                              CY_UINT8  aGPIO6 = 0,
                              CY_UINT8  aGPIO7 = 0,
                              CY_UINT8  aGPIO8 = 0,
                              CY_UINT8  aGPIO9 = 0,
                              CY_UINT8  aGPIO10 = 0,
                              CY_UINT8  aGPIO11 = 0,
                              CY_UINT8  aCC1 = 0,
                              CY_UINT8  aCC2 = 0,
                              CY_UINT8  aCC3 = 0,
                              CY_UINT8  aCC4 = 0 )
    {
        aGPIO8 = 0;
        aGPIO9 = 0;
        aGPIO10 = 0;
        aGPIO11 = 0;
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_FUNCTION_SELECT ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_FUNCTION_SELECT );
        if ( ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_INPUT0, aGPIO0 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_INPUT1, aGPIO1 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_INPUT2, aGPIO2 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_INPUT3, aGPIO3 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT0, aGPIO4 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT1, aGPIO5 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT2, aGPIO6 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT3, aGPIO7 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_CC1, aCC1 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_CC2, aCC2 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_CC3, aCC3 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_FUNCTION_SELECT_CC4, aCC4 ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

    CyResult GetGPIOFunction( CY_UINT8& aGPIO0,
                              CY_UINT8& aGPIO1,
                              CY_UINT8& aGPIO2,
                              CY_UINT8& aGPIO3,
                              CY_UINT8& aGPIO4,
                              CY_UINT8& aGPIO5,
                              CY_UINT8& aGPIO6,
                              CY_UINT8& aGPIO7,
                              CY_UINT8& aGPIO8,
                              CY_UINT8& aGPIO9,
                              CY_UINT8& aGPIO10,
                              CY_UINT8& aGPIO11,
                              CY_UINT8& aCC1,
                              CY_UINT8& aCC2,
                              CY_UINT8& aCC3,
                              CY_UINT8& aCC4 ) const
    {
        aGPIO8 = 0;
        aGPIO9 = 0;
        aGPIO10 = 0;
        aGPIO11 = 0;
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_FUNCTION_SELECT ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_FUNCTION_SELECT );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_INPUT0, aGPIO0 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_INPUT1, aGPIO1 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_INPUT2, aGPIO2 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_INPUT3, aGPIO3 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT0, aGPIO4 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT1, aGPIO5 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT2, aGPIO6 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_OUTPUT3, aGPIO7 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_CC1, aCC1 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_CC2, aCC2 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_CC3, aCC3 ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_FUNCTION_SELECT_CC4, aCC4 ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

    CyResult GetGPIOFunction( CY_UINT8& aGPIO0,
                              CY_UINT8& aGPIO1,
                              CY_UINT8& aGPIO2,
                              CY_UINT8& aGPIO3 ) const
    {
        unsigned char lDummy;
        return GetGPIOFunction( aGPIO0, aGPIO1, aGPIO2, aGPIO3,
                                lDummy, lDummy, lDummy, lDummy,
                                lDummy, lDummy, lDummy, lDummy,
                                lDummy, lDummy, lDummy, lDummy );

    }



    CyResult       SetRescaler( unsigned short  aIndex,
                                CY_UINT8   aGranularity,
                                CY_UINT8   aMultiplier,
                                CY_UINT32  aDivider,
                                CY_UINT8   aInput,
                                bool       aBackupEnabled,
                                CY_UINT8   aBackupInput,
                                CY_UINT16  aBackupWindow )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_RESCALER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_RESCALER + aIndex );
        
        if ( ( lExtension.SetParameter( CY_RESCALER_PARAM_GRANULARITY, aGranularity ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_RESCALER_PARAM_MULTIPLIER, aMultiplier ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_RESCALER_PARAM_DIVIDER, aDivider ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_RESCALER_PARAM_INPUT, aInput ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_RESCALER_PARAM_BACKUP_ENABLED, aBackupEnabled ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_RESCALER_PARAM_BACKUP_INPUT, aBackupInput ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_RESCALER_PARAM_BACKUP_WINDOW, aBackupWindow ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult       GetRescaler( unsigned short  aIndex,
                                CY_UINT8&  aGranularity,
                                CY_UINT8&  aMultiplier,
                                CY_UINT32&  aDivider,
                                CY_UINT8&  aInput,
                                bool&           aBackupEnabled,
                                CY_UINT8&  aBackupInput,
                                CY_UINT16& aBackupWindow ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_RESCALER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_RESCALER + aIndex );
        
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK )  ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_GRANULARITY, aGranularity ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_MULTIPLIER, aMultiplier ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_DIVIDER, aDivider ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_INPUT, aInput ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_BACKUP_ENABLED, aBackupEnabled ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_BACKUP_INPUT, aBackupInput ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_BACKUP_WINDOW, aBackupWindow ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

    CyResult       GetRescalerInputFrequency( unsigned short  aIndex,
                                              double&         aFrequency ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_RESCALER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_RESCALER + aIndex );

        return lExtension.GetParameter( CY_RESCALER_PARAM_INPUT_FREQUENCY, aFrequency );
    }

    CyResult       GetBestRescalerSettings( unsigned short  aIndex,
                                            double          aTargetFrequency,
                                            CY_UINT8&  aGranularity,
                                            CY_UINT8&  aMultiplier,
                                            CY_UINT32&  aDivider ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_RESCALER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_RESCALER + aIndex );

        if ( ( lExtension.SetParameter( CY_RESCALER_PARAM_TARGET_FREQUENCY, aTargetFrequency ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_BEST_GRANULARITY, aGranularity )  != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_BEST_MULTIPLIER, aMultiplier )  != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_RESCALER_PARAM_BEST_DIVIDER, aDivider )  != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }


    CyResult       SetDelayer( unsigned short  aIndex,
                               CY_UINT16 aDelay,
                               CY_UINT8   aReference,
                               CY_UINT8   aInput )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_DELAYER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_DELAYER + aIndex );
        if ( ( lExtension.SetParameter( CY_DELAYER_PARAM_DELAY, aDelay ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DELAYER_PARAM_REFERENCE, aReference ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DELAYER_PARAM_INPUT, aInput ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult       GetDelayer( unsigned short  aIndex,
                               CY_UINT16& aDelay,
                               CY_UINT8&  aReference,
                               CY_UINT8&  aInput ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_DELAYER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_DELAYER + aIndex );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_DELAYER_PARAM_DELAY, aDelay ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_DELAYER_PARAM_REFERENCE, aReference ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_DELAYER_PARAM_INPUT, aInput ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }


    CyResult       SetCounter( unsigned short  aIndex,
                               CY_UINT8   aUpEvent,
                               CY_UINT8   aDownEvent,
                               CY_UINT8   aClearEvent,
                               CY_UINT8   aClearInput )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_COUNTER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_COUNTER + aIndex );
        if ( ( lExtension.SetParameter( CY_COUNTER_PARAM_UP_EVENT, aUpEvent ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_COUNTER_PARAM_DOWN_EVENT, aDownEvent ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_COUNTER_PARAM_CLEAR_EVENT, aClearEvent ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_COUNTER_PARAM_CLEAR_INPUT, aClearInput ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }


    CyResult       GetCounter( unsigned short  aIndex,
                               CY_UINT8&  aUpEvent,
                               CY_UINT8&  aDownEvent,
                               CY_UINT8&  aClearEvent,
                               CY_UINT8&  aClearInput ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_COUNTER + aIndex ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_COUNTER + aIndex );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_COUNTER_PARAM_UP_EVENT, aUpEvent ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_COUNTER_PARAM_DOWN_EVENT, aDownEvent ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_COUNTER_PARAM_CLEAR_EVENT, aClearEvent ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_COUNTER_PARAM_CLEAR_INPUT, aClearInput ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

    // Counter values, compare value and current value
    //

    CyResult       SetCounterCompareValue( unsigned short  aIndex,
                                           CY_UINT32   aValue )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_COUNTER + aIndex ) );
        return GetExtension( CY_DEVICE_EXT_COUNTER + aIndex ).SetParameter( CY_COUNTER_PARAM_COMPARE_VALUE, aValue );
    }
    CyResult       GetCounterCompareValue( unsigned short  aIndex,
                                           CY_UINT32&  aValue ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_COUNTER + aIndex ) );
        return GetExtension( CY_DEVICE_EXT_COUNTER + aIndex ).GetParameter( CY_COUNTER_PARAM_COMPARE_VALUE, aValue );
    }
    CyResult       GetCurrentCounterValue( unsigned short  aIndex,
                                           CY_UINT32&  aValue ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_COUNTER + aIndex ) );
        return GetExtension( CY_DEVICE_EXT_COUNTER + aIndex ).GetParameter( CY_COUNTER_PARAM_CURRENT_VALUE, aValue );
    }
                                             

    CyResult       SetTimestampCounter( CY_UINT8  aGranularity,
                                        CY_UINT8  aSetMode,
                                        CY_UINT8  aSetInput,
                                        CY_UINT8  aClearMode,
                                        CY_UINT8  aClearInput,
                                        CY_UINT8  aCounterSelect,
                                        bool           aBroadcast = false )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER );
        if ( ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_GRANULARITY, aGranularity ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_SET_MODE, aSetMode ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_SET_INPUT, aSetInput ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_CLEAR_MODE, aClearMode ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_CLEAR_INPUT, aClearInput ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_COUNTER_SELECT, aCounterSelect ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_BROADCAST, aBroadcast ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

     CyResult       GetTimestampCounter( CY_UINT8& aGranularity,
                                         CY_UINT8& aSetMode,
                                         CY_UINT8& aSetInput,
                                         CY_UINT8& aClearMode,
                                         CY_UINT8& aClearInput,
                                         CY_UINT8& aCounterSelect ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER );
        if ( ( lExtension.LoadFromDevice() != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_TIMESTAMP_PARAM_GRANULARITY, aGranularity ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_TIMESTAMP_PARAM_SET_MODE, aSetMode ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_TIMESTAMP_PARAM_SET_INPUT, aSetInput ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_TIMESTAMP_PARAM_CLEAR_MODE, aClearMode ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_TIMESTAMP_PARAM_CLEAR_INPUT, aClearInput ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_TIMESTAMP_PARAM_COUNTER_SELECT, aCounterSelect ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }


    // Read or change the set value for the timestamp counter.  This must be call prior
    // to setting the timestamp with SetTimestampCounter or triggering the "set input"
    CyResult       SetTimestampCounterSetValue    ( CY_UINT32 aValue, bool aBroadcast )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER );

         if ( ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_BROADCAST, aBroadcast ) != CY_RESULT_OK ) ||
              ( lExtension.SetParameter( CY_TIMESTAMP_PARAM_SET_VALUE, aValue ) != CY_RESULT_OK ) )
              return SetErrorInfo( lExtension );

         return CY_RESULT_OK;
    }

    CyResult       GetTimestampCounterSetValue    ( CY_UINT32& aValue ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER );

        return lExtension.GetParameter( CY_TIMESTAMP_PARAM_SET_VALUE, aValue );
    }

    // Returns the actual current value of the timestamp.
    CyResult       GetTimestampCounterCurrentValue( CY_UINT32& aValue ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_TIMESTAMP_COUNTER );

        return lExtension.GetParameter( CY_TIMESTAMP_PARAM_CURRENT_VALUE, aValue );
    }


    bool IsTimestampTriggerFIFOFull() const
    {
        bool lBool;       
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_TRIGGERS ) );
        GetExtension( CY_DEVICE_EXT_TIMESTAMP_TRIGGERS ).GetParameter( CY_TIMESTAMP_TRIG_PARAM_FIFO_FULL, lBool );
        return lBool;
    }
    bool IsTimestampTriggerFIFOEmpty() const
    {
        bool lBool;       
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_TRIGGERS ) );
        GetExtension( CY_DEVICE_EXT_TIMESTAMP_TRIGGERS ).GetParameter( CY_TIMESTAMP_TRIG_PARAM_FIFO_EMPTY, lBool );
        return lBool;
    }


    CyResult SetTimestampTrigger( CY_UINT16 aMask,
                                  CY_UINT8  aCounter,
                                  CY_UINT32  aTime )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_TIMESTAMP_TRIGGERS ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_TIMESTAMP_TRIGGERS );

        if ( ( lExtension.SetParameter( CY_TIMESTAMP_TRIG_PARAM_MASK, aMask ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_TRIG_PARAM_COUNTER_SELECT, aCounter ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_TRIG_PARAM_TIME, aTime ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_TIMESTAMP_TRIG_PARAM_ARM, true ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }

    CyResult ClearTimestampTriggers()
    {
        return SetTimestampTrigger( 0, 0, 0 );
    }


        // Setting and clearing GPIO control bits.
    //
    // The aSet and aClear are bit mask that tell if the corresponding
    // input control bit is to be set or cleared.
    //
    // Note this must go in an extension

    CyResult WriteGPIO( CY_UINT16  aSet,
                        CY_UINT16  aClear,
                        bool            aBroadcast = false )
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_CONTROL_BITS ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_CONTROL_BITS );

        if ( ( lExtension.SetParameter( CY_GPIO_CONTROL_BITS_SET  , aSet ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_CONTROL_BITS_CLEAR, aClear ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_GPIO_CONTROL_BITS_BROADCAST, aBroadcast ) != CY_RESULT_OK ) ||
             ( lExtension.SaveToDevice() != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }
    CyResult ReadGPIO ( CY_UINT16& aBits,
                        CY_UINT16& aInputs ) const
    {
        CyAssert( HasExtension( CY_DEVICE_EXT_GPIO_CONTROL_BITS ) );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_CONTROL_BITS );

        if ( ( lExtension.GetParameter( CY_GPIO_CONTROL_BITS_CURRENT_VALUE, aBits ) != CY_RESULT_OK ) ||
             ( lExtension.GetParameter( CY_GPIO_CONTROL_BITS_INPUTS_VALUE, aInputs ) != CY_RESULT_OK ) )
             return SetErrorInfo( lExtension );

        return CY_RESULT_OK;
    }


    bool     CanEnableGPIOInterrupts() const
    {
        return HasExtension( CY_DEVICE_EXT_GPIO_INTERRUPTS );
    }
    CyResult SetGPIOInterrupts( unsigned short  aInterrupts )
    {
        if ( !CanEnableGPIOInterrupts() )
            return SetErrorInfo( "Not supported",
                                 CY_RESULT_NOT_SUPPORTED,
                                 __FILE__,
                                 __LINE__,
                                 0 );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_INTERRUPTS );

        if ( ( lExtension.SetParameter( CY_DEVICE_GPIO_INTERRUPTS_Q15, ( aInterrupts & 0x0001 ) != 0 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DEVICE_GPIO_INTERRUPTS_Q3 , ( aInterrupts & 0x0002 ) != 0 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DEVICE_GPIO_INTERRUPTS_Q7 , ( aInterrupts & 0x0004 ) != 0 ) != CY_RESULT_OK ) ||
             ( lExtension.SetParameter( CY_DEVICE_GPIO_INTERRUPTS_Q10, ( aInterrupts & 0x0008 ) != 0 ) != CY_RESULT_OK ) )
            return SetErrorInfo( lExtension );

        return lExtension.SaveToDevice();
    }
    CyResult GetGPIOInterrupts( CY_UINT16& aInterrupts ) const
    {
        if ( !CanEnableGPIOInterrupts() )
            return SetErrorInfo( "Not supported",
                                 CY_RESULT_NOT_SUPPORTED,
                                 __FILE__,
                                 __LINE__,
                                 0 );
        CyDeviceExtension& lExtension = GetExtension( CY_DEVICE_EXT_GPIO_INTERRUPTS );

        if ( lExtension.LoadFromDevice() != CY_RESULT_OK )
            return SetErrorInfo( lExtension );

        aInterrupts = 0;
        if ( lExtension.GetParameterBool( CY_DEVICE_GPIO_INTERRUPTS_Q15 ) )
            aInterrupts |= 0x0001;
        if ( lExtension.GetParameterBool( CY_DEVICE_GPIO_INTERRUPTS_Q3 ) )
            aInterrupts |= 0x0002;
        if ( lExtension.GetParameterBool( CY_DEVICE_GPIO_INTERRUPTS_Q7 ) )
            aInterrupts |= 0x0004;
        if ( lExtension.GetParameterBool( CY_DEVICE_GPIO_INTERRUPTS_Q10 ) )
            aInterrupts |= 0x0008;

        return CY_RESULT_OK;
    }

    CyResult ConfigPort( unsigned long aPort, CyString& aConfig )
    {
        return SetPortConfig( aPort, aConfig );
    }
    CyResult ConfigPort( Port aPort, const char* aConfig )
    {
        return SetPortConfig( aPort, CyString( aConfig ) );
    }



#undef DEVICE_BACKWARD_COMPATIBILITY_SET
#undef DEVICE_BACKWARD_COMPATIBILITY_GET

#endif // _CY_DEVICE_BACKWARD_COMPATIBILITY_H_

