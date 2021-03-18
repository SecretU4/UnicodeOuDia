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
//	CconvCdPrintPageProp.h
// ****************************************************************
*/
/** @file */

#ifndef  CconvCdPrintPageProp_h
#define  CconvCdPrintPageProp_h

#include "DcdCd\Pos\CdDcdZoneXy.h"

#include "CdPrintPageProp.h"
#include <windows.h>

namespace Print{
	using namespace DcDrawLib::DcdCd::Pos;
	using namespace DcDrawLib::DcDraw;

// ****************************************************************
//	CconvCdPrintPageProp
// ****************************************************************
/**
 *	@brief
 *	CdPrintPageProp �I�u�W�F�N�g�̑������A���̌`���ɕϊ����铮���񋟂��܂��B
 */
class CconvCdPrintPageProp
{
 public:
	/**
	 *	CdPrintPageProp �̌��݂̗]��
	 *	(m_dMarginLeftMm ,  m_dMarginTopMm , 
	 *	m_dMarginRightMm , m_dMarginBottomMm )�̑��������ƂɁA
	 *	�v�����^�̕������W����]�������������W�̈�����߂܂��B
	 *
	 * @param aCdPrintPageProp [in]
	 *	�]���̐ݒ��ێ����Ă��� CdPrintPageProp �I�u�W�F�N�g��
	 *	�w�肵�Ă��������B
	 * @param hDc [in]
	 *	�v�����^��DC���w�肵�Ă��������B
	 * @return 
	 *	�v�����^�̃f�o�C�X���W����A�]�������������W�̈�
	 *	��Ԃ��܂��B
	 *
	 *	X�����̗]�����傫������ꍇ	(m_dMarginLeftMm +m_dMarginRightMm ��
	 *	�v�����^�̉������̗p���̑傫��������ꍇ�j�́A
	 *	�߂�l�� CdDcdZone::getX().getSize() �̒l�����̐��ɂȂ�܂��B
	 *	���̏ꍇ�́A���炩�̃G���[���������ׂ��ł��B
	 *
	 *	���l�ɁAY�����̗]�����傫������ꍇ�́A
	 *	�߂�l�� CdDcdZone::getY().getSize() �̒l�����̐��ɂȂ�܂��B
	 *
	 *	�������̗]�����A�v�����^�̍����̈󎚕s�\�̈�̕���菬�����ꍇ�́A
	 *	���ۂ̗]���͈󎚕s�\�̈�̕��ƂȂ�܂��B���̓���́A�E�E��E��
	 *	�̗]���ɂ����Ă͂܂�܂��B
	 */
	CdDcdZoneXy calcZoneInnerMargin( 
		const CdPrintPageProp& aCdPrintPageProp , HDC hDc ) ;
	
	
	/**
	 *	�v�����^DC �ł́A
	 *	X�����̊e�T�C�Y���A�f�o�C�X�P�ʂŎ擾���܂��B
	 *	Win32 �� GetDeviceCaps() �̃��b�p�[�ł���Ƃ����܂��B
	 * @param hDc [in]
	 *	�v�����^��DC���w�肵�Ă��������B
	 * @param piPhysicalPageSize [out]
	 *	���̊֐��́A
	 *	���[�̈󎚕s�\�̈���܂߂��A
	 *	�����I�ȃy�[�W�i�v�����^�̗p���j�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 * @param piPhysicalOffset1 [out]
	 *	���̊֐��́A
	 *	���W�̏��������i�����j�̈󎚕s�\�̈�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 * @param piRes [out]
	 *	���̊֐��́A
	 *	�󎚉\�̈�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 * @param piPhysicalOffset2 [out]
	 *	���̊֐��́A
	 *	���W�̑傫�����i�E���j�̈󎚕s�\�̈�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 */
	static void getPhysicalXPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) ;

	/**
	 *	�v�����^DC �ł́A
	 *	Y�����̊e�T�C�Y���A�f�o�C�X�P�ʂŎ擾���܂��B
	 *	Win32 �� GetDeviceCaps() �̃��b�p�[�ł���Ƃ����܂��B
	 * @param hDc [in]
	 *	�v�����^��DC���w�肵�Ă��������B
	 * @param piPhysicalPageSize [out]
	 *	���̊֐��́A
	 *	���[�̈󎚕s�\�̈���܂߂��A
	 *	�����I�ȃy�[�W�i�v�����^�̗p���j�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 * @param piPhysicalOffset1 [out]
	 *	���̊֐��́A
	 *	���W�̏��������i�㑤�j�̈󎚕s�\�̈�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 * @param piRes [out]
	 *	���̊֐��́A
	 *	�󎚉\�̈�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 * @param piPhysicalOffset2 [out]
	 *	���̊֐��́A
	 *	���W�̑傫�����i�����j�̈󎚕s�\�̈�̑傫��
	 *	���A���̃A�h���X�ɏ������݂܂��B�s�v�ł���� NULL ���w�肵�Ă�
	 *	���܂��܂���B
	 */
	static void getPhysicalYPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) ;
};

} //namespace Print

#endif /*CconvCdPrintPageProp_h*/
