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
//	CentDedDgrRessyasenCont.h
//	$Id: CentDedDgrRessyasenCont.h 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
#ifndef  CentDedDgrRessyasenCont_h
#define  CentDedDgrRessyasenCont_h
/** @file */
#include "NsMu\CMuiCopied.h"
#include "entDgr\CentDedDgrRessyasen.h"
#include "entDgr\CentDedDgrEkiCont.h"

namespace entDgr{

class CentDedDgrRessya ;

// ****************************************************************
//	CentDedDgrRessyasenCont
// ****************************************************************
/**
@brief
	�w�_�C���O�����G���e�B�e�B�N���X�Q�x��
	�w��Ԑ��x�N���X CentDedDgrRessyasen ��ێ�����R���e�i�ł��B
	
	���̃N���X�́A�w��Ԑ��R���e�i�x (CentDedDgrRessyasenCont) ��
	��܂���܂��B���d�x�́A
	
	�w��ԁx (CentDedDgrRessya):�w��Ԑ��R���e�i�xCentDedDgrRessyasenCont
	=1:1

	�w��Ԑ��R���e�i�xCentDedDgrRessyasenCont :�w��Ԑ��xCentDedDgrRessyasen 
	=1:�i0�ȏ㕡���j
	
	�ƂȂ�܂��B
	
	�܂��A���̃N���X�� Mu<CentDedDgrEkiJikoku> �Ɗ֘A�������܂��B
	���̃R���e�i�ɗ�Ԑ���ǉ�����ƁA�֘A����
	Mu<CentDedDgrEkiJikoku> ���� CentDedDgrEkiJikoku::m_iDgrXZahyouRessyasen
	�ɑ������ݒ肳��܂��B
*/
class CentDedDgrRessyasenCont : public CMuiCopied<CentDedDgrRessyasen>
{
public:
	typedef CMuiCopied<CentDedDgrRessyasen>	super ;
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		���̃I�u�W�F�N�g��ێ������ԃI�u�W�F�N�g�B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis����������Ԃ͐������Ȃ��Ă͂Ȃ�܂���B

		���̊֘A�́Am_pCentDedDgrRessya->m_pCentDedDgrRessyasenCont ����A
		Mu< CdDedDgrEki >�@�ɃA�N�Z�X���邽�߂ɕK�v�ɂȂ�܂��B

	*/
	CentDedDgrRessya* m_pCentDedDgrRessya ;

	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CentDedDgrRessyasenCont( 
		CentDedDgrRessya* pCentDedDgrRessya ) ;
private:
	CentDedDgrRessyasenCont( const CentDedDgrRessyasenCont& value ) ;
public:
	CentDedDgrRessyasenCont& operator=( const CentDedDgrRessyasenCont& value ) ;


protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		iEkiOrderBegin , iEkiOrderEnd �̊Ԃɂ���
		CentDedDgrEkiJikoku ��
		CentDedDgrEkiJikoku::m_iDgrXPosRessyasen �ɁA
		�uiEkiOrderBegin �� iEkiOrderEnd �����Ԓ����v�Ɖw�̌�_�� DgrXPos ��ݒ肵�܂��B
	@param iEkiOrderBegin [in]
		���̋N�_�� �wOrder�B
	@param iEkiOrderEnd [in]
		���̏I�_�� �wOrder�B
	@return 
		���������� 0�ȏ�A�G���[�Ȃ畉�̐�
		-	0 ;	//	����
		-	-1 ;	//	iEkiOrderBegin ��X���W(m_iDgrXChaku,m_iDgrXHatsu�̂����ꂩ)������܂���B
		-	-2 ;	//	iEkiOrderEnd ��X���W(m_iDgrXChaku,m_iDgrXHatsu�̂����ꂩ)������܂���B
	*/
	void setDgrXPosRessyasen( 
		int iEkiOrderBegin ,  
		int iEkiOrderEnd  ) ;

	/**
		iEkiOrderBegin , iEkiOrderEnd �̊Ԃɂ���
		CentDedDgrEkiJikoku ��
		CentDedDgrEkiJikoku::m_iDgrXPosRessyasen �� 
		INT_MIN �Ƀ��Z�b�g���܂��B

		iEkiOrderBegin �ƁA iEkiOrderEnd ��
		CentDedDgrEkiJikoku::m_iDgrXPosRessyasen �͍X�V����܂���B
	@param iEkiOrderBegin [in]
		�����Ώۂ̍ŏ��̉w�����B
	@param iEkiOrderEnd [in]
		�����Ώۂ̏I�[�̉w�����B
		
	*/
	void clearDgrXPosRessyasen( 
		int iEkiOrderBegin , 
		int iEkiOrderEnd ) ;

	///@}

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f�̃R�s�[��ǉ����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int insert( const CentDedDgrRessyasen& element , int iIndex = INT_MAX ) ;
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
	 	�v�f���폜���܂��B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param iSize [in]
	 	�폜����v�f�̐����w�肵�Ă��������B
	 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
	 @attention
		iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) ;
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f���㏑�����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int set( const CentDedDgrRessyasen& element , int iIndex ) ;
	///@}
public:
	// ********************************
	///@name CentDedDgrRessyasenCont::�֘A
	// ********************************
	///@{
	CentDedDgrRessya* getCentDedDgrRessya() ;
	///@}

};

} //namespace entDgr

#endif /*CentDedDgrRessyasenCont_h*/
