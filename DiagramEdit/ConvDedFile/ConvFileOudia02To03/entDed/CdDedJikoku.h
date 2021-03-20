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
//	CdDedJikoku.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDedJikoku_h
#define  CdDedJikoku_h
#include <string>
using namespace std ;
// ****************************************************************
//	CdDedJikoku
// ****************************************************************
/**
 * @brief
 * 【概要】
 *	  秒単位の時刻を表す単純データクラスです。
 *	
 *	  日付の概念はありません。
 *	  一日の間の、00:00 からの２４時間の時刻を表します。
 *	  00:00以前・24:00以降の時刻を指定した場合は、サイクリックした値を
 *	保持します。
 *	  たとえば、このクラスのオブジェクトに 25:00 を設定しようとすると、
 *	オブジェクトは 1:00 を保持します。
 *	
 *	  このクラスは、内部的には 00:00 からの経過秒数を属性 m_iTotalSeconds 
 *	で保持します。時・分・秒は、このクラスの派生属性として位置付けられます。
 *
 *	  このクラスは、『Null状態』を持つことができます。これは、
 *	「this が有効な時刻を保持していない」ことを示す値です。
 *
 *	このクラスが保持する時刻は、 encode() で文字列化することができます。
 *	\n(例)  "10:30:45"
 *	\mまた、encode() で作成した文字列を、 deocde() で解釈することが
 *	できます。
 */
class CdDedJikoku
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/** encode() による文字列化の形式を指定するビットです */
	enum EFormat{
		/** 時：分：秒 の間のコロン ":" を出力しません */
		Format_NoColon = 1 ,
		/** 時が 00 から 09 の場合、10の位の "0" を削除します。 */
		Format_HourZeroToNone = 2 ,
		/** 
		 *	時が 00 から 09 の場合、10の位の "0" をスペースにします。 
		 *
		 *	Format_HourZeroToNone と Format_HourZeroToSpace は
		 *	排他的です。
		 */
		Format_HourZeroToSpace = 4 ,
		/** 秒を出力しません */
		Format_NoSecond = 8 ,
	};

// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	デフォルトの、文字列の書式のオプションを指定します。
	 *	この値はビットごとに意味を持ちます。
	 *	ビットの意味は、 EFormat を参照してください。
	 *
	 *	この値は、引数を指定しないで encode() を利用した場合に
	 *	適用されます。 
	 */
	static unsigned int m_iFmt  ;

	/**
	 *	 00:00 からの経過秒数を保持します。
	 *	有効な値の範囲は、 0 以上 24*60*60 未満
	 *	( 0:00 以上 24:00 未満)です。
	 *
	 *	ただし、『Null状態』のときは、-1 となります。
	 *	デフォルトコンストラクタでは、『Null状態』とします。
	 */
	int	m_iTotalSeconds ;
///@}

// --------------------------------
///@name 下請関数
// --------------------------------
///@{
 protected:
	/**
	 *	経過秒数を正規化します。
	 *
	 *	値を 0 以上 24*60*60 未満
	 *	( 0:00 以上 24:00 未満)とします。
	 *	
	 * @param iTotalSeconds [in]
	 *	正規化前の経過秒数を指定してください。
	 *	負の数でもかまいません。
	 *	\n	-1 は、『Null状態』とはみなしません。
	 * @return
	 *	正規化後の値を返します。
	 * 
	 *	（例）
	 *
	 *	- iTotalSeconds = -1 の場合の戻り値は、 23:59:59 
	 *	- iTotalSeconds = 24*60*60 の場合の戻り値は、 0  
	 */
	static int adjustTotalSeconds( int iTotalSeconds ) ;

///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 *	『Null状態』に初期化します。
	 */
	CdDedJikoku() ;
	
	/**
	 * @param iTotalSeconds [in]
	 *	 00:00 からの経過秒数を保持します。
	 *	有効な値の範囲は、 0 以上 24*60*60 未満です。
	 *	\nただし、『Null状態』のときは、-1 となります。
	 */
	CdDedJikoku( int iTotalSeconds ) ;
	
	/**
	 * @param iHour [in]
	 *	時。範囲は 0 以上 24 未満。
	 * @param iMinute [in]
	 *	分。範囲は 0 以上 60 未満。
	 * @param iSecond [in]
	 *	秒。範囲は 0 以上 60 未満。
	 */
	CdDedJikoku( int iHour , int iMinute , int iSecond = 0 ) ;

	/**
	 *	時刻文字列を使って初期化します。
	 * @param value [in]
	 *	時刻文字列を指定してください。
	 *	
	 * (例)時刻文字列の例
	 *	-	"13:15:45"
	 *	-	"13:15"
	 *	-	"131545"
	 *	-	"1315"
	 *	-	"9:15:45"
	 *	-	"9:15"
	 *	-	"91545"
	 *	-	"915"
	 */
	CdDedJikoku( const string& strTime ) ;

