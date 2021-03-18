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
// CDlgRosenView.cpp : �C���v�������e�[�V���� �t�@�C��
//	$Id: CDlgRosenView.cpp 295 2016-06-11 05:14:13Z okm $

#include "stdafx.h"

#include <deque>

#include "NsOu/dynamic_castOu.h"
#include "TreeCtrl\CaTreeCtrl.h"

#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CDlgRosenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{

using namespace std ;
using OuMfc::TreeCtrl::CaTreeCtrl ;

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenView �_�C�A���O
// --------------------------------
//@name	�����֐�
// --------------------------------
int CDlgRosenView::onEnterItem( HTREEITEM aItem  , int iAction ) 
{
	int iRv = 0 ;

	CaTreeCtrl::Itemlocation	aItemPos ;
	if ( aItem != NULL )
	{
		CaTreeCtrl	aCaTreeCtrl( &m_treeROSEN ) ;
		aCaTreeCtrl.HTREEITEM_to_Itemlocation( aItem , &aItemPos ) ;
	}
	//	�H��
	if ( aItemPos.size() == 1 && 
			aItemPos[0] == 0 && 
			iAction != 1 )
	{
		//	�w�H���t�@�C���̃v���p�e�B�x
		//	�_�C�A���O�i���[�_���j���N�����܂��B
		getCDiagramEditApp()->getCMainFrame()->execCDlgRosenFileProp() ;

		iRv = 1 ;
	}
	//	�w
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 0 &&
			iAction != 2 )
	{
		//	�w�w�x�r���[���J���܂��B
		getCDiagramEditApp()->openCEkiDoc() ;

		iRv = 1 ;
	}
	//	��Ԏ��
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 1 &&
			iAction != 2 )
	{
		//	�w��Ԏ�ʁx�r���[���J���܂��B
		getCDiagramEditApp()->openCRessyasyubetsuDoc() ;

		iRv = 1 ;
	}
	//	�_�C��
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 &&
			iAction != 1 )
	{
		//	�w�_�C���ꗗ�x�_�C�A���O(���[�_��)���J���܂��B
		getCDiagramEditApp()->getCMainFrame()->execCDlgDiaList() ;

		iRv = 1 ;
	}
	//	�����\�����聄
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 && 
			aItemPos[3] == 0 &&
			iAction != 2 )
	{
		//	�w�����\�x�r���[���J���܂��B
		const CentDedDia*	pCentDedDia = getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedDiaCont()->getMuPtr()->get( aItemPos[2] ) ;
		if ( pCentDedDia != NULL )
		{
			getCDiagramEditApp()->openCJikokuhyouDoc( 
				pCentDedDia , 
				Ressyahoukou_Kudari , 
				NULL ) ;
		} 
		iRv = 1 ;
	}
	//	�����\����聄
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 &&
			aItemPos[3] == 1 &&
			iAction != 2 )
	{
		//	�w�����\�x�r���[���J���܂��B
		const CentDedDia*	pCentDedDia = getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedDiaCont()->getMuPtr()->get( aItemPos[2] ) ;
		if ( pCentDedDia != NULL ){
			getCDiagramEditApp()->openCJikokuhyouDoc( 
				pCentDedDia , 
				Ressyahoukou_Nobori , 
				NULL ) ;
		} 
		iRv = 1 ;
	}
	//	�_�C���O����
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 && 
			aItemPos[3] == 2 &&
			iAction != 2 )
	{
		//	�w�_�C���O�����x�r���[���J���܂��B
		const CentDedDia*	pCentDedDia = getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedDiaCont()->getMuPtr()->get( aItemPos[2] ) ;
		if ( pCentDedDia != NULL ){
			getCDiagramEditApp()->openCDedDiagramDoc( pCentDedDia ) ;
		} 
		iRv = 1 ;
	}
	//	�R�����g
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 3 &&
			iAction != 2 )
	{
		//	�w�R�����g�x�r���[���J���܂��B
		{
			getCDiagramEditApp()->openCDedCommentDoc() ;
		} 
		iRv = 1 ;
	}
	return ( iRv ) ;
}

	// ********************************
	//@name	CWnd
	// ********************************
