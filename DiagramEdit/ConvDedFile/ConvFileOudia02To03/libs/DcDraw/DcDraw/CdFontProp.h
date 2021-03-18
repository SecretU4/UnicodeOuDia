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
//	CdFontProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdFontProp_h
#include <string>
using namespace std ;

// ****************************************************************
//	CdFontProp
// ****************************************************************
/**
* @brief
* �y�T�v�z
* 	�t�H���g�̑����̃f�[�^��ێ�����A�P���f�[�^�N���X�ł��B
*/
class CdFontProp
{
// ********************************
/// @name	����
// ********************************
///@{
 private:
	/**
	 * 	�t�H���g�̕����̍����ł��B�P�ʂ̓|�C���g�P��(point*72=twip)�ł��B
	 * 	���̒l�������ȂƂ��́A�O�ɂȂ�܂��B
	 *
	 *	�f�t�H���g��0�ł��B
	 * @attention
	 *	LogicalunitTextHeight�ELogicalunitCellHeight�EPointTextHeight
	 *	�́A���݂ɔr���I�ł��B�L���ɂȂ�̂́A�����ꂩ�P�����ł��B
	 */
	int		m_iPointTextHeight ;
	
	/**
	 * 	�t�H���g�̕����̍����ł��B�P�ʂ͘_���P�ʂł��B
	 * 	���̒l�������ȂƂ��́A�O�ɂȂ�܂��B
	 *
	 *	�f�t�H���g��0�ł��B
	 * @attention
	 *	LogicalunitTextHeight�ELogicalunitCellHeight�EPointTextHeight
	 *	�́A���݂ɔr���I�ł��B�L���ɂȂ�̂́A�����ꂩ�P�����ł��B
	 */
	int		m_iLogicalunitTextHeight ;
	
	/**
	 * 	�t�H���g�̃Z���̍����ł��B�P�ʂ͘_���P�ʂł��B
	 * 	���̒l�������ȂƂ��́A�O�ɂȂ�܂��B
	 *
	 *	�f�t�H���g��0�ł��B
	 * @attention
	 *	LogicalunitTextHeight�ELogicalunitCellHeight�EPointTextHeight
	 *	�́A���݂ɔr���I�ł��B�L���ɂȂ�̂́A�����ꂩ�P�����ł��B
	 */
	int		m_iLogicalunitCellHeight ;
	
	/**
	 * 	���̖��̕�����ł��B
	 * (��)"�l�r  �S�V�b�N"
	 *
	 *	�f�t�H���g�́A�󕶎���ł��B�Œ���ݒ�̕K�v�ȑ����ł��B
	 */
	string	m_strFacename ;
	
	/**	
	 *	�ʏ�͋U�A�����Ȃ�^�ł��B	
	 */
	bool	m_bBold ;
	
	/**	
	 *	�ʏ�͋U�A�Α̂Ȃ�^�ł��B
	 */
	bool	m_bItaric ;
	
	/**	
	 *	�ʏ�͋U�A����������ΐ^�ł��B	
	 */
	bool	m_bUnderine ;
	
