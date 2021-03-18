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
#if !defined(AFX_CWNDDIAGRAM_H__E5EA7615_628B_4059_BBA7_DD1DB661E133__INCLUDED_)
#define AFX_CWNDDIAGRAM_H__E5EA7615_628B_4059_BBA7_DD1DB661E133__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CWndDiagram.h : �w�b�_�[ �t�@�C��
//

#include "..\entDgr\CentDedDgrDia.h"
#include "CDcdDiagram2.h"
#include "WinUtil\CdScrollbarProp.h"

namespace ViewDiagram{
	using namespace DcDrawLib::WinUtil ;
/////////////////////////////////////////////////////////////////////////////
// CWndDiagram �E�B���h�E
/**
 @brief
�y�T�v�z
	�_�C���O������`�悷��q�E�C���h�E�ł��B
  CDcdDiagram �N���X���g���āA�N���C�A���g�̈�Ƀ_�C���O������`�悵�܂��B

	���̃N���X�́ACDcdDiagram2,CDcdDiagram �I�u�W�F�N�g���܂��܂��B
	���̃N���X�́ACDcdDiagram2,CDcdDiagram �I�u�W�F�N�g�̑��������Ƃ�
	�`����s���܂��B

	<H4>
 �y�g�����P�|���I�Ɏq�E�C���h�E�𐶐�����z
	</H4>

	�P�D  �e�E�C���h�E�N���X�ł́A���̃N���X�̃C���X�^���X�𐶐����A
	 Create() ���\�b�h�ŃE�C���h�E�iHWND�j�𐶐����Ă��������B
	  ���̌�́A CWnd::ShowWindow() �E CWnd::UpdateWindow() 
	�ŁA�q�E�C���h�E����ʏ�ɕ\�����Ă��������B@n
	 �ʏ킱�̐����̎菇�́A�e�E�C���h�E�� OnCreate()(WM_CREATE) �ŁA
	�s�����ƂɂȂ�܂��B

	�Q�D  setCentDedDgrDia() �ŁA�Ή�����w�_�C���O�����_�C���x�I�u�W�F�N�g��
	this �̊֘A���m�����Ă��������B

	�R�D  readCdDedDispProp() �ŁA
	�_�C���O�����̊e���̐F��t�H���g�̑������w�肵�ĉ������B
	  �܂��A setVlineMode() �ŁA�r���̃��[�h��ݒ肵�Ă��������B

	�S�D  setZone_Dgr() �ŁA�E�C���h�E��ɕ\������_�C���O�����͈̔�
	�i�X�N���[���ʒu�j���w�肵�ĉ������B
	
	�T�D  this �͂���ȍ~�A OnPaint() �ŁA
	�w�_�C���O�����_�C���x CentDedDgrDia �I�u�W�F�N�g��
	�i�[����Ă���_�C���̏������ƂɁA�E�C���h�E��
	�_�C���O������`�悵�܂��B
	
	<H4>
 �y�g�����Q�|CentDedDgrDia �̍X�V���z
	</H4>

	 <H5>
	 CentDedDgrDia �I�u�W�F�N�g�̓��e���ω������ꍇ
	 </H5>

	onUpdateCentDedDgrDia() ���Ăяo���Ă��������B
	  ���̊֐��́A �X�N���[���o�[�͈̔͂��œK�����A�E�C���h�E���ĕ`�悵��
	�V�����_�C���̓��e���E�C���h�E�ɕ\�����܂��B

	 <H5>
	   CentDedDgrDia �I�u�W�F�N�g�ɕ�܂����
	�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g���ǉ��E�폜�E
	�ύX���ꂽ�ꍇ
	 </H5>

	   onUpdateCentDedDgrRessya() ���Ăяo���Ă��������B
	  ���̊֐��́A�E�C���h�E���ĕ`�悵�āA�V�����_�C���̓��e���E�C���h�E��
	�\�����܂��B

	<H4>
 �y�g�����R�|�e�E�C���h�E�j���z
	</H4>
	
 �P�D  �e�E�C���h�E���j�����ꂽ�Ƃ��i�e�E�C���h�E�� WM_DESTROY/OnDestroy() �j
	�ł́A���̃I�u�W�F�N�g�ɑ΂��� CWnd::DestroyWindow() ���Ăяo����
	CWndDcdGrid �� HWND ��j�����Ă���A���� CWndDcdGrid �I�u�W�F�N�g��
	�j�����Ă��������B


 */
class CWndDiagram : public CWnd
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
public:
	typedef CWnd	super ;
private:
	// ********************************
	///@name	���
	// ********************************
	///@{
	/**
		�w�_�C���O�����G���e�B�e�B�N���X�Q�x�̑��������ƂɁA IfDcdTarget 
		�I�u�W�F�N�g�Ɂw�_�C���O�����x��`�悵�܂��B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
		�R���X�g���N�^�Ő����E�f�X�g���N�^�łŔj�����܂��B
	*/
	CDcdDiagram2*	m_pCDcdDiagram ;
	///@}

	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
		�����l�͋U�ł��B
		�ŏ��� onUpdateCentDedDgrDia() �ŁA 
		.ini �t�@�C������A�X�N���[���ʒu��
		�r���̐ݒ��ǂݍ��񂾂��Ƃ́A�^�ƂȂ�܂��B
	 */
	bool m_bReadCWndDiagramDefault ;

	/**
		�X�N���[���o�[����
	*/
	CdScrollbarProp	m_CdScrollbarPropX ;
	/** @see m_CdScrollbarPropX */
	CdScrollbarProp	m_CdScrollbarPropY ;

	///@}
 protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		�����l�𐳋K�����܂��B
		�ΏۂƂȂ�̂́A�ȉ��̑����ł��B
	
		- m_pCDcdDiagram->m_zonexyZone_Dgr 
		(m_pCentDedDgrDia->Zone() �̓����ɂȂ�悤�ɐ��K�����܂��B)
	
	 @return
		���炩�̒l��ύX�����ꍇ�͐^�ł��B
	 */
	virtual bool update_adjustProp() ;

	/**
		�E�C���h�E��̃R���g���[�����A���݂̏󋵂ɍ��킹��
		�X�V���܂��B
	
		m_pCDcdDiagram �́A�_�C���O�����̕\���ʒu�̕ύX��
		���킹�āA�E�C���h�E���X�N���[�����܂��B

		�X�N���[���o�[���A
		m_pCDcdDiagram->m_zonexyZone_Dgr 
		�ɂ��킹�Ē������܂��B
	 */
	virtual void update_updateScreen() ;
	///@}
protected:
	// --------------------------------
	///@name MFC���b�Z�[�W�n���h���̉����֐�
	// --------------------------------
	///@{
	/**
		OnLButtonDblClk() �̉����֐��ł��B

		point ����Ԑ���ɂ���΁A�����\�r���[���J���A
		�����\�r���[�̃t�H�[�J�X�� point ���w���Ă���
		��ԁE�w�����Ɉړ������܂��B
	@param point [in]
		�}�E�X�J�[�\���̍��W���w�肵�Ă��������B
		���W�́A�N���C�A���g�̈�Ŏw�肵�Ă��������B
	@return 
		-	1 ;	//	�����\�r���[�ֈړ����܂���
		-	-1 ;	//	point ����Ԑ���ɂ���܂���B
		-	-2 ;	//	�_�C���O�����r���[�ɑΉ����� 
				CentDedDia ��������܂���B
		-	-3 ;	//	�����\�r���[���J���̂Ɏ��s���܂����B

	*/
	int OnLButtonDblClk_openJikokuhyouView( CPoint point) ;
	/**
		OnLButtonDblClk() �̉����֐��ł��B

		point ���A�����̉w���̈�ɂ���΁A
		�w�r���[���J���܂��B
		�܂��Apoint �̒����̗�Ԑ��̉w�́A
		�w�̃v���p�e�B�_�C�A���O���J���܂��B
	@param point [in]
		�}�E�X�J�[�\���̍��W���w�肵�Ă��������B
		���W�́A�N���C�A���g�̈�Ŏw�肵�Ă��������B
	@return 
		-	1 ;	//	�w�̃v���p�e�B�_�C�A���O���J���܂��B

	*/
	int OnLButtonDblClk_openDlgEkiProp( CPoint point) ;
	///@}
public:
	// ********************************
	///@name	CDcdDiagram-�֘A
	// ********************************
	///@{
	CentDedDgrDia* getCentDedDgrDia() ;
	CWndDiagram& setCentDedDgrDia( CentDedDgrDia* value ) ;
	///@}
public:
	// ********************************
	///@name CDcdDiagram-����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
	///@{
	virtual bool	getDisplayRessyabangou()const ;

	/**
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	virtual int setDisplayRessyabangou( bool value ) ;

	virtual bool	getDisplayRessyamei()const ;
	/**
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	virtual int setDisplayRessyamei( bool value ) ;

	CdDcdPosXy	getPosDgr()const ;

	/** @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	int setPosDgr( CdDcdPosXy value );

	double getDcdPerDgrX()const ;

	/** @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	int setDcdPerDgrX( double value ) ;

	double getDcdPerDgrY()const ;

	/** @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	int setDcdPerDgrY( double value ) ;


	virtual int	getVlineMode()const ;

	/**
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	virtual int setVlineMode( int value ) ;

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
	virtual bool getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const ;
	
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
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	 */
	virtual int setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) ;
	
