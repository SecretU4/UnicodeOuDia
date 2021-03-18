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
/*
// ****************************************************************
//	CRfEditCmd_Eki.h
//	$Id: CRfEditCmd_Eki.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
*/
#ifndef  CRfEditCmd_Eki_h
#define  CRfEditCmd_Eki_h
/** @file */
#include "..\..\entDed\CentDedEkiCont.h"
#include "..\..\entDed\CentDedRosen.h"
#include "DedRosenFileData\EditCmd\CRfEditCmd.h"

namespace DedRosenFileData{ namespace EditCmd{

// ****************************************************************
//	CRfEditCmd_Eki
// ****************************************************************
/**
@brief
  CDedRosenFileData �I�u�W�F�N�g���� CentDedEki �I�u�W�F�N�g��
�ǉ��E�폜�̕ҏW����ł��B

  ���̃N���X�́A CDedRosenFileData �I�u�W�F�N�g���̉w��
�ǉ��E�u���E�폜���s���܂��B

�@�Ȃ��A�u���̓���́A�폜�ƒǉ��̑g�ݍ��킹�ŕ\�����܂��B

  �w�̍폜�́A�S��Ԃ̉w�����̍폜�𔺂��܂��B
���̂��߁Aundo �̂��߂ɂ� CentDedRosen ��ۑ�����K�v������܂��B

<h2>
�y�g����1-�u���Ώۂ͈̔͂ƁA�ǉ�����w���w��z
</h2>

(1)  1�Ԗڂ̃R���X�g���N�^���g�p���āA
�u���Ώۂ̉wIndex�͈̔͂ƁA�u����̉w��ݒ肵�Ă��������B

(2)�@execute() ���\�b�h�����s���āACDedRosenFileData �I�u�W�F�N�g��
�X�V���Ă��������B
�@(OuDia�ł͒ʏ�ACRfEditCmd::execute() �𒼐ڌĂяo������ɁA
CDiagramEditDoc::executeEditCmd  () ���g�p���āA�h�L�������g���X�V����
���܂��B����ɂ��ACDiagramEditDoc::undo() �����������삵�܂��B)

<h2>
�y�g����2-�u���Ώۂ͈̔͂̃A�C�e���̃R�s�[���擾��A�R�s�[��ҏW�z
</h2>

(1)�@2�Ԗڂ̃R���X�g���N�^���g�p���āA
�ҏW�Ώۂ̉wIndex�͈̔͂��w�肵�Ă��������B
�@���̃R���X�g���N�^�́A���̃I�u�W�F�N�g���ێ����� CentDedEkiCont
( m_CentDedEkiContSrc) �ɁA�w�肳�ꂽ�͈͂̉w���R�s�[���܂��B
�@(OuDia�ł́ACRfEditCmd_Eki �R���X�g���N�^�𒼐ڎg�p�������ɁA
 ViewEki::CWndDcdGridEki::createCmd() ��
 �C���X�^���X�𐶐����Ă��܂�)

(2)�@m_iIndexDst,m_iSizeDst,m_CentDedEkiContSrc ��ҏW���Ă��������B
�@m_CentDedEkiContSrc �̕ҏW�́A m_CaMuiSelect �A�_�v�^�����
�s���Ă��������B
( ViewEki::CWndDcdGridEki::createCmd() ��
�C���X�^���X�𐶐������ꍇ�A createCmd() ���\�b�h��
�E�C���h�E��ł̉w�̑I���󋵂��Am_CaMuiSelect �̑I����Ԃɔ��f�����܂��B
�@�N���X���[�U�[�́Am_CaMuiSelect �őI������Ă��� CentDedEki
�݂̂�Ώۂɂ��� �ҏW������s�����Ƃɂ��A �E�C���h�E�őI�����ꂽ
�w�݂̂�ύX���邱�Ƃ��ł��܂�)

(3)�@execute() ���\�b�h�����s���āACDedRosenFileData �I�u�W�F�N�g��
�X�V���Ă��������B
�@(OuDia�ł͒ʏ�ACRfEditCmd::execute() �𒼐ڌĂяo������ɁA
CDiagramEditDoc::executeEditCmd  () ���g�p���āA�h�L�������g���X�V����
���܂��B����ɂ��ACDiagramEditDoc::undo() �����������삵�܂��B)

 */
class CRfEditCmd_Eki : 
	public CRfEditCmd
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 	CentDedRosen �I�u�W�F�N�g��
	 	�ǉ��E�폜�ΏۂƂȂ� �w �C���f�N�X�B
	 
