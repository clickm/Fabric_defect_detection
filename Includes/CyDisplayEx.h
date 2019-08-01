// *****************************************************************************
//
//     Copyright (c) 2002-2005, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************
//
// File Name....: CyDisplayEx.h
//
// Description..: Display window class
//
// *****************************************************************************

#ifndef _CY_DISPLAY_EX_H_
#define _CY_DISPLAY_EX_H_

// Includes
/////////////////////////////////////////////////////////////////////////////

// ===== CyUtilsLib =====
#include <CyTypes.h>
#include <CyErrorInterface.h>
#include <CyThread.h>
#include <CyGate.h>

// ===== CyComLib =====
#include <CyPerfMonitor.h>
#include <CyRGBFilter.h>

// ===== CyCamLib =====
#include <CyImageBuffer.h>

// ===== This project =====
#include "CyDispLib.h"
#include "CyDisplayExConstants.h"

// ===== Misc =====
#ifdef WIN32
#include <windows.h> // for HWND
#endif // WIN32


// Forward Declaration
/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
class CyDisplayInfo;
class CDisplay;
class CSurface;
#endif // __cplusplus


/* ==========================================================================
@since	2002-09-03
========================================================================== */
#ifdef __cplusplus
struct CyDisplayExInternal;
class CY_DISP_LIB_API CyDisplayEx : public CyErrorInterface
{
// Types and constants
public:
    // Flags
    static const unsigned long FLAG_WAIT;
    static const unsigned long FLAG_KEEP_CONVERTER;
    static const unsigned long FLAG_INVERT_DEINTERLACING;
    static const unsigned long FLAG_BAYER_GRBG;
    static const unsigned long FLAG_BAYER_GBRG;
    static const unsigned long FLAG_BAYER_RGGB;
    static const unsigned long FLAG_BAYER_BGGR;
    static const unsigned long FLAG_BAYER_INTERPOLATE;

    // Constants
    static const unsigned short DEFAULT_POSITION;
    static const unsigned short DEFAULT_SIZE;

// Constructors / Destructor
public:
    // Constructor/Destructor
	                        CyDisplayEx();
	virtual                 ~CyDisplayEx();


// Methods
public:

    // Indicates if the display window is opened or closed
    virtual bool            IsOpened() const;
    virtual bool            IsUsingExternalWindow() const;

#ifdef WIN32
    // Returns the handle to the window in used.
    // Note that when using the internal window, CyDisplayEx owns
    // that window and has complete control and precedence over it.
    virtual HWND            GetWindowHandle() const;
#endif // WIN32

    // Indicates if the display is displaying the specified buffer
    virtual bool            IsDisplaying( unsigned short aIndex = 0 ) const;

    // Get display window
    virtual CyResult        GetSize     ( unsigned short& aSizeX,
                                          unsigned short& aSizeY ) const;
    virtual CyResult        GetPosition ( short&          aPosX,
                                          short&          aPosY ) const;


    // returns the number of sub-displays (see Open)
    virtual unsigned short  GetSubDisplayCount() const;

    // Returns information on a sub-display
    virtual CyResult        GetSubDisplay( unsigned short  aIndex,
                                           short&          aPosX,
                                           short&          aPosY,
                                           unsigned short& aSizeX,
                                           unsigned short& aSizeY ) const;

    // Returns the index of the sub-diplay based on the position
    // in the window
    virtual CyResult        GetSubDisplayIndex( unsigned short  aPosX,
                                                unsigned short  aPosY,
                                                unsigned short& aIndex ) const;

    // Change and get  the flag of a sub-display
    virtual CyResult        SetSubDisplayFlag( unsigned short aIndex,
                                               unsigned long  aFlags );
    virtual unsigned long   GetSubDisplayFlag( unsigned short aIndex ) const;

    // Force the display to focus on a single sub-display
    virtual CyResult        FocusOnSubDisplay( unsigned short aIndex,
                                               bool           aEnabled );
    virtual bool            IsFocusedOnSubDisplay() const;
    virtual unsigned short  GetFocusedSubDisplay() const;

