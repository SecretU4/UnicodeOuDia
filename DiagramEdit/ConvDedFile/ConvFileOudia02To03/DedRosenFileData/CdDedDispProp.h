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
//	CdDedDispProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDedDispProp_h
#define  CdDedDispProp_h

#include "DcDraw/CdFontProp.h"

// ****************************************************************
//	CdDedDispProp
// ****************************************************************
/**
 * @brief
 *	�y�T�v�z  DiagramEdit �̕\���Ɋ֌W����v���p�e�B��ێ�����
 *	�P���f�[�^�N���X�ł��B
 */
class CdDedDispProp
{
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	 �����\��ʃt�H���g�B
	 *	�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropJikokuhyouFont ;

	/**
	 *	 �_�C����ʉw���t�H���g�B
	 *	�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaEkimeiFont ;

	/**
	 *	 �_�C����ʎ����t�H���g�B
	 *	�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaJikokuFont ;

	/**
	 *	 �_�C����ʗ�ԃt�H���g�B
	 *	�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaRessyaFont ;

	/**
	 *	 �R�����g�r���[�t�H���g�B
	 *	�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropViewComment ;

	/**
	 *	 �_�C����ʕ����F�B
	 *	�K��l�́A���B
	 */
	COLORREF	m_colorDiaMojiColor ;
	/**
	 *	 �_�C����ʔw�i�F�B
	 *	�K��l�́A���B
	 */
	COLORREF	m_colorDiaHaikeiColor ;
	/**
	 *	 �_�C����ʗ�Ԑ��F�B
	 *	�K��l�́A���B
	 */
	COLORREF	m_colorDiaRessyaColor ;
	/**
	 *	 �_�C����ʏc�����F�B
	 *	�K��l�́A���B
	 */
	COLORREF	m_colorDiaJikuColor ;

	/**
	 *	�w�����̕���ێ����܂��B
	 *	�P�ʂ́A�S�p�ł̕������ł��B
	 *	�܂�A�w�����̕��́A
	 *
	 *		�����̍��� �~ m_iEkimeiLength 
	 *	
	 *	�ƂȂ�܂��B
	 *	�f�t�H���g�l�� 6 �Ƃ��܂��B�ŏ��l�� 1 �ł��B
	 */
	int m_iEkimeiLength ;

