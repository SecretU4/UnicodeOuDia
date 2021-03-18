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
//	CDropTargetDoctmpl.h
// ****************************************************************
*/
/** @file */
#ifndef  CDropTargetDoctmpl_h
#define  CDropTargetDoctmpl_h

#include <afxwin.h>
#include <afxole.h>

namespace OuMfc{
namespace Hidemdi{

// ****************************************************************
//	CDropTargetDoctmpl
// ****************************************************************
/** @brief 
* �y�T�v�z
* 	 CF_HDROP �`���ŁA���炩���ߎw�肳�ꂽDoctemplate�ɓo�^����Ă���
* 	�g���q�����t�@�C�������̃h���b�v���󂯓���܂��B
*
* �y�g�����z
*
* �P�D	���̃I�u�W�F�N�g���A���C���t���[���E�C���h�E�I�u�W�F�N�g��
* 	�����o�ϐ��Ƃ��Đ錾���Ă��������B
*
* �Q�D  ���C���t���[���E�C���h�E�� OnCreate() �ŁA���̃I�u�W�F�N�g��
* 	Register() ���\�b�h���Ăяo���āA���C���t���[���E�C���h�E�I�u�W�F�N�g��
* 	���̃I�u�W�F�N�g�ɓo�^���Ă��������B
*
* �R�D  ���C���t���[���E�C���h�E�� OnDestroy() �ŁA���̃I�u�W�F�N�g��
* 	Revoke() ���\�b�h���Ăяo���Ă��������B
*
* �S�D  �A�v���P�[�V�����N���X�iCWinApp�h���N���X�j�� InitInstance() �ŁA
* 	AfxOleInit() ���Ăяo���Ă��������B
*
* �y���Ӂz
* �P�D  OLE�h���b�O���h���b�v���T�|�[�g���郁�C���t���[���E�C���h�E�ł́A
* 	DragAcceptFiles() �ďo���s��Ȃ��ł��������B�܂��AWS_EX_ACCEPTFILES
* 	�������w�肵�Ȃ��ł��������B
*/
class CDropTargetDoctmpl : public COleDropTarget
{
// ********************************
//	�]���^
// ********************************
 public:
	typedef COleDropTarget	super ;

//--------------------------------
//	�f�[�^�����o
//--------------------------------
 private:
	/**
	* 	���̃h���b�v�^�[�Q�b�g���T�|�[�g����g���q��ێ����܂�
	* 	������́A".txt" �̌`���ł�
	*/
	CStringArray	m_astrExt ;
	
	/**
	*	̧�قP�����̃h���b�v���󂯕t���܂��iSDI�Ŏg���܂��j
	*	�R���X�g���N�^�Ō��܂�܂��B
	*/
	BOOL					m_bAcceptSingle ;
	
//--------------------------------
//	�����֐�
//--------------------------------
 public:
	/**
	* 	���̃h���b�v�^�[�Q�b�g�ɓ�������HDROP�n���h������A
	* 	�܂܂�Ă���t�@�C���������o���āACStringArray�ɏ������݂܂��B
	* @param hgmemEHdrop [in]
	* 	�h���b�v�^�[�Q�b�g�ɓ�������HDROP�n���h�����w�肵�Ă��������B
	* @param pastrFilename [out]
	* 	���̊֐��́A���̕�����z��ɁA�h���b�v���ꂽ̧�ق̈ꗗ��
	* 	�i�[���܂��B
	* 	�K�v�Ȃ��Ȃ�NULL�ł��܂��܂���B
	* @return
	* 	̧�ق̐���Ԃ��܂�
	*/
	static int HdropToFilenames( HDROP pdropgmemEHdrop 
								, CStringArray* pastrFilename ) ;