    // Zoom operations on sub-display
    virtual CyResult        ZoomFit     ( unsigned short aIndex );
    virtual CyResult        ZoomFullRes ( unsigned short aIndex );
    virtual CyResult        ZoomIn      ( unsigned short aIndex );
    virtual CyResult        ZoomOut     ( unsigned short aIndex );
    virtual CyResult        ZoomRatio   ( unsigned short aIndex, double aRatio );
    virtual CyResult        GetZoomRatio( unsigned short aIndex, double& aRatio ) const;
    virtual CyResult        Move        ( unsigned short aIndex,
                                          int            aTransX,
                                          int            aTransY );
    virtual CyResult        Center      ( unsigned short aIndex );
    virtual CyResult        CenterLock  ( unsigned short aIndex,
                                          bool           aLocked );
    virtual CyResult        IsCenterLocked( unsigned short aIndex,
                                            bool&          aLocked ) const;

    // Background color
    virtual CyResult        SetBackgroundColor( unsigned char  aRed,
                                                unsigned char  aGreen,
                                                unsigned char  aBlue );
    virtual CyResult        GetBackgroundColor( unsigned char& aRed,
                                                unsigned char& aGreen,
                                                unsigned char& aBlue ) const;

    // BGR or RGB mode
    virtual CyResult        SetRGBMode( unsigned long aMode );
    virtual unsigned long   GetRGBMode() const;

    // Specifies the type of memory to use for the internal display
    // engine.  It can be video memory (default) or system memory.
    // Will be virtual in a future version.
    virtual CyResult        SetMemoryType( unsigned long aMemory );
    virtual unsigned long   GetMemoryType() const;
    
    // Returns the number of system display on which the display can
    // be opened
    static unsigned short CY_CALLING_CONV GetSystemDisplayCount();
    static CyResult       CY_CALLING_CONV SetCurrentSystemDisplay( unsigned short aIndex );
    static unsigned short CY_CALLING_CONV GetCurrentSystemDisplay();

    // Setting up the display.
    //
    // The display is created with with a number of sub-displays, which is
    // specified by the rows and columns.
    //
    // The user can assign a CyImageBuffer to each of the resulting sub-display.

    virtual     CyResult    Open( void*          aParent,
                                  unsigned short aPosX,
                                  unsigned short aPosY,
                                  unsigned short aSizeX,
                                  unsigned short aSizeY,
                                  unsigned short aColumns = 1,
                                  unsigned short aRows = 1,
                                  bool           aFullScreen = false );

    // Opens a display in an external windows
    virtual     CyResult    Open( void*          aWindows,  // HWND of the window that will contain the display
                                  unsigned short aColumns = 1,
                                  unsigned short aRows = 1,
                                  bool           aFullScreen = false );

    // close the display, will stop all current displaying
    virtual     CyResult    Close();

    // Change the position and size of the display window
	virtual		CyResult	Move    ( short          aPosX,
                                      short          aPosY );
	virtual		CyResult	Resize  ( unsigned short aSizeX,
                                      unsigned short aSizeY );

    // Title of the window
    virtual     CyResult    SetWindowTitle( const char* aTitle );
    virtual     CyResult    GetWindowTitle( char* aTitle, unsigned long aSize ) const;

    // Maximize, minimize, restore window    
#ifndef UNDER_CE
    virtual     bool        IsMaximized() const;
    virtual     CyResult    MaximizeWindow();

    virtual     bool        IsMinimized() const;
    virtual     CyResult    MinimizeWindow();

    virtual     CyResult    RestoreWindow();
#endif // UNDER_CE
    virtual     CyResult    FocusOnWindow();


	// ===== Displaying =====

    virtual CyResult        Display( const unsigned char * aBuffer,
                                     unsigned long         aBufferSize,
                                     unsigned short        aSizeX,
                                     unsigned short        aSizeY,
                                     CyPixelTypeID         aPixelType,
                                     unsigned short        aIndex = 0,
                                     unsigned long         aFlags = 0 );

	virtual CyResult        Display( CyImageBuffer& aBuffer,
                                     unsigned short aIndex = 0,
                                     unsigned long  aFlags = 0 );

	virtual CyResult        StartDisplaying( CyImageBuffer& aBuffer,
                                             unsigned short aIndex = 0,
                                             unsigned long  aFlags = 0 );

	virtual CyResult        StopDisplaying ( unsigned short aIndex );
    virtual CyResult        StopDisplaying ( );

    // Sets a RGB filter to a sub-display

