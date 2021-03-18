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
#if !defined(AFX_CDEDDIAGRAMVIEW_H__51A5E4F0_D26B_4032_A34F_3BC45B6B3F1F__INCLUDED_)
#define AFX_CDEDDIAGRAMVIEW_H__51A5E4F0_D26B_4032_A34F_3BC45B6B3F1F__INCLUDED_
// cdeddiagramview.h : �w�b�_�[ �t�@�C��
//	$Id: CDedDiagramView.h 295 2016-06-11 05:14:13Z okm $
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NsOu/Ou.h"

#include "DiagramEdit.h"
#include "..\entDgr\CentDedDgrDia.h"
#include "CWndDiagram.h"
#include "DedRosenFileData\EditCmd\CRfEditCmd_Ressya.h"

namespace ViewDiagram{
	using namespace DedRosenFileData::EditCmd;
	using namespace entDed;

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView �r���[
/**
	@brief
	�_�C���O�����̃r���[�ł��B
 */
class CDedDiagramView : public CView
{
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		�w�_�C���O�����G���e�B�e�B�N���X�Q�x��
		�w�_�C���O�����_�C���x�I�u�W�F�N�g�B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��� this �ɂ���܂��B
		OnInitialUpdate()�Ő������A�f�X�g���N�^�Ŕj�����܂��B
	 */
	CentDedDgrDia* m_pCentDedDgrDia ;

	/**
		�_�C���O������`�悷��q�E�C���h�E�B
		OnCreate() �Ő������A OnDestroy() �Ŕj�����܂��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��� this �ɂ���܂��B
		
	*/
	CWndDiagram* m_pCWndDiagram ;
	///@}

private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
		�S�X�V���ۗ�����Ă����� true �B

		�ʏ�� false �B
		���̃r���[���A�N�e�B�u�łȂ��Ƃ��� 
		�S�X�V�i OnUpdate_All() ���Ăяo���j���K�v�ɂȂ��Ă���A
		�r���[���A�N�e�B�u�ɂȂ�܂ł̊Ԃ��� true �ɂȂ�܂��B
		
		���̕ϐ��� true �̂Ƃ��́A
		�r���[�̍X�V���A���Ƀr���[���A�N�e�B�u�������܂�
		�ۗ����Ă��邱�Ƃ������܂��B
	
		�r���[���A�N�e�B�u�łȂ��Ƃ��� OnUpdate_All() ��
		�v�����ꂽ��A���̕ϐ��� true �ɂ��A
		OnUpdate_All() �͎��s���܂���B
	
		���̒l�� true �̂Ƃ��ɁA�r���[���A�N�e�B�u�����ꂽ��A
		OnUpdate_All() �����s���܂��B
	*/
	bool m_bUpdate_All_Requested ;

	/**
		������ɁA�P�y�[�W�Ɉ������_�C���O�����͈̔͂��A
		�_�C���O�����G���e�B�e�B���W�ŕێ����܂��B

		���̒l�́A���[�U�[�����j���[�R�}���h
		[���][����v���r���[]��I���������_��
		�r���[�ɕ\������Ă���_�C���O�����͈̔͂ɂȂ�܂��B
	*/
	CdDcdSizeXy	m_sizePrintSize_Dgr ;

	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	 @return
		�Ή�����h�L�������g�I�u�W�F�N�g��Ԃ��܂��B
	 */
	CDedDiagramDoc*	GetDocument() {
		CView* pCView = this ;
		return (CDedDiagramDoc*)pCView->GetDocument() ;};
	
	/**
	 @return
		CentDedDia �I�u�W�F�N�g��Ԃ��܂��B
	 */
	const CentDedDia*	getCentDedDia()
	{
		const CentDedRosen*	pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		return pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get(  
			pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( 
				GetDocument()->getDiaName() 
			) 
		) ;
	};
	///@}
private:
	// --------------------------------
	///@name OnUpdate�����֐�
	// --------------------------------
	///@{
	/**
		OnUpdate() �� pHint �� CHint_CentDedRessya �I�u�W�F�N�g��
		�Ȃ��ꍇ�ł��B
	
		m_pCentDedDgrDia �I�u�W�F�N�g�����S�ɍX�V���A
		�E�C���h�E m_pCWndDiagram �ɔ��f�����܂��B
	 */
	void OnUpdate_All() ;
	/**
		OnUpdate() �� pHint �� CHint_CentDedRessya �I�u�W�F�N�g��
		�ꍇ�ł��B
	
		m_pCentDedDgrDia �I�u�W�F�N�g�����S�ɍX�V���A
		�E�C���h�E m_pCWndDiagram �ɔ��f�����܂��B
	 */
	void OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) ;
	///@}
private:
	// --------------------------------
	///@name MFC�R�}���h�n���h�������֐�
	// --------------------------------
	///@{
	/** [�\��]-[���������k��]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
				�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		-	0 :	����
		-	-1 :	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
		-	-2 ;	//	�_�C���O�����͕\������Ă��܂���B
	*/
	int OnDiagramXDgrSizeInc_Process( BOOL bQueryEnable );
	/** [�\��]-[���������g��]
	@return
		-	0 :	����
		-	-1 :	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
		-	-2 ;	//	�_�C���O�����͕\������Ă��܂���B
	*/
	int OnDiagramXDgrSizeDec_Process( BOOL bQueryEnable );
	/** [�\��]-[�c�������k��] 
	@return
		-	0 :	����
		-	-1 :	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
		-	-2 ;	//	�_�C���O�����͕\������Ă��܂���B
	*/
	int OnDiagramYDgrSizeInc_Process( BOOL bQueryEnable );
	/** [�\��]-[�c�������g��]
	@return
		-	0 :	����
		-	-1 :	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
		-	-2 ;	//	�_�C���O�����͕\������Ă��܂���B
	*/
	int OnDiagramYDgrSizeDec_Process( BOOL bQueryEnable );
	/** [�\��]-[�c���������Z�b�g]
	@return
		-	0 :	����
		-	-2 ;	//	�_�C���O�����͕\������Ă��܂���B
	*/
	int OnDiagramYDgrSizeReset_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [�\��]-[�ڐ����ׂ�������]
	@return
		-	0 :	����
		-	-1 ;	//	�R�}���h�𖳌�
	*/
	int OnDiagramMemoriDown_Process( BOOL bQueryEnable );
	/** [�\��]-[�ڐ���e������]
	@return
		-	0 :	����
		-	-1 ;	//	�R�}���h�𖳌�
	*/
	int OnDiagramMemoriUp_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [�\��]-[��Ԕԍ��̕\��]
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h�������ł��B
	*/
	int OnDiagramRessyabangou_Process( BOOL bQueryEnable );

	/** [�\��]-[��Ԗ��̕\��]
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h�������ł��B
	*/
	int OnUpdateDiagramRessyamei_Process( BOOL bQueryEnable );

	/** [�\��]-[�����Ԃ̕\��]
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h�������ł��B
	*/
	int OnDiagramRessyasenKudari_Process( BOOL bQueryEnable );
	/** [�\��]-[����Ԃ̕\��]
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h�������ł��B
	*/
	int OnDiagramRessyasenNobori_Process( BOOL bQueryEnable );
	/** [�\��]-[��ʉw�̉w����\�����Ȃ�]
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h�������ł��B
	*/
	int OnDiagramHideIppanekiEkimei_Process( BOOL bQueryEnable );
	/** [�\��]-[��ԉw�̖���]
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)���̃��j���[�R�}���h�������ł��B
	*/
	int OnDiagramStopmarkdraw_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [�\��]-[�X�V]
	@see OnDiagramXDgrSizeInc_Process  
	*/
	int OnViewUpdate_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [�\��]-[�_�C���O�����r���[�̃v���p�e�B]
	@see OnDiagramXDgrSizeInc_Process  
	*/
	int OnDiagramViewProp_Process( BOOL bQueryEnable );
	
	///@}
// ********************************
//	CDedDiagramView
// ********************************
public:
	// ********************************
	///@name CDedDiagramView-����
	// ********************************
	///@{
	/**
		�_�C���O�����r���[�̕\���ʒu���A
		�w��̎����A�w��̉wOrder�Ɉړ������܂��B
	 @param aCdDedJikoku [in]
		�������w�肵�Ă��������B
		���̊֐��́A�_�C���O�����r���[�̍��[���A���̎����ɂ��܂��B
		NULL �������w�肵���ꍇ�A�_�C���O�����r���[��X�����̈ʒu��
		�ύX���܂���B
	 @param iEkiIndex [in]
		�w�wIndex�x���w�肵�Ă��������B
		���̊֐��́A�_�C���O�����̏�[�E���[���A���́w�wIndex�x�ɂ��܂��B
		���̐����w�肵���ꍇ�A�_�C���O�����r���[��Y�����̈ʒu��
		�ύX���܂���B
		�_�C���O�����̏�[�E���[�̂ǂ�������́w�wIndex�x�ɂ��邩�́A
		bEkiOrderIsBottom �Ŏw�肵�܂��B
	 @param bEkiIndexIsBottom [in]
		- false ;	//	���̊֐��� iEkiIndex ���A�_�C���O�����̏�[�ɂ��܂��B
		- true ;	//	���̊֐��� iEkiIndex ���A�_�C���O�����̉��[�ɂ��܂��B
	 */
	virtual int setZone_Dgr( 
		const CdDedJikoku& aCdDedJikoku ,
		int iEkiIndex , bool bEkiIndexIsBottom ) ; 
	///@}


// ----------------------------------------------------------------
protected:
	CDedDiagramView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^
	DECLARE_DYNCREATE(CDedDiagramView)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CDedDiagramView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h���܂����B
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CDedDiagramView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:

private:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�

	//{{AFX_MSG(CDedDiagramView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDiagramViewProp();
	afx_msg void OnDiagramXDgrSizeInc();
	afx_msg void OnUpdateDiagramXDgrSizeInc(CCmdUI* pCmdUI);
	afx_msg void OnDiagramXDgrSizeDec();
	afx_msg void OnUpdateDiagramXDgrSizeDec(CCmdUI* pCmdUI);
	afx_msg void OnDiagramYDgrSizeInc();
	afx_msg void OnUpdateDiagramYDgrSizeInc(CCmdUI* pCmdUI);
	afx_msg void OnDiagramYDgrSizeDec();
	afx_msg void OnUpdateDiagramYDgrSizeDec(CCmdUI* pCmdUI);
	afx_msg void OnDiagramYDgrSizeReset();
	afx_msg void OnUpdateDiagramYDgrSizeReset(CCmdUI* pCmdUI);
	afx_msg void OnDiagramMemoriDown();
	afx_msg void OnUpdateDiagramMemoriDown(CCmdUI* pCmdUI);
	afx_msg void OnDiagramMemoriUp();
	afx_msg void OnUpdateDiagramMemoriUp(CCmdUI* pCmdUI);
	afx_msg void OnDiagramRessyabangou();
	afx_msg void OnUpdateDiagramRessyabangou(CCmdUI* pCmdUI);
	afx_msg void OnDiagramRessyamei();
	afx_msg void OnUpdateDiagramRessyamei(CCmdUI* pCmdUI);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnDiagramRessyasenKudari();
	afx_msg void OnUpdateDiagramRessyasenKudari(CCmdUI* pCmdUI);
	afx_msg void OnDiagramRessyasenNobori();
	afx_msg void OnUpdateDiagramRessyasenNobori(CCmdUI* pCmdUI);
	afx_msg void OnDiagramHideIppanekiEkimei();
	afx_msg void OnUpdateDiagramHideIppanekiEkimei(CCmdUI* pCmdUI);
	afx_msg void OnViewUpdate();
	afx_msg void OnDiagramStopmarkdraw();
	afx_msg void OnUpdateDiagramStopmarkdraw(CCmdUI* pCmdUI);
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewDiagram

#endif // !defined(AFX_CDEDDIAGRAMVIEW_H__51A5E4F0_D26B_4032_A34F_3BC45B6B3F1F__INCLUDED_)
