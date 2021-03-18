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
//	CentDedDia.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDia_h
#define  CentDedDia_h

#include <deque>
using namespace std ;

#include "CentDed.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"
class CentDedEkiCont ;

// ****************************************************************
//	CentDedDia
// ****************************************************************
/**
 *	@brief
 *	【概要】  DiagramEdit の、路線で設定されている『ダイヤ』１件を
 *	表します。
 *	
 *	このクラスのインスタンスは、通常は『路線』 ( CentDedRosen ) に包含
 *	されます。
 *	
 *	実際には、
 *	
 *	- 『路線』 (CentDedRosen) が『ダイヤ』 ( CentDedDia ) を
 *	０以上複数包含
 *	- 各『ダイヤ』 ( CentDedDia ) が『列車』 (CentDedRessya ) を
 *	０以上複数包含
 *	
 *	という関係になっています。
 *	
 *	  このクラスは、『列車』 ( CentDedRessya ) を、下り・上りの別で
 *	保持します。
 *	  『列車』の追加・削除は、このクラスのメソッドになっています。
 *
 * 
 *	　このクラスは、属性として『駅の数』・『列車種別数』を保持します。
 *	ただし、これらは派生属性となっています。
 *
 * <h5>int EkiCount</h5>
 *	このダイヤに存在する『駅の数』です。
 *	この属性は、 m_CentDedRessyaCont[]->m_iEkiCount をもとに決まります。
 * <h5>int RessyasyubetsuCount</h5>
 *	『列車種別数』。列車種別の種類の数です。
 *	この属性は、 m_CentDedRessyaCont[]->m_iRessyasyubetsuCount をもとに
 *	決まります。
 */
class CentDedDia
{
// ********************************
//	インナータイプ
// ********************************
 public:

// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	ダイヤの名称です。
	 *
	 *	（例） "平日ダイヤ" など
	 *
	 * @see CentDedRosen
	 *	 CentDedRosen は、この属性を限定子として扱います。
	 *	CentDedRosen に包含される CentDedDia では、
	 *	この属性は一意でなくてはなりません。
	 */
	string	m_strName ;
///@}
// ********************************
///@name 包含
// ********************************
///@{
 private:
	/**
	 *	この『ダイヤ』内で運行されている列車の
	 *	『列車』 ( CentDedRessya ) を保持します。
	 *
	 *	この変数は、要素数 2 の配列です。\n
	 *	[0] は	下り ( Ressyahoukou_Kudari ) 列車	\n
	 *	[1] は	上り ( Ressyahoukou_Nobori ) 列車	\n
	 *	を保持します。
	 *
	 *	このコンテナ内の CentDedRessya オブジェクトの
	 *	生成・破棄の責務はthisにあります。
	 *
	 *	初期状態では、要素数は 0 となります。
	 */
	CentDedRessyaCont*	m_CentDedRessyaCont[2] ;
	
///@}


// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 *	このコンストラクタは、 
	 *	CentDedDia_From_CdConnectedString() で
	 *	ファイルの内容を取得するときに、
	 *	読み取り先として指定するオブジェクトの生成に使います。
	 * @param iEkiCount [in]
	 *	ダイヤに含まれる駅の数。\n
	 * @param iRessyasyubetsuCount [in]
	 *	列車種別の数
	 */
	CentDedDia( int iEkiCount , int iRessyasyubetsuCount ) ;

	/**
	 * @param strName [in]
	 *	ダイヤの名称です。	\n
	 *	（例） "平日ダイヤ" など
	 * @param iEkiCount [in]]
	 *	ダイヤに含まれる駅の数。\n
	 * @param iRessyasyubetsuCount [in]
	 *	列車種別の数
	 */
	CentDedDia( 
		const string& strName  ,
		int iEkiCount , int iRessyasyubetsuCount ) ;

	CentDedDia( const CentDedDia& value );
	
	/**
	 *	このクラスへの代入を行いますが、
	 *	this の『駅』の数 ( m_iEkiCount ) は変更しません。
	 *
	 *	this が包含する『列車』( CentDedRessya )  のコピーには、
	 *	CentDedRessya& operator=( const CentDedRessya& value ) 
	 *	を使います。
	 */
	CentDedDia& operator=( const CentDedDia& value );

	virtual ~CentDedDia();
		
// ********************************
//	CentDedDia
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	string	getName()const{	return m_strName ;};
	CentDedDia& setName( const string& value ){
		m_strName = value ; return *this ; } ;

	int getEkiCount()const
	{
		return m_CentDedRessyaCont[ Ressyahoukou_Kudari ]->
			getEkiCount() ;
	};
	int getRessyasyubetsuCount()const
	{
		return m_CentDedRessyaCont[ Ressyahoukou_Kudari ]->
			getRessyasyubetsuCount() ;
	};