BOOL CDlgRosenView::PreTranslateMessage(MSG* pMsg)
{

	// -------------------------------- 
	//        �_�C�A���O(��̃R���g���[��)�Ƀt�H�[�J�X�������Ԃ� 
	// �A�N�Z�����[�^�ɂ�郁�j���[�R�}���h�ւ̃A�N�Z�X�� 
	//        �s�����߂ɂ́A���C���t���[���E�C���h�E�� PreTranslateMessage() �� 
	//        �Ϗ����Ȃ��Ă͂Ȃ�܂���B 
	if ( WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST ) 
	{ 
		if ( AfxGetMainWnd()->PreTranslateMessage( pMsg ) ) 
		{ 
			return TRUE ; 
		} 
	} 
	// -------------------------------- 
	return CDialog::PreTranslateMessage(pMsg); 
}

// ********************************
//	CDlgRosenView
// ********************************
	// ********************************
	//@name ����
	// ********************************
void CDlgRosenView::UpdateROSEN( const CentDedRosen* pCentDedRosen ) 
{
	// --------------------------------
	//	���݂̑I���A�C�e�����擾
	// --------------------------------
	CaTreeCtrl::Itemlocation	aItemPos ;
	{
		HTREEITEM	hItem = m_treeROSEN.GetSelectedItem() ;
		if ( hItem != NULL ){
			CaTreeCtrl	aCaTreeCtrl( &m_treeROSEN ) ;
			aCaTreeCtrl.HTREEITEM_to_Itemlocation( hItem , &aItemPos ) ;
		}
	}


	// --------------------------------
	//	��U�A�S�A�C�e����j��
	// --------------------------------
	m_treeROSEN.DeleteAllItems() ;

	// --------------------------------
	//	���H��  �s�N�g�O�����̗��
	// --------------------------------
	HTREEITEM itemRosen = NULL ;
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_ROSEN ) ;
		
		string	strRosenName = pCentDedRosen->getName() ;
		if ( strRosenName.size() > 0 ){
			strItem = strRosenName.c_str() ;
		}

		int nImage = 0 ;
		int nSelectedImage = 0 ;

		itemRosen = m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , TVI_ROOT , TVI_LAST ) ;
		m_treeROSEN.SetItemState( itemRosen , TVIS_EXPANDED  ,  TVIS_EXPANDED  ) ;
	}

	// --------------------------------
	//	���w  �n�}�L���̉w
	// --------------------------------
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_EKI ) ;
		int nImage = 1 ;
		int nSelectedImage = 1 ;

		m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
	}
	// --------------------------------
	//	����Ԏ��  ���S�`���̃T�{
	// --------------------------------
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_RESSYASYUBETSU ) ;
		int nImage = 2 ;
		int nSelectedImage = 2 ;

		m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
	}
	// --------------------------------
	//	���_�C��      �w�����\�������ǂ����A�C�R��
	// --------------------------------
	HTREEITEM itemDia = NULL ;
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_DIA ) ;
		int nImage = 3 ;
		int nSelectedImage = 3 ;

		itemDia = m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
		m_treeROSEN.SetItemState( itemDia , TVIS_EXPANDED ,  TVIS_EXPANDED ) ;

	}
	//itemDia = ���w�_�C���x�A�C�e��

	// --------------------------------
	//	��(�_�C����)  �w�����\�������ǂ����A�C�R��
	// --------------------------------
	{
		int nImage = 4 ;
		int nSelectedImage = 4 ;
		
		const CentDedRosen*	pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr();

		int idxDia ;
		for ( idxDia = 0 ; idxDia < pCentDedDiaContGet->size() ; idxDia ++ ){
			const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idxDia ) ;
			string	strDiaName = pCentDedDia->getName() ;

			HTREEITEM itemDiaName = m_treeROSEN.InsertItem( strDiaName.c_str() , 
				nImage , nSelectedImage , itemDia , TVI_LAST ) ;
			m_treeROSEN.SetItemState( itemDiaName , TVIS_EXPANDED ,  TVIS_EXPANDED ) ;

			// --------------------------------
			//	�����莞���\/��莞���\  ���
			// --------------------------------
			{
				CString	strItem ;
				strItem.LoadString( IDS_WORD_KUDARIJIKOKUHYOU ) ;
				int nImage = 5 ;
				int nSelectedImage = 5 ;

				m_treeROSEN.InsertItem( strItem , 
					nImage , nSelectedImage , itemDiaName , TVI_LAST ) ;
			}
			{
				CString	strItem ;
				strItem.LoadString( IDS_WORD_NOBORIJIKOKUHYOU ) ;
				int nImage = 6 ;
				int nSelectedImage = 6 ;

				m_treeROSEN.InsertItem( strItem , 
					nImage , nSelectedImage , itemDiaName , TVI_LAST ) ;
			}
			// --------------------------------
			//	���_�C���O����  �_�C���O�����̐}��
			// --------------------------------
			{
				CString	strItem ;
				strItem.LoadString( IDS_WORD_DIAGRAM ) ;
				int nImage = 7 ;
				int nSelectedImage = 7 ;

				m_treeROSEN.InsertItem( strItem , 
					nImage , nSelectedImage , itemDiaName , TVI_LAST ) ;
			}
			
		}
	}
	// --------------------------------
	//	���R�����g(0,3)
	// --------------------------------
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_COMMENT ) ;
		int nImage = 8 ;
		int nSelectedImage = 8 ;

		itemDia = m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
		m_treeROSEN.SetItemState( itemDia , TVIS_EXPANDED ,  TVIS_EXPANDED ) ;

	}


	// --------------------------------
	//	�A�C�e����I��
	// --------------------------------
	if ( aItemPos.size() > 0 ){
		HTREEITEM	hItem = NULL ;
		{
			CaTreeCtrl	aCaTreeCtrl( &m_treeROSEN ) ;
			hItem = aCaTreeCtrl.HTREEITEM_from_Itemlocation( &aItemPos ) ;
		}
		
		
		if ( hItem != NULL ){
			m_treeROSEN.Select( hItem , TVGN_CARET ) ;
		}
	}
}

