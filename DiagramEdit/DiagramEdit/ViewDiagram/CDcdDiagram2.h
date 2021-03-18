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
//	CDcdDiagram2.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdDiagram2_h
#define  CDcdDiagram2_h

#include "CDcdDiagram.h"
#include "DcDraw\CDcdText.h"

namespace ViewDiagram{

// ****************************************************************
//	CDcdDiagram2
// ****************************************************************
/**
	@brief
	�y�T�v�z
	�w�_�C���O�����G���e�B�e�B�N���X�Q�x�̑��������ƂɁA IfDcdTarget 
	�I�u�W�F�N�g�Ɂw�_�C���O�����x��`�悵�܂��B
	
	���̃N���X�́A
	- �_�C���O�����̃O���t����
	- �㑤�̎��̕\��
	- �����̉w���\��

	���AIfDcdTarget �I�u�W�F�N�g�̗̈�̑S�ʂɕ`�悵�܂��B

	���̂����́w�_�C���O�����̃O���t�����x�́ACDcdDiagram��
	�g���ĕ`�悵�܂��B���̃N���X�̃I�u�W�F�N�g�́A CDcdDiagram ���܂��܂��B
	��܂��Ă��� CDcdDiagram �̑����́A���̃N���X�̃��\�b�h����ݒ肷�邱�Ƃ�
	�ł��܂��B
	
	
	���̃N���X�̃I�u�W�F�N�g�́A�w�_�C���O�����_�C���x CentDedDgrDia 
	�I�u�W�F�N�g�Ɗ֘A�������܂��B
	
	<H4>
	�y�g�����z
	</H4>
	  �ʏ�A���̃N���X�̃I�u�W�F�N�g�́A�_�C���O������\������
	�E�C���h�E����܂��邱�ƂɂȂ�܂��B

	�P�D  ���̃N���X�̃I�u�W�F�N�g�𐶐�����O�ɁA
	 CentDedDgrDia �I�u�W�F�N�g�𐶐����A CentDedDgrDia::readCentDedDia() ��
	CentDedDia �̓��e��ǂݍ��܂��Ă����ĉ������B
	
	�Q�D  ���̃N���X�̃I�u�W�F�N�g�𐶐����Ă��������B�R���X�g���N�^�ł́A
	�P�D�Ő������� CentDedDgrDia �I�u�W�F�N�g���w�肵�܂��B����ɂ��A
	���������I�u�W�F�N�g�́A CentDedDgrDia �I�u�W�F�N�g�Ƃ̊֘A���m�����܂�
	�i setCentDedDgrDia() �ŁA���Ƃ���֘A���m�����邱�Ƃ��ł��܂��B

	�R�D  �\���Ɋւ���e�푮�����w�肵�ĉ������B
	�R���X�g���N�^�� CdDedDispProp �I�u�W�F�N�g�������ɓn�����A
	readCdDedDispProp() ���g���ƁA�\���Ɋւ��鑮������x�ɐݒ肷�邱�Ƃ�
	�ł��܂��B
	
	�S�D  �\���Ɋւ��鑮���̂����ACdDedDispProp �Ɋi�[����Ȃ�����
		CDcdDiagram::m_posPosDgr,
		CDcdDiagram::m_dDcdPerDgrX,
		CDcdDiagram::m_dDcdPerDgrY
		CDcdDiagram::m_idxVlineMode , 
		CDcdDiagram::m_bDisplayRessyasenKudari , 
		CDcdDiagram::m_bDisplayRessyasenNobori ,
		CDcdDiagram::m_eStopMarkDraw
		CDcdDiagram2::m_bHideIppanekiEkimei
	���w�肵�ĉ������B
	
	�T�D  ���Ƃ́A IfDcDraw::DcDraw() ���\�b�h�ŁA�_�C���O������`�悷�邱�Ƃ�
	�ł��܂��B
	
*/
class CDcdDiagram2 : public IfDcDraw 
{
public:
	// ********************************
	///@name �萔
	// ********************************
	///@{
	/** 
	@return
		����� �w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐� 
		��Ԃ��܂��B
	*/
	static double DEFAULT_DCD_PER_DGR_X()
	{	return CDcdDiagram::DEFAULT_DCD_PER_DGR_X() ;}; 
	/** 
	@see DEFAULT_DCD_PER_DGR_X 
	*/
	static double DEFAULT_DCD_PER_DGR_Y()
	{	return CDcdDiagram::DEFAULT_DCD_PER_DGR_Y() ;};
	///@}
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	///@}
private:
	// ********************************
	///@name ����-CdDedDispProp ����ǂݍ��݉\
	// ********************************
	///@{
	/**
	 	�_�C����ʉw���t�H���g�B
		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaEkimeiFont ;

	/**
		 �_�C����ʎ����t�H���g�B
		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaJikokuFont ;

	
	/**
		 �_�C����ʕ����F�B
		�K��l�́A���B
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �����Ƃ�
		readCdDedDispProp() �Ō��܂�܂��B
	 */
	CdColorProp	m_colorDiaMojiColor ;

