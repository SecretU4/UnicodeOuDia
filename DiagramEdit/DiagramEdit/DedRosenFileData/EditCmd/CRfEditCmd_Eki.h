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
//	CRfEditCmd_Eki.h
//	$Id: CRfEditCmd_Eki.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
*/
#ifndef  CRfEditCmd_Eki_h
#define  CRfEditCmd_Eki_h
/** @file */
#include "..\..\entDed\CentDedEkiCont.h"
#include "..\..\entDed\CentDedRosen.h"
#include "DedRosenFileData\EditCmd\CRfEditCmd.h"

namespace DedRosenFileData{ namespace EditCmd{

// ****************************************************************
//	CRfEditCmd_Eki
// ****************************************************************
/**
@brief
  CDedRosenFileData オブジェクト内の CentDedEki オブジェクトの
追加・削除の編集動作です。

  このクラスは、 CDedRosenFileData オブジェクト内の駅の
追加・置換・削除を行います。

　なお、置換の動作は、削除と追加の組み合わせで表現します。

  駅の削除は、全列車の駅時刻の削除を伴います。
このため、undo のためには CentDedRosen を保存する必要があります。

<h2>
【使い方1-置換対象の範囲と、追加する駅を指定】
</h2>

(1)  1番目のコンストラクタを使用して、
置換対象の駅Indexの範囲と、置換後の駅を設定してください。

(2)　execute() メソッドを実行して、CDedRosenFileData オブジェクトを
更新してください。
　(OuDiaでは通常、CRfEditCmd::execute() を直接呼び出す代わりに、
CDiagramEditDoc::executeEditCmd  () を使用して、ドキュメントを更新して
います。これにより、CDiagramEditDoc::undo() が正しく動作します。)

<h2>
【使い方2-置換対象の範囲のアイテムのコピーを取得後、コピーを編集】
</h2>

(1)　2番目のコンストラクタを使用して、
編集対象の駅Indexの範囲を指定してください。
　このコンストラクタは、このオブジェクトが保持する CentDedEkiCont
( m_CentDedEkiContSrc) に、指定された範囲の駅をコピーします。
　(OuDiaでは、CRfEditCmd_Eki コンストラクタを直接使用する代わりに、
 ViewEki::CWndDcdGridEki::createCmd() で
 インスタンスを生成しています)

(2)　m_iIndexDst,m_iSizeDst,m_CentDedEkiContSrc を編集してください。
　m_CentDedEkiContSrc の編集は、 m_CaMuiSelect アダプタを介して
行ってください。
( ViewEki::CWndDcdGridEki::createCmd() で
インスタンスを生成した場合、 createCmd() メソッドは
ウインドウ上での駅の選択状況を、m_CaMuiSelect の選択状態に反映させます。
　クラスユーザーは、m_CaMuiSelect で選択されている CentDedEki
のみを対象にして 編集操作を行うことにより、 ウインドウで選択された
駅のみを変更することができます)

(3)　execute() メソッドを実行して、CDedRosenFileData オブジェクトを
更新してください。
　(OuDiaでは通常、CRfEditCmd::execute() を直接呼び出す代わりに、
CDiagramEditDoc::executeEditCmd  () を使用して、ドキュメントを更新して
います。これにより、CDiagramEditDoc::undo() が正しく動作します。)

 */
class CRfEditCmd_Eki : 
	public CRfEditCmd
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	 	CentDedRosen オブジェクトの
	 	追加・削除対象となる 駅 インデクス。
	 
	 	INT_MAX は末尾を指定したものとみなします。
	 
	 	コンストラクタで決まります。
	*/
	int m_iIndexDst ;
	
	/**
	 	CentDedRosen オブジェクトの
	 	削除対象となる駅の数。
	 
	 	この値が0の場合は、execute() は 
	 	m_CentDedEkiContSrc.size() 個の
	 	CentDedEki の追加だけを行います。
	 
	 	この値が m_CentDedEkiContSrc.size() と等しい場合は、
	 	CentDedEki の置き換えだけを行います。
	 
	 	INT_MAX は、m_iIndexDst から末尾までを指定したものとみなします。
	 	m_iIndexSrc と m_iIndexDst を両方 INT_MAX にすることはできません。
	 
	 	コンストラクタで決まります。
	*/
	int m_iSizeDst ;
	
