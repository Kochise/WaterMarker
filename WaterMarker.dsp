# Microsoft Developer Studio Project File - Name="WaterMarker" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WaterMarker - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WaterMarker.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WaterMarker.mak" CFG="WaterMarker - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WaterMarker - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WaterMarker - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WaterMarker - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40c /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 Jpeg.lib png.lib Tiff.lib zlib.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "WaterMarker - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x40c /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 JpegD.lib pngD.lib TiffD.lib zlibD.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "WaterMarker - Win32 Release"
# Name "WaterMarker - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Source Helper"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\amsWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\CPathSplit.cpp
# End Source File
# Begin Source File

SOURCE=.\DiskObject.cpp
# End Source File
# Begin Source File

SOURCE=.\EditLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\GroupControl.cpp
# End Source File
# Begin Source File

SOURCE=.\SigUtils.cpp
# End Source File
# Begin Source File

SOURCE=.\SkinProgress.cpp
# End Source File
# End Group
# Begin Group "Source CxImage"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CxImage\CxImage\tif_xfile.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximabmp.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximadsp.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaenc.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaexif.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximage.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximagif.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximahist.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaico.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximainfo.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaint.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaj2k.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximajas.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximajbg.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximajpg.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximalpha.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximalyr.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximamng.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximapal.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximapcx.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximapng.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximasel.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximatga.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximath.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximatif.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximatran.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximawbmp.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximawmf.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximawnd.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\xmemfile.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\WaterMarker.cpp
# End Source File
# Begin Source File

SOURCE=.\WaterMarker.rc
# End Source File
# Begin Source File

SOURCE=.\WaterMarkerDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Header Helper"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\amsWnd.h
# End Source File
# Begin Source File

SOURCE=.\CPathSplit.h
# End Source File
# Begin Source File

SOURCE=.\DiskObject.h
# End Source File
# Begin Source File

SOURCE=.\EditLabel.h
# End Source File
# Begin Source File

SOURCE=.\GroupControl.h
# End Source File
# Begin Source File

SOURCE=.\SigUtils.h
# End Source File
# Begin Source File

SOURCE=.\SkinProgress.h
# End Source File
# End Group
# Begin Group "Header CxImage"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CxImage\CxImage\xfile.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximabmp.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximacfg.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximadef.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximage.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximagif.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaico.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaiter.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximaj2k.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximajas.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximajbg.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximajpg.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximamng.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximapcx.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximapng.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximatga.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximath.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximatif.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximawbmp.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\ximawmf.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\xiofile.h
# End Source File
# Begin Source File

SOURCE=.\CxImage\CxImage\xmemfile.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\WaterMarker.h
# End Source File
# Begin Source File

SOURCE=.\WaterMarkerDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\WaterMarker.ico
# End Source File
# Begin Source File

SOURCE=.\res\WaterMarker.rc2
# End Source File
# Begin Source File

SOURCE=.\res\xptheme.bin
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
