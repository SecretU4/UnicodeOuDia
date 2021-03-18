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
//	CRfEditCmd_Ressya.h
//	$Id: CRfEditCmd_Ressya.h 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
#ifndef  CRfEditCmd_Ressya_h
#define  CRfEditCmd_Ressya_h
/** @file */

#include "DedRosenFileData\EditCmd\CRfEditCmd.h"
#include "NsMu\CaMuiSelect.h"

namespace DedRosenFileData{ namespace EditCmd{

// ****************************************************************
//	CRfEditCmd_Ressya
// ****************************************************************
/**
@brief
 	  CDedRosenFileData �I�u�W�F�N�g���� CentDedRessya �I�u�W�F�N�g��
 	�ǉ��E�폜�̕ҏW����ł��B
 	
  ���̃N���X�́A CDedRosenFileData �I�u�W�F�N�g����
�w��̃_�C���E�w��̗�ԕ����̕����̗�Ԃ̒ǉ��E�u���E�폜��
�s���܂��B

�@�Ȃ��A�u���̓���́A�폜�ƒǉ��̑g�ݍ��킹�ŕ\�����܂��B

<h2>
�y�g����1-�u���Ώۂ͈̔͂ƁA�ǉ������Ԃ��w��z
</h2>

(1)  1�Ԗڂ̃R���X�g���N�^���g�p���āA�ҏW�Ώۂ̃_�C��Index�E��ԕ����ƁA
�u���Ώۂ̗��Index�͈̔͂ƁA�u����̗�Ԃ�ݒ肵�Ă��������B

(2)�@execute() ���\�b�h�����s���āACDedRosenFileData �I�u�W�F�N�g��
�X�V���Ă��������B
�@(OuDia�ł͒ʏ�ACRfEditCmd::execute() �𒼐ڌĂяo������ɁA
CDiagramEditDoc::executeEditCmd  () ���g�p���āA�h�L�������g���X�V����
���܂��B����ɂ��ACDiagramEditDoc::undo() �����������삵�܂��B)

<h2>
�y�g����2-�u���Ώۂ͈̗̔͂�Ԃ̃R�s�[���擾��A�R�s�[��ҏW�z
</h2>

(1)�@2�Ԗڂ̃R���X�g���N�^���g�p���āA�ҏW�Ώۂ̃_�C��Index�E��ԕ����ƁA
�ҏW�Ώۂ̗��Index�͈̔͂��w�肵�Ă��������B
�@���̃R���X�g���N�^�́A���̃I�u�W�F�N�g���ێ����� CentDedRessyaCont
( m_CentDedRessyaContSrc) �ɁA�w�肳�ꂽ�͈̗͂�Ԃ��R�s�[���܂��B
�@(OuDia�ł́ACRfEditCmd_Ressya �R���X�g���N�^�𒼐ڎg�p�������ɁA
 ViewJikokuhyou::WndJikokuhyou::CWndJikokuhyou::createCmd() ��
 �C���X�^���X�𐶐����Ă��܂�)

(2)�@m_iIndexDst,m_iSizeDst,m_CentDedRessyaContSrc ��ҏW���Ă��������B
�@m_CentDedRessyaContSrc �̕ҏW�́A m_CaMuiSelect �A�_�v�^�����
�s���Ă��������B
( ViewJikokuhyou::WndJikokuhyou::CWndJikokuhyou::createCmd() ��
�C���X�^���X�𐶐������ꍇ�A createCmd() ���\�b�h��
�E�C���h�E��ł̗�Ԃ̑I���󋵂��Am_CaMuiSelect �̑I����Ԃɔ��f�����܂��B
�@�N���X���[�U�[�́Am_CaMuiSelect �őI������Ă��� CentDedRessya
�݂̂�Ώۂɂ��� �ҏW������s�����Ƃɂ��A �E�C���h�E�őI�����ꂽ
��Ԃ݂̂�ύX���邱�Ƃ��ł��܂�)

(3)�@execute() ���\�b�h�����s���āACDedRosenFileData �I�u�W�F�N�g��
�X�V���Ă��������B
�@(OuDia�ł͒ʏ�ACRfEditCmd::execute() �𒼐ڌĂяo������ɁA
CDiagramEditDoc::executeEditCmd  () ���g�p���āA�h�L�������g���X�V����
���܂��B����ɂ��ACDiagramEditDoc::undo() �����������삵�܂��B)


 */
class CRfEditCmd_Ressya : 
	public CRfEditCmd
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
 	�ҏW�Ώۂ̃_�C���̃C���f�N�X�B
 
 	�R���X�g���N�^�Ō��܂�܂��B
	 */
	int m_iDiaIndex ;
	
	
	/**
	 	�ҏW�Ώۂ̗�ԕ����B
	 
	 	�R���X�g���N�^�Ō��܂�܂��B
	 */
	ERessyahoukou m_ERessyahoukou ;
	