	/**
		CDcdDiagram::m_eStopMarkDraw 
		�̒l���擾���܂��B
	 @return
		- StopMarkDraw_Not  ��ԋL����`�悵�܂���B  
		- StopMarkDraw_BriefStop  �Z���Ԓ�Ԃ̉w�ɁA��ԋL����`�悵�܂��B  
	*/
	virtual CDcdDiagram::EStopMarkDraw	getStopMarkDraw()const ;

	/**
		CDcdDiagram::m_eStopMarkDraw 
		�̒l��ݒ肵�܂��B
	 @param value [in]
		- StopMarkDraw_Not  ��ԋL����`�悵�܂���B  
		- StopMarkDraw_BriefStop  �Z���Ԓ�Ԃ̉w�ɁA��ԋL����`�悵�܂��B  
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	virtual int setStopMarkDraw( CDcdDiagram::EStopMarkDraw value ) ;

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
	virtual int getVlineChoices( Mui<CDcdDiagram::VLINE>* pContVLINE ) ;
	
	// ********************************
	///@name	CDcdDiagram-����
	// ********************************
	///@{
	/**
		CdDedDispProp �I�u�W�F�N�g�̑�������A 
		�_�C���O�����̊e���̐F��t�H���g�̑��������肵�܂��B
	
		�܂��A�E�C���h�E�̍ĕ`����s�킹�܂��B
	
		���̃��\�b�h���ݒ肷�鑮���́Am_pCDcdDiagram �̈ȉ��̂��̂ł��B
	
		- CdFontProp	m_fontpropDiaRessyaFont ;
		- COLORREF	m_colorDiaMojiColor ;
		- COLORREF	m_colorDiaHaikeiColor ;
		- COLORREF	m_colorDiaRessyaColor ;
		- COLORREF	m_colorDiaJikuColor ;
		- int m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
		- int m_iDiaRessyajouhouHyoujiEkiOrderNobori ;
		
	 @param value [in]
		CdDedDispProp �I�u�W�F�N�g���w�肵�ĉ������B
	 @return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		�A���A����ł� 0 �����Ԃ��܂���B
	 */	
	virtual int readCdDedDispProp( const CdDedDispProp& value ) ;
	
