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
//	IfDcDraw.h
// ****************************************************************
*/
/** @file */
#ifndef  IfDcDraw_h
#define  IfDcDraw_h

#include "./IfDcdTarget.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	IfDcDraw
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	  DcDraw���f���ɂ�����A�`�揈�����s���N���X���T�|�[�g����C���^�[�t�F�[�X
 * 	�ł��B
 *
 *	  ���̃N���X���`����s���ΏہiDC�j�́AIfDcdTarget �C���^�[�t�F�[�X��
 *	�T�|�[�g����I�u�W�F�N�g�ŕ\���܂��B
 *
 * 	  ���Ƃ��΁A�E�C���h�E��WM_PAINT���b�Z�[�W������������A�E�C���h�E�́A
 * 	�`����DC��\�� CdDcdTargetOnPaint �𐶐����A���� IfDcdTarget 
 *	�C���^�[�t�F�[�X���w�肵�� IfDcDraw::DcDraw() ���\�b�h���Ăяo���܂��B
 * 	  DcDraw() ���\�b�h���Ăяo�����ƁA IfDcDraw �I�u�W�F�N�g�́A�n���ꂽ
 *	IfDcdTarget �I�u�W�F�N�g���ێ�����DC�ɁA�`����s���܂��B
 */
class IfDcDraw
{
 public:
	/**
	 * 	�`���v�����܂��B
	 * 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	 * @param pIfDcdTarget  [in]
	 * 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 * @return
	 * 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	 */
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) = 0 ;
	
	/**
	 * 	���̃I�u�W�F�N�g���`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 * 	���̑傫���𒲂ׂ邱�Ƃ��ł��܂��B
	 * 	�֐��Ăяo������������ IfDcDraw �I�u�W�F�N�g��`�悷��ꍇ�ɂ́A
	 * 	�֐��Ăяo�����́A���̊֐��ŃA�C�e���̑傫���𒲂ׂāA
	 * 	�K�؂ȃ��C�A�E�g���l���Ă���ADcDraw() �����s���邱�Ƃ��ł��܂��B
	 * @param pIfDcdTarget [in]
	 * 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 * @param pCdDcdSizeXy [out]
	 * 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 * 	���̊֐��͂��̃A�h���X�ɁA���̃A�C�e���̃T�C�Y��Ԃ��܂��B
	 * 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��Ȃ��ꍇ�́A
	 * 	���̒l�͕s��ł��B
	 * @return
	 * 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��āA
	 * 	���̑傫���� *pCdDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	 * 	�����łȂ��ꍇ�́A�U�ł��B
	 */
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) = 0 ;
	
	virtual ~IfDcDraw(){};
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*IfDcDraw_h*/
