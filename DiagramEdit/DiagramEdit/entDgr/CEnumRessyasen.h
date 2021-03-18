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
//	CEnumRessyasen.h
// $Id: CEnumRessyasen.h 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
#ifndef  CEnumRessyasen_h
#define  CEnumRessyasen_h
#include "entDgr\CentDedDgrDia.h"

namespace entDgr{

// ****************************************************************
//	CEnumRessyasen
// ****************************************************************
/**
@brief
	�w�肳�ꂽ�w�_�C���O�����G���e�B�e�B���W�x�ƌ������邷�ׂĂ̗�Ԑ���
	�񋓂��܂��B


	���̃N���X�́A CDcdDiagram �̃w���p�[�N���X�ł��B
	�w�_�C���O������Ԑ��x���̃��[�v�������s���ꍇ�́A���[�v��
	�G���W���ƂȂ�܂��i���[�v�����͌��\���G������ł��j�B

	�w�_�C���O�����_�C���x�I�u�W�F�N�g�ɕ�܂���Ă���
	�w�_�C���O������ԁx CentDedRessya�E
	�w�_�C���O������Ԑ��x CentDedRessyasen�E
	�w�_�C���O�����w�����x CentDedEkiJikoku
	�I�u�W�F�N�g�̂����A
	�w�肳�ꂽ�`��̈� CdDcdZoneXy ��
	�ꕔ��ʉ߂���\���̂���I�u�W�F�N�g��񋓂��܂��B

�y�g�����z

	�P�D  ���̃N���X�̔h���N���X���`���A
	���z�֐� onCentDedDgrRessyasen() ��
	�w�_�C���O������Ԑ��x CentDedDgrRessyasen ���̏����A
	onCentDedDgrEkijikoku() �Łw�_�C���O�����w�����xCentDedDgrEkiJikoku ���Ƃ�
	�������L�q���Ă��������B

	�Q�D  �h���N���X�̃C���X�^���X�𐶐����Ă��������B
	�R���X�g���N�^�ł́A
	�w�_�C���O�����_�C���x�I�u�W�F�N�g�ƁA�`���ƂȂ�
	IfDcdTarget �I�u�W�F�N�g�ւ̃|�C���^���w�肵�ĉ������B

	�R�D  execute() ���Ăяo���ƁA���̃N���X��
	�`��\�̈�ɂ���w�_�C���O������Ԑ��x���ɁA
	���z�֐� onCentDedDgrRessyasen() ���Ăяo���܂��B
*/
class CEnumRessyasen
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		�w�_�C���O�����_�C���x�Ƃ̊֘A�ł��B

		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this �̔j������������܂�
		�������Ȃ��Ă͂Ȃ�܂���B
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	const CentDedDgrDia*	m_pCentDedDgrDia ;
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�ΏۂƂȂ�`��̈���A
		�w�_�C���O�����G���e�B�e�B���W�n�x�ŕێ����܂��B
		����́A����`����s���͈͂�\���Ă��܂��B
	
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	CdDcdZoneXy	m_zonexyDgrZone ;

	/**
		�����Ԃ̏������s�����ۂ����w�肵�܂��B
		- true ;	//	�����Ԃ̏������s���B
		- false ;	//	����Ԃ̏������s���B
		
		����l�� true 
	 */
	bool m_bDisplayRessyasenKudari ;
	/**
		����Ԃ̏������s�����ۂ����w�肵�܂��B
	 @see m_bDisplayRessyasenKudari
	 */
	bool m_bDisplayRessyasenNobori ;
	///@}
public:
	//*******************************
	//	�R���X�g���N�^
	//*******************************
	/**
	 @param pCentDedDgrDia [in]
		�w�_�C���O�����_�C���x�Ƃ̊֘A�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this �̔j������������܂�
		�������Ȃ��Ă͂Ȃ�܂���B
	 @param zonexyDgrZone [in]
		�ΏۂƂȂ�`��̈���A
		�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏw�肵�Ă��������B
	 @param bDisplayRessyasenKudari [in]
		�����Ԃ̏������s�����ۂ����w�肵�܂��B
		- true ;	//	�����Ԃ̏������s���B
		- false ;	//	�����Ԃ̏������s��Ȃ��B
	 @param bDisplayRessyasenNobori [in]
		����Ԃ̏������s�����ۂ����w�肵�܂��B
	 */
	CEnumRessyasen( 
		const CentDedDgrDia* pCentDedDgrDia ,
		const CdDcdZoneXy& zonexyDgrZone ,
		bool bDisplayRessyasenKudari ,
		bool bDisplayRessyasenNobori ) ;
	virtual ~CEnumRessyasen() ;

protected:
	// --------------------------------
	///@name CEnumRessyasen
	// --------------------------------
	///@{
	/**
		execute() ����Ăяo�����֐��ł��B
	
		execute() �́A�`��\�̈�ɂ���
		�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g���ɁA
		���̊֐����Ăяo���܂��B
		
	 @param eRessyahoukou [in]
		��ԕ����ł��B
	 @param iRessyaIdx [in]
		��ԃC���f�N�X�ł��B
	 @param pCentDedDgrRessya [in]
		�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g���w�肵�܂��B
		
	 �y�I�[�o���C�h�z
		���̃N���X�́A�w�_�C���O������ԁx CentDedDgrRessya ��
		��܂���Ă��� �w�_�C���O������Ԑ��x CentDedDgrRessyasen 
		�I�u�W�F�N�g�̂����A�`��\�̈�ɂ�����̂�񋓂��A
		onCentDedDgrRessyasen() ���Ăяo���܂��B
	
	 */
	virtual void onCentDedDgrRessya( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ) ;