void CDlgRosenView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint ) 
{
	// --------------------------------
	//	�H��View���X�V
	// --------------------------------
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}
	// --------------------------------
	//pHint= 
	//	pHint�� CRfEditCmdHolder �I�u�W�F�N�g�Ȃ�A
	//	�Ή�����ҏW�R�}���h CRfEditCmd ��ێ����Ă��܂��B
	//	���̏ꍇ�Athis �� CRfEditCmd �̓��e�ɍœK������
	//	�X�V���s���܂��B
	//	NULL�Ȃ�A�S�X�V���v������Ă��܂��B


	// --------------------------------
	//	CRfEditCmd �ɍœK�����ꂽ�X�V
	// --------------------------------
	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) ){
		CRfEditCmdHolder* pCHolder = (CRfEditCmdHolder*)pHint ;
		pCmd = pCHolder->getCmd() ;
	}
	if ( pCmd != NULL ){
		if ( 
			dynamic_castOu<CRfEditCmd_Comment>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_Eki>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) 
		){
			//	���̃r���[�́A�ȉ��̏󋵂ł͍X�V�͕s�v�ł��B
			//		�R�����g�̕ҏW
			//		�w�̕ҏW
			//		��Ԃ̕ҏW
			//		��Ԃ̒��ʉ�
			//		��Ԏ�ʂ̕ҏW
			//		��Ԏ�ʂ̓���
		}
		else
		{
			//	�S�X�V���s�킹�܂��B
			//CRfEditCmd_DedRosenFileDataProp
			//	�H�����̕ύX�𔽉f����K�v������܂��B
			//CDedRosenFileData_Dia
			//	�_�C���̒ǉ��E�폜
			//CDedRosenFileData_DiaProp
			//	�_�C�����̕ύX
			//CRfEditCmd_Rosen
			//	�H���I�u�W�F�N�g�̑S�u����
			//CRfEditCmd_RosenFileData
			//	�H���t�@�C���f�[�^�̑S�u����
			pHint = NULL ;
		}
	}

	//	�S�X�V���s���܂��B
	if ( pHint == NULL ){
			getCDiagramEditApp()->getCDlgRosenView()->UpdateROSEN( 
				getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ) ;
	}
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

