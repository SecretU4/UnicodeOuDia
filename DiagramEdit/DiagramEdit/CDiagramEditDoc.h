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
// CDiagramEditDoc.h : CDiagramEditDoc �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//	$Id: CDiagramEditDoc.h 295 2016-06-11 05:14:13Z okm $
/////////////////////////////////////////////////////////////////////////////
/** @file */
#if !defined(AFX_CDIAGRAMEDITDOC_H__A4879B96_62E6_4298_B7DB_8F991F72EC7F__INCLUDED_)
#define AFX_CDIAGRAMEDITDOC_H__A4879B96_62E6_4298_B7DB_8F991F72EC7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NsMu/CMup_deque.h"
#include "NsOu/Ou.h"
#include "Hidemdi\Hidemdi.h"
#include "DedRosenFileData\CDedRosenFileData.h"
#include "DedRosenFileData\EditCmd\CRfEditCmd.h"

using namespace OuLib::NsOu;
using namespace DedRosenFileData;
using namespace DedRosenFileData::EditCmd;

/** oud �t�@�C������ FiltTypeAppComment ���ږ� */
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;

/**
@brief
�y�T�v�z  DiagramEdit �̃��[�g�h�L�������g�N���X�ł��B
MFC �� CDocument ���p�����܂��B

���̃N���X�́A .oud �t�@�C���̓��e��ێ�����
CDedRosenFileData ��
�C���X�^���X���W�񂵂Ă��܂�( m_CDedRosenFileData )�B

m_CDedRosenFileData ���ێ����Ă���H���t�@�C���̃f�[�^���Q�Ƃ���ɂ́A
CDiagramEditDoc::getCDedRosenFileData() �� const CDedRosenFileData* ���擾���A
 ���̃|�C���^��	CDedRosenFileData �̃��\�b�h�ɃA�N�Z�X���Ă��������B

CDiagramEditDoc::getCDedRosenFileData() �Ŏ擾�ł���|�C���^�� const* �ł��B
���̂��߁A m_CDedRosenFileData �A����ɂ͂����ɏW�񂳂��e��I�u�W�F�N�g��
��Ԃ�ς��邱�Ƃ͂ł��܂���B

m_CDedRosenFileData �̓��e��ύX���邽�߂ɂ́A
�ύX���e�ɉ����� CRfEditCmd �h���N���X�I�u�W�F�N�g�𐶐����A
���̃C���X�^���X�ւ� Ou(�X�}�[�g�|�C���^) �������ɂ��� executeEditCmd() ��
�Ăяo���Ă��������B
*/ 
class CDiagramEditDoc : public CHidemdiRootDoc
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CHidemdiRootDoc	super ;
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
	�y�T�v�z  DiagramEdit �̃A�v���P�[�V�������ǂݏ�������
	�w�H���t�@�C���x�Ɋ܂܂��f�[�^��ێ�����N���X�ł��B
	 */
	CDedRosenFileData	m_CDedRosenFileData ;
	///@}
private:
	// --------------------------------
	///@name Undo,Redo�֌W�����f�[�^ 
	// --------------------------------
	///@{
	/**
	 	Undo �̂��߂̏���ێ�����L���[�ł��B
	 
	 	executeEditCmd() �́A CRfEditCmd �I�u�W�F�N�g��
	 	���̃L���[�̖����ɒǉ����܂��B
	 
	 	Undo �����s����ꍇ�́A
	 
	 	�P�D  m_contUndo �̖����� CRfEditCmd �I�u�W�F�N�g
	 	�� createUndoCmd() �Ő��������R�}���h�� execute() ����B
	 
	 	�Q�D  m_contUndo �̖����� CHint_CDedRosenFileData �I�u�W�F�N�g��
	 	�̂Ă�B
	 */
	CMup_deque< Ou< CRfEditCmd > > m_contUndo ;
	
	/**
		Redo �̂��߂̏���ێ�����L���[�ł��B
	
		undo() �́A CRfEditCmd �I�u�W�F�N�g��
		���̃L���[�̖����ɒǉ����܂��B

		executeEditCmd() �́A���̃R���e�i����ɂ��܂��B
	
		Redo �����s����ꍇ�́A
	
		�P�D  m_contRedo �̖����� CRfEditCmd �I�u�W�F�N�g
		�̃R�}���h�� execute() ����B
	
		�Q�D  ���̃R�}���h�� m_contRedo �̖�������͍폜���A
		m_contUndo �̖����ɒǉ�����B
	
		�R�D  m_contRedo �̖����� CHint_CDedRosenFileData �I�u�W�F�N�g��
		�̂Ă�B
	*/
	CMup_deque< Ou< CRfEditCmd > > m_contRedo ;

	/**
�@�@���݂̃h�L�������g�́A
	�w�ύX�t���O�xOFF�̏�Ԃ�����s���ꂽ�ύX/Undo�̉� 
	�������܂��B 

	����{���� 

�@	   ModifyCountFromSave �́A�h�L�������g���V�K�쐬���ꂽ���ƁA�܂��͕ۑ����ꂽ�Ƃ��� 0 �Ƀ��Z�b�g����܂��B 
�@	  ���̌� 
			�ύX����/REDO���s��ꂽ�Ƃ���1���Z 
			UNDO���s��ꂽ�Ƃ���1���Z 
	���s���܂��B 
�@	  �w�ύX�t���O�x�͂��̒l�ɓ�����������̂Ƃ��܂��B�A�v���P�[�V�����́A�ȉ��̋K���ɏ]���āA�w�ύX�t���O�x�𐧌䂵�܂��B 
			ModifyCountFromSave == 0 �̂Ƃ��E�E�E�w�ύX�t���O�x��OFF 
			ModifyCountFromSave != 0 �̂Ƃ��E�E�E�w�ύX�t���O�x��ON 

	����O����|�P 

	�@ModifyCountFromSave �� INT_MAX �ɒB������A���̌�͕ύX�EUNDO�EREDO���s���Ă��l�͕ς��܂���B���̏�Ԃ́A�u�����Ȃ�UNDO�EREDO���s���Ă��A�h�L�������g�̏�Ԃ��w�ύX�t���OOFF�x�ɖ߂����Ƃ͂ł��Ȃ��v���Ƃ������܂��B 

	����O����|2 

�@	  ModifyCountFromSave �����̂Ƃ��ɐV�����ύX���s��ꂽ�ꍇ(UNDO,REDO�ȊO�̕ҏW���삪�s��ꂽ�ꍇ)�́AModifyCountFromSave�� INT_MAX �Ƃ��܂��B 

�@	  ���̗�O���삪�K�p�����ꍇ�̈��́A 

�@	  �u�h�L�������g���t�@�C���ɕۑ��������ƁAUNDO���s���A���̌�ҏW������s�����v 

	�Ƃ������̂ł��B�ȉ��̗�ł́A6.�̑��삪���̏ꍇ�ɂ�����܂��B 

	@code
	// -------------------------------- 
	1.������� 
		�h�L�������g�@"" 
		UNDO�X�^�b�N 
		ModifyCountFromSave=0 

	2.1��ڂ̕ҏW  �@"ABC" 
		�h�L�������g  "ABC" �ɍX�V 
		UNDO�X�^�b�N    "" 
		ModifyCountFromSave=1 

	3.2��ڂ̕ҏW�@"ABCDEF" 
		�h�L�������g  "ABCDEF"  �ɍX�V 
		UNDO�X�^�b�N    "","ABC" 
		ModifyCountFromSave=2 

	4.�h�L�������g���t�@�C���ɕۑ��@ 
		�h�L�������g  "ABCDEF"  �ɍX�V 
		UNDO�X�^�b�N    "","ABC" 
		ModifyCountFromSave=0 

	5.Undo 
		�h�L�������g  "ABC" 
		UNDO�X�^�b�N    "" 
		REDO�X�^�b�N    "ABCDEF" 
		ModifyCountFromSave=-1 

	6.�ҏW "ABCGHI" 
		�h�L�������g  "ABCGHI" 
		UNDO�X�^�b�N    "" "ABC" 
		REDO�X�^�b�N     
		ModifyCountFromSave=INT_MAX 
	// -------------------------------- 
	@endcode

�@	  6.�̕ҏW�ɍۂ��� ModifyCountFromSave �������ǂ��� +1 ����ƁA ModifyCountFromSave �� 0�ƂȂ�A�h�L�������g�́w�ύX�t���OOFF�x�ɂȂ��Ă��܂��܂��B����͐���������܂���B 

	*/
	int m_iModifyCountFromDoc ;	
	///@}

protected:
	// --------------------------------
	///@name	�����֐�-�t�@�C�����J���E�ۑ�
	// --------------------------------
	///@{
	/**
	 	OnOpenDocument() �̉����֐��ł��B
	 	WinDia �`���̃t�@�C����ǂݍ���ŁAm_CDedRosenFileData ��
	 	���f���܂��B
	  @param lpszPathName [in]
	  	�ǂݍ��ރt�@�C�������w�肵�ĉ������B
	 	���̃t�@�C�����́A WinDia �`���łȂ��Ă͂Ȃ�܂���B
	  @return
	 	���������� TRUE �E �G���[�Ȃ� FALSE �ł��B
	 
	 	���̊֐��́A�G���[�̏ꍇ�̓��b�Z�[�W�{�b�N�X��\�����܂��B
	 */
	virtual BOOL OnOpenDocument_WinDia( LPCTSTR lpszPathName ) ;
	
	/**
	 	OnSaveDocument() �̉����֐��ł��B
	 	�h�L�������g�̓��e���AWinDia �`���̃t�@�C���ɕۑ����܂��B
	  @param lpszPathName [in]
	  	�ۑ�����t�@�C�������w�肵�ĉ������B
	  @return
	 	���������� TRUE �E �G���[�Ȃ� FALSE �ł��B
	 
	 	���̊֐��́A�G���[�̏ꍇ�̓��b�Z�[�W�{�b�N�X��\�����܂��B
	 */
	virtual BOOL OnSaveDocument_WinDia( LPCTSTR lpszPathName ) ;
	
	/**
		
	@param lpszDllFilename [in]
		�t�@�C���ϊ�DLL�̃t�@�C�������w�肵�Ă��������B
	@param pbinFileContent [in,out]
		�ϊ����s���t�@�C���R���e���c���w�肵�Ă��������B
		���̊֐��͂��̃o�C�i���f�[�^��ϊ����A�ϊ����ʂ��㏑�����܂��B
	@param pstrError [out]
		���̊֐��́A�ϊ��ŃG���[������������A�G���[���b�Z�[�W��
		�����ɏ������݂܂��B
		���̃��b�Z�[�W�́A�����Ƀ��b�Z�[�W�{�b�N�X�ŕ\���\�Ȍ`���ł��B
	@return 
		-	0 : �����ɐ������܂����B
		-	-1 : ����DLL���T�|�[�g����t�@�C���`���ł͂���܂���ł����B
		-	-101: DLL���݂���܂���ł����B
		-	-102: �t�@�C���̕ϊ��Ɏ��s���܂����B
	@attention
�@	  �߂�l�� -1 �̏ꍇ�́A *pstrError �ɂ̓G���[���b�Z�[�W���i�[����܂���B
	*/
	int OnOpenDocument_ConvFile( 
		LPCTSTR lpszDllFilename , 
		std::vector< char >* pbinFileContent , 
		CString* pstrError ) ;
	///@}


public:
	// ********************************
	//	CHidemdiRootDoc
	// ********************************
	/**
	  	���ׂẴT�uDocview�ƁA���[�gDocview�ɑ΂��āA
	 	UpdateAllViews()�����s���܂�
	   @param pSender
	  	�h�L�������g��ύX�����r���[�ւ̃|�C���^�B
	  ���ׂẴr���[���X�V����Ƃ��ɂ� NULL ���w�肵�܂��B
	   @param lHint
	  	�ύX�Ɋւ�������w�肵�܂��B
	  	�������A((LPARAM)-1)���w�肳�ꂽ�ꍇ�́A���ׂĂ�Docview�ɑ΂��āA
	  	���e�����[�g�h�L�������g�ɔ��f���A�K�v�Ȃ�΃��[�gDoc�ɑ΂���
	  	SetModifiedFlag()�����s�����܂��B
	   @param pHint
	  	�ύX�Ɋւ����񂪊i�[����Ă���I�u�W�F�N�g�ւ̃|�C���^�B
	 
	  [�I�[�o���C�h]
	 	UpdateAllSubDocviews() �ł́ACJikokuhyouDoc �I�u�W�F�N�g�ɑΉ�����
	 	CentDedDia �I�u�W�F�N�g�����邩�ǂ��������؂��܂��B
	 	�Ή����� CentDedDia ���폜����Ă���ꍇ�́A
	 	CJikokuhyouDoc �I�u�W�F�N�g���폜���܂��B
	 */
	virtual void UpdateAllSubDocviews( CView* pSender , LPARAM lHint = 0 , CObject* pHint = NULL );

// ********************************
//	CDiagramEditDoc
// ********************************
public:
	// ********************************
	///@name CDiagramEditDoc-���
	// ********************************
	///@{
	const CDedRosenFileData*	getCDedRosenFileData()const ;
	///@}
	// ********************************
	///@name �N���b�v�{�[�h����
	// ********************************
	///@{
	/**
	@return
		CentDedEki �I�u�W�F�N�g�̓��e��ێ�����
		�N���b�v�{�[�h�t�H�[�}�b�g�l��Ԃ��܂��B
	*/
	static UINT getCF_CentDedEki() ;


	/**
	 �w�肳�ꂽ CentDedEki �I�u�W�F�N�g�̓��e���A
	�N���b�v�{�[�h�ɕۑ����܂��B
	@param pMuCentDedEki [in]
		�w�I�u�W�F�N�g���w�肵�Ă��������B
	@return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B	
		-	-1 ;	//	CentDedEki �̓��e���s���ł��B
		-	-11 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
	*/
	static int CentDedEki_To_Cliboard( const Mu<CentDedEki>* pMuCentDedEki ) ;
	/**
	�@�N���b�v�{�[�h�ɁA CentDedEki �I�u�W�F�N�g��
	���e���i�[����Ă�����A������擾���܂��B
	@param pCentDedEki [out]
		���̊֐��͐���������A���̉w�I�u�W�F�N�g��
		�N���b�v�{�[�h�̓��e��ǉ����܂��B
	@return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B	
			-	-1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
			-	-2 ;	//	�N���b�v�{�[�h����̓ǂݍ��݂Ɏ��s���܂����B	
			-	-3 ;	//	�N���b�v�{�[�h�̓��e���s���ł��B
			-	-4 ;	//	CentDedEki �̓��e���s���ł��B
	*/
	static int CentDedEki_From_Cliboard( 
		Mui<CentDedEki>* pCentDedEki ) ;



	/**
	 @return 
		�N���b�v�{�[�h�ɁA CentDedEki �I�u�W�F�N�g��
		���e���i�[����Ă�����A�^��Ԃ��܂��B
	 */
	static bool CentDedEki_IsClipboardFormatAvailable() ;

	/**
	@return
		CentDedRessyasyubetsu �I�u�W�F�N�g�̓��e��ێ�����
		�N���b�v�{�[�h�t�H�[�}�b�g�l��Ԃ��܂��B
	 */
	static UINT getCF_CentDedRessyasyubetsu() ;

	/**
	 �w�肳�ꂽ CentDedRessyasyubetsu �I�u�W�F�N�g�̓��e���A
	�N���b�v�{�[�h�ɕۑ����܂��B
	@param pMuCentDedRessyasyubetsu [in]
		��Ԏ�ʂ�ێ������R���e�i���w�肵�Ă��������B
	@return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B	
			-	-1 ;	//	CentDedRessyasyubetsu �̓��e���s���ł��B
			-	-11 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
	 */
	static int CentDedRessyasyubetsu_To_Cliboard( 
		const Mu<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) ;

	/**
	 �N���b�v�{�[�h�ɁA CentDedRessyasyubetsu �I�u�W�F�N�g��
	���e���i�[����Ă�����A������擾���܂��B

	@param pMuCentDedRessyasyubetsu [out]
		���̊֐��͐���������A���̃R���e�i�ɁA
		��Ԏ�ʂ�ǉ����܂��B

	@return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B	
			-	-1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
			-	-2 ;	//	�N���b�v�{�[�h����̓ǂݍ��݂Ɏ��s���܂����B	
			-	-3 ;	//	�N���b�v�{�[�h�̓��e���s���ł��B
			-	-4 ;	//	CentDedRessyasyubetsu �̓��e���s���ł��B
	 */
	static int CentDedRessyasyubetsu_From_Cliboard( 
		Mui<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) ;



	/**
	  @return 
	 	�N���b�v�{�[�h�ɁA CentDedRessyasyubetsu �I�u�W�F�N�g��
	 	���e���i�[����Ă�����A�^��Ԃ��܂��B
	 */
	static bool CentDedRessyasyubetsu_IsClipboardFormatAvailable() ;

	/**
	  @return
	 	CentDedRessyaCont �I�u�W�F�N�g�̓��e��ێ�����
	 	�N���b�v�{�[�h�t�H�[�}�b�g�l��Ԃ��܂��B
	 */
	static UINT getCF_CentDedRessyaCont() ;

	/**
	�w�肳�ꂽ CentDedRessyaCont �I�u�W�F�N�g�̓��e���A
	�N���b�v�{�[�h�ɕۑ����܂��B
	 @param aCentDedRessyaCont [in]
		�w�I�u�W�F�N�g���w�肵�Ă��������B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B	
			-	-1 ;	//	aCentDedRessyaCont �̓��e���s���ł��B
			-	-11 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
	 */
	static int CentDedRessyaCont_To_Cliboard( 
		const CentDedRessyaCont& aCentDedRessyaCont ) ;

	/**
	�N���b�v�{�[�h�ɁA CentDedRessyaCont �I�u�W�F�N�g��
	���e���i�[����Ă�����A������擾���A
	pCentDedRessyaCont �ɒǉ����܂��B
	 @param pCentDedRessyaCont [in,out]
		���̊֐��͐���������A���� CentDedRessyaCont �R���e�i�̖�����
		�N���b�v�{�[�h�Ɋi�[����Ă����Ԃ�ǉ����܂��B
		���̃R���e�i�ɂ���܂Ŋi�[����Ă�����Ԃ́A�ێ����܂��B
		pCentDedRessyaCont �ɑ΂��Ă͂��炩���߁A
		�w��ԕ����x m_eRessyaHoukou ��
		�w�w�������x m_iEkiCount ��
		�������ݒ肳��Ă��Ȃ��Ă͂Ȃ�܂���B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B	
			-	-1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
			-	-2 ;	//	�N���b�v�{�[�h����̓ǂݍ��݂Ɏ��s���܂����B	
			-	-3 ;	//	�N���b�v�{�[�h�̓��e���s���ł��B
			-	-4 ;	//	CentDedRessyaCont �̓��e���s���ł��B
	 */
	static int CentDedRessyaCont_From_Cliboard( 
		CentDedRessyaCont* pCentDedRessyaCont ) ;

	/**
	  @return 
	 	�N���b�v�{�[�h�ɁA CentDedRessyaCont �I�u�W�F�N�g��
	 	���e���i�[����Ă�����A�^��Ԃ��܂��B
	 */
	static bool CentDedRessyaCont_IsClipboardFormatAvailable() ;

	///@}
public:
	// ********************************
	///@name CDiagramEditDoc-����
	// ********************************
	///@{
	/**
	 	�h�L�������g�̍X�V���s���܂��B
	 
	 	���̊֐��́A�ڍׂɂ͈ȉ��̂��Ƃ��s���܂��B
	 	
	 	- �P�D  �R�}���h�I�u�W�F�N�g pCmd �̎w��ɏ]���āA�h�L�������g
	 	m_CDedRosenFileData ���X�V���܂��B
	 	- �Q�D�@�X�V�t���O�̐ݒ� SetModifiedFlag( TRUE ) ���s���܂��B
	 	- �R�D  UpdateAllSubDocviews() �ŁA���ׂĂ� View �ɍX�V���s�킹�܂��B
	 	���̂Ƃ��A  pHint ������ pCmd ��n���܂��B�e View �́ApCmd �̓��e��
	 	���ƂɁA��ʍX�V�̏������s���܂��B
	 	- �S�D  pCmd �́A m_contUndo �ɕۑ����܂��B���̒l�́Aundo() �̍ۂ�
	 	�g���܂��B
	 */
	virtual int executeEditCmd( Ou< CRfEditCmd > pCmd ) ;
	
	/**
	 @return
		���[�g Document �ɑ΂���
		Undo ���\�Ȃ�^�ł��B
	*/
	virtual bool canUndo() ; 

	/**
	���[�g Document �ɑ΂���
	Undo �����s���A��������ׂẴr���[�ɓ`�B���܂��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	undo ��񂪂���܂���B
		-	-2 ;	//	undo �̎��s�Ɏ��s
	*/
	virtual int undo() ; 

	/**
	 @return
		���[�g Document �ɑ΂���
		Redo ���\�Ȃ�^�ł��B
	*/
	virtual bool canRedo() ; 

	/**
	���[�g Document �ɑ΂���
	Redo �����s���A��������ׂẴr���[�ɓ`�B���܂��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	redo ��񂪂���܂���B
		-	-2 ;	//	redo �̎��s�Ɏ��s
	 */
	virtual int redo() ; 

	///@}
	
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CDiagramEditDoc();
	DECLARE_DYNCREATE(CDiagramEditDoc)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

//�I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDiagramEditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CDiagramEditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	DECLARE_MESSAGE_MAP()

	//{{AFX_MSG(CDiagramEditDoc)
	afx_msg void OnFileSaveAs();
	//	[�t�@�C��]
	afx_msg void OnUpdateFileSaveAs(CCmdUI *pCmdUI);

	//	[�ҏW]
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditRedo(CCmdUI *pCmdUI);
	afx_msg void OnEditRedo();
	//}}AFX_MSG
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CDIAGRAMEDITDOC_H__A4879B96_62E6_4298_B7DB_8F991F72EC7F__INCLUDED_)
