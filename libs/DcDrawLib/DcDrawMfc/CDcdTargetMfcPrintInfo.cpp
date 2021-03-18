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
//	CDcdTargetMfcPrintInfo.cpp
// ****************************************************************
*/

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

#include <sstream>
#include <string>


#include "CDcdTargetMfcPrintInfo.h"
#include "logmsg/LogMsg.h"
#include "DcDraw/CDcDeviceUnitSizeY.h"
#include "DcDraw\CConverter_WinGdi.h"

namespace DcDrawLib{
namespace DcDrawMfc{

using namespace std ;

// ****************************************************************
//	CDcdTargetMfcPrintInfo
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CDcdTargetMfcPrintInfo::CDcdTargetMfcPrintInfo( 
		CDC*			pCDC ,
		const CPrintInfo*	pCPrintInfo ) :
	m_pCDC( pCDC ) ,
	m_pCPrintInfo( pCPrintInfo )
{
	{
		RECT	aRECT = m_pCPrintInfo->m_rectDraw ;
	
		m_zonexyZone = CdDcdZoneXy( 
			CdDcdZone( aRECT.left , aRECT.right - aRECT.left ) ,
			CdDcdZone( aRECT.top , aRECT.bottom - aRECT.top ) ) ;
	}
}
	
CDcdTargetMfcPrintInfo::~CDcdTargetMfcPrintInfo() 
{
}

// ********************************
//@name	IfDcdTarget
// ********************************
HDC	CDcdTargetMfcPrintInfo::getHdc() 
{
	return m_pCDC->GetSafeHdc() ;
}
CdDcdZoneXy CDcdTargetMfcPrintInfo::getZone() 
{
	return m_zonexyZone ;
}
CdDcdZoneXy CDcdTargetMfcPrintInfo::getDrawableZone() 
{
	return m_zonexyZone ;
}

Ou<CGdiHFontHolder>	CDcdTargetMfcPrintInfo::createGdiHFontHolder(  const CdFontProp& paramCdFontProp ) 
{
	CConverter_WinGdi	aConv ;

	CdFontProp	aCdFontProp( paramCdFontProp ) ;
	if ( isPreview() && aCdFontProp.getPointTextHeight() > 0 ){
		//	�`��Ώۂ�����v���r���[�ŁA
		//	�t�H���g���|�C���g�T�C�Y�ō쐬����ꍇ�A�����
		//	�v���r���[�E�C���h�E��DC�i���W�ɃY�[�����w�肳��Ă���j�ł͂Ȃ�
		//	���DC�i�Y�[���̂Ȃ����W�n�j�ŁA�_���P�ʂɊ��Z����悤�ɂ��܂���
		//	�i�������Ȃ��ƁA�v���r���[��ʂł̃t�H���g�̑傫����
		//	����������܂���j

		HDC hDcScreen = GetDC( NULL ) ;
		
		int iDp = CDcDeviceUnitSizeY( hDcScreen ).
						setPointSize( aCdFontProp.getPointTextHeight() ).
						getDeviceUnitSize() ;
		aCdFontProp.setLogicalunitTextHeight( iDp ) ;

		ReleaseDC( NULL , hDcScreen ) ;

	}
	return aConv.createGdiHFontHolder( aCdFontProp , getHdc() ) ;
}
	
Ou<CGdiHPenHolder> CDcdTargetMfcPrintInfo::createGdiHPenHolder(  const CdPenProp& aCdPenProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHPenHolder( aCdPenProp ) ;
}

Ou<CGdiHBrushHolder> CDcdTargetMfcPrintInfo::createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHBrushHolder( aCdBrushProp ) ;
}

	
// ********************************
//	CDcdTargetMfcPrintInfo
// ********************************
	// ********************************
	//@name �֘A
	// ********************************
HDC CDcdTargetMfcPrintInfo::getPrinterHdc() 
{
	return ( m_pCDC->m_hAttribDC ) ;
}
	// ********************************
	//@name ����
	// ********************************
bool CDcdTargetMfcPrintInfo::isPreview() 
{
	return ( m_pCPrintInfo->m_bPreview != FALSE ) ;
}
	// ********************************
	//@name �f�o�b�O�p�֐�
	// ********************************
string CDcdTargetMfcPrintInfo::stringOf( CPrintInfo* pInfo ) 
{

	string	strRv ;
	{
		stringstream	sstrLs ;

		sstrLs << "\t m_bDocObject=" << pInfo->m_bDocObject << endl ;
		// �������h�L�������g�� DocObject �ł��邩�ǂ����������t���O��ێ����܂��B 
		sstrLs << "\t m_dwFlags=" << pInfo->m_dwFlags << endl ;
		//	DocObject ���������w�肵�܂��B 
		sstrLs << "\t m_nOffsetPage=" << pInfo->m_nOffsetPage << endl ;
		//	��������Ă��� DocObject ����W���u���ł̓���� DocObject �̐擪�y�[�W�̃I�t�Z�b�g���w�肵�܂��B 
		//m_pPD [���] �_�C�A���O �{�b�N�X�Ŏg���� CPrintDialog �I�u�W�F�N�g�̃|�C���^��ێ����܂��B 
		sstrLs << "\t m_bDirect=" << pInfo->m_bDirect << endl ;
		//�h�L�������g�� ([���] �_�C�A���O �{�b�N�X��\��������) ���ڈ������邩�ǂ����������t���O��ێ����܂��B 
		sstrLs << "\t m_bPreview=" << pInfo->m_bPreview << endl ;
		//	�h�L�������g���v���r���[����Ă��邩�ǂ����������t���O��ێ����܂��B 
		sstrLs << "\t m_bContinuePrinting=" << pInfo->m_bContinuePrinting << endl ;
		//	�t���[�����[�N������p���[�v�𑱂��邩�ǂ����������t���O��ێ����܂��B 
		sstrLs << "\t m_nCurPage=" << pInfo->m_nCurPage << endl ;
		//	���݈������Ă���y�[�W�ԍ��������܂��B 
		sstrLs << "\t m_nNumPreviewPages=" << pInfo->m_nNumPreviewPages << endl ;
		//	�v���r���[�p�E�B���h�E�ɕ\������Ă���y�[�W�̐��������܂��B1�A�܂��� 2 �ł��B 
		sstrLs << "\t m_lpUserData=" << pInfo->m_lpUserData << endl ;
		//	�Ǝ��ɗp�ӂ����\���̂ւ̃|�C���^��ێ����܂��B 
		sstrLs << "\t m_rectDraw=" << 
			 pInfo->m_rectDraw.left << " " <<  pInfo->m_rectDraw.top << " " <<  
			 pInfo->m_rectDraw.right << " " <<   pInfo->m_rectDraw.bottom << endl  ; 
		//	���ݎg�p�\�ȃy�[�W�̈�Ƃ��Ē�`����Ă��钷���`�̈�������܂��B 
		sstrLs << "\t m_strPageDesc=" << (LPCTSTR)pInfo->m_strPageDesc << endl ;
		//	�y�[�W�ԍ��̕\���t�H�[�}�b�g���w�肷�镶�����ێ����܂��B 

		strRv = sstrLs.str() ;
	}
	return ( strRv ) ;
};

} //namespace DcDrawMfc
} //namespace DcDrawLib