	/**
	 *	 �_�C����ʗ�ԏ��\���ʒu:�w�wOrder�x
	 *	������( Ressyahoukou_Kudari )�́A
	 *	��ԏ���\������ʒu���A�w�wOrder�x�Ŏw�肵�܂��B
	 *
	 *	�A���A���̒l���w�w�x ( CentDedEki ) �̐��ȏ�̏ꍇ�́A
	 *	( �w�w�x�̐�  - 1 ) ���w�肳��Ă�����̂Ƃ݂Ȃ��܂��B
	 *	
	 *	�K��l�� 0 �ł��B
	 *	
	 * @attention
	 *	�w�wOrder�x�ɂ��ẮA CentDedRessya ���Q�Ƃ��Ă��������B
	 */
	int m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
	/**
	 *	�����( Ressyahoukou_Nobori )�́A
	 *	��ԏ���\������ʒu���A�w�wOrder�x�Ŏw�肵�܂��B
	 * @see m_iDiaRessyajouhouHyoujiEkiOrderKudari 
	 */
	int m_iDiaRessyajouhouHyoujiEkiOrderNobori ;

///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CdDedDispProp() :
		m_fontpropJikokuhyouFont( 9 ,"�l�r �S�V�b�N"  ) ,
		m_fontpropDiaEkimeiFont( 9 ,"�l�r �S�V�b�N"  ) ,
		m_fontpropDiaJikokuFont( 9 ,"�l�r �S�V�b�N"  ) ,
		m_fontpropDiaRessyaFont( 9 ,"�l�r �S�V�b�N"  ) ,
		m_fontpropViewComment( 9 ,"�l�r �S�V�b�N"  ) ,
		m_colorDiaMojiColor( RGB( 0 , 0 , 0 ) ) ,
		m_colorDiaHaikeiColor( RGB( 255 , 255 , 255 ) ) ,
		m_colorDiaRessyaColor( RGB( 0 , 0 , 0 ) ) ,
		m_colorDiaJikuColor( RGB(192 , 192 , 192 ) ) ,
		m_iEkimeiLength( 6 ) ,
		m_iDiaRessyajouhouHyoujiEkiOrderKudari( 0 ) ,
		m_iDiaRessyajouhouHyoujiEkiOrderNobori( 0 ) {};
	
	
// ********************************
//	CdDedDispProp
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	CdFontProp	getJikokuhyouFont()const{
		return 	m_fontpropJikokuhyouFont ;};
	CdDedDispProp& setJikokuhyouFont( const CdFontProp& value ){
		m_fontpropJikokuhyouFont = value ; return *this ;};
	CdFontProp	getDiaEkimeiFont()const{
		return 	m_fontpropDiaEkimeiFont ;};
	CdDedDispProp& setDiaEkimeiFont( const CdFontProp& value ){
		m_fontpropDiaEkimeiFont = value ; return *this ;};
	CdFontProp	getDiaJikokuFont()const{
		return 	m_fontpropDiaJikokuFont ;};
	CdDedDispProp& setDiaJikokuFont( const CdFontProp& value ){
		m_fontpropDiaJikokuFont = value ; return *this ;};
	CdFontProp	getDiaRessyaFont()const{
		return 	m_fontpropDiaRessyaFont ;};
	CdDedDispProp& setDiaRessyaFont( const CdFontProp& value ){
		m_fontpropDiaRessyaFont = value ; return *this ;
	};
	CdFontProp	getViewCommentFont()const{	return m_fontpropViewComment ;};
	CdDedDispProp& setViewCommentFont( const CdFontProp& value ){
		m_fontpropViewComment = value ; return *this ; 
	};


		
	COLORREF	getDiaMojiColor()const{
		return m_colorDiaMojiColor ;};
	CdDedDispProp& setDiaMojiColor( COLORREF value ){
		m_colorDiaMojiColor = value ; return *this ;};
	COLORREF	getDiaHaikeiColor()const{
		return m_colorDiaHaikeiColor ;};
	CdDedDispProp& setDiaHaikeiColor( COLORREF value ){
		m_colorDiaHaikeiColor = value ; return *this ;};
	COLORREF	getDiaRessyaColor()const{
		return m_colorDiaRessyaColor ;};
	CdDedDispProp& setDiaRessyaColor( COLORREF value ){
		m_colorDiaRessyaColor = value ; return *this ;};
	COLORREF	getDiaJikuColor()const{
		return m_colorDiaJikuColor ;};
	CdDedDispProp& setDiaJikuColor( COLORREF value ){
		m_colorDiaJikuColor = value ; return *this ;};

	int getEkimeiLength()const{ return m_iEkimeiLength ;};
	CdDedDispProp& setEkimeiLength( int value ){
		m_iEkimeiLength = value ;
		if ( m_iEkimeiLength < 1 ){
			m_iEkimeiLength = 1 ;
		}
		if ( m_iEkimeiLength > 20 ){
			m_iEkimeiLength = 20 ;
		}
		return *this ;
	};

	/**
	 * @return
	 *	�w���̕����擾���邽�߂̕�������쐬���܂��B
	 *	���̊֐��́A�S�p������ m_iEkimeiLength �������ׂ�
	 *	������i���e�͎g��Ȃ��j��Ԃ��܂��B
	 */
	string createEkimeiExtentString()const 
	{
		string	strRv ;
		for ( int idx = 0 ; idx < m_iEkimeiLength ; idx ++ ){
			strRv += "��" ;
		}
		return strRv ;
	};
	

	
	int getDiaRessyajouhouHyoujiEkiOrder( ERessyahoukou eRessyahoukou )const{
		if ( eRessyahoukou == Ressyahoukou_Kudari ){
			return m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
		}
		return m_iDiaRessyajouhouHyoujiEkiOrderNobori ;
	};
	CdDedDispProp& setDiaRessyajouhouHyoujiEkiOrder( 
		 ERessyahoukou eRessyahoukou , int value ){
		if ( eRessyahoukou == Ressyahoukou_Kudari ){
			m_iDiaRessyajouhouHyoujiEkiOrderKudari = value ;
		}	else	{
			m_iDiaRessyajouhouHyoujiEkiOrderNobori = value ;
		}
		return *this ;
	};

	/**
	 *	���ׂĂ̑������A
	 *	������ԁi�f�t�H���g�R���X�g���N�^�Ő���������ԁj
	 *	�ɂ��܂��B
	 */
	void clear(){	*this = CdDedDispProp() ; } ;
	///@}
};
#endif /*CdDedDispProp_h*/


