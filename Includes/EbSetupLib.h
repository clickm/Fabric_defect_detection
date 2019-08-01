// *****************************************************************************
//
// Eb1h05a1 - EbSetupLib
//
// *****************************************************************************
//
//   Copyright (c) 2006-2007, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: EbSetupLib.h
//
// *****************************************************************************	

#pragma once

#ifndef _EC_SETUP_LIB_H_
#define _EC_SETUP_LIB_H_

#ifdef EB_SETUP_LIB_EXPORTS

    // Define the export symbol
	#ifndef PT_LIB_STATIC
		#define EB_SETUP_LIB_API __declspec( dllexport )
	#else
		#define EB_SETUP_LIB_API
	#endif // PT_LIB_STATIC

#else // EB_SETUP_LIB_EXPORTS

    // Define the import symbol
	#ifndef PT_LIB_STATIC
		#define EB_SETUP_LIB_API __declspec( dllimport )
	#else
		#define EB_SETUP_LIB_API
	#endif // PT_LIB_STATIC

    // Define the suffix used for the static version of the library file
    #ifdef PT_LIB_STATIC
        #define PT_SUFFIX_STATIC "_s"
    #else // PT_LIB_STATIC
        #define PT_SUFFIX_STATIC
    #endif // PT_LIB_STATIC
        
    // Define the suffix used for the debug version of the library file
    #if defined( _PT_DEBUG_ ) && defined( PT_DEBUG_ENABLED )
        #define PT_SUFFIX_DEBUG "_Dbg"
    #else // defined( _PT_DEBUG_ ) && defined( PT_DEBUG_ENABLED )
        #define PT_SUFFIX_DEBUG
    #endif // defined( _PT_DEBUG_ ) && defined( PT_DEBUG_ENABLED )

    // Define the suffix used for the 64-bit version of the library file
    #ifdef _PT_64_
        #define PT_SUFFIX_64 "64"
    #else // _PT_64_
        #define PT_SUFFIX_64
    #endif // _PT_64_


    // Ask the compiler to link the required version of the library
    #pragma comment( lib, "EbSetupLib" PT_SUFFIX_STATIC PT_SUFFIX_64 PT_SUFFIX_DEBUG ".lib" )

    // Undefined the symbols used to link the required library file
    #undef PT_SUFFIX_STATIC
    #undef PT_SUFFIX_DEBUG
    #undef PT_SUFFIX_64

#endif // EB_SETUP_LIB_EXPORTS

#endif // _EC_SETUP_LIB_H_