	/**
	 * @param eRessyahoukou [in]
	 *	列車方向を指定してください。
	 *	-	下り :	Ressyahoukou_Kudari 
	 *	-	上り : 	Ressyahoukou_Nobori 
	 */
	CentDedRessyaCont* getpCentDedRessyaCont( 
			ERessyahoukou eRessyahoukou )const
	{
		return m_CentDedRessyaCont[ eRessyahoukou ] ;
	};
	
	/**
	 * @param eRessyahoukou [in]
	 *	列車方向を指定してください。
	 *	-	下り :	Ressyahoukou_Kudari 
	 *	-	上り : 	Ressyahoukou_Nobori 
	 */
	IfContGet< CentDedRessya* >* getCentDedRessyaContGet( 
			ERessyahoukou eRessyahoukou )const
	{
		return m_CentDedRessyaCont[ eRessyahoukou ]->getIfContGet() ;
	};
	
	
	///@}

	// ********************************
	///@name CentDedDia-駅数・列車種別数の変更
	// ********************************
	///@{
	/**
	 *	このコンテナに含まれるすべての
	 *	『ダイヤ』 ( CentDedDia )に対し、
	 *	『駅』オブジェクトの属性の変更を通知します。
	 *	
	 *	この関数は、『始発駅・終着駅の駅時刻形式変更に伴う、着時刻・発時刻の修正』
	 *	を行わせます。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Index』で指定してください。
	 *	範囲は 0 以上 m_iEkiCount 以下です。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 */
	int onSetCentDedEki( const CentDedEkiCont* pCentDedEkiCont , int iEkiIndex ) ;

	/**
	 *	このダイヤに含まれるすべての『列車』 ( CentDedRessya )に対し、
	 *	『駅時刻』オブジェクトを、指定の位置に挿入します。
	 * @param iEkiIndex [in]
	 *	オブジェクトを挿入する位置を『駅Index』で指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 以下です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 */
	int insertCentDedEkiJikoku(	int iEkiIndex = INT_MAX ) ;
	
	/**
	 *	このダイヤに含まれるすべての『列車』 ( CentDedRessya )に対し、
	 *	『駅時刻』オブジェクトを、指定の位置から削除します。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Index』で指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 */
	int eraseCentDedEkiJikoku( int iEkiIndex = INT_MAX ) ;

	/**
	 *	『列車種別』の追加に伴い、
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を修正します。
	 *
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) のうち、
	 *	引数 iRessyasyubetsuIndex 以上の 『列車種別Index』を持つ
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を 1 加算します。
	 *
	 *	また、同時に this の m_iRessyasyubetsuCount も 1 加算します。
	 *
	 * @param iRessyasyubetsuIndex [in]
	 *	列車種別の追加位置を指定してください。
	 *	範囲は 0 以上 m_iRessyasyubetsuCount 以下です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 */
	int insertRessyasyubetsuIndex( int iRessyasyubetsuIndex = INT_MAX ) ;
	
	/**
	 *	『列車種別』の削除に伴い、
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を修正します。
	 *
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) のうち、
	 *	引数 iRessyasyubetsuIndex より大きい 『列車種別Index』を持つ
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を 1 減算します。
	 *
	 *	また、同時に this の m_iRessyasyubetsuCount も 1 加算します。
	 *
	 * @param iRessyasyubetsuIndex [in]
	 *	削除する列車種別Indexを指定してください。
	 *	範囲は 0 以上 m_iRessyasyubetsuCount 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 *	-	-3 ;	//	『列車種別』が iRessyasyubtsuIndex の列車が存在します。
	 */
	int eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex  = INT_MAX ) ;

	/**
	 *	このコンテナに、指定された『列車種別』の列車があるか否かを調べます。
	 * @param iRessyasyubetsuIndex [in]
	 *	『列車種別Index』を指定してください。
	 *	範囲は、 0 以上 列車種別の数未満です。
	 *	INT_MAX は、末尾の列車種別を指定したものとみなします。
	 * @param peRessyahoukou [out]
	 *	この関数はこの変数に、『列車種別』の列車が見つかった
	 *	ダイヤの列車方向を書き込みます。
	 *	不要なら NULL でもかまいません。
	 * @param piRessyaIndex [out]
	 *	この関数はこの変数に、『列車種別』の列車が見つかった
	 *	列車Index を書き込みます。
	 *	不要なら NULL でもかまいません。
	 * @return 
	 *	-	1; //	指定の列車種別の列車が存在します。
	 *	-	0; //	指定の列車種別の列車は存在しません。
	 *	-	-1 ;	//	インデクスが不正
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) ;

	///@}

};


#endif /*CentDedDia_h*/