	/**
	 	CentDedRosen オブジェクトに対し、
	 	追加する駅を保持するコンテナ。
	 	このコンテナのサイズが 0 の場合は、
	 	execute() は CentDedRosen オブジェクトから
	 	 m_iSizeDst 個の CentDedEki の削除だけを行います。
	 
	 	コンストラクタで決まります。
	*/
	CentDedEkiCont	m_CentDedEkiContSrc ;

	/**
	  m_CentDedEkiContSrc 内のコンテナの一部の要素を選択した形の、
	部分コンテナインターフェースを作成します。
	  このインスタンスは、 m_CentDedEkiContSrc をAdapteeと
	します。

	　コンストラクタで生成された直後は、m_CentDedEkiContSrc 内の
	 すべての要素を選択しています。

	  execute() メソッドの動作は、このインスタンスの影響を受けません。

	<h2>
	【ViewEki::CWndDcdGridEki::createCmd() で
	インスタンスを生成した場合】
	</h2>

	 ViewEki::CWndDcdGridEki::createCmd() で
	インスタンスを生成した場合、 createCmd() メソッドは
	ウインドウ上での駅の選択状況を、このオブジェクトの選択状態に反映させます。
	特に、ウインドウ上で非連続複数選択操作を行っている場合、createCmd() メソッドが、
	生成するインスタンスの m_CaMuiSelect には、選択・非選択が混在します。
	
	　クラスユーザーは、m_CaMuiSelect で選択されている CentDedEki
	のみを対象にして 編集操作を行うことにより、 ウインドウで選択された
	駅のみを変更することができます。
	*/
	CaMuiSelect<CentDedEki>	m_CaMuiSelect ;

	/**
		[駅時刻を駅時刻形式に正規化する]設定。
	*/
	bool m_bAdjustByEkijikokukeisiki ;

	///@}
private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
	 	初期状態では NULL 。
	 	execute() で、
	 	要素を置換え・または追加を
	 	行った後は、execute() で削除した要素を
	 	保持します。
	 	要素を減少させるような操作を行った場合は、
	 	このコンテナは生成されません。
	 */
	CentDedEkiCont*	m_pCentDedEkiContOld ;
	/**
	 	初期状態では NULL 。
	 	execute() で
	 	要素を減少させた後は、
	 	置き換え前の CentDedRosen を
	 	保持します。

		(駅の減少によって、列車の駅時刻が失われます。
		Undoに備えて、全ダイヤ・全列車の駅時刻を
		保存しなくてはなりません)。
	 	
		また、[駅時刻を駅時刻形式に正規化する]場合は、
		全ての場合(要素の置き換え・追加・減少)において、
		置き換え前の CentDedRosen を保持します。
		
		要素を置換え・追加を行った場合は、
	 	このコンテナは生成されません。
	 */
	CentDedRosen*	m_pCentDedRosen ;
	///@}

// ********************************
//	コンストラクタ
// ********************************
public:
	/**
	 すべての属性を、引数で指定します。

	@param iIndexDst [in]
		CentDedRosen オブジェクトの
		追加・削除対象となる駅インデクス。
	@param iSizeDst [in]
		CentDedRosen オブジェクトの
		削除対象となる駅の数。@n
		この値が0の場合は、execute() は 
		m_CentDedRessyaContSrc.size() 個の
		駅の追加だけを行います。
	@param aCentDedEkiContSrc [in]
		CentDedRosen オブジェクトに対し、
		追加する駅を保持するコンテナ。
		このコンテナのサイズが 0 の場合は、
		execute() は CentDedRosen オブジェクトから
		 m_iSizeDst 個の駅の削除だけを行います。@n
		このコンテナに格納するオブジェクトは、駅数が CentDedRosen と同じで
		なくてはなりません。
	@param bAdjustByEkijikokukeisiki [in]
		[駅時刻を駅時刻形式に正規化する]設定。
	*/
	CRfEditCmd_Eki( 
		int iIndexDst ,
		int iSizeDst ,
		const CentDedEkiCont& aCentDedEkiContSrc ,
		bool bAdjustByEkijikokukeisiki );

