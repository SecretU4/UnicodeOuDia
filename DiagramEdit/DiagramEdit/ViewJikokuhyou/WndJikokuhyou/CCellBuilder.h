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
//	ViewJikokuhyou\WndJikokuhyou\CCellBuilder.h
//	$Id: CCellBuilder.h 179 2014-05-05 13:50:33Z okm $
// ****************************************************************
*/

/** @file */
#ifndef  ViewJikokuhyou_WndJikokuhyou_CCellBuilder_h
#define  ViewJikokuhyou_WndJikokuhyou_CCellBuilder_h

#include "DedRosenFileData\CDedRosenFileData.h"
#include "ViewJikokuhyou\WndJikokuhyou\CWndJikokuhyou.h"
#include "ViewJikokuhyou\JikokuhyouColSpec\JikokuhyouColSpec.h"

namespace ViewJikokuhyou{
namespace WndJikokuhyou{

using namespace std ;
using namespace DcDrawLib ;
using namespace OuMfc;
using namespace DedRosenFileData;

/**
@brief
	CWndJikokuhyou �̃Z�����\�z����N���X�ł��B

�y�g�����z

�@(1)�@�R���X�g���N�^�ŃI�u�W�F�N�g�𐶐����Ă��������B
�@
�@(2)�@update() �ŁACWndJikokuhyou �̂��ׂẴZ�����X�V���܂��B

�@(3)�@��Ԃ݂̂̍X�V�̏ꍇ�́A update() �̑���� replaceRessya()��
�g�����Ƃ��ł��܂��B

�y�Z���̍X�V�菇�z

�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B
�@
�@(1.1)�@CWndDcdGrid �̊O�g����DcDraw�I�u�W�F�N�g�ƁA������ݒ�

�@(1.2)�@��̐���ݒ肵�܂��B
�@X�񐔂�2�����Ȃ�2�ɂ��܂��BY�񐔂́ACdYColSpecCont �œ��o���ꂽ�񐔂Ƃ��܂��B
�@
�@(1.3)�@X��(ColumnType_Ekimei) �̊e�Z���ƁA���ׂĂ�Y��̍����EY�񋫊E���EY�񋫊E���̍����ݒ�

�@(1.3.1)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) �ƁAY��(ColumnType_Ressyabangou)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�

�@(1.3.*.1)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) �̌����Z���̑�����ݒ�B

�@(1.3.*.2)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) ��DcDraw�I�u�W�F�N�g�̌^��ݒ�( CDcdTextbox �Ƃ���)�B

�@(1.3.*.3)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) DcDraw�I�u�W�F�N�g�ɁA������ݒ�B

�@(1.3.*.4)�@Y��(ColumnType_Ressyabangou) �̃Z���̍�����ݒ�

�@(1.3.*.5)�@Y��(ColumnType_Ressyabangou) �̋��E����DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B

�@(1.3.*.6)�@Y��ColumnType_Ressyabangou) �̋��E���̍�����ݒ�

�@(1.3.2)�@���l�ɁA�Z��(ColumnType_Ekimei, ColumnType_Ressyasyubetsu�` ColumnType_Bikou ) �ƁAY��(ColumnType_Ressyasyubetsu�` ColumnType_Bikou)�̍����EY�񋫊E���EY�񋫊E���̍�����ݒ�B

�@(1.3.3)�@X��(ColumnType_Ekimei ) �̕���ݒ�B���́A�w����� DcDraw �I�u�W�F�N�g�̕��Ƃ��܂��B

�@(1.3.4)�@X��(ColumnType_Ekimei ) �̋��E���� DcDraw�I�u�W�F�N�g�̑�����ݒ�B

�@(1.3.5)�@X��(ColumnType_Ekimei ) �̋��E���̕���ݒ�B

�@(1.4)�@X��(ColumnType_Chakuhatsu) �̊e�Z����ݒ�

�@(1.4.1)�@�Z��(ColumnType_Chakuhatsu, ColumnType_Ekijikoku_Chaku�` ColumnType_Ekijikoku_Hatsu) ��ݒ�B

�@(1.4.1.2)�@DcDraw�I�u�W�F�N�g�̌^��ݒ�( CDcdTextbox �Ƃ���)�B

�@(1.4.1.3)�@DcDraw�I�u�W�F�N�g�ɁA������ݒ�B

�@(1.4.3)�@X��(ColumnType_Chakuhatsu ) �̕���ݒ�B���́A������� DcDraw �I�u�W�F�N�g�̕��Ƃ��܂��B

�@(1.4.4)�@X��(ColumnType_Chakuhatsu ) �̋��E���� DcDraw�I�u�W�F�N�g�̑�����ݒ�B

�@(1.4.5)�@X��(ColumnType_Chakuhatsu ) �̋��E���̕���ݒ�B

�@(2)�@��ԏ���ݒ肵�܂��B

�@(2.1)�@X��̐���ݒ肵�܂��BCdXColSpecCont �Ŏw�肳�ꂽ�񐔂Ƃ��܂��B
�@
�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�
�@
�@(2.2.1)�@�Z��(ColumnType_Ressya ,ColumnType_Ressyabangou) ��ݒ�
�@
�@(2.2.*.1)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) �̌����Z����ݒ�
�@
�@(2.2.*.2)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) ��DcDraw�I�u�W�F�N�g�̌^��ݒ�( CDcdTextbox �Ƃ���)�B

�@(2.2.*.3)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) DcDraw�I�u�W�F�N�g�ɁA������ݒ�B

�@(2.2.2)�@���l�ɁA�Z��(ColumnType_Ressya, ColumnType_Ressyasyubetsu�` ColumnType_Bikou ) ��ݒ�B

�@(2.2.3)�@X��(ColumnType_Ressya ) �̕���ݒ�B���́A�w������� DcDraw �I�u�W�F�N�g�̕��Ƃ��܂��B

�@(2.2.4)�@X��(ColumnType_Ressya ) �̋��E���� DcDraw�I�u�W�F�N�g�̑�����ݒ�B

�@(2.2.5)�@X��(ColumnType_Ressya ) �̋��E���̕���ݒ�B
�@
�@(2.3)�@X��(ColumnType_NewRessya )�ɁA��ԏ���ݒ�BX��(ColumnType_Ressya )�Ɠ��l�B

*/
class CCellBuilder
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		�@DiagramEdit �̃A�v���P�[�V�������ǂݏ������� �w�H���t�@�C���x��
		�܂܂��f�[�^��ێ�����N���X�ł��B 
		  ���̃I�u�W�F�N�g�́A�֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B
	*/
	const CDedRosenFileData* m_pCDedRosenFileData ; 
	/**
		�@��ԃR���e�i���w�肵�Ă��������B
		  ���̃I�u�W�F�N�g�́A�֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B
	*/
	const CentDedRessyaCont* m_pCentDedRessyaCont ; 
	///@}
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		  �����\�r���[�� CWndJikokuhyou �̊e��ԍ��ƕ\�����e�̑��ݕϊ���
		�@�\����񋟂��܂��B
	*/
	CdXColSpecCont	m_CdXColSpecCont ;

	/**
		  �����\�r���[�� CWndJikokuhyou �̊e��ԍ��ƕ\�����e�̑��ݕϊ���
		�@�\����񋟂��܂��B
	*/
	CdYColSpecCont	m_CdYColSpecCont ;

	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�ʉ߉w�̉w������\�����邩�ۂ��̎w��ł��B
	
		- true ; �ʉ߉w�̉w������\�����܂��B(default)
		- false ; �ʉ߉w�̉w������\�������ɁA�ʉ߃}�[�N "�" ��\�����܂��B
	 */
	bool m_bDisplayTsuukaEkiJikoku ;
	///@}

protected:
	// --------------------------------
	///@name �Z���̕`��Ɏg�p����萔
	// --------------------------------
	///@{
	/**
	 	�e�Z���̃e�L�X�g�̎��̗͂]���̕��ł��B
	 	CDcdTextbox,CDcdTextboxV3 ��
	 	logicalunitFrameWidth , logicalunitFrameHeight �����Ɏg���܂��B
	 */
	static const int RectangleTextFrameWidth = 1 ; 
	///@}
	// --------------------------------
	///@name �Z���̕`��Ɏg�p����萔.
	// --------------------------------
	///@{
	/**
	@return 
		��Ԗ��̏c�����e�L�X�g�̈�̑傫�����A
		�e�L�X�g��(�s���E��)�ŕԂ��܂��B
	@note static �����o�֐��ɂ��邱�Ƃ��ł��܂��B
	*/
	CdDcdSizeXy	getRessyameiTextExtent()const
	{	return CdDcdSizeXy( 2 , 6 ) ;}

	/**
	@return
		���l�̏c�����e�L�X�g�̈�̑傫�����A�e�L�X�g���ŕێ����܂��B
	@note static �����o�֐��ɂ��邱�Ƃ��ł��܂��B
	*/
	CdDcdSizeXy getBikouTextExtent()const
	{	return CdDcdSizeXy( 2 , 12 ) ;}
	/** 
	@return 
		�w������\���`���ɕϊ�����I�u�W�F�N�g��Ԃ��܂��B 
	@note static �����o�֐��ɂ��邱�Ƃ��ł��܂��B
	*/
	const CdDedJikoku::CConv&	getCdDedJikokuConv()const;
	///@}

	// --------------------------------
	///@name �O���b�h�̌r���̑���
	// --------------------------------
	///@{

	/**
		�������̌r����`�悷�� DcDraw �I�u�W�F�N�g�𐶐����ĕԂ��܂��B
	@return
	 	�r���̑�����ێ������I�u�W�F�N�g�𐶐����܂��B
	 	
	@note static �����o�֐��ɂ��邱�Ƃ��ł��܂��B
	 */
	CdPenProp  getCdPenPropBoldLine()const
	{
		return CdPenProp( 2 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
	}

	/**
		�ׂ����̌r����`�悷�� DcDraw �I�u�W�F�N�g�𐶐����ĕԂ��܂��B
	@return
	 	�r���̑�����ێ������I�u�W�F�N�g�𐶐����܂��B
	@note static �����o�֐��ɂ��邱�Ƃ��ł��܂��B
	 */
	CdPenProp getCdPenPropNarrowLine()const
	{
		return CdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
	}
	/**
	 	�w�r���Ȃ��x�̂��߂� DcDraw �I�u�W�F�N�g�𐶐����ĕԂ��܂��B
	@return
	 	�r���̑�����ێ������I�u�W�F�N�g�𐶐����܂��B
	@note static �����o�֐��ɂ��邱�Ƃ��ł��܂��B
	 */
	CdPenProp	getCdPenPropNullLine()const
	{
		return CdPenProp( 0 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::NULLPEN ) ;
	}
	///@}


	// --------------------------------
	///@name �Z���̃e�L�X�g�`�摮��
	// --------------------------------
	///@{

	/**
	 	�������̍��ږ���\������Z��( "��Ԕԍ�" �E "��Ԏ��" �Ȃ�) ��
	 	�e�L�X�g�`�摮���i�t�H���g�E�F�j��ێ������I�u�W�F�N�g�𐶐����܂��B
	@return
		�e�L�X�g�`�摮����Ԃ��܂��B
	 */
	CdDrawTextProp	getCdDrawTextPropMenutext()const ;

	/**
	 	�ʏ�̃Z���i���w�i�j�́A
	 	�e�L�X�g�`�摮���i�t�H���g�E�F�j��ێ������I�u�W�F�N�g�𐶐����܂��B
	 	���̑����́A�w���Ɏg���܂��B
	@return
	 	�e�L�X�g�`�摮���i�t�H���g�E�F�j��Ԃ��܂��B
	 */
	CdDrawTextProp	getCdDrawTextPropStandard()const ;

	/**
	 	�ʉߗ�Ԃ̉w�����i�O���C�̕����j�́A
	 	�e�L�X�g�`�摮���i�t�H���g�E�F�j��ێ������I�u�W�F�N�g�𐶐����܂��B
	@return
	 	�e�L�X�g�`�摮����Ԃ��܂��B
	 */
	CdDrawTextProp	getCdDrawTextPropTsuuka()const ;

	///@}

	// --------------------------------
	///@name �Z���̃u���V����
	// --------------------------------
	///@{
	/**
	 	���ږ���\������Z��( "��Ԕԍ�" �E "��Ԏ��" �Ȃ�) ��
	 	�u���V�̑����𐶐����܂��B
	@return
	 	�u���V�̑�����Ԃ��܂��B
	 */
	CdBrushProp CCellBuilder::getCdBrushPropMenutext()const;

	/**
	 	�ʏ�̃Z���i���w�i�j�́A
	 	�u���V�̑�����ێ������I�u�W�F�N�g�𐶐����܂��B
	@return
	 	�u���V�̑�����Ԃ��܂��B
	 */
	CdBrushProp	CCellBuilder::getCdBrushPropStandard()const;
	///@}
	// --------------------------------
	///@name �Z���̕`��Ɏg�p���� DcDraw�I�u�W�F�N�g�̃v���g�^�C�v
	// --------------------------------
	///@{


	/**
	 	���ږ���\������Z��( "��Ԕԍ�" �E "��Ԏ��" �Ȃ�) ��
	 	DcDraw �I�u�W�F�N�g�𐶐����ĕԂ��܂��B
	@return
	 	DcDraw �I�u�W�F�N�g��Ԃ��܂��B
	 */
	CDcdTextbox createCDcdXColumn0()const;

	/**
	 	�c�����̍��ږ�(��Ԗ��E���l) �\�����Ɏg�p����
	 	 DcDraw �I�u�W�F�N�g�𐶐����܂��B
	@return
	 	DcDraw �I�u�W�F�N�g��Ԃ��܂��B
	 */
	CDcdTextboxV3 createCDcdXColumn0V()const;


	/**
	 	�w�������� DcDraw �I�u�W�F�N�g�𐶐�����
	 	�Ԃ��܂��B
	@return
	 	DcDraw �I�u�W�F�N�g��Ԃ��܂��B
	 */
	CDcdTextbox createCDcdEkimei()const ;

	/**
	 	X��P�Ԃ́A�w���x�E�w���x������ DcDraw �I�u�W�F�N�g�𐶐�����
	 	�Ԃ��܂��B
	@return
		DcDraw �I�u�W�F�N�g��Ԃ��܂��B
	*/
	CDcdTextbox createCDcdHatsuchaku()const;

	/**
		�O���b�h��̗�ԏ��̂����A
		��Ԏ�ʕ����F�ƁA�t�H���g�u�����\�r���[ 1�v�E�ŕ`�悷��Z����
		DcDraw�I�u�W�F�N�g�𐶐����ĕԂ��܂��B

		�K�p�ӏ��́A��Ԕԍ��E�����E�u���v�ł��B
	@param iRessyasyubetsuIndex [in]
		��Ԏ�ʃC���f�N�X���w�肵�Ă��������B
	@return
	 	��ԏ��̗�Ԏ�ʁE�w���������� DcDraw �I�u�W�F�N�g�𐶐�����
	 	�Ԃ��܂��B
	 */
	CDcdTextbox createCDcdRessyabangou(
		int iRessyasyubetsuIndex )const ;

	/**
		�c�����̗�ԏ���DcDraw�I�u�W�F�N�g�𐶐����ĕԂ��܂��B

		�K�p�ӏ��́A��Ԗ��ł��B
	@param iRessyasyubetsuIndex [in]
		��Ԏ�ʃC���f�N�X���w�肵�Ă��������B
	@return
	 	DcDraw �I�u�W�F�N�g��Ԃ��܂��B
	 */
	CDcdTextboxV3 createCDcdRessyamei(
		int iRessyasyubetsuIndex )const;

	/**
		�O���b�h��̗�ԏ��̂����A
		��Ԏ�ʕ����F�ƁA��Ԏ�ʃt�H���g�ŕ`�悷��Z����
		DcDraw�I�u�W�F�N�g�𐶐����ĕԂ��܂��B

		�K�p�ӏ��́A��Ԏ�ʁE�w�����ł��B
	@param iRessyasyubetsuIndex [in]
		��Ԏ�ʃC���f�N�X���w�肵�Ă��������B
	@return
	 	��ԏ��̗�Ԏ�ʁE�w���������� DcDraw �I�u�W�F�N�g�𐶐�����
	 	�Ԃ��܂��B
	 */
	CDcdTextbox createCDcdEkijikoku(
		int iRessyasyubetsuIndex )const;

	///@}

protected:
	// --------------------------------
	///@name update() �̉����֐�
	// --------------------------------
	///@{
	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_updateWithoutRessya(
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

	  (1.1)�@CWndDcdGrid �̊O�g����DcDraw�I�u�W�F�N�g�ƁA�񕝂�ݒ�

	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_01_setGridBorder( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.1)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) �ƁA
			Y��(ColumnType_Ressyabangou)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_01_setEkimei_Ressyabangou( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.2.2)�Z��(ColumnType_Ekimei, ColumnType_Ressyasyubetsu)
		��Y��(ColumnType_Ressyasyubetsu)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_02_02_setEkimei_Ressyasyubetsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	
	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.2.3)�Z��(ColumnType_Ekimei, ColumnType_Ressyamei)
		��Y��(ColumnType_Ressyamei)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_02_03_setEkimei_Ressyamei( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.2.4)�Z��(ColumnType_Ekimei, ColumnType_Gousuu)
		��Y��(ColumnType_Gousuu)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_02_04_setEkimei_Gousuu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.2.5)�Z��(ColumnType_Ekimei, ColumnType_Gou)
		��Y��(ColumnType_Gou)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_02_05_setEkimei_Gou( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.2.6)�Z��(ColumnType_Ekimei, ColumnType_Ekijikoku_Chaku)
		��Y��(ColumnType_Gou)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_02_06_setEkimei_Chaku( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.2.7)�Z��(ColumnType_Ekimei, ColumnType_Ekijikoku_Hatsu)
		��Y��(ColumnType_Gou)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_02_07_setEkimei_Hatsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.3.2.8)�Z��(ColumnType_Ekimei,ColumnType_Bikou)
		��Y��(ColumnType_Gou)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_03_02_08_setEkimei_Bikou( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.4.1)�@�Z��(ColumnType_Chakuhatsu, ColumnType_Ekijikoku_Chaku) 
		��ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_04_01_06_setChakuhatsu_Chaku( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
	�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B

		(1.4.1)�@�Z��(ColumnType_Chakuhatsu, ColumnType_Ekijikoku_Hatsu) 
		��ݒ�
			
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update01_04_01_07_setChakuhatsu_Hatsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;




	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�
	�@(2.3)�@X��(ColumnType_NewRessya )�ɁA��ԏ���ݒ�B
		X��(ColumnType_Ressya )�Ɠ��l�B
	
	  �Z���̍ĕ`��v��(CWnd::InvalidateRect())���s���܂��B

	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_updateRessya( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
		
	
	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

	�@(2.2.2.1)�@�Z��(ColumnType_Ressya ,ColumnType_Ressyabangou) ��ݒ�
			
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_01_setRessya_Ressyabangou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

		(2.2.2.2)�Z��(ColumnType_Ressya, ColumnType_Ressyasyubetsu)
		 ��ݒ�B
			
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_02_02_setRessya_Ressyasyubetsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

		(2.2.2.3)�Z��(ColumnType_Ressya, ColumnType_Ressyamei)
		 ��ݒ�B
			
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_02_03_setRessya_Ressyamei( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

		(2.2.2.4)�Z��(ColumnType_Ressya, ColumnType_Gousuu)
		 ��ݒ�B
			
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_02_04_setRessya_Gousuu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

		(2.2.2.5)�Z��(ColumnType_Ressya, ColumnType_Gou)
		 ��ݒ�B
			
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_02_05_setRessya_Gou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

		(2.2.2.6)�Z��(ColumnType_Ressya,ColumnType_Ekijikoku_Chaku)
		 ��ݒ�B
			
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param iEkiOrder [in]
		  �wOrder���w�肵�Ă��������B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_02_06_setRessya_Chaku( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

		(2.2.2.7)�Z��(ColumnType_Ressya,ColumnType_Ekijikoku_Hatsu)
		 ��ݒ�B
			
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param iEkiOrder [in]
		  �wOrder���w�肵�Ă��������B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_02_07_setRessya_Hatsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�

		(2.2.2.8)�Z��(ColumnType_Ressya,ColumnType_Bikou)
		 ��ݒ�B
	@param iXColumnNumber [in]
		�@��Ԕԍ����w�肷��X��ԍ����w�肵�Ă��������B
	@param pCentDedRessya [in]
		�@�ݒ肷���ԏ����w�肵�ĉ���a.
		�@NULL�Ȃ�A���Ԃ��w�肵�����ƂɂȂ�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update02_02_02_08_setRessya_Bikou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	///@{
	/**
	@param pCDedRosenFileData [in]
		�@DiagramEdit �̃A�v���P�[�V�������ǂݏ������� �w�H���t�@�C���x��
		�܂܂��f�[�^��ێ�����N���X�ł��B 
		  ���̃I�u�W�F�N�g�́A�֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B
	@param pCentDedRessyaCont [in]
		�@��ԃR���e�i���w�肵�Ă��������B
		  ���̃I�u�W�F�N�g�́A�֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B
	@param bDisplayTsuukaEkiJikoku [in]
		�ʉ߉w�̉w������\�����邩�ۂ��̎w��ł��B
		- true ; �ʉ߉w�̉w������\�����܂��B(default)
		- false ; �ʉ߉w�̉w������\�������ɁA�ʉ߃}�[�N "�" ��\�����܂��B
	@param bDisplayAllJikoku [in]
		�S�����\�����[�h��ON/OFF�ł��B
		- true ;[�S������\��] ���[�h
	 */
	CCellBuilder( 
		const CDedRosenFileData* pCDedRosenFileData ,
		const CentDedRessyaCont* pCentDedRessyaCont,
		bool bDisplayTsuukaEkiJikoku ,
		bool bDisplayAllJikoku )  ;
public:
	// ********************************
	///@name CCellBuilder-����
	// ********************************
	///@{
	bool getDisplayTsuukaEkiJikoku()const
	{	return m_bDisplayTsuukaEkiJikoku ;}
	void setDisplayTsuukaEkiJikoku( bool value )
	{	m_bDisplayTsuukaEkiJikoku = value ; }
	///@{
public:
	// ********************************
	///@name	CCellBuilder-����
	// ********************************
	///@{
	/**
		�@���ׂẴZ�����X�V���܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void update( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	 	���ׂĂ̗�ԏ��̗���X�V���܂��B

		Y��̐��E�����̍��ږ���͍X�V���܂���B		

	 	- 1. ��Ԃ̐��ɏ]���āAX�񐔂�ݒ肵�܂��B
	 	- 2. ���ׂĂ̗�Ԃ�ݒ肵�܂��B
	 	- 3. �e��Ԃ̉E���̌r����ݒ肵�܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�̃Z�����X�V���܂��B
	*/
	void updateAllRessya( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
		�@�Z�����̗�Ԃ�u�������܂��B
		  Y��̐��E�����̍��ږ���E�w��͈͊O�̗�ԗ�͍X�V���܂���B		
	@param iDstRessyaIndex [in]
		�@�폜�E�ǉ��ΏۂƂȂ��Ԃ̗��Index���w�肵�Ă��������B
	@param iDstDelCount [in] 
		�@�폜�����(�u���ɂ���Ď�����)��Ԃ̐����w�肵�Ă��������B
	@param iInsertCount [in]
		�@�ǉ������(�u���ɂ���ĐV���ɐ�����ύX���ꂽ)��Ԃ̐����w�肵��
		���������B
	@param bDisplayAllJikoku [in]
		�@- true : �S�Ẳw������\�����܂��B
	@param pCWndJikokuhyou [out]
		�@���̊֐��͂��̃E�C���h�E�ɃZ����ǉ����܂��B
	*/
	void replaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	///@}
};


} //namespace ViewJikokuhyou
} //namespace WndJikokuhyou

#endif //ViewJikokuhyou_WndJikokuhyou_CCellBuilder_h