	/**
		�w�����̕���ێ����܂��B
		�P�ʂ́A�S�p�ł̕������ł��B
		�܂�A�w�����̕��́A
	
			�����̍��� �~ m_iEkimeiLength 
		
		�ƂȂ�܂��B
		�f�t�H���g�l�� 6 �Ƃ��܂��B�ŏ��l�� 1 �ł��B
	 */
	int m_iEkimeiLength ;


	///@}
	// ********************************
	///@name ����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
	///@{
	/**
		��ʉw�̉w���\�����B���w��ł��B
		- false ;	//	���ׂẲw����\�����܂��B(default)
		- true ;	//	��ʉw�̉w����\�����܂���B
	*/
	bool m_bHideIppanekiEkimei ;
	///@}
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		�w�_�C���O�����G���e�B�e�B�N���X�Q�x�̑��������ƂɁA IfDcdTarget 
		�I�u�W�F�N�g�Ɂw�_�C���O�����x��`�悵�܂��B
		
		���̃N���X�́A�_�C���O�����̃O���t����������`�悵�܂��B
		�g�O�̎��\���E	�w���\���͕`�悵�܂���B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́Athis �ɂ���܂��B
		���̃I�u�W�F�N�g�́A�R���X�g���N�^�Ő����E�f�X�g���N�^�Ŕj�����܂��B
	 */
	CDcdDiagram*	m_pCDcdDiagram ;
	///@}	

protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	 @return
		�ׂ��r���́A���̑�����Ԃ��܂��B
	 */
	CdDcdFreeLineProp	getCdLinePropNormal()const;
	/**
	 @return
		�����r���́A���̑�����Ԃ��܂��B
	 */
	CdDcdFreeLineProp	getCdLinePropBold()const;


	/**
	 @return
		���̕\�����s�����߂́A
		DcDraw �I�u�W�F�N�g�𐶐����ĕԂ��܂��B
	 */
	CDcdText	getCDcdTextJikoku()const ;
	/**
	 @return
		�w���̕\�����s�����߂́A
		DcDraw �I�u�W�F�N�g�𐶐����ĕԂ��܂��B
	 */
	CDcdText	getCDcdTextEkimei()const ;


	///@}	
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	
	/**
	 @param pCentDedDgrDia [in]
		�w�_�C���O�����_�C���x�I�u�W�F�N�g�ł��B
		\n this �́A���̃I�u�W�F�N�g����_�C���O�����̏����擾���A
		�`����s���܂��B
		\n ���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this �̔j������������܂�
		�������Ȃ��Ă͂Ȃ�܂���B
	 @param aCdDedDispProp [in]
		���̃R���X�g���N�^�́A CdDedDispProp �I�u�W�F�N�g�̑�������A
		�_�C���O�����̊e���̐F��t�H���g�̑��������肵�܂��B
	 @see setCdDedDispProp() 
	 */
	CDcdDiagram2( 
		CentDedDgrDia*	pCentDedDgrDia , 
		const CdDedDispProp& aCdDedDispProp ) ;
	/**
		���̃R���X�g���N�^���g�����ꍇ�́A
		 setCentDedDgrDia() �ŁA CentDedDgrDia �I�u�W�F�N�g�Ƃ̊֘A��
		�m�����Ȃ��Ă͂Ȃ�܂���B
	 */
	CDcdDiagram2() ; 
	virtual ~CDcdDiagram2() ;
	
public:
	// ********************************
	///@name IfDcDraw
	// ********************************
	///@{
	/**
	 	�`���v�����܂��B
	 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	 @param pIfDcdTarget  [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 @return
	 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	
		�y�I�[�o���C�h�z
		�_�C���O�����̕`����s���܂��B
	 */
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 	���̃I�u�W�F�N�g���`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 	���̑傫���𒲂ׂ邱�Ƃ��ł��܂��B
	 	�֐��Ăяo������������ IfDcDraw �I�u�W�F�N�g��`�悷��ꍇ�ɂ́A
	 	�֐��Ăяo�����́A���̊֐��ŃA�C�e���̑傫���𒲂ׂāA
	 	�K�؂ȃ��C�A�E�g���l���Ă���ADcDraw() �����s���邱�Ƃ��ł��܂��B
	 @param pIfDcdTarget [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 @param pCdDcdSizeXy [out]
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 	���̊֐��͂��̃A�h���X�ɁA���̃A�C�e���̃T�C�Y��Ԃ��܂��B
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��Ȃ��ꍇ�́A
	 	���̒l�͕s��ł��B
	 @return
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��āA
	 	���̑傫���� *pCdDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	 	�����łȂ��ꍇ�́A�U�ł��B
	
		�y�I�[�o���C�h�z
		���̃N���X�ł̓T�|�[�g���܂���Bfalse��Ԃ��܂��B
	 */
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	
	///@}
public:
	// ********************************
	///@name CDcdDiagram-�֘A
	// ********************************
	///@{
	CentDedDgrDia*	getCentDedDgrDia() ;
	CDcdDiagram2& setCentDedDgrDia( CentDedDgrDia* value ) ;
	///@}

public:
	// ********************************
	///@name CDcdDiagram-����-CdDedDispProp ����ǂݍ��݉\
	// ********************************
	///@{
	CdFontProp	getDiaRessyaFont()const ;
	CDcdDiagram2& setDiaRessyaFont( const CdFontProp& value ) ;
	CdColorProp	getDiaHaikeiColor()const ;
	CDcdDiagram2& setDiaHaikeiColor( CdColorProp value ) ;
	CdColorProp	getDiaJikuColor()const ;
	CDcdDiagram2& setDiaJikuColor( CdColorProp value ) ;

	///@}
public:
	// ********************************
	///@name CDcdDiagram-����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
	///@{
	bool	getDisplayRessyabangou()const ;
	CDcdDiagram2& setDisplayRessyabangou( bool value ) ;
	bool	getDisplayRessyamei()const ;
	CDcdDiagram2& setDisplayRessyamei( bool value ) ;
	/**
	@return
		�_�C���O�����G���e�B�e�B���W��DcDraw���W�ɕϊ�����
		�I�u�W�F�N�g��Ԃ��܂��B
	*/
	CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()
	{
		return m_pCDcdDiagram->getCconvContentPosToDcdTarget() ;
	};
	/**
	@return
		�_�C���O�����G���e�B�e�B���W��DcDraw���W�ɕϊ�����
		�I�u�W�F�N�g��Ԃ��܂��B
	*/
	const CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()const
	{
		return m_pCDcdDiagram->getCconvContentPosToDcdTarget() ;
	};

	/**
	@return
		TargetPos�̍���ɕ`�悳���w�_�C���O�������W�x�B 
	*/
	CdDcdPosXy	getPosDgr()const
	{	return m_pCDcdDiagram->getPosDgr() ;};

	/**
	TargetPos�̍���ɕ`�悳���w�_�C���O�������W�x���w�肵�܂��B
		
	@param posPosDgr [in]
		TargetPos�̍���ɕ`�悳���w�_�C���O�������W�x�B
	*/
	void setPosDgr( CdDcdPosXy posPosDgr )
	{	m_pCDcdDiagram->setPosDgr( posPosDgr ) ;};

	/**
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐����擾���܂��B
	@param pIfDcdTarger [in]
		�`��Ώۂ��w�肵�Ă��������B
	@return 
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐��B
	*/
	double getDcdPerDgrX( IfDcdTarget* pIfDcdTarget ) ;

	/**
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐���ݒ肵�܂��B
	@param pIfDcdTarger [in]
		�`��Ώۂ��w�肵�Ă��������B
	@param dDcdPerDgr [in] 
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐��B
	*/
	void setDcdPerDgrX(  IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) ;

	/**
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐����擾���܂��B
	@param pIfDcdTarger [in]
		�`��Ώۂ��w�肵�Ă��������B
	@return 
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐��B
	*/
	double getDcdPerDgrY( IfDcdTarget* pIfDcdTarget ) ;

	/**
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐���ݒ肵�܂��B
	@param pIfDcdTarger [in]
		�`��Ώۂ��w�肵�Ă��������B
	@param dDcdPerDgr [in] 
		�w�_�C���O�������W�x��1�ɑΉ�����A
		�wDcDraw���W(�_�����W)�x�̐��B
	*/
	void setDcdPerDgrY( IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) ;



	int	getVlineMode()const ;
	CDcdDiagram2& setVlineMode( int value ) ;
	
	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		�̒l���擾���܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari ;	//	������ (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	����� (m_bDisplayRessyasenNobori)
	 @return 
		- true ;	//	��Ԑ���\������
		- false ;	//	��Ԑ���\�����Ȃ�
	 */
	bool getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const ;
	
	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		�̒l��ݒ肵�܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari ;	//	������ (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	����� (m_bDisplayRessyasenNobori)
	 @param value [in]
		- true ;	//	��Ԑ���\������
		- false ;	//	��Ԑ���\�����Ȃ�
	 */
	CDcdDiagram2& setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) ;
	
	CDcdDiagram::EStopMarkDraw	getStopMarkDraw()const
	{	return m_pCDcdDiagram->getStopMarkDraw() ;};
	void setStopMarkDraw( CDcdDiagram::EStopMarkDraw	value )
	{	m_pCDcdDiagram->setStopMarkDraw( value ) ;};
	
	/**
	 @return
		�c�r�̊Ԋu�B
	
		���̒l�́A�P�ʂ́A�w�_�C���O�����G���e�B�e�BX���W�x�A
		���Ȃ킿�b�ł��B
		�܂�A���̒l���U�O*�Q�Ȃ�Athis���`�悷��_�C����
		�u�Q���ڃ_�C���v�ƂȂ�܂��B
		m_idxVlineMode ���瓱�o����܂��B
	 */
	int getVlinePitch()const ;
	
	/**
	 @return
		�c�r�����A�����̊Ԋu�B
	
		���̒l�́A�P�ʂ́A�w�_�C���O�����G���e�B�e�BX���W�x�A
		���Ȃ킿�b�ł��B
		���̒l�́A60���̖񐔂łȂ��Ă͂Ȃ�܂���B�܂��A
		m_iVlinePitch �̔{���łȂ��Ă͂Ȃ�܂���B
	 */
	int getVlineMiddlePitch()const ; 

	/**
	 @return
		�c�r�̂����A�����̊Ԋu�B
	
		���̒l�́A�P�ʂ́A�w�_�C���O�����G���e�B�e�BX���W�x�A
		���Ȃ킿�b�ł��B
		���̒l�́A60���̖񐔂łȂ��Ă͂Ȃ�܂���B�܂��A
		m_iVlinePitch �̔{���łȂ��Ă͂Ȃ�܂���B
		m_idxVlineMode ���瓱�o����܂��B
	 */
	int getVlineBoldPitch()const ;
	
	
	/**
		���̃N���X���T�|�[�g����A
		�c�r�̊Ԋu�̐ݒ�̑I�������擾���邱�Ƃ��ł��܂��B
	 @param pContVLINE [out]
		���̊֐��͂��̃R���e�i�ɁA�c�r�̊Ԋu�̐ݒ���������݂܂��B
		�R���e�i������܂ŕێ����Ă����v�f�͔j�����܂��B
		���̃R���e�i�̃C���f�N�X�́Am_idxVlineMode �ɑΉ����܂��B
		�s�v�ł���� NULL �ł����܂��܂���B
	 @return
		�I�����̐���Ԃ��܂��B	
	 */
	int getVlineChoices( Mui<CDcdDiagram::VLINE>* pContVLINE )const ;

	///@}

public:
	// ********************************
	///@name CDcdDiagram-����
	// ********************************
	///@{
	/**
		CdDedDispProp �I�u�W�F�N�g�̑�������A 
		�_�C���O�����̊e���̐F��t�H���g�̑��������肵�܂��B
		���̃��\�b�h���ݒ肷�郁�\�b�h�́A�ȉ��̂��̂ł��B
	
		- CDcdDiagram
			- CdFontProp	m_fontpropDiaRessyaFont ;
			- CdColorProp	m_colorDiaHaikeiColor ;
			- CdColorProp	m_colorDiaRessyaColor ;
			- CdColorProp	m_colorDiaJikuColor ;
			- bool	m_bDisplayRessyabangou ;
			- bool	m_bDisplayRessyamei ;
			- int m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
			- int m_iDiaRessyajouhouHyoujiEkiOrderNobori ;
	
		- CDcdDiagram2
			- CdFontProp	m_fontpropDiaEkimeiFont ;
			- CdFontProp	m_fontpropDiaJikokuFont ;
			- CdColorProp	m_colorDiaMojiColor ;
			- int m_iEkimeiLength
		
	 @param value [in]
		CdDedDispProp �I�u�W�F�N�g���w�肵�ĉ������B
	 */	
	CDcdDiagram2& readCdDedDispProp( const CdDedDispProp& value ) ;

	/**
		���̃N���X���`����s���̈�̍��W���A
	 	�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏ擾���܂��B
		���̒l�́Am_posDgr�Em_dwDcdPerDgrX�Em_dwDcdPerDgrY ����
		���o����܂��B
	@param pIfDcdTarger [in]
		�`��Ώۂ��w�肵�Ă��������B
	@return 
		���̃N���X���`����s���̈�̍��W��
		�w�_�C���O�����G���e�B�e�B���W�n�x�ŕԂ��܂��B
	@attention
		pIfDcdTarget �ւ̃_�C���O�����\�����s�\�ȏꍇ�A
		�߂�l��getX().getSize() , getY().getSize() �̂����ꂩ��
		0�ɂȂ�܂��B
	*/
	CdDcdZoneXy	getZone_Dgr( IfDcdTarget* pIfDcdTarget )const ;

	/**
		���̃N���X���`����s���̈�̍��W���A
	 	�w�_�C���O�����G���e�B�e�B���W�n�x�Őݒ肵�܂��B
		���̒l�́Am_posDgr�Em_dwDcdPerDgrX�Em_dwDcdPerDgrY ��
		���Z�̂����Őݒ肳��܂��B
	@param pIfDcdTarger [in]
		�`��Ώۂ��w�肵�Ă��������B
	@param value [in]
		���̃N���X���`����s���̈�̍��W��
		�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏw�肵�Ă��������B

		�_�C���O������ pIfDcdTarget ���ɕ`��ł��Ȃ��ꍇ�́A
		setZone_Dgr() �͓��삵�܂���B
	*/
	CDcdDiagram2& setZone_Dgr( 
		IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& value ) ;

	/**
		�E�C���h�E�T�C�Y�ύX���̓�����擾���܂��B
	@return 
		- false:�\���͈͂�ύX(OuDia Ver.1.00.04 ����)
		- true: �\���͈͂�ύX���Ȃ�(OuDia Ver.1.00.04 �݊�)
	*/
	bool getKeepZoneDgrOnSize()const
	{
		return m_pCDcdDiagram->getKeepZoneDgrOnSize() ;
	}

	/**
		�E�C���h�E�T�C�Y�ύX���̓����ݒ肵�܂��B
	@return 
		- false:�\���͈͂�ύX(OuDia Ver.1.00.04 ����)
		- true: �\���͈͂�ύX���Ȃ�(OuDia Ver.1.00.04 �݊�)
	*/
	void setKeepZoneDgrOnSize( bool bRv )
	{
		m_pCDcdDiagram->setKeepZoneDgrOnSize( bRv ) ;
	}

	/**
		�w��̍��W�ʒu��ʂ��Ă����Ԑ���T���܂��B
		
	 @param pIfDcdTarget [in]
		�`��Ώۂ��w�肵�ĉ������B
	 @param aCdDcdPosXy [in]
		��Ԑ���T�����W���w�肵�ĉ������B
	 @param iMerginPixels [in]
		���̊֐��́A�w��̍��W�Ɨ�Ԑ��Ƃ̋�����
		���̃s�N�Z�����ȉ��ł���΁A
		���W�ʒu���Ԑ����ʂ��Ă���Ƃ݂Ȃ��܂��B
		0 �Ȃ�A��Ԑ������W�ʒu�����S�ɒʂ��Ă���ꍇ�̂�
		�Y����Ԑ��Ƃ݂Ȃ��܂��B
	 @param pERessyahoukou [out]
		���̊֐��́A��Ԑ������������ꍇ�́A
		��Ԑ��̕������������݂܂��B
	 @param piRessyaIdx [out]
		���̊֐��́A��Ԑ������������ꍇ�́A
		���Index���������݂܂��B
	 @param piRessyasenIdx [out]
		���̊֐��́A��Ԑ������������ꍇ�́A
		��Ԑ�Index���������݂܂��B
	 @return
		-	1 ;	//	��Ԑ����݂���܂����B
		-	0 ;	//	��Ԑ����݂���܂���B
	 */
	virtual int calcCentDedDgrRessyasenOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy , 
		int iMerginPixels , 
		ERessyahoukou *pERessyahoukou , 
		int *piRessyaIdx , 
		int *piRessyasenIdx ) ;
 
	/**
		�w��̍��W�ʒu�ɑΉ����� �wOrder ��Ԃ��܂��B
		
		���̊֐��́A�w��̍��W�ʒu posY_Dcd ����A
		�w��̗�ԕ��� eRessyahoukou �̔��Ε����ɂ���
		�w�̉wOrder��Ԃ��܂��B
		
		(eRessyahoukou �� Ressyahoukou_Kudari �Ȃ� posY_Dcd �̏�A
		eRessyahoukou �� Ressyahoukou_Nobori �Ȃ� posY_Dcd �̉���
		�wOrder��Ԃ��܂�)
		
	 @param pIfDcdTarget [in]
		�`��Ώۂ��w�肵�ĉ������B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
	 @param posY_Dcd [in]
		Y���W�̈ʒu���w�肵�Ă��������B
		���W�n�́A IfDcdTarget ��̂��̂ł��B
	 @return
		����������A�wOrder ��Ԃ��܂��B
		�Ή����� �wOrder ���Ȃ��ꍇ�́A-1 �ł��B
		posY_Dcd�� �`��Ώۂ͈̔͂ɂȂ��ꍇ�́A -1 �ł��B
	 */
	virtual int calcEkiOrderOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		ERessyahoukou eRessyahoukou ,
		DcdPos posY_Dcd ) ; 

