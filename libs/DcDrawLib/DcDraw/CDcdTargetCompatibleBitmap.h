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
//	CDcdTargetCompatibleBitmap.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdTargetCompatibleBitmap_h
#define  CDcdTargetCompatibleBitmap_h
#include <windows.h>
#include "IfDcdTarget.h"
#include "./CGdiCache.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdTargetCompatibleBitmap
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 *	�`����DC�ƌ݊����̂���r�b�g�}�b�v��`��̈�Ƃ����N���X�ł��B
 *
 * �y�g�����z
 *
 * �P�D  �R���X�g���N�^�ŃI�u�W�F�N�g���쐬��AresetSize()�Ńr�b�g�}�b�v��
 *	�傫�����w�肵�Ă��������Bthis�͂��̑傫���̃r�b�g�}�b�v���쐬���܂��B
 *	  �܂��A�����ɕ`���Ɍ݊����̂��郁����DC���쐬���A�r�b�g�}�b�v��
 *	�I�������܂��B
 *
 * �Q�D  getHdc()�ł́A���̃r�b�g�}�b�v��I��������Ԃ�DC���擾���邱�Ƃ�
 *	�ł��܂��B���̂��߁AgetHdc()�Ŏ擾���ꂽDC�ɕ`�悷�邱�Ƃɂ��A
 *	�r�b�g�}�b�v�ւ̕`�悪�ł��܂��B
 *
 * �R�D  �r�b�g�}�b�v�̓��e���E�C���h�E�ɕ`�悷�邽�߂ɂ́A getHdc() �Ŏ擾����
 *	������DC�ƁA�E�C���h�E��DC ���g���āABitBlt()���s���Ă��������B
 */
class CDcdTargetCompatibleBitmap : public IfDcdTarget
{
// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	 *	���݂̃r�b�g�}�b�v�̃T�C�Y�ł��B
	 *	�R���X�g���N�^�Ō��܂�܂����A�ύX���ł��܂��B
	 *	�f�t�H���g�́A(0,0)�ƂȂ�܂��B
	 */
	CdDcdSizeXy	m_CdDcdSizeXy ;

	
	/**
	 *	GDI�I�u�W�F�N�g�̑����ƁA�n���h���̑Ώƕ\��ێ����܂��B
	 */
	CGdiCache	m_CGdiCache ;
///@}
// --------------------------------
///@name	�����f�[�^
// --------------------------------
///@{
 private:
	/**
	 *	�r�b�g�}�b�v�ւ̏o�͂�����DC�ł��B
	 *	����DC�́A�r�b�g�}�b�v�̏o�͐�f�o�C�X��\��DC��
	 *	�݊����̂���DC�ƂȂ�܂��B
	 *	�����Ȃ��R���X�g���N�^���AresetSize() �Ō��܂�܂��B
	 *	�������AresetSize()��X,Y�̂����ꂩ��0�Ɏw�肳�ꂽ
	 *	�ꍇ�́ANULL�ƂȂ�܂��B
	 */
	HDC		m_hDc ;

	/**
	 *	�r�b�g�}�b�v�ւ̏o�͂�����DC�ł��B
	 *	����DC�́A�r�b�g�}�b�v�̏o�͐�f�o�C�X��\��DC��
	 *	�݊����̂���DC�ƂȂ�܂��B
	 *	�����Ȃ��R���X�g���N�^���AresetSize() �Ō��܂�܂��B
	 *	�������AresetSize()��X,Y�̂����ꂩ��0�Ɏw�肳�ꂽ
	 *	�ꍇ�́ANULL�ƂȂ�܂��B
	 */
	HBITMAP		m_hBitmap ;