	/**
		execute() -> onCentDedDgrRessya() -> onCentDedDgrRessyasen() 
	 �̏��ŌĂяo�����	�֐��ł��B
	
		execute() �́A�`��\�̈�ɂ���
		�w�_�C���O������Ԑ��x CentDedDgrRessyasen �I�u�W�F�N�g���ɁA
		���̊֐����Ăяo���܂��B
		
	 @param eRessyahoukou [in]
		��ԕ����ł��B
	 @param iRessyaIdx [in]
		��ԃC���f�N�X�ł��B
	 @param aCentDedDgrRessya [in]
		�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g���w�肵�܂��B
	 @param iRessyasenIdx [in]
		��Ԑ��C���f�N�X�ł��B
	 @param pCentDedDgrRessya [in]
		�w�_�C���O������Ԑ��x CentDedDgrRessyasen 
		�I�u�W�F�N�g���w�肵�܂��B
		
	 �y�I�[�o���C�h�z
		���̃N���X�́A�w�_�C���O������Ԑ��xCentDedDgrRessyasen ��
		�͈͓��́w�_�C���O�����w�����xCentDedDgrEkiJikoku 
		�I�u�W�F�N�g��� ���A onCentDedDgrEkiJikoku() ���Ăяo���܂��B
		�I�[�o���C�h���āA
		�w�_�C���O������Ԑ��x CentDedDgrRessyasen �I�u�W�F�N�g����
		�������L�q���Ă��������B
	*/
	virtual void onCentDedDgrRessyasen( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ) ;
	/**
		execute() -> onCentDedDgrRessya() -> onCentDedDgrRessyasen() -> onCentDedDgrRessyasenEki()
	 �̏��ŌĂяo�����	�֐��ł��B
	
		execute() �́A�`��\�̈�ɂ���
		�w�_�C���O������Ԑ��̉w�x CentDedDgrRessyasenEki �I�u�W�F�N�g���ɁA
		���̊֐����Ăяo���܂��B
		
	 @param eRessyahoukou [in]
		��ԕ����ł��B
	 @param iRessyaIdx [in]
		��ԃC���f�N�X�ł��B
	 @param aCentDedDgrRessya [in]
		�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g���w�肵�܂��B
	 @param iRessyasenIdx [in]
		��Ԑ��C���f�N�X�ł��B
	 @param pCentDedDgrRessya [in]
		�w�_�C���O������Ԑ��x CentDedDgrRessyasen 
		�I�u�W�F�N�g���w�肵�܂��B
	 @param iRessyasenEkiIdx [in]
		��Ԑ��̉w�C���f�N�X�ł��B
	 @param pCentDedDgrRessya [in]
		�w�_�C���O������Ԑ��̉w�x pCentDedDgrRessyasenEki 
		�I�u�W�F�N�g���w�肵�܂��B
		
	 �y�I�[�o���C�h�z
		�I�[�o���C�h���āA
		�w�_�C���O������Ԑ��̉w�x CentDedDgrRessyasenEki �I�u�W�F�N�g����
		�������L�q���Ă��������B
	*/
	virtual void onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) ;

	///@}

public:
	// ********************************
	///@name CEnumRessyasen-�֘A
	// ********************************
	///@{
	const CentDedDgrDia*	getCentDedDgrDia() ;
	///@}
	// ********************************
	///@name CEnumRessyasen-����
	// ********************************
	///@{
	CdDcdZoneXy	getDgrZone() ;

	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		�̒l���擾���܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari ;	//	������ (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	����� (m_bDisplayRessyasenNobori)
	 @return 
		- true ;	//	��Ԃ���������
		- false ;	//	��Ԃ��������Ȃ��B
	 */
	bool getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const ;
	///@}
	// ********************************
	///@name CEnumRessyasen-����
	// ********************************
	///@{
	/**
		�`��\�̈�ɂ���w�_�C���O������Ԑ��x���ɁA
		���z�֐� onCentDedDgrRessyasen() ���Ăяo���܂��B
	 */
	virtual void execute() ;
	///@}
};

} //namespace entDgr

#endif /*CEnumRessyasen_h*/

