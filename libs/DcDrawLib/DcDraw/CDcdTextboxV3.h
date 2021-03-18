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
//	CDcdTextboxV3.h
// ****************************************************************
*/
/** @file */
#ifndef  ViewJikokuhyou_WndJikokuhyou_CDcdFillRectangleTextV3_h
#define  ViewJikokuhyou_WndJikokuhyou_CDcdFillRectangleTextV3_h

#include <string>
#include "str\tstring.h"

#include "DcDraw\CDcdFillrect.h"
#include "DcDraw\CDcdRectangle.h"
#include "DcDraw\CDcdText.h"
#include "DcDraw\CVerticalTextElement.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"
#include "NsMu\Mup.h"

namespace DcDrawLib{
namespace DcDraw{

using namespace std ;
using namespace OuLib::NsMu;
using namespace DcDrawLib::DcDraw;
// ****************************************************************
//	CDcdTextboxV3
// ****************************************************************
/**
@brief
   DcDraw���f���ɂ�����A�`��A���S���Y�������������I�u�W�F�N�g�ł��B
�@��������c����(���v����270����])�ŕ`�悵�܂��B

  ���{����c�����œǂ߂�悤�ɕ`�悷��ɂ́A�t�H���g�̑����Ƃ��āA
  �c�����t�H���g(�^�C�v�t�F�C�X���̐擪�� @ )���w�肷��K�v��
  ����܂��B

  ���̃N���X�ł́ADcDraw�Ŏw�肳�ꂽ�̈�̊O�ӂ��㉺���E�ɁA

	- m_logicalunitFrameWidth 
	- m_logicalunitFrameHeight 

���̘g�̈���m�ۂ��A���̓����� m_strText �̃e�L�X�g���������݂܂��B

  ���̃I�u�W�F�N�g�ɑ΂��� DcDraw() ���Ăяo���ƁA�ȉ��̏������s���܂��B

�P�D  �܂��A�̈�S�̂��A�u���V���� m_CdBrushProp �œh��Ԃ��܂��B

�Q�D  �̈�̊O�ӓ����ɁA�w��̃y������ m_CdPenProp �Řg����
�`�悵�܂��B

�R�D  �g�̈�̓����ɁA
�e�L�X�g m_strText ��`�悵�܂��B
  
<H4>
�y�e�L�X�g�̔z�u�ɂ��āz
</H4>
�@���̃N���X�́A���������ォ��E���Ɍ������āA
 �c����(���v����270����])�ŕ`�悵�܂��B
  �A���A�t�H���g�̑������c�����t�H���g�ŁA�S�p�����̊Ԃɔ��p�����P�E�܂��͂Q������ꍇ�A
���̔��p�����͉������ŕ`�悵�܂��B
  	
�i��j
@code
    11
    ��
    23
    ��
@endcode
  
<H4>
�y���̃N���X�̑����z
</H4>
  ���̃N���X�̑����ɂ́A���̃N���X�̃����o�ϐ��ȊO�ɁA�ȉ��̂��̂�����܂��B
  �����̑����́Am_CDcdFillrect , m_CDcdRectangle �̑����Ƃ��Ď�������܂��B

<H5>
CdBrushProp	m_CdBrushProp ;
</H5>
�h��Ԃ��Ɏg�p����u���V�̑����B

<H5>
CdPenProp	m_CdPenProp
</H5>
�g����`�悷�邽�߂̃y���̑����B
  
<H4>
CDcdTextboxV,CDcdTextboxV2�Ƃ̈Ⴂ
</H4>
�@CDcdTextboxV �́A�������t�H���g���c�ɕ��ׂāA�c�����\�����������Ă��܂����B
  CDcdTextboxV2 �́A�c�����t�H���g���g�p���܂��B���p2���ȉ��̐����́A���
���������s���܂��B
�@CDcdTextboxV3 �ł́A�c�����t�H���g�E�������t�H���g�̂ǂ�����g�p���邱�Ƃ�
�ł��܂��B�c�����t�H���g���w�肵���Ƃ��ɂ́A���p2���ȉ��̐��������������܂��B
�������t�H���g���w�肵���ꍇ�́A���p2���ȉ��̐����ɑ΂��鉡�����͍s���܂���B
 */
class CDcdTextboxV3 : public IfDcDraw
{
public:
	// ****************************************************************
	//	CDcdTextboxV3::CStrElementPlace
	// ****************************************************************
	/**
	  	�w������v�f�x�̕`��ʒu��\���\���̂ł��B
	 */
	class CStrElementPlace
	{
	private:
		// ********************************
		///@name ����
		// ********************************
		///@{
		/**
		  	�`����s��������v�f�B
		 */
		CVerticalTextElement	m_CStrElement ;
	
