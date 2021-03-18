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
//$Id: CentDedEkiJikokuTrack.h 378 2016-11-16 21:10:54Z okm $
#ifndef  entDed_CentDedEkiJikokuTrack_h
#define  entDed_CentDedEkiJikokuTrack_h

#include "NsMu\CChildBase.h"
#include "CdDedJikoku.h"
#include "CentDedEkiTrackSelector.h"

namespace entDed{
	using namespace OuLib::NsMu ;
	using namespace std ;
/**
@brief
  �w�����x��\���܂��B
  
  ���̒l�́A�_�C���O�����r���[�ł́A�w�̍ݐ������������̗�Ԑ��̕`��Ɏg���܂��B
  
  �����Ƃ��āA��������(CentDedEkiJikoku)�E�����Ԑ�(CentDedEkiTrackSelector)
�������܂��B

  ����l�ł́A���������E�����Ԑ��Ƃ�NULL�ł��B

  �����Ԑ���NULL�̏ꍇ�A�_�C���O�����̍ݐ����͖{���ɕ`�悳��܂��B
  
  ����������NULL�̏ꍇ�A��������=�������Ƃ݂Ȃ��܂��B�n���w�œ�������=NULL�̏ꍇ�A�ݐ����͕`�悳��܂���B

����
 -------------------------------- 
���Ԑ��w��q���C���f�N�X�̏ꍇ�A���̃C���f�N�X�́A�w�̔Ԑ��R���e�i
(CentDedEkiTrackCont)�ɑΉ����Ă��Ȃ��Ă͂Ȃ�܂���B

��CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
�@�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�A�������E��������NULL�B
�@�����́A�Ԑ�Index�E���������Ƃ���NULL�B

����̃G���[�����E�C��
 -------------------------------- 

���Ԑ��̒ǉ�(OnInsertEkiTrack):�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w��
�������C���f�N�X�̏ꍇ�A�C���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B

���Ԑ��̍폜(OnEraseEkiTrack):�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w�����
���C���f�N�X�̏ꍇ�A�C���f�N�X�́A�R���e�i�ւ̍폜�ɍ��킹�ăV�t�g������B
�@�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w��������C���f�N�X�ŁA����
 �C���f�N�X���폜�Ώۂ̂��̂ł���ꍇ�A�w�w��Ȃ��x�ɕύX����

��setNyusenJikoku:CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
�@�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�ANULL�ȊO�̎����̐ݒ�̓G���[(��O)

��setEkiTrack: CentDedEkiJikokuTrack ���H��(CentDedRosen)�̈ꕔ�ł���
�ꍇ�ŁA�Ԑ��w��q���w�Ԑ��R���e�i�xCentDedEkiTrackCont �̗v�f�ɑΉ�����
���Ȃ��ꍇ�̓G���[�B(��O�X���[)

��setEkiTrack:CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
�@�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�ANULL�ȊO�̔Ԑ��̐ݒ�̓G���[(��O)


��operator= : CentDedEkiJikokuTrackCont::set()�����s����悤�ȑ���̓G���[

 
 ����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 

��CentDedEkiJikokuTrack ���H��(CentDedRosen)�̈ꕔ�ł���ꍇ�ŁA�Ԑ��w��q��
�w�Ԑ��R���e�i�xCentDedEkiTrackCont �̗v�f�ɑΉ����Ă��Ȃ��ꍇ�́A
�w�w��Ȃ��x�ɕύX����

��CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
�@�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�A�������E��������NULL�B
�@�����́A�Ԑ�Index�E���������Ƃ���NULL��ݒ肷��B

 
*/
class CentDedEkiJikokuTrack : public CChildBase
{
	typedef CChildBase	super ;
public:
	/**
		�ȉ��̏ꍇ�ɃX���[����܂��B

		CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
�@		�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�ɁANULL�ȊO�̎����E�Ԑ�Index���w��

		�Ԑ��w��q���C���f�N�X�̏ꍇ�ŁA���̃C���f�N�X���A�w�̔Ԑ��R���e�i
		(CentDedEkiTrackCont)�ɑΉ����Ă��Ȃ��ꍇ
	*/
	class LException
	{
	};
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	  ��������
	*/
	CdDedJikoku m_NyusenJikoku ;
	
	/**
	  �����Ԑ�
	*/
	CentDedEkiTrackSelector m_Track ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	///@{
	/** 
	  �f�t�H���g�R���X�g���N�^�́A
	  ���������E�����Ԑ��Ƃ���NULL�ɏ��������܂��B 
	*/
	CentDedEkiJikokuTrack(); 
	/**
	@param nyusenJikoku
	  ��������
	@param track
	  �����Ԑ�
	*/
	CentDedEkiJikokuTrack( 
		CdDedJikoku nyusenJikoku ,
		CentDedEkiTrackSelector track ); 
	/** 
	��operator= : CentDedEkiJikokuTrackCont::set()�����s����悤�ȑ���̓G���[
	
	@exception LException 
	*/
	CentDedEkiJikokuTrack& operator=( const CentDedEkiJikokuTrack& value ) ;
public:
	// ********************************
	///@name CParentBase-����
	// ********************************
	///@{
	virtual void setParent( CParentBase* pParent );
	///@}

public:
	// ********************************
	///@name CentDedEkiJikokuTrack-����
	// ********************************
	///@{
	/**@see m_NyusenJikoku */
	CdDedJikoku getNyusenJikoku()const;
	/**@see m_NyusenJikoku */
	void setNyusenJikoku( const CdDedJikoku value );
	
	/**@see m_Track */
	CentDedEkiTrackSelector getTrack()const;
	/**
	@see m_Track 
	@exception LException
		 CentDedEkiJikokuTrack ���H��(CentDedRosen)�̈ꕔ�ł���
		�ꍇ�ŁA�Ԑ��w��q���w�Ԑ��R���e�i�xCentDedEkiTrackCont �̗v�f�ɑΉ�����
		���Ȃ��ꍇ�̓G���[�B(��O�X���[)
	*/
	void setTrack( const CentDedEkiTrackSelector& value );
	///@}

public:
	// ********************************
	///@name CentDedEkiJikokuTrack-����
	// ********************************
	///@{
	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B


	��CentDedEkiJikokuTrack ���H��(CentDedRosen)�̈ꕔ�ł���ꍇ�ŁA
	�Ԑ��w��q���w�Ԑ��R���e�i�xCentDedEkiTrackCont �̗v�f��
	�Ή����Ă��Ȃ��ꍇ�́A�w�w��Ȃ��x�ɕύX����
	*/
	void adjust() ;
	
	///@}
public:
	// ********************************
	///@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
	///@{
	/**
		CentDedEkiTrackCont �� CentDedEkiTrack ���ǉ����ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiTrackIndex
		�ǉ����ꂽ CentDedEkiTrack �̃C���f�N�X�B
	*/
	virtual void onEkiTrackInsert( int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont ���� CentDedEkiTrack ���폜���ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiTrackIndex
		�폜���ꂽ CentDedEkiTrack �̃C���f�N�X�B
	*/
	virtual void onEkiTrackErase( int iEkiTrackIndex ); 

	///@}
};



} //namespace entDed

#endif //entDed_CentDedEkiJikokuTrack_h
