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

#include "CentDed.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"

namespace entDed{

class CentDedEkiCont ;

// ****************************************************************
//	CentDedDia
// ****************************************************************
/**
@brief
 DiagramEdit の、路線で設定されている『ダイヤ』１件を表します。

このクラスのインスタンスは、通常は『路線』 ( CentDedRosen ) に包含
されます。

実際には、

- 『路線』 (CentDedRosen) が『ダイヤ』 ( CentDedDia ) を
０以上複数包含
- 各『ダイヤ』 ( CentDedDia ) が『列車』 (CentDedRessya ) を
０以上複数包含

という関係になっています。

  このクラスは、『列車』 ( CentDedRessya ) を、下り・上りの別で
保持します。

　このクラスは、属性として『駅の数』・『列車種別数』を保持します。
ただし、これらは派生属性となっています。

<h5>int EkiCount</h5>
このダイヤに存在する『駅の数』です。
この属性は、 m_CentDedRessyaCont[]->m_iEkiCount をもとに決まります。

<h5>int RessyasyubetsuCount</h5>
『列車種別数』。列車種別の種類の数です。
この属性は、 m_CentDedRessyaCont[]->m_iRessyasyubetsuCount をもとに
決まります。

制約
 -------------------------------- 

操作のエラー検査・修正
 -------------------------------- 


△上書き(operator=): このオブジェクトが親オブジェクト CentDedDiaCont の子である場合で、代入元のダイヤ名が空文字列である場合、もしくは同じ名前のダイヤが CentDedDiaCont にある場合は例外スロー。
　(代入元が、CentDedDiaCont::set()に渡すとエラーになるようなオブジェクトである場合は、代入は例外スローとします)

△setName:このオブジェクトが親オブジェクト CentDedDiaCont の子である場合で、代入元のダイヤ名が空文字列である場合、もしくは同じ名前のダイヤが CentDedDiaCont にある場合は例外スローとします。
　(属性変更後のオブジェクトが、CentDedDiaCont::set()に渡すとエラーになるようなオブジェクトである場合は、エラーとします)

△setParent:adjustを実行する

 制約に合うように属性を修正(adjust)
 -------------------------------- 

○列車コンテナ(CentDedRessyaCont)にadjust()を委譲します。


*/
class CentDedDia : public CChildBase
{
	typedef CChildBase	super ;
public:
	// ****************************************************************
	//	インナータイプ
	// ****************************************************************
	/**
	　CentDedDia に包含されている『列車』コンテナです。
	*/
	class CXRessyaCont : public CentDedRessyaCont
	{
		typedef CentDedRessyaCont super ;
	 public:
		// ********************************
		///@name 関連
		// ********************************
		///@{
		/**
			親オブジェクトへのポインタです。コンストラクタで決まります。
		*/
		CentDedDia* m_pDia ;
	public:
		// ********************************
		//	コンストラクタ
		// ********************************
		CXRessyaCont( 
			CentDedDia* pCentDedDia , 
			ERessyahoukou m_eRessyahoukou ) 
			: 
			super( 0 ,
				m_eRessyahoukou ) ,
		  	m_pDia( pCentDedDia )
		{}
		CXRessyaCont( 
			CentDedDia* pCentDedDia , 
			int iEkiCount ,
			ERessyahoukou m_eRessyahoukou ) 
			: 
			super( iEkiCount ,
				m_eRessyahoukou ) ,
		  	m_pDia( pCentDedDia )
		{}


		CXRessyaCont( 
			CentDedDia* pCentDedDia , 
			const CentDedRessyaCont& value )
			: 
			super( value ) ,
		  	m_pDia( pCentDedDia )
		{}

	 public:
		// ********************************
		///@name CentDedRessyaCont-関連
		// ********************************
		///@{
		/**
		@return
			このコンテナが CentDedDia に包含されている場合は、
			CentDedDia のアドレス。
			そうでないならNULL。
		*/
		virtual CentDedDia* getDia(){ return m_pDia ;}
		/**
		@return
			このコンテナが CentDedRessya に包含されている場合は、
			CentDedRessya のアドレス。
			そうでないならNULL。
		*/
		virtual const CentDedDia* getDia()const{ return m_pDia ;}
	};
	/**
		代入演算子や、set...() でスローされる例外です。
	*/
	class LException
	{
	};


