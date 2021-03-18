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
//$Id: CentDedEkiJikokuTrack.cpp 378 2016-11-16 21:10:54Z okm $

#include "stdafx.h"
#include "CentDedEkiJikokuTrack.h"
#include "CentDedEkiJikokuTrackCont.h"
#include "CentDedEki.h"
#include "CentDedEkiJikokuCont.h"
#include "CentDedRessya.h"
#include "CentDedRosen.h"

namespace entDed{


	// ********************************
	//	�R���X�g���N�^
	// ********************************
CentDedEkiJikokuTrack::CentDedEkiJikokuTrack() 
{
}
CentDedEkiJikokuTrack::CentDedEkiJikokuTrack( 
		CdDedJikoku nyusenJikoku ,
		CentDedEkiTrackSelector track ) 
		: m_NyusenJikoku( nyusenJikoku )
		, m_Track( track )
{
}

CentDedEkiJikokuTrack& 
CentDedEkiJikokuTrack::operator=( const CentDedEkiJikokuTrack& value ) 
{
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
		int iResult = pEkiJikokuTrackCont->setable( value , pEkiJikokuTrackCont->getIndex( this ) ) ;
		if ( iResult < 0 ){
			throw( LException() ) ;
		}
	}
	super::operator=( value ) ; 
	// --------------------------------
	m_NyusenJikoku = value.m_NyusenJikoku ;
	m_Track = value.m_Track ;

	return *this ;
}
	// ********************************
	//@name CParentBase-����
	// ********************************
void CentDedEkiJikokuTrack::setParent( CParentBase* pParent )
{
	super::setParent( pParent ) ;
	adjust() ;
}

	// ********************************
	//@name CentDedEkiJikokuTrack-����
	// ********************************
CdDedJikoku CentDedEkiJikokuTrack::getNyusenJikoku()const
{ return m_NyusenJikoku ;}

void CentDedEkiJikokuTrack::setNyusenJikoku( const CdDedJikoku value )
{ 
	//��setNyusenJikoku:CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
	//�@�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�ANULL�ȊO�̎����̐ݒ�̓G���[(��O)
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
		CentDedEkiJikoku* pEkiJikoku = pEkiJikokuTrackCont->getEkiJikoku() ;
		if ( pEkiJikoku != NULL )
		{
			if ( pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None
				|| pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				if ( !value.isNull() )
				{
					throw( LException() ) ;
				}
			}
		}
	}

	m_NyusenJikoku = value ;
}
	
CentDedEkiTrackSelector CentDedEkiJikokuTrack::getTrack()const
{ return m_Track ;}

void CentDedEkiJikokuTrack::setTrack( const CentDedEkiTrackSelector& value )
{ 
	// CentDedEkiJikokuTrack ���H��(CentDedRosen)�̈ꕔ�ł���
	//�ꍇ�ŁA�Ԑ��w��q���w�Ԑ��R���e�i�xCentDedEkiTrackCont �̗v�f�ɑΉ�����
	//���Ȃ��ꍇ�̓G���[�B(��O�X���[)
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
	
		const CentDedEki* pEki = pEkiJikokuTrackCont->getEki() ;
		if ( pEki != NULL )
		{
			const CentDedEkiTrackCont* pEkTrackCont = pEki->getEkiTrackCont() ;
			if ( !value.isNull() && value.getiIndex() >= pEkTrackCont->size() )
			{
				throw( LException() ) ;	//	�Ԑ���Index���ACentDedEkiTrackCont�̗v�f�ɑΉ����Ă��܂���
			}
		}
	}
	//��setEkiTrack:CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
	//�@�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�ANULL�ȊO�̔Ԑ��̐ݒ�̓G���[(��O)
	if ( pEkiJikokuTrackCont != NULL )
	{
		CentDedEkiJikoku* pEkiJikoku = pEkiJikokuTrackCont->getEkiJikoku() ;
		if ( pEkiJikoku != NULL )
		{
			if ( pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None
				|| pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				if ( !value.isNull() )
				{
					throw( LException() ) ;
				}
			}
		}
	}

	// --------------------------------
	m_Track = value ;
}

	// ********************************
	//@name CentDedEkiJikokuTrack-����
	// ********************************
void CentDedEkiJikokuTrack::adjust() 
{
	//��CentDedEkiJikokuTrack ���H��(CentDedRosen)�̈ꕔ�ł���ꍇ�ŁA
	//�Ԑ��w��q���w�Ԑ��R���e�i�xCentDedEkiTrackCont �̗v�f��
	//�Ή����Ă��Ȃ��ꍇ�́A�w�w��Ȃ��x�ɕύX����
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
		const CentDedEki* pEki = pEkiJikokuTrackCont->getEki() ;
		if ( pEki != NULL )
		{
			const CentDedEkiTrackCont* pEkTrackCont = pEki->getEkiTrackCont() ;
			if ( !this->m_Track.isNull() && this->m_Track.getiIndex() >= pEkTrackCont->size() )
			{
				this->m_Track.setNull() ;	//	�Ԑ���Index���ACentDedEkiTrackCont�̗v�f�ɑΉ����Ă��܂���
			}
		}
	}

	//��CentDedEkiJikokuTrack ���w�w�����x�̈ꕔ�ł���ꍇ�ŁA
	//�@�w�����w�^�s�Ȃ��x�܂��́w�o�R�Ȃ��x�̏ꍇ�A�������E��������NULL�B
	//�@�����́A�Ԑ�Index�E���������Ƃ���NULL��ݒ肷��B
	if ( pEkiJikokuTrackCont != NULL )
	{
		CentDedEkiJikoku* pEkiJikoku = pEkiJikokuTrackCont->getEkiJikoku() ;
		if ( pEkiJikoku != NULL )
		{
			if ( pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None
				|| pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				m_Track.setNull() ;
				m_NyusenJikoku.setNull() ;
			}
		}
	}
}
	
	
	// ********************************
	//@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
void CentDedEkiJikokuTrack::onEkiTrackInsert( int iEkiTrackIndex )
{
	//���Ԑ��̒ǉ�(OnInsertEkiTrack):�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w��
	//�������C���f�N�X�̏ꍇ�A�C���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B
	if ( !m_Track.isNull() && m_Track.getiIndex() >= iEkiTrackIndex )
	{
		m_Track.setIndex( m_Track.getiIndex() + 1 ) ;
	}
}

void CentDedEkiJikokuTrack::onEkiTrackErase( int iEkiTrackIndex )
{
	//���Ԑ��̍폜(OnEraseEkiTrack):�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w�����
	//���C���f�N�X�̏ꍇ�A�C���f�N�X�́A�R���e�i�ւ̍폜�ɍ��킹�ăV�t�g������B
	//�@�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w��������C���f�N�X�ŁA����
	// �C���f�N�X���폜�Ώۂ̂��̂ł���ꍇ�A�w�w��Ȃ��x�ɕύX����
	if ( !m_Track.isNull() )
	{
		if ( m_Track.getiIndex() > iEkiTrackIndex )
		{
			m_Track.setIndex( m_Track.getiIndex() - 1 ) ;
		}
		else if ( m_Track.getiIndex() == iEkiTrackIndex )
		{
			m_Track.setNull() ;
		}
	}
}









} //namespace entDed


