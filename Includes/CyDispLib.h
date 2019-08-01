// *****************************************************************************
//
// $Id: CyDispLib.h,v 1.12 2007/07/04 21:27:06 igors Exp $
//
// cy1h03b1
//
// *****************************************************************************
//
//     Copyright (c) 2002-2003, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyDispLib.h
//
// Description..: 
//
// *****************************************************************************

#ifndef _CY_DISP_LIB_H_
#define _CY_DISP_LIB_H_

// Define import/export symbols for Windows
#if defined( WIN32 ) && !defined( CY_DISP_LIB_STATIC )

    // Define the extern "C" depending if the compiler is C++ or C
    #if defined( __cplusplus )
        #define CY_DISP_LIB_EXTERN_C extern "C"
    #else // defined( __cplusplus )
        #define CY_DISP_LIB_EXTERN_C
    #endif // defined( __cplusplus )


    //
    // Export symbols
    //
    #if defined( CY_DISP_LIB_EXPORTS )

        // Export symbol for C++ classes
        #define CY_DISP_LIB_API __declspec(dllexport)


        // Export symbol for C functions
        #define CY_DISP_LIB_C_API(aType) CY_DISP_LIB_EXTERN_C __declspec(dllexport) aType CY_CALLING_CONV


    //
    // Import symbols
    //
    #else // defined( CY_DISP_LIB_EXPORTS )

        // Import symbol for C++ classes
        #define CY_DISP_LIB_API __declspec(dllimport)

        // Import symbol for C functions
        #define CY_DISP_LIB_C_API(aType) CY_DISP_LIB_EXTERN_C __declspec(dllimport) aType CY_CALLING_CONV

        // Automatically link import libraries for Windows applications
        #if !defined( UNDER_CE ) && !defined( CY_NO_FORCE_LINK_LIB )

            // NOTE: The debug version of the libraries has been deprecated
            // you can enable CY_DEBUG_ENABLED only if the Cy*_Dbg.dll files
            // are available

            #if defined( _WIN64 ) && defined ( _DEBUG ) && defined ( CY_DEBUG_ENABLED )
                #pragma comment( lib, "CyDispExLib64_Dbg.lib" )
            #elif defined( _WIN64 )
                #pragma comment( lib, "CyDispExLib64.lib" )
            #elif defined( _DEBUG ) && defined ( CY_DEBUG_ENABLED )
                #pragma comment( lib, "CyDispExLib_Dbg.lib" )
            #else
                #pragma comment( lib, "CyDispExLib.lib" )
            #endif // defined( _DEBUG )

        #endif // !defined( UNDER_CE ) && !defined( CY_NO_FORCE_LINK_LIB )

    #endif // defined( CY_DISP_LIB_EXPORTS )

#else // defined( WIN32) && ! defined( CY_DISP_LIB_STATIC )

    // Define the import/export symbols as nothing for this configuration
    #define CY_DISP_LIB_API
    #define CY_DISP_LIB_C_API(aType) aType

#endif // defined( WIN32) && ! defined( CY_DISP_LIB_STATIC )

#endif // _CY_DISP_LIB_H_
