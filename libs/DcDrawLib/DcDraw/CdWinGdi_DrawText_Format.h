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
//****************************************************************
//	CdWinGdi_DrawText_Format.h
//****************************************************************
*/
/** @file */
#ifndef  CdWinGdi_DrawText_Format_h
#define  CdWinGdi_DrawText_Format_h

#include <windows.h>

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CdWinGdi_DrawText_Format
// ****************************************************************
/**
 @brief
 �y�T�v�z
 	Win32 �� DrawText() API�� ���� uFormat �����ɕt�^����鑮���ł��B
	
	���̃N���X�̃I�u�W�F�N�g�́A UINT �ɃL���X�g���邱�Ƃɂ��A
	���� DrawText() �ɓn�����Ƃ��ł��܂��B
*/
class CdWinGdi_DrawText_Format
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**	�������̃e�L�X�g�z�u���w�肷��񋓂ł�	*/
	enum EHolizontal
	{
		/**	���� (����l)	*/
		H_LEFT ,				//	DT_LEFT , 
		/**	������	*/
		H_CENTER ,				//	DT_CENTER , 
		/**	�E��	*/
		H_RIGHT ,				//	DT_RIGHT
	};
	
	/**	�c�����̃e�L�X�g�z�u���w�肷��񋓂ł��B	*/
	enum EVertical
	{
		/**	�P��s�ŁA���	*/
		V_SINGLELINE_TOP ,		//	DT_SINGLELINE | DT_TOP
		
		/**	�P��s�ŁA���� (����l)	*/
		V_SINGLELINE_CENTER ,	//	DT_SINGLELINE | DT_VCENTER
		
		/**	�P��s�ŁA����	*/
		V_SINGLELINE_BOTTOM ,	//	DT_SINGLELINE | DT_BOTTOM
		
		/**	�����s				*/
		V_MULTILINE ,			//	0

		/**	�����s�ŁA�܂�Ԃ��͒P��̓r���ł��s���܂�	*/
		V_MULTILINE_WORDBREAK ,	//	DT_WORDBREAK
		
		/**	
			�����s�ŁA�܂�Ԃ��͒P��̓r���ł��s���܂�
			�� DBCS�i�_�u���o�C�g�����Z�b�g�̕�����j�ŉ��s�����̂�
			���܂��B���̂��߁A���s�K���� SBCS ������Ɠ����ɂȂ�܂��B
		*/
		V_NOFULLWIDTHCHARBREAK,	//	DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK
		
	};
	
	/**	�N���b�s���O�̗L��	*/
	enum EClipping
	{
		/**	�N���b�s���O���s���܂��B (����l)	*/
		C_CLIP , 				//	0
		/**	�N���b�s���O�����܂���B�`�悪���������Ȃ�܂��B	*/
		C_NOCLIP ,				//	DT_NOCLIP
	};
	
	/**	�G�f�B�b�g�R���g���[������	*/
	enum EEditControl
	{
		/**	�G�f�B�b�g�R���g���[�������Ȃ� (����l)	*/
		NOEDITCONTROL ,			//	0
		/**
		  	�G�f�B�b�g�R���g���[������
		  	�����s�G�f�B�b�g�R���g���[�����������Ɠ��������ŕ`�悵�܂��B
		  	���ɁA���ϕ��������G�f�B�b�g�R���g���[���Ɠ������@�Ōv�Z����A
		  	�����I�Ɍ����Ă���Ō�̍s�͕\������܂���B
		 */
		EDITCONTROL ,			//	DT_EDITCONTROL
	};
	
	/**	�ȗ�����	*/
	enum EEllipses
	{
		/**	�ȗ��Ȃ� (����l)	*/
		NOELLIPSIS ,			//	0
		/**
		  	������̍Ō�̕����������`�̈�ɔ[�܂�؂�Ȃ��ꍇ�A
		  	�͂ݏo���������؂����A�����ɏȗ������i...�j���ǉ�����܂��B
		  	������̍Ō�ł͂Ȃ��ꏊ�ɂ���P�ꂪ�����`�̈悩��͂ݏo���ꍇ�́A
		  	�ȗ��L���Ȃ��Ő؂����܂��B 
		 */
		END_ELLIPSIS ,			//	DT_END_ELLIPSIS
		/**
		  	�w�肵�������`�̈�Ɏ��܂�悤�ɁA�K�v�ɉ����ăe�L�X�g�̓r����
		  	�ȗ����� (...) �ɒu�������܂��B�~�L���i\�j���܂܂�Ă���
		  	�e�L�X�g�̏ꍇ�A�Ō�̉~�L���̌��̃e�L�X�g���\�Ȍ���ێ�
		  	����܂��B 
		 */
		PATH_ELLIPSIS ,			//	DT_PATH_ELLIPSIS
		/**
		  	�����`�̈���ɔ[�܂�Ȃ�����������ꍇ�A�����؂����������ŁA
		  	�K���ȗ��L���i...�j��ǉ����܂��B 
		 */
		WORD_ELLIPSIS ,			//	DT_WORD_ELLIPSIS
	};
	
	
	/**	�O�����f�B���O�������Ƃ��Ċ܂߂�	*/
	enum EExternalLeading
	{
		/**	�ݒ�Ȃ� (����l) */
		NOEXTERNALLEADING ,		//	0
		/**
	  	�s�̍����ɁA�O�����f�B���O�̍����i�e�L�X�g�̍s�ԂƂ��ēK�؂ȍ����j
	  	�����Z���܂��B�ʏ�A�O�����f�B���O�̓e�L�X�g�s�̍�����
	  	�������܂���B
		 */
		EXTERNALLEADING ,		//	DT_EXTERNALLEADING
	};
	
	/**	������/�E����	*/
	enum EReading
	{
		/**	������ (����l)	*/
		R_LEFT			 ,		//	0
		/**	�E����	*/
		R_RIGHT ,					//	DT_RTLREADING
	};
	
	/**	�����L��	*/
	enum EPrefix
	{
		/**	�ʏ폈��	*/
		NORMAL_PREFIX ,			//	0
		/**
	  	�v���t�B�b�N�X�����̏������s��Ȃ��悤�ɂ��܂��B (����l)
		
		�ʏ�́A
	  	�j�[���j�b�N�v���t�B�N�X�����́u&�v�́A���̎��ɂ��镶���ɉ����i_�j
	  	��t���ĕ\������Ƃ̖��߂ł���Ɖ��߂���A�j�[���j�b�N
	  	�v���t�B�b�N�X�����́u&&�v�́A1 �́u&�v��\������Ƃ̖��߂�
	  	����Ɖ��߂���܂��BDT_NOPREFIX ���w�肷��ƁA���̏������s���Ȃ�
	  	�Ȃ�܂��B
		 */
		NOPREFIX ,				//	DT_NOPREFIX 
		/**
	  	�e�L�X�g�ɖ��ߍ��܂�Ă���v���t�B�b�N�X�Ƃ��ẴA���p�T���h�i&�j
	  	�𖳎����܂��B���ɑ��������ɉ������{����Ȃ��Ȃ�܂��B�������A
	  	���̑��̃j�[���j�b�N�v���t�B�b�N�X�����́A�ʏ�ǂ��菈������܂��B
		 */
		HIDEPREFIX , 			//	DT_HIDEPREFIX 
		/**
	  	�A���p�T���h�v���t�B�b�N�X�����i&�j�̌��̕���������ʒu��
	  	����������`�悵�܂��B��������̂��̑��̕����͈�ؕ`�悵�܂���B
		 */
		PREFIXONLY , 			//	DT_PREFIXONLY 
	};

	/**	�e�L�X�g�̃T�C�Y�v�Z(�`��ɂ͊֌W����܂���)	*/
	enum ECalcrect
	{
		/**	
		 	���ۂ̕`����s���܂��B (����l)	
		 */
		NOCALCRECT , 			//	0
		/**	
		 	�e�L�X�g�T�C�Y���v�Z���܂��B�`��͍s���܂���B	
		 */
		CALCRECT ,				//	DT_CALCRECT
		/**
		  	�e�L�X�g�T�C�Y���v�Z���܂��B�`��͍s���܂���B	
		  	�e�L�X�g�̕\���T�C�Y���v�Z����ۂɃV�X�e���t�H���g���g�p���܂��B
		 */
		CALCRECT_INTERNAL ,		//	DT_CALCRECT | DT_INTERNAL
	};
	/**	�ȗ��e�L�X�g�ɂ���Ď��ۂɕ`�悳�ꂽ��������擾(�`��ɂ͊֌W����܂���)	*/
	enum EModifystring
	{
		/**	
		���ۂɕ`�悳�ꂽ������̎擾���s���܂���B(����l)
		 */
		NOMODIFYSTEING ,		//	0
		/**	
	 	lpString �p�����[�^���w���o�b�t�@�ɁA
		���ۂɕ\�����ꂽ��������i�[���܂��B
		DT_END_ELLIPSIS �t���O�܂��� 
		DT_PATH_ELLIPSIS �t���O���w�肵���Ƃ��ɂ����Ӗ��������܂���B
		 */
		MODIFYSTRING ,			//	DT_MODIFYSTRING
	};
	

// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
		Win32 �� DrawText() API�� uFormat �����ɕt�^����鑮���ł��B
	 */
	UINT	m_uiDrawTextFormat ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	  @param uiForamt [in]
	  	Win32 �� DrawText() API�� uFormat �����ɕt�^����鑮���ł��B
	 */
	CdWinGdi_DrawText_Format( UINT uiFormat ) ;
	/**
	 	�e������ݒ肷��R���X�g���N�^�ł��B
	  @param iTabstop [in]
	  	TabStop�l�́A�ȉ��̂悤�ɉ��߂��܂��B
	  	-	0: �^�u�̓W�J���s���܂���B	
	  	-	1�ȏ�:�^�u�����w�肵�܂��B	
	  	-	-1:�f�t�H���g�̃^�u���Ń^�u��W�J���܂��B	
	 */
	CdWinGdi_DrawText_Format( 
		EHolizontal eHolizontal = H_LEFT ,
		EVertical eVertical = V_SINGLELINE_CENTER,
		EClipping eClipping = C_CLIP ,
		EEditControl eEditControl = NOEDITCONTROL ,
		EEllipses eEllipse = NOELLIPSIS ,
		int iTabstop = 0 ,
		EExternalLeading eExternalLeading = NOEXTERNALLEADING ,
		EReading eReading = R_LEFT ,
		EPrefix ePrefix = NOPREFIX ,
		ECalcrect eCalcrect = NOCALCRECT ,
		EModifystring eModifystring = NOMODIFYSTEING );