	/**	
	 *	�ʏ�͋U�A�ł�����������ΐ^�ł��B	
	 */
	bool	m_bStrikeOut ;

	
	/**
	 *	���̃t�H���g�ŕ\�������e�e�L�X�g�s�̊p�x 
	 *	(�y�[�W�̍ŉ�������̑��Ίp�x) �� 
	 *	10����1�x�P�ʂŎw�肵�܂��B
	 *
	 *	����l�� 0 �ł��B
	 *	�c�����t�H���g���g�p����ꍇ�́A�ʏ�� 2700 �Ƃ��܂��B
	 */
	int m_iEscapement ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 *	�|�C���g�P�ʂ̕����̍����Ə��̖�����{�ɂ����t�H���g�������w�肷��
	 *	�R���X�g���N�^�ł��B
	 * @param iPointTextHeight [in]
	 * 	�t�H���g�̕����̍����ł��B�P�ʂ̓|�C���g�P��(point*72=twip)�ł��B
	 * @param strFacename [in]
	 * 	���̖��̕�����ł��B
	 * (��)"�l�r  �S�V�b�N"
	 * @param bBold [in]
	 *	�ʏ�͋U�A�����Ȃ�^�ł��B	
	 * @param bItaric [in]
	 *	�ʏ�͋U�A�Α̂Ȃ�^�ł��B
	 * @param bUnderine [in]
	 *	�ʏ�͋U�A����������ΐ^�ł��B	
	 * @param bStrikeOut [in]
	 *	�ʏ�͋U�A�ł�����������ΐ^�ł��B	
	 */
	CdFontProp( int iPointTextHeight , const string& strFacename ,
		bool bBold = false , bool bItaric = false , 
		bool bUnderine = false , bool bStrikeOut = false ):
		m_iPointTextHeight( iPointTextHeight ) ,
		m_iLogicalunitTextHeight( 0 ) ,
		m_iLogicalunitCellHeight( 0 ) ,
		m_strFacename( strFacename ) ,
		m_bBold( bBold ) ,
		m_bItaric( bItaric ) ,
		m_bUnderine( bUnderine ) ,
		m_bStrikeOut( bStrikeOut ) , 
		m_iEscapement( 0 ) {};
	
	/**
	 *	�f�t�H���g�R���X�g���N�^�B
	 *	���̃R���X�g���N�^�ł́A�L���ȃt�H���g�����͐ݒ肳��܂���B
	 */
	CdFontProp() : 
		m_iPointTextHeight( 0 ) ,
		m_iLogicalunitTextHeight( 0 ) ,
		m_iLogicalunitCellHeight( 0 ) ,
		m_bBold( false ) ,
		m_bItaric( false ) ,
		m_bUnderine( false ) ,
		m_bStrikeOut( false ) , 
		m_iEscapement( 0 ) {};
	
	virtual ~CdFontProp(){} ;

// ********************************
//	CdFontProp
// ********************************
 public:
	// ********************************
	/// @name	����
	// ********************************
	///@{
	int getPointTextHeight()const{	
		return m_iPointTextHeight ;};
	CdFontProp& setPointTextHeight( int ev ){
		m_iPointTextHeight = ev ;
		m_iLogicalunitTextHeight = 0 ;
		m_iLogicalunitCellHeight = 0 ;
		return *this ;
	};
	
	int getLogicalunitTextHeight()const{	
		return m_iLogicalunitTextHeight ;};
	CdFontProp& setLogicalunitTextHeight( int ev ){
		m_iPointTextHeight = 0 ;
		m_iLogicalunitTextHeight = ev ;
		m_iLogicalunitCellHeight = 0 ;
		return *this ;
	};
	
	int getLogicalunitCellHeight()const{	
		return m_iLogicalunitCellHeight ;};
	CdFontProp& setLogicalunitCellHeight( int ev ){
		m_iPointTextHeight = 0 ;
		m_iLogicalunitTextHeight = 0 ;
		m_iLogicalunitCellHeight = ev ;
		return *this ;
	};
	
	string	getFacename()const{	return m_strFacename ;	};
	CdFontProp& setFacename( const string& ev ){
		m_strFacename = ev ;	return *this ; } ;
	
	bool	getBold()const{
		return m_bBold ;	};
	CdFontProp& setBold( bool ev ){
		m_bBold = ev ;	return *this ; } ;
	bool	getItaric()const{
		return m_bItaric ;	};
	CdFontProp& setItaric( bool ev ){
		m_bItaric = ev ;	return *this ; } ;
	bool	getUnderine()const{
		return m_bUnderine ;	};
	CdFontProp& setUnderine( bool ev ){
		m_bUnderine = ev ;	return *this ; } ;
	bool	getStrikeOut()const{
		return m_bStrikeOut ;	};
	CdFontProp& setStrikeOut( bool ev ){
		m_bStrikeOut = ev ;	return *this ; } ;
	int getEscapement()const{
		return m_iEscapement ;};
	CdFontProp&  setEscapement( int value ){
		m_iEscapement = value ; return *this ; } ;

	/**
	 *	���̃t�H���g�ŕ\�������e�e�L�X�g�s�̊p�x�� 
	 *	�������p�ɐݒ肵�܂��B
	 *	�܂�A m_iEscapement �� 0 �ɂ��܂��B
	 */
	CdFontProp&  setIsEscapementHolyzontal(){
		m_iEscapement = 0 ; return *this ; } ;

	/**
	 *	���̃t�H���g�ŕ\�������e�e�L�X�g�s�̊p�x�� 
	 *	�c�����p�ɐݒ肵�܂��B
	 *	�܂�A m_iEscapement �� 2700 �ɂ��܂��B
	 */
	CdFontProp&  setIsEscapementVertical(){
		m_iEscapement = 2700 ; return *this ; } ;


	/**
	 * @return
	 *	���̃t�H���g�ŕ\�������e�e�L�X�g�s�̊p�x�� 
	 *	�������p�ɐݒ肳��Ă�����
	 *	�i m_iEscapement �� 0 �Ȃ�j�^�ł��B
	 */
	bool getIsEscapementHolyzontal()const{
		return m_iEscapement == 0 ; } ;

	/**
	 * @return
	 *	���̃t�H���g�ŕ\�������e�e�L�X�g�s�̊p�x�� 
	 *	�c�����p�ɐݒ肳��Ă�����
	 *	�i m_iEscapement �� 2700 �Ȃ�j�^�ł��B
	 */
	bool getIsEscapementVertical()const{
		return m_iEscapement == 2700 ; } ;



	/**
	 *	2�̃I�u�W�F�N�g�̊e���������������ǂ����𔻒肵�܂��B
	 * @param value [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	value �� *this �Ƃ̊ԂŁA���ׂĂ̑�������������ΐ^�ł��B
	 */
	bool isEqualTo( const CdFontProp& value )const{
		return ( 
			m_iPointTextHeight == value.m_iPointTextHeight && 
			m_iLogicalunitTextHeight == value.m_iLogicalunitTextHeight && 
			m_iLogicalunitCellHeight == value.m_iLogicalunitCellHeight && 
			m_strFacename == value.m_strFacename &&
			m_bBold == value.m_bBold && 
			m_bItaric == value.m_bItaric &&
			m_bUnderine == value.m_bUnderine && 
			m_bStrikeOut == value.m_bStrikeOut &&  
			m_iEscapement == value.m_iEscapement ) ;
	} ;
	/**
	 *	isEqualTo() �Ɠ����ł��B
	 */
	bool operator==( const CdFontProp& value )const{
		return ( isEqualTo( value ) ) ;
	};
	bool operator!=( const CdFontProp& value )const{
		return ( !isEqualTo( value ) ) ;
	};

	/**
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 * @param b [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 */
	bool  less( const CdFontProp& b )const{
			if ( this->m_iPointTextHeight != b.m_iPointTextHeight ){
				return ( this->m_iPointTextHeight < b.m_iPointTextHeight ) ;
			}	else if ( this->m_iLogicalunitTextHeight != 
					b.m_iLogicalunitTextHeight ){
				return ( this->m_iLogicalunitTextHeight < 
					b.m_iLogicalunitTextHeight ) ;
			}	else if ( this->m_iLogicalunitCellHeight != 
					b.m_iLogicalunitCellHeight ){
				return ( this->m_iLogicalunitCellHeight < 
					b.m_iLogicalunitCellHeight ) ;
			}	else if ( this->m_strFacename != b.m_strFacename ){
				return ( this->m_strFacename < b.m_strFacename ) ;
			}	else if ( this->m_bBold != b.m_bBold ){
				return ( this->m_bBold < b.m_bBold ) ;
			}	else if ( this->m_bItaric != b.m_bItaric ){
				return ( this->m_bItaric < b.m_bItaric ) ;
			}	else if ( this->m_bUnderine != b.m_bUnderine ){
				return ( this->m_bUnderine < b.m_bUnderine ) ;
			}	else if ( this->m_bStrikeOut != b.m_bStrikeOut ){
				return ( this->m_bStrikeOut < b.m_bStrikeOut ) ;
			}	else if ( this->m_iEscapement != b.m_iEscapement ){
				return ( this->m_iEscapement < b.m_iEscapement ) ;
			}
			return ( false ) ;		
	};
	/**
	 *	less() �Ɠ����ł��B
	 */
	bool operator<( const CdFontProp& b )const{
		return less( b );
	};
	///@}

};




#define  CdFontProp_h
#endif /*CdFontProp_h*/