CDlgRosenView::CDlgRosenView(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRosenView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRosenView)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CDlgRosenView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRosenView)
	DDX_Control(pDX, IDC_TREE_ROSEN, m_treeROSEN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRosenView, CDialog)
	//{{AFX_MSG_MAP(CDlgRosenView)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_TREE_ROSEN, OnClickTreeRosen)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_ROSEN, OnDblclkTreeRosen)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_MENUITEM_OPEN, &CDlgRosenView::OnMenuitemOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenView ���b�Z�[�W �n���h��

BOOL CDlgRosenView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// --------------------------------
	m_imagelistROSEN.Create( IDB_TREE_ROSEN , 16 , 16 , RGB( 255 , 255 , 255 ) ) ;
	m_treeROSEN.SetImageList( &m_imagelistROSEN , TVSIL_NORMAL   ) ;


	// --------------------------------
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgRosenView::OnSize(UINT nType, int cx, int cy) 
{
	//CDialog::OnSize(nType, cx, cy);
	

	if ( GetDlgItem( IDC_TREE_ROSEN ) == NULL ){
		return ;
	}
	// --------------------------------
	//	�e�E�C���h�E�̌��݂̈ʒu���擾
	// --------------------------------
	CRect	rectThis ;
	{
		GetClientRect( &rectThis  ) ;
	}
	CRect	rectIDC_TREE_ROSEN ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		GetDlgItem( IDC_TREE_ROSEN ) ->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectIDC_TREE_ROSEN = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	// --------------------------------
	//	�e�E�C���h�E�̐V�����ʒu���Z��
	// --------------------------------
	CRect	rectIDC_TREE_ROSENNew  ;
	{
		rectIDC_TREE_ROSENNew = rectIDC_TREE_ROSEN ;
		rectIDC_TREE_ROSENNew.right = rectThis.right ; 
		if ( rectIDC_TREE_ROSENNew.right < rectIDC_TREE_ROSENNew.left ){
			rectIDC_TREE_ROSENNew.right = rectIDC_TREE_ROSENNew.left ;
		}
		rectIDC_TREE_ROSENNew.bottom = rectThis.bottom ; 
		if ( rectIDC_TREE_ROSENNew.bottom < rectIDC_TREE_ROSENNew.top ){
			rectIDC_TREE_ROSENNew.bottom = rectIDC_TREE_ROSENNew.top ;
		}
	}
	// --------------------------------
	//	�e�E�C���h�E�̐V�����ʒu��ݒ�
	// --------------------------------
	GetDlgItem( IDC_TREE_ROSEN )->SetWindowPos( NULL , 
		rectIDC_TREE_ROSENNew.left , 
		rectIDC_TREE_ROSENNew.top , 
		rectIDC_TREE_ROSENNew.Width() , 
		rectIDC_TREE_ROSENNew.Height() , 
		SWP_NOZORDER ) ;   
	
}

void CDlgRosenView::OnOK() 
{
	// �q�_�C�A���O�̏ꍇ�́AOnOK()�EOnCancel()
	//	�́A�I�[�o���C�h���āA
	//	CDlalog::OnOK()�̌ďo�͗}�~���Ȃ��Ă�
	//	�Ȃ�܂���B
	//
	//CDialog::OnOK();

	//	OnOK() �ɂ́A���^�[���L�[�̑�����������܂��B

	// --------------------------------
	int iRv = 0 ;
	HTREEITEM	aItem = NULL ;
	{
		aItem = m_treeROSEN.GetSelectedItem() ;
	}
	{
		iRv = onEnterItem( aItem , 0 ) ;
	}
	// --------------------------------
	
}

void CDlgRosenView::OnCancel() 
{
	// �q�_�C�A���O�̏ꍇ�́AOnOK()�EOnCancel()
	//	�́A�������Ȃ��悤�ɃI�[�o���C�h���Ȃ��Ă͂Ȃ�܂���B
	//
	//CDialog::OnCancel();
}

