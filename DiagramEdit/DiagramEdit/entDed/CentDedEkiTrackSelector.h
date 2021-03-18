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
/** @file */
//$Id: CentDedEkiTrackSelector.h 378 2016-11-16 21:10:54Z okm $
#ifndef  entDed_CentDedEkiTrackSelector_h
#define  entDed_CentDedEkiTrackSelector_h



namespace entDed{
/**
@brief
  �w�w���������x�I�u�W�F�N�g�́w�Ԑ��w��q�x�B�w�Ԑ��R���e�i�x���́w�Ԑ��x�I�u�W�F�N�g���w�肷�邽�߂̃N���X�ł��B

  �w�Ԑ��x�I�u�W�F�N�g�̎w����@�́A�ȉ�����I���ł��܂��B

 - NULL�F(����l)�@��Ԑ��́A��ԕ����ɉ������w����{���x�w���{���x�̂����ꂩ�ƂȂ�܂��B
 - �C���f�N�X�w��F�w�Ԑ��R���e�i�x���̐����C���f�N�X���w��

  �C���f�N�X�w��ɂ����āA�C���f�N�X���A�w�Ԑ��R���e�i�x���́A��Ԃ̕����́w�{���x���w���Ă���ꍇ�A�w�Ԑ��w��q�x��NULL�ɐ��K�����܂��B
*/
class CentDedEkiTrackSelector
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	  �Ԑ��R���e�i���̃C���f�N�X�B
	  
	  NULL �̏ꍇ��-1�ƂȂ�܂��B
	*/
	int	m_iIndex ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	  �Ԑ��w��q��NULL�ɏ��������܂��B
	*/
	CentDedEkiTrackSelector() : m_iIndex( -1 ){}

	/**
	@param iIndex 
	  �C���f�N�X���w�肵�ď��������܂��B
	*/
	CentDedEkiTrackSelector( int iIndex ) : m_iIndex( iIndex ){}

public:
	// ********************************
	///@name CentDedEkiTrackSelector-����
	// ********************************
	///@{
	///@see m_iIndex
	int	getiIndex()const{ return m_iIndex ;}
	///@see m_iIndex
	void setIndex( int value ){	m_iIndex = value ;}
	/**
	@return this��NULL�Ȃ� true �A�C���f�N�X�w��Ȃ� false �ł��B	
	*/
	bool isNull()const{ return m_iIndex < 0 ;}
	/**
		this �� NULL�ɐݒ肵�܂��B
	*/
	void setNull(){ m_iIndex = -1 ;}
	///@}
};

} //namespace entDed

#endif //entDed_CentDedEkiTrackSelector_h
