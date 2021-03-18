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
//	CDcdTargetMfcPrintInfo.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdTargetMfcPrintInfo_h
#define  CDcdTargetMfcPrintInfo_h

#include <afxext.h>

#include "DcDraw/IfDcdTarget.h"
#include "DcDraw/CGdiCache.h"

namespace DcDrawLib{
	using namespace DcDraw;
namespace DcDrawMfc{


// ****************************************************************
//	CDcdTargetMfcPrintInfo
// ****************************************************************
/**
 * @brief
 *	�y�T�v�z
 *	  MFC �� DocView ���f���ł́A���/����v���r���[�̕`��̈��񋟂���
 *	�N���X�ł��B����̏ꍇ�E����v���r���[�̏ꍇ�Ƃ��A���̃N���X��
 *	���p���邱�Ƃ��ł��܂��B
 *	
 *	  MFC��DocView�A�v���P�[�V�����ł́ACView::OnPrint() �̃I�[�o���C�h��
 *	���̃I�u�W�F�N�g�𐶐����邱�Ƃɂ��ADcDraw���f���ɂ��v�����^�ւ�
 *	�`����s�����Ƃ��ł��܂��B
 *	
 *	  ���̃N���X�̃C���X�^���X�́ACView::OnPrint() �̃I�[�o���C�h�̒���
 *	�������A���̊֐������^�[������܂łɔj�����Ȃ��Ă͂Ȃ�܂���B
 *	�ʏ�́A�����ϐ��Ƃ��ăC���X�^���X�𐶐����Ă��������B
 *	
 *	<H4>
 *	�y���W�n�ɂ��āz
 *	</H4>
 *	
 *	  ���̃N���X�́A����̏��́AOnPrint() �œn����� CDC �� CPrintInfo 
 *	����擾���܂��B�`��̈�i getZone() �Ŏ擾�ł���̈�j�́A
 *	CPrintInfo::m_rectDraw �i�y�[�W�̕`��ł���̈�j�ɓ������Ȃ�܂��B
 *	
 *	  �`��̈�̍��W�l�́A����̏ꍇ������v���r���[�̏ꍇ���A
 *	�v�����^�̂P�h�b�g���P�_���P�ʂƂȂ�܂��B
 *	  ����v���r���[�̏ꍇ�AMFC�� OnPrint() ���Ăяo���O�ɁADC�Ƀv�����^��
 *	�s�N�Z���ɍ��킹���}�b�s���O���[�h���ݒ肳��Ă��܂��B
 *	  �܂�A�v�����^�̗p���̍��[����E�[�܂ł̃h�b�g����1000�ł���΁A
 *	����v���r���[��ʂ̗p�������̍��[����E�[�܂ł̘_���P�ʂ�1000��
 *	��������Ă��܂��B
 *	
 *	@see CaDcdTargetZoomDisplay 
 *	  ���̃I�u�W�F�N�g�Ɋ֘A���� CaDcdTargetZoomDisplay �A�_�v�^�N���X��
 *	�I�u�W�F�N�g�𐶐�����ƁA�f�B�X�v���C�Ɠ��l�̍��W�n�ŕ`����s�����Ƃ�
 *	�ł��܂��B
 *	
 *	<H4>
 *	�y�g�����z
 *	</H4>
 *	
 *	�P�D  CView::OnPrint() �̃I�[�o���C�h�ŁA���̃N���X�̃I�u�W�F�N�g��
 *	�������Ă��������B
 *	  ���̃N���X�̃C���X�^���X�́ACView::OnPrint() �̃I�[�o���C�h�̒���
 *	�������A���̊֐������^�[������܂łɔj�����Ȃ��Ă͂Ȃ�܂���B
 *	  �ʏ�́A�����ϐ��Ƃ��ăC���X�^���X�𐶐����Ă��������B
 *	
 *	�Q�D  ���̃I�u�W�F�N�g�� IfDcDraw �C���^�[�t�F�[�X�ɓn���āA�`���
 *	�s�����Ƃ��ł��܂��B
 *	
 */
class CDcdTargetMfcPrintInfo : public IfDcdTarget 
{
// ********************************
///@name �֘A
// ********************************
///@{
 private:
	/**
	  	�ΏۂƂȂ� DC �B
	 	CView::OnPrint() �̃I�[�o���C�h�̈�����n���Ă��������B
	 
	 	����̏ꍇ�A
	  @code
	    m_pCPrintInfo->m_bPreview = FALSE
	  	m_pDC->GetSafeHdc() = �v�����^��DC
	  	m_pDC->m_hAttribDC = �v�����^��DC
	  @endcode
	 	����v���r���[�̏ꍇ�A
	 
	  @code
	    - m_pCPrintInfo->m_bPreview = TRUE
	  	- m_pDC->GetSafeHdc() = �v���r���[��ʂ�DC
	    - m_pDC->m_hAttribDC = �v�����^��DC
	  @endcode
	 	�ƂȂ�܂��B
	 
	 	���̃I�u�W�F�N�g�̔j���̐Ӗ��� �N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�́Athis��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 */
	CDC*			m_pCDC ;
	
