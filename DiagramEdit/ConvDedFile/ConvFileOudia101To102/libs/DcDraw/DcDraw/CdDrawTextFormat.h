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

#include <windows.h>

// ****************************************************************
//	CdDrawTextFormat
// ****************************************************************
/**
* @brief
* 【概要】
* 	Win32 の DrawText() APIの 引数 uFormat 引数に付与される属性です。
*	
*	このクラスのオブジェクトは、 UINT にキャストすることにより、
*	直接 DrawText() に渡すことができます。
*/
class CdDrawTextFormat
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**	横方向のテキスト配置を指定する列挙です	*/
	enum EHolizontal
	{
		/**	左寄せ	*/
		H_LEFT ,				//	DT_LEFT , 
		/**	中央寄せ	*/
		H_CENTER ,				//	DT_CENTER , 
		/**	右寄せ	*/
		H_RIGHT ,				//	DT_RIGHT
	};
	
	/**	縦方向のテキスト配置を指定する列挙です。	*/
	enum EVertical
	{
		/**	単一行で、上寄せ	*/
		V_SINGLELINT_TOP ,		//	DT_SINGLELINE | DT_TOP
		
		/**	単一行で、中寄せ	*/
		V_SINGLELINT_CENTER ,	//	DT_SINGLELINE | DT_VCENTER
		
		/**	単一行で、下寄せ	*/
		V_SINGLELINT_BOTTOM ,	//	DT_SINGLELINE | DT_BOTTOM
		
		/**	複数行				*/
		V_MULTILINE ,			//	0

		/**	複数行で、折り返しは単語の途中でも行われます	*/
		V_MULTILINE_WORDBREAK ,	//	DT_WORDBREAK
		
		/**	
		*	複数行で、折り返しは単語の途中でも行われます
		*	が DBCS（ダブルバイト文字セットの文字列）で改行されるのを
		*	ぎます。このため、改行規則は SBCS 文字列と同じになります。
		*/
		V_NOFULLWIDTHCHARBREAK,	//	DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK
		
	};
	
	/**	クリッピングの有無	*/
	enum EClipping
	{
		/**	クリッピングを行います。	*/
		C_CLIP , 				//	0
		/**	クリッピングをしません。描画が多少速くなります。	*/
		C_NOCLIP ,				//	DT_NOCLIP
	};
	
	/**	エディットコントロール属性	*/
	enum EEditControl
	{
		/**	エディットコントロール属性なし	*/
		NOEDITCONTROL ,			//	0
		/**
		 * 	エディットコントロール属性
		 * 	複数行エディットコントロールがもつ特性と同じ特性で描画します。
		 * 	特に、平均文字幅がエディットコントロールと同じ方法で計算され、
		 * 	部分的に見えている最後の行は表示されません。
		 */
		EDITCONTROL ,			//	DT_EDITCONTROL
	};
	
	/**	省略属性	*/
	enum EEllipses
	{
		/**	省略なし	*/
		NOELLIPSIS ,			//	0
		/**
		 * 	文字列の最後の部分が長方形領域に納まり切らない場合、
		 * 	はみ出す部分が切り取られ、末尾に省略符号（...）が追加されます。
		 * 	文字列の最後ではない場所にある単語が長方形領域からはみ出す場合は、
		 * 	省略記号なしで切り取られます。 
		 */
		END_ELLIPSIS ,			//	DT_END_ELLIPSIS
		/**
		 * 	指定した長方形領域に収まるように、必要に応じてテキストの途中を
		 * 	省略符号 (...) に置き換えます。円記号（\）が含まれている
		 * 	テキストの場合、最後の円記号の後ろのテキストが可能な限り保持
		 * 	されます。 
		 */
		PATH_ELLIPSIS ,			//	DT_PATH_ELLIPSIS
		/**
		 * 	長方形領域内に納まらない部分がある場合、それを切り取ったうえで、
		 * 	必ず省略記号（...）を追加します。 
		 */
		WORD_ELLIPSIS ,			//	DT_WORD_ELLIPSIS
	};
	
	
	/**	外部レディングを高さとして含める	*/
	enum EExternalLeading
	{
		/**	設定なし	*/
		NOEXTERNALLEADING ,		//	0
		/**
		 * 	行の高さに、外部レディングの高さ（テキストの行間として適切な高さ）
		 * 	を加算します。通常、外部レディングはテキスト行の高さに
		 * 	加えられません。
		 */
		EXTERNALLEADING ,		//	DT_EXTERNALLEADING
	};
	
	/**	左書き/右書き	*/
	enum EReading
	{
		/**	左書き	*/
		R_LEFT			 ,		//	0
		/**	右書き	*/
		R_RIGHT ,					//	DT_RTLREADING
	};
	
	/**	下線記号	*/
	enum EPrefix
	{
		/**	通常処理	*/
		NORMAL_PREFIX ,			//	0
		/**
		 * 	プリフィックス文字の処理を行わないようにします。通常は、
		 * 	ニーモニックプレフィクス文字の「&」は、その次にくる文字に下線（_）
		 * 	を付けて表示せよとの命令であると解釈され、ニーモニック
		 * 	プレフィックス文字の「&&」は、1 つの「&」を表示せよとの命令で
		 * 	あると解釈されます。DT_NOPREFIX を指定すると、この処理が行われなく
		 * 	なります。
		 */
		NOPREFIX ,				//	DT_NOPREFIX 
		/**
		 * 	テキストに埋め込まれているプレフィックスとしてのアンパサンド（&）
		 * 	を無視します。後ろに続く文字に下線が施されなくなります。ただし、
		 * 	その他のニーモニックプレフィックス文字は、通常どおり処理されます。
		 *
		 * @attention
		 *	このフラグが利用可能なWindowsのバージョンは限定されます( Windows 2000/XP)。
		 *	現在のところ、この値はサポートしていません。
		HIDEPREFIX , 			//	DT_HIDEPREFIX 
		 */
		/**
		 * 	アンパサンドプレフィックス文字（&）の後ろの文字がくる位置の
		 * 	下線だけを描画します。文字列内のその他の文字は一切描画しません。
		 *
		 * @attention
		 *	このフラグが利用可能なWindowsのバージョンは限定されます( Windows 2000/XP)。
		 *	現在のところ、この値はサポートしていません。
		PREFIXONLY , 			//	DT_PREFIXONLY 
		 */
	};
