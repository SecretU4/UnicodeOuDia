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
//	CDcdDiagram.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdDiagram_h
#define  CDcdDiagram_h

#include "DcDraw/IfDcDraw.h"
#include "DcdCd/DcDrawProp/CdFontProp.h"
#include "DcdCd/Pos/CconvDcdPosOnZoneXy.h"
#include "DcDraw\CconvContentPosToDcdTarget.h"
#include "..\entDgr\CentDedDgrDia.h"
#include "..\DedRosenFileData\CdDedDispProp.h"

namespace ViewDiagram{
	using namespace DcDrawLib::DcDraw;
	using namespace entDgr;
	using namespace DedRosenFileData;
// ****************************************************************
//	CDcdDiagram
// ****************************************************************
/**
	@brief
	�y�T�v�z
	�w�_�C���O�����G���e�B�e�B�N���X�Q�x�̑��������ƂɁA IfDcdTarget 
	�I�u�W�F�N�g�Ɂw�_�C���O�����x��`�悵�܂��B
	
	���̃N���X�́A�_�C���O�����̃O���t����������`�悵�܂��B�g�O�̎��\���E
	�w���\���͕`�悵�܂���B
	
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
	
	�S�D  �\���Ɋւ��鑮���̂����ACdDedDispProp �Ɋi�[����Ȃ�����	���w�肵�ĉ������B


		- CDcdDiagram::m_CconvContentPosToDcdTarget::m_CconvContentPosToTargetXy
			- m_convX::m_iContentPos
			- m_convX::m_dTargetPosPerContent
			- m_convY::m_iContentPos
			- m_convY::m_dTargetPosPerContent
		- CDcdDiagram::m_idxVlineMode , 
		- CDcdDiagram::m_bDisplayRessyasenKudari , 
		- CDcdDiagram::m_bDisplayRessyasenNobori 
		- CDcdDiagram::m_eStopMarkDraw
	
	�T�D  IfDcDraw::DcDraw() ���\�b�h�ŁA�_�C���O������`�悷�邱�Ƃ�
	�ł��܂��B
	
 */
class CDcdDiagram : public IfDcDraw 
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	// ****************************************************************
	//	VLINE
	// ****************************************************************
	/**
	 @brief
		�c�r�̊Ԋu�̐ݒ���e��ێ�����\���̂ł��B
	 */
	struct VLINE
	{
		/**
			�c�r�̊Ԋu�B���̐��́A�_���ƂȂ�܂��B
		
			���̒l�́A�P�ʂ́A�w�_�C���O�����G���e�B�e�BX���W�x�A
			���Ȃ킿�b�ł��B
			�܂�A���̒l���U�O*�Q�Ȃ�Athis���`�悷��_�C����
			�u�Q���ڃ_�C���v�ƂȂ�܂��B
			���̒l�́A60���̖񐔂łȂ��Ă͂Ȃ�܂���B
		 */
		int m_iVlinePitch ;
		
		/**
			�c�r�����A�����̊Ԋu�B
		
			���̒l�́A�P�ʂ́A�w�_�C���O�����G���e�B�e�BX���W�x�A
			���Ȃ킿�b�ł��B
			���̒l�́A60���̖񐔂łȂ��Ă͂Ȃ�܂���B�܂��A
			m_iVlinePitch �̔{���łȂ��Ă͂Ȃ�܂���B
		 */
		int m_iVlineMiddlePitch ;
		
		/**
			�c�r�̂����A�����̊Ԋu�B
		
			���̒l�́A�P�ʂ́A�w�_�C���O�����G���e�B�e�BX���W�x�A
			���Ȃ킿�b�ł��B
			���̒l�́A60���̖񐔂łȂ��Ă͂Ȃ�܂���B�܂��A
			m_iVlinePitch �̔{���łȂ��Ă͂Ȃ�܂���B
		 */
		int m_iVlineBoldPitch ;
		
		
	};



	/**
		�_�C���O�����r���[�ɒ�ԋL����\�����邩�ۂ���
		�\���񋓂ł��B
	*/
	enum EStopMarkDraw
	{
		/**
			��ԉw����=OFF
			
			��ԉw�������s���܂���B
		*/
		EStopMarkDraw_Nothing ,
		/**
			��ԉw����=ON

			�Z���Ԓ�Ԃ̉w�ɁA��ԉw�������L��(��)��`�悵�܂��B
		*/
		EStopMarkDraw_DrawOnBriefStop ,
	};
	
public:
	// ********************************
	///@name CDcdDiagram-�萔
	// ********************************
	///@{
	/** 
	@return
		����� �w�_�C���O�������W�x��1�ɑΉ�����A�wDcDraw���W(�_�����W)�x�̐� 
		��Ԃ��܂��B
	*/
	static double DEFAULT_DCD_PER_DGR_X(){	return 0.05 ;}; 
	/** @see DEFAULT_DCD_PER_DGR_X */
	static double DEFAULT_DCD_PER_DGR_Y(){	return 0.05 ;};
	///@}
private:
	// ********************************
	///@name �萔
	// ********************************
	///@{
	/**
		�c�r�̊Ԋu�̐ݒ�̑I�����B
		this �́A���̕ϐ��Ɋi�[����Ă���ݒ���e����P��I�����ė��p���܂��B
	 */
	static const VLINE	m_arVline[8] ;
	///@}
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		�w�_�C���O�����_�C���x�I�u�W�F�N�g�Ƃ̊֘A�ł��B
	