	/**
	 * 	  MFC ����n���ꂽ  CPrintInfo �ł��B
	 *	CView::OnPrint() �̃I�[�o���C�h�̈�����n���Ă��������B
	 *	
	 *	  ���̃N���X�́A CPrintInfo �̓��e��ύX���܂���B
	 *
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��� �N���X���[�U�[�ɂ���܂��B
	 * 	���̃I�u�W�F�N�g�́Athis��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 */
	const CPrintInfo*	m_pCPrintInfo ;
	
///@}
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 * 	  �`��̕K�v�ȗ̈�̍��W�͈́B
	 *	  �`��̈�̍��W�l�́A����̏ꍇ������v���r���[�̏ꍇ���A
	 *	�v�����^�̂P�h�b�g���P�ƂȂ�܂��B
	 *	
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 */
	CdDcdZoneXy	m_zonexyZone ;
	
	
///@}
// --------------------------------
///@name	�����f�[�^
// --------------------------------
///@{
 private:
	/**
	 *	GDI�I�u�W�F�N�g�̑����ƁA�n���h���̑Ώƕ\��ێ����܂��B
	 */
	CGdiCache	m_CGdiCache ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @aram pCDC [in]
	 * 	�ΏۂƂȂ� DC �B
	 *	CView::OnPrint() �̃I�[�o���C�h�̈�����n���Ă��������B
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��� �N���X���[�U�[�ɂ���܂��B
	 * 	���̃I�u�W�F�N�g�́Athis��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 * @param pCPrintInfo [in]
	 * 	  MFC ����n���ꂽ  CPrintInfo �ł��B
	 *	CView::OnPrint() �̃I�[�o���C�h�̈�����n���Ă��������B
	 *	  ���̃N���X�́A CPrintInfo �̓��e��ύX���܂���B\n
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��� �N���X���[�U�[�ɂ���܂��B
	 * 	���̃I�u�W�F�N�g�́Athis��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 */
	CDcdTargetMfcPrintInfo( 
		CDC*			pCDC ,
		const CPrintInfo*	pCPrintInfo ) ;
	virtual ~CDcdTargetMfcPrintInfo() ; 

// ********************************
///@name	IfDcdTarget
// ********************************
///@{
 public:
	/**
	 * @return
	 * 	�`����s��DC���擾���܂��B
	 * 	����HDC�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *
	 *	�y�I�[�o���C�h�z
	 *
	 *	����̏ꍇ�A���̊֐����Ԃ��̂� �v�����^��DC�ł��B
	 *	����v���r���[�̏ꍇ�́A���̊֐����Ԃ��̂́A�v���r���[��ʂ�DC�ł��B
	 *
	 *	����v���r���[�̏ꍇ�́A�v�����^��DC�� getPrinterHdc() �Ŏ擾�ł��܂��B
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
//	CDcdTargetMfcPrintInfo
// ********************************
 public:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	CDC*			getCDC(){	return m_pCDC ;};
	const CPrintInfo*	getCPrintInfo(){	return m_pCPrintInfo ;};

	/**
	 * @return
	 * 	�v�����^��DC���擾���܂��B
	 * 	����HDC�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *
	 *	����̏ꍇ���A����v���r���[�̏ꍇ���A
	 *	���̊֐��̓v�����^��DC��Ԃ��܂��B
	 */
	virtual HDC getPrinterHdc() ;
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 *	�v�����g�v���r���[�Ȃ�^�ł��B
	 */
	virtual bool isPreview() ;
	///@}
	// ********************************
	///@name �f�o�b�O�p�֐�
	// ********************************
	///@{
	/**
	 *	CPrintInfo �̓��e���L�q�����Ǖ�������쐬���܂��B
	 *	
	 *	���̕�����̗p�r�́A�f�o�b�O�Ɍ����܂��B
	 * @param pInfo [in]
	 *	�ΏۂƂȂ� CPrintInfo �I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	CPrintInfo �̓��e���L�q�����Ǖ�����B
	 *	
	 */
	static std::string stringOf( CPrintInfo* pInfo ) ;
	///@}

};

} //namespace DcDrawMfc
} //namespace DcDrawLib

#endif /*CDcdTargetMfcPrintInfo_h*/
