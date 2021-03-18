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
//$Id: DcDraw.h 110 2012-09-30 01:24:19Z okm $
#ifndef  DcDraw_DcDraw_h
#define  DcDraw_DcDraw_h
/**
 @file 
 @brief
	���O��Ԃ̊֐��Q�E�N���X�Q�̂��ׂĂ��C���N���[�h���܂��B
*/

namespace DcDrawLib{


/**
@brief
  DcDraw �ŁA�}�`�E�������^�[�Q�b�g�̈�ɕ`�悷��N���X�Q���܂��܂��B

*/
namespace DcDraw{
} //namespace DcDraw

} //namespace DcDrawLib

#include "DcDraw\CaContentPosToDcdTarget_Dim.h"
#include "DcDraw\CaDcdTargetClip.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CconvContentPosToDcdTarget.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcDeviceUnitSizeX.h"
#include "DcDraw\CDcDeviceUnitSizeY.h"
#include "DcDraw\CDcdFillrect.h"
#include "DcDraw\CDcdFillRectangleText.h"
#include "DcDraw\CDcdFillRectangleTextV.h"
#include "DcDraw\CDcdFillRectangleTextV2.h"
#include "DcDraw\CDcdFillrectRop.h"
#include "DcDraw\CDcdFreeLine.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CDcdRectangle.h"
#include "DcDraw\CDcdTarget.h"
#include "DcDraw\CDcdTargetCompatibleBitmap.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CDcdTargetOnPaint.h"
#include "DcDraw\CDcdTargetPrinter.h"
#include "DcDraw\CDcdText.h"
#include "DcDraw\CdDeviceUnitSize.h"
//#include "DcDraw\CdWinGdi_DrawText_Format.h"
#include "DcDraw\CGdiCache.h"
#include "DcDraw\CGdiHBrushHolder.h"
#include "DcDraw\CGdiHFontHolder.h"
#include "DcDraw\CGdiHPenHolder.h"
#include "DcDraw\IfDcDraw.h"
#include "DcDraw\IfDcdTarget.h"

//#include "DcDraw\print\print.h"

#endif //DcDraw_DcDraw_h
