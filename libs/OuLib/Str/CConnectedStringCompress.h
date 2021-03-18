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
//	CConnectedStringCompress.h
// ****************************************************************
*/
/** @file */
#ifndef  CConnectedStringCompress_h
#define  CConnectedStringCompress_h

#include <string>
#include "str/CdConnectedString2.h"

namespace OuLib{
namespace Str{

// ****************************************************************
//	CConnectedStringCompress
// ****************************************************************
/**
@brief
�y�T�v�z
  CdConnectedString2 �I�u�W�F�N�g���ێ����Ă�����e���A������ɕϊ����܂��B���̂Ƃ��A�w���ږ��x�́w�T�u�A�C�e���x���������k���܂��B�ϊ���������������߂���@�\�������܂��B

  ���̃N���X�́A CdConnectesString2 �̓��e���A������ɕϊ����܂��B���̓_�́A CdConnectedString::encode() �Ɠ����ł����A�w���ږ��x�́w�T�u�A�C�e���x���d�����Ă���ꍇ�́A�d�����Ă���w�T�u�A�C�e���x�̋L�q���ȗ����邱�Ƃɂ��A������̃T�C�Y�����炵�܂��B
���ɁA�w�T�u�A�C�e���x�̐��������A����q�̃��x�����[���ꍇ�A�T�C�Y�̍팸���ʂ��傫���Ȃ�܂��B

  ���̃N���X���g�p�ł��� CdConnectedString2 �ɂ́A�ȉ��̏���������܂��B


�P�D  ���ׂẮw���ږ��x�́A���ʂ́w�T�u�A�C�e���K�w��؂蕶���x�i�w�T�u�A�C�e���x�̊K�w�̂���؂�A�P�o�C�g�̕����j�������Ȃ��Ă͂Ȃ�܂���B

<H5>
�i��j
</H5>
  �ȉ��́A�w�T�u�A�C�e���K�w��؂蕶���x�� "." �Ƃ����w���ږ��x�̗�ł�
�i�A�C�e���Ԃ̋�؂蕶��=���s�E���ڂƒl�̊Ԃ̋�؂蕶��="="�j�B

@code
Itemname0=Value0
Subitem1.Itemname1=Value1
Subitem1.Subitem2.Itemname2=Value2
Subitem1.Subitem2.Itemname3=Value3
Subitem1.Subitem3.Itemname4=Value4
@endcode

�y���̃N���X���������镶����z

  ������̍쐬�ɂ����ẮA�w�J�����g�T�u�A�C�e���x�̊T�O��������܂��B
  �T�u�A�C�e���ɑ�����A�C�e���𕶎��񉻂���ۂ́A

�P�D  �w�J�����g�T�u�A�C�e���x���A�o�͂���T�u�A�C�e���ɓ��ꂳ���āA

�Q�D  �T�u�A�C�e��������菜�������ږ��ƒl���������ށB

�R�D  �T�u�A�C�e���ɑ����鍀�ږ��E�l�����ׂď������񂾂�A�w�J�����g�T�u�A�C�e���x�́A���̃T�u�A�C�e������ޏꂷ��B

�Ƃ����������Ƃ�܂��B

  �w�J�����g�T�u�A�C�e���x�̓���́A�X�^�b�N�̌`���Ƃ�܂��B���Ƃ��΁A

�P�D  �w�J�����g�T�u�A�C�e���x�� "Subitem1" �ɓ��ꂳ����B

�Q�D  �w�J�����g�T�u�A�C�e���x�� "Subitem2"
 �i "Subitem1" �̉��� "Subitem2" �j�ɓ��ꂳ����B

�R�D  �w�J�����g�T�u�A�C�e���x��ޏꂳ����i"Subitem2" ����̑ޏ�j�B

  ���̂Ƃ��́w�J�����g�T�u�A�C�e���x�́A"Subitem1" �ƂȂ�܂��B


  �w�J�����g�T�u�A�C�e���x���A�T�u�A�C�e���ɓ��ꂳ����ۂ́A������Ƃ��āw�J�����g�T�u�A�C�e������R�}���h�x���o�͂��܂��B
  ����́A�ȉ��̌`���ƂȂ�܂��B

  <B>
  �T�u�A�C�e�����{�w�T�u�A�C�e���K�w��؂蕶���x�{�w�A�C�e���Ԃ̋�؂蕶���x
  </B>

<H5>
�i��j
</H5>
�i�T�u�A�C�e���K�w��؂蕶��="." �E�A�C�e���Ԃ̋�؂蕶��=���s�E���ڂƒl�̊Ԃ̋�؂蕶��="="�j
@code
Subitem1.
@endcode

  �w�J�����g�T�u�A�C�e���x���A�T�u�A�C�e������ޏꂳ����ۂ́A������Ƃ��āw�J�����g�T�u�A�C�e���ޏ�R�}���h�x���o�͂��܂��B
  ����́A�ȉ��̌`���ƂȂ�܂��B

  <B>
  �w�T�u�A�C�e���K�w��؂蕶���x�{�w�A�C�e���Ԃ̋�؂蕶���x
  </B>

<H5>
�i��j
</H5>
�i�T�u�A�C�e���K�w��؂蕶��="." �E�A�C�e���Ԃ̋�؂蕶��=���s�E���ڂƒl�̊Ԃ̋�؂蕶��="="�j
@code
.
@endcode

<H5>
�i��j
</H5>

  �ȉ��̂悤�ȃA�C�e�����o�͂���ꍇ��z�肵�܂��B(151�o�C�g)�i�T�u�A�C�e���K�w��؂蕶��="." �E�A�C�e���Ԃ̋�؂蕶��=���s�E���ڂƒl�̊Ԃ̋�؂蕶��="="�j

@code
Itemname0=Value0
Subitem1.Itemname1=Value1
Subitem1.Subitem2.Itemname2=Value2
Subitem1.Subitem2.Itemname3=Value3
Subitem1.Subitem3.Itemname4=Value4
@endcode

���̂Ƃ��̏o�͓��e�́A�ȉ��̂悤�ɂȂ�܂�( �J�b�R�ň͂܂�Ă��镔���́A�����̃R�����g�ł��B���ۂ̕�����ɂ͊܂܂�܂���)�B

@code
�i�J�����g�T�u�A�C�e����""�j
Itemname0=Value0
Subitem1.
�i�J�����g�T�u�A�C�e����"Subitem1."�j
Itemname1=Value1
Subitem2.
�i�J�����g�T�u�A�C�e����"Subitem1.Subitem2."�j
Itemname2=Value2
Itemname3=Value3
.
�i�J�����g�T�u�A�C�e����"Subitem1."�j
Subitem3.
�i�J�����g�T�u�A�C�e����"Subitem1.Subitem3."�j
Itemname4=Value4
@endcode

�R�����g���������ŏI���ʂ́A�ȉ��̂悤�Ȃ��̂ł��i124�o�C�g�j�B

@code
Itemname0=Value0
Subitem1.
Itemname1=Value1
Subitem2.
Itemname2=Value2
Itemname3=Value3
.
Subitem3.
Itemname4=Value4
@endcode



�y�g�����P- CdConnectedString2 �Ɋi�[����Ă�����e�𕶎��񉻁z

�P�D  �R���X�g���N�^�ł́A

  - �T�u�A�C�e���K�w��؂蕶��(����l=".")

���w�肵�Ă��������B

�Q�D  �����񉻂���A�C�e����ێ����Ă��� CdConnectedString2 �I�u�W�F�N�g��

 - CdConnectedString2::m_chSplit �ɃA�C�e���Ԃ̋�؂蕶���E
 - CdConnectedString2::m_chEqualChar �Ɂw���ڂƒl�̊Ԃ̋�؂蕶���x
 - CdConnectedString2::m_bEncodeNoValue

���w�肵�Ă��������B

�R�D  encode() ���Ăяo�����Ƃɂ��A��������쐬���邱�Ƃ��ł��܂��B


�y�g�����Q- encode() �ō쐬��������������߁z

�P�D  �R���X�g���N�^�ł́A

  - �T�u�A�C�e���K�w��؂蕶��(����l=".")

���w�肵�Ă��������B

�Q�D  ����������߂������e���i�[���� CdConnectedString2 �I�u�W�F�N�g��

 - CdConnectedString2::m_chSplit �ɃA�C�e���Ԃ̋�؂蕶���E
 - CdConnectedString2::m_chEqualChar �Ɂw���ڂƒl�̊Ԃ̋�؂蕶���x

���w�肵�Ă��������B

�R�D  decode() ���Ăяo���Ă��������B���̊֐��́A����������߂��āA CdConnectedString2 �Ɋi�[���܂��B
*/
class CConnectedStringCompress
{
// ********************************
///@name ����
// ********************************
 private:
	/**
	 *	�T�u�A�C�e���K�w��؂蕶��(����l=".")
	 */
	char		m_chSubitemSeparater ;
	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param chSubitemSeparater [in]
	 *	�T�u�A�C�e���K�w��؂蕶��(����l=".") 
	 */
	CConnectedStringCompress( 
		char chSubitemSeparater = '.' );
	virtual ~CConnectedStringCompress();
	
	
// ********************************
//	CConnectedStringCompress
// ********************************
 public:
	// ********************************
	///@name CConnectedStringCompress-����
	// ********************************
	virtual char getSubitemSeparater()const ;
	virtual CConnectedStringCompress& setSubitemSeparater( char value ) ;
	// ********************************
	///@name CConnectedStringCompress-����
	// ********************************
	/**
	 *	CdConnectedString2 �Ɋi�[����Ă�����e�𕶎��񉻂��܂��B
	 *
	 *	�����񉻂���O�� aCdConnectedString2 ��
	 *
	 *	- CdConnectedString2::m_chSplit
	 *	- CdConnectedString2::m_chEqualChar
	 *	- CdConnectedString2::m_bEncodeNoValue
	 *
	 *	��ݒ肵�Ă��Ȃ��Ă͂Ȃ�܂���B
	 * @param aCdConnectedString2 [in]
	 *	�����񉻂���A�C�e����ێ����Ă���I�u�W�F�N�g���w�肵�Ă��������B
	 * @return
	 *	�����񉻂������e��Ԃ��܂��B
	 */
	virtual std::string encode( const CdConnectedString2& aCdConnectedString2 ) ;

	/**
	 *	encode() �ō쐬��������������߂��A���̓��e��
	 *	 CdConnectedString2 �Ɋi�[���܂��B
	 *
	 *	�֐����s�O�ɁA pCdConnectedString2 ��
	 *
	 *	- CdConnectedString2::m_chSplit
	 *	- CdConnectedString2::m_chEqualChar
	 *
	 *	��ݒ肵�Ă��Ȃ��Ă͂Ȃ�܂���B
	 * @param aStr [in]
	 *	���߂��镶������w�肵�Ă��������B
	 * @param pCdConnectedString2 [out]
	 *	���̊֐��͂��̃I�u�W�F�N�g�ɁA���߂������e��ǉ����܂��B
	 *	���̃I�u�W�F�N�g������܂ŕێ����Ă����f�[�^�͈ێ����܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B
	 */
	virtual int decode( const std::string& aStr , 
		CdConnectedString2* pCdConnectedString2 ) ;
};

} //namespace Str{
} //namespace OuLib{

#endif /*CConnectedStringCompress_h*/



