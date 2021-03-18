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
// ****************************************************************
//	CPropEditUi2.h
// ****************************************************************
#ifndef  OuLib_DocView_CPropEditUi2_h
#define  OuLib_DocView_CPropEditUi2_h

#include <string>

namespace OuLib{
namespace NsPropEditUi2{

/**
@brief
  オブジェクトのプロパティと、そのプロパティを編集するUiとの間での、
データ交換の手順を実装したクラスです。

　このクラスは、Target,Ui,UiData の3つの要素の間でのデータ交換の手順を
実装します。
　
Target
 --------------------------------

　編集の対象となるプロパティを持つオブジェクトです。
　クラスユーザーは、サブクラスのメンバー変数として、Target へのポインタを
追加してください。


Ui
 --------------------------------

　編集を行うUiのオブジェクトです。
　MFCアプリケーションの場合、Uiは通常は、CDialog の派生クラスの
オブジェクトです。
　
　クラスユーザーは、サブクラスのメンバー変数として、Uiへのポインタを追加
してください。

UiData
 --------------------------------

　Uiの現在の表示内容を保持するデータのオブジェクトです。

　UiDataの型は、通常は構造体となります。この構造体には、 Ui の表示内容す
べてを保持するためのデータメンバを持たせてください。
  例えば、Ui上にテキストボックスがあるなら、UiDataには、そのテキスト
ボックスの入力内容を示す string のメンバー変数が必要です。
　
　UiDataの型は、CPropEditUi2 のテンプレート引数 ARG_UIDATA で指定してください。

　UiDataのインスタンスは、 CPropEditUi2 によって、生成・破棄されます。
　
　このクラスは、抽象メソッド UiDataFromTarget(),UiDataToTarget() を
適切な時期・適切な順序で呼び出すことにより、Target とUiData の間の
データ交換を行います。また、抽象メソッド UiDataToUi(),UiDataFromUi() で、
 UiData と Ui とのデータ交換を行います。クラスユーザーは、 CPropEditUi2 の
 サブクラスで、これら抽象メソッドを実装してください。

使い方
 ================================
(1)　クラスユーザーは、プロパティの編集の開始時に、CPropEditUi2 クラスの
派生クラスのオブジェクトを作成し、 CPropEditUi2::StartEdit() を呼び出して
ください。

　 CPropEditUi2::StartEdit() は、 UiDataFromTarget() で、Target の内容を
 UiData に転送します。次に、AdjustProp() を呼び出して、UiData を正規化
します。その後、正規化した UiData の内容を、 UiDataToUi() で Ui に転送します。

　MFCアプリケーションの場合、クラスユーザーは、通常は CDialog の派生クラス
となります。 CDialog::OnInitDialog() で、CPropEditUi2 派生クラスの
オブジェクトを生成し、 CPropEditUi2::StartEdit() を呼び出してください。

(2)　Ui 上で何らかの変更が行われたら、 OnUiChanged() を呼び出してください。

　CPropEditUi2::OnUiChanged() は、 UiDataFromUi() で、Ui の内容を UiData に
転送した後、 AdjustUiData() を呼び出して、UiData を正規化します。
　その後、正規化した UiData の内容を、 UiDataToUi() で Ui に転送します。

　MFCアプリケーションの場合は、Ui上のテキストボックスから EN_KILLFOCUS 
イベントが送られたとき・チェックボックスから BN_CLICKED イベントが
送られたときに、 CPropEditUi2::OnUiChanged() を呼び出してください。

(3)　クラスユーザーは、編集作業終了時に、 CPropEditUi2::EndEdit() を
呼び出してください。 CPropEditUi2::EndEdit()  が正常終了したら、
クラスユーザーは、Ui を閉じて、プロパティ編集を終了してください。

　 CPropEditUi2::EndEdit() は、UiDataFromUi() で Ui の内容を UiData に
転送した後、 AdjustUiData() をy飛び出して、UiData を正規化します。
さらに、正規化した結果を 、UiDataToUi() に転送します。
　次いで、 CPropEditUi2::EndEdit() は、 CheckUiData() を呼び出して、
 UiData の値の検証を行います。UiData の値が不正(例：有効範囲外や、
書式エラー)であった場合は、 CheckUiData() はエラーメッセージを表示します。
また、 SetFocus() で、問題のある Ui にフォーカスを設定します。

@param ARG_UIDATA
  UiData の型を指定してください。通常は、Ui上の表示内容を保持するための
データメンバを持つ構造体を指定してください。
*/
template < class ARG_UIDATA >
class CPropEditUi2
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/**
		UiData の型。テンプレートパラメータで決まります。
	*/
	typedef ARG_UIDATA	UIDATA ;

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		編集対象を保持します。コンストラクタで決まります。
		
