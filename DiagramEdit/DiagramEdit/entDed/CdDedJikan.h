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
//	CdDedJikan.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDedJikan_h
#define  CdDedJikan_h
#include <string>

namespace entDed{

// ****************************************************************
//	CdDedJikan
// ****************************************************************
/**
 @brief
 【概要】
	  秒単位の経過時間を表す単純データクラスです。
	
	  このクラスは、「時刻Aから時刻Bまでの間の時間」といった、
	時間の相対値を表します。負の数も存在します。

	  このクラスは、内部的には秒数を属性 m_iTotalSeconds 
	で保持します。
	  時間・分・秒は、このクラスの派生属性として位置付けられます。

	このクラスが保持する時間は、 encode() で文字列化することができます。\n
 (例)  "10:30:45"\n
	また、encode() で作成した文字列を、 deocde() で解釈することが
	できます。

 */
class CdDedJikan
{
public:
	// ****************************************************************
	//	CdDedJikan::CConv
	// ****************************************************************
	/**
		CdDedJikoku の内容を文字列化するクラスです。
		属性として、文字列のフォーマットを保持します。
	*/
	class CConv
	{
		/**	秒を出力しません */
		bool m_bNoSecond ;

		/** 時が正の数の場合は、先頭に "+" を付与します。 */
		bool m_bPlusDisplay ;
		/** 
			時が正の数の場合は、先頭にスペースを付与します。
		
			Format_PlusToNone と Format_PlusToSpace は
			排他的です。
		 */
		bool m_bPlusToSpace ;

	public:
		CConv() ;
		/**
		@param bNoSecond [in]
			秒を出力しません 
		@param bPlusDisplay [in]
			 時が正の数の場合は、先頭に "+" を付与します。 
		@param bPlusToSpace [in]
			時が正の数の場合は、先頭にスペースを付与します。 
		*/
		CConv( 
			bool bNoSecond ,
			bool bPlusDisplay ,
			bool bPlusToSpace  ) ;
		
		bool getNoSecond()const
		{	return m_bNoSecond ;};
		CConv& setNoSecond( bool value )
		{	m_bNoSecond = value ; return *this ;};

		bool getPlusDisplay()const
		{	return m_bPlusDisplay ;};
		CConv& setPlusDisplay( bool value )
		{	m_bPlusDisplay = value ; return *this ;};

		bool getPlusToSpace()const
		{	return m_bPlusToSpace ;};
		CConv& setPlusToSpace( bool value )
		{	m_bPlusToSpace = value ; return *this ;};

		/**
			時間を文字列で表現します。
		 @param aJikoku [in]
			文字列の書式のオプションを指定します。
			この値はビットごとに意味を持ちます。
			ビットの意味は、 EFormat を参照してください。
		 @return
			文字列化したものを返します。
			this が『Null状態』の場合は、空文字列を返します。
		*/
		std::string encode( const CdDedJikan& aJikan )const ;

	};

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		 秒数を保持します。
		負の数の場合もあります。
	 */
	int	m_iTotalSeconds ;
	///@}
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		値の符号を返します。
		
		値をその値の絶対値で割った数になります。
	 @param value [in]
		対象となる値を指定してください。
	 @return
		-	value > 0 のとき、 +1
		-	value == 0 のとき、 0
		-	value < 0 のとき、 -1
	 */
	static int sign( int value ){
		if ( value > 0 ){	return +1 ; } 
		else if ( value < 0 ){	return -1 ; } 
		return 0 ;
	};


	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		0 に初期化します。
	 */
	CdDedJikan() : m_iTotalSeconds( 0 ){};
	
	/**
	 @param iTotalSeconds [in]
		秒数を指定してください。
	 */
	CdDedJikan( int iTotalSeconds ) : m_iTotalSeconds( iTotalSeconds ){};
	
	/**
		時：分：秒を指定して、時間を初期化します。
	 @param iSign [in]
		符号を指定してください。
		-	1 ;	//	正の数
		-	0 ;	//	ゼロ
		-	-1 ;	//	負の数
	 @param iHour [in]
		時。範囲は 0 以上 。
	 @param iMinute [in]
		分。範囲は 0 以上 60 未満。
	 @param iSecond [in]
		秒。範囲は 0 以上 60 未満。
	
		負の数を設定する場合は、 iSign に -1 を指定し、
		iHour , iMinute , iSecond には正の数を指定してください。
		
	 (例)
	
		「２時間前」を設定する場合は、	\n
		CdDedJikan( -1 , 2 , 0 , 0 ) 
		\nとなります。
	
		「２時間後」を設定する場合は、	\n
		CdDedJikan( +1 , 2 , 0 , 0 ) 
		\nとなります。
		
	 */
	CdDedJikan( int iSign , int iHour , int iMinute , int iSecond = 0 ) ;