// ********************************
//	CdDedJikoku
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	static unsigned int getFmt(){return m_iFmt  ;};
	static void setFmt( unsigned int value ){
		m_iFmt = value ; };

	int getTotalSeconds()const{	return m_iTotalSeconds ; } ;
	CdDedJikoku& setTotalSeconds( int value ) ;
	
	/**
	 * @return
	 *	時。
	 * @attention
	 *	this が 『Null状態』の場合は、0を返します。
	 */
	int getHour()const{	return m_iTotalSeconds / ( 60 * 60 )  ; } ;
	
	/**
	 * @return
	 *	分。
	 * @attention
	 *	this が 『Null状態』の場合は、0を返します。
	 */
	int getMinute()const{	return m_iTotalSeconds / ( 60 ) % ( 60 )  ; } ;
	
	/**
	 * @return
	 *	秒。
	 * @attention
	 *	this が 『Null状態』の場合は、0を返します。
	 */
	int getSecond()const{	return m_iTotalSeconds % ( 60 )  ; } ;
	
	/**
	 *	時刻を、設定します。
	 * @param iHour [in]
	 *	時。範囲は 0 以上 24 未満。
	 * @param iMinute [in]
	 *	分。範囲は 0 以上 60 未満。
	 * @param iSecond [in]
	 *	秒。範囲は 0 以上 60 未満。
	 */
	CdDedJikoku& setTime( int iHour , int iMinute , int iSecond = 0 ) ;
	
	/**
	 * @return
	 *	this が『Null状態』なら真を返します。
	 */
	bool isNull()const{	return m_iTotalSeconds == -1 ; } ;

	/**
	 *	this を『Null状態』とします。
	 */
	CdDedJikoku& setNull() ;
	
	///@}
	
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	 *	２つの時刻を、比較します。
	 * @param value [in]
	 *	比較対象のオブジェクトを指定してください。
	 * @return
	 *	this - value を行った結果の符号を返します。
	 *	-	+1 ;	//	this > value。
	 *				//	または、 this が非『Null状態』で value が 『Null状態』
	 *	-	0 ;		//	this == value。
	 *				//	または、 this も value も 『Null状態』
	 *	-	-1 ;	//	this < value。
	 *				//	または、 this が『Null状態』で value が 非『Null状態』
	 */
	int compare( const CdDedJikoku& value )const ;
	
	/**	compare() と等価です。	 */
	bool operator>( const CdDedJikoku& value )const{
		return ( compare( value ) == 1 ) ; } ;
	/**	compare() と等価です。	 */
	bool operator>=( const CdDedJikoku& value )const{
		return ( compare( value ) != -1  ) ; } ;
	/**	compare() と等価です。	 */
	bool operator==( const CdDedJikoku& value )const{
		return ( compare( value ) == 0 ) ; } ;
	/**	compare() と等価です。	 */
	bool operator<=( const CdDedJikoku& value )const{
		return ( compare( value ) != 1  ) ; } ;
	/**	compare() と等価です。	 */
	bool operator<( const CdDedJikoku& value )const{
		return ( compare( value ) == -1 ) ; } ;

	/**
	 *	this が保持している時刻に対して、秒数を加算します。
	 * @param value [in]
	 *	加算する秒数を指定してください。
	 *	負の数を指定することもできます。
	 * @attention
	 *	this が 『Null状態』の場合は、『Null状態』のまま変わりません。
	 */
	CdDedJikoku& addSeconds( int value ) ;

	/** addSeconds() と等価です */
	CdDedJikoku& operator+=( int value ) {
		return addSeconds( value ) ; } ;
	/** addSeconds() と等価です。
	 *
	 *	this が保持している時刻に対して、秒数を減算します。
	 * @param value [in]
	 *	減算する秒数を指定してください。
	 *	負の数を指定することもできます。
	 * @attention
	 *	this が 『Null状態』の場合は、『Null状態』のまま変わりません。
	 */
	CdDedJikoku& operator-=( int value ) {
		return addSeconds( -value ) ; } ;



	/**
	 *	２つの時刻の差を、秒数で返します。
	 *	差は、絶対値が１２時間以下の側とします。
	 * @param value [in]
	 *	比較対象のオブジェクトを指定してください。
	 * @return
	 *	this - value を行った結果の秒数を返します。
	 *	this < value の場合は、負の数を返します。\n
	 *	ただし、this - value の絶対値が１２時間を超えている場合は、
	 *	逆周りで１２時間未満の値を返します。
	 *	
	 *	(例) 
	 *	
	 *	this が 1:00 で value が 23:00 の場合、単純計算では -22 時間ですが、
	 *	この値の絶対値は12時間を超えています。この場合、+2 時間を返します
	 *
	 *	※  1:00 は23:00 の２２時間前でもありますし、
	 *	（翌日の）1:00 は 23:00の２時間後であるともいえます。
	 *	この関数が返すのは、絶対値の小さい方の値です。
	 * @attention
	 *	this ・ value のいずれかが 『Null状態』の場合は、0を返します。
	 */
	int subJikoku( const CdDedJikoku& value  )const ;


	/**
	 *	２つの時刻の差を、秒数で返します。
	 * @param value [in]
	 *	比較対象のオブジェクトを指定してください。
	 * @param jikokuDateLine [in]
	 *	日付境界の時刻を指定してください。\n
	 *	この関数は、日付境界を跨がないように計算を行います。
	 * @return
	 *	this - value を行った結果の秒数を返します。
	 *	this < value の場合は、負の数を返します。
	 *
	 *	jikokuDateLine は、値が this 以上 value 以下の間に
	 *	位置した場合に意味を持ちます。
	 *	
	 *	(例) this が 1:00 で value が 5:00 の場合、
	 *	- jikokuDate が 0:00 なら、この関数の戻り値は -4 時間です。
	 *	- jikokuDate が 3:00 なら、この関数は、
	 *		this の1:00 を「翌日の1:00(25時)」とみなします。
	 *		戻り値は、( 25時 - 5時 )として計算を行った結果の +20 時間と
	 *		なります。
	 *	(例) this が 5:00 で value が 1:00 の場合、
	 *	- jikokuDate が 0:00 なら、この関数の戻り値は 4 時間です。
	 *	- jikokuDate が 3:00 なら、この関数は、
	 *		value の1:00 を「翌日の1:00(25時)」とみなします。
	 *		戻り値は、( 5時 - 25時 )として計算を行った結果の -20 時間と
	 *		なります。
	 *
	 *	
	 * @attention
	 *	this ・ value のいずれかが 『Null状態』の場合は、0を返します。
	 */
	int subJikoku( const CdDedJikoku& value , 
		const CdDedJikoku& jikokuDateLine )const ;


	/**
	 *	時刻を文字列で表現します。
	 * @param iFmt [in]
	 *	文字列の書式のオプションを指定します。
	 *	この値はビットごとに意味を持ちます。
	 *	ビットの意味は、 EFormat を参照してください。
	 * @return
	 *	文字列化したものを返します。
	 *	this が『Null状態』の場合は、空文字列を返します。
	 */
	string encode( unsigned int iFmt )const ;

	/**
	 *	時刻を文字列で表現します。
	 * @return
	 *	文字列化したものを返します。
	 *	this が『Null状態』の場合は、空文字列を返します。
	 *
	 *	文字列の書式のオプションは、 m_iFmt の値を採用します。
	 */
	string encode()const{	return encode( m_iFmt ) ;};

	/**
	 *	encode() によって生成された時刻文字列を
	 *	解析し、this の属性に反映します。
	 *
	 *	時刻文字列が解釈不可能な場合は、this は 『Null状態』
	 *	となります。
	 * @param value [in]
	 *	時刻文字列を指定してください。
	 * @return
	 *	成功すれば0以上、エラーなら負の数です。
	 *	-	-1 ;	//	項目数が不足しています。
	 *	-	-2 ;	//	時・分・秒の表記が不正です。
	 *
	 * (例)時刻文字列の例
	 *	-	"13:15:45"
	 *	-	"13:15"
	 *	-	"131545"
	 *	-	"1315"
	 *	-	"9:15:45"
	 *	-	"9:15"
	 *	-	"91545"
	 *	-	"915"
	 *
	 */
	int decode( const string& value ) ;

	
	///@}
	
};


#endif /*CdDedJikoku_h*/