// ********************************
//	CdWinGdi_DrawText_Format
// ********************************
 public:
	EHolizontal getHorizontal()const ;
	CdWinGdi_DrawText_Format& setHorizontal( EHolizontal ev ) ;
	EVertical getVertical()const ;
	CdWinGdi_DrawText_Format& setVertical( EVertical ev ) ;
	EClipping getClipping()const ;
	CdWinGdi_DrawText_Format& setClipping( EClipping ev ) ;
	EEditControl getEditControl()const ;
	CdWinGdi_DrawText_Format& setEditControl( EEditControl ev ) ;
	EEllipses getEllipses()const ;
	CdWinGdi_DrawText_Format& setEllipses( EEllipses ev ) ;
	
	/**
	 @return 
	 	TabStop�l��Ԃ��܂��B
	
	 	TabStop�l�́A�ȉ��̂悤�ɉ��߂��܂��B
	 	-	0: �^�u�̓W�J���s���܂���B	
	 	-	1�ȏ�:�^�u�����w�肵�܂��B	
	 	-	-1:�f�t�H���g�̃^�u���Ń^�u��W�J���܂��B	
	*/
	int getTabStop()const ;
	/**
	 	TabStop�l��ݒ肵�܂��B
	 @param ev [in]
	 	TabStop�l�́A�ȉ��̂悤�ɉ��߂��܂��B
	 	-	0: �^�u�̓W�J���s���܂���B	
	 	-	1�ȏ�:�^�u�����w�肵�܂��B	
	 	-	-1:�f�t�H���g�̃^�u���Ń^�u��W�J���܂��B	
	*/
	CdWinGdi_DrawText_Format& setTabStop( int ev );
	
	EExternalLeading getExternalLeading()const ;
	CdWinGdi_DrawText_Format& setExternalLeading( EExternalLeading ev ) ;
	EReading getReading()const ;
	CdWinGdi_DrawText_Format& setReading( EReading ev ) ;
	EPrefix getPrefix()const ;
	CdWinGdi_DrawText_Format& setPrefix( EPrefix ev ) ;

	ECalcrect getCalcrect()const ;
	CdWinGdi_DrawText_Format& setCalcrect( ECalcrect ev );
	EModifystring getModifystring()const ;
	CdWinGdi_DrawText_Format& setModifystring( EModifystring ev ) ;
	
	/**
	@return
	 	Win32 �� DrawText() API�� ���� uFormat �����ɕt�^�����l��
	 	�Ԃ��܂��B
	*/
	UINT getFormat()const ;

	CdWinGdi_DrawText_Format& setFormat( UINT uiFormat ) ;
	
	/**
	 	getDrawTextFormat() �Ɠ����ł��B
	 */
	operator UINT()const{	return getFormat() ; } ;
	/**
	 	setDrawTextFormat() �Ɠ����ł��B
	 */
	CdWinGdi_DrawText_Format& operator=( UINT uiFormat ){
		return ( setFormat( uiFormat ) ) ; } ;
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*CdWinGdi_DrawText_Format_h*/