	 	INT_MAX �͖������w�肵�����̂Ƃ݂Ȃ��܂��B
	 
	 	�R���X�g���N�^�Ō��܂�܂��B
	*/
	int m_iIndexDst ;
	
	/**
	 	CentDedRosen �I�u�W�F�N�g��
	 	�폜�ΏۂƂȂ�w�̐��B
	 
	 	���̒l��0�̏ꍇ�́Aexecute() �� 
	 	m_CentDedEkiContSrc.size() ��
	 	CentDedEki �̒ǉ��������s���܂��B
	 
	 	���̒l�� m_CentDedEkiContSrc.size() �Ɠ������ꍇ�́A
	 	CentDedEki �̒u�������������s���܂��B
	 
	 	INT_MAX �́Am_iIndexDst ���疖���܂ł��w�肵�����̂Ƃ݂Ȃ��܂��B
	 	m_iIndexSrc �� m_iIndexDst �𗼕� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	 
	 	�R���X�g���N�^�Ō��܂�܂��B
	*/
	int m_iSizeDst ;
	
	/**
	 	CentDedRosen �I�u�W�F�N�g�ɑ΂��A
	 	�ǉ�����w��ێ�����R���e�i�B
	 	���̃R���e�i�̃T�C�Y�� 0 �̏ꍇ�́A
	 	execute() �� CentDedRosen �I�u�W�F�N�g����
	 	 m_iSizeDst �� CentDedEki �̍폜�������s���܂��B
	 
	 	�R���X�g���N�^�Ō��܂�܂��B
	*/
	CentDedEkiCont	m_CentDedEkiContSrc ;

	/**
	  m_CentDedEkiContSrc ���̃R���e�i�̈ꕔ�̗v�f��I�������`�́A
	�����R���e�i�C���^�[�t�F�[�X���쐬���܂��B
	  ���̃C���X�^���X�́A m_CentDedEkiContSrc ��Adaptee��
	���܂��B

	�@�R���X�g���N�^�Ő������ꂽ����́Am_CentDedEkiContSrc ����
	 ���ׂĂ̗v�f��I�����Ă��܂��B

	  execute() ���\�b�h�̓���́A���̃C���X�^���X�̉e�����󂯂܂���B

	<h2>
	�yViewEki::CWndDcdGridEki::createCmd() ��
	�C���X�^���X�𐶐������ꍇ�z
	</h2>

	 ViewEki::CWndDcdGridEki::createCmd() ��
	�C���X�^���X�𐶐������ꍇ�A createCmd() ���\�b�h��
	�E�C���h�E��ł̉w�̑I���󋵂��A���̃I�u�W�F�N�g�̑I����Ԃɔ��f�����܂��B
	���ɁA�E�C���h�E��Ŕ�A�������I�𑀍���s���Ă���ꍇ�AcreateCmd() ���\�b�h���A
	��������C���X�^���X�� m_CaMuiSelect �ɂ́A�I���E��I�������݂��܂��B
	
	�@�N���X���[�U�[�́Am_CaMuiSelect �őI������Ă��� CentDedEki
	�݂̂�Ώۂɂ��� �ҏW������s�����Ƃɂ��A �E�C���h�E�őI�����ꂽ
	�w�݂̂�ύX���邱�Ƃ��ł��܂��B
	*/
	CaMuiSelect<CentDedEki>	m_CaMuiSelect ;