	/**
		時刻文字列を使って初期化します。
	 @param value [in]
		時刻文字列を指定してください。
		
	 (例)時刻文字列の例
		-	"13:15:45"
		-	"13:15"
		-	"131545"
		-	"1315"
		-	"9:15:45"
		-	"9:15"
		-	"91545"
		-	"915"
	 */
	CdDedJikan( const std::string& strTime ) ;

public:
	// ********************************
	//	CdDedJikan
	// ********************************
	// ********************************
	///@name CdDedJikan-属性
	// ********************************
	///@{
	int getTotalSeconds()const{	return m_iTotalSeconds ; } ;
	CdDedJikan& setTotalSeconds( int value ){
		m_iTotalSeconds = value ;
		return ( *this ) ;
	};
	
	/** 
	 @return
		m_iTotalSeconds を返します。 
	 */
	operator int()const{	return getTotalSeconds() ; } ;
	
	/**
	 @return
		値の符号を返します。
		-	1 ;	//	正の数
		-	0 ;	//	ゼロ
		-	-1 ;	//	負の数
	 */
	int getSign()const{	return sign( m_iTotalSeconds ) ; } ;
	
	/**
	 @return
		時。値は0以上。
	 @attention
		this が負の数の場合でも、この値は正（絶対値）です。
	 */
	int getHour()const{	return abs( m_iTotalSeconds / ( 60 * 60 ) ) ; } ;
	
	/**
	 @return
		分。
	 @attention
		this が負の数の場合でも、この値は正（絶対値）です。
	 */
	int getMinute()const{	return abs( m_iTotalSeconds / ( 60 ) % ( 60 ) ) ; } ;
	
	/**
	 @return
		秒。
	 @attention
		this が負の数の場合でも、この値は正（絶対値）です。
	 */
	int getSecond()const{	return abs( m_iTotalSeconds % ( 60 ) ) ; } ;
	
	/**
		時間を、設定します。
	 @param iSign [in]
		符号を指定してください。
		-	1 ;	//	正の数
		-	0 ;	//	ゼロ
		-	-1 ;	//	負の数
	 @param iHour [in]
		時。範囲は 0 以上 。
	 @param iMinute [in]
		分。範囲は 0 以上 60 未満。
	 @param iSecond [in]
		秒。範囲は 0 以上 60 未満。
	
		負の数を設定する場合は、 iSign に -1 を指定し、
		iHour , iMinute , iSecond には正の数を指定してください。
		
	 */
	CdDedJikan& setTime( int iSign , 
		int iHour , int iMinute , int iSecond = 0 ) ;
	
	
	///@}
	
	// ********************************
	///@name CdDedJikan-操作
	// ********************************
	///@{
	/**
		２つの時間を、比較します。
	 @param value [in]
		比較対象のオブジェクトを指定してください。
	 @return
		this - value を行った結果の符号を返します。
		-	+1 ;	//	this > value。
		-	0 ;		//	this == value。
		-	-1 ;	//	this < value。
	 */
	int compare( const CdDedJikan& value )const ;
	
	/**	compare() と等価です。	 */
	bool operator>( const CdDedJikan& value )const{
		return ( compare( value ) == 1 ) ; } ;
	/**	compare() と等価です。	 */
	bool operator>=( const CdDedJikan& value )const{
		return ( compare( value ) != -1  ) ; } ;
	/**	compare() と等価です。	 */
	bool operator==( const CdDedJikan& value )const{
		return ( compare( value ) == 0 ) ; } ;
	/**	compare() と等価です。	 */
	bool operator<=( const CdDedJikan& value )const{
		return ( compare( value ) != 1  ) ; } ;
	/**	compare() と等価です。	 */
	bool operator<( const CdDedJikan& value )const{
		return ( compare( value ) == -1 ) ; } ;
	
	/**
		this が保持している時間に対して、秒数を加算します。
	 @param value [in]
		加算する秒数を指定してください。
		負の数を指定することもできます。
	 */
	CdDedJikan& addSeconds( int value ) ;

	/** addSeconds() と等価です */
	CdDedJikan& operator+=( int value ) {
		return addSeconds( value ) ; } ;

	/** addSeconds() と等価です。
	
		this が保持している時間に対して、秒数を減算します。
	 @param value [in]
		減算する秒数を指定してください。
	 */
	CdDedJikan& operator-=( int value ) {
		return addSeconds( -value ) ; } ;

	
	/**
		２つの時間の差を、秒数で返します。
	 @param value [in]
		比較対象のオブジェクトを指定してください。
	 @return
		this - value を行った結果の秒数を返します。
		this < value の場合は、負の数を返します。
	
	 */
	int subJikan( const CdDedJikan& value )const ;

	/**
		encode() によって生成された時刻文字列を
		解析し、this の属性に反映します。
	
		時刻文字列が解釈不可能な場合は、this は 『Null状態』
		となります。
	 @param value [in]
		時刻文字列を指定してください。
	 @return
		成功すれば0以上、エラーなら負の数です。
		-	-1 ;	//	項目数が不足しています。
		-	-2 ;	//	時・分・秒の表記が不正です。
		
	 (例)時刻文字列の例
		-	"13:15:45"
		-	"13:15"
		-	"131545"
		-	"1315"
		-	"9:15:45"
		-	"9:15"
		-	"91545"
		-	"915"
	
	 */
	int decode( const std::string& value ) ;

	
	///@}
	
};

} //namespace entDed

#endif /*CdDedJikan_h*/
