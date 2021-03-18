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
//	CentDedRessyasyubetsu.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyasyubetsu_h
#define  CentDedRessyasyubetsu_h

#include <string>

#include "DcdCd\DcDrawProp\CdColorProp.h"


// ****************************************************************
//	CentDedRessyasyubetsu
// ****************************************************************
/**
   @brief
  	�y�T�v�z  DiagramEdit �́A�H����ŉ^�s������Ԃ́w��Ԏ�ʁx
  	�P��ނ�\���܂��B
  	
  	  �����Ƃ��āA�w��ʖ��x�ƁA���̗�Ԏ�ʂ�\�����鎞���\�r���[�E
  	�_�C���O�����r���[�ł̕`��F�E���X�^�C����ێ����܂��B
 */
class CentDedRessyasyubetsu
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**
		��Ԑ�(����)�̌`���\���񋓂ł��B
	*/
	enum ESenStyle
	{
		/// ����
		SenStyle_Jissen = 0 ,
		/// �j��
		SenStyle_Hasen ,
		/// �_��
		SenStyle_Tensen ,
		/// ��_����
		SenStyle_Ittensasen ,
	};
	/**
		��Ԑ�(����)�̐��̌`�󑮐���\���P���f�[�^�N���X�B
	*/
	class CdDiagramLineStyle
	{
	private:
		// ********************************
		///@name ����
		// ********************************
		///@{
		/**
	  		�_�C���O�����̐��F�B
		  
	  		�K��l�́A���B
		 */
		CdColorProp	m_colorDiagramSenColor ;

		/**
			�_�C���O�����̐��X�^�C���B
		  
	  		�K��l�́A SenStyle_Jissen
		 */
		ESenStyle	m_eDiagramSenStyle ;
		
		/**
	  		�_�C���O�����̐��̑����B
		  
	  		�_�C���O�����̐��������ł���� true�B
	  		�א��Ȃ� false �ł��B
		  
	  		�K��l�́A false �ł��B
		 */
		bool m_bDiagramSenIsBold ;

	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		CdDiagramLineStyle( 
			const CdColorProp& colorDiagramSenColor ,
			ESenStyle	eDiagramSenStyle ,
			bool bDiagramSenIsBold )
			:
			m_colorDiagramSenColor( colorDiagramSenColor ) ,
			m_eDiagramSenStyle( eDiagramSenStyle ),
			m_bDiagramSenIsBold( bDiagramSenIsBold )
		{};

		CdDiagramLineStyle():
			m_colorDiagramSenColor( CdColorProp( 0 , 0 , 0 ) ),
			m_eDiagramSenStyle( SenStyle_Jissen ),
			m_bDiagramSenIsBold( false )
		{};

		// ********************************
		///@name CdDiagramLineStyle::����
		// ********************************
		///@{
		CdColorProp	getDiagramSenColor()const
		{	return m_colorDiagramSenColor ;};
		void setDiagramSenColor( const CdColorProp value )
		{	m_colorDiagramSenColor = value ;};
		ESenStyle	getDiagramSenStyle()const
		{	return m_eDiagramSenStyle ;};
		void setDiagramSenStyle( ESenStyle value )
		{	m_eDiagramSenStyle = value ;};
		bool	getDiagramSenIsBold()const
		{	return m_bDiagramSenIsBold ;};
		void setDiagramSenIsBold( bool value )
		{	m_bDiagramSenIsBold = value ;};
	};


	/**
		��Ԏ�ʖ��́A��ԉw�����̕��@�̑I������\���񋓂ł��B
	*/
	enum EStopMarkDrawType
	{
		/**
			��ԉw����=��ԉw�𖾎��@
			
			����l�B�_�C���O�����r���[�Œ�ԉw������ON�̏ꍇ�́A
			�Z���Ԓ�ԉw�Ɂ���`�悵�܂��B
		*/
		EStopMarkDrawType_DrawOnStop = 0 ,
		
		/**
			��ԉw����=�������Ȃ�
		
			��ԉw�������s���܂���B
			
			�e�w��ԂȂǁA��ԉw�����̕K�v�̂Ȃ���Ԏ�ʂł��邱�Ƃ�
			�����܂��B
			
			�_�C���O�����r���[�̑�������ԉw����=ON
			(CDcdDiagram::m_eStopMarkDraw==
				CDcdDiagram::EStopMarkDraw_DrawOnBriefStop )
			���s���ꍇ�ł��A���̗�Ԏ�ʂ̗�Ԃɂ́A
			��ԉw�����͍s���܂���B
		*/
		EStopMarkDrawType_Nothing ,

		/**
			���݂͎g���Ă��܂���B�����ɗ\�񂳂�Ă��܂��B
			
			��ԉw����=�ʉ߉w�𖾎�

			�_�C���O�����r���[�Œ�ԉw������ON�̏ꍇ�́A
			�ʉ߉w�ɋL����`�悵�܂��B��ԉw�ւ̕`��͍s���܂���B
		*/
		EStopMarkDrawType_DrawOnPass ,
	};



private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	  	��ʖ��B
	  
	  	�K��l�́A�󕶎���B
	  
	  	���̒l���󕶎���̏ꍇ�A���̃I�u�W�F�N�g�͖����ł��B
	 */
	std::string	m_strSyubetsumei ;
	
	/**
	  	���́i��ʖ��̗��́j�B
	  
	  	�K��l�́A�󕶎���B
	 */
	std::string	m_strRyakusyou ;
	
	/**
	  	�����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)
	  
	  	�K��l�́A���B
	 */
	CdColorProp	m_colorJikokuhyouMojiColor ;

	/**
		�����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g�B
		�͈͂́A 0 �ȏ�A CdDedDispProp::JIKOKUHYOUFONT_COUNT �����ł��B
	
	- 0�F�w�����\�r���[ 1�x
	- 1: �w�����\�r���[ 2�x
	- 2: �w�����\�r���[ 3�x
�@�@- �@�@�@�F
	
	*/
	int m_iJikokuhyouFontIndex ;

	/**
		��Ԑ�(����)�̐��̌`�󑮐��B
	*/
	CdDiagramLineStyle	m_CdDiagramLineStyle ;

	/**
		��Ԏ�ʖ��́A��ԉw�����̕��@�B
		����l�́A EStopMarkDrawType_DrawOnStop �B
	*/
	EStopMarkDrawType m_eStopMarkDrawType ;
	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	   @param strSyubetsumei [in]
	  	��ʖ��B
	   @param strRyakusyou [in]
	  	���́i��ʖ��̗��́j�B
	   @param colorJikokuhyouMojiColor [in]
	  	�����\�����F�B
	   @param colorDiagramSenColor [in] 
	  	�_�C���O�����̐��F�B
	   @param eDiagramSenStyle [in]
	  	�_�C���O�����̐��X�^�C���B
	   @param bDiagramSenIsBold [in]
	  	�_�C���O�����̐��̑����B
	  	�_�C���O�����̐��������ł���� true�B
	  	�א��Ȃ� false �ł��B
	 */
	CentDedRessyasyubetsu( 
			const std::string& strSyubetsumei ,
			const std::string& strRyakusyou ,
			CdColorProp	colorJikokuhyouMojiColor = CdColorProp( 0 , 0 ,0 ), 
			CdColorProp	colorDiagramSenColor = CdColorProp( 0 , 0 , 0 ),
			ESenStyle	eDiagramSenStyle = SenStyle_Jissen ,
			bool bDiagramSenIsBold = false ) :
		m_strSyubetsumei( strSyubetsumei ) ,
		m_strRyakusyou( strRyakusyou ) ,
		m_colorJikokuhyouMojiColor( colorJikokuhyouMojiColor ) , 
		m_iJikokuhyouFontIndex( 0 ) ,
		m_CdDiagramLineStyle( colorDiagramSenColor , eDiagramSenStyle , bDiagramSenIsBold ) ,
		m_eStopMarkDrawType( EStopMarkDrawType_DrawOnStop ){};

	CentDedRessyasyubetsu() :
		m_colorJikokuhyouMojiColor( CdColorProp( 0 , 0 , 0 ) ) , 
		m_iJikokuhyouFontIndex( 0 ) ,
		m_eStopMarkDrawType( EStopMarkDrawType_DrawOnStop ){};



// ********************************
//	CentDedRessyasyubetsu
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	std::string	getSyubetsumei()const{	return 	m_strSyubetsumei ;};
	CentDedRessyasyubetsu& setSyubetsumei( const std::string& value )
	{	m_strSyubetsumei = value ; return *this ; } ;

	std::string	getRyakusyou()const{	return m_strRyakusyou ;};
	CentDedRessyasyubetsu& setRyakusyou( const std::string& value )
	{	m_strRyakusyou = value ; return *this ; } ;
	
	CdColorProp	getJikokuhyouMojiColor()const{
		return m_colorJikokuhyouMojiColor ;};
	CentDedRessyasyubetsu& setJikokuhyouMojiColor( const CdColorProp&	value )
	{	m_colorJikokuhyouMojiColor = value ; return *this ; } ;

	int getJikokuhyouFontIndex()const
	{	return m_iJikokuhyouFontIndex ;};
	CentDedRessyasyubetsu& setJikokuhyouFontIndex( int value )
	{	m_iJikokuhyouFontIndex = value ; return *this ;};

	CdDiagramLineStyle	getCdDiagramLineStyle()const
	{	return m_CdDiagramLineStyle ;};
	void setCdDiagramLineStyle( const CdDiagramLineStyle& value )
	{	m_CdDiagramLineStyle = value ;};
	/// getCdDiagramLineStyle(),getDiagramSenColor() �Ɠ����ł��B�݊����̂��߂Ɏc����Ă��܂��B
	CdColorProp	getDiagramSenColor()const{
		return 	m_CdDiagramLineStyle.getDiagramSenColor() ;};
	/// setCdDiagramLineStyle() �ő�ւł��܂��B�݊����̂��߂Ɏc����Ă��܂��B
	CentDedRessyasyubetsu& setDiagramSenColor( const CdColorProp&	value ){
		m_CdDiagramLineStyle.setDiagramSenColor( value ); return *this ; } ;
	/// getCdDiagramLineStyle(),getDiagramSenStyle() �Ɠ����ł��B�݊����̂��߂Ɏc����Ă��܂��B
	ESenStyle	getDiagramSenStyle()const{
		return m_CdDiagramLineStyle.getDiagramSenStyle() ;};
	/// setCdDiagramLineStyle() �ő�ւł��܂��B�݊����̂��߂Ɏc����Ă��܂��B
	CentDedRessyasyubetsu& setDiagramSenStyle( ESenStyle value ){
		m_CdDiagramLineStyle.setDiagramSenStyle( value ); return *this ;};
	/// getCdDiagramLineStyle(),getDiagramSenIsBold() �Ɠ����ł��B�݊����̂��߂Ɏc����Ă��܂��B
	bool getDiagramSenIsBold()const{ 
		return m_CdDiagramLineStyle.getDiagramSenIsBold() ; };
	/// setCdDiagramLineStyle() �ő�ւł��܂��B�݊����̂��߂Ɏc����Ă��܂��B
	CentDedRessyasyubetsu& setDiagramSenIsBold( bool value ){
		m_CdDiagramLineStyle.setDiagramSenIsBold( value ) ; return *this ;};



	EStopMarkDrawType getStopMarkDrawType()const
	{ return m_eStopMarkDrawType ;};
	CentDedRessyasyubetsu& setStopMarkDrawType( EStopMarkDrawType value )
	{	m_eStopMarkDrawType = value ; return *this ;};

	///@}

	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	@return
		this������( m_strSyubetsumei ���󕶎���)�Ȃ�^�ł��B
	*/
	bool isNull()const{	return m_strSyubetsumei.empty() ;};
	///@}
};


#endif /*CentDedRessyasyubetsu_h*/


