# Microsoft Developer Studio Project File - Name="DcDraw" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=DcDraw - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "DcDraw.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "DcDraw.mak" CFG="DcDraw - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "DcDraw - Win32 Release" ("Win32 (x86) Static Library" 用)
!MESSAGE "DcDraw - Win32 Debug" ("Win32 (x86) Static Library" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DcDraw - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../" /I "../../../OuLib" /I "../../OuLib" /D "_LIB" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "LOGMSG_MILLISEC" /D "_AFXDLL" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "DcDraw - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "../../OuLib" /I "../" /D "_LIB" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "LOGMSG_MILLISEC" /D "_AFXDLL" /YX /FD /GZ /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "DcDraw - Win32 Release"
# Name "DcDraw - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CaDcdTargetClip.cpp
# End Source File
# Begin Source File

SOURCE=.\CaDcdTargetItemPosition.cpp
# End Source File
# Begin Source File

SOURCE=.\print\CaDcdTargetZoomDisplay.cpp
# End Source File
# Begin Source File

SOURCE=.\CconvDcDrawProp.cpp
# End Source File
# Begin Source File

SOURCE=.\CConverter_WinGdi.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcDeviceUnitSizeX.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcDeviceUnitSizeY.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdFillrect.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdFillRectangleText.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdFillRectangleTextV.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdFillRectangleTextV2.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdFreeLine.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdLine.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdRectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdTarget.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetCompatibleBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetGetDC.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetOnPaint.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetPrinter.cpp
# End Source File
# Begin Source File

SOURCE=.\CDcdText.cpp
# End Source File
# Begin Source File

SOURCE=.\CdDrawTextFormat.cpp
# End Source File
# Begin Source File

SOURCE=.\CdDrawTextFormat2.cpp
# End Source File
# Begin Source File

SOURCE=.\CGdiCache.cpp
# End Source File
# Begin Source File

SOURCE=.\CLineFunc.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CaDcdTargetClip.h
# End Source File
# Begin Source File

SOURCE=.\CaDcdTargetItemPosition.h
# End Source File
# Begin Source File

SOURCE=.\print\CaDcdTargetZoomDisplay.h
# End Source File
# Begin Source File

SOURCE=.\CconvDcDrawProp.h
# End Source File
# Begin Source File

SOURCE=.\CConverter_WinGdi.h
# End Source File
# Begin Source File

SOURCE=.\CdBrushProp.h
# End Source File
# Begin Source File

SOURCE=.\CDcDeviceUnitSizeX.h
# End Source File
# Begin Source File

SOURCE=.\CDcDeviceUnitSizeY.h
# End Source File
# Begin Source File

SOURCE=.\CDcdFillrect.h
# End Source File
# Begin Source File

SOURCE=.\CDcdFillRectangleText.h
# End Source File
# Begin Source File

SOURCE=.\CDcdFillRectangleTextV.h
# End Source File
# Begin Source File

SOURCE=.\CDcdFillRectangleTextV2.h
# End Source File
# Begin Source File

SOURCE=.\CDcdFreeLine.h
# End Source File
# Begin Source File

SOURCE=.\CDcdLine.h
# End Source File
# Begin Source File

SOURCE=.\CDcdRectangle.h
# End Source File
# Begin Source File

SOURCE=.\CDcdTarget.h
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetCompatibleBitmap.h
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetGetDC.h
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetOnPaint.h
# End Source File
# Begin Source File

SOURCE=.\CDcdTargetPrinter.h
# End Source File
# Begin Source File

SOURCE=.\CDcdText.h
# End Source File
# Begin Source File

SOURCE=.\CdColorProp.h
# End Source File
# Begin Source File

SOURCE=.\cddcdfreelineprop.h
# End Source File
# Begin Source File

SOURCE=.\CdDcdPosXy.h
# End Source File
# Begin Source File

SOURCE=.\CdDcdSizeXy.h
# End Source File
# Begin Source File

SOURCE=.\CdDcdZone.h
# End Source File
# Begin Source File

SOURCE=.\CdDcdZoneXy.h
# End Source File
# Begin Source File

SOURCE=.\CdDeviceUnitSize.h
# End Source File
# Begin Source File

SOURCE=.\CdDrawTextFormat.h
# End Source File
# Begin Source File

SOURCE=.\CdDrawTextFormat2.h
# End Source File
# Begin Source File

SOURCE=.\CdDrawTextProp.h
# End Source File
# Begin Source File

SOURCE=.\CdFontProp.h
# End Source File
# Begin Source File

SOURCE=.\CdPenProp.h
# End Source File
# Begin Source File

SOURCE=.\CGdiCache.h
# End Source File
# Begin Source File

SOURCE=.\CLineFunc.h
# End Source File
# Begin Source File

SOURCE=.\DcdType.h
# End Source File
# Begin Source File

SOURCE=.\IfDcDraw.h
# End Source File
# Begin Source File

SOURCE=.\IfDcdTarget.h
# End Source File
# End Group
# End Target
# End Project
