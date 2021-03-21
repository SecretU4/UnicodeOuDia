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
//	$Id: CPropEditUi_Ressyasyubetsu.h 399 2016-11-26 08:45:03Z okm $
// ****************************************************************

/** @file */
#pragma once ;
#ifndef  CPropEditUi_Ressyasyubetsu_h
#define  CPropEditUi_Ressyasyubetsu_h
#include <string>
#include "NsPropEditUi2\CPropEditUi2.h"
#include "entDed\CentDedRessyasyubetsuCont.h"

namespace ViewRessyasyubetsu {

	using namespace std ;
	using namespace entDed ;
	using namespace OuLib::NsPropEditUi2 ;


/**
@brief
	NULL 状態をとることのできる、CdColorProp です。

	既定ではNULLですが、CdColorPropを代入すると、
	有効値になります。

	NULL状態の場合は、R,G,Bは0xFFになります。
*/
class CdColorPropNullable 
	: public CdColorProp 
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	- false: 非NULL状態。
	- true:	 NULL状態(既定値)
	*/
	bool m_bIsNull ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/** this をNULL状態に初期化します。 */
	CdColorPropNullable() : CdColorProp( 0xFF , 0xFF , 0xFF ) , m_bIsNull( true ){}

	/** 
		変換コンストラクタ。CdColorPropを代入すると、
		非NULL状態になります。

	@note
		代入演算子 
		CdColorPropNullable& operator=(  const CdColorProp& value )
		は、必要ありません。@n
	@code
		CdColorPropNullable a ;
		CdColorProp b ;
		a = b ;	
	@endcode
		上記のコードの a=b は、以下のようになります。	
	@code
		a.operator=( CdColorPropNullable( b ) ) ;
	@endcode
	*/
	CdColorPropNullable( const CdColorProp& value ) 
		: CdColorProp( value ) 
		, m_bIsNull( false )
	{
	}

	/** RGB値で初期化するコンストラクタ */
	CdColorPropNullable( 
		unsigned char iRed ,
		unsigned char iGreen ,
		unsigned char iBlue ) 
		: CdColorProp( iRed , iGreen , iBlue ) 
		, m_bIsNull( false )
	{
	}

public:
	// ********************************
	///@name CdColorPropNullable - 属性
	// ********************************
	///@{
	bool getIsNull()const{ return m_bIsNull ;}
	/** NULL を設定すると、RGBは0xFF,0xFF,0xFF になります。 */
	void setIsNull( bool value )
	{
		m_bIsNull = value ;
		if ( m_bIsNull )
		{ 
			setRed( 0xFF ) ;setGreen( 0xFF ) ; setBlue( 0xFF ) ;
		}
	}
	///@}


public:
	// ********************************
	//	演算子
	// ********************************
	bool operator==( const CdColorPropNullable& value )const
	{
		return CdColorProp::operator==( value ) 
			&& ( m_bIsNull == value.m_bIsNull ) ;
	}
	bool operator!=( const CdColorPropNullable& value )const
	{
		return !( *this == value ) ; 
	}
};


/**
@brief
	CPropEditUi_Ressyasyubetsu で編集する UIDATA 構造体です
*/
struct UIData_Ressyasyubetsu
{
	/** 列車種別名 */
	string strSyubetsumei ;
	
	/** 
	列車種別名の有効・無効 
	
	現在のところ、この値は true 固定です。
	*/
	bool bSyubetsumeiIsEnable ;
	
	/** 略称（種別名の略称） */
	string strRyakusyou ;
	
	/** 
	時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)	

	不定の場合(複数選択時で、Targetが異なる文字色を含んでいる場合)は、
	NULL状態です。
	*/
	CdColorPropNullable colorJikokuhyouMojiColor ;



	/** 
	時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント
	-	0～7: 時刻表フォントのインデクス
	-	-1:	不定
	*/
	int iJikokuhyouFontIndex ;