		- true: 新規オブジェクトに対する、プロパティの編集
		- false: 既存オブジェクトに対する、プロパティの編集
	*/
	bool m_bNewItem ;
	
	/**
		UiData のオブジェクト。
		
		このオブジェクトの破棄の責務は、this にあります。
		thisは、 StartEdit() 時に、NewUiData() でオブジェクトを生成し、
		 EndEdit() 時に、 DeleteUiData() で破棄します。

		NewUiData()・DeleteUiData() をオーバーライドすることにより、
		UIDATAの派生クラスのインスタンスを、UiData として用いることができます。
	*/
	UIDATA* m_pUiData ;
	
	/**
		CPropEditUi2::StartEdit() 終了時点での UiData のコピーです。
		CPropEditUi2::StartEdit() 終了前までは、この値はNULLです。
	*/
	UIDATA* m_pUiDataStartEdit ;
	
	
	/**
		前回の AdjustUiData() 実行時点での、UiData のコピーです。
		CPropEditUi2::StartEdit() 終了前までは、この値はNULLです。
	*/
	UIDATA* m_pUiDataPrev ;
	
	///@}
private:
    // ================================
    ///@name 内部データ
    // ================================
    ///@{
	/**
		通常はfalse。publicメソッドが実行中の間はtrueです。
		メソッド内でのUI操作によりイベントが発生し、再入が発生するのを
		防止するためのフラグです。
	*/
    bool m_bMethodProcessing ;
    ///@}

protected:
	// ================================
	/** @name オーバーライトの必要なメソッド1-Targetに依存する処理
		Target と UiData との間のデータ交換のためのメソッドです。
		このグループのメソッドは、 Ui の環境には依存しません。
	*/
	// ================================
	///@{
	
	/**
		UiData を、新規Targetのプロパティの編集のために
		初期化します。
		
		m_bNewItem が true の場合にだけ、 CPropEditUi2::StartEdit() 
		から呼び出されます。
	
		通常、 UiData は、UIDATAのデフォルトコンストラクタで初期化されます。
		クラスユーザーは、UiData に、デフォルトコンストラクタと異なる
		初期値を与えたい場合は、このメンバ関数をオーバーライドしてください。

	@param pUiData [out]
		UiData のオブジェクト。
	*/
	virtual void InitUiData( UIDATA* pUiData ) { }

	/**
		UiData に、Targetの属性を反映します。
		
		m_bNewItem が false の場合にだけ、 CPropEditUi2::StartEdit() 
		から呼び出されます。
		
		クラスユーザーは、この関数をオーバーライドして、
		Target の内容をUiData に反映する処理を実装してください。

	@param pUiData [out]
		UiData のオブジェクト。
	*/
	virtual void UiDataFromTarget( UIDATA* pUiData ) = 0 ; 