	// ****************************************************************
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	  	ダイヤの名称です。
	  
	  	（例） "平日ダイヤ" など
	  
	   @see CentDedRosen
	  	 CentDedRosen は、この属性を限定子として扱います。
	  	CentDedRosen に包含される CentDedDia では、
	  	この属性は一意でなくてはなりません。
	 */
	std::string	m_strName ;
	///@}
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		この『ダイヤ』内で運行されている列車の
		『列車』 ( CentDedRessya ) を保持します。
	
		この変数は、要素数 2 の配列です。

		- [0] は	下り ( Ressyahoukou_Kudari ) 列車	
		- [1] は	上り ( Ressyahoukou_Nobori ) 列車	
	
		このコンテナ内の CentDedRessya オブジェクトの
		生成・破棄の責務はthisにあります。
	
		初期状態では、要素数は 0 となります。
	*/
	CXRessyaCont*	m_CentDedRessyaCont[2] ;
	
	///@}


public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	   @param strName [in]
	  	ダイヤの名称です。	\n
	  	（例） "平日ダイヤ" など
	*/
	CentDedDia( const string& strName = "" ) ;

	/**
	  	このコンストラクタは、 
	  	CentDedDia_From_CdConnectedString() で
	  	ファイルの内容を取得するときに、
	  	読み取り先として指定するオブジェクトの生成に使います。
	   @param iEkiCount [in]
	  	ダイヤに含まれる駅の数。
	 */
	CentDedDia( int iEkiCount ) ;

	/**
	   @param strName [in]
	  	ダイヤの名称です。	\n
	  	（例） "平日ダイヤ" など
	   @param iEkiCount [in]]
	  	ダイヤに含まれる駅の数。
	 */
	CentDedDia( 
		const std::string& strName  ,
		int iEkiCount ) ;


	CentDedDia( const CentDedDia& value );
	
	/**
	  	このクラスへの代入を行いますが、
	  	this の『駅』の数 ( m_iEkiCount ) は変更しません。
	  
		△上書き(operator=): このオブジェクトが親オブジェクト CentDedDiaCont 
		の子である場合で、代入元のダイヤ名が空文字列である場合、
		もしくは同じ名前のダイヤが CentDedDiaCont にある場合は例外スロー。
		　(代入元が、CentDedDiaCont::set()に渡すとエラーになるような
		　オブジェクトである場合は、代入は例外スローとします)

	 */
	CentDedDia& operator=( const CentDedDia& value );

	virtual ~CentDedDia();

public:
	// ********************************
	///@name CChildBase-操作
	// ********************************
	///@{
	/**
	　△setParent:adjustを実行する
	*/
	virtual void setParent( CParentBase* pParent );
	///@}
public:
	// ********************************
	///@name CentDedDia-属性
	// ********************************
	///@{
	std::string	getName()const{	return m_strName ;};
	
	/**
	△setName:このオブジェクトが親オブジェクト CentDedDiaCont の子である
	場合で、代入元のダイヤ名が空文字列である場合、もしくは同じ名前のダイヤが
	 CentDedDiaCont にある場合は例外スローとします。
	　(属性変更後のオブジェクトが、CentDedDiaCont::set()に渡すとエラーに
	　なるようなオブジェクトである場合は、エラーとします)
	*/
	void setName( const std::string& value );