		this �́A���̃I�u�W�F�N�g����_�C���O�����̏����擾���A
		�`����s���܂��B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this �̔j������������܂�
		�������Ȃ��Ă͂Ȃ�܂���B
	
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	CentDedDgrDia*	m_pCentDedDgrDia ;
	
	///@}

private:
	// ********************************
	///@name ����-CdDedDispProp ����ǂݍ��݉\
	// ********************************
	///@{
	/**
		 �_�C����ʗ�ԃt�H���g�B
		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �����Ƃ�
		readCdDedDispProp() �Ō��܂�܂��B
	 */
	CdFontProp	m_fontpropDiaRessyaFont ;

	/**
		 �_�C����ʔw�i�F�B
		�K��l�́A���B
	
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �����Ƃ�
		readCdDedDispProp() �Ō��܂�܂��B
	 */
	CdColorProp	m_colorDiaHaikeiColor ;

	/**
		 �_�C����ʏc�����F�B
		�K��l�́A���B
	
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �����Ƃ�
		readCdDedDispProp() �Ō��܂�܂��B
	 */
	CdColorProp	m_colorDiaJikuColor ;

	/**
		 �_�C����ʗ�Ԕԍ��\��
		- true ;	//	�_�C����ʂɗ�Ԕԍ���\������
		- false ;	//	�_�C����ʂɗ�Ԕԍ���\�����Ȃ�
	
		�K��l�́Atrue�B
	
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �����Ƃ�
		readCdDedDispProp() �Ō��܂�܂��B
	 */
	bool	m_bDisplayRessyabangou ;
	/**
		 �_�C����ʗ�Ԗ��\��
		- true ;	//	�_�C����ʂɗ�Ԗ���\������
		- false ;	//	�_�C����ʂɗ�Ԗ���\�����Ȃ�
	
		�K��l�́Atrue�B
	
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �����Ƃ�
		readCdDedDispProp() �Ō��܂�܂��B
	 */
	bool	m_bDisplayRessyamei ;
	
	
	///@}
	// ********************************
	///@name ����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
	///@{
	/**
		�w�_�C���O�����G���e�B�e�B���W�x �� ContentPos �A
		IfDcdTarget �� TargetPos �Ƃ���
		�o���̍��W�ϊ����s���܂��B
	*/
	CconvContentPosToDcdTarget m_CconvContentPosToDcdTarget ;

	/**
		�c�r�̊Ԋu�̃��[�h�B
		���̒l�́A m_arVline[] �̃C���f�N�X�ƂȂ�܂��B
		����l�� 1 (�Q���ڃ_�C��)�Ƃ��܂��B
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �ɂ͊܂܂�Ă��܂���B
	 */
	int	m_idxVlineMode ;

	/**
		�����Ԃ�
		��Ԑ���\�����邩�ۂ����w�肵�܂��B
		- true ;	//	��Ԑ���\������
		- false ;	//	��Ԑ���\�����Ȃ�
		
		����l�� true 
	
		���̒l�́A 
		CDedRosenFileData::m_CdDedDispProp �ɂ͊܂܂�Ă��܂���B
	 */
	bool m_bDisplayRessyasenKudari ;

	/**
		����Ԃ�
		��Ԑ���\�����邩�ۂ����w�肵�܂��B
	 @see m_bDisplayRessyasenKudari
	 */
	bool m_bDisplayRessyasenNobori ;

	/**
		�_�C���O�����r���[�ɒ�ԋL����\�����邩�ۂ���
		�\���񋓂ł��B
	*/
	EStopMarkDraw	m_eStopMarkDraw ;
	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		�����̐��K�����s���܂��B
		�ΏۂƂȂ�̂́A�ȉ��̑����ł��B

		- m_dwDcdPerDgrX	0.0001�`10
		- m_dwDcdPerDgrY	0.0001�`10
	*/
	void adjustProp() ;


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
	CDcdDiagram( 
		CentDedDgrDia*	pCentDedDgrDia , 
		const CdDedDispProp& aCdDedDispProp ) ;
	CDcdDiagram() ; 
	virtual ~CDcdDiagram() ;
	
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
	 	���̑傫����pCdDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	 	�����łȂ��ꍇ�́A�U�ł��B
	
		�y�I�[�o���C�h�z
		�T�|�[�g����܂���B�U��Ԃ��܂��B
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
	CDcdDiagram& setCentDedDgrDia( CentDedDgrDia* value ) ;
	///@}

public:
	// ********************************
	///@name CDcdDiagram-����-CdDedDispProp ����ǂݍ��݉\
	// ********************************
	///@{
	CdFontProp	getDiaRessyaFont()const ;
	CDcdDiagram& setDiaRessyaFont( const CdFontProp& value ) ;
	CdColorProp	getDiaHaikeiColor()const ;
	CDcdDiagram& setDiaHaikeiColor( CdColorProp value ) ;

	CdColorProp	getDiaJikuColor()const ;
	CDcdDiagram& setDiaJikuColor( CdColorProp value ) ;
	
	///@}
public:
	// ********************************
	///@name CDcdDiagram-����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
	///@{
	bool	getDisplayRessyabangou()const ;
	CDcdDiagram& setDisplayRessyabangou( bool value ) ;
	bool	getDisplayRessyamei()const ;
	CDcdDiagram& setDisplayRessyamei( bool value ) ;
	/**
	@return
		�_�C���O�����G���e�B�e�B���W��DcDraw���W�ɕϊ�����
		�I�u�W�F�N�g��Ԃ��܂��B
	@note
		�ȉ��̃��\�b�h�́Am_CconvContentPosToDcdTarget �ɑ΂���
		���b�p�[�֐��ł��B@n
		getPosDgr(),setPosDgr(),getDcdPerDgrX(),setDcdPerDgrX(),
		getDcdPerDgrY(),setDcdPerDgrY(),getZone_Dgr(),setZone_Dgr(),
		getKeepZoneDgrOnSize(),setKeepZoneDgrOnSize(),
		XDgrToDcd(),YDgrToDcd(),XDgrFromDcd(),YDgrFromDcd(),
		DgrToDcd(),DgrFromDcd()
	*/
	CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()
	{
		return &m_CconvContentPosToDcdTarget ;
	};

	/**
	@return
		�_�C���O�����G���e�B�e�B���W��DcDraw���W�ɕϊ�����
		�I�u�W�F�N�g��Ԃ��܂��B
	*/
	const CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()const
	{
		return &m_CconvContentPosToDcdTarget ;
	};

	/**
	@return
		TargetPos�̍���ɕ`�悳���w�_�C���O�������W�x�B 
	*/
	CdDcdPosXy	getPosDgr()const ;

