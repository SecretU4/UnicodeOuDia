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
//****************************************************************
//	CdDrawTextFormat.h
//****************************************************************
*/
/** @file */
#ifndef  CdDrawTextFormat_h
#define  CdDrawTextFormat_h

namespace DcDrawLib{
namespace DcdCd{
namespace DcDrawProp{

// ****************************************************************
//	CdDrawTextFormat
// ****************************************************************
/**
 @brief
  テキスト描画の形式を指定する、データクラスです。

  このクラスは、プラットフォームに依存しません。
*/
class CdDrawTextFormat
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**	横方向のテキスト配置	*/
	enum EHolizontal
	{
		/**	左寄せ(既定値)	*/
		H_LEFT ,				//	DT_LEFT 
		/**	中央寄せ	*/
		H_CENTER ,				//	DT_CENTER , 
		/**	右寄せ	*/
		H_RIGHT ,				//	DT_RIGHT
	};
	
	/**	縦方向のテキスト配置	*/
	enum EVertical
	{
		/**	単一行で、上寄せ	*/
		V_SINGLELINT_TOP ,		//	DT_SINGLELINE | DT_TOP
		
		/**	単一行で、中寄せ(既定値)	*/
		V_SINGLELINT_CENTER ,	//	DT_SINGLELINE | DT_VCENTER　(
		
		/**	単一行で、下寄せ	*/
		V_SINGLELINT_BOTTOM ,	//	DT_SINGLELINE | DT_BOTTOM
		
		/**	複数行				*/
		V_MULTILINE ,			//	0

		/**	複数行で、折り返しは単語の途中でも行われます	*/
		V_MULTILINE_WORDBREAK ,	//	DT_WORDBREAK
		
		/**	
			複数行で、折り返しは単語の途中でも行われます
			が DBCS（ダブルバイト文字セットの文字列）で改行されるのを防
			ぎます。このため、改行規則は SBCS 文字列と同じになります。
		*/
		V_NOFULLWIDTHCHARBREAK,	//	DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK
		
	};
	
	
	/**	省略属性	*/
	enum EEllipses
	{
		/**	省略なし(既定値)	*/
		NOELLIPSIS ,			//	0
		/**
		 	文字列の最後の部分が長方形領域に納まり切らない場合、
		 	はみ出す部分が切り取られ、末尾に省略符号（...）が追加されます。
		 	文字列の最後ではない場所にある単語が長方形領域からはみ出す場合は、
		 	省略記号なしで切り取られます。 
		 */
		END_ELLIPSIS ,			//	DT_END_ELLIPSIS
		/**
		 	指定した長方形領域に収まるように、必要に応じてテキストの途中を
		 	省略符号 (...) に置き換えます。円記号（\）が含まれている
		 	テキストの場合、最後の円記号の後ろのテキストが可能な限り保持
		 	されます。 
		 */
		PATH_ELLIPSIS ,			//	DT_PATH_ELLIPSIS
		/**
		 	長方形領域内に納まらない部分がある場合、それを切り取ったうえで、
		 	必ず省略記号（...）を追加します。 
		 */
		WORD_ELLIPSIS ,			//	DT_WORD_ELLIPSIS
	};
	
	
	/**	左書き/右書き	*/
	enum EReading
	{
		/**	左書き(既定値)	*/
		R_LEFT			 ,		//	0
		/**	右書き	*/
		R_RIGHT ,					//	DT_RTLREADING
	};
	
	/**
	 アンパサンド「&」の下線描画指示。

	 アンパサンドをニーモニックプレフィクス文字(下線描画指示)として
	処理するか否かを指定します。
	この機能は、メニューテキストを描画する場合に使用します。
	*/
	enum EAmpersand
	{
		/** & をそのまま描画します。(既定値)  */
		EAmpersand_NoPrefix ,	//DT_NOPREFIX,
		
		/** 
		& の次に & 以外の文字がある場合、 
		& は描画せずに、&の次の文字に下線を付与して描画します。

		& が2つ連続した場合、 & を下線なしで描画します。
		*/
		EAmpersand_NormalPrefix ,	//	0

	};
// ********************************
///@name	属性
// ********************************
///@{
 private:
	/**	
	横方向のテキスト配置。
	既定値はH_LEFT(左寄せ)
	*/
	EHolizontal	m_eHolizontal ;
	
	/**	
	縦方向のテキスト配置。
	既定値は V_SINGLELINT_CENTER (単一行で、中寄せ)
	*/
	EVertical	m_eVertical ;

	/**	
	省略属性。	
	既定値は、NOELLIPSIS 省略なし(既定値)
	*/
	EEllipses	m_eEllipses ;

	/**	
	左書き/右書き。
	既定値は R_LEFT	(左書き)
	*/
	EReading	m_eReading ;

	/**
	アンパサンド「&」の下線描画指示。
	既定値は EAmpersand_NoPrefix 
	*/
	EAmpersand m_eAmpresand ;

	
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
		各属性を設定するコンストラクタです。
	 */
	CdDrawTextFormat( 
		EHolizontal eHolizontal = H_LEFT ,
		EVertical eVertical = V_SINGLELINT_CENTER,
		EEllipses eEllipse = NOELLIPSIS ,
		EReading eReading = R_LEFT ,
		EAmpersand eAmpresand = EAmpersand_NoPrefix ) :
		m_eHolizontal( eHolizontal ) ,
		m_eVertical( eVertical ) ,
		m_eEllipses( eEllipse ) ,
		m_eReading( eReading ) ,
		m_eAmpresand( eAmpresand ) {} ;
		

// ********************************
//	CdDrawTextFormat
// ********************************
 public:
	EHolizontal getHorizontal()const 
	{	return m_eHolizontal ;};
	CdDrawTextFormat& setHorizontal( EHolizontal ev ) 
	{	m_eHolizontal = ev ;	return *this ;};
	EVertical getVertical()const 
	{	return m_eVertical ;};
	CdDrawTextFormat& setVertical( EVertical ev ) 
	{	m_eVertical = ev ;	return *this ;};
	EEllipses getEllipses()const 
	{	return m_eEllipses ;};
	CdDrawTextFormat& setEllipses( EEllipses ev ) 
	{	m_eEllipses = ev ;	return *this ;};
	
	
	EReading getReading()const{	return m_eReading ;};
	CdDrawTextFormat& setReading( EReading ev ) 
	{	m_eReading = ev ;	return *this ;};

	EAmpersand getAmpresand()const{	return m_eAmpresand ;};
	CdDrawTextFormat& setAmpersand( EAmpersand ev )
	{	m_eAmpresand = ev ;	return *this ;};


};

} //namespace DcDrawProp
} //namespace DcdCd
} //namespace DcDrawLib

#endif /*CdDrawTextFormat_h*/