void CDlgRosenView::OnClickTreeRosen(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	//	NM_DBLCLK (tree view)
	//	Return nonzero to prevent the default processing, 
	//	or zero to allow the default processing.
	//
	//	0 ;	//	�W���̏������s���܂��B
	//	1 ;	//	�W���̏������s���܂���B
	*pResult = 0 ;

	// --------------------------------
	int iRv = 0 ;
	HTREEITEM	aItem = NULL ;
	{
		CPoint	aPoint ;
		GetCursorPos( &aPoint ) ;
		m_treeROSEN.ScreenToClient( &aPoint ) ;
		UINT iFlags = 0 ;	
		aItem = m_treeROSEN.HitTest( aPoint , &iFlags ) ;

		// --------------------------------
		/*
		//	Tree�R���g���[���̃C�x���g�̓��e
		LogMsg( "CDlgRosenView::OnClickTreeRosen()" ) ;
		if ( iFlags & TVHT_ABOVE ){
			LogMsg( "\tTVHT_ABOVE" ) ;
		}
		if ( iFlags & TVHT_BELOW ){
			LogMsg( "\tTVHT_BELOW" ) ;
		}
		if ( iFlags & TVHT_NOWHERE ){
			//	���́A�A�C�e���̂Ȃ��̈�
			LogMsg( "\tTVHT_NOWHERE" ) ;
		}
		if ( iFlags & TVHT_ONITEM ){
			//	�A�C�e���̃A�C�R��
			//	�A�C�e���̃��x��
			LogMsg( "\tTVHT_ONITEM" ) ;
		}
		if ( iFlags & TVHT_ONITEMBUTTON ){
			//	[+][-]�{�^��
			LogMsg( "\tTVHT_ONITEMBUTTON" ) ;
		}
		if ( iFlags & TVHT_ONITEMICON ){
			//	�A�C�e���̃A�C�R��
			LogMsg( "\tTVHT_ONITEMICON" ) ;
		}
		if ( iFlags & TVHT_ONITEMINDENT ){
			LogMsg( "\tTVHT_ONITEMINDENT" ) ;
		}
		if ( iFlags & TVHT_ONITEMLABEL ){
			//	�A�C�e���̃��x��
			LogMsg( "\tTVHT_ONITEMLABEL" ) ;
		}
		if ( iFlags & TVHT_ONITEMRIGHT ){
			//	�A�C�e���̉E��
			LogMsg( "\tTVHT_ONITEMRIGHT" ) ;
		}
		if ( iFlags & TVHT_ONITEMSTATEICON ){
			LogMsg( "\tTVHT_ONITEMSTATEICON" ) ;
		}
		if ( iFlags & TVHT_TOLEFT ){
			LogMsg( "\tTVHT_TOLEFT" ) ;
		}
		if ( iFlags & TVHT_TORIGHT ){
			LogMsg( "\tTVHT_TORIGHT" ) ;
		}
		*/
		// --------------------------------
		if ( ( iFlags & TVHT_ONITEM ) )
		{
			iRv = onEnterItem( aItem , 1 ) ;
			if ( iRv == 1 )
			{
				//	*pResult �� 1 �ɂ���ƁA�N���b�N���ꂽ�A�C�e����
				//	�I����ԃA�C�e���ɂȂ�܂���B
				//
				//	*pResult = 1 ;
			}
		}
	}
}

void CDlgRosenView::OnDblclkTreeRosen(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//	NM_DBLCLK (tree view)
	//	Return nonzero to prevent the default processing, 
	//	or zero to allow the default processing.
	//
	//	0 ;	//	�W���̏������s���܂��B
	//	1 ;	//	�W���̏������s���܂���B
	*pResult = 0 ;

	// --------------------------------
	int iRv = 0 ;
	HTREEITEM	aItem = NULL ;
	{
		CPoint	aPoint ;
		GetCursorPos( &aPoint ) ;
		m_treeROSEN.ScreenToClient( &aPoint ) ;
		UINT iFlags = 0 ;	
		aItem = m_treeROSEN.HitTest( aPoint , &iFlags ) ;

		// --------------------------------
		if ( ( iFlags & TVHT_ONITEM ) ){
			iRv = onEnterItem( aItem , 2 ) ;
			if ( iRv == 1 ){
				//	*pResult �� 0 �ɂ���ƁA�_�u���N���b�N���ꂽ�A�C�e����
				//	�q�A�C�e�����W�J����܂��B
				*pResult = 1 ;
			}
		}
	}
}

void CDlgRosenView::OnMenuitemOpen()
{
	if ( m_treeROSEN.getItemContextMenu() != NULL )
	{
		onEnterItem( m_treeROSEN.getItemContextMenu() , 1 ) ;
	}
}
} //namespace ViewRosen
