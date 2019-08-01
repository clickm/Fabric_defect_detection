// *****************************************************************************
//
// $Id: CyConfigBackwardCompatibility.h,v 1.10 2009/05/29 14:46:14 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyConfigBackwardCompatibility.h
//
// Description..: CyConfig object define interface to create and modify device
//                list.
//
// *****************************************************************************

#ifndef _CY_CONFIG_BACKWARD_COMPATIBILITY_H_
#define _CY_CONFIG_BACKWARD_COMPATIBILITY_H_

// Data types
public:

	enum
	{
		MODE_DRV       = CY_CONFIG_MODE_DRV,
		MODE_UDP       = CY_CONFIG_MODE_UDP,
		MODE_TCP       = CY_CONFIG_MODE_TCP,
        MODE_FILTER    = CY_CONFIG_MODE_FILTER,

		MODE_DEFAULT   = 1,
		MODE_LAST      = 3,
		MODE_QTY       = 4
	};
	typedef CY_UINT32 AccessMode;


    enum
    {
	    DSM_UNICAST		    = CY_CONFIG_DSM_UNICAST,
	    DSM_MULTICAST	    = CY_CONFIG_DSM_MULTICAST,
	    DSM_MULTI_UNICAST	= CY_CONFIG_DSM_MULTI_UNICAST,
	    DSM_ROUND_ROBIN	    = CY_CONFIG_DSM_ROUND_ROBIN,
	    DSM_TRIGGER_QUEUE	= CY_CONFIG_DSM_TRIGGER_QUEUE,
    };
    typedef CY_UINT32 DataSendingMode;

