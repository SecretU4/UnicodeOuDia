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
//	CDropTargetDoctmpl.cpp
// ****************************************************************
*/
#include "CDropTargetDoctmpl.h"

namespace OuMfc{
namespace Hidemdi{

// ****************************************************************
//	CDropTargetDoctmpl
// ****************************************************************
int CDropTargetDoctmpl::HdropToFilenames( HDROP pdropgmemEHdrop 
								, CStringArray* pastrExt ) 
		//	���̃h���b�v�^�[�Q�b�g�ɓ�������HDROP�n���h������A
		//	�g���q�����o���܂��B
		//hgmemEHdrop
		//	�h���b�v�^�[�Q�b�g�ɓ�������HDROP�n���h�����w�肵�Ă��������B
		//pastrExt
		//	���̊֐��́A���̕�����z��ɁA�h���b�v���ꂽ̧�ق̈ꗗ��
		//	�i�[���܂��B
		//	�K�v�Ȃ��Ȃ�NULL�ł��܂��܂���B
		//[r]
		//	̧�ق̐���Ԃ��܂�
{
	CStringArray	LArray ;
	if ( pastrExt == NULL ){
		pastrExt = &LArray ;
	}

	int	iLDropNof = DragQueryFile( pdropgmemEHdrop 
										, 0xffffffff , NULL, 0 ) ;
	int	iLi ;
	for ( iLi = 0 ; iLi < iLDropNof ; iLi ++ ){
		int	iLFilenameSz = DragQueryFile( pdropgmemEHdrop 
												, iLi , NULL, 0 ) + 1 ;
		TCHAR* lpszFilename = new TCHAR[ iLFilenameSz ] ;
		DragQueryFile( pdropgmemEHdrop , iLi , lpszFilename , iLFilenameSz ) ;
			//	lpszFilename = �h���b�v���ꂽ�t�@�C���i���R�[�h�j�̖��̂ł�

		pastrExt->Add( lpszFilename ) ;		

		delete[] lpszFilename ;
		
	}
	return ( iLDropNof ) ;	
}

int CDropTargetDoctmpl::FilenamesNoExtRemove
			( const CStringArray& astrEExt , CStringArray* pastrFilename ) 
{
	int	iRv = 0 ;
	
	int	idxLFilename ;
	for ( idxLFilename = 0 
			; idxLFilename < pastrFilename->GetSize()
			; idxLFilename ++ ){
		int	idxLExt ;
		for ( idxLExt = 0 
				; idxLExt < astrEExt.GetSize()
				; idxLExt ++ ){
			if ( (*pastrFilename)[idxLFilename].GetLength() > astrEExt[idxLExt].GetLength() ){
				if ( (*pastrFilename)[idxLFilename].
						Right( astrEExt[idxLExt].GetLength() ).
						CompareNoCase( astrEExt[idxLExt] ) == 0 ){
					break ;
				}
			}
		}
		if ( idxLExt == astrEExt.GetSize() ){
			pastrFilename->RemoveAt( idxLFilename ) ;
			idxLFilename -- ;
			iRv ++ ;
		}
		 
	}
	return ( iRv ) ;
}
// ********************************
//	�R���X�g���N�^
// ********************************
CDropTargetDoctmpl::CDropTargetDoctmpl( BOOL bEAcceptSingle ) 
		//bEAcceptSingle ;
		//	̧�قP�����̃h���b�v���󂯕t���܂��iSDI�Ŏg���܂��j
{
	m_bAcceptSingle = bEAcceptSingle ;
		//	̧�قP�����̃h���b�v���󂯕t���܂��iSDI�Ŏg���܂��j
	
}

CDropTargetDoctmpl::~CDropTargetDoctmpl() 
{
}
	
// ********************************
//	COleDropTarget
// ********************************
DROPEFFECT CDropTargetDoctmpl::OnDragEnter( CWnd* pWnd
						, COleDataObject* pDataObject
						, DWORD dwKeyState, CPoint point )
		//�y�I�[�o���C�h�z
		//	CWinApp�ɑ΂��āA���̃A�v���P�[�V�������T�|�[�g���Ă���g���q��
		//	�₢���킹�āA���̌��ʂ� m_astrExt �ɕۑ����܂��B
		//	�h���b�O����Ă���̂��A�A�v���P�[�V�����ŃT�|�[�g���Ă���g���q
		//	�ł������ꍇ�́A���̃h���b�v�^�[�Q�b�g�ւ̃R�s�[���󂯕t���܂�
{
	m_astrExt.RemoveAll() ;
	


	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;
	while( LPosition != NULL ){
		CDocTemplate*	pLTemplate = AfxGetApp()->GetNextDocTemplate( LPosition ) ;
		CString	strLExt ;
		pLTemplate->GetDocString( strLExt , CDocTemplate::filterExt ) ;
		if ( strLExt.GetLength() >= 2 && strLExt[0] == _T( '.' ) ){
			m_astrExt.Add( strLExt ) ;
		}
	}
	
	
	return ( OnDragOver( pWnd, pDataObject , dwKeyState, point ) ) ;
}

DROPEFFECT CDropTargetDoctmpl::OnDragOver( CWnd* pWnd, COleDataObject* pDataObject
										, DWORD dwKeyState, CPoint point )
		//�y�I�[�o���C�h�z
		//	�h���b�O����Ă���̂��A�A�v���P�[�V�����ŃT�|�[�g���Ă���g���q
		//	�ł������ꍇ�́A���̃h���b�v�^�[�Q�b�g�ւ̃R�s�[���󂯕t���܂�
{
	if ( pDataObject->IsDataAvailable( CF_HDROP ) ){
		HGLOBAL	hLGlobal = pDataObject->GetGlobalData( CF_HDROP ) ;
		CStringArray	astrLFilename ;
		HdropToFilenames( (HDROP)hLGlobal , &astrLFilename ) ;
		GlobalFree( hLGlobal ) ;
		if ( m_bAcceptSingle && astrLFilename.GetSize() != 1 ){
			return ( DROPEFFECT_NONE ) ;
		}
		FilenamesNoExtRemove( m_astrExt , &astrLFilename ) ;
		if ( astrLFilename.GetSize() > 0 ) {
 			return ( DROPEFFECT_COPY ) ; 
		}
	}
	return ( DROPEFFECT_NONE ) ; 
}

void CDropTargetDoctmpl::OnDragLeave( CWnd* pWnd ) 
		//�y�I�[�o���C�h�z
		//	���ɏ����͂���܂���
{
}
	
BOOL CDropTargetDoctmpl::OnDrop( CWnd* pWnd, COleDataObject* pDataObject
									, DROPEFFECT dropEffect, CPoint point )
		//�y�I�[�o���C�h�z
		//	�h���b�O����Ă���̂��A�A�v���P�[�V�����ŃT�|�[�g���Ă���g���q
		//	�ł������ꍇ�́A���̃t�@�C������z��Ɋi�[���āADropProc() ��
		//	�Ăяo���܂�
{
	BOOL	bRv = FALSE ;
	
	if ( dropEffect == DROPEFFECT_COPY 
			&& pDataObject->IsDataAvailable( CF_HDROP ) ){
		HGLOBAL	hLGlobal = pDataObject->GetGlobalData( CF_HDROP ) ;
		CStringArray	astrLFilename ;
		HdropToFilenames( (HDROP)hLGlobal , &astrLFilename ) ;
		GlobalFree( hLGlobal ) ;
		if ( m_bAcceptSingle && astrLFilename.GetSize() != 1 ){
			return ( FALSE ) ;
		}
		FilenamesNoExtRemove( m_astrExt , &astrLFilename ) ;
		if ( astrLFilename.GetSize() > 0 ) {
 			return ( OnFiledrop( pWnd 
				, astrLFilename
				, dropEffect, point ) ) ;
 		}
	}
	return ( DROPEFFECT_NONE ) ; 
}


// ********************************
//	COleDropTarget
// ********************************
BOOL CDropTargetDoctmpl::OnFiledrop( CWnd* pWnd 
				, const CStringArray& astrEFilename
				, DROPEFFECT dropEffect, CPoint point ) 
		//pWnd
		//	�J�[�\�������݂���E�B���h�E�ւ̃|�C���^
		//astrEFilename
		//	�h���b�v�����f�[�^�������Ă���f�[�^ �I�u�W�F�N�g�ւ̃|�C���^�B
		//dropEffect
		//	���[�U�[���I������h���b�v����̌��ʁB���̒l�� 1 �ȏ��
		//	�g�ݍ��킹�����̂ł��B 
		//		DROPEFFECT_COPY   �R�s�[���삪�s���܂��B
		//		DROPEFFECT_MOVE   �ړ����삪�s���܂��B
		//		DROPEFFECT_LINK   �h���b�v���ꂽ�f�[�^�ƌ��̃f�[�^��
		//			�����N����܂��B
		//		DROPEFFECT_SCROLL   �h���b�O �X�N���[�����삪�^�[�Q�b�g����
		//			��������Ƃ��납�A�������Ă��܂��B 
		//point
		//	��ʏ�ɂ�����J�[�\���̈ʒu���s�N�Z���P�ʂŎw�肵�܂��B
		//[r]
		//	�h���b�v�����������ꍇ�� 0 �ȊO��Ԃ��܂��B
		//	����ȊO�̏ꍇ�� 0 ��Ԃ��܂��B
{
	BOOL	bRv = TRUE ;
	int	idxLFilename ;
	for ( idxLFilename = 0 
			; bRv && idxLFilename < astrEFilename.GetSize()
			; idxLFilename ++ ){
		CDocument*	pLDocument = AfxGetApp()
			->OpenDocumentFile( astrEFilename[idxLFilename] ) ;
	}
	return ( bRv ) ;
}

} //namespace Hidemdi
} //namespace OuMfc