	/**
		[�w�������w�����`���ɐ��K������]�ݒ�B
	*/
	bool m_bAdjustByEkijikokukeisiki ;

	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
	 	������Ԃł� NULL �B
	 	execute() �ŁA
	 	�v�f��u�����E�܂��͒ǉ���
	 	�s������́Aexecute() �ō폜�����v�f��
	 	�ێ����܂��B
	 	�v�f������������悤�ȑ�����s�����ꍇ�́A
	 	���̃R���e�i�͐�������܂���B
	 */
	CentDedEkiCont*	m_pCentDedEkiContOld ;
	/**
	 	������Ԃł� NULL �B
	 	execute() ��
	 	�v�f��������������́A
	 	�u�������O�� CentDedRosen ��
	 	�ێ����܂��B

		(�w�̌����ɂ���āA��Ԃ̉w�����������܂��B
		Undo�ɔ����āA�S�_�C���E�S��Ԃ̉w������
		�ۑ����Ȃ��Ă͂Ȃ�܂���)�B
	 	
		�܂��A[�w�������w�����`���ɐ��K������]�ꍇ�́A
		�S�Ă̏ꍇ(�v�f�̒u�������E�ǉ��E����)�ɂ����āA
		�u�������O�� CentDedRosen ��ێ����܂��B
		
		�v�f��u�����E�ǉ����s�����ꍇ�́A
	 	���̃R���e�i�͐�������܂���B
	 */
	CentDedRosen*	m_pCentDedRosen ;
	///@}

// ********************************
//	�R���X�g���N�^
// ********************************
public:
	/**
	 ���ׂĂ̑������A�����Ŏw�肵�܂��B

	@param iIndexDst [in]
		CentDedRosen �I�u�W�F�N�g��
		�ǉ��E�폜�ΏۂƂȂ�w�C���f�N�X�B
	@param iSizeDst [in]
		CentDedRosen �I�u�W�F�N�g��
		�폜�ΏۂƂȂ�w�̐��B@n
		���̒l��0�̏ꍇ�́Aexecute() �� 
		m_CentDedRessyaContSrc.size() ��
		�w�̒ǉ��������s���܂��B
	@param aCentDedEkiContSrc [in]
		CentDedRosen �I�u�W�F�N�g�ɑ΂��A
		�ǉ�����w��ێ�����R���e�i�B
		���̃R���e�i�̃T�C�Y�� 0 �̏ꍇ�́A
		execute() �� CentDedRosen �I�u�W�F�N�g����
		 m_iSizeDst �̉w�̍폜�������s���܂��B@n
		���̃R���e�i�Ɋi�[����I�u�W�F�N�g�́A�w���� CentDedRosen �Ɠ�����
		�Ȃ��Ă͂Ȃ�܂���B
	@param bAdjustByEkijikokukeisiki [in]
		[�w�������w�����`���ɐ��K������]�ݒ�B
	*/
	CRfEditCmd_Eki( 
		int iIndexDst ,
		int iSizeDst ,
		const CentDedEkiCont& aCentDedEkiContSrc ,
		bool bAdjustByEkijikokukeisiki );

	/**
	 m_CentDedEkiContSrc ���A
	�w�肳�ꂽCDedRosenFileData �́A�w��͈̔͂̉w�ŏ��������܂��B
	
	@param aCDedRosenFileData [in]
		�ҏW�Ώۂ� CDedRosenFileData ���w�肵�Ă��������B
	@param iIndexDst [in]
		�ҏW�Ώۂ̉w�̐擪�C���f�N�X���w�肵�Ă��������B
	@param iSizeDst [in]
		�ҏW�Ώۂ̉w�̐����w�肵�Ă��������B
	@param bAdjustByEkijikokukeisiki [in]
		[�w�������w�����`���ɐ��K������]�ݒ�B

 	���̃R���X�g���N�^�́A m_CentDedEkiContSrc ��
	aCDedRosenFileData ���� iIndex ���� iSize �̉w�ŏ��������܂��B

	���������āA���̃R���X�g���N�^�Ő��������I�u�W�F�N�g��
	execute() �����s���Ă��A�h�L�������g�͕ω����܂���B

	���̃R���X�g���N�^�ŃI�u�W�F�N�g�𐶐�������́A
	���\�b�h�� m_iIndexDst , m_iSizeDst ,
	m_CentDedEkiContSrc��ҏW���Ă���A
	execute() �����s���Ă��������B
	m_CentDedRessyaContSrc �̕ҏW�́A m_CaMuiSelect �A�_�v�^��
	�g�p���Ă��������B
	*/
	CRfEditCmd_Eki( 
		const CDedRosenFileData& aCDedRosenFileData ,
		int iIndexDst , 
		int iSizeDst ,
		bool bAdjustByEkijikokukeisiki );
	

