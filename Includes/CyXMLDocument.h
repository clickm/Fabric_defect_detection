// *****************************************************************************
//
// $Id: CyXMLDocument.h,v 1.21 2009/05/29 14:55:28 sbouchard Exp $
//
// 
//
// *****************************************************************************
//
//     Copyright (c) 2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyXMLDocument.h
//
// Description..: XML document, internally using Apache Xerces
//
// *****************************************************************************

#ifndef _CY_XML_DOCUMENT_H_
#define _CY_XML_DOCUMENT_H_

// Headers
/////////////////////////////////////////////////////////////////////////////

#include "CyTypes.h"
#include "CyErrorInterface.h"
#include "CyString.h"
#include "CyUtilsLibCDef.h"


// Class CyXMLDocument
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyXMLDocumentInternal;
class CY_UTILS_LIB_API CyXMLDocument : public CyErrorInterface
{
// Constructors / Destructor
public:
            CyXMLDocument( const CyString& aFileName );
    virtual ~CyXMLDocument( );

// Methods
public:
    // save the document to file
    CyResult WriteToFile( );

    // Load the document from the file name
    CyResult LoadDocument( );

    // Create a new empty document
    CyResult CreateDocument( const CyString& aRoot,
                             CY_UINT8   aVersionMajor = 1,
                             CY_UINT8   aVersionMinor = 0 );

    // Document version
    // If no version is available, 0.0 is returned
    CyResult SetVersion( CY_UINT8  aVersionMajor,
                         CY_UINT8  aVersionMinor );
    CyResult GetVersion( CY_UINT8& aVersionMajor,
                         CY_UINT8& aVersionMinor ) const;
    CyResult GetVersion( double& aVersion ) const;

    // Element creation / deletion.
    CyResult CreateElement( const CyString& aName );
    CyResult DeleteElement( );

    // Create a child element with the specified value
    CyResult CreateElement( const CyString& aName,
                            const char*     aValue );
    CyResult CreateElement( const CyString& aName,
                            const CyString& aValue );
    CyResult CreateElement( const CyString& aName,
                            CY_INT8            aValue );
    CyResult CreateElement( const CyString& aName,
                            CY_UINT8   aValue );
    CyResult CreateElement( const CyString& aName,
                            CY_INT16           aValue );
    CyResult CreateElement( const CyString& aName,
                            CY_UINT16  aValue );
    CyResult CreateElement( const CyString& aName,
                            CY_INT32             aValue );
    CyResult CreateElement( const CyString& aName,
                            CY_UINT32    aValue );
#ifndef __LP64__
    CyResult CreateElement( const CyString& aName,
                            long            aValue );
    CyResult CreateElement( const CyString& aName,
                            unsigned long   aValue );
#endif /* __LP64__ */                                                        
    CyResult CreateElement( const CyString&  aName,
                            CY_INT64        aValue );
    CyResult CreateElement( const CyString&  aName,
                            CY_UINT64       aValue );
    CyResult CreateElement( const CyString& aName,
                            float           aValue );
    CyResult CreateElement( const CyString& aName,
                            double          aValue );
    CyResult CreateElement( const CyString& aName,
                            bool            aValue ); 

    // Properties of the current element
    CyResult SetName        ( const CyString& aName );
    CyResult GetName        ( CyString&       aName ) const;
    CyResult SetAttribute   ( const CyString& aAttrib,
                              const char*     aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              const CyString& aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              CY_INT8            aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              CY_UINT8   aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              CY_INT16           aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              CY_UINT16  aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              CY_INT32             aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              CY_UINT32    aValue );
#ifndef __LP64__                              
    CyResult SetAttribute   ( const CyString& aAttrib,
                              long            aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              unsigned long   aValue );
#endif /* __LP64__ */                                                            
    CyResult SetAttribute   ( const CyString&  aAttrib,
                              CY_INT64        aValue );
    CyResult SetAttribute   ( const CyString&  aAttrib,
                              CY_UINT64       aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              float           aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              double          aValue );
    CyResult SetAttribute   ( const CyString& aAttrib,
                              bool            aValue );
    CyResult RemoveAttribute( const CyString& aAttrib );
    CyResult GetAttribute   ( const CyString& aAttrib,
                              CyString&       aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              CY_INT8&           aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              CY_UINT8&  aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              CY_INT16&          aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              CY_UINT16& aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              CY_INT32&            aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              CY_UINT32&   aValue ) const;
#ifndef __LP64__
    CyResult GetAttribute   ( const CyString& aAttrib,
                              long&           aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              unsigned long&  aValue ) const;
#endif /* __LP64__ */                                                            
    CyResult GetAttribute   ( const CyString&   aAttrib,
                              CY_INT64&          aValue ) const;
    CyResult GetAttribute   ( const CyString&   aAttrib,
                              CY_UINT64& aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              float&          aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              double&         aValue ) const;
    CyResult GetAttribute   ( const CyString& aAttrib,
                              bool&           aValue ) const;