	/**
		���̃N���X���`����s���̈�̍��W���A
	 	�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏ擾���܂��B
		���̒l�́Am_posDgr�Em_dwDcdPerDgrX�Em_dwDcdPerDgrY ����
		���o����܂��B
	@return 
		���̃N���X���`����s���̈�̍��W��
		�w�_�C���O�����G���e�B�e�B���W�n�x�ŕԂ��܂��B
	@attention
		pIfDcdTarget �ւ̃_�C���O�����\�����s�\�ȏꍇ�A
		�߂�l��getX().getSize() , getY().getSize() �̂����ꂩ��
		0�ɂȂ�܂��B
	*/
	virtual CdDcdZoneXy	getZone_Dgr()const ;

	/**
		���̃N���X���`����s���̈�̍��W���A
	 	�w�_�C���O�����G���e�B�e�B���W�n�x�Őݒ肵�܂��B
		���̒l�́Am_posDgr�Em_dwDcdPerDgrX�Em_dwDcdPerDgrY ��
		���Z�̂����Őݒ肳��܂��B
	@param value [in]
		���̃N���X���`����s���̈�̍��W��
		�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏw�肵�Ă��������B

		�_�C���O������ pIfDcdTarget ���ɕ`��ł��Ȃ��ꍇ�́A
		setZone_Dgr() �͓��삵�܂���B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	 */
	virtual int setZone_Dgr( const CdDcdZoneXy& value ) ;
	
	/**
		�E�C���h�E�T�C�Y�ύX���̓�����擾���܂��B
	@return 
		- false:�\���͈͂�ύX(OuDia Ver.1.00.04 ����)
		- true: �\���͈͂�ύX���Ȃ�(OuDia Ver.1.00.04 �݊�)
	*/
	bool getKeepZoneDgrOnSize()const ;