		/**
		  	�`��J�n�ʒu�̂x���W����A�e�L�X�g�̍���̂x���W�܂ł̋���
		  	�i�_���P�ʁj�B
		 */
		int m_logicalunitYOffset ;	
	
		/**
		  	�`�悷��w�����̍s�ԍ��B�N�_�i��ԉE�j�͂O�B
		 */
		int m_iXLineNumber ;

		/**
		  	������̂w�����̕��i�_���P�ʁj�B
		 */
		int m_iXLineWidth ;
		///@}
	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		/**
		   @param aCStrElement [in]
		  	�`����s��������v�f�B
		   @param logicalunitYOffset [in]
		  	�`��J�n�ʒu�̂x���W����A�e�L�X�g�̍���̂x���W�܂ł̋���
		  	�i�_���P�ʁj�B
		   @param iXLineNumber [in]
		  	�`�悷��w�����̍s�ԍ��B�N�_�i��ԉE�j�͂O�B
		   @param iXLineWidth [in]
		  	������̂w�����̕��i�_���P�ʁj�B
		 */
		CStrElementPlace( 
			const CVerticalTextElement&	aCStrElement ,
			int logicalunitYOffset , 
			int iXLineNumber , 
			int iXLineWidth ) :
			m_CStrElement( aCStrElement ) , 
			m_logicalunitYOffset( logicalunitYOffset ) ,
			m_iXLineNumber( iXLineNumber ) , 
			m_iXLineWidth( iXLineWidth ) {};
		CStrElementPlace( ) :
			m_logicalunitYOffset( 0 ) ,
			m_iXLineNumber( 0 ){};
	public:
		// ********************************
		///@name CStrElementPlace-����
		// ********************************
		///@{
		CVerticalTextElement	getCStrElement()const{ return m_CStrElement ;};
		CStrElementPlace& setCStrElement( 
				const CVerticalTextElement& value ){
			m_CStrElement = value ; return *this ; } ;
		int getYOffset()const{ return m_logicalunitYOffset ;};
		CStrElementPlace& setYOffset( int value ){
			m_logicalunitYOffset = value ;	};
		int getXLineNumber()const{ return m_iXLineNumber ;};
		CStrElementPlace& setXLineNumber( int value ){
			m_iXLineNumber = value ; return *this ; } ;
		int getXLineWidth()const{ return m_iXLineWidth ;};
		CStrElementPlace& setXLineWidth( int value ){
			m_iXLineWidth = value ; return *this ; } ;
		///@}
	};


	
private:
	// ********************************
	///@name	���
	// ********************************
	///@{
	/**
	  	�w�i��`�悷��I�u�W�F�N�g�ł��B
	  
	  	���̃I�u�W�F�N�g�̑��� CDcdFillrect::m_CdBrushProp �́A
	  	���̃N���X�̃����o�֐��o�R�ő���ł��܂��B
	 */
	CDcdFillrect		m_CDcdFillrect ;
	/**
	  	�g����`�悷��I�u�W�F�N�g�ł��B
	  
	  	���̃I�u�W�F�N�g�̑��� CDcdRectangle::m_CdPenProp �́A
	  	���̃N���X�̃����o�֐��o�R�ő���ł��܂��B
	 */
	CDcdRectangle		m_CDcdRectangle ;
	