    // Get/Set the value of the current element
    CyResult SetValue       ( const char* aValue );
    CyResult SetValue       ( const CyString& aValue );
    CyResult SetValue       ( CY_INT8 aValue );
    CyResult SetValue       ( CY_UINT8 aValue );
    CyResult SetValue       ( CY_INT16 aValue );
    CyResult SetValue       ( CY_UINT16 aValue );
    CyResult SetValue       ( CY_INT32 aValue );
    CyResult SetValue       ( CY_UINT32 aValue );
#ifndef __LP64__
    CyResult SetValue       ( long aValue );
    CyResult SetValue       ( unsigned long aValue );
#endif /* __LP64__ */
    CyResult SetValue       ( CY_INT64 aValue );
    CyResult SetValue       ( CY_UINT64 aValue );
    CyResult SetValue       ( float aValue );
    CyResult SetValue       ( double aValue );
    CyResult SetValue       ( bool aValue );
    CyResult GetValue       ( CyString& aValue) const;
    CyResult GetValue       ( CY_INT8& aValue ) const;
    CyResult GetValue       ( CY_UINT8& aValue ) const;
    CyResult GetValue       ( CY_INT16& aValue ) const;
    CyResult GetValue       ( CY_UINT16& aValue ) const;
    CyResult GetValue       ( CY_INT32& aValue ) const;
    CyResult GetValue       ( CY_UINT32& aValue ) const;
#ifndef __LP64__
    CyResult GetValue       ( long& aValue ) const;
    CyResult GetValue       ( unsigned long& aValue ) const;
#endif /* __LP64__ */
    CyResult GetValue       ( CY_INT64& aValue ) const;
    CyResult GetValue       ( CY_UINT64& aValue ) const;
    CyResult GetValue       ( float& aValue ) const;
    CyResult GetValue       ( double& aValue ) const;
    CyResult GetValue       ( bool& aValue ) const;

    // Get the value of a child element
    CyResult GetValue       ( const CyString& aName,
                              CyString& aValue) const;
    CyResult GetValue       ( const CyString& aName,
                              CY_INT8& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              CY_UINT8& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              CY_INT16& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              CY_UINT16& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              CY_INT32& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              CY_UINT32& aValue ) const;
#ifndef __LP64__
    CyResult GetValue       ( const CyString& aName,
                              long& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              unsigned long& aValue ) const;
#endif /* __LP64__ */                                                            
    CyResult GetValue       ( const CyString& aName,
                              CY_INT64& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              CY_UINT64& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              float& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              double& aValue ) const;
    CyResult GetValue       ( const CyString& aName,
                              bool& aValue ) const;

    // Go to the parent element
    CyResult GotoParentElement();
    bool     HasChildElements();

    // Find a child  element base on name in the current node
    // if successful, the current element will be set on the found element
    CyResult GotoElement( const CyString& aName );
    CyResult GotoElement( const CyString& aName,
                          const CyString& aAttrib,
                          const CyString& aValue );

    // Push/pop current XML location
    CyResult PushLocation();
    CyResult PopLocation();

    // Traverse the sibling elements
    CyResult GotoPreviousElement();
    CyResult GotoNextElement    ();

