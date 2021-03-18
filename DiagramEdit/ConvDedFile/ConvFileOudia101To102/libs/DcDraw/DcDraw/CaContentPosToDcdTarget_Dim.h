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
// $Id: CaContentPosToDcdTarget_Dim.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdCd_Pos_CaContentPosToDcdTarget_Dim_h
#define  DcDraw_DcdCd_Pos_CaContentPosToDcdTarget_Dim_h
#include "DcdCd\Pos\CconvContentPosToTarget.h"
#include "DcDraw\IfDcdTarget.h"

class CconvContentPosToDcdTarget ;	//	outer�̎Q��

// ****************************************************************
//	CaContentPosToDcdTarget_Dim
// ****************************************************************
/**
@brief
  CaContentPosToDcdTarget_Dim �́A
  CconvContentPosToDcdTarget �ɏW�񂳂�܂��B
  
  ���̃N���X�͒��ۃN���X�ł��B
  IfDcdTarget* �������Ƃ������\�b�h�Ăяo�����A
  calcCdDcdZone() �֐��� �`��̈�ɕϊ����āA
  m_pCconvContentPosToTarget �ɈϏ����܂��B
*/
class CaContentPosToDcdTarget_Dim
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**	
		IfDcdTarget �̉E�E���̗]�T�̈��ێ����܂��B
		IfDcdTarget �̍��W�n�Ŏw�肵�܂��B
	
		���W�n�ɂ���ẮA�E���̃R���e���c��
		��ʊO(IfDcdTarget�̗̈�O)�ɂȂ�ꍇ������܂��B
		
		���̒l��1�ȏ�ɂ��邱�Ƃɂ��A�R���e���c��
		��ʓ��̂��E��ɕ\�������邱�Ƃ��ł��܂��B
	*/
	DcdSize m_sizeDcdMargin ;
	///@}

protected:
	// --------------------------------
	///@name �I�[�o���C�h
	// --------------------------------
	///@{
	/**
	@return 
		IfDcdTarget �̕`��̈��Ԃ��܂��B
	*/
	virtual CdDcdZone calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) = 0 ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CaContentPosToDcdTarget_Dim(
		DcdSize sizeDcdMargin );
	virtual ~CaContentPosToDcdTarget_Dim(){} ;


public:
	// ********************************
	///@name CconvContentPosToTarget-����
	// ********************************
	///@{
	CconvContentPosToTarget::EMode	getMode()const ;
	void setMode( CconvContentPosToTarget::EMode	value ) ;

	DcdPos	getContentPos()const ;
	void setContentPos( DcdPos value ) ;

	double getTargetPosPerContent()const ;
	DcdSize	getContentSize()const ;
	///@}
	
public:
	// ********************************
	///@name CconvContentPosToTarget-TargetPosPerContent,ContentSize �擾�E�ݒ�
	// ********************************
	///@{
	/**
		�g�嗦���擾���邱�Ƃ��ł��܂��B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL�Ȃ�A�����̓������s���܂���B
	@return
		�g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B

	*/
	double getTargetPosPerContent( 
		IfDcdTarget* pIfDcdTarget ) ;

	/**
		�g�嗦��ݒ肷�邱�Ƃ��ł��܂��B
	@param value[in]
		�g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL�Ȃ�A�����̓������s���܂���B
	*/
	void setTargetPosPerContent( double value , 
		IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZone�ɕ\������R���e���g�̑傫�����擾���邱�Ƃ��ł��܂��B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL�Ȃ�A�����̓������s���܂���B
	@return
		TargetZone�ɕ\������R���e���g�̑傫���B
	*/
	DcdSize getContentSize( IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZone�ɕ\������R���e���g�̑傫����ݒ肷�邱�Ƃ��ł��܂��B
	@param value[in]
		TargetZone�ɕ\������R���e���g�̑傫���B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL�Ȃ�A�����̓������s���܂���B
	*/
	void setContentSize( DcdSize value , IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZone�ɕ\������R���e���g�̎n�_�Ɗg�嗦��ݒ肷�邱�Ƃ��ł��܂��B
	@param posContentPos [in]
		TargetPos�̍���ɕ`�悳���Content�́AContentPos���W�B
	@param dTargetPosPerContentX [in]
		�g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL�Ȃ�A�����̓������s���܂���B
	*/
	void setContentPosAndRate( 
		DcdPos posContentPos , 
		double dTargetPosPerContent ,
		IfDcdTarget* pIfDcdTarget ) ;

	/** 
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫�����擾���邱�Ƃ��ł��܂��B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL�Ȃ�A�����̓������s���܂���B
	@return
		TargetZone�ɕ\������R���e���g�̈ʒu�Ƒ傫���B
	*/
	CdDcdZone getContentZone( IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫����ݒ肷�邱�Ƃ��ł��܂��B
	@param zoneContent[in]
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫���B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL�Ȃ�A�����̓������s���܂���B
	*/
	void setContentZone( const CdDcdZone& zoneContent , 
		IfDcdTarget* pIfDcdTarget ) ;


	///@}
public:
	// ********************************
	///@name CconvContentPosToTarget-���W�ϊ�
	// ********************************
	///@{
	/**
		ContentPos ��̍��W���ATargetZone ��̍��W�ɕϊ����܂��B
	@param posContent [in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL �͎w��ł��܂���B
	*/
	DcdPos	ContentPosToTarget( 
		DcdPos posContent , IfDcdTarget* pIfDcdTarget ) ;

	/**
		ContentPos ��̍��W���ATargetZone ��̍��W�ɕϊ����܂��B
	@param posContent [in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL �͎w��ł��܂���B
	*/
	CdDcdZone	ContentZoneToTarget( 
		const CdDcdZone& zoneContent , IfDcdTarget* pIfDcdTarget) ;

	/**
		TargetZone ��̍��W���AContentPos �ɕϊ����܂��B
	@param posTarget[in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL �͎w��ł��܂���B
	*/
	DcdPos	ContentPosFromTarget( 
		DcdPos posTarget , IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZone ��̍��W���AContentPos �ɕϊ����܂��B
	@param zoneTarget [in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param pIfDcdTarget[in]
		�`��Ώۂ��w�肵�Ă��������B
		NULL �͎w��ł��܂���B
	*/
	CdDcdZone	ContentZoneFromTarget( 
		const CdDcdZone& zoneTarget , IfDcdTarget* pIfDcdTarget ) ;

	///@}
public:
	// ********************************
	///@name CconvContentPosToTargetDim-�֘A
	// ********************************
	///@{
	virtual CconvContentPosToTarget* getCconvContentPosToTarget()=0 ;
	virtual const CconvContentPosToTarget* getCconvContentPosToTarget()const=0  ;
	///@}
public:
	// ********************************
	///@name CaContentPosToDcdTarget_Dim-����
	// ********************************
	///@{
	DcdSize getDcdMargin()const ;
	void setDcdMargin(DcdSize value ) ;
	///@}
};

#endif //DcDraw_DcdCd_Pos_CaContentPosToDcdTarget_Dim_h