	/**
		UiData の内容を正規化します。
		
		CPropEditUi2::StartEdit(),CPropEditUi2::OnUiChanged(),
		CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
		から呼び出されます。
		
		クラスユーザーは、この関数をオーバーライドして、
		UiDataのメンバの内容を正規化する処理を実装してください。
		
		この関数では、入力内容に対するエラーメッセージの表示はお勧めしません。
		エラーメッセージの表示は、CheckUiData() で行ってください。
	
	正規化の例
	 --------------------------------
	-	テキストボックスに全角で入力されたテキストを、半角に変換する。
	-	あるチェックボックスがONのときにはテキストボックスを有効、
		OFFの時には無効(グレー)にする

	@param pUiData [in,out]
		UiData のオブジェクト。
	@param pUiDataPrev [in]
		前回の AdjustUiData() 終了後の UiData のコピーです。
		この関数では、 pUiDataPrev と pUiData の値を比較することにより、
		「今回ユーザーによって変更されたUiDataメンバー」を判断することが
		できます。
		この関数が CPropEditUi2::StartEdit() から呼び出された場合は、
		この引数はNULLとなります。
	@param bStartEdit [in]
		- true: この関数は、 CPropEditUi2::StartEdit() から呼び出されています。
			この場合は、pUiDataPrev は無効です。
			関数では、 UiData のすべてのデータの正規化を行ってください。
		- false: この関数は、 CPropEditUi2::StartEdit() 以外から
			呼び出されています。
			pUiData と pUiDataPrev を比較することにより
			今回変化した UiData メンバー変数を判断することが出来ます。
			この関数では、UiData のうち、今回変化したデータメンバーだけを
			正規化してください。
	
	
	この関数のコーディングの例
	 --------------------------------
	@code
	virtual void AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
	{
		if ( bStartEdit || pUiDataPrev->メンバー名 != pUiData->メンバー名)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}
	@endcode
	*/
	virtual void AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )=0;

	/**
		UiData の内容を検証し、問題があればエラーメッセージを表示します。
		
		CPropEditUi2::EndEdit()
		から呼び出されます。
		
		クラスユーザーは、この関数をオーバーライドして、
		UiDataのメンバの内容を検証する処理を実装してください。
		入力内容に問題があれば、ShowError()でエラーメッセージを表示し、
		SetFocus()で、フォーカスを問題のあるUIに設定してください。
		
		新規オブジェクトに対するプロパティの編集の場合は、
		UiDataのすべてのメンバーを検証する必要があります。
		また、必須のメンバーがブランクである場合は、
		エラーメッセージを表示するべきです。

		既存オブジェクトに対するプロパティ編集の場合は、
		ユーザーによって値の変更されたメンバーのみを検証してください。
		pUiData と pUiDataStartEdit との間で違いのあるデータメンバーが、
		ユーザーによって値の変更されたメンバーです。
		
	@param bNewItem [in]
		-true: 新規オブジェクトに対する、プロパティの編集
		-false: 既存オブジェクトに対する、プロパティの編集
	@param pUiData [in]
		UiData のオブジェクト。
	@param pUiDataStartEdit [in]
		StartEdit()終了後の UiData のコピーです。
		この関数では、 pUiDataStartEdit と pUiData の値を比較することにより、
		「ユーザーによって変更されたUiDataメンバー」を判断することが
		できます。
	@return
		成功したら0以上、エラーなら負の数です。
		0以外を返した場合、戻り値は、CPropEditUi2::EndEdit() の
		戻り値となります。
		
	この関数のコーディングの例
	 --------------------------------
	@code
	virtual int CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
	{
		int iRv = 0 ; 
		
		if ( bNewItem || pUiDataStartEdit->メンバー名 != pUiData->メンバー名)
		{
			//	pUiData->メンバー名 の検証を行うコード。
			
			if ( pUiData->メンバー名 にエラーがあり )
			{
				ShowError( エラーの理由を示す文字列 );
				SetFocus( offsetof( UIDATA , メンバー名 ) );
				iRv = -1 ;
			}
		}
		return iRv ;
	}
	@endcode
	*/
	virtual int CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) = 0 ;
	
	/**
		UiData の内容を、Targetに反映します。
		
		CPropEditUi2::EndEdit()
		から呼び出されます。
		
		クラスユーザーは、この関数をオーバーライドして、
		UiDataのメンバの内容を、Target のプロパティに反映する処理を
		実装してください。
		
		新規オブジェクトに対するプロパティの編集の場合は、
		UiDataのすべてのメンバーを、Targetに反映する必要があります。

		既存オブジェクトに対するプロパティ編集の場合は、
		ユーザーによって値の変更されたメンバーのみを
		Targetに反映してください。
		pUiData と pUiDataStartEdit との間で違いのあるデータメンバーが、
		ユーザーによって値の変更されたメンバーです。
		
		CPropEditUi2 は、 CheckUiData() が正常終了した後にだけ
		UiDataToTarget() を呼び出します。
		従いまして、この関数では、CheckUiData() でやっているような
		値の検証を行う必要はありません。
		
	@param bNewItem [in]
		-true: 新規オブジェクトに対する、プロパティの編集
		-false: 既存オブジェクトに対する、プロパティの編集
	@param pUiData [in]
		UiData のオブジェクト。
	@param pUiDataStartEdit [in]
		StartEdit()終了後の UiData のコピーです。
		この関数では、 pUiDataStartEdit と pUiData の値を比較することにより、
		「ユーザーによって変更されたUiDataメンバー」を判断することが
		できます。
	@return
		成功したら0以上、エラーなら負の数です。
		0以外を返した場合、戻り値は、CPropEditUi2::EndEdit() の
		戻り値となります。
		
		
	この関数のコーディングの例
	 --------------------------------
	@code
	virtual int UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
	{
		int iRv = 0 ; 
		
		if ( bNewItem || pUiDataStartEdit->メンバー名 != pUiData->メンバー名)
		{
			//	pUiData->メンバー名 を、Target に反映するコード
		}
		return iRv ;
	}
	@endcode
	*/
	virtual int UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) = 0 ;
	///@}