public:
    CY_COM_LIB_API static const CY_UINT32 MIN_ANSWER_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 MAX_ANSWER_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 DEFAULT_ANSWER_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 MIN_FIRST_PACKET_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 MAX_FIRST_PACKET_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 DEFAULT_FIRST_PACKET_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 MIN_PACKET_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 MAX_PACKET_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 DEFAULT_PACKET_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 MIN_REQUEST_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 MAX_REQUEST_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 DEFAULT_REQUEST_TIMEOUT;
    CY_COM_LIB_API static const CY_UINT32 TIMEOUT_AUTO;
    CY_COM_LIB_API static const CY_UINT32 MIN_PACKET_SIZE;
    CY_COM_LIB_API static const CY_UINT32 MAX_PACKET_SIZE_UDP;
    CY_COM_LIB_API static const CY_UINT32 MAX_PACKET_SIZE_DRV;
    CY_COM_LIB_API static const CY_UINT32 DEFAULT_PACKET_SIZE_UDP;
    CY_COM_LIB_API static const CY_UINT32 DEFAULT_PACKET_SIZE_DRV;
    CY_COM_LIB_API static const CY_UINT32 MIN_COMMAND_RETRY_COUNT;
    CY_COM_LIB_API static const CY_UINT32 MAX_COMMAND_RETRY_COUNT;
    CY_COM_LIB_API static const CY_UINT32 DEFAULT_COMMAND_RETRY_COUNT;
    CY_COM_LIB_API static const CyAdapterID   DEFAULT_ADAPTER_ID;

	bool IsDeviceSelected() const
    {
        return GetParameterInt( CY_CONFIG_PARAM_CURRENT_INDEX ) >= 0;
    }
	unsigned int GetCount() const
    {
        return GetParameterInt( CY_CONFIG_PARAM_DEVICE_COUNT );
    }

    // Get/set the index to the selected device
	int	GetIndex() const
    {
        return GetParameterInt( CY_CONFIG_PARAM_CURRENT_INDEX );
    }
	CyResult SetIndex( unsigned int aIndex )
    {
        return SetParameter( CY_CONFIG_PARAM_CURRENT_INDEX, aIndex );
    }


    #define CY_IMPLEMENT_INT_PARAMETER( aName, aType, aID ) \
        CyResult Get##aName( aType * aValue ) const \
        { \
            CyAssert( aValue != NULL ); \
            return GetParameter( aID, *aValue ); \
        } \
        CyResult Get##aName( aType& aValue ) const \
        { \
            return GetParameter( aID, aValue ); \
        } \
        CyResult Set##aName( aType aValue ) \
        { \
            return SetParameter( aID, aValue ); \
        }

    #define CY_IMPLEMENT_STRING_PARAMETER( aName, aID ) \
        CyResult Get##aName( CyString& aValue ) \
        { \
            return GetParameter( aID, aValue ); \
        } \
        CyResult Get##aName( char * aValue, unsigned int aValueSize ) const \
        { \
            CyAssert( aValue != NULL ); \
            CyAssert( aValueSize > 0 ); \
            CyString lValue; \
            if ( GetParameter( aID, lValue ) != CY_RESULT_OK ) \
                return GetErrorInfo(); \
            if ( (unsigned int)lValue.size() > aValueSize ) \
                return SetErrorInfo( "Buffer size is too small", CY_RESULT_BUFFER_TOO_SMALL, __FILE__, __LINE__, 0 ); \
            CyStrcpy( aValue, aValueSize, lValue.c_str_ascii() ); \
            return CY_RESULT_OK; \
        } \
        CyResult Set##aName( const char* aValue ) \
        { \
            return SetParameter( aID, CyString( aValue ) ); \
        } \
        CyResult Set##aName( const CyString& aValue ) \
        { \
            return SetParameter( aID, aValue ); \
        }



    CY_IMPLEMENT_INT_PARAMETER( AnswerTimeOut, CY_UINT32, CY_CONFIG_PARAM_ANSWER_TIMEOUT );
    CY_IMPLEMENT_INT_PARAMETER( FirstPacketTimeOut, CY_UINT32, CY_CONFIG_PARAM_FIRST_PACKET_TIMEOUT );
    CY_IMPLEMENT_INT_PARAMETER( PacketTimeOut, CY_UINT32, CY_CONFIG_PARAM_PACKET_TIMEOUT );
    CY_IMPLEMENT_INT_PARAMETER( RequestTimeOut, CY_UINT32, CY_CONFIG_PARAM_REQUEST_TIMEOUT );
    CY_IMPLEMENT_INT_PARAMETER( PacketSize, CY_UINT32, CY_CONFIG_PARAM_PACKET_SIZE )
    CY_IMPLEMENT_INT_PARAMETER( CommandRetryCount, CY_UINT32, CY_CONFIG_PARAM_COMMAND_RETRY_COUNT );
    CY_IMPLEMENT_INT_PARAMETER( AccessMode, AccessMode, CY_CONFIG_PARAM_ACCESS_MODE );
    CY_IMPLEMENT_STRING_PARAMETER( AdapterID, CY_CONFIG_PARAM_ADAPTER_ID );
    CY_IMPLEMENT_STRING_PARAMETER( Address, CY_CONFIG_PARAM_ADDRESS_IP );
    CY_IMPLEMENT_STRING_PARAMETER( MACAddress, CY_CONFIG_PARAM_ADDRESS_MAC );
    CY_IMPLEMENT_STRING_PARAMETER( Name, CY_CONFIG_PARAM_DEVICE_NAME );
    CY_IMPLEMENT_STRING_PARAMETER( DeviceType, CY_CONFIG_PARAM_DEVICE_TYPE );

    CY_IMPLEMENT_INT_PARAMETER( HeartbeatInterval, CY_UINT32, CY_CONFIG_PARAM_HEARTBEAT_INTERVAL );
    CY_IMPLEMENT_INT_PARAMETER( HeartbeatExpiration, CY_UINT32, CY_CONFIG_PARAM_HEARTBEAT_EXPIRATION );

    CY_IMPLEMENT_INT_PARAMETER( DataSendingMode, DataSendingMode, CY_CONFIG_PARAM_DATA_SENDING_MODE );
    CY_IMPLEMENT_INT_PARAMETER( DataSendingModeMaster, bool, CY_CONFIG_PARAM_DATA_SENDING_MODE_MASTER );
    CY_IMPLEMENT_STRING_PARAMETER( DataSendingModeAddress, CY_CONFIG_PARAM_DATA_SENDING_MODE_ADDRESS );


    CyResult GetAdapterID( CyAdapterID * aID ) const
    {
        CyAssert( aID != NULL );
        CyString lValue;
        if ( GetParameter( CY_CONFIG_PARAM_ADAPTER_ID, lValue ) != CY_RESULT_OK )
            return GetErrorInfo();

        *aID = CyAdapterID( lValue );
        return CY_RESULT_OK;
    }

    CyResult SetAdapterID( const CyAdapterID& aID )
    {
        return SetAdapterID( aID.GetIdentifier() );
    }


    CyResult GetMulticast( bool * aEnabled, bool * aMaster ) const
    {
        CyAssert( aEnabled != NULL );
        CyAssert( aMaster != NULL );
        
        *aEnabled = GetParameterInt( CY_CONFIG_PARAM_DATA_SENDING_MODE ) == CY_CONFIG_DSM_MULTICAST;
        *aMaster = GetParameterInt( CY_CONFIG_PARAM_DATA_SENDING_MODE_MASTER ) != 0;

        return CY_RESULT_OK;
    }
    CyResult GetMulticastAddress( char *aOut, unsigned int aOutSize ) const
    {
        return GetDataSendingModeAddress( aOut, aOutSize );
    }
    CyResult SetMulticast( bool aEnabled, bool aMaster )
    {
        if ( SetParameter( CY_CONFIG_PARAM_DATA_SENDING_MODE, aEnabled ? CY_CONFIG_DSM_MULTICAST : CY_CONFIG_DSM_UNICAST ) != CY_RESULT_OK )
            return GetErrorInfo();
        if ( SetParameter( CY_CONFIG_PARAM_DATA_SENDING_MODE_MASTER, aEnabled ? aMaster : true ) != CY_RESULT_OK )
            return GetErrorInfo();

        return CY_RESULT_OK;
    }
    CyResult SetMulticastAddress( const char * aVal )
    {
        return SetDataSendingModeAddress( aVal );
    }

    CyResult FindDeviceByName( const char* aName )
    {
        return FindDeviceByName( CyString( aName ) );
    }

#undef CY_IMPLEMENT_PARAMETER
#undef CY_IMPLEMENT_STRING_PARAMETER

#endif // _CY_CONFIG_BACKWARD_COMPATIBILITY_H_

