// *****************************************************************************
//
// $Id: CyParameterRepositoryUtilities.h,v 1.17 2009/05/29 14:55:28 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyParameterRepositoryUtilities.h
//
// Description..: Repository of parameters
//
// *****************************************************************************

#ifndef __CY_PARAMETER_REPOSITORY_UTILITES_H__
#define __CY_PARAMETER_REPOSITORY_UTILITES_H__

#ifdef WIN32
#pragma warning( push )
#pragma warning( disable : 4244 4800 )
#endif // WIN32

#include "CyTypes.h"

//
// Macros
//

    #define CY_IMPLEMENT_PARAMETER( aTypeC, aTempType, aDefaultValue ) \
        CyResult AddParameter( const CyString& aName, \
                               unsigned long   aType, \
                               aTypeC          aMinValue, \
                               aTypeC          aMaxValue, \
                               unsigned long   aID  = CY_PARAMETER_INVALID_VALUE, \
                               aTypeC          aDefault = aDefaultValue ) \
        { \
            return AddParameter( aName, \
                                 aType, \
                                 static_cast<aTempType>( aMinValue ), \
                                 static_cast<aTempType>( aMaxValue ), \
                                 aID, \
                                 static_cast<aTempType>( aDefault ) ); \
        } \
        CY_UTILS_LIB_API virtual CyResult SetParameterByIndex( unsigned long aIndex, \
                                                               aTypeC        aValue, \
                                                               bool          aTest = false ) \
        { \
            return SetParameterByIndex( aIndex, static_cast<aTempType>( aValue ), aTest ); \
        } \
        CY_UTILS_LIB_API virtual CyResult SetParameter( unsigned long aID, \
                                                        aTypeC        aValue, \
                                                        bool          aTest = false ) \
        { \
            return SetParameter( aID, static_cast<aTempType>( aValue ), aTest ); \
        } \
        CY_UTILS_LIB_API virtual CyResult SetParameter( const CyString& aName, \
                                                        aTypeC          aValue, \
                                                        bool            aTest = false ) \
        { \
            return SetParameter( aName, static_cast<aTempType>( aValue ), aTest ); \
        } \
        CY_UTILS_LIB_API virtual CyResult GetParameterByIndex( unsigned long aIndex, \
                                                               aTypeC&       aValue ) const \
        { \
            aTempType lTemp; \
            if ( GetParameterByIndex( aIndex, lTemp ) != CY_RESULT_OK ) \
                return GetErrorInfo(); \
            aValue = static_cast<aTypeC>( lTemp ); \
            return CY_RESULT_OK; \
        } \
        CY_UTILS_LIB_API virtual CyResult GetParameter( unsigned long aID, \
                                                        aTypeC&       aValue ) const \
        { \
            return GetParameterByIndex( GetIndex( aID ), aValue ); \
        } \
        CY_UTILS_LIB_API virtual CyResult GetParameter( const CyString& aName, \
                                                        aTypeC&         aValue ) const \
        { \
            return GetParameterByIndex( GetIndex( aName ), aValue ); \
        } \
        CyResult GetDefaultByIndex( unsigned long aIndex, aTypeC& aDefault ) \
        { \
            aTempType lTemp; \
            if ( GetDefaultByIndex( aIndex, lTemp ) != CY_RESULT_OK ) \
                return GetErrorInfo(); \
            aDefault = static_cast<aTypeC>( lTemp ); \
            return CY_RESULT_OK; \
        } \
        CyResult GetDefaultValue( unsigned long aID, aTypeC& aDefault ) \
        { \
            return GetDefaultByIndex( GetIndex( aID ), aDefault ); \
        } \
        CyResult GetDefaultValue( const CyString& aName, aTypeC& aDefault ) \
        { \
            return GetDefaultByIndex( GetIndex( aName ), aDefault ); \
        }

    #define CY_IMPLEMENT_PARAMETER_BOOL( aTypeC, aTempType, aDefaultValue ) \
        CyResult AddParameter( const CyString& aName, \
                               unsigned long   aType, \
                               aTypeC          aMinValue, \
                               aTypeC          aMaxValue, \
                               unsigned long   aID  = CY_PARAMETER_INVALID_VALUE, \
                               aTypeC          aDefault = aDefaultValue ) \
        { \
            return AddParameter( aName, \
                                 aType, \
                                 static_cast<aTempType>( aMinValue ), \
                                 static_cast<aTempType>( aMaxValue ), \
                                 aID, \
                                 static_cast<aTempType>( aDefault ) ); \
        } \
        CY_UTILS_LIB_API virtual CyResult SetParameterByIndex( unsigned long aIndex, \
                                                               aTypeC        aValue, \
                                                               bool          aTest = false ) \
        { \
            return SetParameterByIndex( aIndex, static_cast<aTempType>( aValue ), aTest ); \
        } \
        CY_UTILS_LIB_API virtual CyResult SetParameter( unsigned long aID, \
                                                        aTypeC        aValue, \
                                                        bool          aTest = false ) \
        { \
            return SetParameter( aID, static_cast<aTempType>( aValue ), aTest ); \
        } \
        CY_UTILS_LIB_API virtual CyResult SetParameter( const CyString& aName, \
                                                        aTypeC          aValue, \
                                                        bool            aTest = false ) \
        { \
            return SetParameter( aName, static_cast<aTempType>( aValue ), aTest ); \
        } \
        CyResult GetParameterByIndex( unsigned long aIndex, \
                                      aTypeC&       aValue ) const \
        { \
            aTempType lTemp; \
            if ( GetParameterByIndex( aIndex, lTemp ) != CY_RESULT_OK ) \
                return GetErrorInfo(); \
            aValue = lTemp != 0; \
            return CY_RESULT_OK; \
        } \
        CyResult GetParameter( unsigned long aID, \
                               aTypeC&       aValue ) const \
        { \
            return GetParameterByIndex( GetIndex( aID ), aValue ); \
        } \
        CyResult GetParameter( const CyString& aName, \
                               aTypeC&         aValue ) const \
        { \
            return GetParameterByIndex( GetIndex( aName ), aValue ); \
        } \
        CyResult GetDefaultByIndex( unsigned long aIndex, aTypeC& aDefault ) \
        { \
            aTempType lTemp; \
            if ( GetDefaultByIndex( aIndex, lTemp ) != CY_RESULT_OK ) \
                return GetErrorInfo(); \
            aDefault = lTemp != 0; \
            return CY_RESULT_OK; \
        } \
        CyResult GetDefaultValue( unsigned long aID, aTypeC& aDefault ) \
        { \
            return GetDefaultByIndex( GetIndex( aID ), aDefault ); \
        } \
        CyResult GetDefaultValue( const CyString& aName, aTypeC& aDefault ) \
        { \
            return GetDefaultByIndex( GetIndex( aName ), aDefault ); \
        }

    #define CY_IMPLEMENT_GET_BY_VALUE( aName, aTypeC, aTempType ) \
        aTypeC GetParameter##aName##ByIndex( unsigned long aIndex ) const \
        { \
            aTempType lResult; \
            GetParameterByIndex( aIndex, lResult ); \
            return lResult; \
        } \
        aTypeC GetParameter##aName( unsigned long aID ) const \
        { \
            return GetParameter##aName##ByIndex( GetIndex( aID ) ); \
        } \
        aTypeC GetParameter##aName( const CyString& aName ) const \
        { \
            return GetParameter##aName##ByIndex( GetIndex( aName ) ); \
        } \
        aTypeC GetDefault##aName##ByIndex( unsigned long aIndex ) const \
        { \
            aTempType lResult; \
            GetDefaultByIndex( aIndex, lResult ); \
            return lResult; \
        } \
        aTypeC GetDefault##aName( unsigned long aID ) const \
        { \
            return GetDefault##aName##ByIndex( GetIndex( aID ) ); \
        } \
        aTypeC GetDefault##aName( const CyString& aName ) const \
        { \
            return GetDefault##aName##ByIndex( GetIndex( aName ) ); \
        }


    #define CY_IMPLEMENT_GET_BY_VALUE_BOOL( aName, aTypeC, aTempType ) \
        aTypeC GetParameter##aName##ByIndex( unsigned long aIndex ) const \
        { \
            aTempType lResult; \
            GetParameterByIndex( aIndex, lResult ); \
            return lResult != 0; \
        } \
        aTypeC GetParameter##aName( unsigned long aID ) const \
        { \
            return GetParameter##aName##ByIndex( GetIndex( aID ) ); \
        } \
        aTypeC GetParameter##aName( const CyString& aName ) const \
        { \
            return GetParameter##aName##ByIndex( GetIndex( aName ) ); \
        } \
        aTypeC GetDefault##aName##ByIndex( unsigned long aIndex ) const \
        { \
            aTempType lResult; \
            GetDefaultByIndex( aIndex, lResult ); \
            return lResult != 0; \
        } \
        aTypeC GetDefault##aName( unsigned long aID ) const \
        { \
            return GetDefault##aName##ByIndex( GetIndex( aID ) ); \
        } \
        aTypeC GetDefault##aName( const CyString& aName ) const \
        { \
            return GetDefault##aName##ByIndex( GetIndex( aName ) ); \
        }


    #define IMPLEMENT_ATTRIBUTE_FUNCTION( aName, aFlag ) \
        bool Is##aName##ByIndex( unsigned long aIndex ) const \
        { \
            return ( GetAttributesByIndex( aIndex ) & CY_PARAMETER_ATTR_##aFlag ) != 0; \
        } \
        bool Is##aName( unsigned long aID ) const \
        { \
            return Is##aName##ByIndex( GetIndex( aID ) ); \
        } \
        bool Is##aName( const CyString& aName ) const \
        { \
            return Is##aName##ByIndex( GetIndex( aName ) ); \
        } \
        void Set##aName##ByIndex( unsigned long aIndex, bool aValue ) \
        { \
            unsigned long lCurrent = GetAttributesByIndex( aIndex ); \
            if ( aValue ) \
                lCurrent |= CY_PARAMETER_ATTR_##aFlag; \
            else \
                lCurrent &= ~CY_PARAMETER_ATTR_##aFlag; \
            SetAttributesByIndex( aIndex, lCurrent ); \
        } \
        void Set##aName( unsigned long aID, bool aValue ) \
        { \
            Set##aName##ByIndex( GetIndex( aID ), aValue ); \
        } \
        void Set##aName( const CyString& aName, bool aValue ) \
        { \
            Set##aName##ByIndex( GetIndex( aName ), aValue ); \
        }


//
// Implement types that are aliases over Integer and Double
//

    // Wrappers for CY_INT8 type over CY_INT64
    CY_IMPLEMENT_PARAMETER( CY_INT8, CY_INT64, 0 )

    // Wrappers for CY_UINT8 type over CY_INT64
    CY_IMPLEMENT_PARAMETER( CY_UINT8, CY_INT64, 0 )
    
    // Wrappers for CY_INT16 type over CY_INT64
    CY_IMPLEMENT_PARAMETER( CY_INT16, CY_INT64, 0 )

    // Wrappers for CY_UINT16 type over CY_INT64
    CY_IMPLEMENT_PARAMETER( CY_UINT16, CY_INT64, 0 )

    // Wrappers for CY_INT32 type over CY_INT64
    CY_IMPLEMENT_PARAMETER( CY_INT32, CY_INT64, 0 )

    // Wrappers for CY_UINT32 type over CY_INT64
    CY_IMPLEMENT_PARAMETER( CY_UINT32, CY_INT64, 0 )
    
#ifndef __LP64__
    // Wrappers for int over CY_INT64
    CY_IMPLEMENT_PARAMETER( long, CY_INT64, 0 )

    // Wrappers for unsigned int over CY_INT64
    CY_IMPLEMENT_PARAMETER( unsigned long, CY_INT64, 0 )
#endif /* __LP64__ */

    // Wrappers for flaot over double
    CY_IMPLEMENT_PARAMETER( float, double, 0.0 )

    // Wrappers for bool over CY_INT64
    CY_IMPLEMENT_PARAMETER_BOOL( bool, CY_INT64, false )


//
// Implement GetParameterTYPE to easily return parameter by their types
//

    // Return by type
    CY_IMPLEMENT_GET_BY_VALUE( String, CyString, CyString )
    CY_IMPLEMENT_GET_BY_VALUE( Char, CY_INT8, CY_INT64 )
    CY_IMPLEMENT_GET_BY_VALUE( UChar, CY_UINT8, CY_INT64 )
    CY_IMPLEMENT_GET_BY_VALUE( Short, CY_INT16, CY_INT64 )
    CY_IMPLEMENT_GET_BY_VALUE( UShort, CY_UINT16, CY_INT64 )
    CY_IMPLEMENT_GET_BY_VALUE( Int, CY_INT32, CY_INT64 )
    CY_IMPLEMENT_GET_BY_VALUE( UInt, CY_UINT32, CY_INT64 )
#ifndef __LP64__    
    CY_IMPLEMENT_GET_BY_VALUE( Long, long, CY_INT64 )
    CY_IMPLEMENT_GET_BY_VALUE( ULong, unsigned long, CY_INT64 )
#endif /* __LP64__ */        
    CY_IMPLEMENT_GET_BY_VALUE( Int64, CY_INT64, CY_INT64 )
    CY_IMPLEMENT_GET_BY_VALUE( Double, double, double )
    CY_IMPLEMENT_GET_BY_VALUE( Float, float, double )
    CY_IMPLEMENT_GET_BY_VALUE_BOOL( Bool, bool, CY_INT64 )



    //
    // Implement Set/Get functions for the attributes.
    //

    IMPLEMENT_ATTRIBUTE_FUNCTION( ReadOnly, READ_ONLY );
    IMPLEMENT_ATTRIBUTE_FUNCTION( Hidden, HIDDEN );
    IMPLEMENT_ATTRIBUTE_FUNCTION( Volatile, VOLATILE );
    IMPLEMENT_ATTRIBUTE_FUNCTION( Persistent, PERSISTENT );
    IMPLEMENT_ATTRIBUTE_FUNCTION( Vital, VITAL );
    IMPLEMENT_ATTRIBUTE_FUNCTION( Advanced, ADVANCED );
    IMPLEMENT_ATTRIBUTE_FUNCTION( RestartRequired, RESTART_REQUIRED );
    IMPLEMENT_ATTRIBUTE_FUNCTION( MultiLine, MULTI_LINE );
    IMPLEMENT_ATTRIBUTE_FUNCTION( Helper, HELPER );
    IMPLEMENT_ATTRIBUTE_FUNCTION( Hexadecimal, HEXADECIMAL );



//
// Macros to easily register parameters in the repository
//

    #define DEFINE_PARAMETER_INT( aID, aMin, aMax, aDefault, aReadOnly, aHidden, aVolatile, aPersistent, aAdvanced, aRestartRequired, aVital ) \
            AddParameter( aID##_LABEL, \
                          CY_PARAMETER_INT, \
                          static_cast<CY_INT64>( aMin ), \
                          static_cast<CY_INT64>( aMax ), \
                          aID, \
                          static_cast<CY_INT64>( aDefault ) ); \
        SetReadOnly( aID, aReadOnly ); \
        SetHidden( aID, aHidden ); \
        SetVolatile( aID, aVolatile ); \
        SetPersistent( aID, aPersistent ); \
        SetAdvanced( aID, aAdvanced ); \
        SetRestartRequired( aID, aRestartRequired ); \
        SetVital( aID, aVital );

    #define DEFINE_PARAMETER_BOOL( aID, aMin, aMax, aDefault, aReadOnly, aHidden, aVolatile, aPersistent, aAdvanced, aRestartRequired, aVital ) \
            AddParameter( aID##_LABEL, \
                          CY_PARAMETER_BOOL, \
                          static_cast<CY_INT64>( aMin ), \
                          static_cast<CY_INT64>( aMax ), \
                          aID, \
                          static_cast<CY_INT64>( aDefault ) ); \
        SetReadOnly( aID, aReadOnly ); \
        SetHidden( aID, aHidden ); \
        SetVolatile( aID, aVolatile ); \
        SetPersistent( aID, aPersistent ); \
        SetAdvanced( aID, aAdvanced ); \
        SetRestartRequired( aID, aRestartRequired ); \
        SetVital( aID, aVital );

    #define DEFINE_PARAMETER_ENUM( aID, aMin, aMax, aDefault, aReadOnly, aHidden, aVolatile, aPersistent, aAdvanced, aRestartRequired, aVital ) \
            AddParameter( aID##_LABEL, \
                          CY_PARAMETER_ENUM, \
                          static_cast<CY_INT64>( aMin ), \
                          static_cast<CY_INT64>( aMax ), \
                          aID, \
                          static_cast<CY_INT64>( aDefault ) ); \
        SetReadOnly( aID, aReadOnly ); \
        SetHidden( aID, aHidden ); \
        SetVolatile( aID, aVolatile ); \
        SetPersistent( aID, aPersistent ); \
        SetAdvanced( aID, aAdvanced ); \
        SetRestartRequired( aID, aRestartRequired ); \
        SetVital( aID, aVital );
        
    #define DEFINE_PARAMETER_DOUBLE( aID, aMin, aMax, aDefault, aReadOnly, aHidden, aVolatile, aPersistent, aAdvanced, aRestartRequired, aVital ) \
            AddParameter( aID##_LABEL, \
                          CY_PARAMETER_DOUBLE, \
                          static_cast<double>( aMin ), \
                          static_cast<double>( aMax ), \
                          aID, \
                          static_cast<double>( aDefault ) ); \
        SetReadOnly( aID, aReadOnly ); \
        SetHidden( aID, aHidden ); \
        SetVolatile( aID, aVolatile ); \
        SetPersistent( aID, aPersistent ); \
        SetAdvanced( aID, aAdvanced ); \
        SetRestartRequired( aID, aRestartRequired ); \
        SetVital( aID, aVital );

    #define DEFINE_PARAMETER_STRING( aID, aDefault, aReadOnly, aHidden, aVolatile, aPersistent, aAdvanced, aRestartRequired, aVital ) \
            AddParameter( aID##_LABEL, \
                          CY_PARAMETER_STRING, \
                          aID, \
                          CyString( aDefault ) ); \
        SetReadOnly( aID, aReadOnly ); \
        SetHidden( aID, aHidden ); \
        SetVolatile( aID, aVolatile ); \
        SetPersistent( aID, aPersistent ); \
        SetAdvanced( aID, aAdvanced ); \
        SetRestartRequired( aID, aRestartRequired ); \
        SetVital( aID, aVital );

    #define SET_PARAMETER_DESCRIPTION(aID) \
        SetParameterDescription( aID, aID##_DESC )

    #define ADD_PARAMETER_ALIAS(aID, aIndex) \
        AddAlias( aID##_LABEL, aID##_ALIAS_##aIndex )

    //
    // Undefine macros that are used only in the file
    //

    #undef CY_IMPLEMENT_PARAMETER
    #undef CY_IMPLEMENT_PARAMETER_BOOL
    #undef CY_IMPLEMENT_GET_BY_VALUE
    #undef CY_IMPLEMENT_GET_BY_VALUE_BOOL

#ifdef WIN32
#pragma warning( pop )
#endif // WIN32

#endif // __CY_PARAMETER_REPOSITORY_UTILITES_H__