protected:
	// ================================
	/** @name オーバーライトの必要なメソッド2-UIに依存する処理
		UiData と Ui との間のデータ交換のためのメソッドです。
		このグループのメソッドは、 Ui の環境(Windows,MFCなど)
		に依存する処理だけを実装します。
	*/
	// ================================
	///@{
	/**
		UiDataの内容をUiに反映します。
		
		CPropEditUi2::StartEdit(),CPropEditUi2::OnUiChanged(),
		CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
		から呼び出されます。
		
		クラスユーザーは、この関数をオーバーライドして、
		UiDataのメンバの内容をUiに表示する処理を実装してください。
	@param pUiData [in]
		UiData のオブジェクト。
	*/
	virtual void UiDataToUi( const UIDATA* pUiData )=0 ;
	
	
	/**
		Uiの入力内容をUiDataに反映します。
		
		CPropEditUi2::OnUiChanged(),
		CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
		から呼び出されます。
		
		クラスユーザーは、この関数をオーバーライドして、
		Ui への変更内容をUiData に反映する処理を実装してください。
	@param pUiData [out]
		UiData のオブジェクト。
	*/
	virtual void UiDataFromUi( UIDATA* pUiData ) =0 ;
	
	/**
		画面上にエラーメッセージを表示します。

		クラスユーザーは、この関数をオーバーライドして、
		エラーメッセージを表示する処理を実装してください。
		
		MFCアプリケーションでは、通常は、メッセージボックスを表示します。
	@param strErrorReason [in]
		エラーの内容を示す文字列
	@param strInfo [in]
        エラーの補助情報を示す文字列。不要であれば、空文字列を
        指定してください。
	*/
	virtual void ShowError( 
		const std::string& strErrorReason ,
		const std::string& strInfo ) =0 ;
	
	/**
		Ui 上の特定のコントロールに、フォーカスを設定します。

		クラスユーザーは、この関数をオーバーライドして、
		指定されたコントロールにフォーカスを設定する処理を実装してください。
		
	@param iOffsetofUiDataMember [in]
		フォーカスを設定する編集項目を指定してください。
		UiData内の対象となるデータメンバの、構造体の先頭アドレスからの
		オフセットを指定してください。

	例:フォーカスを、UiDataのメンバ strNumber を入力するコントロールに設定
		する場合は、以下のようにしてください。
	@code
		SetFocus( offsetof(UIDATA,strNumber ) ) ;
	@endcode
	*/
	virtual void SetFocus( int iOffsetofUiDataMember ) =0 ;
	
	
	
	///@}

