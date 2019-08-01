// *****************************************************************************
//
// $Id: CyParameterRepository.h,v 1.58 2009/08/19 20:15:36 jwhitwill Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyParameterRepository.h
//
// Description..: Repository of parameters
//
// *****************************************************************************

#ifndef __CY_PARAMETER_REPOSITORY_H__
#define __CY_PARAMETER_REPOSITORY_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include "CyTypes.h"
#include "CyErrorInterface.h"
#include "CyString.h"
#include "CyUtilsLibCDef.h"


// Constants
/////////////////////////////////////////////////////////////////////////////

typedef enum
{
    CY_PARAMETER_STRING            =  0,
    CY_PARAMETER_INT               =  1,
    CY_PARAMETER_DOUBLE            =  2,
    CY_PARAMETER_BOOL              =  3,
    CY_PARAMETER_ENUM              =  4,

    // Aliases for integer, internally the same as CY_PARAMETER_INT
    CY_PARAMETER_BYTE              =  5,
    CY_PARAMETER_CHAR              =  6,
    CY_PARAMETER_SHORT             =  7,
    CY_PARAMETER_USHORT            =  8,
    CY_PARAMETER_UINT              =  9,
    CY_PARAMETER_LONG              = 10,
    CY_PARAMETER_ULONG             = 11,

    // Aliases for floating point, internally the same as CY_PARAMETER_DOUBLE
    CY_PARAMETER_FLOAT             = 12,

    // Invalid parameter type
    CY_PARAMETER_INVALID           = 13,
} CyParameterType;

// Invalid ID or INDEX constant
typedef enum
{
    CY_PARAMETER_INVALID_VALUE = 0xFFFFFFFF,
} CyParameterInvalidValue;

// Callback types
typedef enum
{
    CY_PARAMETER_CALLBACK_SET      = 0,
    CY_PARAMETER_CALLBACK_GET      = 1,
    CY_PARAMETER_CALLBACK_CHANGED  = 2,
    CY_PARAMETER_CALLBACK_QTY      = 3,
} CyParameterCallbackTypes;

// Callback function prototype
typedef CyResult (CY_CALLING_CONV * CyParameterCallback )( unsigned long   aCallbackID,
                                                           unsigned long   aParameterIndex,
                                                           unsigned long   aParameterId,
                                                           const char*     aParameterName,
                                                           void*           aContext,
                                                           int             aTest,       // used on for "SET"
                                                           const char*     aValueS,     // used on for "SET" and "CHANGED"
                                                           CY_INT64        aValueI,     // used on for "SET" and "CHANGED"
                                                           double          aValueD );   // used on for "SET" and "CHANGED"

// Parameter Attributes
#define CY_PARAMETER_ATTR_READ_ONLY        0x00000001
#define CY_PARAMETER_ATTR_HIDDEN           0x00000002
#define CY_PARAMETER_ATTR_VOLATILE         0x00000004
#define CY_PARAMETER_ATTR_PERSISTENT       0x00000008
#define CY_PARAMETER_ATTR_VITAL            0x00000010
#define CY_PARAMETER_ATTR_ADVANCED         0x00000020
#define CY_PARAMETER_ATTR_RESTART_REQUIRED 0x00000040
#define CY_PARAMETER_ATTR_MULTI_LINE       0x00000080
#define CY_PARAMETER_ATTR_HELPER           0x00000100
#define CY_PARAMETER_ATTR_HEXADECIMAL      0x00000200


