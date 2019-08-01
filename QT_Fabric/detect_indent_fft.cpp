#include "HalconCpp.h"
#include "HDevThread.h"
#include "detect_indent_fft.h"
using namespace HalconCpp;

void dev_update_off ()
{

  //This procedure sets different update settings to 'off'.
  //This is useful to get the best performance and reduce overhead.
  //
  // dev_update_pc(...); only in hdevelop
  // dev_update_var(...); only in hdevelop
  // dev_update_window(...); only in hdevelop
  return;
}

// Chapter: Graphics / Text
// Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen.
void disp_continue_message (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_ContinueMessage, hv_Row, hv_Column;
  HTuple  hv_Width, hv_Height, hv_Ascent, hv_Descent, hv_TextWidth;
  HTuple  hv_TextHeight;

  //This procedure displays 'Press Run (F5) to continue' in the
  //lower right corner of the screen.
  //It uses the procedure disp_message.
  //
  //Input parameters:
  //WindowHandle: The window, where the text shall be displayed
  //Color: defines the text color.
  //   If set to '' or 'auto', the currently set color is used.
  //Box: If set to 'true', the text is displayed in a box.
  //
  hv_ContinueMessage = "Press Run (F5) to continue";
  GetWindowExtents(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Width, &hv_Height);
  GetStringExtents(hv_WindowHandle, (" "+hv_ContinueMessage)+" ", &hv_Ascent, &hv_Descent,
      &hv_TextWidth, &hv_TextHeight);
  disp_message(hv_WindowHandle, hv_ContinueMessage, "window", (hv_Height-hv_TextHeight)-12,
      (hv_Width-hv_TextWidth)-12, hv_Color, hv_Box);
  return;
}

