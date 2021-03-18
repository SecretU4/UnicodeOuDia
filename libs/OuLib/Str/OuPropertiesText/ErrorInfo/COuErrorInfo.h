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
// $Id: COuErrorInfo.h 63 2012-09-01 08:54:26Z okm $
// ****************************************************************
/** @file */
#ifndef  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfo_h
#define  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfo_h

#include "str\OuPropertiesText\CDirectory.h"
#include <string>
namespace OuLib{
namespace Str{
namespace OuPropertiesText{
namespace ErrorInfo{

/**
@brief
  OuErrorInfo は、エラーの詳細情報を保持する単純データ形式です。

  このクラスは、属性として

  - Reason - エラーの内容を示す文字列
  - Prop  - エラーの補足情報を示す OuPropertiesText 
  
を持ちます。但し、Prop はオプションなので、不要であれば使わなくてかまいません

  Reason には原則として、改行文字・タブ文字は含まないものとします（OuErrorInfoTextからの変換ができなくなるため）

  this は、Null状態(エラー情報を保持していない状態)をとることができます。
  この場合、 Reason が空文字列・Prop.size() が 0 となります。
 
<H4>
【OuPropertiesTextErrorInfo】
</H4>

  OuPropertiesTextErrorInfo は、OuErrorInfo の内容を
  OuPropertiesText をベースフォーマットとして表現したデータ形式です。

  @see COuErrorInfoContainer


(例)
@code
ErrorInfo.
Reason=File Not Found.
Prop.
FileName=source.txt
Server.
Host=FtpServer
Username=FtpUser
.
.
.
@endcode

<H4>
【OuErrorInfoText】
</H4>

  OuErrorInfo の内容を表すテキストです。UIへの表示を想定しています。

  @see COuErrorInfoContainer

(例)
@code
File Not Found.	FileName=source.txt
@endcode

*/
class COuErrorInfo
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		"Reason" PropertyText 。
		エラーの原因を表す文字列を示します。この文字列は、
		半角英字を原則とします。
		タブ文字・改行文字を含むことはできません
		(但し、このクラスではタブ文字・改行文字のチェックは行いません)
	*/
	std::string m_strReason ;
	/**
		エラーの補足情報を示す OuPropertiesText 
	*/
	CNodeContainer	m_Prop ;
	///@}
public:
	// ********************************
	///@name 定数
	// ********************************
	///@{
	static const char* const DirectoryName_ErrorInfo ;
	static const char* const PropertyTextName_Reason ;
	static const char* const DirectoryName_Prop ;
	///@}
	
public:
	COuErrorInfo()
	{
	};
	COuErrorInfo( const std::string& strReason ) :
		m_strReason( strReason )
	{
	};
	COuErrorInfo( 
		const std::string& strReason , 
		const CNodeContainer& Prop ) :
		m_strReason( strReason ) ,
		m_Prop( Prop ) 
	{
	}
public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	std::string getReason()const{	return m_strReason ;};
	void setReason( const std::string& value )
	{	m_strReason = value ;};
	CNodeContainer*	getProp(){	return &m_Prop ;};
	const CNodeContainer*	getProp()const{	return &m_Prop ;};
	///@}
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	@return
		このコンテナの内容を OuPropertiesTextErrorInfo に変換し、
		それを格納した "ErrorInfo" Directory を返します。
		
	*/
	Ou<CDirectory> toOuPropertiesTextErrorInfo()const;

	/**
		OuPropertiesTextErrorInfo を保持している
		"ErrorInfo" Directory の内容を、this に反映します。
	@param pCNode [in]
		"pCDirectory" Directory を保持している
		CDirectory の内容を指定してください。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	pCDirectory は "Directory" ではありません。
		-	-2 ;	//	Directory に"Reason" PropertyText がありません。
	*/
	int fromOuPropertiesTextErrorInfo( 
		Ou<const CDirectory> pCDirectory );

	/**	
	@return
		『OuErrorInfoText』を生成して返します。
	*/
	std::string toOuErrorInfoText()const ;

	/**	
		『OuErrorInfoText』を解釈し、このクラスの属性に反映します。
		このクラスがそれまで保持していたデータは破棄します。
	@param strOuErrorInfoText [in]
		『OuErrorInfoText』を指定しました。
	@return 
		成功したら 0 以上、エラーなら負の数です。
	
	@note
		strOuErrorInfoText が空文字列の場合は、エラーにはならずに
		全ての属性をクリアした状態になります。
	*/
	int fromOuErrorInfoText( const std::string& strOuErrorInfoText );
	/**	
		this を Null 状態にします。
	*/
	void clear() ;

	/**	
	@return
		this が Null 状態なら  true です。
	*/
	bool isNull()const ;
	///@}
};


} //namespace ErrorInfo{
} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{

#endif //OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfo_h