	/** ダイヤグラム線の色

	不定の場合(複数選択時で、Targetが異なる文字色を含んでいる場合)は、
	NULL状態です。
	*/
	CdColorPropNullable colorDiagramSenColor ;
	
	/** ダイヤグラム線の線スタイル	
	-	0以上: entDed::CentDedRessyasyubetsu::ESenStyleの値 
	-	-1: 不定
	*/
	int iDiagramSenStyle ;

	/** 
	 ダイヤグラム線の線スタイルが太線か否かを指定します。
	-	0: OFF	
	-	1: ON	
	-	-1: 不定	
	*/
	int  iDiagramSenIsBold ;
	
	/**
	 停車駅明示の方法
	-	0以上: entDed::CentDedRessyasyubetsu::EStopMarkDrawType の値
	-	-1: 不定	
	*/
	int iStopMarkDrawType ;

	UIData_Ressyasyubetsu()
		: bSyubetsumeiIsEnable( true )
		, colorJikokuhyouMojiColor( 0 , 0 , 0 )
		, iJikokuhyouFontIndex( 0 ) 
		, colorDiagramSenColor( 0 , 0 , 0 )
		, iDiagramSenStyle( (int)CentDedRessyasyubetsu::SenStyle_Jissen )
		, iDiagramSenIsBold( 0 ) 
		, iStopMarkDrawType( (int)CentDedRessyasyubetsu::EStopMarkDrawType_DrawOnStop )
	{
	}
};



/**
@brief
  列車種別プロパティの編集を行うクラスです。
  
  このクラスは抽象クラスです。
  このクラスは、使用するUI環境(例：Windows,MFC)には依存しません。
　クラスユーザーは、このクラスを継承して、
 『オーバーライトの必要なメソッド2-UIに依存する処理』の仮想関数に、
 UI環境に依存した処理を実装してください。

*/
class CPropEditUi_Ressyasyubetsu : public CPropEditUi2< UIData_Ressyasyubetsu >
{
public:
	// ********************************
	///@name エラーメッセージ
	// ********************************
	///@{
	/// 種別名が指定されていません
	static const char* const ERRMSG_SYUBETUSMEI_EMPTY ;

	/// 略称が長すぎます(略称は6文字まで(半角)です)
	static const char* const ERRMSG_RYAKUSYOULENGTH ;
	///@}
	

private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
	　Target(編集対象のプロパティを保持する変数へのポインタ)。 
	　コンストラクタで決まります。
	*/
	Mu<CentDedRessyasyubetsu*>* m_pTarget ;

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
	//virtual void InitUiData( UIDATA* pUiData ) ;

	/**
		UiData に、Targetの属性を反映します。
		
		m_bNewItem が false の場合にだけ、 CPropEditUi2::StartEdit() 
		から呼び出されます。
		
		クラスユーザーは、この関数をオーバーライドして、
		Target の内容をUiData に反映する処理を実装してください。

	@param pUiData [out]
		UiData のオブジェクト。
	*/
	virtual void UiDataFromTarget( UIDATA* pUiData ) ; 

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
		bool bStartEdit );

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
		
	@param bNewItem
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
		const UIDATA* pUiDataStartEdit ) ;
	
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
		const UIDATA* pUiDataStartEdit ) ;
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
		const std::string& strInfo = "" ) =0 ;
	
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


public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	@param bNewItem 
		編集対象を指定してください。
		- true: 新規オブジェクトに対する、プロパティの編集
		- false: 既存オブジェクトに対する、プロパティの編集
	@param pTarget [in,out]
	　Target(編集対象のプロパティを保持する変数へのポインタ)。 
	　コンストラクタで決まります。
	*/
	CPropEditUi_Ressyasyubetsu( 
		bool bNewItem , 
		Mu<CentDedRessyasyubetsu*>* pTarget );
	
};

} //namespace ViewRessyasyubetsu 



#endif /*CPropEditUi_Ressyasyubetsu_h*/
