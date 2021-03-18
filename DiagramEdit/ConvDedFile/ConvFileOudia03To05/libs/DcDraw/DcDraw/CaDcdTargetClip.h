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
//	CaDcdTargetClip.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdTargetClip_h
#define  CaDcdTargetClip_h

#include "IfDcdTarget.h"

// ****************************************************************
//	CaDcdTargetClip
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 *	�A�_�v�^�N���X�ł��B
 *	DcDraw���f���ɂ����āA���� IfDcdTarget �̒��̓���̗̈��
 *	�N���b�v���܂��B����DC�ɑ΂��ẮA�N���b�v�̈�ȊO�ւ̕`���
 *	�����ɂȂ�܂��B
 *
 *	�ΏۂƂȂ� IfDcdTarget �ɂ��łɃN���b�v�̈悪�������ꍇ�́A
 *	���̃N���b�v�̈�ɑ΂��Ă���ɃN���b�v���s���܂��B
 *	���̏ꍇ�A�`��\�ȗ̈�́A�]����苷���Ȃ�܂��B
 *
 * 
 * �y�g�����z
 * 
 * �P�D  �R���X�g���N�^�ł́A�N���b�v���s�� IfDcdTarget �I�u�W�F�N�g�ƁA
 *	�N���b�v�̈���w�肵�Ă��������B
 * 
 * �Q�D  <B>validate() �ŗL�������Ă��������B</B>
 *	validate() �Ɏ��s������A���̃I�u�W�F�N�g�͓���s�\�ł��B
 *
 * �R�D  validate()������������AgetHdc() �Ŏ擾���� DC �ɂ́A�N���b�s���O��
 *	�ݒ肳��Ă��܂��B
 *
 */
class CaDcdTargetClip : public IfDcdTarget
{
// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	 * 	�N���b�s���O�̈�̍��W�͈�
	 * 	�P�ʂ́A�_���P�ʂł��B
	 */
	CdDcdZoneXy	m_zonexyZoneClip ;
///@}
	
// ********************************
///@name	�֘A
// ********************************
///@{
 private:
	/**
	*	�N���b�v���s�� IfDcdTarget �ł��B
	*	���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	*/
	IfDcdTarget*	m_pIfDcdTarget ;
///@}

// --------------------------------
///@name	�����f�[�^
// --------------------------------
///@{
 private:
	/**
	 * 	DC ������܂ň����Ă����N���b�v���[�W�����B
	 *	����܂ł̂c�b�ɃN���b�v���[�W�������Ȃ��Ȃ�ANULL�ł��B
	 */
	HRGN	m_hRgnSid  ;

	/**
	 * 	DC �����ݑI�����Ă���N���b�v���[�W�����B
	 *	����܂ł̂c�b�ɃN���b�v���[�W�������Ȃ��Ȃ�ANULL�ł��B
	 */
	HRGN	m_hRgnNew ;
///@}
	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param pIfDcdTarget [in]
	 *	�N���b�v�̉�ʑS�́i���邢�́A this ���L���͈́j��\�� DcDrawTarget 
	 *	�I�u�W�F�N�g�ł��B
	 *	���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 * @param zonexyZoneClip [in]
	 * 	�`��̕K�v�ȗ̈�̍��W�͈�
	 * 	�P�ʂ́A�_���P�ʂł��B
	 */
	CaDcdTargetClip( 
			IfDcdTarget* pIfDcdTarget ,
			const CdDcdZoneXy& zonexyZoneClip ) ;
	virtual ~CaDcdTargetClip(); 

// ********************************
///@name	IfDcdTarget
// ********************************
///@{
 public:
	/**
	 * @return
	 * 	�`����s��DC���擾���܂��B
	 * 	����HDC�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 */
	virtual HDC	getHdc() ;
	