	virtual ~CRfEditCmd_Eki() ; 
	
	
 public:
	// ********************************
	///@name	CRfEditCmd-����
	// ********************************
	///@{
	/**
	 CDedRosenFileData �I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���܂��B
	 �܂��A�ҏW����ɐ��������ꍇ�A this �́Aundo
	�i�ҏW����̎������j���s���̂ɕK�v�ȃf�[�^���A
	�����o�ϐ��ɕێ����܂��B
	  @param pCDedRosenFileData [in,out]
		���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	m_iIndexDst �̒l���s���ł��B
		-	-11 ;	//	�v�f�̍폜�Ɏ��s���܂����B
		-	-12 ;	//	�v�f�̒ǉ��Ɏ��s���܂����B
		-	-13 ;	//	�v�f�̒u�������Ɏ��s���܂����B
	 
	<H4>
	�y�I�[�o���C�h�z
	</H4>
		pCDedRosenFileData �I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���Ă��������B
	 */
	virtual int execute( CDedRosenFileData* pCDedRosenFileData ) ;
	
	/**
	�u this->execute() �ōs�����ҏW�����������
	�i this->execute() �ŕҏW������s��������� CDedRosenFileData 
	�I�u�W�F�N�g���A this->execute() ���s�����O�̏�Ԃ�
	����j�v���߂̕ҏW�R�}���h�I�u�W�F�N�g�𐶐����܂��B

	���̃����o�֐����Ԃ����I�u�W�F�N�g���g���� execute() ��
	�Ăяo�����Ƃɂ��A this->execute() ����̏�Ԃ� CentDedRosen
	 �I�u�W�F�N�g���A this->execute() ���O�̏�Ԃɖ߂����Ƃ��ł��܂��B
	 
	 @return
		execute() �ōs�����ҏW������������A
		 CDedRosenFileData �I�u�W�F�N�g�� execute() ���s�����O�̏�Ԃ�
		���邽�߂̃R�}���h�I�u�W�F�N�g�𐶐����܂��B
	<H4>
	�y�I�[�o���C�h�z
	</H4>
	 execute() �Ŏ��s�����ҏW���e�����ɖ߂��悤�ȃI�u�W�F�N�g��
	�������Ă��������B
	 */
	virtual Ou<CRfEditCmd> createUndoCmd()  ;
	///@}

public:
	// ********************************
	///@name CRfEditCmd_Eki-����
	// ********************************
	///@{
	int getIndexDst()const{	return m_iIndexDst ; } ;
	CRfEditCmd_Eki& setIndexDst( int value )
	{
		m_iIndexDst = value ;	return *this ; 
	};
	int getSizeDst()const{	return m_iSizeDst ; } ;
	CRfEditCmd_Eki& setSizeDst( int value )
	{
		m_iSizeDst = value ;	return *this ; 
	};
	
	const CentDedEkiCont* getCentDedEkiContSrc()const
	{
		return &m_CentDedEkiContSrc ; 
	} ;

	bool getAdjustByEkijikokukeisiki()const
	{	return m_bAdjustByEkijikokukeisiki ;};
	CRfEditCmd_Eki& setAdjustByEkijikokukeisiki( bool value )
	{	m_bAdjustByEkijikokukeisiki = value ; return *this ;};

	/**
	@return
		�w�̑I�����s���A�_�v�^�ւ̃C���^�[�t�F�[�X��Ԃ��܂��B
	*/
	CaMuiSelect<CentDedEki>* getCaMuiSelect()
	{
		return &m_CaMuiSelect ;
	}
		
	/**
	@return
		�w�̑I�����s���A�_�v�^�ւ̃C���^�[�t�F�[�X��Ԃ��܂��B
	*/
	const CaMuiSelect<CentDedEki>* getCaMuiSelect()const 
	{
		return &m_CaMuiSelect ;
	}
	///@}
};

} } //namespace EditCmd namespace DedRosenFileData


#endif /*CRfEditCmd_Eki_h*/
