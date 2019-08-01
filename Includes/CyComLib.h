// *****************************************************************************
//
// $Id: CyComLib.h,v 1.16 2007/11/13 13:42:01 sbouchard Exp $
//
// cy1h02b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyComLib.h
//
// Description..: 
//
// *****************************************************************************

#ifndef _CY_COM_LIB_H_
#define _CY_COM_LIB_H_

// Define the extern "C" depending if the compiler is C++ or C
#if defined( __cplusplus )
	#define CY_COM_LIB_EXTERN_C extern "C"
#else // defined( __cplusplus )
	#define CY_COM_LIB_EXTERN_C
#endif // defined( __cplusplus )

#if defined( WIN32 ) && !defined( CY_COM_LIB_STATIC )
   	// Export symbols
   	#if defined( CY_COM_LIB_EXPORTS )
       	// Export symbol for C++ classes
       	#define CY_COM_LIB_API __declspec(dllexport)

        // Export symbol for C functions
        #define CY_COM_LIB_C_API(aType) CY_COM_LIB_EXTERN_C __declspec(dllexport) aType CY_CALLING_CONV
		    
   		// Import symbols
	#else // defined( CY_COM_LIB_EXPORTS )
        // Import symbol for C++ classe
        #define CY_COM_LIB_API __declspec(dllimport)

        // Import symbol for C functions
   	    #define CY_COM_LIB_C_API(aType) CY_COM_LIB_EXTERN_C __declspec(dllimport) aType CY_CALLING_CONV

        // Automatically link import libraries for Windows applications
   	    #if !defined( UNDER_CE ) && !defined( CY_NO_FORCE_LINK_LIB )

            // NOTE: The debug version of the libraries has been deprecated
   	        // you can enable CY_DEBUG_ENABLED only if the Cy*_Dbg.dll files
       	    // are available

            #if defined( _WIN64 ) && defined ( _DEBUG ) && defined ( CY_DEBUG_ENABLED )
   	            #pragma comment( lib, "CyComLib64_Dbg.lib" )
       	    #elif defined( _WIN64 )
       	        #pragma comment( lib, "CyComLib64.lib" )
       	    #elif defined( _DEBUG ) && defined ( CY_DEBUG_ENABLED )
       	        #pragma comment( lib, "CyComLib_Dbg.lib" )
       	    #else
       	        #pragma comment( lib, "CyComLib.lib" )
       	    #endif // defined( _DEBUG )

   	    #endif // !defined( UNDER_CE ) && !defined( CY_NO_FORCE_LINK_LIB )

	#endif // defined( CY_COM_LIB_EXPORTS )
#else
	#define CY_COM_LIB_API
	#define CY_COM_LIB_C_API(aType) CY_COM_LIB_EXTERN_C  aType
#endif /* WIN32 && !CY_COM_LIB_STATIC */

#endif // _CY_COM_LIB_H_
