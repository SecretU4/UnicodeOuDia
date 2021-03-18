# Microsoft Developer Studio Project File - Name="DiagramEdit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DiagramEdit - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "DiagramEdit.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "DiagramEdit.mak" CFG="DiagramEdit - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "DiagramEdit - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "DiagramEdit - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DiagramEdit - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "." /I "..\..\libs\OuMfc" /I "..\..\libs\OuLib" /I "..\..\libs\DcDraw" /I "..\ConvDedFile\interface" /I "ConvFile" /I "ConvFile\03" /I "DedRosenFileData" /I "DedRosenFileData\EditCmd" /I "entDed" /I "entDgr" /I "JikokuhyouCsv" /I "Print" /I "ViewDiagram" /I "ViewEki" /I "ViewJikokuhyou" /I "ViewRessyasyubetsu" /I "ViewRosen" /I "ViewComment" /I "WinDia" /I "C:\Program Files\HTML Help Workshop\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 Version.lib htmlhelp.lib imm32.lib /nologo /subsystem:windows /machine:I386 /out:"..\bin\OuDia.exe" /libpath:"C:\Program Files\HTML Help Workshop\lib"

!ELSEIF  "$(CFG)" == "DiagramEdit - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "." /I "..\..\libs\OuMfc" /I "..\..\libs\OuLib" /I "..\..\libs\DcDraw" /I "..\ConvDedFile\interface" /I "ConvFile" /I "ConvFile\03" /I "DedRosenFileData" /I "DedRosenFileData\EditCmd" /I "entDed" /I "entDgr" /I "JikokuhyouCsv" /I "Print" /I "ViewDiagram" /I "ViewEki" /I "ViewJikokuhyou" /I "ViewRessyasyubetsu" /I "ViewRosen" /I "ViewComment" /I "WinDia" /I "C:\Program Files\HTML Help Workshop\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fr /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Version.lib htmlhelp.lib imm32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\bin\OuDia.exe" /pdbtype:sept /libpath:"C:\Program Files\HTML Help Workshop\lib"

!ENDIF 

# Begin Target

# Name "DiagramEdit - Win32 Release"
# Name "DiagramEdit - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ViewDiagram\CaDcdDiagram_PageSelector.cpp
# End Source File
# Begin Source File

SOURCE=.\Print\CaDcdGrid_PageSelector.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CaTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\Print\CconvCdPrintPageProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CconvDcdZoneScale.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CconvDcdZoneXyScale.cpp
# End Source File
# Begin Source File

SOURCE=.\WinDia\CconvWinDia.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDcdDiagram.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDcdDiagram2.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CDcdFreeLine_StyleSample.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewComment\CDedCommentDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewComment\CDedCommentView.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDedDiagramDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\cdeddiagramview.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\CDedRosenFileData_CEditCmdHolder.cpp
# End Source File
# Begin Source File

SOURCE=.\CDedStatusBar.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiagramEditDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiagramEditDoctmpl.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDlgDiagramViewProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgDiaList.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgDiaProp.cpp
# End Source File
# Begin Source File

SOURCE=.\WinDia\CDlgDiaSaveSelect.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgEkijikokuProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CDlgEkiProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgJikokuhyouViewProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\cdlgmodifyekijikokuoperation2.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgOuJikokuhyouCsvExport.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Print\CDlgPrintPageProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgRessyaProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CDlgRessyasyubetsuProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp_Diagram.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp_FontColor.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp_Rosen.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenView.cpp
# End Source File
# Begin Source File

SOURCE=.\Print\CdPrintPageProp.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CEkiDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CEkiView.cpp
# End Source File
# Begin Source File

SOURCE=.\entDgr\CentDedDgrDia.cpp
# End Source File
# Begin Source File

SOURCE=.\entDgr\CentDedDgrRessya.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CJikokuhyouDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CJikokuhyouView.cpp
# End Source File
# Begin Source File

SOURCE=.\CMainFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CRessyasyubetsuDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CRessyasyubetsuView.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CWndDcdGridEki.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyou.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyouState_Renzoku.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyouState_Ressyahensyu.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyouState_Ressyasentaku.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CWndDcdGridRessyasyubetsu.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CWndDiagram.cpp
# End Source File
# Begin Source File

SOURCE=.\DiagramEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\DiagramEdit.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ViewDiagram\CaDcdDiagram_PageSelector.h
# End Source File
# Begin Source File

SOURCE=.\Print\CaDcdGrid_PageSelector.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CaTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\Print\CconvCdPrintPageProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CconvDcdZoneScale.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CconvDcdZoneXyScale.h
# End Source File
# Begin Source File

SOURCE=.\WinDia\CconvWinDia.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDcdDiagram.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDcdDiagram2.h
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CDcdFreeLine_StyleSample.h
# End Source File
# Begin Source File

SOURCE=.\ViewComment\CDedCommentDoc.h
# End Source File
# Begin Source File

SOURCE=.\ViewComment\CDedCommentView.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDedDiagramDoc.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\cdeddiagramview.h
# End Source File
# Begin Source File

SOURCE=.\CDedRosenFileData_CEditCmdHolder.h
# End Source File
# Begin Source File

SOURCE=.\CDedStatusBar.h
# End Source File
# Begin Source File

SOURCE=.\CDiagramEditDoc.h
# End Source File
# Begin Source File

SOURCE=.\CDiagramEditDoctmpl.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CDlgDiagramViewProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgDiaList.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgDiaProp.h
# End Source File
# Begin Source File

SOURCE=.\WinDia\CDlgDiaSaveSelect.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgEkijikokuProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CDlgEkiProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgJikokuhyouViewProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\cdlgmodifyekijikokuoperation2.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgOuJikokuhyouCsvExport.h
# End Source File
# Begin Source File