	int getEkiCount()const
	{
		return m_CentDedRessyaCont[ Ressyahoukou_Kudari ]->
			getEkiCount() ;
	};
	///@}
	// ********************************
	///@name CentDedDia-包含
	// ********************************
	///@{
	/**
	   @param eRessyahoukou [in]
	  	列車方向を指定してください。
	  	-	下り :	Ressyahoukou_Kudari 
	  	-	上り : 	Ressyahoukou_Nobori 
	 */
	CentDedRessyaCont* getCentDedRessyaCont( 
			ERessyahoukou eRessyahoukou )
	{
		return m_CentDedRessyaCont[ eRessyahoukou ] ;
	};
	/**
	   @param eRessyahoukou [in]
	  	列車方向を指定してください。
	  	-	下り :	Ressyahoukou_Kudari 
	  	-	上り : 	Ressyahoukou_Nobori 
	 */
	const CentDedRessyaCont* getCentDedRessyaCont( 
			ERessyahoukou eRessyahoukou )const
	{
		return m_CentDedRessyaCont[ eRessyahoukou ] ;
	};
	///@}
	// ********************************
	///@name CentDedDia-操作
	// ********************************
	///@{

	/**
		指定の駅 Order の駅時刻を、
		駅時刻形式・始発・終着に合わせて変更します。

		変更内容は、 CentDedEkiJikoku::adjustByEkijikokukeisiki 
		の説明を参照してください。

	@see CentDedEkiJikoku::adjustByEkijikokukeisiki 

	@param pCentDedEkiCont [in]
		駅コンテナを指定してください。
	@param iEkiIndex [in]
		駅Indexを指定してください。
		INT_MAX は、末尾を指定したことになります。
	*/
	void adjustByEkijikokukeisiki(
		const CentDedEkiCont* pCentDedEkiCont ,
		int iEkiIndex );
	///@}

	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。

		○列車コンテナ(CentDedRessyaCont)にadjust()を委譲します。

	*/
	void adjust() ;

public:
	// ********************************
	///@name CentDedDia-駅数・列車種別数の変更
	// ********************************
	///@{

	/**
	  	このコンテナに、指定された『列車種別』の列車があるか否かを調べます。
	   @param iRessyasyubetsuIndex [in]
	  	『列車種別Index』を指定してください。
	  	範囲は、 0 以上 列車種別の数未満です。
	  	INT_MAX は、末尾の列車種別を指定したものとみなします。
	   @param peRessyahoukou [out]
	  	この関数はこの変数に、『列車種別』の列車が見つかった
	  	ダイヤの列車方向を書き込みます。
	  	不要なら NULL でもかまいません。
	   @param piRessyaIndex [out]
	  	この関数はこの変数に、『列車種別』の列車が見つかった
	  	列車Index を書き込みます。
	  	不要なら NULL でもかまいません。
	   @return 
	  	-	1; //	指定の列車種別の列車が存在します。
	  	-	0; //	指定の列車種別の列車は存在しません。
	  	-	-1 ;	//	インデクスが不正
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const ;

	///@}
public:
	// ********************************
	///@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
	///@{
	/**
		m_CentDedEkiCont に CentDedEki が追加された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiIndex
		追加された CentDedEki のインデクス。
	*/
	virtual void onEkiInsert( int iEkiIndex );

	/**
		m_CentDedEkiCont から CentDedEki が削除された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiIndex
		削除された CentDedEki のインデクス。
	*/
	virtual void onEkiErase( int iEkiIndex  );

	/**
		CentDedEkiTrackCont に CentDedEkiTrack が追加された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiIndex
		CentDedEkiTrackCont が追加された CentDedEki の駅Index。
	@param iEkiTrackIndex
		追加された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex );

	/**
		CentDedEkiTrackCont から CentDedEkiTrack が削除された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiIndex
		CentDedEkiTrackCont が削除された CentDedEki の駅Index。
	@param iEkiTrackIndex
		削除された CentDedEkiTrack の先頭のインデクス。
	*/
	virtual void onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex );

	/**
		CentDedRessyasyubetsuCont に CentDedRessyasyubetsu が追加された直後、
		CentDedRessyasyubetsuCont から呼び出されます。
	@param iRessyasyubetsuIndex
		追加された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuInsert( int iRessyasyubetsuIndex );

	/**
		CentDedRessyasyubetsuCont から CentDedRessyasyubetsu が削除された直後、
		CentDedRessyasyubetsuCont から呼び出されます。
	@param iRessyasyubetsuIndex
		削除された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuErase( int iRessyasyubetsuIndex );



	///@}
};

} //namespace entDed

#endif /*CentDedDia_h*/


