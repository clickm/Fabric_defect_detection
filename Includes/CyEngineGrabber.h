// *****************************************************************************
//
// $Id: CyEngineGrabber.h,v 1.7 2007/07/04 21:27:06 igors Exp $
//
// cy1h23b1
//
// *****************************************************************************
//
//     Copyright (c) 2004, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyEngineGrabber.h
//
// *****************************************************************************

#ifndef _CY_ENGINE_GRABBER_H_
#define _CY_ENGINE_GRABBER_H_

// Headers
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include "CyResultEvent.h"

// ===== CyEngineLib =====
#include "CyEngineLib.h"
#include "CyEngine.h"
#include "CyEngineExtension.h"


// Class
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
struct CyEngineGrabberInternal;
class CyEngineGrabber : public CyEngineExtension
{
// Construction / Destruction
public:
    CY_ENGINE_LIB_API CyEngineGrabber();
    CY_ENGINE_LIB_API virtual ~CyEngineGrabber();

// ===== Accessors =====
public:
    // Indicates if if object construction was successful or not
    CY_ENGINE_LIB_API virtual bool IsValid() const;

// ===== Methods =====
public:
    // Sets the size of each image that will be sent to the client
    //      aSizeX: width, in pixels
    //      aSizeY: Height, in pixels
    //      aDepth: number of BYTES per pixel
    CY_ENGINE_LIB_API virtual CyResult SetImageSize( unsigned long aSizeX,
                                                     unsigned long aSizeY,
                                                     unsigned long aDepth );

    // Connect the grabber to its underlying engine
    CY_ENGINE_LIB_API virtual CyResult Connect( CyEngine& aEngine );
    CY_ENGINE_LIB_API virtual CyResult Connect( CyEngine* aEngine ); // for backward compatibility

    // Clears the list of triggers from the client.  This means that the client will not
    // receive its expected images
    CY_ENGINE_LIB_API virtual void ClearTrigger();

    // Indicates if the trigger is armed or not (continuously or single shot)
    CY_ENGINE_LIB_API /*virtual*/ bool IsTriggerArmed() const;

    // Sends an image to the client
    //      aBuffer      : The image data to send
    //      aTrigTimeout : The maximum time (in ms) that the engine will wait for a trig from the client to send the image
    //      aEvent       : Event that will be signaled when the engine as send the image or an error or timeout occured
    //      aSharedMemory: Shared memory object to use to send the image.
    //      aConcurrent  : Indicates if the buffer and shared memory is filled concurrently as sending.  The sender will
    //                     send the data only as it becomes available
    CY_ENGINE_LIB_API virtual CyResult SendData( const void          * aBuffer,
                                                 unsigned long         aTrigTimeout,
                                                 CyResultEvent       * aEvent,
                                                 CyEngineSharedMemory* aSharedMemory = 0,
                                                 bool                  aConcurrent   = false );

// ===== Event Handlers =====
protected:
    CY_ENGINE_LIB_API virtual void OnModuleReset();
    CY_ENGINE_LIB_API virtual void OnUnknownAction( const unsigned char* aData,
                                                    unsigned long        aDataSize,
                                                    unsigned long        aSrcAddr,
                                                    unsigned short       aSrcPort );

private:
    // Members
    struct CyEngineGrabberInternal* mInternal;

    // Disabled
    CyEngineGrabber( const CyEngineGrabber & );
    const CyEngineGrabber & operator = ( const CyEngineGrabber & );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyEngineGrabber Handle
typedef void* CyEngineGrabberH;

// Constructor
// Destructor: use CyEngineExtenion_Dstroy
CY_ENGINE_LIB_C_API( CyEngineGrabberH ) CyEngineGrabber_Init();


// Sets the size of each image that will be sent to the client
CY_ENGINE_LIB_C_API( CyResult ) CyEngineGrabber_SetImageSize( CyEngineGrabberH aHandle,
                                                              unsigned long    aSizeX,
                                                              unsigned long    aSizeY,
                                                              unsigned long    aDepth );

// Connect the grabber to its underlying engine
CY_ENGINE_LIB_C_API( CyResult ) CyEngineGrabber_Connect( CyEngineGrabberH aHandle,
                                                      CyEngineH        aEngine );

// Clears the list of triggers from the client.
CY_ENGINE_LIB_C_API( void ) CyEngineGrabber_ClearTrigger( CyEngineGrabberH aHandle );

// Indicates if the trigger is armed or not (continuously or single shot)
CY_ENGINE_LIB_C_API( int ) CyEngineGrabber_IsTriggerArmed( CyEngineGrabberH aHandle );

// Sends an image to the client
CY_ENGINE_LIB_C_API( CyResult ) CyEngineGrabber_SendData( CyEngineGrabberH      aHandle,
                                                          const void*           aBuffer,
                                                          unsigned long         aTrigTimeout,
                                                          CyResultEventH        aEvent,
                                                          CyEngineSharedMemoryH aSharedMemory,
                                                          int                   aConcurrent  );

#endif // _CY_ENGINE_GRABBER_H_