protected:
	// ================================
	/** @name UIDATA のオブジェクト生成に関するメソッド
		UiData に UIDATAの派生クラスのインスタンスを使用する場合には、
		これらのメソッドをオーバーライドしてください。
	*/
	// ================================
	///@{
	/**
		UiData オブジェクトを生成します。
		
		CPropEditUi2::StartEdit() から呼び出されます。
		
		m_pUiData を UIDATA の派生クラスのオブジェクトにすることができます。
		その場合は、この関数をオーバーライドして、派生クラスのオブジェクトを
		生成する処理を実装してください。
		
		NewUiData() をオーバーライドしたときは、 DeleteUiData() ・
		 CopyUiData() もオーバーライドする必要があります。
	@return
		生成されたオブジェクトのアドレスを返します。
	*/
	virtual UIDATA* NewUiData(){ return new UIDATA() ;}

	/**
		NewUiData() で生成した オブジェクトを削除します。
		
		CPropEditUi2::EndEdit() ・デストラクタから呼び出されます。
		
		NewUiData() をオーバーライドした場合は、 DeleteUiData() も
		オーバーライドして、 NewUiData() で生成したオブジェクトを削除する
		処理を実装してください。
	@param pUiData [in]
		削除するオブジェクトを指定してください。
	*/
	virtual void DeleteUiData( UIDATA* pUiData ){ delete pUiData ;} 

	/**
		UiData オブジェクトの内容をコピーします。
		
		NewUiData() をオーバーライドした場合は、 CopyUiData() も
		オーバーライドして、 NewUiData() で生成したオブジェクトの
		メンバーをすべてコピーする処理を実装してください。
	@param pDst [out]
		コピー先のオブジェクトを指定してください。
	@param pSrc [in]
		コピー元のオブジェクトを指定してください。
	*/
	virtual void CopyUiData( UIDATA* pDst , const UIDATA* pSrc )
	{ *pDst = *pSrc ;}

	///@}
protected:
	// ================================
	///@name	下請関数
	// ================================
	///@{
	/**
		m_pUiData・m_pUiDataStartEdit・m_pUiDataPrev 
		を削除し、NULLに初期化します。
	*/
	void DeleteUiDatas()
	{
		if ( m_pUiData != NULL )
		{
			DeleteUiData( m_pUiData ) ; 
			m_pUiData = NULL ; 
		}
		if ( m_pUiDataStartEdit != NULL )
		{
			DeleteUiData( m_pUiDataStartEdit ) ; 
			m_pUiDataStartEdit = NULL ; 
		}
		if ( m_pUiDataPrev != NULL )
		{
			DeleteUiData( m_pUiDataPrev ) ; 
			m_pUiDataPrev = NULL ; 
		}
	}
	///@}



public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	@param bNewItem [in]
		編集対象を指定してください。
		- true: 新規オブジェクトに対する、プロパティの編集
		- false: 既存オブジェクトに対する、プロパティの編集
	*/
	CPropEditUi2( bool bNewItem )
		: m_bNewItem( bNewItem ) 
		, m_pUiData( NULL ) 
		, m_pUiDataStartEdit( NULL ) 
		, m_pUiDataPrev( NULL ) 
		, m_bMethodProcessing( false ) 
	{
	}
	virtual ~CPropEditUi2()
	{
		DeleteUiDatas() ;
	}
	

public:
	// ********************************
	///@name  CPropEditUi2-属性
	// ********************************
	///@{
	/**
	@return
		現在のUiDataへのポインタです。

	  このポインタを使って、CPropEditUi2の派生クラス外から、
	UiDataを変更することもできます。
	  UiDataを派生クラス外から変更した場合は、
	OnUiDataChanged() を呼び出してください。
	*/
	UIDATA* GetUiData()const{ return m_pUiData ;}
	///@}
