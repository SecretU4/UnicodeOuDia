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
//	CRfEditCmd_DedRosenFileDataProp.h
//	$Id: CRfEditCmd_DedRosenFileDataProp.h 141 2012-10-20 08:03:25Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CRfEditCmd_DedRosenFileDataProp_h
#define  CRfEditCmd_DedRosenFileDataProp_h

#include "DedRosenFileData\EditCmd\CRfEditCmd.h"

namespace DedRosenFileData{ namespace EditCmd{

// ****************************************************************
//	CRfEditCmd_DedRosenFileDataProp
// ****************************************************************
/**
 * @brief
  CDedRosenFileData �I�u�W�F�N�g�̑���
�w�H���t�@�C���̃v���p�e�B�x�_�C�A���O�ōX�V�ł��鑮��
���㏑������ҏW����ł��B

 */
class CRfEditCmd_DedRosenFileDataProp :
	public CRfEditCmd
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 *	�V����
	 *	�H�����B
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 */
	std::string	m_strRosenName ;

	/**
	 *	�V����
	 *	�_�C���̋N�_�����ł��B
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 */
	CdDedJikoku	m_jikokuKitenJikoku ;

	/**
		�_�C���O�����̊���̉w�ԕ��B

		��Ԑݒ�̂Ȃ��w�Ԃ́A�_�C���O�����r���[��ł�
		�c�����̕����w�_�C���O�����G���e�B�e�BY���W�x�P��(�b)�Ŏw�肵�܂��B
	
		����l�� 60 �ł��B
		�R���X�g���N�^�ŏ���������܂��B���̒l�́A�_�C�A���O�\������
		�����l�Ƃ��Ďg���܂��B
		OnOK() �́A�_�C�A���O�̒l�ŏ㏑�����܂��B�N���X���[�U�[�́A
		 DoModal() �����^�[��������ɁA���̒l���Q�Ƃ��邱�Ƃ��ł��܂��B
	*/
	int	m_iDiagramDgrYZahyouKyoriDefault ;
	/**
	 *	�V����
	 *	DiagramEdit �̕\���Ɋ֌W����v���p�e�B��ێ�����
	 *	�P���f�[�^�N���X�ł��B
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 */
	CdDedDispProp	m_CdDedDispProp ;
	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
	 *	������Ԃł͋�B
	 *	execute() ���s������́Aexecute() ���s�����O�̒l�ƂȂ�܂��B
	 */
	std::string	m_strRosenNameOld ;

	/**
	 *	������Ԃł͋�B
	 *	execute() ���s������́Aexecute() ���s�����O�̒l�ƂȂ�܂��B
	 */
	CdDedJikoku	m_jikokuKitenJikokuOld ;

	/**
	 *	������Ԃł͋�B
	 *	execute() ���s������́Aexecute() ���s�����O�̒l�ƂȂ�܂��B
	 */
	int m_iDiagramDgrYZahyouKyoriDefaultOld ;

	/**
	 *	������Ԃł͋�B
	 *	execute() ���s������́Aexecute() ���s�����O�̒l�ƂȂ�܂��B
	 */
	CdDedDispProp	m_CdDedDispPropOld ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	 @param strRosenName [in]
		�V����
		�H�����B
		�R���X�g���N�^�Ō��܂�܂��B
	 @param jikokuKitenJikoku [in]
		�V����
		�_�C���̋N�_�����ł��B
		�R���X�g���N�^�Ō��܂�܂��B
	 @param iDiagramDgrYZahyouKyoriDefault [in]
		�_�C���O�����̊���̉w�ԕ��B
	 @param aCdDedDispProp [in]
		�V����
		DiagramEdit �̕\���Ɋ֌W����v���p�e�B��ێ�����
		�P���f�[�^�N���X�ł��B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	CRfEditCmd_DedRosenFileDataProp( 
		const std::string& strRosenName ,
		const CdDedJikoku& jikokuKitenJikoku , 
		int	iDiagramDgrYZahyouKyoriDefault ,
		const CdDedDispProp& aCdDedDispProp ) ;
	virtual ~CRfEditCmd_DedRosenFileDataProp() ;
	
public:
	// ********************************
	///@name	CRfEditCmd-����
	// ********************************
	///@{
	/**
	 *	CDedRosenFileData �I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���܂��B
	 *	�@�܂��A�ҏW����ɐ��������ꍇ�A this �́Aundo
	 *	�i�ҏW����̎������j���s���̂ɕK�v�ȃf�[�^���A
	 *	�����o�ϐ��ɕێ����܂��B
	 * @param pCDedRosenFileData [in,out]
	 *	���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	<H4>
	 *	�y�I�[�o���C�h�z
	 *	</H4>
	 *	pCDedRosenFileData �I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���Ă��������B
	 */
	virtual int execute( CDedRosenFileData* pCDedRosenFileData ) ;
	
	/**
	 *	�u this->execute() �ōs�����ҏW�����������
	 *	�i this->execute() �ŕҏW������s��������� CDedRosenFileData 
	 *	�I�u�W�F�N�g���A this->execute() ���s�����O�̏�Ԃ�
	 *	����j�v���߂̕ҏW�R�}���h�I�u�W�F�N�g�𐶐����܂��B
	 *
	 *	���̃����o�֐����Ԃ����I�u�W�F�N�g���g���� execute() ��
	 *	�Ăяo�����Ƃɂ��A this->execute() ����̏�Ԃ� CentDedRosen
	 *	 �I�u�W�F�N�g���A this->execute() ���O�̏�Ԃɖ߂����Ƃ��ł��܂��B
	 * @return
	 *	execute() �ōs�����ҏW������������A
	 *	 CDedRosenFileData �I�u�W�F�N�g�� execute() ���s�����O�̏�Ԃ�
	 *	���邽�߂̃R�}���h�I�u�W�F�N�g�𐶐����܂��B
	 *	<H4>
	 *	�y�I�[�o���C�h�z
	 *	</H4>
	 *	execute() �Ŏ��s�����ҏW���e�����ɖ߂��悤�ȃI�u�W�F�N�g��
	 *	�������ĕԂ��Ă��������B
	 */
	virtual Ou<CRfEditCmd> createUndoCmd()  ;
	
	///@}
public:
	// ********************************
	///@name CRfEditCmd_DedRosenFileDataProp-����
	// ********************************
	///@{
	std::string	getRosenName()const{	return m_strRosenName ;};
	CRfEditCmd_DedRosenFileDataProp& 
		setRosenName( const std::string& value )
	{
		m_strRosenName = value ; return *this ; 
	};
	CdDedJikoku	getKitenJikoku()const{	return m_jikokuKitenJikoku ;};
	CRfEditCmd_DedRosenFileDataProp& 
		setKitenJikoku( const CdDedJikoku& value )
	{
		m_jikokuKitenJikoku = value ; return *this ;
	};

	int	getDiagramDgrYZahyouKyoriDefault()const
	{	return m_iDiagramDgrYZahyouKyoriDefault ;};
	CRfEditCmd_DedRosenFileDataProp&
		setDiagramDgrYZahyouKyoriDefault( int value )
	{	m_iDiagramDgrYZahyouKyoriDefault = value ; return *this ;}

	
	
	CdDedDispProp	getCdDedDispProp()const{ return m_CdDedDispProp ;};
	CRfEditCmd_DedRosenFileDataProp& 
		setCdDedDispProp( const CdDedDispProp& value )
	{
		m_CdDedDispProp = value ;return *this ; 
	};
	///@}
};

} } // namespace EditCmd namespace DedRosenFileData

#endif /*CRfEditCmd_DedRosenFileDataProp_h*/