	/**
		�w��̍��W�ʒu�ɑΉ����� �wIndex ��Ԃ��܂��B
		
		���̊֐��́A�w��̍��W�ʒu posY_Dcd �̉��ɂ���
		�w�̉wIndex��Ԃ��܂��B
		
	 @param pIfDcdTarget [in]
		�`��Ώۂ��w�肵�ĉ������B
	 @param posY_Dcd [in]
		Y���W�̈ʒu���w�肵�Ă��������B
		���W�n�́A IfDcdTarget ��̂��̂ł��B
	 @return
		����������A�wIndex ��Ԃ��܂��B
		�Ή����� �wIndex ���Ȃ��ꍇ�́A-1 �ł��B
		posY_Dcd�� �`��Ώۂ͈̔͂ɂȂ��ꍇ�́A -1 �ł��B
	 */
	virtual int calcEkiIndexOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		DcdPos posY_Dcd ) ; 

	///@}

public:
	// ********************************
	///@name CDcdDiagram-�_�C���O�������W�ƁAIfDcdTarget ��̍��W��ϊ�
	// ********************************
	///@{
	/**
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�� X ���W�̈ʒu���A
		IfDcdTarget 
		�̍��W�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual DcdPos XDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�� Y ���W�̈ʒu���A
		IfDcdTarget �̍��W
		�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual DcdPos YDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		IfDcdTarget 
		�� X ���W�̈ʒu���A
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�̍��W�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual DcdPos XDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		IfDcdTarget �̍��W
		�� Y ���W�̈ʒu���A
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual DcdPos YDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�� X ���W�̗̈���A
		IfDcdTarget 
		�̍��W�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdZone XDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�� Y ���W�̗̈��
		IfDcdTarget �̍��W
		�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdZone YDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		IfDcdTarget 
		�� X ���W�̗̈���A
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�̍��W�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdZone XDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		IfDcdTarget �̍��W
		�� Y ���W�̗̈���A
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdZone YDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�̓_��
		IfDcdTarget 
		�̍��W�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdPosXy DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) ;

	/**
		IfDcdTarget �̍��W
		�̓_��
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param posSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdPosXy DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) ;


	/**
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�̋�`�̈���A
		IfDcdTarget 
		�̍��W�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param zoneSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdZoneXy DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) ;

	/**
		IfDcdTarget �̍��W
		�̋�`�̈���A
		�w�_�C���O�����G���e�B�e�B���W�n�x
		�ɕϊ����܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget �I�u�W�F�N�g���w�肵�ĉ������B
	 @param zoneSrc [in]
		�ϊ��O�̍��W���w�肵�ĉ������B	
	 @return
		�ϊ���̍��W��Ԃ��܂��B
	 */
	virtual CdDcdZoneXy DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) ;
	///@}
