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
//	CentDedRessyasyubetsu.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyasyubetsu_h
#define  CentDedRessyasyubetsu_h

#include <string>
using namespace std ;

#include <windows.h>

// ****************************************************************
//	CentDedRessyasyubetsu
// ****************************************************************
/**
 * @brief
 *	�y�T�v�z  DiagramEdit �́A�H����ŉ^�s������Ԃ́w��Ԏ�ʁx
 *	�P��ނ�\���܂��B
 *	
 *	  �����Ƃ��āA�w��ʖ��x�ƁA���̗�Ԏ�ʂ�\�����鎞���\�r���[�E
 *	�_�C���O�����r���[�ł̕`��F�E���X�^�C����ێ����܂��B
 */
class CentDedRessyasyubetsu
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**
	 *	��(����)�̌`���\���񋓂ł��B
	 */
	enum ESenStyle
	{
		/** ���� */
		SenStyle_Jissen = 0 ,
		/** �j�� */
		SenStyle_Hasen ,
		/** �_�� */
		SenStyle_Tensen ,
		/** ��_���� */
		SenStyle_Ittensasen ,
	};
	
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	��ʖ��B
	 *
	 *	�K��l�́A�󕶎���B
	 *
	 *	���̒l���󕶎���̏ꍇ�A���̃I�u�W�F�N�g�͖����ł��B
	 */
	string	m_strSyubetsumei ;
	
	/**
	 *	���́i��ʖ��̗��́j�B
	 *
	 *	�K��l�́A�󕶎���B
	 */
	string	m_strRyakusyou ;
	
	/**
	 *	�����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)
	 *
	 *	�K��l�́A���B
	 */
	COLORREF	m_colorJikokuhyouMojiColor ;
	
	/**
	 *	�_�C���O�����̐��F�B
	 *
	 *	�K��l�́A���B
	 */
	COLORREF	m_colorDiagramSenColor ;

	/**
	 *	�_�C���O�����̐��X�^�C���B
	 *
	 *	�K��l�́A SenStyle_Jissen
	 */
	ESenStyle	m_eDiagramSenStyle ;
	
	/**
	 *	�_�C���O�����̐��̑����B
	 *
	 *	�_�C���O�����̐��������ł���� true�B
	 *	�א��Ȃ� false �ł��B
	 *
	 *	�K��l�́A false �ł��B
	 */
	bool m_bDiagramSenIsBold ;
///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param strSyubetsumei [in]
	 *	��ʖ��B
	 * @param strRyakusyou [in]
	 *	���́i��ʖ��̗��́j�B
	 * @param colorJikokuhyouMojiColor [in]
	 *	�����\�����F�B
	 * @param colorDiagramSenColor [in] 
	 *	�_�C���O�����̐��F�B
	 * @param eDiagramSenStyle [in]
	 *	�_�C���O�����̐��X�^�C���B
	 * @param bDiagramSenIsBold [in]
	 *	�_�C���O�����̐��̑����B
	 *	�_�C���O�����̐��������ł���� true�B
	 *	�א��Ȃ� false �ł��B
	 */
	CentDedRessyasyubetsu( 
			const string& strSyubetsumei ,
			const string& strRyakusyou ,
			COLORREF	colorJikokuhyouMojiColor = RGB( 0 , 0 ,0 ), 
			COLORREF	colorDiagramSenColor = RGB( 0 , 0 , 0 ),
			ESenStyle	eDiagramSenStyle = SenStyle_Jissen ,
			bool bDiagramSenIsBold = false ) :
		m_strSyubetsumei( strSyubetsumei ) ,
		m_strRyakusyou( strRyakusyou ) ,
		m_colorJikokuhyouMojiColor( colorJikokuhyouMojiColor ) , 
		m_colorDiagramSenColor( colorDiagramSenColor ) ,
		m_eDiagramSenStyle( eDiagramSenStyle ) ,
		m_bDiagramSenIsBold( bDiagramSenIsBold ){};

	CentDedRessyasyubetsu() :
		m_colorJikokuhyouMojiColor( RGB( 0 , 0 , 0 ) ) , 
		m_colorDiagramSenColor( RGB( 0 , 0 , 0  ) ) ,
		m_eDiagramSenStyle( SenStyle_Jissen ) ,
		m_bDiagramSenIsBold( false ){};



// ********************************
//	CentDedRessyasyubetsu
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	string	getSyubetsumei()const{	return 	m_strSyubetsumei ;};
	CentDedRessyasyubetsu& setSyubetsumei( const string& value ){
		m_strSyubetsumei = value ; return *this ; } ;

	string	getRyakusyou()const{	return m_strRyakusyou ;};
	CentDedRessyasyubetsu& setRyakusyou( const string& value ){
		m_strRyakusyou = value ; return *this ; } ;
	
	COLORREF	getJikokuhyouMojiColor()const{
		return m_colorJikokuhyouMojiColor ;};
	CentDedRessyasyubetsu& setJikokuhyouMojiColor( COLORREF	value ){
		m_colorJikokuhyouMojiColor = value ; return *this ; } ;
	COLORREF	getDiagramSenColor()const{
		return 	m_colorDiagramSenColor ;};
	CentDedRessyasyubetsu& setDiagramSenColor( COLORREF	value ){
		m_colorDiagramSenColor = value ; return *this ; } ;

	ESenStyle	getDiagramSenStyle()const{	return m_eDiagramSenStyle ;};
	CentDedRessyasyubetsu& setDiagramSenStyle( ESenStyle value ){
		m_eDiagramSenStyle = value ; return *this ;};
	bool getDiagramSenIsBold()const{ return m_bDiagramSenIsBold ; };
	CentDedRessyasyubetsu& setDiagramSenIsBold( bool value ){
		m_bDiagramSenIsBold = value ; return *this ;};


	///@}

	// ********************************
	///@name ����
	// ********************************
	///@{

	///@}
};


#endif /*CentDedRessyasyubetsu_h*/


