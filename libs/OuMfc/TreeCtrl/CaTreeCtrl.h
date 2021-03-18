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
//	CaTreeCtrl.h
// ****************************************************************
*/
#ifndef  CaTreeCtrl_h
#define  CaTreeCtrl_h

#include <afxcmn.h>
#include <deque>
namespace OuMfc{
namespace TreeCtrl{

// ****************************************************************
//	CaTreeCtrl
// ****************************************************************
/**
@brief
�y�T�v�z
  CTreeCtrl �̃A�_�v�^�N���X�ł��B

  ���̃N���X�́A CTreeCtrl �Ƃ̊֘A�������܂��B�֘A���� CTreeCtrl �ւ́A�ǉ��̑����񋟂��܂��B
�@�ǉ��̑���Ƃ��ẮA�ȉ��̂��̂�����܂��B

 - HTREEITEM �ƁA�w�A�C�e�����P�[�V�����x�Ƃ̊Ԃ̕ϊ�
 - ���� HTREEITEM �̎q�A�C�e�����

  <H4>
�y�g�����z
  </H4>

�@�P�D  ���̃N���X�̃I�u�W�F�N�g�𐶐�����O�ɁACTreeCtrl �I�u�W�F�N�g����������Ă��Ȃ��Ă͂Ȃ�܂���B�Ȃ����A���� CTreeCtrl �́A HWND ����������Ă��Ȃ��Ă͂Ȃ�܂���

�@�Q�D  ���̃N���X�̃I�u�W�F�N�g�𐶐����Ă��������B�R���X�g���N�^�ł́A���삷�� CTreeCtrl �I�u�W�F�N�g���w�肵�Ă��������B

�@�R�D�@���̂��Ƃ́A���ׂẴ��\�b�h�����p�ł��܂��B

  <H4>
�y�A�C�e�����P�[�V�����z
  </H4>

�@�w�A�C�e�����P�[�V�����x�́A�c���[�R���g���[���̃A�C�e���̈ʒu�������l�ł��B���̒l�́A std::deque<int> �^��
 �\���܂��B���̃N���X�ɂ́A�A�C�e�����P�[�V�����̌^��\��typedef �Ƃ��āA Itemlocation ���`���Ă��܂��B

  �K�w���ł̃A�C�e���̈ʒu�́A��ԏ�̃A�C�e���� 0 �Ƃ����C���f�N�X�Ŏw�肵�܂��B
  �P�Ԗڂ̊K�w���ł̃C���f�N�X���R���e�i�̃C���f�N�X 0 �̗v�f�E
�Q�Ԗځi�q�A�C�e���j�� �C���f�N�X�� 1 �E
����Ȃ�q�A�C�e���̃C���f�N�X�� 2 �E 3 �E�E�E�Ɋi�[����܂��B
�w�A�C�e�����P�[�V�����x�̃R���e�i�̗v�f���́A���̃A�C�e���̊K�w�̐[����\���܂��B
  
  �i��j
	@code
	+-- ���̃A�C�e���́w�A�C�e�����P�[�V�����x [0]=0
	+-- ���̃A�C�e���́w�A�C�e�����P�[�V�����x [0]=1
	  +-- ���̃A�C�e���́w�A�C�e�����P�[�V�����x [0]=1 [1]=0
	  +-- ���̃A�C�e���́w�A�C�e�����P�[�V�����x [0]=1 [1]=1
		+-- ���̃A�C�e���́w�A�C�e�����P�[�V�����x [0]=1 [1]=1  [2]=0
	@endcode
 
 */
class CaTreeCtrl
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	/**
	 	�w�A�C�e�����P�[�V�����x�̃f�[�^�^�B
	 */
	typedef std::deque<int> Itemlocation ;

private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
	 	this �����삷�� CTreeCtrl �I�u�W�F�N�g�B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis ���j�������܂Ő������Ȃ��Ă͂Ȃ�܂���B
	 	�R���X�g���N�^�Ō��܂�܂��B
	 */
	CTreeCtrl* m_pCTreeCtrl ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	///@{
	/**
	  @param pCTreeCtrl [in]
	 	this �����삷�� CTreeCtrl �I�u�W�F�N�g�B
	 */
	CaTreeCtrl( CTreeCtrl* pCTreeCtrl ) ;
	///@}

public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	  	HTREEITEM �ɑΉ�����w�A�C�e�����P�[�V�����x���쐬���܂��B
	  @param HTREEITEM [in]
	 	�w�A�C�e�����P�[�V�����x���擾���� HTREEITEM ���w�肵�Ă��������B
	  @param pItemlocation [out]
	 	���̊֐��͂��̃R���e�i�ɁA�w�A�C�e�����P�[�V�����x���������݂܂��B
	 	���̃R���e�i������܂ŕێ����Ă����v�f�͔j�����܂��B
	  @return 
	 	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 	-  -1 ;	//	aHTREEITEM ���s���ł��B

	  @b �g�p��
	  @code
		CMup_deque<int>	aItemlocation ;
		CaTreeCtrl	aCaTreeCtrl( &m_CTreeCtrl ) ;
		aCaTreeCtrl.HTREEITEM_to_Itemlocation( aHTREEITEM , &aItermlocation ) ;
	  @endcode
	 */
	int HTREEITEM_to_Itemlocation( HTREEITEM aHTREEITEM , 
		Itemlocation* pItemlocation ) ;
	
	/**
	  	�w�A�C�e�����P�[�V�����x�ɑΉ�����HTREEITEM �𒲂ׂ܂��B
	  @param pItemlocation [in]
	 	�w�A�C�e�����P�[�V�����x���w�肵�Ă��������B
	  @return 
	 	���������� pItemlocation �ɑΉ����� HTREEITEM �A�G���[�Ȃ� NULL �ł��B
	 
	 */
	HTREEITEM HTREEITEM_from_Itemlocation( 
		const Itemlocation* pItemlocation ) ;
	///@}
};


} //namespace TreeCtrl
} //namespace OuMfc




#endif /*CaTreeCtrl_h*/