	/**
	* 	�t�@�C�������i�[����CStringArray�̊e�v�f�̂����A
	*	�g���q�̕s�K�؂Ȃ��̂��������܂��B
	* @param astrEExt [in]
	* 	�g���q�Q���i�[����������z����w�肵�Ă��������B
	*	�g���q�́A ".exe"
	* @param pastrFilename [in,out]
	* 	���̊֐��́A���̕�����z��Ɋi�[����Ă���t�@�C��������A
	* 	�g���q�̕s�K�؂ȗv�f���폜���܂�
	* 	NULL���w�肷�邱�Ƃ͂ł��܂���
	*  @return
	* 	�폜����̧�ق̐���Ԃ��܂�
	*/
	static int FilenamesNoExtRemove
			( const CStringArray& astrEExt , CStringArray* pastrFilename ) ;

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	* @param bEAcceptSingle [in]
	*	̧�قP�����̃h���b�v���󂯕t���܂��iSDI�Ŏg���܂��j
	*/
	CDropTargetDoctmpl( BOOL bEAcceptSingle ) ;
	virtual ~CDropTargetDoctmpl() ;
	
// ********************************
//	COleDropTarget
// ********************************
 public:
	/**
	* �y�I�[�o���C�h�z
	* 	CWinApp�ɑ΂��āA���̃A�v���P�[�V�������T�|�[�g���Ă���g���q��
	* 	�₢���킹�āA���̌��ʂ� m_astrExt �ɕۑ����܂��B
	* 	�h���b�O����Ă���̂��A�A�v���P�[�V�����ŃT�|�[�g���Ă���g���q
	* 	�ł������ꍇ�́A���̃h���b�v�^�[�Q�b�g�ւ̃R�s�[���󂯕t���܂�
	*/
	virtual DROPEFFECT OnDragEnter( CWnd* pWnd, COleDataObject* pDataObject
										, DWORD dwKeyState, CPoint point );

	/**
	* �y�I�[�o���C�h�z
	* 	�h���b�O����Ă���̂��A�A�v���P�[�V�����ŃT�|�[�g���Ă���g���q
	* 	�ł������ꍇ�́A���̃h���b�v�^�[�Q�b�g�ւ̃R�s�[���󂯕t���܂�
	*/
	virtual DROPEFFECT OnDragOver( CWnd* pWnd, COleDataObject* pDataObject
										, DWORD dwKeyState, CPoint point );
	
	/**
	* �y�I�[�o���C�h�z
	* 	���ɏ����͂���܂���
	*/
	virtual void OnDragLeave( CWnd* pWnd ) ;
	
	/**
	* �y�I�[�o���C�h�z
	* 	�h���b�O����Ă���̂��A�A�v���P�[�V�����ŃT�|�[�g���Ă���g���q
	* 	�ł������ꍇ�́A���̃t�@�C������z��Ɋi�[���āADropProc() ��
	* 	�Ăяo���܂�
	*/
	virtual BOOL OnDrop( CWnd* pWnd, COleDataObject* pDataObject
									, DROPEFFECT dropEffect, CPoint point );
	
	
// ********************************
//	COleDropTarget
// ********************************
 public:
	/**
	* @param pWnd [in]
	* 	�J�[�\�������݂���E�B���h�E�ւ̃|�C���^
	* @param astrEFilename [in]
	* 	�h���b�v�����f�[�^�������Ă���f�[�^ �I�u�W�F�N�g�ւ̃|�C���^�B
	* @param dropEffect [in]
	* 	���[�U�[���I������h���b�v����̌��ʁB���̒l�� 1 �ȏ��
	* 	�g�ݍ��킹�����̂ł��B 
	* 		- DROPEFFECT_COPY   �R�s�[���삪�s���܂��B
	* 		- DROPEFFECT_MOVE   �ړ����삪�s���܂��B
	* 		- DROPEFFECT_LINK   �h���b�v���ꂽ�f�[�^�ƌ��̃f�[�^��
	* 			�����N����܂��B
	* 		- DROPEFFECT_SCROLL   �h���b�O �X�N���[�����삪�^�[�Q�b�g����
	* 			��������Ƃ��납�A�������Ă��܂��B 
	* @param point [in]
	* 	��ʏ�ɂ�����J�[�\���̈ʒu���s�N�Z���P�ʂŎw�肵�܂��B
	* @return
	* 	�h���b�v�����������ꍇ�� 0 �ȊO��Ԃ��܂��B
	* 	����ȊO�̏ꍇ�� 0 ��Ԃ��܂��B
	*/
	virtual BOOL OnFiledrop( CWnd* pWnd , const CStringArray& astrEFilename
								, DROPEFFECT dropEffect, CPoint point ) ;

};

} //namespace Hidemdi
} //namespace OuMfc

#endif /*CDropTargetDoctmpl_h*/


