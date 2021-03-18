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
//$Id: CentDedEkiTrackSelector.h 378 2016-11-16 21:10:54Z okm $
#ifndef  entDed_CentDedEkiTrackSelector_h
#define  entDed_CentDedEkiTrackSelector_h



namespace entDed{
/**
@brief
  『駅時刻入線』オブジェクトの『番線指定子』。『番線コンテナ』内の『番線』オブジェクトを指定するためのクラスです。

  『番線』オブジェクトの指定方法は、以下から選択できます。

 - NULL：(既定値)　列車線は、列車方向に応じた『下り本線』『上り本線』のいずれかとなります。
 - インデクス指定：『番線コンテナ』内の整数インデクスを指定

  インデクス指定において、インデクスが、『番線コンテナ』内の、列車の方向の『本線』を指している場合、『番線指定子』はNULLに正規化します。
*/
class CentDedEkiTrackSelector
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	  番線コンテナ内のインデクス。
	  
	  NULL の場合は-1となります。
	*/
	int	m_iIndex ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	  番線指定子をNULLに初期化します。
	*/
	CentDedEkiTrackSelector() : m_iIndex( -1 ){}

	/**
	@param iIndex 
	  インデクスを指定して初期化します。
	*/
	CentDedEkiTrackSelector( int iIndex ) : m_iIndex( iIndex ){}

public:
	// ********************************
	///@name CentDedEkiTrackSelector-属性
	// ********************************
	///@{
	///@see m_iIndex
	int	getiIndex()const{ return m_iIndex ;}
	///@see m_iIndex
	void setIndex( int value ){	m_iIndex = value ;}
	/**
	@return thisがNULLなら true 、インデクス指定なら false です。	
	*/
	bool isNull()const{ return m_iIndex < 0 ;}
	/**
		this を NULLに設定します。
	*/
	void setNull(){ m_iIndex = -1 ;}
	///@}
};

} //namespace entDed

#endif //entDed_CentDedEkiTrackSelector_h