	/**
	 * @return
	 * 	�`��̕K�v�ȗ̈�̍��W�͈͂��擾���邱�Ƃ��ł��܂��B
	 * 	�P�ʂ́A�_���P�ʂł��B
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
	 */
	virtual CdDcdZoneXy getDrawableZone() ;

	/**
	 * 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 * @param aCdFontProp [in]
	 * 	�t�H���g�������w�肵�Ă��������B
	 * @return
	 *	�t�H���g�̃n���h����Ԃ��܂��B
	 *	���̃n���h���̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *	�֐��ďo���́A�n���h����������Ă͂����܂���B
	 */
	virtual HFONT	CreateFont(  const CdFontProp& aCdFontProp ) {
		return m_pIfDcdTarget->CreateFont( aCdFontProp )  ;} ;
	
	/**
	 * 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 * @param aCdPenProp [in]
	 * 	�y���������w�肵�Ă��������B
	 * @return
	 *	�y���̃n���h����Ԃ��܂��B
	 *	���̃n���h���̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *	�֐��ďo���́A�n���h����������Ă͂����܂���B
	 */
	virtual HPEN	CreatePen(  const CdPenProp& aCdPenProp ) {
		return m_pIfDcdTarget->CreatePen( aCdPenProp )  ;} ;

	/**
	 * 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 * @param aCdBrushProp [in]
	 * 	�y���������w�肵�Ă��������B
	 * @return
	 *	�y���̃n���h����Ԃ��܂��B
	 *	���̃n���h���̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *	�֐��ďo���́A�n���h����������Ă͂����܂���B
	 */
	virtual HBRUSH	CreateBrush(  const CdBrushProp& aCdBrushProp ) {
		return m_pIfDcdTarget->CreateBrush( aCdBrushProp )  ;} ;
		
///@}

// ********************************
///@name	IfValidate
// ********************************
///@{
 public:
	/**
	 * 	  �I�u�W�F�N�g�̏����������s���A�L�������܂��B
	 * 	  ���������ɂ������ĕK�v�ȃp�����[�^�́A�R���X�g���N�^�Ȃǂ�
	 * 	�w�肵�Ă���
	 * 	�K�v������܂��B
	 * @return
	 * 	  �L�����ɐ���������P�ȏ�A
	 * 	  ���łɗL�������I�����Ă����ꍇ�͂O�A
	 * 	  �G���[�̏ꍇ�͕��̐���Ԃ��܂��B\n
	 * 	  ���������Ƃ��̂P�ȏ�̒l�̈Ӗ��́A��������N���X�����R�ɒ�`
	 * 	�ł��܂��B\n
	 * 	  ���s�����Ƃ��̕��̐��̈Ӗ����A�����N���X����`�ł��܂��B����ɂ��A
	 * 	���s�̗��R���ƂɈقȂ�G���[�l��Ԃ����Ƃ��ł��܂��B
	 * 	
	 */
	virtual int validate() ;
	
	/**
	 * 	  �I�u�W�F�N�g�𖳌������܂��B
	 * 	  �L�������Ɋm�ۂ������\�[�X���J�����܂��B
	 * 	  �L����ԂłȂ��I�u�W�F�N�g�ɑ΂��ẮA�Ȃɂ����܂���B
	 */
	virtual void invalidate() ;
	
	/**
	 * @return
	 * 	  ���݃I�u�W�F�N�g���L����Ԃł���ΐ^��Ԃ��܂��B
	 */
	virtual bool isValid() ;
///@}

// ********************************
///@name	CaDcdTargetClip
// ********************************
///@{
 public:
	/**
	 * @return
	 *	m_zonexyZone �Ŏ������A���̕��i�̕`��ʒu���A
	 *	getDrawableZone() �ƑS���ڂ��Ă��Ȃ��ꍇ�ɐ^�ł��B
	 *	���̒l���^�ł���΁A���̕`��̈�ւ̕`���
	 *	�S���Ӗ�������܂���B
	 */
	virtual bool isDrawable() ;
///@}
};



#endif /*CaDcdTargetClip_h*/


