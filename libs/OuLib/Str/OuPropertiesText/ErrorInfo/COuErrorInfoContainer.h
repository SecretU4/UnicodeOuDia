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
// $Id: COuErrorInfoContainer.h 294 2016-06-11 05:10:03Z okm $
// ****************************************************************
/** @file */
#ifndef  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfoContainer_h
#define  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfoContainer_h
#include "str\OuPropertiesText\CNodeContainer.h"
#include "NsMu\CMup_deque.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfo.h"

namespace OuLib{
namespace Str{
namespace OuPropertiesText{
namespace ErrorInfo{

/**
@brief
	複数の OuErrorInfo を集約するコンテナです。
	
	集約している OuErrorInfo と『OuErrorInfoText』の間の相互変換の機能・
	『OuPropertiesTextErrorInfo』 との間の相互変換の機能を持ちます。

<H4>
【OuPropertiesTextErrorInfo】
</H4>

  OuPropertiesTextErrorInfo は、OuErrorInfo の内容を
  OuPropertiesText をベースフォーマットとして表現したデータ形式です。
  
  OuPropertiesTextErrorInfo は、0個以上複数の "ErrorInfo" Directory を
集約します。１つの "ErrorInfo" Directory で１つのエラー情報を表します。

  "ErrorInfo" Directory は、１つの "Reason" PropertyText と、0個または1個の
"Prop" Directory を集約します。

  "Prop" Directory には、エラー情報を補足するための属性データを記述した OuPropertiesText を集約することができます。
  
  
(例)
@code
ErrorInfo.
Reason=Receive Timeout.
.
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

 １つの OuErrorInfo が1行に出力されます。複数のOuErrorInfo が
集約されている場合は、 OuErroInfo の間は改行で区切られます。

  OuErrorInfoText は、以下の形式です。

  - 行頭に "Reason" 。
  - "Prop" に集約されるPropertyText がある場合は、"Reason" の後に "Prop" に集約される PropertyText (0個以上複数)がタブ区切りで並びます。
  - 複数の OuErrorInfo の間は、改行で区切ります。
  - 【注意】"Prop"に集約される Directory は、『OuErrorInfoText』には含まれません。

(例)
@code
Receive Timeout.
File Not Found.	FileName=source.txt
@endcode





*/
class COuErrorInfoContainer : public CMup_deque<COuErrorInfo>
{
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	COuErrorInfoContainer( );
	// ********************************
	///@name 集約
	// ********************************
	///@{
	/**
	@return
		"ErrorInfo" ディレクトリを集約するコンテナの内容を
		取得・設定するためのインターフェース。
	*/
	Mui<COuErrorInfo>* getCOuErrorInfoCont();
	const Mui<COuErrorInfo>* getCOuErrorInfoCont()const;
	///@}
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	@return
		このコンテナの内容を OuPropertiesTextErrorInfo に変換し、
		それを格納した CNodeContainer を返します。
		
	*/
	CNodeContainer toOuPropertiesTextErrorInfo()const;

	/**
		OuPropertiesTextErrorInfo を保持している
		OuPropertiesText の内容を、this に反映します。

		m_contCOuErrorInfoCont がそれまで保持していた
		インスタンスは破棄します。
	@param pCNodeContainer [in]
		OuPropertiesTextErrorInfo を保持している
		OuPropertiesText の内容を指定してください。
	@return
		成功したら 0 以上、エラーなら負の数です。
	*/
	int fromOuPropertiesTextErrorInfo( 
		const CNodeContainer* pCNodeContainer );

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
		-	-1 ;	//	解釈に失敗しました。
	*/
	int fromOuErrorInfoText( const std::string& strOuErrorInfoText ) ;
	///@}

};

} //namespace ErrorInfo{
} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{

#endif //OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfoContainer_h