	/**
	 	CentDedRosen �I�u�W�F�N�g��
	 	�_�C���C���f�N�X m_iDiaIndex �E
	 	�ҏW�Ώۂ̗�ԕ��� m_ERessyahoukou ���ł́A
	 	�ǉ��E�폜�ΏۂƂȂ��ԃC���f�N�X�B
	 
	 	INT_MAX �͖������w�肵�����̂Ƃ݂Ȃ��܂��B
	 */
	int m_iIndexDst ;
	
	/**
	 	CentDedRosen �I�u�W�F�N�g�̃_�C���C���f�N�X m_iDiaIndex �E
	 	�ҏW�Ώۂ̗�ԕ��� m_ERessyahoukou ���ł́A
	 	�폜�ΏۂƂȂ��Ԃ̐����w�肵�Ă��������B
	 	���̒l��0�̏ꍇ�́Aexecute() �� 
	 	m_CentDedRessyaContSrc.size() ��
	 	��Ԃ̒ǉ��������s���܂��B
	 
	 	INT_MAX �́Am_iIndexDst ���疖���܂ł��w�肵�����̂Ƃ݂Ȃ��܂��B
		m_iIndexSrc �� m_iIndexDst �𗼕� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	 */
	int m_iSizeDst ;
	
	/**
	 	CentDedRosen �I�u�W�F�N�g�ɑ΂��A
	 	�ǉ������Ԃ�ێ������ԃR���e�i�B
	 	���̃R���e�i�̃T�C�Y�� 0 �̏ꍇ�́A
	 	execute() �� CentDedRosen �I�u�W�F�N�g����
	 	 m_iSizeDst �̗�Ԃ̍폜�������s���܂��B

		���̃I�u�W�F�N�g���̗�Ԃ̕ҏW�́A
		muiCentDedRessya() ���\�b�h�Ŏ擾����
		Mui<CentDedRessya> ����čs���Ă��������B
	*/
	CentDedRessyaCont	m_CentDedRessyaContSrc ;
	
	/**
	  m_CentDedRessyaContSrc ���̃R���e�i�̈ꕔ�̗v�f��I�������`�́A
	�����R���e�i�C���^�[�t�F�[�X���쐬���܂��B
	  ���̃C���X�^���X�́A m_CentDedRessyaContSrc ��Adaptee��
	���܂��B

	�@�R���X�g���N�^�Ő������ꂽ����́Am_CentDedRessyaContSrc ����
	 ���ׂĂ̗v�f��I�����Ă��܂��B

	  execute() ���\�b�h�̓���́A���̃C���X�^���X�̉e�����󂯂܂���B

	<h2>
	�yViewJikokuhyou::WndJikokuhyou::CWndJikokuhyou::createCmd() ��
	�C���X�^���X�𐶐������ꍇ�z
	</h2>

	 ViewJikokuhyou::WndJikokuhyou::CWndJikokuhyou::createCmd() ��
	�C���X�^���X�𐶐������ꍇ�A createCmd() ���\�b�h��
	�E�C���h�E��ł̗�Ԃ̑I���󋵂��A���̃I�u�W�F�N�g�̑I����Ԃɔ��f�����܂��B
	���ɁA�E�C���h�E��Ŕ�A�������I�𑀍���s���Ă���ꍇ�AcreateCmd() ���\�b�h���A
	��������C���X�^���X�� m_CaMuiSelect �ɂ́A�I���E��I�������݂��܂��B
	
	�@�N���X���[�U�[�́Am_CaMuiSelect �őI������Ă��� CentDedRessya
	�݂̂�Ώۂɂ��� �ҏW������s�����Ƃɂ��A �E�C���h�E�őI�����ꂽ
	��Ԃ݂̂�ύX���邱�Ƃ��ł��܂��B
	*/
	CaMuiSelect<CentDedRessya>	m_CaMuiSelect ;
	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
	 	������Ԃł� NULL �B
	 	execute() ���s������́Aexecute() �ō폜������Ԃ�
	 	�ێ����܂��B
	 */
	CentDedRessyaCont*	m_pCentDedRessyaContOld ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************

	/**
	 ���ׂĂ̑������A�����Ŏw�肵�܂��B
	  @param iDiaIndex [in]
	 	�ҏW�Ώۂ̃_�C���̃C���f�N�X�B
	  @param eERessyahoukou [in]
	 	�ҏW�Ώۂ̗�ԕ����B
	  @param iIndexDst [in]
	 	CentDedRosen �I�u�W�F�N�g��
	 	�_�C���C���f�N�X m_iDiaIndex �E
	 	�ҏW�Ώۂ̗�ԕ��� m_ERessyahoukou ���ł́A
	 	�ǉ��E�폜�ΏۂƂȂ��ԃC���f�N�X�B
	  @param iSizeDst [in]
	 	CentDedRosen �I�u�W�F�N�g�̃_�C���C���f�N�X m_iDiaIndex �E
	 	�ҏW�Ώۂ̗�ԕ��� m_ERessyahoukou ���ł́A
	 	�폜�ΏۂƂȂ��Ԃ̐����w�肵�Ă��������B
	 	���̒l��0�̏ꍇ�́Aexecute() �� 
	 	m_CentDedRessyaContSrc.size() ��
	 	��Ԃ̒ǉ��������s���܂��B
	  @param aCentDedRessyaContSrc [in]
	 	CentDedRosen �I�u�W�F�N�g�ɑ΂��A
	 	�ǉ������Ԃ�ێ������ԃR���e�i�B
	 	���̃R���e�i�̃T�C�Y�� 0 �̏ꍇ�́A
	 	execute() �� CentDedRosen �I�u�W�F�N�g����
	 	 m_iSizeDst �̗�Ԃ̍폜�������s���܂��B
	 */
	CRfEditCmd_Ressya( 
		int iDiaIndex ,
		ERessyahoukou eERessyahoukou ,
		int iIndexDst , 
		int iSizeDst , 
		const CentDedRessyaCont& aCentDedRessyaContSrc ) ;

