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
//	CentDedEki.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEki_h
#define  CentDedEki_h

#include <string>
using namespace std ;

// ****************************************************************
//	CentDedEki
// ****************************************************************
/**
 * @brief
 *	�y�T�v�z  DiagramEdit �́A�H���ɂ���w�ЂƂ�\���܂��B
 *	�����Ƃ��āA�w�w���x�E�w�w�����`���x�E�w�w�K�́x��ێ����܂��B
 *
 */
class CentDedEki
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**
	 *	�w�w�����`���x��\���񋓂ł��B
	 */
	enum EEkijikokukeisiki
	{
		/**
		 *	�������݂̂̕\���B(�K��l)
		 *
		 *	(�������A�I���w�ł͒������݂̂�\�����܂�)
		 */
		Jikokukeisiki_Hatsu = 0 ,
		
		/**
		 *	�����\���B
		 *
		 *	����E���Ƃ��A���������̎�����\���B
		 *	(�n���w�E�I���w�ł�����������\��)
		 */
		Jikokukeisiki_Hatsuchaku ,

		/**
		 *	���蒅�\���B
		 *
		 *	-	�����Ԃł́A�������݂̂̕\���B
		 *	-	����Ԃł́A�������݂̂̕\���B
		 *	(�������A�I���w�ł͒������݂̂�\�����܂�)
		 */
		Jikokukeisiki_KudariChaku ,
		
		/**
		 *	��蒅�\���B
		 *
		 *	-	�����Ԃł́A�������݂̂̕\���B
		 *	(�������A�I���w�ł͒������݂̂�\�����܂�)
		 *	-	����Ԃł́A�������݂̂̕\���B
		 */
		Jikokukeisiki_NoboriChaku ,
		
	};
	
	/**
	 *	�w�w�K�́x��\���񋓂ł��B
	 */
	enum EEkikibo
	{
		/**
		 *	��ʉw�B(�K��l)
		 */
		Ekikibo_Ippan = 0 ,
		/**
		 *	��v�w�B
		 *
		 *	��v�w�ł́A�_�C���O�����̌r���������ɂȂ�܂��B
		 */
		Ekikibo_Syuyou ,
	};
	
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	�w��
	 *
	 *	�K��l�́A�󕶎���B
	 */
	string	m_strEkimei ;
	
	/**
	 *	�w�����`���B
	 *
	 *	�K��l�́A Jikokukeisiki_Hatsuhyouji 
	 */
	EEkijikokukeisiki	m_eEkijikokukeisiki ;
	
	/**
	 *	�w�w�K�́x��\���񋓂ł��B
	 *
	 *	�K��l�́A Ekikibo_Ippan 
	 */
	EEkikibo	m_eEkikibo ;
	
	/**
	 *	���E������B
	 *
	 *  ���̑����� true �̉w�ł́A�����\��ʂ�
	 *	��������̉��ɁA�������E����`�悵�܂��B
	 *  ���̑����́A�w�r���[�Ǝ����\�r���[�ɓK�p����܂��B
	 */
	bool m_bKyoukaisen ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CentDedEki() :
		m_eEkijikokukeisiki( Jikokukeisiki_Hatsu ) ,
		m_eEkikibo( Ekikibo_Ippan ) ,
		m_bKyoukaisen( false )
		{};
	
	/**
	 * @param strEkimei [in]
	 *	�w��
	 * @param eEkijikokukeisiki [in]
	 *	�w�����`���B
	 * @param eEkikibo [in]
	 *	�w�w�K�́x��\���񋓂ł��B
	 * @param bKyoukaisen [in]
	 *	���E������B
	 *  ���̑����� true �̉w�ł́A�����\��ʂ�
	 *	��������̉��ɁA�������E����`�悵�܂��B
	 *  ���̑����́A�w�r���[�Ǝ����\�r���[�ɓK�p����܂��B
	 */
	CentDedEki( const string& strEkimei , 
			EEkijikokukeisiki	eEkijikokukeisiki ,
			EEkikibo	eEkikibo , 
			bool bKyoukaisen ) :
		m_strEkimei( strEkimei ) ,
		m_eEkijikokukeisiki( eEkijikokukeisiki ) ,
		m_eEkikibo( eEkikibo ) ,
		m_bKyoukaisen( bKyoukaisen )
		{};
		
	
	virtual ~CentDedEki(){} ;

// ********************************
//	CentDedEki
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	string	getEkimei()const{	return m_strEkimei ;};
	CentDedEki& setEkimei( const string& value ){
		m_strEkimei = value ; return *this ; } ;
	EEkijikokukeisiki	getEkijikokukeisiki()const{
		return 	m_eEkijikokukeisiki ;};
	CentDedEki& setEkijikokukeisiki( EEkijikokukeisiki	value ){
		m_eEkijikokukeisiki = value ;	return *this ; } ;
	EEkikibo	getEkikibo()const{	return 	m_eEkikibo ;};
	CentDedEki& setEkikibo( EEkikibo value ){
		m_eEkikibo = value ; return *this ; } ;
	bool getKyoukaisen()const{	return m_bKyoukaisen ; };
	CentDedEki& setKyoukaisen( bool value ){
		m_bKyoukaisen = value ; return *this ; } ;
	///@}
	
	// ********************************
	///@name ����
	// ********************************
	///@{
	///@}
};
#endif /*CentDedEki_h*/