SOURCE=.\Print\CDlgPrintPageProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CDlgRessyaProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CDlgRessyasyubetsuProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp_Diagram.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp_FontColor.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenFileProp_Rosen.h
# End Source File
# Begin Source File

SOURCE=.\ViewRosen\CDlgRosenView.h
# End Source File
# Begin Source File

SOURCE=.\Print\CdPrintPageProp.h
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CEkiDoc.h
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CEkiView.h
# End Source File
# Begin Source File

SOURCE=.\entDgr\CentDedDgrDia.h
# End Source File
# Begin Source File

SOURCE=.\entDgr\CentDedDgrEki.h
# End Source File
# Begin Source File

SOURCE=.\entDgr\CentDedDgrRessya.h
# End Source File
# Begin Source File

SOURCE=.\entDgr\CentDedDgrRessyasen.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CJikokuhyouDoc.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CJikokuhyouView.h
# End Source File
# Begin Source File

SOURCE=.\CMainFrame.h
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CRessyasyubetsuDoc.h
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CRessyasyubetsuView.h
# End Source File
# Begin Source File

SOURCE=.\ViewEki\CWndDcdGridEki.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyou.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyouState_Renzoku.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyouState_Ressyahensyu.h
# End Source File
# Begin Source File

SOURCE=.\ViewJikokuhyou\CWndDcdGridJikokuhyouState_Ressyasentaku.h
# End Source File
# Begin Source File

SOURCE=.\ViewRessyasyubetsu\CWndDcdGridRessyasyubetsu.h
# End Source File
# Begin Source File

SOURCE=.\ViewDiagram\CWndDiagram.h
# End Source File
# Begin Source File

SOURCE=.\DiagramEdit.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\CDiagramEditDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\DiagramEdit.ico
# End Source File
# Begin Source File

SOURCE=.\res\DiagramEdit.rc2
# End Source File
# Begin Source File

SOURCE=.\res\idr_comment.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_dgr.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_docv.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_eki.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_jikoku.ico
# End Source File
# Begin Source File

SOURCE=.\res\tb_diagram.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tree_ros.bmp
# End Source File
# End Group
# Begin Group "JikokuhyouCsv"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ConvJikokuhyouCsv\CconvJikokuhyouCsv.cpp
# End Source File
# Begin Source File

SOURCE=.\ConvJikokuhyouCsv\CconvJikokuhyouCsv.h
# End Source File
# End Group
# Begin Group "DedRosenFileData"

# PROP Default_Filter ""
# Begin Group "EditCmd"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Comment.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Comment.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_DedRosenFileDataProp.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_DedRosenFileDataProp.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Dia.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Dia.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_DiaProp.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_DiaProp.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Eki.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Eki.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Ressya.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Ressya.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Ressyasyubetsu.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Ressyasyubetsu.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_RessyasyubetsuSwap.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_RessyasyubetsuSwap.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Rosen.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_Rosen.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_RosenFileData.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\EditCmd\CDedRosenFileData_CEditCmd_RosenFileData.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\DedRosenFileData\CconvCdDedDispProp.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\CconvCdDedDispProp.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\CconvCDedRosenFileData.cpp
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\CconvCDedRosenFileData.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\CdDedDispProp.h
# End Source File
# Begin Source File

SOURCE=.\DedRosenFileData\CDedRosenFileData.h
# End Source File
# End Group
# Begin Group "ConvFile"

# PROP Default_Filter ""
# Begin Group "03"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ConvFile\03\CconvCdDedDispProp_03.cpp
# End Source File
# Begin Source File

SOURCE=.\ConvFile\03\CconvCdDedDispProp_03.h
# End Source File
# Begin Source File

SOURCE=.\ConvFile\03\CconvCDedRosenFileData_03.cpp
# End Source File
# Begin Source File

SOURCE=.\ConvFile\03\CconvCDedRosenFileData_03.h
# End Source File
# Begin Source File

SOURCE=.\ConvFile\03\CconvCentDed_03.cpp
# End Source File
# Begin Source File

SOURCE=.\ConvFile\03\CconvCentDed_03.h
# End Source File
# Begin Source File

SOURCE=.\ConvFile\03\CConvFile_Oudia03To05.cpp
# End Source File
# Begin Source File

SOURCE=.\ConvFile\03\CConvFile_Oudia03To05.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ConvFile\CaByteBuffer_string.h
# End Source File
# Begin Source File

SOURCE=.\ConvFile\CaByteBuffer_vector.h
# End Source File
# Begin Source File

SOURCE=.\ConvFile\CConvFileDll.cpp
# End Source File
# Begin Source File

SOURCE=.\ConvFile\CConvFileDll.h
# End Source File
# End Group
# Begin Group "interface"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ConvDedFile\interface\ConvFile2Dll.h
# End Source File
# Begin Source File

SOURCE=..\ConvDedFile\interface\IfByteBuffer.h
# End Source File
# Begin Source File

SOURCE=..\ConvDedFile\interface\IfConvFile.h
# End Source File
# End Group
# Begin Group "entDed"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\entDed\CconvCentDed.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CconvCentDed.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CdDedJikan.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CdDedJikan.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CdDedJikoku.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CdDedJikoku.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDed.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedDia.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedDia.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedDiaCont.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedDiaCont.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedEki.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedEkiCont.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedEkiCont.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedEkiJikoku.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessya.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessya.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessya_EkijikokuModifyOperation2.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessya_EkijikokuModifyOperation2.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessyaCont.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessyaCont.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessyasyubetsu.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessyasyubetsuCont.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRessyasyubetsuCont.h
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRosen.cpp
# End Source File
# Begin Source File

SOURCE=.\entDed\CentDedRosen.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\DiagramEdit.reg
# End Source File
# End Target
# End Project
