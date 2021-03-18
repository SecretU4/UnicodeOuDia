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
// ****************************************************************
//	CEnumToString
//	$Id: CEnumToString.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
/** @file */
#ifndef  CEnumToString_h
#define  CEnumToString_h
#include <string>
#include <map>

// ****************************************************************
//	CEnumToString
// ****************************************************************
/**
@brief
	列挙子-文字列間の変換を提供します。

	列挙子→文字列の一方向の変換なら std::map で事足ります。
	しかし、 map には両方向の変換ができません。
	このクラスは、 map の値からキーを逆引きする機能を追加しています。

@param _EnumType 
	列挙型を指定してください。

【使い方】

1.  列挙子と対応する文字列を add() で追加してください。

2.  以後は、stringOf()・fromString() が利用できます。

(例)
@code
enum ERessyahoukou
{
	//	下り 
	Ressyahoukou_Kudari = 0 ,
	//	上り 
	Ressyahoukou_Nobori ,
};


const CEnumToString<ERessyahoukou>& getEnumToString()
{
	static CEnumToString<ERessyahoukou> aEnumToString ;
	if ( aEnumToString.size() == 0 )
	{
		aEnumToString.add( Ressyahoukou_Kudari , "Kudari" ) ;
		aEnumToString.add( Ressyahoukou_Nobori , "Nobori" ) ;
	}
	return aEnumToString ;
};
	string strValue = getERessyahoukouToString().stringOf( 
				Ressyahoukou_Kudari ) ;

@endcode


*/
template <class _EnumType > class CEnumToString
{
public:
	typedef typename _EnumType EnumType ;
private:
	/**
		
	*/
	std::map< _EnumType , std::string >	m_Map ;
public:
	/**
	@return
		登録した列挙子の数を返します。
	*/
	int size()const
	{
		return (int)m_Map.size() ;
	};

	/**
		列挙子と対応する文字列を追加してください。
	@param eValue [in]
		列挙子を指定してください。
	@param strValue [in]
		文字列を指定してください。
	*/
	void add( EnumType eValue , const std::string& strValue ) 
	{
		m_Map[eValue] = strValue ;
	};
	/**
		列挙子に対応する文字列を返します。
	@param eValue [in]
		列挙子を指定してください。
	@return
		対応する文字列を返します。
		eValue が add() で登録されていない場合は、空文字列を返します。
	*/
	std::string stringOf( EnumType eValue )const 
	{
		std::string strValue ;
		std::map< _EnumType , std::string >::const_iterator ite = m_Map.find( eValue ) ;
		if ( ite != m_Map.end() )
		{
			strValue = ite->second ;
		}
		return strValue ;
	};
	/**
		stringOf() の逆変換を行います。
	@param strValue [in]
		文字列を指定してください。
	@param peValue [out]
		この関数はこのアドレスに、対応する列挙子を書き込みます。
		変換に失敗した場合は、このアドレスは変更されません。
	@return
		変換に成功したら 0 、エラーなら負の数です。
		-	-1 ; //	対応する列挙子が登録されていません。
	*/
	int fromString( const std::string& strValue , EnumType* peValue )const 
	{
		int iRv = 0 ;
	
		std::map< _EnumType , std::string >::const_iterator ite ;
		for ( ite = m_Map.begin() ; ite != m_Map.end() ; ite ++ )
		{
			if ( ite->second == strValue )
			{
				break ;
			}
		}
		if ( ite == m_Map.end() )
		{
			iRv = -1 ;
		}
		else
		{
			*peValue = ite->first ;
		}
		return iRv ;
	}
};
#endif //CEnumToString_h
