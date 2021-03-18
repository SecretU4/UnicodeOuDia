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


(��: 

	OuDia - ��Ԏ����\�����ƂɁA�_�C���O������`�悷��Win32�A�v���P�[�V
�����B

Copyright (C) 2006-2017 take-okm 

���̃v���O�����̓t���[�\�t�g�E�F�A�ł��B���Ȃ��͂�����A�t���[�\�t�g�E�F�A��
�c�ɂ���Ĕ��s���ꂽGNU ��ʌ��O���p������(�o�[�W����3���A����ȍ~�̃o�[�W��
���̂����ǂꂩ)����߂�����̉��ōĔЕz�܂��͉��� ���邱�Ƃ��ł��܂��B

���̃v���O�����͗L�p�ł��邱�Ƃ�����ĔЕz����܂����A*�S���̖��ۏ� *�ł��B
���Ɖ\���̕ۏ؂����ړI�ւ̓K�����́A���O�Ɏ����ꂽ���̂� �܂߁A�S������
���܂���B�ڂ�����GNU ��ʌ��O���p���������������������B

���Ȃ��͂��̃v���O�����Ƌ��ɁAGNU ��ʌ��O���p�������̃R�s�[���ꕔ �󂯎��
�Ă���͂��ł��B�����󂯎���Ă��Ȃ���΁A<http://www.gnu.org/licenses/> ��
�������������B

)

  �����āA���ʂȗ�O�Ƃ��āAtake-okm �͂��̃v���O�����̃R�[�h�� 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  ���邢�� "MFC Version 9.0" �Ɠ������C�Z���X���K�p���ꂽ
  "MFC Version 9.0" �̉��ς��ꂽ�o�[�W����)�ƃ����N���A
  �����N���ꂽ���҂��܂ތ������앨��Еz���鋖��^���܂��B
  ���Ȃ��� "MFC" �ȊO�Ŏg���Ă��邷�ׂ�
  �̃R�[�h�Ɋւ��Ă͑S�ʓI��GNU��ʌ��O���p�����_�񏑂ɏ]��Ȃ����
  �Ȃ�܂���B���Ȃ������̃t�@�C�������ς����Ȃ�΁A���Ȃ��͂��̗�O
  �����Ȃ��̃o�[�W�����̃t�@�C���Ɉ��������݂��邱�Ƃ��ł��܂����A��
  ������`���͂���܂���B������O��݂������Ȃ���΁A���̗�O������
  ���Ȃ��̃o�[�W��������͍폜���Ă��������B)
*/
// DiagramEdit.h : DIAGRAMEDIT �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
/** @file */

#if !defined(AFX_DIAGRAMEDIT_H__BB10ABB1_4C17_48C5_8B0E_831BB25A10EC__INCLUDED_)
#define AFX_DIAGRAMEDIT_H__BB10ABB1_4C17_48C5_8B0E_831BB25A10EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

#include "CMainFrame.h"
#include "CDiagramEditDoc.h"
#include "Print\CdPrintPageProp.h"
#include "ConvJikokuhyouCsv\CconvJikokuhyouCsv.h"
#include "ConvJikokuhyouCsv\CconvJikokuhyouCsv.h"
#include "ViewEki\CEkiDoc.h"
#include "ViewEki\CEkiView.h"
#include "ViewRessyasyubetsu\CRessyasyubetsuDoc.h"
#include "ViewJikokuhyou\CJikokuhyouDoc.h"
#include "ViewJikokuhyou\CJikokuhyouView.h"
#include "ViewJikokuhyou\WndJikokuhyou\CWndJikokuhyou.h"
#include "ViewDiagram\CDedDiagramDoc.h"
#include "ViewDiagram\CWndDiagram.h"
#include "ViewComment\CDedCommentDoc.h"

using namespace Print;
using namespace ViewEki;
using namespace ViewRessyasyubetsu;
using namespace ViewJikokuhyou;
using namespace ViewDiagram;
using namespace ViewComment;
using namespace ConvJikokuhyouCsv;
/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� DiagramEdit.cpp �t�@�C�����Q�Ƃ��Ă��������B
//
/**
 @brief DiagramEdit �̃A�v���P�[�V�����N���X�ł��B
	CWinApp �̔h���N���X�ƂȂ�܂��B

	���[�gDoc/View�E�e��T�uDoc/View �ւ̃A�N�Z�X�̎�i��񋟂��܂��B
 */
class CDiagramEditApp : public CHidemdiApp
{
	// ********************************
	///@name	�W��
	// ********************************
	///@{
	/**
		�w�w�x�T�u DocView �ւ̃|�C���^�ł��B
		InitInstance() �Ő��������I�u�W�F�N�g���w���܂��B
	 */
	CHidemdiSubDoctmpl* m_pdoctmplEki ;
	/**
		�w��Ԏ�ʁx�T�u DocView �ւ̃|�C���^�ł��B
		InitInstance() �Ő��������I�u�W�F�N�g���w���܂��B
	 */
	CHidemdiSubDoctmpl* m_pdoctmplResssyasyubetsu ;

	/**
		�w�����\�x�T�u DocView �ւ̃|�C���^�ł��B
		InitInstance() �Ő��������I�u�W�F�N�g���w���܂�
	 */
	CHidemdiSubDoctmpl* m_pdoctmplJikokuhyou ;

	/**
		�w�_�C���O�����x�T�u DocView �ւ̃|�C���^�ł��B
		InitInstance() �Ő��������I�u�W�F�N�g���w���܂�
	 */
	CHidemdiSubDoctmpl* m_pdoctmplDiagram ;

	/**
		�w�R�����g�x�T�u DocView �ւ̃|�C���^�ł��B
		InitInstance() �Ő��������I�u�W�F�N�g���w���܂�
	 */
	CHidemdiSubDoctmpl* m_pdoctmplComment ;

	///@}
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		  �P���f�[�^�N���X�ł��B
		  ����y�[�W�Ɋւ���v���p�e�B��ێ����܂��B
	 */
	CdPrintPageProp	m_CdPrintPageProp ;
	
	///@}
private:
	// ================================
	//	�����֐�
	// ================================
	/**
		�o�[�W�������\�[�X����A�o�[�W�����ԍ����擾���܂��B
	@param pstrFileVersion [out]
		���[�g�u���b�N�̃o�[�W�����ԍ����擾���܂��B
		(��F"0.05.03" ) 
	@param pstrLegalCopyright [out]
		lang-codepage="041104b0"�� "LegalCopyright" ���擾���܂��B
	*/
	static void readVersionResource( 
		string* pstrFileVersion , 
		string* pstrLegalCopyright ) ;

 public:
	// ********************************
	///@name CDiagramEditApp-����
	// ********************************
	///@{
	CdPrintPageProp	getCdPrintPageProp(){
		return m_CdPrintPageProp ; };
	std::string getProgramVer()const ;
	///@}

	// ********************************
	///@name CDiagramEditApp-����
	// ********************************
	///@{
	/**
	 @return
		���C���t���[���E�C���h�E�I�u�W�F�N�g�ւ�
		�|�C���^��Ԃ��܂��B
	 */
	CMainFrame*	getCMainFrame() ;

	/**
	 @return
		�w�H���x�r���[�i�����y�C���j��Ԃ��܂��B
	 */
	CDlgRosenView*	getCDlgRosenView() ;
	
	/**
		�w�w�x�h�L�������g�ƃr���[���J���A�ҏW�\�ɂ��܂��B
	@param ppEkiView [out]
		���̊֐��͂��̃|�C���^�ɁACEkiView �̃A�h���X���������݂܂��B
		�r���[�������J���Ă���ꍇ�́A�ŏ��̃r���[���������݂܂��B
		�G���[�̏ꍇ�́ANULL���������݂܂��B
		�s�v�̏ꍇ�́ANULL���w�肵�Ă��������B
	@return
		����������A�w�T�u�h�L�������g�x�I�u�W�F�N�g��Ԃ��܂��B
		�G���[�Ȃ�NULL�ł��B
	 */
	CEkiDoc* openCEkiDoc( CEkiView** ppEkiView = NULL ) ;
	
	/**
		�w��Ԏ�ʁx�h�L�������g�ƃr���[���J���A�ҏW�\�ɂ��܂��B
	 @return
		����������A�w�T�u�h�L�������g�x�I�u�W�F�N�g��Ԃ��܂��B
		�G���[�Ȃ�NULL�ł��B
	 */
	CRessyasyubetsuDoc* openCRessyasyubetsuDoc() ;

	/**
		�w�����\�x�h�L�������g�ƃr���[���J���A�ҏW�\�ɂ��܂��B
	 @param pCentDedDia [in]
		�ҏW�ΏۂƂȂ�_�C���I�u�W�F�N�g��
		�w�肵�Ă��������B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- ���� =Ressyahoukou_Kudari
		- ��� =Ressyahoukou_Nobori 
	@param ppJikokuhyouView [out]
		���̊֐��͂��̃|�C���^�ɁACJikokuhyouView �̃A�h���X���������݂܂��B
		�r���[�������J���Ă���ꍇ�́A�ŏ��̃r���[���������݂܂��B
		�G���[�̏ꍇ�́ANULL���������݂܂��B
		�s�v�̏ꍇ�́ANULL���w�肵�Ă��������B
	 @return
		����������A�w�T�u�h�L�������g�x�I�u�W�F�N�g��Ԃ��܂��B
		�G���[�Ȃ畉�̐��ł��B
	 */
	CJikokuhyouDoc* openCJikokuhyouDoc( 
		const CentDedDia* pCentDedDia , 
		ERessyahoukou eRessyahoukou ,
		CJikokuhyouView** ppJikokuhyouView ) ;

	/**
		�w�_�C���O�����x�h�L�������g�ƃr���[���J���A�ҏW�\�ɂ��܂��B
	 @param pCentDedDia [in]
		�ҏW�ΏۂƂȂ�_�C���I�u�W�F�N�g��
		�w�肵�Ă��������B
	 @return
		����������A�w�T�u�h�L�������g�x�I�u�W�F�N�g��Ԃ��܂��B
		�G���[�Ȃ畉�̐��ł��B
	 */
	CDedDiagramDoc* openCDedDiagramDoc( const CentDedDia* pCentDedDia ) ;

	/**
		�w�R�����g�x�h�L�������g�ƃr���[���J���A�ҏW�\�ɂ��܂��B
	 @return
		����������A�w�T�u�h�L�������g�x�I�u�W�F�N�g��Ԃ��܂��B
		�G���[�Ȃ畉�̐��ł��B
	 */
	CDedCommentDoc* openCDedCommentDoc() ;


	/**
	 @return
		OuDia �t�@�C���EWinDIA�t�@�C���E"*.*" �̃t�B���^�������
		�Ԃ��܂��B
		���̕�����́A CFileDialog �̈����ɓn�����Ƃ��ł��܂��B
	 */
	virtual CString getCFileDialogFilter() ;

	/**
	 @return
		OuDia �t�@�C���E"*.*" �̃t�B���^�������
		�Ԃ��܂��B
		���̕�����́A CFileDialog �̈����ɓn�����Ƃ��ł��܂��B
	 */
	virtual CString getCFileDialogOudFilter() ;

	/**
	 @return
		CSV�t�@�C���E"*.*" �̃t�B���^�������
		�Ԃ��܂��B
		���̕�����́A CFileDialog �̈����ɓn�����Ƃ��ł��܂��B
	 */
	virtual CString getCFileDialogFilterCsv() ;

	/**
	@return
		CconvJikokuhyouCsv �𐶐����܂��B
	*/
	virtual CconvJikokuhyouCsv createCconvJikokuhyouCsv() ;

	///@}
	// ********************************
	///@name CDiagramEditApp-�t�@�C����
	// ********************************
	///@{
	/**
		�t�@�C���^�C�g��+�g���q �`���̃t�@�C��������A
		�v���O�����f�B���N�g��(.exe�t�@�C���Ɠ����ꏊ�̃f�B���N�g��)��
		�t�^�����t���p�X�����쐬���܂��B
	@param strFilename [in]
		�t�@�C�������w�肵�Ă��������B(��:"sub.dll" )
	@return
		�t���p�X����Ԃ��܂��B(��:"c:\program files\oudia\sub.dll" )

		strFilename �ɋ󕶎�����w�肷��ƁA
		�߂�l�̓v���O�����f�B���N�g���ɂȂ�܂�
		(��:"c:\program files\oudia\" )�B
	*/
	CString makeProgramDirFilename( const CString& strFilename ) ;

	/**
		�t�@�C���^�C�g��+�g���q �`���̃t�@�C��������A
		LOCAL_APPDATA �f�B���N�g������ \oudia �f�B���N�g����
		�t�^�����t���p�X�����쐬���܂��B
	@param strFilename [in]
		�t�@�C�������w�肵�Ă��������B(��:"profile.ini" )
	@return
		�t���p�X����Ԃ��܂��B
		(��:"c:\documents and settings\username\local settings\application data\oudia\profile.ini" )

		strFilename �ɋ󕶎�����w�肷��ƁA
		�߂�l�̓v���O�����f�B���N�g���ɂȂ�܂�
		(��:"c:\documents and settings\username\local settings\application data\oudia\" )�B
	*/
	CString makeLocalAppdataFilename( const CString& strFilename ) ;

	/**
		�g�s�b�N������AHtmlHelp() API�̑�3�����Ɏw�肷�邽�߂́A
		HTML Help URL ���쐬���܂��B
	@param strTopic [in]
		�g�s�b�N�����w�肵�Ă��������B (��:"/Topic.htm" ) ;
	@return
		Html Help URL��Ԃ��܂��B
		(��:"c:\program files\oudia\oudia.chm::/Topic.htm" )�B

		strTopic�ɋ󕶎�����w�肷��ƁA.chm �t�@�C���̃t���p�X����Ԃ��܂��B
		(��:"c:\program files\oudia\oudia.chm" )�B
	*/
	CString makeHtmlHelpUrl( const CString& strTopic ) ;

	///@}
	// ********************************
	///@name CDiagramEditApp-.ini �t�@�C��
	// ********************************
	///@{
	/**
	�w�_�C���O�����x�E�C���h�E CWndDiagram �́A
	�\���ݒ�� PrivateProfile (.ini �t�@�C��) �ɕۑ����܂��B

	�ۑ��Ώۂ́A�Z�N�V����[AppProp]�́A�ȉ��̃G���g���ł��B

	- "DiagramPosDgr" @n
	 TargetPos�̍���ɕ`�悳���w�_�C���O�������W�x�B 
	 �J���}��؂�ŁAX,Y���W���L�q���܂��B

	- "DcdPerDgrX" @n
	 �w�_�C���O�������W�x��1�ɑΉ�����A�wDcDraw���W(�_�����W)�x�̐�

	- "DcdPerDgrY" @n
	 �w�_�C���O�������W�x��1�ɑΉ�����A�wDcDraw���W(�_�����W)�x�̐�

	- "DiagramVlineMode" @n
		�c�r�̊Ԋu�̃��[�h�BCDcdDiagram::m_arVline[8] �̓Y�����ł��B

	- "DiagramDisplayRessyabangou" @n 
		 �_�C����ʗ�Ԕԍ��\��
		- 1 ;	//	�_�C����ʂɗ�Ԕԍ���\������
		- 0 ;	//	�_�C����ʂɗ�Ԕԍ���\�����Ȃ�
	
	- "DiagramDisplayRessyamei" @n
		 �_�C����ʗ�Ԗ��\��
		- 1 ;	//	�_�C����ʂɗ�Ԗ���\������
		- 0 ;	//	�_�C����ʂɗ�Ԗ���\�����Ȃ�

	- "DiagramDisplayRessyasen" @n
		��Ԑ���\�����邩�ۂ����w�肵�܂��B�J���}��؂�ŁA����,�����L�q���܂��B
		- 1 ;	//	��Ԑ���\������
		- 0 ;	//	��Ԑ���\�����Ȃ�

	- "DiagramHideIppanekiEkimei" @n
		��ʉw�̉w���\�����B���w��ł��B
		- 1 ;	//	���ׂẲw����\�����܂��B(default)
		- 0 ;	//	��ʉw�̉w����\�����܂���B

	- "DiagramStopMarkDraw" @n
		��ԉw�\���̗L�����w�肵�܂��B
		- 0: ��ԉw����=OFF�B��ԉw�������s���܂���B
		- 1: ��ԉw����=ON�B�Z���Ԓ�Ԃ̉w�ɁA��ԉw�������L��(��)��`�悵�܂��B

	- "DiagramKeepZoneDgrOnSize" @n 
		�E�C���h�E�T�C�Y�ύX���̓���B
		- false:�\���͈͂�ύX(OuDia Ver.1.00.04 ����)
		- true: �\���͈͂�ύX���Ȃ�(OuDia Ver.1.00.04 �݊�)

	@param pCWndDiagram [in]
		�w�_�C���O�����x�E�C���h�E�I�u�W�F�N�g���w�肵�Ă��������B
		���̊֐��́A���̃I�u�W�F�N�g�̑������A�t�@�C���ɕۑ����܂��B
	 @return	
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int writeCWndDiagramViewProp( const CWndDiagram* pCWndDiagram ) ;

	/**
	�w�_�C���O�����x�E�C���h�E CWndDiagram �́A
	�\���ݒ�� PrivateProfile (.ini �t�@�C��) ����
	�ǂݍ��݂܂��B
	
	 @param pCWndDiagram [in]
		�w�_�C���O�����x�E�C���h�E�I�u�W�F�N�g���w�肵�Ă��������B
		���̊֐��́A���̃I�u�W�F�N�g�̑������A�t�@�C���ɕۑ����܂��B
	 @return	
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	DiagramZoneDgr ���w�肳��Ă��܂���B
		-	-2 ;	//	DiagramVlineMode ���w�肳��Ă��܂���B
		-	-3 ;	//	DisplayRessyabangou ���w�肳��Ă��܂���B
		-	-4 ;	//	DisplayRessyamei ���w�肳��Ă��܂���B
		-	-5 ;	//	DisplayRessyasen ���w�肳��Ă��܂���B
		-	-6 ;	//	HideIppanekiEkimei ���w�肳��Ă��܂���B
	*/
	virtual int readCWndDiagramViewProp( CWndDiagram* pCWndDiagram ) ;


	/**
	�w�_�C���O�����x�E�C���h�E CWndJikokuhyou �́A
	�\���ݒ�� PrivateProfile (.ini �t�@�C��) �ɕۑ����܂��B

	�ۑ��Ώۂ́A�Z�N�V����[AppProp]�́A�ȉ��̃G���g���ł��B

	- "Jikokuhyou_DisplayTsuukaEkiJikoku" @n
		�ʉ߉w�̉w�����\���̗L���̎w��
		- 1 ; �ʉ߉w�̉w������\�����܂��B(default)
		- 0 ; �ʉ߉w�̉w������\�������ɁA�ʉ߃}�[�N "�" ��\�����܂��B
	- "Jikokuhyou_DisplayAllEkiJikoku" @n
		�S�w�̉w������\�����邩�ۂ��̎w��

		- 1 ; �w�̉w�����`��(CentDedEki::m_eEkijikokukeisiki )�Ƃ͖��֌W�ɁA
			�����\�r���[�ɑS�w�̒���������\�����܂��B
		- 0 ; �S�w�\�����s���܂���B
	- "Jikokuhyou_EkijikokuSort" @n
		�����\�r���[�̉w�����ł́u���בւ��v�̃��[�h�B 
		����́A�w���ł̃\�[�g�ł��B
		- 0 : �w���ł̃\�[�g
		- 1 : ��p�\�[�g
	- "Jikokuhyou_ModifyEkiJikoku" @n
		�J�グ�E�J�艺���̗L���E�����������܂��B
		- 1: �L��
		- 0: ����
	
	@param pCWndJikokuhyou [in]
		�w�����\�x�E�C���h�E�I�u�W�F�N�g���w�肵�Ă��������B
		���̊֐��́A���̃I�u�W�F�N�g�̑������A�t�@�C���ɕۑ����܂��B
	 @return	
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int writeCWndJikokuhyouViewProp( 
		const CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�w�_�C���O�����x�E�C���h�E CWndJikokuhyou �́A
	�\���ݒ�� PrivateProfile (.ini �t�@�C��) ����
	�ǂݍ��݂܂��B
	
	 @param pCWndJikokuhyou [in]
		�w�_�C���O�����x�E�C���h�E�I�u�W�F�N�g���w�肵�Ă��������B
		���̊֐��́A���̃I�u�W�F�N�g�̑������A�t�@�C���ɕۑ����܂��B
	 @return	
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int readCWndJikokuhyouViewProp( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�w�w�x�E�C���h�E CWndDcdGridEki �́A
	�\���ݒ�� PrivateProfile (.ini �t�@�C��) �ɕۑ����܂��B

	�ۑ��Ώۂ́A�Z�N�V����[AppProp]�́A�ȉ��̃G���g���ł��B

	- "EkiProp_AdjustByEkijikokukeisiki" @n
		- 1; �w�̃v���p�e�B���ύX���ꂽ�Ƃ��A
			���ׂẴ_�C���E��Ԃ̉w�������A
			�w�����`���ɐ��K�����܂��B
		- 0; �w�̃v���p�e�B���ύX���ꂽ�Ƃ����A
			��Ԃ̉w������ύX���܂���B

	@param pCWndDcdGridEki [in]
		�w�w�x�E�C���h�E�I�u�W�F�N�g���w�肵�Ă��������B
		���̊֐��́A���̃I�u�W�F�N�g�̑������A�t�@�C���ɕۑ����܂��B
	 @return	
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int writeCWndDcdGridEkiProp( 
		const CWndDcdGridEki* pCWndDcdGridEki ) ;

	/**
		�w�w�x�E�C���h�E CWndDcdGridEki �́A
		�\���ݒ�� PrivateProfile (.ini �t�@�C��) ����
		�ǂݍ��݂܂��B
	
	 @param pCWndDcdGridEki [in]
		�w�w�x�E�C���h�E�I�u�W�F�N�g���w�肵�Ă��������B
		���̊֐��́A���̃I�u�W�F�N�g�̑������A�t�@�C���ɕۑ����܂��B
	 @return	
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int readCWndDcdGridEkiProp( 
		CWndDcdGridEki* pCWndDcdGridEki ) ;



	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

public:
	CDiagramEditApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDiagramEditApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	//{{AFX_MSG(CDiagramEditApp)
	afx_msg void OnAppAbout();
	afx_msg void OnVIEWEki();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnFILEPrintPageProp();
	afx_msg void OnFileOpen();
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};


/////////////////////////////////////////////////////////////////////////////

/**
 @return 
	�A�v���P�[�V�����I�u�W�F�N�g��Ԃ��܂��B
 */
inline CDiagramEditApp*	getCDiagramEditApp(){
	return (CDiagramEditApp*)AfxGetApp() ; 
};

/**
 @return 
	�w���[�g�h�L�������g�x�I�u�W�F�N�g��Ԃ��܂��B
 */
inline CDiagramEditDoc*	getCDiagramEditDoc(){
	return (CDiagramEditDoc*)getCDiagramEditApp()->pRootDoc() ; 
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B



#endif // !defined(AFX_DIAGRAMEDIT_H__BB10ABB1_4C17_48C5_8B0E_831BB25A10EC__INCLUDED_)