	/**
	TargetPos�̍���ɕ`�悳���w�_�C���O�������W�x���w�肵�܂��B
		
	@param posPosDgr [in]
		TargetPos�̍���ɕ`�悳���w�_�C���O�������W�x�B
	*/
	void setPosDgr( CdDcdPosXy posPosDgr );

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
	CDcdDiagram& setVlineMode( int value ) ;

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
	CDcdDiagram& setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) ;

	EStopMarkDraw	getStopMarkDraw()const{	return m_eStopMarkDraw ;};
	void setStopMarkDraw( EStopMarkDraw	value )
	{	m_eStopMarkDraw = value ;};


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
		\n�s�v�ł���� NULL �ł����܂��܂���B
	 @return
		�I�����̐���Ԃ��܂��B	
	 */
	int getVlineChoices( Mui<VLINE>* pContVLINE )const ;

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
		- CdFontProp	m_fontpropDiaRessyaFont ;
		- COLORREF	m_colorDiaHaikeiColor ;
		- COLORREF	m_colorDiaRessyaColor ;
		- COLORREF	m_colorDiaJikuColor ;
		
	 @param value [in]
		CdDedDispProp �I�u�W�F�N�g���w�肵�ĉ������B
	*/	
	CDcdDiagram& readCdDedDispProp( const CdDedDispProp& value ) ;
	
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
	CdDcdZoneXy	getZone_Dgr( IfDcdTarget* pIfDcdTarger ) ;

	/**
		���̃N���X���`����s���̈�̍��W���A
	 	�w�_�C���O�����G���e�B�e�B���W�n�x�Őݒ肵�܂��B
		���̒l�́Am_posDgr�Em_dwDcdPerDgrX�Em_dwDcdPerDgrY ��
		���Z�̂����Őݒ肳��܂��B
	@param pIfDcdTarger [in]
		�`��Ώۂ��w�肵�Ă��������B
	@param
		���̃N���X���`����s���̈�̍��W��
		�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏw�肵�Ă��������B
	*/
	void setZone_Dgr( IfDcdTarget* pIfDcdTarger , const CdDcdZoneXy& value ) ;
	
	/**
		�E�C���h�E�T�C�Y�ύX���̓�����擾���܂��B
	@return 
		- false:�\���͈͂�ύX(OuDia Ver.1.00.04 ����)
		- true: �\���͈͂�ύX���Ȃ�(OuDia Ver.1.00.04 �݊�)
	*/
	bool getKeepZoneDgrOnSize()const;

	/**
		�E�C���h�E�T�C�Y�ύX���̓����ݒ肵�܂��B
	@return 
		- false:�\���͈͂�ύX(OuDia Ver.1.00.04 ����)
		- true: �\���͈͂�ύX���Ȃ�(OuDia Ver.1.00.04 �݊�)
	*/
	void setKeepZoneDgrOnSize( bool bRv );
	
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
	
};
} //namespace ViewDiagram

#endif /*CDcdDiagram_h*/