// Chapter: Graphics / Text
// Short Description: This procedure writes a text message.
void disp_message (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
    HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_M, hv_N, hv_Red, hv_Green, hv_Blue;
  HTuple  hv_RowI1Part, hv_ColumnI1Part, hv_RowI2Part, hv_ColumnI2Part;
  HTuple  hv_RowIWin, hv_ColumnIWin, hv_WidthWin, hv_HeightWin;
  HTuple  hv_I, hv_RowI, hv_ColumnI, hv_StringI, hv_MaxAscent;
  HTuple  hv_MaxDescent, hv_MaxWidth, hv_MaxHeight, hv_R1;
  HTuple  hv_C1, hv_FactorRowI, hv_FactorColumnI, hv_UseShadow;
  HTuple  hv_ShadowColor, hv_Exception, hv_Width, hv_Index;
  HTuple  hv_Ascent, hv_Descent, hv_W, hv_H, hv_FrameHeight;
  HTuple  hv_FrameWidth, hv_R2, hv_C2, hv_DrawMode, hv_CurrentColor;

  //This procedure displays text in a graphics window.
  //
  //Input parameters:
  //WindowHandle: The WindowHandle of the graphics window, where
  //   the message should be displayed
  //String: A tuple of strings containing the text message to be displayed
  //CoordSystem: If set to 'window', the text position is given
  //   with respect to the window coordinate system.
  //   If set to 'image', image coordinates are used.
  //   (This may be useful in zoomed images.)
  //Row: The row coordinate of the desired text position
  //   If set to -1, a default value of 12 is used.
  //   A tuple of values is allowed to display text at different
  //   positions.
  //Column: The column coordinate of the desired text position
  //   If set to -1, a default value of 12 is used.
  //   A tuple of values is allowed to display text at different
  //   positions.
  //Color: defines the color of the text as string.
  //   If set to [], '' or 'auto' the currently set color is used.
  //   If a tuple of strings is passed, the colors are used cyclically...
  //   - if |Row| == |Column| == 1: for each new textline
  //   = else for each text position.
  //Box: If Box[0] is set to 'true', the text is written within an orange box.
  //     If set to' false', no box is displayed.
  //     If set to a color string (e.g. 'white', '#FF00CC', etc.),
  //       the text is written in a box of that color.
  //     An optional second value for Box (Box[1]) controls if a shadow is displayed:
  //       'true' -> display a shadow in a default color
  //       'false' -> display no shadow
  //       otherwise -> use given string as color string for the shadow color
  //
  //It is possible to display multiple text strings in a single call.
  //In this case, some restrictions apply:
  //- Multiple text positions can be defined by specifying a tuple
  //  with multiple Row and/or Column coordinates, i.e.:
  //  - |Row| == n, |Column| == n
  //  - |Row| == n, |Column| == 1
  //  - |Row| == 1, |Column| == n
  //- If |Row| == |Column| == 1,
  //  each element of String is display in a new textline.
  //- If multiple positions or specified, the number of Strings
  //  must match the number of positions, i.e.:
  //  - Either |String| == n (each string is displayed at the
  //                          corresponding position),
  //  - or     |String| == 1 (The string is displayed n times).
  //
  if (0 != (hv_Color==HTuple()))
  {
    hv_Color = "";
  }
  if (0 != (hv_Box==HTuple()))
  {
    hv_Box = "false";
  }
  //
  //
  //Check conditions
  //
  hv_M = (hv_Row.TupleLength())*(hv_Column.TupleLength());
  hv_N = hv_Row.TupleLength();
  if (0 != (HTuple(hv_M==0).TupleOr(hv_String==HTuple())))
  {
    return;
  }
  if (0 != (hv_M!=1))
  {
    //Multiple positions
    //
    //Expand single parameters
    if (0 != ((hv_Row.TupleLength())==1))
    {
      hv_N = hv_Column.TupleLength();
      TupleGenConst(hv_N, hv_Row, &hv_Row);
    }
    else if (0 != ((hv_Column.TupleLength())==1))
    {
      TupleGenConst(hv_N, hv_Column, &hv_Column);
    }
    else if (0 != ((hv_Column.TupleLength())!=(hv_Row.TupleLength())))
    {
      throw HalconCpp::HException("Number of elements in Row and Column does not match.");
    }
    if (0 != ((hv_String.TupleLength())==1))
    {
      TupleGenConst(hv_N, hv_String, &hv_String);
    }
    else if (0 != ((hv_String.TupleLength())!=hv_N))
    {
      throw HalconCpp::HException("Number of elements in Strings does not match number of positions.");
    }
    //
  }
  //
  //Prepare window
  GetRgb(hv_WindowHandle, &hv_Red, &hv_Green, &hv_Blue);
  GetPart(hv_WindowHandle, &hv_RowI1Part, &hv_ColumnI1Part, &hv_RowI2Part, &hv_ColumnI2Part);
  GetWindowExtents(hv_WindowHandle, &hv_RowIWin, &hv_ColumnIWin, &hv_WidthWin, &hv_HeightWin);
  SetPart(hv_WindowHandle, 0, 0, hv_HeightWin-1, hv_WidthWin-1);
  //
  //Loop over all positions
  {
  HTuple end_val89 = hv_N-1;
  HTuple step_val89 = 1;
  for (hv_I=0; hv_I.Continue(end_val89, step_val89); hv_I += step_val89)
  {
    hv_RowI = HTuple(hv_Row[hv_I]);
    hv_ColumnI = HTuple(hv_Column[hv_I]);
    //Allow multiple strings for a single position.
    if (0 != (hv_N==1))
    {
      hv_StringI = hv_String;
    }
    else
    {
      //In case of multiple positions, only single strings
      //are allowed per position.
      //For line breaks, use \n in this case.
      hv_StringI = HTuple(hv_String[hv_I]);
    }
    //Default settings
    //-1 is mapped to 12.
    if (0 != (hv_RowI==-1))
    {
      hv_RowI = 12;
    }
    if (0 != (hv_ColumnI==-1))
    {
      hv_ColumnI = 12;
    }
    //
    //Split string into one string per line.
    hv_StringI = ((""+hv_StringI)+"").TupleSplit("\n");
    //
    //Estimate extentions of text depending on font size.
    GetFontExtents(hv_WindowHandle, &hv_MaxAscent, &hv_MaxDescent, &hv_MaxWidth,
        &hv_MaxHeight);
    if (0 != (hv_CoordSystem==HTuple("window")))
    {
      hv_R1 = hv_RowI;
      hv_C1 = hv_ColumnI;
    }
    else
    {
      //Transform image to window coordinates.
      hv_FactorRowI = (1.*hv_HeightWin)/((hv_RowI2Part-hv_RowI1Part)+1);
      hv_FactorColumnI = (1.*hv_WidthWin)/((hv_ColumnI2Part-hv_ColumnI1Part)+1);
      hv_R1 = (((hv_RowI-hv_RowI1Part)+0.5)*hv_FactorRowI)-0.5;
      hv_C1 = (((hv_ColumnI-hv_ColumnI1Part)+0.5)*hv_FactorColumnI)-0.5;
    }
    //Workaround for special case handling of set_tposition
    if (0 != (HTuple((hv_R1.TupleRound())==-1).TupleAnd((hv_C1.TupleRound())==-1)))
    {
      hv_R1 = 0;
      hv_C1 = 0;
    }
    //
    //Display text box depending on text size.
    hv_UseShadow = 1;
    hv_ShadowColor = "gray";
    if (0 != (HTuple(hv_Box[0])==HTuple("true")))
    {
      hv_Box[0] = "#fce9d4";
      hv_ShadowColor = "#f28d26";
    }
    if (0 != ((hv_Box.TupleLength())>1))
    {
      if (0 != (HTuple(hv_Box[1])==HTuple("true")))
      {
        //Use default ShadowColor set above
      }
      else if (0 != (HTuple(hv_Box[1])==HTuple("false")))
      {
        hv_UseShadow = 0;
      }
      else
      {
        hv_ShadowColor = ((const HTuple&)hv_Box)[1];
        //Valid color?
        try
        {
          SetColor(hv_WindowHandle, HTuple(hv_Box[1]));
        }
        // catch (Exception)
        catch (HalconCpp::HException &HDevExpDefaultException)
        {
          HDevExpDefaultException.ToHTuple(&hv_Exception);
          hv_Exception = HTuple("Wrong value of control parameter Box[1] (must be a 'true', 'false', or a valid color string)");
          throw HalconCpp::HException(hv_Exception);
        }
      }
    }
    if (0 != (HTuple(hv_Box[0])!=HTuple("false")))
    {
      //Valid color?
      try
      {
        SetColor(hv_WindowHandle, HTuple(hv_Box[0]));
      }
      // catch (Exception)
      catch (HalconCpp::HException &HDevExpDefaultException)
      {
        HDevExpDefaultException.ToHTuple(&hv_Exception);
        hv_Exception = HTuple("Wrong value of control parameter Box[0] (must be a 'true', 'false', or a valid color string)");
        throw HalconCpp::HException(hv_Exception);
      }
      //Calculate box extents
      hv_StringI = (" "+hv_StringI)+" ";
      hv_Width = HTuple();
      {
      HTuple end_val165 = (hv_StringI.TupleLength())-1;
      HTuple step_val165 = 1;
      for (hv_Index=0; hv_Index.Continue(end_val165, step_val165); hv_Index += step_val165)
      {
        GetStringExtents(hv_WindowHandle, HTuple(hv_StringI[hv_Index]), &hv_Ascent,
            &hv_Descent, &hv_W, &hv_H);
        hv_Width = hv_Width.TupleConcat(hv_W);
      }
      }
      hv_FrameHeight = hv_MaxHeight*(hv_StringI.TupleLength());
      hv_FrameWidth = (HTuple(0).TupleConcat(hv_Width)).TupleMax();
      hv_R2 = hv_R1+hv_FrameHeight;
      hv_C2 = hv_C1+hv_FrameWidth;
      //Display rectangles
      GetDraw(hv_WindowHandle, &hv_DrawMode);
      SetDraw(hv_WindowHandle, "fill");
      //Set shadow color
      SetColor(hv_WindowHandle, hv_ShadowColor);
      if (0 != hv_UseShadow)
      {
        DispRectangle1(hv_WindowHandle, hv_R1+1, hv_C1+1, hv_R2+1, hv_C2+1);
      }
      //Set box color
      SetColor(hv_WindowHandle, HTuple(hv_Box[0]));
      DispRectangle1(hv_WindowHandle, hv_R1, hv_C1, hv_R2, hv_C2);
      SetDraw(hv_WindowHandle, hv_DrawMode);
    }
    //Write text.
    {
    HTuple end_val187 = (hv_StringI.TupleLength())-1;
    HTuple step_val187 = 1;
    for (hv_Index=0; hv_Index.Continue(end_val187, step_val187); hv_Index += step_val187)
    {
      //Set color
      if (0 != (hv_N==1))
      {
        //Wiht a single text position, each text line
        //may get a different color.
        hv_CurrentColor = HTuple(hv_Color[hv_Index%(hv_Color.TupleLength())]);
      }
      else
      {
        //With multiple text positions, each position
        //gets a single color for all text lines.
        hv_CurrentColor = HTuple(hv_Color[hv_I%(hv_Color.TupleLength())]);
      }
      if (0 != (HTuple(hv_CurrentColor!=HTuple("")).TupleAnd(hv_CurrentColor!=HTuple("auto"))))
      {
        //Valid color?
        try
        {
          SetColor(hv_WindowHandle, hv_CurrentColor);
        }
        // catch (Exception)
        catch (HalconCpp::HException &HDevExpDefaultException)
        {
          HDevExpDefaultException.ToHTuple(&hv_Exception);
          hv_Exception = ((("Wrong value of control parameter Color["+(hv_Index%(hv_Color.TupleLength())))+"] == '")+hv_CurrentColor)+"' (must be a valid color string)";
          throw HalconCpp::HException(hv_Exception);
        }
      }
      else
      {
        SetRgb(hv_WindowHandle, hv_Red, hv_Green, hv_Blue);
      }
      //Finally display text
      hv_RowI = hv_R1+(hv_MaxHeight*hv_Index);
      SetTposition(hv_WindowHandle, hv_RowI, hv_C1);
      WriteString(hv_WindowHandle, HTuple(hv_StringI[hv_Index]));
    }
    }
  }
  }
  //Reset changed window settings
  SetRgb(hv_WindowHandle, hv_Red, hv_Green, hv_Blue);
  SetPart(hv_WindowHandle, hv_RowI1Part, hv_ColumnI1Part, hv_RowI2Part, hv_ColumnI2Part);
  return;
}

