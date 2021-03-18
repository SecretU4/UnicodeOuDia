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
//	CconvContentPosToDcdTarget.h
// ****************************************************************
*/
/** @file */
#ifndef  DcDrawa_DcdCd_Pos_CconvContentPosToDcdTarget_h
#define  DcDrawa_DcdCd_Pos_CconvContentPosToDcdTarget_h
#include "DcdCd\Pos\CconvContentPosToTargetXy.h"
#include "DcDraw\CaContentPosToDcdTarget_Dim.h"
#include "DcDraw\IfDcdTarget.h"

// ****************************************************************
//	CconvContentPosToDcdTarget
// ****************************************************************
/**
@brief
  X,Y ���W�n�̊ԂŁAContentPos(�R���e���g���W)��
�`��Ώۂ� IfDcdTarget �̍��W�ɕϊ�������@��񋟂���N���X�ł��B
 */
class CconvContentPosToDcdTarget
{
public:
	// ********************************
	//	 �����N���X
	// ********************************
	// ****************************************************************
	//	CaConvX
	// ****************************************************************
	class CaConvX : public CaContentPosToDcdTarget_Dim
	{
	protected:
		// --------------------------------
		///@name �I�[�o���C�h
		// --------------------------------
		///@{
		/**
		@return 
			IfDcdTarget �̕`��̈��Ԃ��܂��B
		*/
		virtual CdDcdZone calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) ;
		///@}

	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		CaConvX(
			DcdSize sizeDcdMargin );
		// ********************************
		///@name CconvContentPosToTargetDim-�֘A
		// ********************************
		///@{
		virtual CconvContentPosToTarget* getCconvContentPosToTarget() ;
		virtual const CconvContentPosToTarget* getCconvContentPosToTarget()const  ;
		///@}
	};
	friend class CaConvX ;
	// ****************************************************************
	//	CaConvY
	// ****************************************************************
	class CaConvY : public CaContentPosToDcdTarget_Dim
	{
	protected:
		// --------------------------------
		///@name �I�[�o���C�h
		// --------------------------------
		///@{
		/**
		@return 
			IfDcdTarget �̕`��̈��Ԃ��܂��B
		*/
		virtual CdDcdZone calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) ;
		///@}

	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		CaConvY(
			DcdSize sizeDcdMargin );
		// ********************************
		///@name CconvContentPosToTargetDim-�֘A
		// ********************************
		///@{
		virtual CconvContentPosToTarget* getCconvContentPosToTarget() ;
		virtual const CconvContentPosToTarget* getCconvContentPosToTarget()const  ;
		///@}
	};
	friend class CaConvY ;
private:
	// ********************************
	///@name �W��
	// ********************************
	///@{
	/**
		���W��ϊ����� CconvContentPosToTarget �I�u�W�F�N�g�ł��B
	 */
	CconvContentPosToTargetXy	m_CconvContentPosToTargetXy ;
	
	/**
		X���W��ϊ����� CconvContentPosToTarget �I�u�W�F�N�g�ł��B
		���̃I�u�W�F�N�g�́A���ۂɂ� 
		m_CconvContentPosToTargetXy.m_convX �ւ̃A�_�v�^�ł��B
	*/
	CaConvX	m_convX ;

	/**
		X���W��ϊ����� CconvContentPosToTarget �I�u�W�F�N�g�ł��B
		���̃I�u�W�F�N�g�́A���ۂɂ� 
		m_CconvContentPosToTargetXy.m_convY �ւ̃A�_�v�^�ł��B
	*/
	CaConvY	m_convY ;
	///@}
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		m_sizeDcdMarginXRight , m_sizeDcdMarginYBottom ��
		�K�p���ꂽ�̈���Z�o���܂��B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
		NULL �͎w��ł��܂���B
	@return
		�Z�o��̗̈�ł��B
	*/
	virtual CdDcdZoneXy calcMarginAppliedZone( IfDcdTarget* pIfDcdTarget ) ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/** m_convX,m_convY �̗����ɁA���[�h��ݒ肵�܂� */
	CconvContentPosToDcdTarget( 
		CconvContentPosToTarget::EMode	eMode ,
		DcdSize	sizeDcdMarginXRight = 0 ,
		DcdSize	sizeDcdMarginYBottom = 0 );

	/** m_convX,m_convY �� EModePosAndRate �Ƃ��ď��������܂��B*/
	CconvContentPosToDcdTarget( 
		DcdPos	iContentPosX ,
		double dTargetPosPerContentX ,
		DcdPos	iContentPosY ,
		double dTargetPosPerContentY ,
		DcdSize	sizeDcdMarginXRight = 0 ,
		DcdSize	sizeDcdMarginYBottom = 0 ) ;

	/**
		m_convX,m_convY �� EModeZone �Ƃ��ď��������܂��B
	@param zoneContent[in]
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫���B
	*/
	CconvContentPosToDcdTarget( 
		const CdDcdZoneXy&	zonexyContent ,
		DcdSize	sizeDcdMarginXRight = 0 ,
		DcdSize	sizeDcdMarginYBottom = 0 ) ;

	CconvContentPosToDcdTarget() ;

	virtual ~CconvContentPosToDcdTarget() ;