	/**
	 m_CentDedRessyaContSrc ���A
	�w�肳�ꂽ CDedRosenFileData �́A�w��͈̗̔͂�Ԃŏ��������܂��B
	
	@param aCDedRosenFileData [in]
		�ҏW�Ώۂ� CDedRosenFileData ���w�肵�Ă��������B
	@param iDiaIndex [in]
	 	�ҏW�Ώۂ̃_�C���̃C���f�N�X�B
	@param eRessyahoukou [in]
		��ԕ���
	@param iIndex [in]
		�ҏW�Ώۂ̗�Ԃ̐擪�C���f�N�X���w�肵�Ă��������B
	@param iSize [in]
		�ҏW�Ώۂ̗�Ԃ̐����w�肵�Ă��������B

 	���̃R���X�g���N�^�́A m_CentDedRessyaContSrc ��
	aCDedRosenFileData ���́A iDiaIndex, eRessyahoukou ��
	�w�肳�ꂽ CentDedRessyaCont �́A
	iIndex ���� iSize �{�̗�Ԃŏ��������܂��B

	���������āA���̃R���X�g���N�^�Ő��������I�u�W�F�N�g��
	execute() �����s���Ă��A�h�L�������g�͕ω����܂���B

	���̃R���X�g���N�^�ŃI�u�W�F�N�g�𐶐�������́A
	���\�b�h�� m_iIndexDst , m_iSizeDst ,
	m_CentDedRessyaContSrc ��ҏW���Ă���A
	execute() �����s���Ă��������B
	m_CentDedRessyaContSrc �̕ҏW�́A m_CaMuiSelect �A�_�v�^��
	�g�p���Ă��������B

		
	*/
	CRfEditCmd_Ressya( 
		const CDedRosenFileData& aCDedRosenFileData ,
		int iDiaIndex ,
		ERessyahoukou eRessyahoukou , 
		int iIndex , 
		int iSize );

	virtual ~CRfEditCmd_Ressya() ;

 public:
	// ********************************
	///@name CRfEditCmd-����
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
	 	-	-2 ;	//	m_iDiaIndex �̒l���s���ł��B
	 	-	-11 ;	//	�v�f�̍폜�Ɏ��s���܂����B
	 	-	-12 ;	//	�v�f�̒ǉ��Ɏ��s���܂����B
	 
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
	///@name CRfEditCmd_Ressya-����
	// ********************************
	///@{
	
	int getDiaIndex()const{	return m_iDiaIndex ;};

	ERessyahoukou getRessyahoukou()const{ return m_ERessyahoukou ;};
	int getIndexDst()const{	return m_iIndexDst ;};
	CRfEditCmd_Ressya& setIndexDst( int value )
	{
		m_iIndexDst = value ;	return *this ; 
	};
	int getSizeDst()const{	return m_iSizeDst ;};
	CRfEditCmd_Ressya& setSizeDst( int value )
	{
		m_iSizeDst = value ;	return *this ; 
	};

	const CentDedRessyaCont* getCentDedRessyaContSrc()const
	{
		return &m_CentDedRessyaContSrc ;
	}

	/**
	@return
		m_CentDedRessyaContSrc ���̗�Ԃ��Q�Ƃ��邽�߂�
		Mu<const CentDedRessya*> �C���^�[�t�F�[�X��Ԃ��܂��B
	*/
	const Mu<const CentDedRessya*>* muCentDedRessya()const
	{
		return ((const CentDedRessyaCont&)m_CentDedRessyaContSrc).getMuPtr() ;
	}

	/**
	@return
		��Ԃ̑I�����s���A�_�v�^�ւ̃C���^�[�t�F�[�X��Ԃ��܂��B
	*/
	CaMuiSelect<CentDedRessya>* getCaMuiSelect()
	{
		return &m_CaMuiSelect ;
	}
		
	/**
	@return
		��Ԃ̑I�����s���A�_�v�^�ւ̃C���^�[�t�F�[�X��Ԃ��܂��B
	*/
	const CaMuiSelect<CentDedRessya>* getCaMuiSelect()const 
	{
		return &m_CaMuiSelect ;
	}
		

	///@}
};

} } // namespace EditCmd namespace DedRosenFileData


#endif /*CRfEditCmd_Ressya_h*/
