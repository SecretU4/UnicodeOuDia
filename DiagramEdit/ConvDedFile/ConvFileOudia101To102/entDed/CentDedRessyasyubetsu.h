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


(訳: 

	OuDia - 列車時刻表をもとに、ダイヤグラムを描画するWin32アプリケーシ
ョン。

Copyright (C) 2006-2017 take-okm 

このプログラムはフリーソフトウェアです。あなたはこれを、フリーソフトウェア財
団によって発行されたGNU 一般公衆利用許諾書(バージョン3か、それ以降のバージョ
ンのうちどれか)が定める条件の下で再頒布または改変 することができます。

このプログラムは有用であることを願って頒布されますが、*全くの無保証 *です。
商業可能性の保証や特定目的への適合性は、言外に示されたものも 含め、全く存在
しません。詳しくはGNU 一般公衆利用許諾書をご覧ください。

あなたはこのプログラムと共に、GNU 一般公衆利用許諾書のコピーを一部 受け取っ
ているはずです。もし受け取っていなければ、<http://www.gnu.org/licenses/> を
ご覧ください。

)

  加えて、特別な例外として、take-okm はこのプログラムのコードを 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  あるいは "MFC Version 9.0" と同じライセンスが適用された
  "MFC Version 9.0" の改変されたバージョン)とリンクし、
  リンクされた両者を含む結合著作物を頒布する許可を与えます。
  あなたは "MFC" 以外で使われているすべて
  のコードに関しては全面的にGNU一般公衆利用許諾契約書に従わなければ
  なりません。あなたがこのファイルを改変したならば、あなたはこの例外
  をあなたのバージョンのファイルに引き続き設けることもできますが、そ
  うする義務はありません。もし例外を設けたくなければ、この例外条項を
  あなたのバージョンからは削除してください。)
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
  	【概要】  DiagramEdit の、路線上で運行される列車の『列車種別』
  	１種類を表します。
  	
  	  属性として、『種別名』と、その列車種別を表示する時刻表ビュー・
  	ダイヤグラムビューでの描画色・線スタイルを保持します。
 */