public:
	// ********************************
	///@name CconvContentPosToDcdTarget-�W��
	// ********************************
	///@{
	CaConvX* getX()
	{
		return &m_convX ;
	};
	const CaConvX* getX()const
	{
		return &m_convX ;
	};
	CaConvY* getY() 
	{
		return &m_convY ;
	};
	const CaConvY* getY()const 
	{
		return &m_convY ;
	};
	///@}
	
	// ********************************
	///@name CconvContentPosToDcdTarget-����
	// ********************************
	///@{
	DcdSize	getDcdMarginXRight()const ;
	void setDcdMarginXRight( DcdSize value ) ;
	DcdSize	getDcdMarginYBottom()const ;
	void setDcdMarginYBottom( DcdSize value ) ;
	///@}
	// ********************************
	///@name CconvContentPosToDcdTarget-����
	// ********************************
	///@{
	/**
	@return
		m_convX,m_convY �́A TargetPos�ւ̕ϊ����[�h�B
	@attention
		m_convX,m_convY �ŕϊ����[�h���قȂ�ꍇ�́A���̊֐��̖߂�l��
		����`�ł��B
	*/
	virtual CconvContentPosToTarget::EMode	getMode()const ;

	/**
	@param value [in]
		m_convX,m_convY �́A TargetPos�ւ̕ϊ����[�h���w�肵�Ă��������B
	*/
	virtual void setMode( CconvContentPosToTarget::EMode	value ) ;

	/**
	@return 
		TargetPos�̍���ɕ`�悳���Content�́AContentPos���W�B
	*/
	virtual CdDcdPosXy getContentPos()const ;

	/**
	@param value [in]
		TargetPos�̍���ɕ`�悳���Content�́AContentPos���W��ݒ�B
	*/
	virtual void setContentPos( const CdDcdPosXy& value ) ;

	/**
		TargetZone�ɕ\������R���e���g�̎n�_�Ɗg�嗦��ݒ肷�邱�Ƃ��ł��܂��B
	@param posContentPos [in]
		TargetPos�̍���ɕ`�悳���Content�́AContentPos���W�B
	@param dTargetPosPerContentX [in]
		X�����̊g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param dTargetPosPerContentY [in]
		Y�����̊g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
	@note
		�����l���擾����Ƃ��́A 
		getX() , getY() ���g�p���āA
		m_convX,m_convY �̃|�C���^���擾���A���̃I�u�W�F�N�g����
		�l���擾���Ă��������B
	*/
	virtual void setContentPosAndRate( 
		const CdDcdPosXy& posContentPos , 
		double dTargetPosPerContentX , 
		double dTargetPosPerContentY , 
		IfDcdTarget* pIfDcdTarget ) ;


	/** 
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫�����擾���邱�Ƃ��ł��܂��B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
	@return
		TargetZone�ɕ\������R���e���g�̈ʒu�Ƒ傫���B
	*/
	CdDcdZoneXy getContentZone( IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫����ݒ肷�邱�Ƃ��ł��܂��B
	@param zoneContent[in]
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫���B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
	*/
	virtual void setContentZone( const CdDcdZoneXy& zoneContent , 
		IfDcdTarget* pIfDcdTarget ) ;
	///@}
	// ********************************
	///@name CconvContentPosToDcdTarget-���W�ϊ�
	// ********************************
	///@{
	/**
		ContentPos ��̍��W
		���A
		TargetZone ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
	@return
  		�ϊ���̒l��Ԃ��܂��B
	 */
	virtual CdDcdPosXy ContentPosToTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		TargetZone ��̍��W
		���A
		ContentPos ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
	 */
	virtual CdDcdPosXy ContentPosFromTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;

	/**
		ContentPos ��̍��W
		���A
		TargetZone ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
	 */
	virtual CdDcdZoneXy ContentZoneToTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		TargetZone ��̍��W
		���A
		ContentPos ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param pIfDcdTarget [in]
		�`��Ώۂ� IfDcdTarget ���w�肵�Ă��������B
	 */
	virtual CdDcdZoneXy ContentZoneFromTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;
	///@}
};

#endif /*DcDrawa_DcdCd_Pos_CconvContentPosToDcdTarget_h*/
