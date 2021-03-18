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
#if !defined(AFX_CJIKOKUHYOUDOC_H__FCE36EB0_2EBD_4E11_B59B_A7EBE1843A4E__INCLUDED_)
#define AFX_CJIKOKUHYOUDOC_H__FCE36EB0_2EBD_4E11_B59B_A7EBE1843A4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CJikokuhyouDoc.h : �w�b�_�[ �t�@�C��
//$Id: CJikokuhyouDoc.h 261 2016-01-23 03:59:53Z okm $
/** @file */

#include "..\entDed\CentDed.h"
#include "Hidemdi\Hidemdi.h"

namespace ViewJikokuhyou{
using namespace entDed;
using namespace OuMfc::Hidemdi;
/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouDoc �h�L�������g
/**
 * @brief
 *	��Ԃ̎����\�r���[�́A
 *	�h�L�������g�N���X�ł��B
 *	
 *	
 *	Docstr = "<�_�C����>\n<��ԕ���>"
 */
class CJikokuhyouDoc : public CHidemdiSubDoc
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	typedef CHidemdiSubDoc super ;
// ********************************
///@name �֘A
// ********************************
///@{
 private:
	/**
	 *	���̃h�L�������g/�r���[���\�����Ă���_�C���̃_�C�������w���܂��B
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	 *
	 *	SetTitle() �Ō��܂�܂��B
	 *
	 *	this �́A���̃I�u�W�F�N�g�����[�g�h�L�������g
	 *	CDiagramEditDoc ����
	 *	�폜���ꂽ���Ƃ����m������A
	 *	this �� CDocTemplate::RemoveDocument() ��
	 *	�폜���܂��B
	 */
	std::string	m_strDiaName ;

	/**
	 *	���̃h�L�������g/�r���[���\������
	 *	��ԕ����������񋓂ł��B
	 *	-	���� Ressyahoukou_Kudari
	 *	-	��� Ressyahoukou_Nobori ,
	 *
	 *	SetTitle() �Ō��܂�܂��B
	 */
	ERessyahoukou	m_eRessyahoukou ; 
//@}
// ********************************
///@name CDocument
// ********************************
///@{
 protected:
	/**
	 *	���̃h�L�������g���������ꂽ�Ƃ��ɌĂяo����܂��B
	 *
	 *	strDocument= "<�_�C���̃C���f�N�X>,<��ԕ���>"
	 */
	virtual void SetTitle( LPCTSTR lpszTitle );
///@}

// ********************************
//	CJikokuhyouDoc
// ********************************
 public:
	// ********************************
	///@name CJikokuhyouDoc-�֘A
	// ********************************
	///@{
	std::string getDiaName()
	{
		return m_strDiaName ; 
	} ;
	int getDiaIndex();
	ERessyahoukou	getRessyahoukou()
	{
		return m_eRessyahoukou ;
	}; 
	///@}

// ----------------------------------------------------------------
protected:
	CJikokuhyouDoc();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	DECLARE_DYNCREATE(CJikokuhyouDoc)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CJikokuhyouDoc)
	public:
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CJikokuhyouDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// ���b�Z�[�W �}�b�v�֐��̐���
protected:
	//{{AFX_MSG(CJikokuhyouDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewJikokuhyou

#endif // !defined(AFX_CJIKOKUHYOUDOC_H__FCE36EB0_2EBD_4E11_B59B_A7EBE1843A4E__INCLUDED_)