// Chapter: Graphics / Text
// Short Description: Set font independent of OS
void set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
    HTuple hv_Slant)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_OS, hv_BufferWindowHandle, hv_Ascent;
  HTuple  hv_Descent, hv_Width, hv_Height, hv_Scale, hv_Exception;
  HTuple  hv_SubFamily, hv_Fonts, hv_SystemFonts, hv_Guess;
  HTuple  hv_I, hv_Index, hv_AllowedFontSizes, hv_Distances;
  HTuple  hv_Indices, hv_FontSelRegexp, hv_FontsCourier;

  //This procedure sets the text font of the current window with
  //the specified attributes.
  //It is assumed that following fonts are installed on the system:
  //Windows: Courier New, Arial Times New Roman
  //Mac OS X: CourierNewPS, Arial, TimesNewRomanPS
  //Linux: courier, helvetica, times
  //Because fonts are displayed smaller on Linux than on Windows,
  //a scaling factor of 1.25 is used the get comparable results.
  //For Linux, only a limited number of font sizes is supported,
  //to get comparable results, it is recommended to use one of the
  //following sizes: 9, 11, 14, 16, 20, 27
  //(which will be mapped internally on Linux systems to 11, 14, 17, 20, 25, 34)
  //
  //Input parameters:
  //WindowHandle: The graphics window for which the font will be set
  //Size: The font size. If Size=-1, the default of 16 is used.
  //Bold: If set to 'true', a bold font is used
  //Slant: If set to 'true', a slanted font is used
  //
  GetSystem("operating_system", &hv_OS);
  // dev_get_preferences(...); only in hdevelop
  // dev_set_preferences(...); only in hdevelop
  if (0 != (HTuple(hv_Size==HTuple()).TupleOr(hv_Size==-1)))
  {
    hv_Size = 16;
  }
  if (0 != ((hv_OS.TupleSubstr(0,2))==HTuple("Win")))
  {
    //Set font on Windows systems
    try
    {
      //Check, if font scaling is switched on
      OpenWindow(0, 0, 256, 256, 0, "buffer", "", &hv_BufferWindowHandle);
      SetFont(hv_BufferWindowHandle, "-Consolas-16-*-0-*-*-1-");
      GetStringExtents(hv_BufferWindowHandle, "test_string", &hv_Ascent, &hv_Descent,
          &hv_Width, &hv_Height);
      //Expected width is 110
      hv_Scale = 110.0/hv_Width;
      hv_Size = (hv_Size*hv_Scale).TupleInt();
      CloseWindow(hv_BufferWindowHandle);
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      //throw (Exception)
    }
    if (0 != (HTuple(hv_Font==HTuple("Courier")).TupleOr(hv_Font==HTuple("courier"))))
    {
      hv_Font = "Courier New";
    }
    else if (0 != (hv_Font==HTuple("mono")))
    {
      hv_Font = "Consolas";
    }
    else if (0 != (hv_Font==HTuple("sans")))
    {
      hv_Font = "Arial";
    }
    else if (0 != (hv_Font==HTuple("serif")))
    {
      hv_Font = "Times New Roman";
    }
    if (0 != (hv_Bold==HTuple("true")))
    {
      hv_Bold = 1;
    }
    else if (0 != (hv_Bold==HTuple("false")))
    {
      hv_Bold = 0;
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Bold";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Slant==HTuple("true")))
    {
      hv_Slant = 1;
    }
    else if (0 != (hv_Slant==HTuple("false")))
    {
      hv_Slant = 0;
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Slant";
      throw HalconCpp::HException(hv_Exception);
    }
    try
    {
      SetFont(hv_WindowHandle, ((((((("-"+hv_Font)+"-")+hv_Size)+"-*-")+hv_Slant)+"-*-*-")+hv_Bold)+"-");
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      //throw (Exception)
    }
  }
  else if (0 != ((hv_OS.TupleSubstr(0,2))==HTuple("Dar")))
  {
    //Set font on Mac OS X systems. Since OS X does not have a strict naming
    //scheme for font attributes, we use tables to determine the correct font
    //name.
    hv_SubFamily = 0;
    if (0 != (hv_Slant==HTuple("true")))
    {
      hv_SubFamily = hv_SubFamily|1;
    }
    else if (0 != (hv_Slant!=HTuple("false")))
    {
      hv_Exception = "Wrong value of control parameter Slant";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Bold==HTuple("true")))
    {
      hv_SubFamily = hv_SubFamily|2;
    }
    else if (0 != (hv_Bold!=HTuple("false")))
    {
      hv_Exception = "Wrong value of control parameter Bold";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Font==HTuple("mono")))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "Menlo-Regular";
      hv_Fonts[1] = "Menlo-Italic";
      hv_Fonts[2] = "Menlo-Bold";
      hv_Fonts[3] = "Menlo-BoldItalic";
    }
    else if (0 != (HTuple(hv_Font==HTuple("Courier")).TupleOr(hv_Font==HTuple("courier"))))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "CourierNewPSMT";
      hv_Fonts[1] = "CourierNewPS-ItalicMT";
      hv_Fonts[2] = "CourierNewPS-BoldMT";
      hv_Fonts[3] = "CourierNewPS-BoldItalicMT";
    }
    else if (0 != (hv_Font==HTuple("sans")))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "ArialMT";
      hv_Fonts[1] = "Arial-ItalicMT";
      hv_Fonts[2] = "Arial-BoldMT";
      hv_Fonts[3] = "Arial-BoldItalicMT";
    }
    else if (0 != (hv_Font==HTuple("serif")))
    {
      hv_Fonts.Clear();
      hv_Fonts[0] = "TimesNewRomanPSMT";
      hv_Fonts[1] = "TimesNewRomanPS-ItalicMT";
      hv_Fonts[2] = "TimesNewRomanPS-BoldMT";
      hv_Fonts[3] = "TimesNewRomanPS-BoldItalicMT";
    }
    else
    {
      //Attempt to figure out which of the fonts installed on the system
      //the user could have meant.
      QueryFont(hv_WindowHandle, &hv_SystemFonts);
      hv_Fonts.Clear();
      hv_Fonts.Append(hv_Font);
      hv_Fonts.Append(hv_Font);
      hv_Fonts.Append(hv_Font);
      hv_Fonts.Append(hv_Font);
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font);
      hv_Guess.Append(hv_Font+"-Regular");
      hv_Guess.Append(hv_Font+"MT");
      {
      HTuple end_val100 = (hv_Guess.TupleLength())-1;
      HTuple step_val100 = 1;
      for (hv_I=0; hv_I.Continue(end_val100, step_val100); hv_I += step_val100)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[0] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
      //Guess name of slanted font
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font+"-Italic");
      hv_Guess.Append(hv_Font+"-ItalicMT");
      hv_Guess.Append(hv_Font+"-Oblique");
      {
      HTuple end_val109 = (hv_Guess.TupleLength())-1;
      HTuple step_val109 = 1;
      for (hv_I=0; hv_I.Continue(end_val109, step_val109); hv_I += step_val109)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[1] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
      //Guess name of bold font
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font+"-Bold");
      hv_Guess.Append(hv_Font+"-BoldMT");
      {
      HTuple end_val118 = (hv_Guess.TupleLength())-1;
      HTuple step_val118 = 1;
      for (hv_I=0; hv_I.Continue(end_val118, step_val118); hv_I += step_val118)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[2] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
      //Guess name of bold slanted font
      hv_Guess.Clear();
      hv_Guess.Append(hv_Font+"-BoldItalic");
      hv_Guess.Append(hv_Font+"-BoldItalicMT");
      hv_Guess.Append(hv_Font+"-BoldOblique");
      {
      HTuple end_val127 = (hv_Guess.TupleLength())-1;
      HTuple step_val127 = 1;
      for (hv_I=0; hv_I.Continue(end_val127, step_val127); hv_I += step_val127)
      {
        TupleFind(hv_SystemFonts, HTuple(hv_Guess[hv_I]), &hv_Index);
        if (0 != (hv_Index!=-1))
        {
          hv_Fonts[3] = HTuple(hv_Guess[hv_I]);
          break;
        }
      }
      }
    }
    hv_Font = HTuple(hv_Fonts[hv_SubFamily]);
    try
    {
      SetFont(hv_WindowHandle, (hv_Font+"-")+hv_Size);
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      //throw (Exception)
    }
  }
  else
  {
    //Set font for UNIX systems
    hv_Size = hv_Size*1.25;
    hv_AllowedFontSizes.Clear();
    hv_AllowedFontSizes[0] = 11;
    hv_AllowedFontSizes[1] = 14;
    hv_AllowedFontSizes[2] = 17;
    hv_AllowedFontSizes[3] = 20;
    hv_AllowedFontSizes[4] = 25;
    hv_AllowedFontSizes[5] = 34;
    if (0 != ((hv_AllowedFontSizes.TupleFind(hv_Size))==-1))
    {
      hv_Distances = (hv_AllowedFontSizes-hv_Size).TupleAbs();
      TupleSortIndex(hv_Distances, &hv_Indices);
      hv_Size = HTuple(hv_AllowedFontSizes[HTuple(hv_Indices[0])]);
    }
    if (0 != (HTuple(hv_Font==HTuple("mono")).TupleOr(hv_Font==HTuple("Courier"))))
    {
      hv_Font = "courier";
    }
    else if (0 != (hv_Font==HTuple("sans")))
    {
      hv_Font = "helvetica";
    }
    else if (0 != (hv_Font==HTuple("serif")))
    {
      hv_Font = "times";
    }
    if (0 != (hv_Bold==HTuple("true")))
    {
      hv_Bold = "bold";
    }
    else if (0 != (hv_Bold==HTuple("false")))
    {
      hv_Bold = "medium";
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Bold";
      throw HalconCpp::HException(hv_Exception);
    }
    if (0 != (hv_Slant==HTuple("true")))
    {
      if (0 != (hv_Font==HTuple("times")))
      {
        hv_Slant = "i";
      }
      else
      {
        hv_Slant = "o";
      }
    }
    else if (0 != (hv_Slant==HTuple("false")))
    {
      hv_Slant = "r";
    }
    else
    {
      hv_Exception = "Wrong value of control parameter Slant";
      throw HalconCpp::HException(hv_Exception);
    }
    try
    {
      SetFont(hv_WindowHandle, ((((((("-adobe-"+hv_Font)+"-")+hv_Bold)+"-")+hv_Slant)+"-normal-*-")+hv_Size)+"-*-*-*-*-*-*-*");
    }
    // catch (Exception)
    catch (HalconCpp::HException &HDevExpDefaultException)
    {
      HDevExpDefaultException.ToHTuple(&hv_Exception);
      if (0 != (HTuple((hv_OS.TupleSubstr(0,4))==HTuple("Linux")).TupleAnd(hv_Font==HTuple("courier"))))
      {
        QueryFont(hv_WindowHandle, &hv_Fonts);
        hv_FontSelRegexp = (("^-[^-]*-[^-]*[Cc]ourier[^-]*-"+hv_Bold)+"-")+hv_Slant;
        hv_FontsCourier = (hv_Fonts.TupleRegexpSelect(hv_FontSelRegexp)).TupleRegexpMatch(hv_FontSelRegexp);
        if (0 != ((hv_FontsCourier.TupleLength())==0))
        {
          hv_Exception = "Wrong font name";
          //throw (Exception)
        }
        else
        {
          try
          {
            SetFont(hv_WindowHandle, ((HTuple(hv_FontsCourier[0])+"-normal-*-")+hv_Size)+"-*-*-*-*-*-*-*");
          }
          // catch (Exception)
          catch (HalconCpp::HException &HDevExpDefaultException)
          {
            HDevExpDefaultException.ToHTuple(&hv_Exception);
            //throw (Exception)
          }
        }
      }
      //throw (Exception)
    }
  }
  // dev_set_preferences(...); only in hdevelop
  return;
}
