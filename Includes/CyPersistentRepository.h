// *****************************************************************************
//
// $Id: CyPersistentRepository.h,v 1.7 2007/11/13 13:42:07 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyPersistentRepository.h
//
// Description..: Repository that can be saved or loaded from a XML file
//
// *****************************************************************************

#ifndef __CY_PERSISTENT_REPOSITORY_H__
#define __CY_PERSISTENT_REPOSITORY_H__

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include "CyTypes.h"
#include "CyParameterRepository.h"
#include "CyXMLDocument.h"
#include "CyUtilsLibCDef.h"


// Class CyPersistentRepository
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct PersistentRepository;
class CyPersistentRepository : public CyParameterRepository
{
// Construction / Destruction
public:
    CY_UTILS_LIB_API         CyPersistentRepository();
    CY_UTILS_LIB_API         CyPersistentRepository( const CyString& aName,
                                                     unsigned long   aID = CY_PARAMETER_INVALID_VALUE );
    CY_UTILS_LIB_API virtual ~CyPersistentRepository();

    //
    // Copy the parameters of a repository to another.  Parameters are copied by IDs.  If
    // a parameter ID exists in both it will be copied, otherwise it is ignored.
    //

    CY_UTILS_LIB_API static CyResult CY_CALLING_CONV
                                            Copy( CyPersistentRepository&       aDest,
                                                  const CyPersistentRepository& aSource );


// Persistence

    // Indicates if the we want to group the parameters under a common tag.
    // The name of the tag is the name of the repository.
    CY_UTILS_LIB_API virtual void     GroupParametersInXML( bool aGroup );
    CY_UTILS_LIB_API virtual bool     ParametersAreGroupedInXML() const;

    // Save the parameters in to a XML document.
    CY_UTILS_LIB_API virtual CyResult SaveToXML  ( CyXMLDocument& aDocument ) const;

    // Load the parameters in from a XML document.
    CY_UTILS_LIB_API virtual CyResult LoadFromXML( CyXMLDocument& aDocument );

// Members
private:
    friend struct PersistentRepository;
    struct PersistentRepository* mInternal;
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////
// Construction (use CyParameterRepository_Destroy to delete a persistent repository)
CY_UTILS_LIB_C_API( CyPersistentRepositoryH ) CyPersistentRepository_Init( const char*   aName,
                                                                           unsigned long aID );

// Copy
CY_UTILS_LIB_C_API( CyResult ) CyPersistentRepository_Copy( CyPersistentRepositoryH aDest,
                                                            CyPersistentRepositoryH aSource );

// Methods
CY_UTILS_LIB_C_API( void )     CyPersistentRepository_GroupParametersInXML( CyPersistentRepositoryH aHandle,
                                                                            int                     aGroup );
CY_UTILS_LIB_C_API( int )      CyPersistentRepository_ParametersAreGroupedInXML( CyPersistentRepositoryH aHandle );
CY_UTILS_LIB_C_API( CyResult ) CyPersistentRepository_SaveToXML  ( CyPersistentRepositoryH aHandle,
                                                                   CyXMLDocumentH          aDocument );
CY_UTILS_LIB_C_API( CyResult ) CyPersistentRepository_LoadFromXML( CyPersistentRepositoryH aHandle,
                                                                   CyXMLDocumentH          aDocument );

#endif  // __CY_PERSISTENT_REPOSITORY_H__