// ********************************
///@name	属性
// ********************************
///@{
 private:
	/**
	 * 	Win32 の DrawText() APIの uFormat 引数に付与される属性です。
	 */
	UINT	m_uiDrawTextFormat ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param uiForamt [in]
	 * 	Win32 の DrawText() APIの uFormat 引数に付与される属性です。
	 */
	CdDrawTextFormat( UINT uiFormat ) ;
	/**
	 *	各属性を設定するコンストラクタです。
	 * @param iTabstop [in]
	 * 	TabStop値は、以下のように解釈します。
	 * 	-	0: タブの展開を行いません。	
	 * 	-	1以上:タブ幅を指定します。	
	 * 	-	-1:デフォルトのタブ幅でタブを展開します。	
	 */
	CdDrawTextFormat( 
		EHolizontal eHolizontal = H_LEFT ,
		EVertical eVertical = V_SINGLELINT_CENTER,
		EClipping eClipping = C_CLIP ,
		EEditControl eEditControl = NOEDITCONTROL ,
		EEllipses eEllipse = NOELLIPSIS ,
		int iTabstop = 0 ,
		EExternalLeading eExternalLeading = NOEXTERNALLEADING ,
		EReading eReading = R_LEFT ,
		EPrefix ePrefix = NORMAL_PREFIX ) ;

// ********************************
//	CdDrawTextFormat
// ********************************
 public:
	EHolizontal getHorizontal()const ;
	CdDrawTextFormat& setHorizontal( EHolizontal ev ) ;
	EVertical getVertical()const ;
	CdDrawTextFormat& setVertical( EVertical ev ) ;
	EClipping getClipping()const ;
	CdDrawTextFormat& setClipping( EClipping ev ) ;
	EEditControl getEditControl()const ;
	CdDrawTextFormat& setEditControl( EEditControl ev ) ;
	EEllipses getEllipses()const ;
	CdDrawTextFormat& setEllipses( EEllipses ev ) ;
	
	/**
	* @return 
	* 	TabStop値を返します。
	*
	* 	TabStop値は、以下のように解釈します。
	* 	-	0: タブの展開を行いません。	
	* 	-	1以上:タブ幅を指定します。	
	* 	-	-1:デフォルトのタブ幅でタブを展開します。	
	*/
	int getTabStop()const ;
	/**
	* 	TabStop値を設定します。
	* @param ev [in]
	* 	TabStop値は、以下のように解釈します。
	* 	-	0: タブの展開を行いません。	
	* 	-	1以上:タブ幅を指定します。	
	* 	-	-1:デフォルトのタブ幅でタブを展開します。	
	*/
	CdDrawTextFormat& setTabStop( int ev );
	
	EExternalLeading getExternalLeading()const ;
	CdDrawTextFormat& setExternalLeading( EExternalLeading ev ) ;
	EReading getReading()const ;
	CdDrawTextFormat& setReading( EReading ev ) ;
	EPrefix getPrefix()const ;
	CdDrawTextFormat& setPrefix( EPrefix ev ) ;
	
	UINT getDrawTextFormat()const ;
	CdDrawTextFormat& setDrawTextFormat( UINT uiFormat ) ;
	
	/**
	 *	getDrawTextFormat() と等価です。
	 */
	operator UINT()const{	return getDrawTextFormat() ; } ;
	/**
	 *	setDrawTextFormat() と等価です。
	 */
	CdDrawTextFormat& operator=( UINT uiFormat ){
		return ( setDrawTextFormat( uiFormat ) ) ; } ;
};
#endif /*CdDrawTextFormat_h*/