	///@}
private:
	// ********************************
	/// @name ����
	// ********************************
	///@{
	/**
	  	�`�悷�镶����ł��B
	 */
	tstring			m_strText ;


	/**
	  	�e�L�X�g��`�悷��ۂ̃t�H���g��ێ����܂��B
	 */
	CdFontProp	m_CdFontProp ;

	
	/**
	  	���̕`�敔�i�ɕ\���ł���AX�����i�������j�̑S�p�ł̕�������ێ����܂��B
	  	�ڍׂ́A m_iLinesExtentY �̐������Q�Ƃ��Ă��������B

		����l��1�ł��B
	 */
	int	m_iLinesExtentX ;

	/**
	  	���̕`�敔�i�ɕ\���ł���AY�����i�c�����j�̑S�p�ł̕�������ێ����܂��B
	  
	  	 getItemSize() �́A �ȉ��̒l��Ԃ��܂��B
	  	-	X = �t�H���g�̍����~m_LinesExtectX 
	  	-	Y = �t�H���g�̍����~m_LinesExtectY 

		����l��1�ł��B
	*/
	int	m_iLinesExtentY ;

	/**
	  	�e�L�X�g��`�悷��ꍇ�̕����F�ł��B
	  	�f�t�H���g�͍��ł��B
	 */
	CdColorProp	m_colorrefText ;
	
	/**
	  	�e�L�X�g�̍��E�̘g�̈�̑������A�_���P�ʂŕێ����܂��B
	  	�����E�E�����ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B

		����l��0�ł��B
	 */
	int	m_logicalunitFrameWidth ;

	/**
	  	�e�L�X�g�̏㉺�̘g�̈�̑������A�_���P�ʂŕێ����܂��B
	  	�㑤�E�������ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B

		����l��0�ł��B
	*/
	int	m_logicalunitFrameHeight ;
	///@}
 protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	  	�t�H���g�̑������i�[���� CdFontProp �I�u�W�F�N�g�����ƂɁA
	  	�c�����p�̃t�H���g�n���h���𐶐����܂��B
	  	
	  	���̊֐��́A�w�肳�ꂽ CdFontProp ��  m_iEscapement
	  	��ύX���������ŁA�t�H���g�𐶐����܂��B
	  	
	@param pIfDcdTarget [in]
	  	�`��Ώۂ̃f�o�C�X�R���e�L�X�g���w�肵�Ă��������B
	@param aCdFontProp [in]
	  	�`��Ɏg�p����t�H���g���w�肵�Ă��������B
	@return
	  	�Ή����� HFONT ��ێ����� Ou<CGdiHFontHolder> ��Ԃ��܂��B
	*/
	static Ou<CGdiHFontHolder> CreateVFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp ) ;

	
	/**
	  	�t�H���g�̑������i�[���� CdFontProp �I�u�W�F�N�g�����ƂɁA
	  	�������p�̃t�H���g�n���h���𐶐����܂��B
	  	
	  	���̊֐��́A�w�肳�ꂽ CdFontProp ��  m_iEscapement
	  	��ύX���������ŁA�t�H���g�𐶐����܂��B
	  	
	@param pIfDcdTarget [in]
	  	�`��Ώۂ̃f�o�C�X�R���e�L�X�g���w�肵�Ă��������B
	@param aCdFontProp [in]
	  	�`��Ɏg�p����t�H���g���w�肵�Ă��������B
	@return
	  	�Ή����� HFONT ��ێ����� Ou<CGdiHFontHolder> ��Ԃ��܂��B
	*/
	static Ou<CGdiHFontHolder> CreateHFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp )  ;
	