// Class CyParameterRepository
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyParameterRepository : public CyErrorInterface
{
// Utilities
public:
    // Indicates if a parameter is an integer type
    CY_UTILS_LIB_API static bool CY_CALLING_CONV IsString       ( unsigned long aType );
    CY_UTILS_LIB_API static bool CY_CALLING_CONV IsInteger      ( unsigned long aType );
    CY_UTILS_LIB_API static bool CY_CALLING_CONV IsFloatingPoint( unsigned long aType );

// Construction / Destruction
public:
    CY_UTILS_LIB_API            CyParameterRepository();
    CY_UTILS_LIB_API            CyParameterRepository( const CyString& aName,
                                                       unsigned long   aID = CY_PARAMETER_INVALID_VALUE );
    CY_UTILS_LIB_API virtual    ~CyParameterRepository();

// Methods
public:
    //
    // Repository information
    //

    // Return the name, ID and group of the repository
    CY_UTILS_LIB_API virtual const CyString& GetName() const;
    CY_UTILS_LIB_API virtual unsigned long   GetID() const;
    CY_UTILS_LIB_API virtual const CyString& GetGroup() const;

    // Returns the number of parameters in the repository
    CY_UTILS_LIB_API virtual unsigned long   GetParameterCount() const;

protected:
    // Change the name, ID or group of the repository (only available to derived classes)
    CY_UTILS_LIB_API virtual void SetRepositoryName( const CyString& aName );
    CY_UTILS_LIB_API virtual void SetRepositoryID( unsigned long aID );
    CY_UTILS_LIB_API virtual void SetGroup( const CyString& aName );

    //
    // Parameter Information
    //

public:
    // Indicates if a parameter exists
    CY_UTILS_LIB_API virtual bool            HasParameter( unsigned long   aID ) const;
    CY_UTILS_LIB_API virtual bool            HasParameter( const CyString& aName ) const;

    // Returns the index of a parameter from its name
    // Returns (-1) if no parameter exists with the given name
    CY_UTILS_LIB_API virtual unsigned long   GetIndex   ( const CyString& aName ) const;
    CY_UTILS_LIB_API virtual unsigned long   GetIndex   ( unsigned long   aID ) const;

    // Returns the identifier of a parameter
    CY_UTILS_LIB_API virtual unsigned long   GetIdentifier    ( unsigned long   aIndex ) const;
    CY_UTILS_LIB_API virtual unsigned long   GetIdentifier    ( const CyString& aName  ) const;

    // Returns the type of a parameter
    CY_UTILS_LIB_API virtual unsigned long   GetParameterTypeByIndex( unsigned long   aIndex ) const;
    CY_UTILS_LIB_API virtual unsigned long   GetParameterType       ( unsigned long   aID    ) const;
    CY_UTILS_LIB_API virtual unsigned long   GetParameterType       ( const CyString& aName  ) const;

    // Returns the name of a parameter
    CY_UTILS_LIB_API virtual const CyString& GetParameterNameByIndex( unsigned long   aIndex ) const;
    CY_UTILS_LIB_API virtual const CyString& GetParameterName       ( unsigned long   aID    ) const;

    // Returns the description of a parameter
    CY_UTILS_LIB_API virtual const CyString& GetParameterDescriptionByIndex( unsigned long   aIndex ) const;
    CY_UTILS_LIB_API virtual const CyString& GetParameterDescription       ( unsigned long   aID    ) const;
    CY_UTILS_LIB_API virtual const CyString& GetParameterDescription       ( const CyString& aName  ) const;

    // Returns the range of a parameter (integer types and max length of strings)
    CY_UTILS_LIB_API virtual CyResult        GetParameterRangeByIndex( unsigned long   aIndex,
                                                                       CY_INT64&       aMinValue,
                                                                       CY_INT64&       aMaxValue ) const;
    CY_UTILS_LIB_API virtual CyResult        GetParameterRange       ( unsigned long   aID,
                                                                       CY_INT64&       aMinValue,
                                                                       CY_INT64&       aMaxValue ) const;
    CY_UTILS_LIB_API virtual CyResult        GetParameterRange       ( const CyString& aName,
                                                                       CY_INT64&       aMinValue,
                                                                       CY_INT64&       aMaxValue ) const;

    // Returns the range of a parameter (integer types)
    CY_UTILS_LIB_API virtual CyResult        GetParameterIncrementByIndex( unsigned long   aIndex,
                                                                           CY_INT64&       aIncrement ) const;
    CY_UTILS_LIB_API virtual CyResult        GetParameterIncrement       ( unsigned long   aID,
                                                                           CY_INT64&       aIncrement ) const;
    CY_UTILS_LIB_API virtual CyResult        GetParameterIncrement       ( const CyString& aName,
                                                                           CY_INT64&       aIncrement ) const;

    // Returns the range of a parameter (floating point types)
    CY_UTILS_LIB_API virtual CyResult        GetParameterRangeByIndex( unsigned long   aIndex,
                                                                       double&         aMinValue,
                                                                       double&         aMaxValue ) const;
    CY_UTILS_LIB_API virtual CyResult        GetParameterRange       ( unsigned long   aID,
                                                                       double&         aMinValue,
                                                                       double&         aMaxValue ) const;
    CY_UTILS_LIB_API virtual CyResult        GetParameterRange       ( const CyString& aName,
                                                                       double&         aMinValue,
                                                                       double&         aMaxValue ) const;

    //
    // Copy the parameters of a repository to another.  Parameters are copied by IDs.  If
    // a parameter ID exists in both it will be copied, otherwise it is ignored.
    //

    CY_UTILS_LIB_API static CyResult CY_CALLING_CONV
                                            Copy( CyParameterRepository&       aDest,
                                                  const CyParameterRepository& aSource );

    //
    //  Parameter Attributes
    //
    
    CY_UTILS_LIB_API virtual unsigned long GetAttributesByIndex( unsigned long   aIndex ) const;
    CY_UTILS_LIB_API virtual unsigned long GetAttributes       ( unsigned long   aID    ) const;
    CY_UTILS_LIB_API virtual unsigned long GetAttributes       ( const CyString& aName  ) const;

protected:
    CY_UTILS_LIB_API virtual CyResult      SetAttributesByIndex( unsigned long   aIndex,
                                                                 unsigned long   aAttrib );
    CY_UTILS_LIB_API virtual CyResult      SetAttributes       ( unsigned long   aID,
                                                                 unsigned long   aAttrib );
    CY_UTILS_LIB_API virtual CyResult      SetAttributes       ( const CyString& aName,
                                                                 unsigned long   aAttrib );

    CY_UTILS_LIB_API virtual CyResult      EnableReadOnlyChecking( bool aEnabled = true );

public:


    // Indicates if the parameter has changed.
    // GetParameter or HasParameterChanged[ByIndex] reset the flag to false
    CY_UTILS_LIB_API virtual bool            HasParameterChangedByIndex( unsigned long   aIndex ) const;
    CY_UTILS_LIB_API virtual bool            HasParameterChanged       ( unsigned long   aID    ) const;
    CY_UTILS_LIB_API virtual bool            HasParameterChanged       ( const CyString& aName  ) const;

    // Returns the default value of a parameter (for strings)
    CY_UTILS_LIB_API virtual CyResult GetDefaultByIndex( unsigned long   aIndex,
                                                         CyString&       aDefault ) const;
    CY_UTILS_LIB_API virtual CyResult GetDefault       ( unsigned long   aID,
                                                         CyString&       aDefault ) const;
    CY_UTILS_LIB_API virtual CyResult GetDefault       ( const CyString& aName,
                                                         CyString&       aDefault ) const;

    // Returns the default value of a parameter (for integers)
    CY_UTILS_LIB_API virtual CyResult GetDefaultByIndex( unsigned long   aIndex,
                                                         CY_INT64&       aDefault ) const;
    CY_UTILS_LIB_API virtual CyResult GetDefault       ( unsigned long   aID,
                                                         CY_INT64&       aDefault ) const;
    CY_UTILS_LIB_API virtual CyResult GetDefault       ( const CyString& aName,
                                                         CY_INT64&       aDefault ) const;

    // Returns the default value of a parameter (for floating point)
    CY_UTILS_LIB_API virtual CyResult GetDefaultByIndex( unsigned long   aIndex,
                                                         double&         aDefault ) const;
    CY_UTILS_LIB_API virtual CyResult GetDefault       ( unsigned long   aID,
                                                         double&         aDefault ) const;
    CY_UTILS_LIB_API virtual CyResult GetDefault       ( const CyString& aName,
                                                         double&         aDefault ) const;


    //
    // Adding/Removing parameters to the repository.
    // Protected in order to allow only derived classes to do so
    //
protected:
    // Adds a parameter, with the limits being that of the type
    CY_UTILS_LIB_API virtual CyResult AddParameter( const CyString& aName,
                                                    unsigned long   aType,
                                                    unsigned long   aIdentifier = CY_PARAMETER_INVALID_VALUE,
                                                    const CyString& aDefault = CyString() );

    // Adds a parameter with specified limits
    //      char, byte, short, ushort, int, uint, long, ulong, int64 and enum
    CY_UTILS_LIB_API virtual CyResult AddParameter   ( const CyString& aName,
                                                       unsigned long   aType,
                                                       CY_INT64        aMinValue,
                                                       CY_INT64        aMaxValue,
                                                       unsigned long   aIdentifier = CY_PARAMETER_INVALID_VALUE,
                                                       CY_INT64        aDefault = 0 );

    // Adds a parameter with specified limits
    //      double and float
    CY_UTILS_LIB_API virtual CyResult AddParameter( const CyString& aName,
                                                    unsigned long   aType,
                                                    double          aMinValue,
                                                    double          aMaxValue,
                                                    unsigned long   aIdentifier = CY_PARAMETER_INVALID_VALUE,
                                                    double          aDefault = 0.0 );

    // Adds an alias for a parameter name
    CY_UTILS_LIB_API virtual CyResult AddAlias( const CyString& aName,
                                                const CyString& aAlias );

    // Remove a parameter from the repository
    CY_UTILS_LIB_API virtual CyResult RemoveParameterByIndex( unsigned long aIndex );
    CY_UTILS_LIB_API virtual CyResult RemoveParameter       ( unsigned long aID );
    CY_UTILS_LIB_API virtual CyResult RemoveParameter       ( const CyString& aName);


    // Sets/Gets a parameters range (for integers and max length of strings)
    CY_UTILS_LIB_API virtual CyResult SetParameterRangeByIndex( unsigned long   aIndex,
                                                                CY_INT64        aMinValue,
                                                                CY_INT64        aMaxValue );
    CY_UTILS_LIB_API virtual CyResult SetParameterRange       ( unsigned long   aID,
                                                                CY_INT64        aMinValue,
                                                                CY_INT64        aMaxValue );
    CY_UTILS_LIB_API virtual CyResult SetParameterRange       ( const CyString& aName,
                                                                CY_INT64        aMinValue,
                                                                CY_INT64        aMaxValue );

    // Sets the increment size (for integers)
    CY_UTILS_LIB_API virtual CyResult SetParameterIncrementByIndex( unsigned long   aIndex,
                                                                    CY_INT64        aIncrement );
    CY_UTILS_LIB_API virtual CyResult SetParameterIncrement       ( unsigned long   aID,
                                                                    CY_INT64        aIncrement );
    CY_UTILS_LIB_API virtual CyResult SetParameterIncrement       ( const CyString& aName,
                                                                    CY_INT64        aIncrement );

    // Sets/Gets a parameters range (for floating points)
    CY_UTILS_LIB_API virtual CyResult SetParameterRangeByIndex( unsigned long   aIndex,
                                                                double          aMinValue,
                                                                double          aMaxValue );
    CY_UTILS_LIB_API virtual CyResult SetParameterRange       ( unsigned long   aID,
                                                                double          aMinValue,
                                                                double          aMaxValue );
    CY_UTILS_LIB_API virtual CyResult SetParameterRange       ( const CyString& aName,
                                                                double          aMinValue,
                                                                double          aMaxValue );

    // Add a value string to an enumeration parameter
    CY_UTILS_LIB_API virtual CyResult AddEnumParameterValueByIndex( unsigned long   aIndex,
                                                                    const CyString& aValue );
    CY_UTILS_LIB_API virtual CyResult AddEnumParameterValue       ( unsigned long   aID,
                                                                    const CyString& aValue );
    CY_UTILS_LIB_API virtual CyResult AddEnumParameterValue       ( const CyString& aName,
                                                                    const CyString& aValue );

    // Replace a value string to an enumeration parameter
    CY_UTILS_LIB_API virtual CyResult ReplaceEnumParameterValueByIndex( unsigned long   aIndex,
                                                                        CY_INT64        aValueIndex,
                                                                        const CyString& aValue );
    CY_UTILS_LIB_API virtual CyResult ReplaceEnumParameterValue       ( unsigned long   aID,
                                                                        CY_INT64        aValueIndex,
                                                                        const CyString& aValue );
    CY_UTILS_LIB_API virtual CyResult ReplaceEnumParameterValue       ( const CyString& aName,
                                                                        CY_INT64        aValueIndex,
                                                                        const CyString& aValue );

    // Gets/Sets a string descriptions for a parameter
    CY_UTILS_LIB_API virtual CyResult SetParameterDescriptionByIndex( unsigned long   aIndex,
                                                                      const CyString& aDesc );
    CY_UTILS_LIB_API virtual CyResult SetParameterDescription       ( unsigned long   aID,
                                                                      const CyString& aDesc );
    CY_UTILS_LIB_API virtual CyResult SetParameterDescription       ( const CyString& aName,
                                                                      const CyString& aDesc );

public:
    // Gets/Sets a string parameter
    CY_UTILS_LIB_API virtual CyResult SetParameterByIndex( unsigned long   aIndex,
                                                           const CyString& aValue,
                                                           bool            aTest = false );
    CY_UTILS_LIB_API virtual CyResult SetParameter       ( unsigned long   aID,
                                                           const CyString& aValue,
                                                           bool            aTest = false );
    CY_UTILS_LIB_API virtual CyResult SetParameter       ( const CyString& aName,
                                                           const CyString& aValue,
                                                           bool            aTest = false );
    CY_UTILS_LIB_API virtual CyResult GetParameterByIndex( unsigned long   aIndex,
                                                           CyString&       aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetParameter       ( unsigned long   aID,
                                                           CyString&       aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetParameter       ( const CyString& aName,
                                                           CyString&       aValue ) const;
    
    // Gets/Sets an integer parameter
    //      char, byte, short, ushort, int, uint, long, ulong, bool and enum
    CY_UTILS_LIB_API virtual CyResult SetParameterByIndex( unsigned long   aIndex,
                                                           CY_INT64        aValue,
                                                           bool            aTest = false );
    CY_UTILS_LIB_API virtual CyResult SetParameter       ( unsigned long   aID,
                                                           CY_INT64        aValue,
                                                           bool            aTest = false );
    CY_UTILS_LIB_API virtual CyResult SetParameter       ( const CyString& aName,
                                                           CY_INT64        aValue,
                                                           bool            aTest = false  );
    CY_UTILS_LIB_API virtual CyResult GetParameterByIndex( unsigned long  aIndex,
                                                           CY_INT64&      aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetParameter       ( unsigned long  aID,
                                                           CY_INT64&      aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetParameter       ( const CyString& aName,
                                                           CY_INT64&      aValue ) const;

    // Gets/Sets a floating point parameter
    //      float and double
    CY_UTILS_LIB_API virtual CyResult SetParameterByIndex( unsigned long   aIndex,
                                                           double          aValue,
                                                           bool            aTest = false );
    CY_UTILS_LIB_API virtual CyResult SetParameter       ( unsigned long   aID,
                                                           double          aValue,
                                                           bool            aTest = false );
    CY_UTILS_LIB_API virtual CyResult SetParameter       ( const CyString& aName,
                                                           double          aValue,
                                                           bool            aTest = false  );
    CY_UTILS_LIB_API virtual CyResult GetParameterByIndex( unsigned long   aIndex,
                                                           double&         aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetParameter       ( unsigned long   aID,
                                                           double&         aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetParameter       ( const CyString& aName,
                                                           double&         aValue ) const;

    // Returns information about enumeration values
    CY_UTILS_LIB_API virtual CyResult GetEnumParameterValueByIndex( unsigned long   aIndex,
                                                                    CY_INT64        aValueIndex,
                                                                    CyString&       aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetEnumParameterValue       ( unsigned long   aID,
                                                                    CY_INT64        aValueIndex,
                                                                    CyString&       aValue ) const;
    CY_UTILS_LIB_API virtual CyResult GetEnumParameterValue       ( const CyString& aName,
                                                                    CY_INT64        aValueIndex,
                                                                    CyString&       aValue ) const;
    CY_UTILS_LIB_API virtual CyResult FindEnumValueByIndex        ( unsigned long   aIndex,
                                                                    const CyString& aValue,
                                                                    CY_INT64&       aEnumIndex ) const;
    CY_UTILS_LIB_API virtual CyResult FindEnumValue               ( unsigned long   aID,
                                                                    const CyString& aValue,
                                                                    CY_INT64&       aEnumIndex ) const;
    CY_UTILS_LIB_API virtual CyResult FindEnumValue               ( const CyString& aName,
                                                                    const CyString& aValue,
                                                                    CY_INT64&       aEnumIndex ) const;

    // Invoked by a property page to indicate that it is time to apply the latest changed
    CY_UTILS_LIB_API virtual CyResult ApplyChanges();


    //
    // Callbacks
    //

    // Register a callback function
    CY_UTILS_LIB_API virtual CyParameterCallback
                                      RegisterCallback  ( unsigned long       aCallbackID,
                                                          CyParameterCallback aFunction = NULL,
                                                          void*               aContext  = NULL );
    CY_UTILS_LIB_API virtual CyParameterCallback
                                      UnregisterCallback( unsigned long       aCallbackID,
                                                          CyParameterCallback aFunction,
                                                          void*               aContext );
                                        

    // Get the callback for a function
    CY_UTILS_LIB_API virtual CyParameterCallback
                                      GetCallback     ( unsigned long       aCallbackID ) const;


protected:
    // For derived classes.  Invoked when a parameter is set or queried
    CY_UTILS_LIB_API virtual CyResult OnParameterGet    ( unsigned long   aParameterIndex,
                                                          unsigned long   aParameterID,
                                                          const CyString& aParameterName  );
    CY_UTILS_LIB_API virtual CyResult OnParameterSet    ( unsigned long   aParameterIndex,
                                                          unsigned long   aParameterID,
                                                          const CyString& aParameterName,
                                                          bool            aTest,
                                                          const CyString& aValueS,
                                                          CY_INT64        aValueI,
                                                          double          aValueD );
    CY_UTILS_LIB_API virtual CyResult OnParameterChanged( unsigned long   aParameterIndex,
                                                          unsigned long   aParameterID,
                                                          const CyString& aParameterName,
                                                          const CyString& aValueS,
                                                          CY_INT64        aValueI,
                                                          double          aValueD );


public:
#ifndef CY_PARAMETER_REPOSITORY_NO_UTILITIES
    #include "CyParameterRepositoryUtilities.h"
#endif // CY_PARAMETER_REPOSITORY_NO_UTILITIES

// Members
private:
    friend struct CyParameterRepositoryInternal;
    struct CyParameterRepositoryInternal* mInternal;
#ifdef _MANAGED	//CyParameterRepositoryNet need access to protected members
	friend ref class CyParameterRepositoryNet;
    friend ref class ManipulateRepositoryClass;
#endif //_MANAGED
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////


// Construction - Destruction
CY_UTILS_LIB_C_API( CyParameterRepositoryH ) CyParameterRepository_Init( const char*   aName,
                                                                         unsigned long aID );
CY_UTILS_LIB_C_API( void ) CyParameterRepository_Destroy( CyParameterRepositoryH aHandle );

// Utility to identify parameter type groups
CY_UTILS_LIB_C_API( int ) CyParameterRepository_IsString       ( unsigned long aType );
CY_UTILS_LIB_C_API( int ) CyParameterRepository_IsInteger      ( unsigned long aType );
CY_UTILS_LIB_C_API( int ) CyParameterRepository_IsFloatingPoint( unsigned long aType );

// Return the name and ID of the repository
CY_UTILS_LIB_C_API( const char* )   CyParameterRepository_GetName( CyParameterRepositoryH aHandle );
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetID  ( CyParameterRepositoryH aHandle );

// Returns the number of parameters in the repository
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetParameterCount( CyParameterRepositoryH aHandle );

//
// Parameter Information
//

// Indicates if a parameter exists
CY_UTILS_LIB_C_API( int ) CyParameterRepository_HasParameterByID( CyParameterRepositoryH aHandle,
                                                                  unsigned long          aID );
CY_UTILS_LIB_C_API( int ) CyParameterRepository_HasParameterByName( CyParameterRepositoryH aHandle,
                                                                    const char*            aName );

// Returns the index of a parameter from its name
// Returns (-1) if no parameter exists with the given name
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetIndexByName( CyParameterRepositoryH aHandle,
                                                                          const char*            aName );
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetIndexByID  ( CyParameterRepositoryH aHandle,
                                                                          unsigned long          aID );

// Returns the identifier of a parameter
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetIdentifierByIndex( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aIndex );
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetIdentifierByName( CyParameterRepositoryH aHandle,
                                                                               const char*            aName  );

// Returns the type of a parameter
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetParameterTypeByIndex( CyParameterRepositoryH aHandle,
                                                                                   unsigned long          aIndex );
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetParameterTypeByID   ( CyParameterRepositoryH aHandle,
                                                                                   unsigned long          aID    );
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetParameterTypeByName ( CyParameterRepositoryH aHandle,
                                                                                   const char*            aName  );

// Returns the name of a parameter
CY_UTILS_LIB_C_API( const char* ) CyParameterRepository_GetParameterNameByIndex( CyParameterRepositoryH aHandle,
                                                                                 unsigned long          aIndex );
CY_UTILS_LIB_C_API( const char* ) CyParameterRepository_GetParameterName       ( CyParameterRepositoryH aHandle,
                                                                                 unsigned long          aID    );

// Returns the description of a parameter
CY_UTILS_LIB_C_API( const char* ) CyParameterRepository_GetParameterDescriptionByIndex( CyParameterRepositoryH aHandle,
                                                                                        unsigned long          aIndex );
CY_UTILS_LIB_C_API( const char* ) CyParameterRepository_GetParameterDescriptionByID   ( CyParameterRepositoryH aHandle,
                                                                                        unsigned long          aID    );
CY_UTILS_LIB_C_API( const char* ) CyParameterRepository_GetParameterDescriptionByName ( CyParameterRepositoryH aHandle,
                                                                                        const char*            aName  );

// Returns the range of a parameter (integer types)
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterRangeIntByIndex( CyParameterRepositoryH aHandle,
                                                                                  unsigned long          aIndex,
                                                                                  CY_INT64*              aMinValue,
                                                                                  CY_INT64*              aMaxValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterRangeIntByID   ( CyParameterRepositoryH aHandle,
                                                                                  unsigned long          aID,
                                                                                  CY_INT64*              aMinValue,
                                                                                  CY_INT64*              aMaxValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterRangeIntByName ( CyParameterRepositoryH aHandle,
                                                                                  const char*            aName,
                                                                                  CY_INT64*              aMinValue,
                                                                                  CY_INT64*              aMaxValue );

// Sets the increment size (for integers)
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterIncrementIntByIndex( CyParameterRepositoryH aHandle,
                                                                                      unsigned long          aIndex,
                                                                                      CY_INT64*              aIncrement );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterIncrementIntByID   ( CyParameterRepositoryH aHandle,
                                                                                      unsigned long          aID,
                                                                                      CY_INT64*              aIncrement );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterIncrementIntByName ( CyParameterRepositoryH aHandle,
                                                                                      const char*            aName,
                                                                                      CY_INT64*              aIncrement );


// Returns the range of a parameter (floating point types)
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterRangeDoubleByIndex( CyParameterRepositoryH aHandle,
                                                                                     unsigned long          aIndex,
                                                                                     double*                aMinValue,
                                                                                     double*                aMaxValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterRangeDoubleByID   ( CyParameterRepositoryH aHandle,
                                                                                     unsigned long          aID,
                                                                                     double*                aMinValue,
                                                                                     double*                aMaxValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterRangeDoubleByName ( CyParameterRepositoryH aHandle,
                                                                                     const char*            aName,
                                                                                     double*                aMinValue,
                                                                                     double*                aMaxValue );

CY_UTILS_LIB_C_API( int ) CyParameterRepository_HasParameterChangedByIndex( CyParameterRepositoryH aHandle,
                                                                            unsigned long          aIndex );
CY_UTILS_LIB_C_API( int ) CyParameterRepository_HasParameterChangedByID   ( CyParameterRepositoryH aHandle,
                                                                            unsigned long          aID    );
CY_UTILS_LIB_C_API( int ) CyParameterRepository_HasParameterChangedByName ( CyParameterRepositoryH aHandle,
                                                                            const char*            aName  );

// Returns the default value of a parameter (for strings)
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultStringByIndex( CyParameterRepositoryH aHandle,
                                                                              unsigned long          aIndex,
                                                                              char*                  aBuffer,
                                                                              unsigned long          aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultStringByID   ( CyParameterRepositoryH aHandle,
                                                                              unsigned long          aID,
                                                                              char*                  aBuffer,
                                                                              unsigned long          aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultStringByName ( CyParameterRepositoryH aHandle,
                                                                              const char*            aName,
                                                                              char*                  aBuffer,
                                                                              unsigned long          aBufferSize );

// Returns the default value of a parameter (for integers)
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultIntByIndex( CyParameterRepositoryH aHandle,
                                                                           unsigned long          aIndex,
                                                                           CY_INT64*              aDefault );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultIntByID   ( CyParameterRepositoryH aHandle,
                                                                           unsigned long          aID,
                                                                           CY_INT64*              aDefault );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultIntByName ( CyParameterRepositoryH aHandle,
                                                                           const char*            aName,
                                                                           CY_INT64*              aDefault );

// Returns the default value of a parameter (for floating point)
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultDoubleByIndex( CyParameterRepositoryH aHandle,
                                                                              unsigned long          aIndex,
                                                                              double*                aDefault );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultDoubleByID   ( CyParameterRepositoryH aHandle,
                                                                              unsigned long          aID,
                                                                              double*                aDefault );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetDefaultDoubleByName ( CyParameterRepositoryH aHandle,
                                                                              const char*            aName,
                                                                              double*                aDefault );


//
// Copy
//

CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_Copy( CyParameterRepositoryH aDest,
                                                           CyParameterRepositoryH aSource );


//
//  Parameter Attributes
//

CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetAttributesByIndex( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aIndex );
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetAttributesByID   ( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aID    );
CY_UTILS_LIB_C_API( unsigned long ) CyParameterRepository_GetAttributesByName ( CyParameterRepositoryH aHandle,
                                                                                const char*            aName  );

//
// Get/Set Parameter
//

// Gets/Sets a string parameter
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterStringByIndex( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aIndex,
                                                                                const char*            aValue,
                                                                                int                    aTest );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterStringByID   ( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aID,
                                                                                const char*            aValue,
                                                                                int                    aTest );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterStringByName ( CyParameterRepositoryH aHandle,
                                                                                const char*            aName,
                                                                                const char*            aValue,
                                                                                int                    aTest );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterStringByIndex( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aIndex,
                                                                                char*                  aBuffer,
                                                                                unsigned long          aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterStringByID   ( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aID,
                                                                                char*                  aBuffer,
                                                                                unsigned long          aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterStringByName ( CyParameterRepositoryH aHandle,
                                                                                const char*            aName,
                                                                                char*                  aBuffer,
                                                                                unsigned long          aBufferSize );

// Gets/Sets an integer parameter
//      char, byte, short, ushort, int, uint, long, ulong, int and enum
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterIntByIndex( CyParameterRepositoryH aHandle,
                                                                             unsigned long          aIndex,
                                                                             CY_INT64               aValue,
                                                                             int                    aTest );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterIntByID   ( CyParameterRepositoryH aHandle,
                                                                             unsigned long          aID,
                                                                             CY_INT64               aValue,
                                                                             int                    aTest );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterIntByName ( CyParameterRepositoryH aHandle,
                                                                             const char*            aName,
                                                                             CY_INT64               aValue,
                                                                             int                    aTest  );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterIntByIndex( CyParameterRepositoryH aHandle,
                                                                             unsigned long          aIndex,
                                                                             CY_INT64*              aValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterIntByID   ( CyParameterRepositoryH aHandle,
                                                                             unsigned long          aID,
                                                                             CY_INT64*              aValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterIntByName ( CyParameterRepositoryH aHandle,
                                                                             const char*            aName,
                                                                             CY_INT64*              aValue );

// Gets/Sets a floating point parameter
//      float and double
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterDoubleByIndex( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aIndex,
                                                                                double                 aValue,
                                                                                int                    aTest );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterDoubleByID   ( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aID,
                                                                                double                 aValue,
                                                                                int                    aTest );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_SetParameterDoubleByName ( CyParameterRepositoryH aHandle,
                                                                                const char*            aName,
                                                                                double                 aValue,
                                                                                int                    aTest  );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterDoubleByIndex( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aIndex,
                                                                                double*                aValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterDoubleByID   ( CyParameterRepositoryH aHandle,
                                                                                unsigned long          aID,
                                                                                double*                aValue );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetParameterDoubleByName ( CyParameterRepositoryH aHandle,
                                                                                const char*            aName,
                                                                                double*                aValue );

//
// Enumeration Type Functions
///
    
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetEnumParameterValueByIndex( CyParameterRepositoryH aHandle,
                                                                                   unsigned long          aIndex,
                                                                                   CY_INT64               aValueIndex,
                                                                                   char*                  aBuffer,
                                                                                   unsigned long          aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetEnumParameterValueByID   ( CyParameterRepositoryH aHandle,
                                                                                   unsigned long          aID,
                                                                                    CY_INT64              aValueIndex,
                                                                                   char*                  aBuffer,
                                                                                   unsigned long          aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_GetEnumParameterValueByName ( CyParameterRepositoryH aHandle,
                                                                                   const char*            aName,
                                                                                   CY_INT64               aValueIndex,
                                                                                   char*                  aBuffer,
                                                                                   unsigned long          aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_FindEnumValueByIndex        ( CyParameterRepositoryH aHandle,
                                                                                   unsigned long          aIndex,
                                                                                   const char*            aValue,
                                                                                   CY_INT64*              aEnumIndex );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_FindEnumValueByID           ( CyParameterRepositoryH aHandle,
                                                                                   unsigned long          aID,
                                                                                   const char*            aValue,
                                                                                   CY_INT64*              aEnumIndex );
CY_UTILS_LIB_C_API( CyResult ) CyParameterRepository_FindEnumValueByName         ( CyParameterRepositoryH aHandle,
                                                                                   const char*            aName,
                                                                                   const char*            aValue,
                                                                                   CY_INT64*              aEnumIndex );

//
// Callbacks
//

// Register a callback function
CY_UTILS_LIB_C_API( CyParameterCallback )
                                  CyParameterRepository_RegisterCallback( CyParameterRepositoryH aHandle,
                                                                          unsigned long          aCallbackID,
                                                                          CyParameterCallback    aFunction,
                                                                          void*                  aContext );

// Get the callback for a function
CY_UTILS_LIB_C_API( CyParameterCallback )
                                  CyParameterRepository_GetCallback     ( CyParameterRepositoryH aHandle,
                                                                          unsigned long          aCallbackID );
#endif  // __CY_PARAMETER_REPOSITORY_H__