public:
	// ********************************
	///@name  CPropEditUi2-操作
	// ********************************
	///@{
	/**
		編集動作を開始します。
		UiDataをTargetのデータで初期化し、それを
		Uiに反映します。

		オブジェクトに対して他のpublicメソッドが実行中に、
		このメソッドを呼び出した場合(再入が発生した場合)、
		このメソッドは何もせずにリターンします。
	*/
    void StartEdit()
    {
        int iRv = 0;
        if (m_bMethodProcessing)
        {
            iRv = -11;  //  再入はできません。
        }
        else
        {
            m_bMethodProcessing = true; //  再入抑止
            // --------------------------------
			
            if (iRv >= 0)
            {
				//	UiData オブジェクトの破棄。
				DeleteUiDatas();

				//	UiData オブジェクトを初期化
				m_pUiData = NewUiData() ;
                if (m_bNewItem)
                {
                    InitUiData( m_pUiData );
                }
                else
                {
                    UiDataFromTarget( m_pUiData );
                }
                
 				//	UiData を表示
                AdjustUiData( m_pUiData , NULL , true );
                UiDataToUi( m_pUiData );

				//	m_pUiDataStartEdit・ m_pUiDataPrev に
				//	UiDataのコピーを保持する
                m_pUiDataStartEdit = NewUiData() ;
                CopyUiData( m_pUiDataStartEdit , m_pUiData ) ;
                m_pUiDataPrev = NewUiData() ;
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
            }

            // --------------------------------
            m_bMethodProcessing = false;
        }
    }
	/**
		UIが変更されたときに呼び出してください。
		UiDataに、UIのデータを取り込みます。
		その後、AdjustUiData() でUiData の正規化を行い、
		結果をUIに反映します。

		オブジェクトに対して他のpublicメソッドが実行中に、
		このメソッドを呼び出した場合(再入が発生した場合)、
		このメソッドは何もせずにリターンします。
	*/
	void OnUiChanged()
	{
	    int iRv = 0;
	    if (m_bMethodProcessing)
	    {
	        iRv = -11;  //  再入はできません。
	    }
	    else
	    {
	        m_bMethodProcessing = true; //
	        // --------------------------------
	        if (iRv >= 0)
	        {
	            UiDataFromUi( m_pUiData );
                AdjustUiData( m_pUiData , m_pUiDataPrev , false );
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
	            UiDataToUi( m_pUiData );
	        }
	        // --------------------------------
	        m_bMethodProcessing = false; //
	    }
	}
	/**
		UIは変更されていないが、UiDataが変更されたときに
		AdjustUiData() でUiData の正規化を行い、
		結果をUIに反映します。

		オブジェクトに対して他のpublicメソッドが実行中に、
		このメソッドを呼び出した場合(再入が発生した場合)、
		このメソッドは何もせずにリターンします。
	*/
    void OnUiDataChanged()
    {
        int iRv = 0;
        if (m_bMethodProcessing)
        {
            iRv = -11;  //  再入はできません。
        }
        else
        {
            m_bMethodProcessing = true; //
            // --------------------------------
            if (iRv >= 0)
            {
                AdjustUiData( m_pUiData , m_pUiDataPrev , false );
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
	            UiDataToUi( m_pUiData );
            }

            // --------------------------------
            m_bMethodProcessing = false;
        }
	}
	/**
		編集動作の終了を試みます。
		UiからUiDataに値を取り込み、AdjustUiData()で
		検証を行います。このとき、エラーが検出されたら、
		ShowError() でエラーを表示し、処理を中断します。
		エラーが見つからない場合は、UiDataの値を
		UiDataToTarget() で、Target() に転送します。

		オブジェクトに対して他のpublicメソッドが実行中に、
		このメソッドを呼び出した場合(再入が発生した場合)、
		、このメソッドは何もせずにリターンします(戻り値は-11)
	
	@return
		成功したら0以上、エラーなら負の数です。
		-   -11: 再入が発生したため、何もせずにリターンしました
		-	0でも-11でもない: CheckUiData(),UiDataToTarget() の戻り値。
	*/
	int EndEdit()
	{
	    int iRv = 0;
	    if (m_bMethodProcessing)
	    {
	        iRv = -11;  //  再入はできません。
	    }
	    else
	    {
	        m_bMethodProcessing = true; //
	        // --------------------------------
	        if (iRv >= 0)
	        {
	            UiDataFromUi( m_pUiData );
				AdjustUiData( m_pUiData , m_pUiDataPrev , false );
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
	            UiDataToUi( m_pUiData );
	        }
	        if (iRv >= 0)
	        {
	            int iResult = CheckUiData( 
	            	m_bNewItem , m_pUiData , m_pUiDataStartEdit ) ;
	            if (iResult != 0 )
	            {
	                iRv = iResult ;
	            }
	        }
	        if (iRv >= 0)
	        {
	            int iResult = UiDataToTarget( 
	            	m_bNewItem , m_pUiData , m_pUiDataStartEdit ) ;
	            if (iResult != 0 )
	            {
	                iRv = iResult ;
	            }
	        }
	        // --------------------------------
	        m_bMethodProcessing = false;
	    }
	    return iRv;
	}
	///@}

};

} //namespace NsPropEditUi2
} //namespace OuLib


#endif /*OuLib_DocView_CPropEditUi2_h*/