	/**
	  	�c�����̑S�p�����P�̑傫�����v�Z���܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ̃f�o�C�X�R���e�L�X�g���w�肵�Ă��������B
	   @param fontHorizontal [in]
	  	�`��Ɏg�p����t�H���g���w�肵�Ă��������B
	  	�����Ŏw�肷��t�H���g�́A�������̂��̂łȂ��Ă͂Ȃ�܂���B
	   @return
	  	�c�����̑S�p�����P�̑傫����Ԃ��܂��B
	 */
	static CdDcdSizeXy calcZenkakuCharExtent(
		IfDcdTarget* pIfDcdTarget , 
		const CdFontProp& aCdFontProp ) ;
	
	
	/**
	  	�c���������񒆂ɉ������e�L�X�g��`�悷�邽�߂� CDcdText �I�u�W�F�N�g��
	  	�������܂��B
		���̃I�u�W�F�N�g�́Am_strExtent�� "00" �A m_iLinesExtent ��
		1 ���ݒ肳��Ă��܂��B���̂��߁AgetExtent() ���Ăяo�����Ƃɂ��A
		�������e�L�X�g�̕��ƍ������擾�ł��܂��B
	   @param aCdFontProp [in]
	  	�e�L�X�g��`�悷��ۂ̃t�H���g��ێ����܂��B
		���̊֐��́AaCdFontProp �� m_iEscapement �𖳎����܂��B
	   @param colorrefText [in]
	  	�e�L�X�g��`�悷��ꍇ�̕����F�ł��B

	 */
	static CDcdText createCDcdTextH( 
		const CdFontProp&	aCdFontProp , 
		const CdColorProp& colorrefText ) ;
	
	/**
	  	�z��Ɋi�[����Ă���w������v�f�x�̊e�v�f�̕`��ʒu�����߂܂��B
	  	
	  	���̊֐��́A�w�肳�ꂽ�����̕`��̈�Ƀe�L�X�g���c�����Ŕz�u�����
	  	���肵�āA�w������v�f�x���̂ӂ��킵�����W�����肵�܂��B
	  
	  	���̊֐������ۂ̕`����s���킯�ł͂���܂���B���̊֐��͍s���̂�
	  	�`��ʒu�̌��肾���ł��B
	@param pIfDcdTarget [in]
	  	�`��Ώۂ̃f�o�C�X�R���e�L�X�g���w�肵�Ă��������B
	@param aCdFontProp [in]
	  	�`��Ɏg�p����t�H���g���w�肵�Ă��������B
	@param pCStrElementCont [in]
	  	�w������v�f�x���i�[�����R���e�i���w�肵�Ă��������B
	@param pCStrElementPlaceCont [out]
	  	���̊֐��͂��̃R���e�i�̖����ɁA
	  	�w������v�f�x���Ƃ̕`��ʒu���i�[���� CStrElementPlace 
	  	�I�u�W�F�N�g��ǉ����܂��B
	  	���̃R���e�i������܂ŕێ����Ă����v�f�͔j�����܂��B
	@return
	  	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	  	���݂̂Ƃ���A��� 0 �ł��B
	   @attention
	  	pCStrElementCont �Ɋi�[����Ă���v�f�̐��ƁA
	  	pCStrElementPlaceCont �ɒǉ������v�f�̐��́A�����Ƃ͌���܂���B
	  	���̊֐���������v�f�̌������s���ꍇ�����邩��ł��B@n
	  	�i��j pCStrElementCont �� "��"�E"�s"�E"��" �Ƃ���
	  	�v�f���i�[����Ă����ꍇ�A���̂R���������������s�ɕ`��ł���ꍇ�́A
	  	���̊֐��́w������v�f�x���������āA��� "���s��" �Ƃ���������v�f��
	  	���܂��B
	 */
	static int VerticalTextElementToElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp ,
		const Mu<CVerticalTextElement>* pCStrElementCont ,
		Mui<CStrElementPlace>* pCStrElementPlaceCont ) ;