	/**
	 m_CentDedEkiContSrc を、
	指定されたCDedRosenFileData の、指定の範囲の駅で初期化します。
	
	@param aCDedRosenFileData [in]
		編集対象の CDedRosenFileData を指定してください。
	@param iIndexDst [in]
		編集対象の駅の先頭インデクスを指定してください。
	@param iSizeDst [in]
		編集対象の駅の数を指定してください。
	@param bAdjustByEkijikokukeisiki [in]
		[駅時刻を駅時刻形式に正規化する]設定。

 	このコンストラクタは、 m_CentDedEkiContSrc を
	aCDedRosenFileData 内の iIndex から iSize 個の駅で初期化します。

	したがって、このコンストラクタで生成したオブジェクトで
	execute() を実行しても、ドキュメントは変化しません。

	このコンストラクタでオブジェクトを生成した後は、
	メソッドで m_iIndexDst , m_iSizeDst ,
	m_CentDedEkiContSrcを編集してから、
	execute() を実行してください。
	m_CentDedRessyaContSrc の編集は、 m_CaMuiSelect アダプタを
	使用してください。
	*/
	CRfEditCmd_Eki( 
		const CDedRosenFileData& aCDedRosenFileData ,
		int iIndexDst , 
		int iSizeDst ,
		bool bAdjustByEkijikokukeisiki );
	

	virtual ~CRfEditCmd_Eki() ; 
	
	
 public:
	// ********************************
	///@name	CRfEditCmd-操作
	// ********************************
	///@{
	/**
	 CDedRosenFileData オブジェクトに対して、編集操作を実行します。
	 また、編集動作に成功した場合、 this は、undo
	（編集動作の取り消し）を行うのに必要なデータを、
	メンバ変数に保持します。
	  @param pCDedRosenFileData [in,out]
		この関数はこのオブジェクトに対して、編集操作を実行します。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	m_iIndexDst の値が不正です。
		-	-11 ;	//	要素の削除に失敗しました。
		-	-12 ;	//	要素の追加に失敗しました。
		-	-13 ;	//	要素の置き換えに失敗しました。
	 
	<H4>
	【オーバライド】
	</H4>
		pCDedRosenFileData オブジェクトに対して、編集動作を実行してください。
	 */
	virtual int execute( CDedRosenFileData* pCDedRosenFileData ) ;
	
	/**
	「 this->execute() で行った編集操作を取り消す
	（ this->execute() で編集動作を行った直後の CDedRosenFileData 
	オブジェクトを、 this->execute() を行う直前の状態に
	する）」ための編集コマンドオブジェクトを生成します。

	このメンバ関数が返したオブジェクトを使って execute() を
	呼び出すことにより、 this->execute() 直後の状態の CentDedRosen
	 オブジェクトを、 this->execute() 直前の状態に戻すことができます。
	 
	 @return
		execute() で行った編集操作を取り消し、
		 CDedRosenFileData オブジェクトを execute() を行う直前の状態に
		するためのコマンドオブジェクトを生成します。
	<H4>
	【オーバライド】
	</H4>
	 execute() で実行した編集内容を元に戻すようなオブジェクトを
	生成してください。
	 */
	virtual Ou<CRfEditCmd> createUndoCmd()  ;
	///@}

public:
	// ********************************
	///@name CRfEditCmd_Eki-属性
	// ********************************
	///@{
	int getIndexDst()const{	return m_iIndexDst ; } ;
	CRfEditCmd_Eki& setIndexDst( int value )
	{
		m_iIndexDst = value ;	return *this ; 
	};
	int getSizeDst()const{	return m_iSizeDst ; } ;
	CRfEditCmd_Eki& setSizeDst( int value )
	{
		m_iSizeDst = value ;	return *this ; 
	};
	
	const CentDedEkiCont* getCentDedEkiContSrc()const
	{
		return &m_CentDedEkiContSrc ; 
	} ;

	bool getAdjustByEkijikokukeisiki()const
	{	return m_bAdjustByEkijikokukeisiki ;};
	CRfEditCmd_Eki& setAdjustByEkijikokukeisiki( bool value )
	{	m_bAdjustByEkijikokukeisiki = value ; return *this ;};

	/**
	@return
		駅の選択を行うアダプタへのインターフェースを返します。
	*/
	CaMuiSelect<CentDedEki>* getCaMuiSelect()
	{
		return &m_CaMuiSelect ;
	}
		
	/**
	@return
		駅の選択を行うアダプタへのインターフェースを返します。
	*/
	const CaMuiSelect<CentDedEki>* getCaMuiSelect()const 
	{
		return &m_CaMuiSelect ;
	}
	///@}
};

} } //namespace EditCmd namespace DedRosenFileData


#endif /*CRfEditCmd_Eki_h*/