	/**
	 *	m_hDc ��m_hBitmap��I�����Ă���Ԃ́A
	 *	m_hDc ������܂őI�����Ă����r�b�g�}�b�v��ێ����܂��B
	 *	�����łȂ��ꍇ��NULL�ƂȂ�܂��B
	 */
	HBITMAP		m_hBitmapSid ;
///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param aCdDcdSizeXy [in]
	 *	�r�b�g�}�b�v�̃T�C�Y���w�肵�Ă��������B
	 * @param hDC [in]
	 *	�r�b�g�}�b�v�̏o�͐��DC���w�肵�Ă��������B@n
	 *	NULL�Ȃ�A�X�N���[���ƌ݊����̂���DC���w�肵�����ƂɂȂ�܂��B
	 *	�E�C���h�E��BitBlt()���邽�߂̃r�b�g�}�b�v��
	 *	�쐬����̂ł���΁A���̒l��NULL�ł����܂��܂���B
	 */
	CDcdTargetCompatibleBitmap( const CdDcdSizeXy& aCdDcdSizeXy 
								, HDC hDC = NULL ) ;
	CDcdTargetCompatibleBitmap() ;
	
	virtual ~CDcdTargetCompatibleBitmap() ;
	
	
 public:
	// ********************************
	///@name	IfDcdTarget
	// ********************************
	///@{
	/**
	 * @return
	 * 	�`����s��DC���擾���܂��B
	 * 	����HDC�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *
	 * [�I�[�o���C�h]
	 *	m_hDc ��Ԃ��܂��B
	 */
	virtual HDC	getHdc() ;
	
	/**
	 * @return
	 * 	�`��̕K�v�ȗ̈�̍��W�͈͂��擾���邱�Ƃ��ł��܂��B
	 * 	�P�ʂ́A�_���P�ʂł��B
	 *
	 * [�I�[�o���C�h]
	 *	���_��0,0�A�T�C�Y�̓r�b�g�}�b�v�̗̈��Ԃ��܂��B
	 */
	virtual CdDcdZoneXy getZone() ;
	
	/**
	 * @return
	 * 	�`�悪�L���Ȕ͈͂��擾�ł��܂��B
	 * 	�ʏ�́AgetZone()�Ɠ����̈�ƂȂ�܂��B
	 * 
	 * 	�E�C���h�E��WM_PAINT�ɂ��`��̏ꍇ�A���̊֐����Ԃ��̂́A
	 * 	�ĕ`�悪�K�v�ȗ̈�ƂȂ�܂��B
	 * 	���̗̈�𖳎����Ă����܂��܂���B�������A���͈̔͊O�ւ̕`���
	 * 	�Ӗ�������܂���̂ŁA���͈̔͊O�ւ̕`���}������悤�ɂ���΁A
	 * 	�`�揈���̌����̉��P�����҂ł��܂��B
	 *
	 * [�I�[�o���C�h]
	 *	���_��0,0�A�T�C�Y�̓r�b�g�}�b�v�̗̈��Ԃ��܂��B
	 */
	virtual CdDcdZoneXy getDrawableZone() ;

	/**
	 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 @param aCdFontProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @return
		�t�H���g�̃n���h����ێ����� CGdiHFontHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHFontHolder>	createGdiHFontHolder(  const CdFontProp& aCdFontProp ) ;
	
	/**
	 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 @param aCdPenProp [in]
	 	�y���������w�肵�Ă��������B
	 @return
		�y���̃n���h����ێ����� CGdiHPenHolder ��Ԃ��܂��B
	*/
	virtual  Ou<CGdiHPenHolder>		createGdiHPenHolder(  const CdPenProp& aCdPenProp ) ;

	/**
	 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�u���V�𐶐����܂�
	 @param aCdBrushProp [in]
	 	�u���V�������w�肵�Ă��������B
	 @return
		�u���V�̃n���h����ێ����� CGdiHBrushHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHBrushHolder>	createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) ;


	///@}
// ********************************
///@name	CDcdTargetCompatibleBitmap
// ********************************
///@{
 public:
	/**
	 * @return 
	 *	���݂̃r�b�g�}�b�v�̃T�C�Y��Ԃ��܂��B
	 */
	virtual CdDcdSizeXy getSize() ;
	
	/**
	 *	�r�b�g�}�b�v�̃T�C�Y��ݒ肵�܂��B
	 *	�����̃r�b�g�}�b�v�̓��e��j�����܂��B
	 * @param aCdDcdSizeXy [in]
	 *	�V�����r�b�g�}�b�v�̃T�C�Y���w�肵�Ă��������B
	 * @param hDC [in]
	 *	�r�b�g�}�b�v�̏o�͐��DC���w�肵�Ă��������B@n
	 *	NULL�Ȃ�A�X�N���[���ƌ݊����̂���DC���w�肵�����ƂɂȂ�܂��B
	 *	�E�C���h�E��BitBlt()���邽�߂̃r�b�g�}�b�v��
	 *	�쐬����̂ł���΁A���̒l��NULL�ł����܂��܂���B
	 * @return
	 *	����������0�ȏ㤎��s�����畉�̐��ł��B
	 *	-	-1 ;	//	DC�̍쐬�Ɏ��s���܂���
	 *	-	-2 ;	//	BITMAP�̍쐬�Ɏ��s���܂���
	 */
	virtual int resetSize( const CdDcdSizeXy& aCdDcdSizeXy , HDC hDc = NULL ) ;
///@}
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*CDcdTargetCompatibleBitmap_h*/