    virtual CyResult        SetRGBFilter( unsigned short     aIndex,
                                          const CyRGBFilter& aFilter );
    virtual CyResult        RemoveRGBFilter( unsigned short aIndex );
    virtual bool            HasRGBFilter( unsigned short aIndex ) const;


    // ===== Performance and Information =====

    virtual CyPerfMonitor&  GetPerformanceMonitor( unsigned short aIndex = 0 ) const;
    virtual CyBufferQueue::ImageStatus
                            GetLastImageStatus( unsigned short aIndex = 0 ) const;
    virtual unsigned long   GetLastImageID( unsigned short aIndex = 0 ) const;
    virtual unsigned long   GetLastTimestamp( unsigned short aIndex = 0 ) const;


    // ===== Utilities =====

    // GUI Message Pump for console applications
    static void CY_CALLING_CONV PerformGUIMessagePump();
    static bool CY_CALLING_CONV PumpGUIMessage();

    // Returns a suggested number of columns and rows to use from a number of sub-display
    static unsigned short CY_CALLING_CONV GetColumnCount( unsigned short aSubDisplayCount );
    static unsigned short CY_CALLING_CONV GetRowCount( unsigned short aSubDisplayCount );

    // Returns the size of the current display
    static unsigned long CY_CALLING_CONV GetCurrentDisplayWidth();
    static unsigned long CY_CALLING_CONV GetCurrentDisplayHeight();


// Notifications from window
    virtual bool            OnCreate();
    virtual void            OnMove( unsigned int aPosX,
                                    unsigned int aPosY );
    virtual void            OnSize( unsigned int aSizeX,
                                    unsigned int aSizeY );
    virtual void            OnPaint();
    virtual void            OnMinMaxInfo( unsigned long& aMinX,
                                          unsigned long& aMinY,
                                          unsigned long& aMaxX,
                                          unsigned long& aMaxY );
    virtual void            OnClose();

// Internal methods
private:
    CyResult        InternalDisplay( const unsigned char * aBuffer,
                                     unsigned long         aBufferSize,
                                     unsigned short        aSizeX,
                                     unsigned short        aSizeY,
                                     unsigned short        aIndex,
                                     unsigned long         aFlags );

    CyResult UpdateSubDisplay( unsigned short aIndex, bool aGateLocked );


// Returns the display info for a sub-display
public: // For technical reasons, please do not use
    CyDisplayInfo&  GetSubDisplayInfo( unsigned short aIndex ) const;
    CyResult        RecreateDisplay();

// Graphic Engine methods
private:
    CyResult InitDisplay( unsigned short aSizeX,
                          unsigned short aSizeY,
                          bool aFullScreen );
    CyResult CloseDisplay();
    CyResult CreateBackBuffer( unsigned int aIndex );
    CyResult CloseBackBuffer( unsigned int aIndex );

    friend class CyWindow;
    friend class CyProperties;
    struct CyDisplayExInternal* mInternal;

// Disabled
private:
	      CyDisplayEx( const CyDisplayEx & );
	const CyDisplayEx &operator=( const CyDisplayEx & );
};
#endif // __cplusplus


// Standard C Wrapper
/////////////////////////////////////////////////////////////////////////////

// CyDisplayEx Handle
typedef void* CyDisplayExH;

// Construction / Destruction
CY_DISP_LIB_C_API( CyDisplayExH )   CyDisplayEx_Init();
CY_DISP_LIB_C_API( void  )          CyDisplayEx_Destroy( CyDisplayExH aHandle );

CY_DISP_LIB_C_API( int )            CyDisplayEx_IsOpened             ( CyDisplayExH    aHandle );
CY_DISP_LIB_C_API( int )            CyDisplayEx_IsUsingExternalWindow( CyDisplayExH    aHandle );
#ifdef WIN32
CY_DISP_LIB_C_API( HWND )           CyDisplayEx_GetWindowHandle( CyDisplayExH aHandle );
#endif
CY_DISP_LIB_C_API( int )            CyDisplayEx_IsDisplaying         ( CyDisplayExH    aHandle,
                                                                       unsigned short  aIndex );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_GetSize              ( CyDisplayExH    aHandle,
                                                                       unsigned short* aSizeX,
                                                                       unsigned short* aSizeY );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_GetPosition          ( CyDisplayExH    aHandle ,
                                                                       short*          aPosX,
                                                                       short*          aPosY );
