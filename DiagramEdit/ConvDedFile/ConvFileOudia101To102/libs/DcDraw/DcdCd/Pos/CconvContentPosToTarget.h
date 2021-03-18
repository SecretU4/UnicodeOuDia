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
// $Id: CconvContentPosToTarget.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdCd_Pos_CconvContentPosToTarget_h
#define  DcDraw_DcdCd_Pos_CconvContentPosToTarget_h
#include "DcdCd\Pos\DcdType.h"
#include "DcdCd\Pos\CdDcdZone.h"


// ****************************************************************
//	CconvContentPosToTarget
// ****************************************************************
/**
@brief
  CconvContentPosToTarget �́A1������ContentPos(�R���e���g���W)��
TargetPos(�^�[�Q�b�g���W)�ɕϊ�������@��񋟂���N���X�ł��B
	
<h2>
��1���T�v
</h2>

  ���̃N���X�́A�ȉ��̂悤�ȏꍇ��z�肵�Ă��܂��B
  
  �u����2cm,��3cm,���㒸�_�ʒu�����_����E1.5cm,��1cm�̒����`���A
��200pixel,����200pixel�̃N���C�A���g�̈�����E�C���h�E��
���W(10,10)-(190,190)�ɕ`�悷��Ƃ��Acm�P�ʂŕ\�����e���_���W��
�E�C���h�E�̃s�N�Z�����W�ɕϊ�����v
 
  �A���A���̃N���X�́A1�����̍��W�ϊ������ł��܂���BX,Y2�����̍��W��
�ϊ����邽�߂ɂ́A���̃N���X�̃C���X�^���X��X,Y ���ꂼ���(�v�Q��)
�쐬����K�v������܂��B


<h3>
���̃N���X�Ŏg�p����A���W��\���ď�
</h3>

(1)ContentPos(�R���e���g���W)

�@�`�悵�����R���e���g�ɌŗL�̍��W�ł��B���㌴�_�ł��B
�@�w�g�p��x�̏ꍇ�A�u���㒸�_�ʒu���`�v�ł͂��܂�Acm�P�ʂ̍��W�������
�Y�����܂��B

(2)TargetPos(�`��Ώۍ��W)

�@�R���e���g��`�悷��Ώۂ̃f�o�C�X�̍��W�B���㌴�_�ł��B
�@�w�g�p��x�̏ꍇ�A�u��200pixel,����200pixel�̃N���C�A���g�̈������
�E�C���h�E�v�́A�N���C�A���g�̈�̍��W���A����ɂ�����܂��B

(3)TargetZone(�`��Ώۗ̈�)

�@�R���e���g��`�悷��Ώۂ̃f�o�C�X�ɂ����āA�R���e���g��`�悷��̈�B
�@���̗̈��\�����W�n�́ATargetPos(�`��Ώۍ��W)�ł��B
�@�g�p��̏ꍇ�A�u�E�C���h�E�̍��W(10,10)-(190,190)�v���ATargetZone��
������܂��B



<h2>
��2��TargetPos�ւ̕ϊ����[�h
</h2>

�@���̃N���X�́AContentPos ��TargetPos �ϊ�������@�Ƃ��āA�ȉ���2���[�h��
�p�ӂ��Ă��܂��B�N���X���[�U�[�́A���̂����̈��I���ł��܂��B�܂��A
�g�p���ɐ؂�ւ��邱�Ƃ��ł��܂��B

	- (1)PosAndRate
	- (2)Zone
	
(1)PosAndRate

�@�ȉ��̑��������Ƃɕϊ����s���܂��B

ContentPos�@(�n�_���W)(TargetPos�̍���ɕ`�悳���Content�́AContentPos���W)
TargetPosPerContent(�g�嗦)

�@���̃��[�h�ł́ATargetZone�̑傫�����ς���Ă��A�\�������R���e���g��
�傫���E�`��͕ς��܂���B�R���e���g�̕\���͈͂������ς��܂��B

�@��TargetPosPerContent(�g�嗦) �́A���������_�ł��B


(2)Zone

�@�ȉ��̑��������Ƃɕϊ��������Ȃ��܂��B

ContentPos�@(�n�_���W)
ContentSize�@(TargetZone�ɕ\������R���e���g�̑傫��)

���̃��[�h�ł́ATargetZone�̑傫�����ς��ƁA�\�������R���e���g�̑傫���A
�`�󂪕ς��܂��B�R���e���g�̕\���͈͕͂ς��܂���B


<h2>
��3�������̓��� SynchronizeProp 
</h2>

�@���̃N���X�́A����TargetPosPerContent �� ContentSize �̊Ԃ̓�����
��ɕۂ��A�������������Ȃ��悤�ɂ��܂��B���̋@�\���A
�w�����̓����xSynchronizeProp �ƌď̂��܂��B
�@
�@�w�����̓����x�́A�ȉ��̂悤�ɓ��삵�܂��B

<h3>
(1)�����ݒ莞�̓���
</h3>

�@PosAndRate ���[�h�ł͒ʏ�A���� ContentPos �� TargetPosPerContent ��
�w�肵�܂��B�������ATargetPosPerContent �̑���� ContentSize ���w�肷��
���Ƃ��ł��܂��B
�@���l�ɁAZone ���[�h�ł��ATargetPosPerContent ���w�肷�邱�Ƃ��ł��܂��B

�@�N���X���[�U�[�� TargetPosPerContent ��ݒ肷��ƁA���̃N���X��
 ContentSize ���w�����ݒ蓯���҂��x��Ԃɂ��܂��B
  TargetZone ���w�肷�鑀�삪�s��ꂽ�Ƃ��AContentSize���@
�w�����ݒ蓯���҂��x�Ȃ�A���̃N���X�� TargetZone��TargetPosPerContent����A
ContentSize���Z�o�E�ݒ肵�܂��B���̂Ƃ��AContentSize�́w�����ݒ蓯���҂��x
�͉�������܂��B

�@TargetZone ���w�肷�鑀��ɂ����āATargetZone.Size��0�̏ꍇ�ATargetZone
 ��NULL���w�肳�ꂽ�ꍇ�́A��L�̓��������͍s���܂���B���̏ꍇ�́A
 �w�����ݒ蓯���҂��x�͉������ꂸ�AContentSize �͂���܂ł̒l��ێ����܂��B

�@��L�̓���́A�N���X���[�U�[�� ContentSize ���w�肵���ꍇ�ł����l�ł��BContentSize���w�肵���ꍇ�́ATargetPosPerContent ���w�����ݒ蓯���҂��x��ԂɂȂ�܂��B

<h3>
(2)�����擾���̓���
</h3>

�@PosAndRate ���[�h�ŁA�N���X���[�U�[�� TargetZone ���w�肷�鑀����s���ƁA
���̃N���X�� TargetZone��TargetPosPerContent����AContentSize���Z�o�E
�ݒ肵�܂��B
  
  �A���ATargetZone ���w�肷�鑀��ɂ����āATargetZone.Size��0�̏ꍇ�A
TargetZone ��NULL���w�肳�ꂽ�ꍇ�́A��L�̓��������͍s���܂���B
  ���̏ꍇ�́AContentSize �͂���܂ł̒l��ێ����܂��B

�@��L�̓���́AZone ���[�h�ł����l�ł��B���̃N���X�́ATargetZone��
ContentSize����ATargetPosPerContent ���Z�o�E�ݒ肵�܂��B



<h2>
��4���v���p�e�B�̃L���b�V�� PropCache
</h2>

�@�O�q�̒ʂ�A���̃N���X�́A���[�U�[���uTargetZone���w�肷�鑀��v��
�s�����тɁw�����̓����xSynchronizeProp ���s���܂��B
�@�A���A�w�肳�ꂽ TargetZone �� Size ���O��Ɠ����Ȃ�A
�����̓��� SynchronizeProp ���s���܂���B������A�w�v���p�e�B�̃L���b�V���x
PropCache �ƌď̂��܂��B
�@PropCache �ɂ��A(1)������ݒ肵�A(2)���O�Ɏw�肵���������擾 �����Ƃ��A
(1)�Őݒ肵���l��(2)�Ŏ擾�����l�����������Ƃ��ۏ؂���܂��B

<h3>
�y�⑫�z�v���p�e�B�̃L���b�V�� PropCache ���s��Ȃ������ꍇ
</h3>
�@�v���p�e�B�̃L���b�V�� PropCache ���s��Ȃ������ꍇ�́APosAndRate���[�h��
 ContentSize ��ݒ肵�A����� ContentSize ���擾���Ă��A�ݒ肵���l�ƈقȂ�
 �l���擾����邱�Ƃ�����܂��B�����́AContentSize����TargetPosPerContent
  �����߂鉉�Z�A����т��̋t�̉��Z�ŁA�[���ɂ��덷�������邽�߂ł��B

�@�v���p�e�B�̃L���b�V�����s��Ȃ��ꍇ�̓���͈ȉ��̂悤�ɂȂ�܂��B

(1)ContentSize��ݒ�

�@OuDia �́A ContentSize��TargetZone ��Size����ATargetPosPerContent ��
�Z�o���A�X�V����B

(2)ContentSize ���擾

�@�����̓������������s�����B
�@OuDia�́ATargetPosPerContent�� TargetZone �� Size ����AContentSize ��
�Z�o���A�X�V����B

�@(1)��(2)�̏����͂�������A�[���덷�̔����̉\��������܂��B���ꂪ
�ςݏd�Ȃ邽�߁A(1)�Őݒ肵�� ContentSize �� (2)�Ŏ擾���� ContentSize 
���s��v�ɂȂ�\��������܂��B
*/
class CconvContentPosToTarget
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	/** TargetPos�ւ̕ϊ����[�h */
	enum EMode
	{
		EModePosAndRate ,	
		EModeZone ,		
	};
	/** �v���p�e�B�̓��� �̏�� */
	enum ESynchronizeState
	{
		/// �����ݒ蓯���҂� �Ȃ�
		ESynchronizeState_None ,	
		/// m_dTargetPosPerContent �������ݒ蓯���҂��B
		ESynchronizeState_TargetPosPerContent ,	
		/// m_iContentSize �������ݒ蓯���҂��B
		ESynchronizeState_ContentSize ,	
	};
	
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		TargetPos�ւ̕ϊ����[�h 
	*/
	EMode	m_eMode ;
	/**
		�n�_���W�B
		
		TargetPos�̍���ɕ`�悳���Content�́AContentPos���W�B

		����l=0 
	*/
	DcdPos	m_iContentPos ;
	
	/**
		�g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B

		����l=1�B

	*/
	double m_dTargetPosPerContent ;
	
	/**
		TargetZone�ɕ\������R���e���g�̑傫���B

		����l=1�B
	*/
	DcdSize	m_iContentSize ;

	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/** 
		�v���p�e�B�̓��� �̏�� 
	*/
	ESynchronizeState	m_eSynchronizeState ;
	/**	
		�v���p�e�B�̃L���b�V�������{���邽�߂́ATargetZone.Size �̑O��l�B
		�����l��0�B
	*/
	DcdSize m_iTargetSize_Prev ;
	///@}

protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**	
		TargetPosPerContent �̒l����AContentSize �𓱏o���܂��B
	@param dTargetPosPerContent 
		TargetPosPerContent �̒l���w�肵�Ă��������B
	@param pTargetZone
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		NULL�͎w��ł��܂���B
	@return 
		ContentSize �̒l��Ԃ��܂��B
		dTargetPosPerContent�EpTargetZone->getSize() �̂ǂ��炩��0�Ȃ�A
		�߂�l�� 0 �ł��B
	*/
	DcdSize TargetPosPerContentToContentSize( 
		double dTargetPosPerContent , 
		const CdDcdZone* pTargetZone ) ;

	/**	
		ContentSize �̒l����A TargetPosPerContent �𓱏o���܂��B
	@param dTargetPosPerContent 
		ContentSize �̒l���w�肵�Ă��������B
	@param pTargetZone
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		NULL�͎w��ł��܂���B
	@return 
		TargetPosPerContent �̒l��Ԃ��܂��B
		iContentSize�EpTargetZone->getSize() �̂ǂ��炩��0�Ȃ�A
		�߂�l�� 0 �ł��B
	*/
	double TargetPosPerContentFromContentSize( 
		DcdSize iContentSize , 
		const CdDcdZone* pTargetZone ) ;
	/**	
		�v���p�e�B�̓���
	*/
	void synchronizeProp( const CdDcdZone* pTargetZone ) ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CconvContentPosToTarget() ;
	CconvContentPosToTarget( 
		EMode	eMode ) ;
	/** m_eMode �� EModePosAndRate �Ƃ��ď��������܂��B*/
	CconvContentPosToTarget( 
		DcdPos	iContentPos ,
		double dTargetPosPerContent ) ;
	/** m_eMode �� EModeZone �Ƃ��ď��������܂��B*/
	CconvContentPosToTarget( 
		DcdPos	iContentPos ,
		DcdSize	iContentSize ) ;
	/** 
		m_eMode �� EModeZone �Ƃ��ď��������܂��B
	@param zoneContent[in]
		TargetZone�ɕ\������R���e���g�̎n�_�Ƒ傫���B
		���̃R���X�g���N�^�́A
		zoneContent.getPos() �� m_iContentPos�ɁA
		zoneContent.getSize() ���Am_iContentSize ��
		���������܂��B
	*/
	CconvContentPosToTarget( 
		const CdDcdZone&	zoneContent ) ;
public:
	// ********************************
	///@name CconvContentPosToTarget-����
	// ********************************
	///@{
	EMode	getMode()const ;
	void setMode( EMode	value ) ;

	DcdPos	getContentPos()const ;
	void setContentPos( DcdPos value ) ;

	double getTargetPosPerContent()const ;
	DcdSize	getContentSize()const ;
	///@}
	
	// ********************************
	///@name CconvContentPosToTarget-TargetPosPerContent,ContentSize �擾�E�ݒ�
	// ********************************
	///@{
	/**
		�g�嗦���擾���邱�Ƃ��ł��܂��B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w��
		���Ă��������B
		m_eMode=EModePosAndRate �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode=EModeZone �̂Ƃ��͕K�{�ł��B
	@return
		�g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B

	*/
	double getTargetPosPerContent( 
		const CdDcdZone* pTargetZone ) ;

	/**
		�g�嗦��ݒ肷�邱�Ƃ��ł��܂��B
	@param value[in]
		�g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		m_eMode=EModePosAndRate �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode=EModeZone �̂Ƃ��͕K�{�ł��B
	*/
	void setTargetPosPerContent( double value , 
		const CdDcdZone* pTargetZone ) ;

	/**
		TargetZone�ɕ\������R���e���g�̑傫�����擾���邱�Ƃ��ł��܂��B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		m_eMode=EModeZone �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode=EModePosAndRate �̂Ƃ��͕K�{�ł��B
	@return
		TargetZone�ɕ\������R���e���g�̑傫���B
	*/
	DcdSize getContentSize( const CdDcdZone* pTargetZone ) ;

	/**
		TargetZone�ɕ\������R���e���g�̑傫����ݒ肷�邱�Ƃ��ł��܂��B
	@param value[in]
		TargetZone�ɕ\������R���e���g�̑傫���B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		m_eMode=EModeZone �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode=EModePosAndRate �̂Ƃ��͕K�{�ł��B
	*/
	void setContentSize( DcdSize value , const CdDcdZone* pTargetZone ) ;

	/**
		TargetZone�ɕ\������R���e���g�̎n�_�Ɗg�嗦��ݒ肷�邱�Ƃ��ł��܂��B
	@param posContentPos [in]
		TargetPos�̍���ɕ`�悳���Content�́AContentPos���W�B
	@param dTargetPosPerContentX [in]
		�g�嗦�B�R���e���g���W�P������́ATargetPos �̐��B
	@param pTargetZone[in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
		m_eMode= EModePosAndRate �̂Ƃ��́A���̒l�͏ȗ����邱�Ƃ��ł��܂��B
		m_eMode= EModeZone �̂Ƃ��͕K�{�ł��B
	*/
	void setContentPosAndRate( 
		DcdPos posContentPos , 
		double dTargetPosPerContent ,
		const CdDcdZone* pTargetZone ) ;

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
	CdDcdZone getContentZone( const CdDcdZone* pTargetZone ) ;

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
	void setContentZone( const CdDcdZone& zoneContent , 
		const CdDcdZone* pTargetZone ) ;


	///@}
	// ********************************
	///@name CconvContentPosToTarget-���W�ϊ�
	// ********************************
	///@{
	/**
		ContentPos ��̍��W���ATargetZone ��̍��W�ɕϊ����܂��B
	@param posContent [in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	*/
	DcdPos	ContentPosToTarget( 
		DcdPos posContent , const CdDcdZone& aTargetZone ) ;

	/**
		ContentPos ��̍��W���ATargetZone ��̍��W�ɕϊ����܂��B
	@param posContent [in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	*/
	CdDcdZone	ContentZoneToTarget( 
		const CdDcdZone& zoneContent , const CdDcdZone& aTargetZone ) ;

	/**
		TargetZone ��̍��W���AContentPos �ɕϊ����܂��B
	@param posTarget[in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	*/
	DcdPos	ContentPosFromTarget( 
		DcdPos posTarget , const CdDcdZone& aTargetZone ) ;

	/**
		TargetZone ��̍��W���AContentPos �ɕϊ����܂��B
	@param zoneTarget [in]
		�ϊ��Ώۂ̍��W���w�肵�Ă��������B
	@param aTargetZone [in]
		���̃N���X�ō��W�ϊ����s���ۂɑΏۂƂȂ� TargetZone ���w�肵��
		���������B
	*/
	CdDcdZone	ContentZoneFromTarget( 
		const CdDcdZone& zoneTarget , const CdDcdZone& aTargetZone ) ;

	///@}
};

#endif /*DcDraw_DcdCd_Pos_CconvDcdPosOnZone_h*/
