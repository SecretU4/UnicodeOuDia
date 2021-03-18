/*
	OuDia - Win32 Application Software to draw a "Train Service Planning
 Diagram" based on a "Train Timetable".

Copyright (C) 2006-2017 take-okm

This program is free software; you can redistribute it and/or modify it 
under the terms of the GNU General Public License as published by the Free 
Software Foundation; either version 3 of the License, or (at your option) 
any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT 
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
more details. 

You should have received a copy of the GNU General Public License along with
 this program. If not, see <http://www.gnu.org/licenses/>.

  In addition, as a special exception, take-okm
  gives permission to link the code of this program with
  the "MFC(Microsoft Foundation Class library) Version 9.0" 
  (or with modified versions of "MFC Version 9.0" that use the same license as 
  "MFC Version 9.0" ), and distribute linked combinations including
  the two.  You must obey the GNU General Public License in all
  respects for all of the code used other than  "MFC".  If you modify
  this file, you may extend this exception to your version of the
  file, but you are not obligated to do so.  If you do not wish to
  do so, delete this exception statement from your version.


(訳: 

	OuDia - 列車時刻表をもとに、ダイヤグラムを描画するWin32アプリケーシ
ョン。

Copyright (C) 2006-2017 take-okm 

このプログラムはフリーソフトウェアです。あなたはこれを、フリーソフトウェア財
団によって発行されたGNU 一般公衆利用許諾書(バージョン3か、それ以降のバージョ
ンのうちどれか)が定める条件の下で再頒布または改変 することができます。

このプログラムは有用であることを願って頒布されますが、*全くの無保証 *です。
商業可能性の保証や特定目的への適合性は、言外に示されたものも 含め、全く存在
しません。詳しくはGNU 一般公衆利用許諾書をご覧ください。

あなたはこのプログラムと共に、GNU 一般公衆利用許諾書のコピーを一部 受け取っ
ているはずです。もし受け取っていなければ、<http://www.gnu.org/licenses/> を
ご覧ください。

)

  加えて、特別な例外として、take-okm はこのプログラムのコードを 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  あるいは "MFC Version 9.0" と同じライセンスが適用された
  "MFC Version 9.0" の改変されたバージョン)とリンクし、
  リンクされた両者を含む結合著作物を頒布する許可を与えます。
  あなたは "MFC" 以外で使われているすべて
  のコードに関しては全面的にGNU一般公衆利用許諾契約書に従わなければ
  なりません。あなたがこのファイルを改変したならば、あなたはこの例外
  をあなたのバージョンのファイルに引き続き設けることもできますが、そ
  うする義務はありません。もし例外を設けたくなければ、この例外条項を
  あなたのバージョンからは削除してください。)
*/
//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by DiagramEdit.rc
//
#define IDD_OUJIKOKUHYOUCSV_EXPORT      102
#define IDR_MAINFRAME                   128
#define IDR_DIATYPE                     129
#define IDD_ROSEN_VIEW                  130
#define IDR_DOCVIEW_Eki                 130
#define IDB_TREE_ROSEN                  131
#define IDR_DOCVIEW_Ressyasyubetsu      131
#define IDD_RosenFileProp_Rosen         132
#define IDR_DOCVIEW_Jikokuhyou          132
#define IDD_RosenFileProp_FontColor     133
#define IDR_DOCVIEW_Diagram             133
#define IDD_RosenFileProp               134
#define IDS_WinDIAFilter                134
#define IDD_RosenFileProp_Diagram       135
#define IDR_DOCVIEW_Comment             135
#define IDD_EkiProp                     136
#define IDS_CSVFilter                   136
#define IDD_RessyasyubetsuProp          141
#define IDD_DiaList                     142
#define IDD_DiaProp                     143
#define IDD_RessyaProp                  145
#define IDD_EkijikokuProp               146
#define IDD_JikokuhyouViewProp          148
#define IDD_PrintPageProp               149
#define IDD_DiagramViewProp             152
#define IDD_DiaSaveSelect               153
#define IDD_ModifyEkijikokuOperation2   157
#define IDD_AboutBoxGpl                 158
#define IDD_FILE_ROSEN_CREATE_SUB_ROSEN 161
#define IDD_RosenfileInsert             162
#define IDD_PROGRESS                    163
#define IDR_MENU_EKIVIEW_CONTEXT        164
#define IDR_MENU_RESSYASYUBETSUVIEW_CONTEXT 165
#define IDR_MENU_JIKOKUHYOUVIEW_CONTEXT 166
#define IDR_MENU_DIAGRAMVIEW_CONTEXT    167
#define IDR_MENU_ROSENVIEW_CONTEXT      168
#define IDS_WORD_EKI                    600
#define IDS_WORD_RESSYASYUBETSU         601
#define IDS_WORD_DIA                    602
#define IDS_WORD_KUDARIJIKOKUHYOU       603
#define IDS_WORD_NOBORIJIKOKUHYOU       604
#define IDS_WORD_DIAGRAM                605
#define IDS_WORD_ROSEN                  606
#define IDS_WORD_COMMENT                607
#define IDS_WORD_Jikokukeisiki_Hatsu    610
#define IDS_WORD_Jikokukeisiki_KudariChaku 611
#define IDS_WORD_Jikokukeisiki_NoboriChaku 612
#define IDS_WORD_Jikokukeisiki_Hatsuchaku 613
#define IDS_WORD_Ekikibo_Ippan          614
#define IDS_WORD_Ekikibo_Syuyou         615
#define IDS_WORD_Jikokukeisiki          616
#define IDS_WORD_Ekikibo                617
#define IDS_WORD_Ekimei                 618
#define IDS_WORD_Ressyasyubetsumei      630
#define IDS_WORD_Ryakusyou              631
#define IDS_WORD_Senstyle               632
#define IDS_WORD_Ressyamei              640
#define IDS_WORD_Bikou                  641
#define IDS_WORD_Ressyabangou           642
#define IDS_WORD_Chaku                  650
#define IDS_WORD_Hatsu                  651
#define IDS_WORD_GOUSUU2                652
#define IDS_WORD_Kudari                 653
#define IDS_WORD_Nobori                 654
#define IDS_WORD_Sono                   655
#define IDS_WORD_Gousuu                 656
#define IDS_WORD_JIKOKUHYOU_TSUUKA      657
#define IDS_WORD_JIKOKUHYOU_KEIYUNASI   658
#define IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN 659
#define IDS_WORD_JIKOKUHYOU_UNKOUNASI_SYUYOU 660
#define IDS_WORD_JIKOKUHYOU_TEISYA      661
#define IDS_ERR_ERRORCODE               700
#define IDS_ERR_FILENOTFOUND            701
#define IDS_ERR_FILEREAD                702
#define IDS_ERR_FILEFORMAT              703
#define IDS_ERR_FILECREATE              704
#define IDS_ERR_FILEWRITE               705
#define IDS_ERR_FileTypeAppComment      706
#define IDS_ERR_FILECONVERT_FAILED      707
#define IDS_ERR_FILEFORMAT_ERRORCODE    708
#define IDS_ERR_RessyasyubetsuTooMany   711
#define IDS_ERR_NoDia                   712
#define IDS_ERR_RyakusyouTooLong        713
#define IDS_ERR_ExistRessyaOfRessyasyubetsu 731
#define IDS_ERR_ClipboardRessyaMust1    750
#define IDS_ERR_ChakuModifyFromSelf     751
#define IDS_ERR_ChakuModifyFromPair     752
#define IDS_ERR_HatsuModifyFromSelf     753
#define IDS_ERR_HatsuModifyFromPair     754
#define IDS_ERR_EkikanSaisyouSecIsNone  756
#define IDS_ERR_DiaNameDuplex           760
#define IDS_ERR_DLLNOTFOUND             761
#define ID_INDICATOR_PasteZoubun        800
#define IDS_INDICATOR_Renzoku           801
#define IDC_TREE_ROSEN                  1000
#define IDC_EDIT_Ekimei                 1001
#define IDC_EDIT_Syubetsumei            1001
#define IDC_EDIT_Name                   1001
#define IDC_EDIT_Ressyabangou           1001
#define IDC_EDIT_Chakujikoku            1001
#define IDC_EDIT_PasteZoubun            1001
#define IDC_EDIT_MarginLeft             1001
#define IDC_EDIT_YokojikuPos            1001
#define IDC_EDIT_DiagramKitenJikoku     1001
#define IDC_LIST_FONT                   1002
#define IDC_EDIT_Ryakusyou              1002
#define IDC_EDIT_Hatsujikoku            1002
#define IDC_EDIT_MarginRight            1002
#define IDC_EDIT_YokojikuSize           1002
#define IDC_EDIT_DiagramDgrYZahyouKyoriDefault 1002
#define IDC_BUTTON_FONT_CHANGE          1003
#define IDC_EDIT_MarginTop              1003
#define IDC_EDIT_TatejikuPos            1003
#define IDC_STATIC_FONT                 1004
#define IDC_EDIT_MarginBottom           1004
#define IDC_EDIT_TatejikuSize           1004
#define IDC_LIST_COLOR                  1008
#define IDC_EDIT_RosenName              1008
#define IDC_STATIC_COLOR                1009
#define IDC_TAB_MAIN                    1009
#define IDC_EDIT_RESSYAINDEX            1009
#define IDC_STATIC_TABNAME              1010
#define IDC_EDIT_RESSYACOUNT            1010
#define IDC_LIST_FONT_ITEMS             1011
#define IDC_STATIC_ERROR_KitenJikoku    1011
#define IDC_LIST_COLOR_ITEMS            1012
#define IDC_STATIC_ERROR_DiagramDgrYZahyouKyoriDefault 1012
#define IDC_STATIC_JikokuhyouMojiColor  1016
#define IDC_BUTTON_COLOR_CHANGE         1017
#define IDC_BUTTON_JikokuhyouMojiColor  1017
#define IDC_STATIC_DiagramSen           1018
#define IDC_BUTTON_DiagramSeniColor     1019
#define IDC_STATIC_JikokuhyouFont       1021
#define IDC_CHECK_DiagramSenStyleIsBold 1024
#define IDC_LIST_Dia                    1025
#define IDC_BUTTON_NEW                  1026
#define IDC_BUTTON_PROP                 1027
#define IDC_BUTTON_DELETE               1028
#define IDC_BUTTON_UP                   1029
#define IDC_BUTTON_DOWN                 1030
#define IDC_STATIC_ERROR_NameNotSet     1030
#define IDC_STATIC_ERROR_DeleteDiaPrompt 1031
#define IDC_STATIC_ERROR_DeleteDiaPrompt2 1032
#define IDC_COMBO_Ressyasyubetsu        1032
#define IDC_EDIT_Ressyamei              1033
#define IDC_EDIT_Gousuu                 1034
#define IDC_EDIT_Bikou                  1035
#define IDC_ERROR_ChakujikokuFormat     1041
#define IDC_ERROR_HatsujikokuFormat     1042
#define IDC_CHECK_IsNull                1042
#define IDC_COMBO_Jikanmemori           1043
#define IDC_ERR_1                       1044
#define IDC_ERR_2                       1045
#define IDC_STATIC_VERSION              1045
#define IDC_ERR_3                       1046
#define IDC_ERROR_RyakusyouLength       1046
#define IDC_ERR_4                       1047
#define IDC_ERR_EkimeiNo                1047
#define IDC_ERROR_SyubetsumeiNo         1047
#define IDC_ERR_EkimeiTooLong           1047
#define IDC_ERROR_SyubetsumeiEmpty      1047
#define IDC_ERR_5                       1048
#define IDC_RADIO_Ekiatsukai            1048
#define IDC_ERR_X                       1049
#define IDC_RADIO_Ekiatsukai2           1049
#define IDC_RADIO_Jikokukeisiki         1049
#define IDC_ERR_6                       1050
#define IDC_RADIO_Ekiatsukai3           1050
#define IDC_RADIO_Jikokukeisiki2        1050
#define IDC_RADIO_Ekiatsukai4           1051
#define IDC_RADIO_Jikokukeisiki3        1051
#define IDC_RADIO_Jikokukeisiki4        1052
#define IDC_ERR_8                       1052
#define IDC_RADIO_Ekikibo               1053
#define IDC_ERR_9                       1053
#define IDC_RADIO_Ekikibo2              1054
#define IDC_CHECK_EkiatsukaiModify      1054
#define IDC_CHECK_Kyoukaisen            1064
#define IDC_EDIT_EkimeiLength           1065
#define IDC_COMBO_JikokuOrderCopySrc    1066
#define IDC_EDIT_JikokuhyouRessyaWidth  1066
#define IDC_RADIO_EkijikokuOperation    1067
#define IDC_RADIO_EkijikokuOperation1   1068
#define IDC_RADIO_EkijikokuOperation2   1069
#define IDC_RADIO_EkijikokuOperation3   1070
#define IDC_EDIT_Seconds1               1071
#define IDC_EDIT_Seconds2               1072
#define IDC_RADIO_Ekiatsukai1           1073
#define IDC_TEXT_INPUTERROR             1074
#define IDC_TEXT_ENCODE_ERROR           1075
#define IDC_COMBO_DiagramSenStyle       1075
#define IDC_TEXT_FILE_SAVE_FAILED       1076
#define IDC_COMBO_DiagramRessyajouhouHyoujiKudari 1080
#define IDC_COMBO_StopMarkDrawType      1081
#define IDC_COMBO_SIHATSU_EKIINDEX      1081
#define IDC_COMBO_EKIINDEX_TO_ADD       1081
#define IDC_COMBO_DiagramRessyajouhouHyoujiNobori 1082
#define IDC_BUTTON_OPEN_GPL             1082
#define IDC_COMBO_SYUUCHAKU_EKIINDEX    1082
#define IDC_BUTTON_OPEN_GPL_J           1083
#define IDC_ERR_EKIINDEX_ORDER          1083
#define IDC_ERR_EKI_TOO_FEW             1084
#define IDC_EDIT_ADD_ROSENFILENAME      1084
#define IDC_BUTTON_ADD_ROSENFILENAME    1085
#define IDC_STATIC_ERR_EKIINDEX_NOT_SELECTED 1086
#define IDC_BUTTON_ABORT                1087
#define IDC_STATIC_PROGRESSTEXT         1088
#define IDC_RADIO_EKIJIKOUSORT_0        1089
#define IDC_RADIO_EKIJIKOUSORT_1        1090
#define IDC_CHECK_MODIFYHATSUJIKOKU     1090
#define IDC_COMBO_JikokuhyouFontIndex   1091
#define IDC_CHECK_AdjustByEkijikokukeisiki 1092
#define IDC_STATIC_LEGALCOPYRIGHT       1093
#define ID_ROSEN_FILE_PROP              32771
#define ID_EDIT_EkiProp                 32774
#define IDD_INSERT_EKI                  32775
#define ID_EDIT_EkiInsert               32776
#define ID_WINDOW_ROSEN_VIEW            32777
#define ID_Ressyasyubetsu_Prop          32778
#define ID_Ressyasyubetsu_Insert        32779
#define ID_Jikokuhyou_RessyaProp        32780
#define ID_Jikokuhyou_RessyaInsert      32781
#define ID_Jikokuhyou_ViewProp          32782
#define ID_FILE_PrintPageProp           32783
#define ID_Jikokuhyou_JikokuSakujo      32784
#define ID_Jikokuhyou_Tsuuka            32785
#define ID_Jikokuhyou_Sihatsu           32786
#define ID_Jikokuhyou_Syuuchaku         32787
#define ID_Jikokuhyou_Keiyunasi         32788
#define ID_Jikokuhyou_Renzoku           32789
#define ID_Edit_PasteEkiJikoku          32791
#define ID_Diagram_ViewProp             32792
#define ID_Diagram_XDgrSize_Inc         32794
#define ID_Diagram_XDgrSize_Dec         32795
#define ID_Diagram_YDgrSize_Inc         32796
#define ID_Diagram_YDgrSize_Dec         32797
#define ID_Diagram_Memori_Down          32798
#define ID_Diagram_Memori_Up            32799
#define ID_Diagram_Ressyabangou         32801
#define ID_Diagram_Ressyamei            32802
#define ID_Ressyasyubetsu_Up            32808
#define ID_Ressyasyubetsu_Down          32809
#define ID_Jikokuhyou_FocusMoveDown     32810
#define ID_Jikokuhyou_FocusMoveRight    32811
#define ID_Jikokuhyou_EkijikokuProp     32814
#define ID_Jikokuhyou_EkijikokuInsert   32815
#define ID_Jikokuhyou_EkijikokuErase    32816
#define ID_Jikokuhyou_ModifyEkijikokuCmd 32817
#define ID_Jikokuhyou_ModifyEkijikokuCmdRepeat 32818
#define ID_ROSEN_DIALIST                32819
#define ID_Diagram_YDgrSize_Reset       32820
#define ID_Diagram_RessyasenKudari      32821
#define ID_Diagram_RessyasenNobori      32822
#define ID_Jikokuhyou_EkijikokuDec      32824
#define ID_Jikokuhyou_EkijikokuNext     32825
#define ID_Jikokuhyou_EkijikokuInc      32826
#define ID_Jikokuhyou_EKikanSaisyouSec  32827
#define ID_Jikokuhyou_DiagramHeIdou     32829
#define ID_VIEW_DisplayTsuukaEkiJikoku  32831
#define ID_Diagram_HideIppanekiEkimei   32832
#define ID_FILE_JIKOKUHYOUCSV_EXPORT    32833
#define ID_FILE_EXPORT_JIKOKUHYOUCSV    32834
#define ID_FILE_IMPORT_JIKOKUHYOUCSV    32835
#define ID_Jikokuhyou_EkijikokuDecNoMove 32844
#define ID_Jikokuhyou_EkijikokuIncNoMove 32845
#define ID_Jikokuhyou_EkijikokuPrev     32849
#define ID_Diagram_StopMarkDraw         32853
#define ID_Jikokuhyou_SORT              32857
#define ID_FILE_ROSEN_FILE_INSERT       32859
#define ID_FILE_ROSEN_CREATE_SUB_ROSEN  32861
#define ID_Jikokuhyou_TsuukaTeisya      32862
#define ID_Jikokuhyou_Direct            32866
#define ID_Jikokuhyou_Undirect          32868
#define ID_EDIT_EKI_INVERT              32877
#define ID_VIEW_DisplayAllEkiJikoku     32878
#define ID_Jikokuhyou_Unify             32884
#define ID_MENUITEM_OPEN                32888
#define ID_VIEW_UPDATE                  59394

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_3D_CONTROLS                     1
#define _APS_NEXT_RESOURCE_VALUE        169
#define _APS_NEXT_COMMAND_VALUE         32891
#define _APS_NEXT_CONTROL_VALUE         1094
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif
