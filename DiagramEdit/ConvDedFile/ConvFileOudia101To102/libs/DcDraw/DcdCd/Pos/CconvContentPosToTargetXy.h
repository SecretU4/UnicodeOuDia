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
//	CconvContentPosToTargetXy.h
// ****************************************************************
*/
/** @file */
#ifndef  DcDrawa_DcdCd_Pos_CconvContentPosToTargetXy_h
#define  DcDrawa_DcdCd_Pos_CconvContentPosToTargetXy_h
#include "DcdCd\Pos\CdDcdZoneXy.h"
#include "DcdCd\Pos\CconvContentPosToTarget.h"

// ****************************************************************
//	CconvContentPosToTargetXy
// ****************************************************************
/**
 @brief
  X,Y ���W�n�̊ԂŁAContentPos(�R���e���g���W)��
TargetPos(�^�[�Q�b�g���W)�ɕϊ�������@��񋟂���N���X�ł��B
 */
class CconvContentPosToTargetXy
{
private:
	// ********************************
	///@name �W��
	// ********************************
	///@{
	/**
		X �����̍��W��ϊ����� CconvContentPosToTarget �I�u�W�F�N�g�ł��B
	 */
	CconvContentPosToTarget	m_convX ;
	
	/**
		Y �����̍��W��ϊ����� CconvContentPosToTarget �I�u�W�F�N�g�ł��B
	 */
	CconvContentPosToTarget	m_convY ;
	
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/** m_convX,m_convY �̗����ɁA���[�h��ݒ肵�܂� */
	CconvContentPosToTargetXy( 
		CconvContentPosToTarget::EMode	eMode ) ;

	/** m_convX,m_convY �� EModePosAndRate �Ƃ��ď��������܂��B*/
	CconvContentPosToTargetXy( 
		DcdPos	iContentPosX ,
		double dTargetPosPerContentX ,
		DcdPos	iContentPosY ,
		double dTargetPosPerContentY ) ;

	/** m_convX,m_convY �� EModeZone �Ƃ��ď��������܂��B*/
	CconvContentPosToTargetXy( 
		DcdPos	iContentPosX ,
		DcdSize	iContentSizeX ,
		DcdPos	iContentPosY ,
		DcdSize	iContentSizeY ) ;

	/**
		m_convX,m_convY �� EModeZone �Ƃ��ď��������܂��B
	@param zoneContent[in]
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫���B
	*/
	CconvContentPosToTargetXy( 
		const CdDcdZoneXy&	zonexyContent ) ;

	CconvContentPosToTargetXy() ;

	virtual ~CconvContentPosToTargetXy() ;


public:
	// ********************************
	///@name CconvContentPosToTargetXy-�W��
	// ********************************
	///@{
	CconvContentPosToTarget* getX()
	{	return  &m_convX;	};
	const CconvContentPosToTarget* getX()const 
	{	return  &m_convX;	};
	CconvContentPosToTarget* getY() 
	{	return  &m_convY;	};
	const CconvContentPosToTarget* getY()const  
	{	return  &m_convY;	};
	///@}
	
	// ********************************
	///@name CconvContentPosToTargetXy-����
	// ********************************
	///@{
	/**
	@return
		m_convX,m_convY �́A TargetPos�ւ̕ϊ����[�h�B
	@attention
		m_convX,m_convY �ŕϊ����[�h���قȂ�ꍇ�́A���̊֐��̖߂�l��
		����`�ł��B
	*/
	CconvContentPosToTarget::EMode	getMode()const ;

	/**
	@param value [in]
		m_convX,m_convY �́A TargetPos�ւ̕ϊ����[�h���w�肵�Ă��������B
	*/
	void setMode( CconvContentPosToTarget::EMode	value ) ;
	
	/**
		TargetZone�ɕ\������R���e���g�̎n�_�Ɗg�嗦��ݒ肷�邱�Ƃ��ł��܂��B
	@param posContentPos [in]
		TargetPos�̍���ɕ`�悳���Content�́AContentPos���W�B
	@param dTargetPosPerContentX [in]
		X�����̊g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param dTargetPosPerContentY [in]
		Y�����̊g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		m_eMode=EModePosAndRate �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode=EModeZone �̂Ƃ��͕K�{�ł��B
	@note
		�����l���擾����Ƃ��́A getX() , getY() ���g�p���āA
		m_convX,m_convY �̃|�C���^���擾���A���̃I�u�W�F�N�g����
		�l���擾���Ă��������B
	*/
	void setContentPosAndRate( 
		const CdDcdPosXy& posContentPos , 
		double dTargetPosPerContentX , 
		double dTargetPosPerContentY , 
		const CdDcdZoneXy* pTargetZone ) ;
	
	/** 
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫�����擾���邱�Ƃ��ł��܂��B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		m_eMode=EModeZone �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode=EModePosAndRate �̂Ƃ��͕K�{�ł��B
	@return
		TargetZone�ɕ\������R���e���g�̈ʒu�Ƒ傫���B
	*/
	CdDcdZoneXy getContentZone( const CdDcdZoneXy* pTargetZone ) ;

	/**
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫����ݒ肷�邱�Ƃ��ł��܂��B
	@param zoneContent[in]
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫���B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		m_eMode=EModeZone �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode=EModePosAndRate �̂Ƃ��͕K�{�ł��B
	*/
	void setContentZone( const CdDcdZoneXy& zoneContent , const CdDcdZoneXy* pTargetZone ) ;
	///@}
	// ********************************
	///@name CconvContentPosToTargetXy-���W�ϊ�
	// ********************************
	///@{
	/**
		ContentPos ��̍��W
		���A
		TargetZone ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	@return
  		�ϊ���̒l��Ԃ��܂��B
	 */
	virtual CdDcdPosXy ContentPosToTarget( 
		const CdDcdPosXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;
	
	/**
		TargetZone ��̍��W
		���A
		ContentPos ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	 */
	virtual CdDcdPosXy ContentPosFromTarget( 
		const CdDcdPosXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;

	/**
		ContentPos ��̍��W
		���A
		TargetZone ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	 */
	virtual CdDcdZoneXy ContentZoneToTarget( 
		const CdDcdZoneXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;
	
	/**
		TargetZone ��̍��W
		���A
		ContentPos ��̍��W
		�ɕϊ����܂��B
	@param value [in]
  		�ϊ��O�̒l���w�肵�ĉ������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	 */
	virtual CdDcdZoneXy ContentZoneFromTarget( 
		const CdDcdZoneXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;
	///@}
};

#endif /*DcDrawa_DcdCd_Pos_CconvContentPosToTargetXy_h*/
