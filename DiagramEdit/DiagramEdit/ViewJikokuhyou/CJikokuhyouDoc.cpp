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
// CJikokuhyouDoc.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "..\DiagramEdit.h"
#include "CJikokuhyouDoc.h"
#include "str/stringSplit.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <vector>
#include <string>

namespace ViewJikokuhyou{

using namespace std ;

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouDoc
// ********************************
//@name CDocument
// ********************************
void CJikokuhyouDoc::SetTitle( LPCTSTR lpszTitle )
{
	string	strTitle = lpszTitle ;
	vector<string>	arstrTitle = splitc< vector< string > >( '\n' , lpszTitle  ) ;
	m_strDiaName = arstrTitle[0] ;
	m_eRessyahoukou = (ERessyahoukou)atoi( arstrTitle[1].c_str() ) ;

	if ( getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedDiaCont()->findCentDedDiaByName( m_strDiaName ) < 0 ){
		ASSERT( 0 ) ;
	}

	// --------------------------------
	//	�^�C�g��������̍쐬
	// --------------------------------
	{
		CString	strDiamei =m_strDiaName.c_str() ;
		CString	strRessyahoukou ;
		if ( m_eRessyahoukou == Ressyahoukou_Kudari ){
			strRessyahoukou.LoadString( IDS_WORD_KUDARIJIKOKUHYOU ) ;
		}	else	{
			strRessyahoukou.LoadString( IDS_WORD_NOBORIJIKOKUHYOU ) ;
		}
		strDiamei += " " ;
		strDiamei += strRessyahoukou ;
		super::SetTitle( strDiamei ) ;
	}
}

int CJikokuhyouDoc::getDiaIndex()
{
	return ( getCDiagramEditDoc()->getCDedRosenFileData()->
		getCentDedRosen()->getCentDedDiaCont()->
		findCentDedDiaByName( getDiaName() ) ) ;
}

// ----------------------------------------------------------------
IMPLEMENT_DYNCREATE(CJikokuhyouDoc, CHidemdiSubDoc)

CJikokuhyouDoc::CJikokuhyouDoc()
	:  m_eRessyahoukou( Ressyahoukou_Kudari ) 
{
}

BOOL CJikokuhyouDoc::OnNewDocument()
{
	if (!CJikokuhyouDoc::super::OnNewDocument())
		return FALSE;
	return TRUE;
}

CJikokuhyouDoc::~CJikokuhyouDoc()
{
}


BEGIN_MESSAGE_MAP(CJikokuhyouDoc, CHidemdiSubDoc)
	//{{AFX_MSG_MAP(CJikokuhyouDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouDoc �f�f

#ifdef _DEBUG
void CJikokuhyouDoc::AssertValid() const
{
	CJikokuhyouDoc::super::AssertValid();
}

void CJikokuhyouDoc::Dump(CDumpContext& dc) const
{
	CJikokuhyouDoc::super::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouDoc �V���A���C�Y



/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouDoc �R�}���h

} //namespace ViewJikokuhyou

