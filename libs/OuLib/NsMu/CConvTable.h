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
/** @file */
// $Id: CConvTable.h 355 2016-08-18 16:41:28Z okm $
#ifndef OuLib_NsMu_CConvTable_h
#define OuLib_NsMu_CConvTable_h

#include <map>

namespace OuLib{
namespace NsMu{


/**
@brief
  ２つの値の変換表を実現するクラスです。

  このクラスは、２つの値のペアをのテーブルを保持し、左の値をキーに右の値を検索・またはその逆を行います。
  
  このクラスでは、ペアの2つの値をそれぞれ、left,right と呼びます。

<H4>
【使い方】
</H4>

1. このクラスのインスタンスを生成してください。
  テンプレート引数には、left、right の型を指定してください。

2. add() で、値のペアを登録してください。

3. rightFrom() で、left に対応する right の値を取得できます。また、leftFrom() で、right に対応する left を取得できます。

  rightFrom() は、未登録の left を指定された場合、 m_bRightDefaultEnable が偽ならば、LException を throw します。
  m_bRightDefaultEnable が真なら、LException を throwせず、rightFrom() の戻り値として m_RightDefault を返します。
  この振る舞いは、 leftFrom() も同様です。

  left に同一の値を2つ以上登録した場合、rightFrom() の戻り値がどちらの値になるのかは未定義です。この振る舞いは、 leftFrom() も同様です。

@param TYPE_LEFT
	left の型を指定してください。
@param TYPE_RIGHT
	right の型を指定してください。

*/
template <class TYPE_LEFT , class TYPE_RIGHT >
class CConvTable
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/**
		対応する値が見つからない場合にスローされる例外です。
	*/
	class LException
	{
	};
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/** left と right のペアを格納するコンテナです。 */
	std::map<TYPE_LEFT,TYPE_RIGHT>	m_Map ;
	///@}
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	- false: left を返す関数において、値が見つからない場合は LException を 
		throw します。
	- true: left を返す関数において、値が見つからない場合は LException を 
		throw せずに m_LeftDefault を返します。
	*/
	bool m_bLeftDefaultEnable ;
	/** @see m_bLeftDefaultEnable */
	TYPE_LEFT	m_LeftDefault ;
	/**
	- false: right を返す関数において、値が見つからない場合は LException を 
		throw します。
	- true: right を返す関数において、値が見つからない場合は LException を 
		throw せずに m_RightDefault を返します。
	*/
	bool m_bRightDefaultEnable ;
	/** @see m_bRightDefaultEnable */
	TYPE_RIGHT	m_RightDefault ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CConvTable()
		: m_bLeftDefaultEnable( false ) 
		, m_bRightDefaultEnable( false ) 
	{
	}

public:
	// ********************************
	///@name	CConvTable - 属性
	// ********************************
	///@{
	void setLeftDefaultEnable( bool value ){	m_bLeftDefaultEnable = value ;}
	bool getLeftDefaultEnable()const{	return m_bLeftDefaultEnable ;}
	/** m_LeftDefault を設定します。m_bLeftDefaultEnable もtrue になります。*/
	CConvTable& setLeftDefault( const TYPE_LEFT& value )
	{
		m_LeftDefault = value ;
		m_bLeftDefaultEnable = true ;
		return *this ;
	}
	TYPE_LEFT getLeftDefault()const{	return m_LeftDefault ;}

	void setRightDefaultEnable( bool value ){	m_bRightDefaultEnable = value ;}
	bool getRightDefaultEnable()const{	return m_bRightDefaultEnable  ;}
	/** 
		m_RightDefault を設定します。m_bRightDefaultEnable もtrue になります。
	*/
	CConvTable& setRightDefault( const TYPE_RIGHT& value )
	{
		m_RightDefault = value ;
		m_bRightDefaultEnable = true ;
		return *this ;
	}
	TYPE_RIGHT getRightDefault()const{	return m_LeftDefault ;}
	///@}
public:
	// ********************************
	///@name	CConvTable - 操作
	// ********************************
	///@{
	/**
	@return
		登録された値のペアの数を返します。
	*/
	int size(){	return m_Map.size() ;}
	/**
		値のペアを追加します。
	@param left
		left の値
	@param rigth 
		rigth の値
	*/
	CConvTable& add( const TYPE_LEFT& left , const TYPE_RIGHT& right )
	{
		m_Map[left] = right ;	return *this ;
	}
	/**
		指定された left の値に対応する rigth を返します。
	@param left
		left を指定してください。
	@return 
		対応する right の値を返します。

		left を変換できない場合の挙動は、 m_bRightDefaultEnable の
		説明をご覧下さい。

	@see m_bRightDefaultEnable
	*/
	TYPE_RIGHT rightFrom( const TYPE_LEFT& left )const
	{
		TYPE_RIGHT	rv = m_RightDefault ;
		std::map< TYPE_LEFT , TYPE_RIGHT >::const_iterator ite = m_Map.find( left ) ;
		if ( ite != m_Map.end() )
		{
			rv = ite->second ;
		}
		else if ( !m_bRightDefaultEnable )
		{
			throw( LException() ) ;
		}
		return rv ;
	}
	/**
		指定された right の値に対応する left を返します。
	@param left
		right を指定してください。
	@return 
		対応する left の値を返します。

		right を変換できない場合の挙動は、 m_bLeftDefaultEnable の
		説明をご覧下さい。

	@see m_bLeftDefaultEnable
	*/
	TYPE_LEFT leftFrom( const TYPE_RIGHT& right )const 
	{
		TYPE_LEFT rv = m_LeftDefault ;
		std::map< TYPE_LEFT , TYPE_RIGHT >::const_iterator ite ;
		for ( ite = m_Map.begin() ; ite != m_Map.end() ; ite ++ )
		{
			if ( ite->second == right )
			{
				rv = ite->first ;
				break ;
			}
		}
		if ( ite == m_Map.end() )
		{
			if ( !m_bLeftDefaultEnable )
			{
				throw( LException() ) ;
			}
		}
		return rv ;
	}
	
	const std::map<TYPE_LEFT,TYPE_RIGHT>& getMap()const{  return m_Map ;}
	///@}
};

} //namespace NsMu
} //namespace OuLib


#endif //OuLib_NsMu_CConvTable_h
