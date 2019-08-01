// *****************************************************************************
//
// $Id: CyCamLib.h,v 1.14 2007/11/13 13:42:04 sbouchard Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyCamLib.h
//
// Description..: 
//
// *****************************************************************************

#ifndef _CY_CAM_LIB_H_
#define _CY_CAM_LIB_H_

// Define the extern "C" depending if the compiler is C++ or C
#if defined( __cplusplus )
    #define CY_CAM_LIB_EXTERN_C extern "C"
#else // defined( __cplusplus )
    #define CY_CAM_LIB_EXTERN_C
#endif // defined( __cplusplus )
    
// Define import/export symbols for Windows
#if defined( WIN32 ) && !defined( CY_CAM_LIB_STATIC )
    //
    // Export symbols
    //
    #if defined( CY_CAM_LIB_EXPORTS )

        // Export symbol for C++ classes
        #define CY_CAM_LIB_API __declspec(dllexport)


        // Export symbol for C functions
        #define CY_CAM_LIB_C_API(aType) CY_CAM_LIB_EXTERN_C __declspec(dllexport) aType CY_CALLING_CONV


    //
    // Import symbols
    //
    #else // defined( CY_CAM_LIB_EXPORTS )

        // Import symbol for C++ classes
        #define CY_CAM_LIB_API __declspec(dllimport)

        // Import symbol for C functions
        #define CY_CAM_LIB_C_API(aType) CY_CAM_LIB_EXTERN_C __declspec(dllimport) aType CY_CALLING_CONV

        // Automatically link import libraries for Windows applications
        #if !defined( UNDER_CE ) && !defined( CY_NO_FORCE_LINK_LIB )

            // NOTE: The debug version of the libraries has been deprecated
            // you can enable CY_DEBUG_ENABLED only if the Cy*_Dbg.dll files
            // are available

            #if defined( _WIN64 ) && defined ( _DEBUG ) && defined ( CY_DEBUG_ENABLED )
                #pragma comment( lib, "CyCamLib64_Dbg.lib" )
            #elif defined( _WIN64 )
                #pragma comment( lib, "CyCamLib64.lib" )
            #elif defined( _DEBUG ) && defined ( CY_DEBUG_ENABLED )
                #pragma comment( lib, "CyCamLib_Dbg.lib" )
            #else
                #pragma comment( lib, "CyCamLib.lib" )
            #endif // defined( _DEBUG )

        #endif // !defined( UNDER_CE ) && !defined( CY_NO_FORCE_LINK_LIB )

    #endif // defined( CY_CAM_LIB_EXPORTS )

#else // defined( WIN32) && ! defined( CY_CAM_LIB_STATIC )

    // Define the import/export symbols as nothing for this configuration
    #define CY_CAM_LIB_API
    #define CY_CAM_LIB_C_API(aType) CY_CAM_LIB_EXTERN_C  aType

#endif // defined( WIN32) && ! defined( CY_CAM_LIB_STATIC ) 

#endif // _CY_CAM_LIB_H_