	/**
		�E�C���h�E�T�C�Y�ύX���̓����ݒ肵�܂��B
	@param value [in] 
		- false:�\���͈͂�ύX(OuDia Ver.1.00.04 ����)
		- true: �\���͈͂�ύX���Ȃ�(OuDia Ver.1.00.04 �݊�)
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	int setKeepZoneDgrOnSize( bool value );
	
	///@}	
	
	
	// ********************************
	///@name	CDcdDiagrem-����
	// ********************************
	///@{
	///@}
	// ********************************
	///@name	CDcdDiagrem2-����
	// ********************************
	///@{
	bool getHideIppanekiEkimei()const ;

	/**
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�l���ύX����A�E�C���h�E���ĕ`�悳��܂����B
	*/
	int setHideIppanekiEkimei( bool value )  ;
	///@}
	// ********************************
	///@name	CDcdDiagrem2-����
	// ********************************
	///@{
	/**
		�E�C���h�E���ŁA�_�C���O������`�悷��̈�̑傫�������߂܂��B
		�P�ʂ́A IfDcdTarget ��̍��W�ł��B
	 @return
		�_�C���O�����̕`��̈��Ԃ��܂��B
		���̒l�� X,Y �����ꂩ�̃T�C�Y��0�ȉ��̏ꍇ�A
		�_�C���O�����̕`��͂ł��܂���B
	 */
	virtual CdDcdZoneXy calcDiagramZoneDcd()const ;
	///@}
	// ********************************
	///@name	CWndDiagram-���
	// ********************************
	///@{
	CDcdDiagram2* getCDcdDiagram() ;
	///@}

	// ********************************
	///@name	CWndDiagram-�\�z
	// ********************************
	///@{
	/**
		�E�C���h�E��HWND�𐶐����܂��B
	 @param rect [in]
		�E�C���h�E�̃T�C�Y�ƈʒu���w�肵�܂��B
		CRect �I�u�W�F�N�g�܂��� RECT �\���̂��w��ł��܂��B
	 @param pParentWnd [in]
		�R���g���[���̐e�E�B���h�E (CDialog�̏ꍇ������) ���w�肵�܂��B
		NULL �͎w��ł��܂���B
	 @param nID [in]
		�R���g���[���� ID ���w�肵�܂��B
	 */
	BOOL Create( const RECT& rect, CWnd* pParentWnd, UINT nID = 0 );

	/**
		�T�C�Y�O�ŁA�E�C���h�E��HWND�𐶐����܂��B
		�e�E�C���h�E�̃T�C�Y�����ƂɈʒu�����肷��ꍇ�ɂ́A
		��������g�����Ƃ��ł��܂��B
	 @param pParentWnd [in]
		�R���g���[���̐e�E�B���h�E (CDialog�̏ꍇ������) ���w�肵�܂��B
		NULL �͎w��ł��܂���B
	 @param nID [in]
		�R���g���[���� ID ���w�肵�܂��B
	 */
	BOOL Create( CWnd* pParentWnd, UINT nID  = 0 );
	///@}

	///@}

	// ********************************
	///@name	CWndDiagram-����
	// ********************************
	///@{
	/**
		�N���X���[�U�[�́A
		 m_pCentDedDgrDia �I�u�W�F�N�g�̓��e���X�V�����Ƃ��ɁA
		onUpdateCentDedDgrDia() ���Ăяo���Ă��������B
		  ���̊֐��́A �X�N���[���o�[�͈̔͂��œK�����A�E�C���h�E���ĕ`�悵��
		�V�����_�C���̓��e���E�C���h�E�ɕ\�����܂��B
	 */
	virtual void onUpdateCentDedDgrDia() ;
	
	/**
		�N���X���[�U�[�́A
		   CentDedDgrDia �I�u�W�F�N�g�ɕ�܂����
		�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g���ǉ��E�폜�E
		�ύX���ꂽ�ꍇ
		   onUpdateCentDedDgrRessya() ���Ăяo���Ă��������B
		  ���̊֐��́A�E�C���h�E���ĕ`�悵�āA�V�����_�C���̓��e���E�C���h�E��
		�\�����܂��B
	 */
	virtual void onUpdateCentDedDgrRessya() ;
	///@}

// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	CWndDiagram();

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CWndDiagram)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CWndDiagram();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CWndDiagram)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewDiagram

#endif // !defined(AFX_CWNDDIAGRAM_H__E5EA7615_628B_4059_BBA7_DD1DB661E133__INCLUDED_)
