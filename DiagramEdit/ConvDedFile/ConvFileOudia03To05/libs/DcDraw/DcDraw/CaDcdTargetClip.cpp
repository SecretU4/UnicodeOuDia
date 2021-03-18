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
//	CaDcdTargetClip.cpp
// ****************************************************************
*/
#include "CaDcdTargetClip.h"
#include "CConverter_WinGdi.h"


// ****************************************************************
//	CaDcdTargetClip
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CaDcdTargetClip::CaDcdTargetClip( 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdZoneXy& zonexyZoneClip ) 
{
	m_zonexyZoneClip = zonexyZoneClip ;
	m_pIfDcdTarget = pIfDcdTarget ;
	
	// --------------------------------
	m_hRgnSid = NULL ;
	m_hRgnNew = NULL ;
	
}
CaDcdTargetClip::~CaDcdTargetClip()
{
	invalidate() ;
}

// ********************************
//	IfValidate
// ********************************
int CaDcdTargetClip::validate()
{
	int iRv = 1 ;
	
	if ( isValid() ){
		return ( 0 ) ;
	}
	// --------------------------------
	//	DC�̊����̃��[�W������ۑ�
	// --------------------------------
	if ( iRv >= 0 ){
			m_hRgnSid = CreateRectRgn( 0 , 0 , 0 , 0 ) ;
			if ( m_hRgnSid == NULL ){
				iRv = -1 ;	//	HRGN �̐����Ɏ��s���܂���
			}
	}
	if ( iRv >= 0 ){
			int	iLi = GetClipRgn( getHdc() , m_hRgnSid ) ;
			if ( iLi == 0 ){
				DeleteObject( m_hRgnSid ) ;
				m_hRgnSid = NULL ;
			}	else if ( iLi < 0 ){
				iRv = -2 ;	//	DC�̃��[�W�����擾�Ɏ��s���܂����B
			}	else	{
				iRv += 0 ;
			}
	}
	//m_hRgnSid = ����܂ł̃N���b�v���[�W�����B
	//	����܂ł̂c�b�ɃN���b�v���[�W�������Ȃ��Ȃ�ANULL�ł��B

	// --------------------------------
	//	�V�������[�W�����𐶐�
	// --------------------------------
	if ( iRv >= 0 ){
			CdDcdZoneXy	zonexyZoneClip = m_zonexyZoneClip ;
			CConverter_WinGdi	aConverter ;
			zonexyZoneClip = aConverter.LPtoDP( m_zonexyZoneClip , getHdc() ) ;  
			//	SelectClipRgn() �֐��́A
			//	���[�W�����̍��W���f�o�C�X�P�ʂŎw�肳��Ă�����̂Ɖ��肵�܂��B

			m_hRgnNew = CreateRectRgn( zonexyZoneClip.getX().getPos()
									, zonexyZoneClip.getY().getPos()
									, zonexyZoneClip.getX().getEndPos()
									, zonexyZoneClip.getY().getEndPos() ) ;


			if ( m_hRgnNew == NULL ){
				iRv = -3 ;	//	HRGN �̐����Ɏ��s���܂���
			}
	}
	//m_hRgnNew = m_zonexyZoneClip �Ŏw�肳�ꂽ�̈�̋�`�̃��[�W�����B
		
	if ( iRv >= 0 ){
			if ( m_hRgnSid != NULL ){
				if ( CombineRgn( m_hRgnNew , m_hRgnNew , m_hRgnSid , RGN_AND ) 
															== ERROR ){
					iRv = -4 ;	//	CombineRgn() �Ɏ��s���܂���
				}
			}
	}
	//m_hRgnNew = DcDrawRq() �Ŏw�肳�ꂽ�̈�ɁA
	//	����܂ł̃N���b�v���[�W������g�ݍ��킹������
	
	// --------------------------------
	//	�V�������[�W�����𐶐�
	// --------------------------------
	if ( iRv >= 0 ){
		if ( SelectClipRgn( getHdc() , m_hRgnNew ) == ERROR ){
			iRv = -5 ;	//	SelectClipRgn() �Ɏ��s
		}
	}



	return ( iRv ) ;
}

void CaDcdTargetClip::invalidate()
{
	SelectClipRgn( getHdc() , m_hRgnSid ) ;
	if ( m_hRgnNew != NULL ){
		DeleteObject( m_hRgnNew ) ;
		m_hRgnNew = NULL ;
	}
	if ( m_hRgnSid != NULL ){
		DeleteObject( m_hRgnSid ) ;
		m_hRgnSid = NULL ;
	}
	
	
}

bool CaDcdTargetClip::isValid()
{
	return ( m_hRgnNew != NULL ) ;
}

// ********************************
//	IfDcdTarget
// ********************************
HDC	CaDcdTargetClip::getHdc() 
{
	return ( m_pIfDcdTarget->getHdc() ) ;

}
CdDcdZoneXy CaDcdTargetClip::getZone() 
{
	return ( m_pIfDcdTarget->getZone()  ) ;
}
CdDcdZoneXy CaDcdTargetClip::getDrawableZone() 
{
	CdDcdZoneXy	zonexyCross( m_zonexyZoneClip.CrossZone( m_pIfDcdTarget->getDrawableZone() ) ) ;
	return ( zonexyCross ) ;
}

// ********************************
//	CaDcdTargetClip
// ********************************
bool CaDcdTargetClip::isDrawable() 
{
	CdDcdZoneXy	zonexyCross( m_zonexyZoneClip.CrossZone( m_pIfDcdTarget->getDrawableZone() ) ) ;
	if ( zonexyCross.getX().getSize() > 0 && zonexyCross.getY().getSize() > 0 ){
		return ( true ) ;
	}	
	return ( false ) ;
}