CY_DISP_LIB_C_API( unsigned short ) CyDisplayEx_GetSubDisplayCount   ( CyDisplayExH    aHandle );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_GetSubDisplay        ( CyDisplayExH    aHandle,
                                                                       unsigned short  aIndex,
                                                                       short*          aPosX,
                                                                       short*          aPosY,
                                                                       unsigned short* aSizeX,
                                                                       unsigned short* aSizeY );

CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_GetSubDisplayIndex  ( CyDisplayExH    aHandle,
                                                                       unsigned short  aPosX,
                                                                       unsigned short  aPosY,
                                                                       unsigned short* aIndex );

CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_SetSubDisplayFlag   ( CyDisplayExH    aHandle,
                                                                       unsigned short  aIndex,
                                                                       unsigned long   aFlags );
CY_DISP_LIB_C_API( unsigned long )   CyDisplayEx_GetSubDisplayFlag   ( CyDisplayExH    aHandle,
                                                                       unsigned short  aIndex );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_FocusOnSubDisplay   ( CyDisplayExH    aHandle,
                                                                       unsigned short  aIndex,
                                                                       int             aEnabled );
CY_DISP_LIB_C_API( int )             CyDisplayEx_IsFocusedOnSubDisplay( CyDisplayExH aHandle );
CY_DISP_LIB_C_API( unsigned short )  CyDisplayEx_GetFocusedSubDisplay ( CyDisplayExH aHandle );

CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_ZoomFit             ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_ZoomFullRes         ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_ZoomIn              ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_ZoomOut             ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_ZoomRatio           ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex,
                                                                       double         aRatio );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_GetZoomRatio        ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex,
                                                                       double*        aRatio );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_Move                ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex,
                                                                       int            aTransX,
                                                                       int            aTransY );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_Center              ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_CenterLock          ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex,
                                                                       int           aLocked );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_IsCenterLocked      ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex,
                                                                       int*          aLocked );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_SetBackgroundColor  ( CyDisplayExH   aDisplay,
                                                                       unsigned char  aRed,
                                                                       unsigned char  aGreen,
                                                                       unsigned char  aBlue );
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_GetBackgroundColor  ( CyDisplayExH   aDisplay,
                                                                       unsigned char* aRed,
                                                                       unsigned char* aGreen,
                                                                       unsigned char* aBlue );

CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_SetRGBMode          ( CyDisplayExH  aDisplay,
                                                                       unsigned long aMode );
CY_DISP_LIB_C_API( unsigned long )   CyDisplayEx_GetRGBMode          ( CyDisplayExH  aDisplay );

CY_DISP_LIB_C_API( unsigned short )  CyDisplayEx_GetSystemDisplayCount();
CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_SetCurrentSystemDisplay( unsigned short aIndex );
CY_DISP_LIB_C_API( unsigned short )  CyDisplayEx_GetCurrentSystemDisplay();

CY_DISP_LIB_C_API( CyResult )        CyDisplayEx_Open               ( CyDisplayExH   aDisplay,
                                                                      void*          aParent,
                                                                      unsigned short aPosX,
                                                                      unsigned short aPosY,
                                                                      unsigned short aSizeX,
                                                                      unsigned short aSizeY,
                                                                      unsigned short aColumns ,
                                                                      unsigned short aRows ,
                                                                      int            aFullScreen );

CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_OpenEx              ( CyDisplayExH   aDisplay,
                                                                      void*          aWindows,
                                                                      unsigned short aColumns ,
                                                                      unsigned short aRows ,
                                                                      int            aFullScreen );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_Close               ( CyDisplayExH   aDisplay );

CY_DISP_LIB_C_API( CyResult )	     CyDisplayEx_MoveWindow          ( CyDisplayExH   aDisplay,
                                                                      short          aPosX,
                                                                      short          aPosY );
CY_DISP_LIB_C_API( CyResult )	     CyDisplayEx_ResizeWindow        ( CyDisplayExH   aDisplay,
                                                                      unsigned short aSizeX,
                                                                      unsigned short aSizeY );

CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_SetWindowTitle      ( CyDisplayExH   aDisplay,
                                                                      const char*    aTitle );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_GetWindowTitle      ( CyDisplayExH   aDisplay,
                                                                      char*          aTitle,
                                                                      unsigned long  aSize );