public:
	// ********************************
	///@name CDcdDiagram2-����
	// ********************************
	///@{
	CdFontProp	getDiaEkimeiFont()const ;
	CDcdDiagram2& setDiaEkimeiFont( const CdFontProp& value ) ;
	CdFontProp	getDiaJikokuFont()const ;
	CDcdDiagram2& setDiaJikokuFont( const CdFontProp& value ) ;
	CdColorProp	getDiaMojiColor()const ;
	CDcdDiagram2& setDiaMojiColor( CdColorProp value ) ;
	int getEkimeiLength(){	return m_iEkimeiLength ;};
	CDcdDiagram2& setEkimeiLength( int value ) ;
	bool getHideIppanekiEkimei()const ;
	CDcdDiagram2& setHideIppanekiEkimei( bool value )  ;

	///@}
public:
	// ********************************
	///@name CDcdDiagram2-����
	// ********************************
	///@{
	/**
		 �w�肳�ꂽ IfDcdTarget �I�u�W�F�N�g�̗̈�̒��ŁA
		�_�C���O������`�悷��̈�̑傫�������߂܂��B
		�P�ʂ́A IfDcdTarget ��̍��W�ł��B
	 @param pIfDcdTarget [in]
		���ɂȂ�`��̈���w�肵�Ă��������B
	 @return
		�_�C���O�����̕`��̈��Ԃ��܂��B
		���̒l�� X,Y �����ꂩ�̃T�C�Y��0�ȉ��̏ꍇ�A
		�_�C���O�����̕`��͂ł��܂���B
	 */
	virtual CdDcdZoneXy calcDiagramZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const ;
	/**
		 �w�肳�ꂽ IfDcdTarget �I�u�W�F�N�g�̗̈�̒��ŁA
		�w��`�悷��̈�(��)�̑傫�������߂܂��B
		�P�ʂ́A IfDcdTarget ��̍��W�ł��B
	 @param pIfDcdTarget [in]
		���ɂȂ�`��̈���w�肵�Ă��������B
	 @return
		�_�C���O�����̕`��̈��Ԃ��܂��B
		���̒l�� X,Y �����ꂩ�̃T�C�Y��0�ȉ��̏ꍇ�A
		�_�C���O�����̕`��͂ł��܂���B
	 */
	virtual CdDcdZoneXy calcEkimeiZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const ;
	
	/**
		 �w�肳�ꂽ IfDcdTarget �I�u�W�F�N�g�̗̈�̒��ŁA
		������`�悷��̈�(��)�̑傫�������߂܂��B
		�P�ʂ́A IfDcdTarget ��̍��W�ł��B
	 @param pIfDcdTarget [in]
		���ɂȂ�`��̈���w�肵�Ă��������B
	 @return
		�_�C���O�����̕`��̈��Ԃ��܂��B
		���̒l�� X,Y �����ꂩ�̃T�C�Y��0�ȉ��̏ꍇ�A
		�_�C���O�����̕`��͂ł��܂���B
	 */
	virtual CdDcdZoneXy calcJikokuZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const ;

	///@}
	
};
} //namespace ViewDiagram

#endif /*CDcdDiagram2_h*/



