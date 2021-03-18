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
//	CKeyinputSenderToModalDlg.cpp
// ****************************************************************
*/
#include "CKeyinputSenderToModalDlg.h"

namespace OuMfc{
namespace OuDlg{

// ****************************************************************
//	CKeyinputSenderToModalDlg
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CKeyinputSenderToModalDlg::CKeyinputSenderToModalDlg() :
		m_hwndControl( NULL ) ,
		m_bIsSend( false ) 
{
}

// ********************************
//	CKeyinputSenderToModalDlg
// ********************************
	// ********************************
	//@name �w�]�����E�C���h�E�x����̑���
	// ********************************
bool CKeyinputSenderToModalDlg::
	OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	bool bRv = false ;
	if ( m_bIsSend ){
		bRv = true ;
		MsgToPost	aMsg ;
		aMsg.Msg = WM_KEYDOWN ;
		aMsg.wParam = nChar ;
		aMsg.lParam = MAKELONG( nRepCnt , nFlags )  ;
		if ( m_hwndControl == NULL ){
			m_contmsgToSend.push_back( aMsg ) ;
		}	else	{
			PostMessage( m_hwndControl , aMsg.Msg , aMsg.wParam , 
				aMsg.lParam ) ;
		}
	}
	return bRv ;
}

bool CKeyinputSenderToModalDlg::
	OnKeyUp( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	bool bRv = false ;
	if ( m_bIsSend ){
		bRv = true ;
		MsgToPost	aMsg ;
		aMsg.Msg = WM_KEYUP ;
		aMsg.wParam = nChar ;
		aMsg.lParam = MAKELONG( nRepCnt , nFlags )  ;
		if ( m_hwndControl == NULL ){
			m_contmsgToSend.push_back( aMsg ) ;
		}	else	{
			PostMessage( m_hwndControl , aMsg.Msg , aMsg.wParam , 
				aMsg.lParam ) ;
		}
	}
	return bRv ;
}


int CKeyinputSenderToModalDlg::startSend() 
{
	int iRv = 0 ;
	if ( iRv >=0 ){
		if ( m_bIsSend ){
			iRv = -1 ;	//	���łɓ]�����ł��B
		}
	}
	if ( iRv >=0 ){
		m_bIsSend = true ;
	}
	return ( iRv ) ;
}

void CKeyinputSenderToModalDlg::endSend() 
{
	m_bIsSend = false ;
	m_hwndControl = NULL ;
	m_contmsgToSend.clear() ;
}
	// ********************************
	//@name �w�]����_�C�A���O�x����̑���
	// ********************************
int CKeyinputSenderToModalDlg::registerCtrl( HWND hwndControl ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( m_bIsSend && m_hwndControl == NULL ) ){
			//	���M���łȂ����A���łɁw�]����R���g���[���x��
			//	�o�^�ς݂ł�
			iRv = -1 ;
		}
	}
	if ( iRv >= 0 ){
		m_hwndControl = hwndControl ;
		while ( m_contmsgToSend.size() > 0 ){
			MsgToPost	aMsg = m_contmsgToSend.front() ;
			m_contmsgToSend.pop_front() ;
			PostMessage( m_hwndControl , aMsg.Msg , aMsg.wParam , 
				aMsg.lParam ) ;
		}
	}
	return ( iRv ) ;
}
void CKeyinputSenderToModalDlg::unregisterCtrl() 
{
	m_hwndControl = NULL ;
}
	// ********************************
	//@name ����
	// ********************************
bool CKeyinputSenderToModalDlg::isSend() 
{
	return ( m_bIsSend ) ;
}
HWND CKeyinputSenderToModalDlg::getControl() 
{
	return ( m_hwndControl ) ;
}

	// ********************************
	///@name 
	// ********************************
bool CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown()
{
	//	�A�N�Z�����[�^�L�[�ɂ��
	//	���j���[�R�}���h�N����W�Q���Ȃ��悤�ɁA
	//	ALT�L�[��CTRL�L�[��������Ă���Ƃ��́A
	//	�_�C�A���O�N��������Ă��܂��B
	//	�������A���ۂɂ̓A�N�Z�����[�^�L�[�̋@�\��
	//	�E�C���h�E�� OnKeyDown() �����D�悳��邽�߁A
	//	���̔���͌����ɂ͕K�v����܂���B

	//ALT
	{
		SHORT	iResult = GetKeyState( VK_MENU ) ;
		if ( iResult < 0 ){
			return false ;
		}
	}
	//CTRL
	{
		SHORT	iResult = GetKeyState( VK_CONTROL ) ;
		if ( iResult < 0 ){
			return false ;
		}
	}

	// --------------------------------
	int iCount = 0 ;
	//	�A���t�@�x�b�g�L�[��̐���
	int iKeycode ;
	for ( iKeycode = '0' ; iKeycode <= '9' ; iKeycode ++ ){
		SHORT	iResult = GetKeyState( iKeycode ) ;
		if ( iResult < 0 ){
			iCount ++ ;
		}
	}
	//	�A���t�@�x�b�g�L�[(�啶���E������������̏ꍇ���A
	//	������̏����ɊY�����܂�)
	for ( iKeycode = 'A' ; iKeycode <= 'Z' ; iKeycode ++ ){
		SHORT	iResult = GetKeyState( iKeycode ) ;
		if ( iResult < 0 ){
			iCount ++ ;
		}
	}
	//	�e���L�[�� 0x60�`0x69�܂łł�
	for ( iKeycode = 0x60 ; iKeycode <= 0x69 ; iKeycode ++ ){
		SHORT	iResult = GetKeyState( iKeycode ) ;
		if ( iResult < 0 ){
			iCount ++ ;
		}
	}

	return ( iCount == 1 );
}

} //namespace OuDlg
} //namespace OuMfc