#ifndef UNDER_CE
CY_DISP_LIB_C_API( int )            CyDisplayEx_IsMaximized         ( CyDisplayExH   aDisplay );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_MaximizeWindow      ( CyDisplayExH   aDisplay );
CY_DISP_LIB_C_API( int )            CyDisplayEx_IsMinimized         ( CyDisplayExH   aDisplay );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_MinimizeWindow      ( CyDisplayExH   aDisplay );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_RestoreWindow       ( CyDisplayExH   aDisplay );
#endif // UNDER_CE
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_FocusOnWindow       ( CyDisplayExH   aDisplay );

CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_DisplayUser         ( CyDisplayExH   aDisplay,
                                                                      const unsigned char * aBuffer,
                                                                      unsigned long         aBufferSize,
                                                                      unsigned short        aSizeX,
                                                                      unsigned short        aSizeY,
                                                                      CyPixelTypeID         aPixelType,
                                                                      unsigned short        aIndex ,
                                                                      unsigned long         aFlags );

CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_Display            ( CyDisplayExH   aDisplay,
                                                                     CyImageBufferH aBuffer,
                                                                     unsigned short aIndex ,
                                                                     unsigned long  aFlags );

CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_StartDisplaying    ( CyDisplayExH   aDisplay,
                                                                     CyImageBufferH aBuffer,
                                                                     unsigned short aIndex ,
                                                                     unsigned long  aFlags );

CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_StopDisplaying     ( CyDisplayExH   aDisplay,
                                                                     unsigned short aIndex );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_StopDisplayingAll  ( CyDisplayExH   aDisplay );

CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_SetRGBFilter       ( CyDisplayExH   aDisplay,
                                                                   unsigned short     aIndex,
                                                                   CyRGBFilterH aFilter );
CY_DISP_LIB_C_API( CyResult )       CyDisplayEx_RemoveRGBFilter    ( CyDisplayExH   aDisplay,
                                                                     unsigned short aIndex );
CY_DISP_LIB_C_API( int )            CyDisplayEx_HasRGBFilter       ( CyDisplayExH   aDisplay,
                                                                     unsigned short aIndex );

CY_DISP_LIB_C_API( CyPerfMonitorH ) CyDisplayEx_GetPerformanceMonitor( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( unsigned long )  CyDisplayEx_GetLastImageStatus   ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( unsigned long )  CyDisplayEx_GetLastImageID       ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );
CY_DISP_LIB_C_API( unsigned long )  CyDisplayEx_GetLastTimestamp     ( CyDisplayExH   aDisplay,
                                                                       unsigned short aIndex );

CY_DISP_LIB_C_API( void )           CyDisplayEx_PerformGUIMessagePump();
CY_DISP_LIB_C_API( int )            CyDisplayEx_PumpGUIMessage       ();

CY_DISP_LIB_C_API( unsigned short ) CyDisplayEx_GetColumnCount ( unsigned short aSubDisplayCount );
CY_DISP_LIB_C_API( unsigned short ) CyDisplayEx_GetRowCount    ( unsigned short aSubDisplayCount );

CY_DISP_LIB_C_API( unsigned long )  CyDisplayEx_GetCurrentDisplayWidth();
CY_DISP_LIB_C_API( unsigned long )  CyDisplayEx_GetCurrentDisplayHeight();


CY_DISP_LIB_C_API( int )            CyDisplayEx_OnCreate       ( CyDisplayExH aDisplay );
CY_DISP_LIB_C_API( void  )          CyDisplayEx_OnMove         ( CyDisplayExH aDisplay,
                                                                 unsigned int aPosX,
                                                                 unsigned int aPosY );
CY_DISP_LIB_C_API( void )           CyDisplayEx_OnSize         ( CyDisplayExH aDisplay,
                                                                 unsigned int aSizeX,
                                                                 unsigned int aSizeY );
CY_DISP_LIB_C_API( void )           CyDisplayEx_OnPaint        ( CyDisplayExH aDisplay );
CY_DISP_LIB_C_API( void )           CyDisplayEx_OnMinMaxInfo   ( CyDisplayExH aDisplay,
                                                                 unsigned long* aMinX,
                                                                 unsigned long* aMinY,
                                                                 unsigned long* aMaxX,
                                                                 unsigned long* aMaxY );
CY_DISP_LIB_C_API( void )           CyDisplayEx_OnClose        ( CyDisplayExH aDisplay );

#endif // _CY_DISPLAY_EX_H_