    // Goto to the child elements
    CyResult GotoFirstChild();
    CyResult GotoLastChild();

    
// Members
private:
    struct CyXMLDocumentInternal* mInternal;

private:
    CyXMLDocument( const CyXMLDocument& );
    CyXMLDocument& operator=( const CyXMLDocument& );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// Construction - Destruction
CY_UTILS_LIB_C_API( CyXMLDocumentH ) CyXMLDocument_Init( const CY_INT8 * aFileName );
CY_UTILS_LIB_C_API( void )           CyXMLDocument_Destroy( CyXMLDocumentH aHandle );

// Document parsing and creation
CY_UTILS_LIB_C_API( CyResult )       CyXMLDocument_LoadDocument  ( CyXMLDocumentH aHandle );
CY_UTILS_LIB_C_API( CyResult )       CyXMLDocument_CreateDocument( CyXMLDocumentH aHandle,
                                                                   const CY_INT8*    aRoot );

// Save a document to file
CY_UTILS_LIB_C_API( CyResult )       CyXMLDocument_WriteToFile( CyXMLDocumentH aHandle );

// Creates an element at the current level and moves the current location to it
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElement( CyXMLDocumentH aHandle,
                                                            const CY_INT8*    aName );

// Delete the current element and moves to the parent element
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_DeleteElement( CyXMLDocumentH aHandle );

// Create a child element with the specified value
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementString( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  const char*    aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementChar  ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  CY_INT8           aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementByte  ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  CY_UINT8  aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementShort ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  CY_INT16          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementUShort( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  CY_UINT16 aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementInt   ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  CY_INT32            aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementUInt  ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  CY_UINT32   aValue );
#ifndef __LP64__
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementLong  ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  long           aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementULong ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  unsigned long  aValue );
#endif /*__LP64__*/
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementInt64 ( CyXMLDocumentH   aHandle,
                                                                  const char*      aName,
                                                                  CY_INT64          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementUInt64( CyXMLDocumentH   aHandle,
                                                                  const char*      aName,
                                                                  CY_UINT64 aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementFloat ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  float          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementDouble( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  double         aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_CreateElementBool  ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  CY_INT32            aValue );

// Set/Get the properties of the current element
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetName ( CyXMLDocumentH aHandle,
                                                       const char*    aName );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetName ( CyXMLDocumentH aHandle,
                                                       CY_INT8*          aBuffer,
                                                       CY_UINT32  aBufferSize );

CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_RemoveAttribute   ( CyXMLDocumentH  aHandle,
                                                                 const char*     aAttrib );

CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeString( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 const CY_INT8*     aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeChar  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT8            aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeByte  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT8   aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeShort ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT16           aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeUShort( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT16  aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeInt   ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT32             aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeUInt  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT32    aAttrib );
#ifndef __LP64__
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeLong  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 long            aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeULong( CyXMLDocumentH   aHandle,
                                                                 const char*     aName,
                                                                 unsigned long   aAttrib );
#endif /* __LP64__ */
                                                                                                                                  
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeInt64 ( CyXMLDocumentH   aHandle,
                                                                 const char*      aName,
                                                                 CY_INT64         aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeUInt64( CyXMLDocumentH    aHandle,
                                                                 const char*      aName,
                                                                 CY_UINT64 aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeFloat ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 float           aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeDouble( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 double          aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetAttributeBool  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT32             aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeString( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT8*           aBuffer,
                                                                 CY_UINT32*  aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeChar  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT8*           aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeByte  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT8*  aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeShort ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT16*          aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeUShort( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT16* aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeInt   ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT32*            aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeUInt  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT32*   aAttrib );
#ifndef __LP64__                                                                  
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeLong  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 long*           aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeULong ( CyXMLDocumentH   aHandle,
                                                                 const char*     aName,
                                                                 unsigned long*  aAttrib );
#endif /* __LP64__ */
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeInt64 ( CyXMLDocumentH    aHandle,
                                                                 const char*       aName,
                                                                 CY_INT64*          aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeUInt64( CyXMLDocumentH    aHandle,
                                                                 const char*       aName,
                                                                 CY_UINT64* aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeFloat ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 float*          aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeDouble( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 double*         aAttrib );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetAttributeBool  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT32*            aAttrib );


// Get/Set the value of the current element
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueString  ( CyXMLDocumentH aHandle,
                                                               const CY_INT8*    aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueChar    ( CyXMLDocumentH aHandle,
                                                               CY_INT8           aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueByte    ( CyXMLDocumentH aHandle,
                                                               CY_UINT8  aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueShort   ( CyXMLDocumentH aHandle,
                                                               CY_INT16          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueUShort  ( CyXMLDocumentH aHandle,
                                                               CY_UINT16 aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueInt     ( CyXMLDocumentH aHandle,
                                                               CY_INT32            aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueUInt    ( CyXMLDocumentH aHandle,
                                                               CY_UINT32   aValue );
#ifndef __LP64__
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueLong    ( CyXMLDocumentH aHandle,
                                                               long           aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueULong   ( CyXMLDocumentH aHandle,
                                                               unsigned long aValue );
#endif /* __LP64__ */
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueInt64   ( CyXMLDocumentH aHandle,
                                                               CY_INT64         aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueUInt64  ( CyXMLDocumentH aHandle,
                                                               CY_UINT64 aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueFloat   ( CyXMLDocumentH aHandle,
                                                               float          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueDouble  ( CyXMLDocumentH aHandle,
                                                               double         aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_SetValueBool    ( CyXMLDocumentH aHandle,
                                                               CY_INT32            aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueString  ( CyXMLDocumentH  aHandle,
                                                               CY_INT8*           aBuffer,
                                                               CY_UINT32   aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueChar    ( CyXMLDocumentH  aHandle,
                                                               CY_INT8*           aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueByte    ( CyXMLDocumentH  aHandle,
                                                               CY_UINT8*  aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueShort   ( CyXMLDocumentH  aHandle,
                                                               CY_INT16*          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueUShort  ( CyXMLDocumentH  aHandle,
                                                               CY_UINT16* aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueInt     ( CyXMLDocumentH  aHandle,
                                                               CY_INT32*            aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueUInt    ( CyXMLDocumentH  aHandle,
                                                               CY_UINT32*   aValue );
#ifndef __LP64__
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueLong    ( CyXMLDocumentH  aHandle,
                                                               long*           aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueULong   ( CyXMLDocumentH  aHandle,
                                                               unsigned long*  aValue );
#endif /* __LP64__ */                                                               
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueInt64   ( CyXMLDocumentH    aHandle,
                                                               CY_INT64*          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueUInt64  ( CyXMLDocumentH    aHandle,
                                                               CY_UINT64* aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueFloat   ( CyXMLDocumentH  aHandle,
                                                               float*          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueDouble  ( CyXMLDocumentH  aHandle,
                                                               double*         aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetValueBool    ( CyXMLDocumentH  aHandle,
                                                               CY_INT32*            aValue );

// Get the value of a chilf element
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueString ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT8*           aBuffer,
                                                                 CY_UINT32   aBufferSize );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueChar   ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT8*           aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueByte   ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT8*  aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueShort  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT16*          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueUShort ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT16* aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueInt    ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT32*            aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueUInt   ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT32*   aValue );
#ifndef __LP64__
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueLong    ( CyXMLDocumentH  aHandle,
                                                                 const char*      aName,
                                                                 long*            aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueULong   ( CyXMLDocumentH  aHandle,
                                                                 const char*      aName,
                                                                 unsigned long*   aValue );
#endif /* __LP64__*/ 
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueInt64  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT64*        aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueUInt64 ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_UINT64* aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueFloat  ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 float*          aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueDouble ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 double*         aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GetSubValueBool   ( CyXMLDocumentH  aHandle,
                                                                 const char*     aName,
                                                                 CY_INT32*            aValue );

// Document traversing
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GotoParentElement  ( CyXMLDocumentH aHandle );
CY_UTILS_LIB_C_API( CY_INT32 )      CyXMLDocument_HasChildElements   ( CyXMLDocumentH aHandle );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GotoElement        ( CyXMLDocumentH aHandle,
                                                                  const char*    aName );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GotoElementAttrib  ( CyXMLDocumentH aHandle,
                                                                  const char*    aName,
                                                                  const CY_INT8*    aAttrib,
                                                                  const CY_INT8*    aValue );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GotoPreviousElement( CyXMLDocumentH aHandle );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GotoNextElement    ( CyXMLDocumentH aHandle );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GotoFirstChild     ( CyXMLDocumentH aHandle );
CY_UTILS_LIB_C_API( CyResult ) CyXMLDocument_GotoLastChild      ( CyXMLDocumentH aHandle );

#endif // _CY_XML_DOCUMENT_H__