	/**
	 	�z��Ɋi�[����Ă���w������v�f�x�̕`��ʒu�ɂ��������āA
	 	������� IfDcdTarget �̈���ɕ`�悵�܂��B
	@param pIfDcdTarget [in]
	 	�`��Ώۂ��w�肵�Ă��������B
	 	���̊֐��́A���̕`��̈�̍��ォ��A�c�����Ńe�L�X�g��`�悵�܂��B
	@param aFontProp [in]
	 	�`��Ɏg�p����t�H���g���w�肵�Ă��������B
	 	�����Ŏw�肷��t�H���g�́A�������̂��̂łȂ��Ă͂Ȃ�܂���B
	@param colorTextColor [in]
		�e�L�X�g�̕����̐F���w�肵�Ă��������B
	@param pCStrElementPlaceCont [in]
	 	�w������v�f�x���Ƃ̕`��̈���i�[�����R���e�i���w�肵�Ă��������B
	@return
	 	�`����s������^�E�����`����s��Ȃ������ꍇ�͋U�ł��B
	*/
	static bool DcDrawElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aFontProp ,
		const CdColorProp& colorTextColor , 
		const Mu<CStrElementPlace>* pCStrElementPlaceCont ) ;

	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************

	/**
	@param strText [in]
	 	�`�悷�镶����ł��B
	@param aCdFontProp [in]
	 	�e�L�X�g��`�悷��ۂ̃t�H���g��ێ����܂��B
	@param bAlwaysUseVFont [in]
		�@�c�����t�H���g����Ɏg�p���邩�ۂ����w�肵�܂��B
	@param iLinesExtentX [in]
	 	���̕`�敔�i�ɕ\���ł���AX�����i�������j�̕�������ێ����܂��B
	@param iLinesExtentY [in]
		���̕`�敔�i�ɕ\���ł���AY�����i�c�����j�̕�������ێ����܂��B
		 getItemSize() �́A �ȉ��̒l��Ԃ��܂��B
		-	X = �t�H���g�̍����~m_LinesExtectX 
		-	Y = �t�H���g�̍����~m_LinesExtectY 
	@param colorrefText [in]
		�e�L�X�g��`�悷��ꍇ�̕����F�ł��B
	@param logicalunitFrameWidth [in]
		�e�L�X�g�̍��E�̘g�̈�̑������A�_���P�ʂŎw�肵�Ă��������B
		�����E�E�����ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
	@param logicalunitFrameHeight [in]
		�e�L�X�g�̏㉺�̘g�̈�̑������A�_���P�ʂŎw�肵�Ă��������B
		�㑤�E�������ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
		logicalunitFrameHeight �������ȗ������ꍇ�́A logicalunitFrameWidth 
		�Ɠ����ł���Ƃ݂Ȃ���܂��B
		logicalunitFrameHeight �E logicalunitFrameWidth �̗�����
		�ȗ������ꍇ�́A �O �Ƃ݂Ȃ��܂�
	@param aCdPenProp [in]
		�g����`�悷�邽�߂̃y���̑���
	@param aCdBrushProp [in]
		�h��Ԃ��Ɏg�p����u���V�̑������w�肵�Ă��������B
		�ȗ�������ANULLBRUSH�Ƃ݂Ȃ��܂��B
	@param eHalfCharInTextV [in]
		�@�c�����\���̃e�L�X�g�{�b�N�X���ŁA
		���p������`�悷����@���w�肵�܂��B
	 */
	CDcdTextboxV3( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp ,
		int						iLinesExtentX ,
		int						iLinesExtentY ,
		const CdColorProp&	colorrefText = CdColorProp( 0 , 0 , 0 ) , 
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const CdPenProp&		aCdPenProp = CdPenProp() ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() ) ;

	CDcdTextboxV3() ;
	
	virtual ~CDcdTextboxV3() ;

 public:
	// ********************************
	///@name	IfDcDraw
	// ********************************
	///@{
	/**
	 	�`���v�����܂��B
	 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	
		�y�I�[�o���C�h�z
		  �n���ꂽ�̈�ɁA m_strText ��`�悵�܂��B
	 @param pIfDcdTarget  [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 @return
	 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	*/
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 	���̃I�u�W�F�N�g���`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 	���̑傫���𒲂ׂ邱�Ƃ��ł��܂��B
	 	�֐��Ăяo������������ IfDcDraw �I�u�W�F�N�g��`�悷��ꍇ�ɂ́A
	 	�֐��Ăяo�����́A���̊֐��ŃA�C�e���̑傫���𒲂ׂāA
	 	�K�؂ȃ��C�A�E�g���l���Ă���ADcDraw() �����s���邱�Ƃ��ł��܂��B
	
		�y�I�[�o���C�h�z
		m_LinesExtentX m_LinesExtentY �����ƂɌv�Z�����e�L�X�g�̈�̃T�C�Y��
		m_logicalunitFrameWidth ,m_logicalunitFrameHeight �������āA
		�̈�̃T�C�Y���v�Z���܂��B

 	
	@param pIfDcdTarget [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 @param pCdDcdSizeXy [out]
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 	���̊֐��͂��̃A�h���X�ɁA���̃A�C�e���̃T�C�Y��Ԃ��܂��B
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��Ȃ��ꍇ�́A
	 	���̒l�͕s��ł��B
	 @return
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��āA
	 	���̑傫���� *pCDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	 	�����łȂ��ꍇ�́A�U�ł��B
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	///@}
// ********************************
//	CDcdTextboxV3
// ********************************
 public:
	// ********************************
	///@name CDcdTextboxV3-����
	// ********************************
	///@{
	virtual CdBrushProp	getCdBrushProp()
	{	return m_CDcdFillrect.getCdBrushProp()	;	} ;
	virtual CDcdTextboxV3& setCdBrushProp( const CdBrushProp& value )
	{	m_CDcdFillrect.setCdBrushProp( value ) ;	return *this ;}
	virtual CdPenProp	getCdPenProp()
	{	return m_CDcdRectangle.getCdPenProp()	;	} ;
	virtual CDcdTextboxV3& setCdPenProp( const CdPenProp& value )
	{	m_CDcdRectangle.setCdPenProp( value ) ;	return *this ;}

	virtual tstring			getText()
	{	return m_strText ;	} ;
	virtual CDcdTextboxV3& setText( const tstring& value )
	{	m_strText = value ; 	return *this ; } ;

	virtual CdFontProp	getCdFontProp()
	{	return m_CdFontProp ;};
	virtual CDcdTextboxV3& setCdFontProp( 
			const CdFontProp& value )
	{	m_CdFontProp = value ; return *this ; } ;

	virtual int				getLinesExtentX()
	{	return m_iLinesExtentX ; } ;
	virtual CDcdTextboxV3& setLinesExtentX( int value )
	{	m_iLinesExtentX = value ; 	return *this ; } ;
	virtual int				getLinesExtentY()
	{	return m_iLinesExtentY ; } ;
	virtual CDcdTextboxV3& setLinesExtentY( int value )
	{	m_iLinesExtentY = value ; 	return *this ; } ;

	virtual CdColorProp	getTextColor()
	{	return m_colorrefText ;	};
	virtual CDcdTextboxV3& setTextColor( const CdColorProp& value )
	{	m_colorrefText = value ; return *this ; } ;

	virtual int	getFrameWidth()
	{	return m_logicalunitFrameWidth ;};
	virtual CDcdTextboxV3& setFrameWidth( int value )
	{	m_logicalunitFrameWidth = value ;	return *this ; } ;

	virtual int	getFrameHeight(){	return m_logicalunitFrameHeight ;};
	virtual CDcdTextboxV3&  setFrameHeight( int value )
	{	m_logicalunitFrameHeight = value ;	return *this ; } ;
	///@}
		

};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*ViewJikokuhyou_WndJikokuhyou_CDcdTextboxV3_h*/