class CentDedRessyasyubetsu
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**
		列車線(直線)の形状を表す列挙です。
	*/
	enum ESenStyle
	{
		/// 実線
		SenStyle_Jissen = 0 ,
		/// 破線
		SenStyle_Hasen ,
		/// 点線
		SenStyle_Tensen ,
		/// 一点鎖線
		SenStyle_Ittensasen ,
	};
	/**
		列車線(直線)の線の形状属性を表す単純データクラス。
	*/
	class CdDiagramLineStyle
	{
	private:
		// ********************************
		///@name 属性
		// ********************************
		///@{
		/**
	  		ダイヤグラムの線色。
		  
	  		規定値は、黒。
		 */
		CdColorProp	m_colorDiagramSenColor ;

		/**
			ダイヤグラムの線スタイル。
		  
	  		規定値は、 SenStyle_Jissen
		 */
		ESenStyle	m_eDiagramSenStyle ;
		
		/**
	  		ダイヤグラムの線の太さ。
		  
	  		ダイヤグラムの線が太線であれば true。
	  		細線なら false です。
		  
	  		規定値は、 false です。
		 */
		bool m_bDiagramSenIsBold ;

	public:
		// ********************************
		//	コンストラクタ
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
		///@name CdDiagramLineStyle::属性
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
		列車種別毎の、停車駅明示の方法の選択肢を表す列挙です。
	*/
	enum EStopMarkDrawType
	{
		/**
			停車駅明示=停車駅を明示　
			
			既定値。ダイヤグラムビューで停車駅明示がONの場合は、
			短時間停車駅に○を描画します。
		*/
		EStopMarkDrawType_DrawOnStop = 0 ,
		
		/**
			停車駅明示=明示しない
		
			停車駅明示を行いません。
			
			各駅停車など、停車駅明示の必要のない列車種別であることを
			示します。
			
			ダイヤグラムビューの属性が停車駅明示=ON
			(CDcdDiagram::m_eStopMarkDraw==
				CDcdDiagram::EStopMarkDraw_DrawOnBriefStop )
			を行う場合でも、この列車種別の列車には、
			停車駅明示は行われません。
		*/
		EStopMarkDrawType_Nothing ,

		/**
			現在は使われていません。将来に予約されています。
			
			停車駅明示=通過駅を明示

			ダイヤグラムビューで停車駅明示がONの場合は、
			通過駅に記号を描画します。停車駅への描画は行われません。
		*/
		EStopMarkDrawType_DrawOnPass ,
	};



private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	  	種別名。
	  
	  	規定値は、空文字列。
	  
	  	この値が空文字列の場合、このオブジェクトは無効です。
	 */
	std::string	m_strSyubetsumei ;
	
	/**
	  	略称（種別名の略称）。
	  
	  	規定値は、空文字列。
	 */
	std::string	m_strRyakusyou ;
	
	/**
	  	時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)
	  
	  	規定値は、黒。
	 */
	CdColorProp	m_colorJikokuhyouMojiColor ;

	/**
		時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント。
		範囲は、 0 以上、 CdDedDispProp::JIKOKUHYOUFONT_COUNT 未満です。
	
	- 0：『時刻表ビュー 1』
	- 1: 『時刻表ビュー 2』
	- 2: 『時刻表ビュー 3』
　　- 　　　：
	
	*/
	int m_iJikokuhyouFontIndex ;

	/**
		列車線(直線)の線の形状属性。
	*/
	CdDiagramLineStyle	m_CdDiagramLineStyle ;

	/**
		列車種別毎の、停車駅明示の方法。
		既定値は、 EStopMarkDrawType_DrawOnStop 。
	*/
	EStopMarkDrawType m_eStopMarkDrawType ;
	///@}
 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	   @param strSyubetsumei [in]
	  	種別名。
	   @param strRyakusyou [in]
	  	略称（種別名の略称）。
	   @param colorJikokuhyouMojiColor [in]
	  	時刻表文字色。
	   @param colorDiagramSenColor [in] 
	  	ダイヤグラムの線色。
	   @param eDiagramSenStyle [in]
	  	ダイヤグラムの線スタイル。
	   @param bDiagramSenIsBold [in]
	  	ダイヤグラムの線の太さ。
	  	ダイヤグラムの線が太線であれば true。
	  	細線なら false です。
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
	///@name 属性
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
	/// getCdDiagramLineStyle(),getDiagramSenColor() と等価です。互換性のために残されています。
	CdColorProp	getDiagramSenColor()const{
		return 	m_CdDiagramLineStyle.getDiagramSenColor() ;};
	/// setCdDiagramLineStyle() で代替できます。互換性のために残されています。
	CentDedRessyasyubetsu& setDiagramSenColor( const CdColorProp&	value ){
		m_CdDiagramLineStyle.setDiagramSenColor( value ); return *this ; } ;
	/// getCdDiagramLineStyle(),getDiagramSenStyle() と等価です。互換性のために残されています。
	ESenStyle	getDiagramSenStyle()const{
		return m_CdDiagramLineStyle.getDiagramSenStyle() ;};
	/// setCdDiagramLineStyle() で代替できます。互換性のために残されています。
	CentDedRessyasyubetsu& setDiagramSenStyle( ESenStyle value ){
		m_CdDiagramLineStyle.setDiagramSenStyle( value ); return *this ;};
	/// getCdDiagramLineStyle(),getDiagramSenIsBold() と等価です。互換性のために残されています。
	bool getDiagramSenIsBold()const{ 
		return m_CdDiagramLineStyle.getDiagramSenIsBold() ; };
	/// setCdDiagramLineStyle() で代替できます。互換性のために残されています。
	CentDedRessyasyubetsu& setDiagramSenIsBold( bool value ){
		m_CdDiagramLineStyle.setDiagramSenIsBold( value ) ; return *this ;};



	EStopMarkDrawType getStopMarkDrawType()const
	{ return m_eStopMarkDrawType ;};
	CentDedRessyasyubetsu& setStopMarkDrawType( EStopMarkDrawType value )
	{	m_eStopMarkDrawType = value ; return *this ;};

	///@}

	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	@return
		thisが無効( m_strSyubetsumei が空文字列)なら真です。
	*/
	bool isNull()const{	return m_strSyubetsumei.empty() ;};
	///@}
};


#endif /*CentDedRessyasyubetsu_h*/


