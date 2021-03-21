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
// $Id: CconvContentPosToTarget.h 262 2016-01-23 07:19:44Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdCd_Pos_CconvContentPosToTarget_h
#define  DcDraw_DcdCd_Pos_CconvContentPosToTarget_h
#include "DcdCd\Pos\DcdType.h"
#include "DcdCd\Pos\CdDcdZone.h"

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CconvContentPosToTarget
// ****************************************************************
/**
@brief
  CconvContentPosToTarget は、1次元のContentPos(コンテント座標)を
TargetPos(ターゲット座標)に変換する方法を提供するクラスです。
	
<h2>
＜1＞概要
</h2>

  このクラスは、以下のような場合を想定しています。
  
  「高さ2cm,幅3cm,左上頂点位置が原点から右1.5cm,下1cmの長方形を、
幅200pixel,高さ200pixelのクライアント領域を持つウインドウの
座標(10,10)-(190,190)に描画するとき、cm単位で表される各頂点座標を
ウインドウのピクセル座標に変換する」
 
  但し、このクラスは、1次元の座標変換しかできません。X,Y2次元の座標を
変換するためには、このクラスのインスタンスをX,Y それぞれに(計２つ)
作成する必要があります。


<h3>
このクラスで使用する、座標を表す呼称
</h3>

(1)ContentPos(コンテント座標)

　描画したいコンテントに固有の座標です。左上原点です。
　『使用例』の場合、「左上頂点位置が～」ではじまる、cm単位の座標がこれに
該当します。

(2)TargetPos(描画対象座標)

　コンテントを描画する対象のデバイスの座標。左上原点です。
　『使用例』の場合、「幅200pixel,高さ200pixelのクライアント領域を持つ
ウインドウ」の、クライアント領域の座標が、これにあたります。

(3)TargetZone(描画対象領域)

　コンテントを描画する対象のデバイスにおいて、コンテントを描画する領域。
　この領域を表す座標系は、TargetPos(描画対象座標)です。
　使用例の場合、「ウインドウの座標(10,10)-(190,190)」が、TargetZoneに
あたります。



<h2>
＜2＞TargetPosへの変換モード
</h2>

　このクラスは、ContentPos をTargetPos 変換する方法として、以下の2モードを
用意しています。クラスユーザーは、そのうちの一つを選択できます。また、
使用中に切り替えることもできます。

 - (1)PosAndRate
 - (2)Zone
	
(1)PosAndRate

　以下の属性をもとに変換を行います。

- ContentPos　(始点座標)(TargetPosの左上に描画されるContentの、ContentPos座標)
- TargetPosPerContent(拡大率)

　このモードでは、TargetZoneの大きさが変わっても、表示されるコンテントの
大きさ・形状は変わりません。コンテントの表示範囲だけが変わります。

　※TargetPosPerContent(拡大率) は、浮動小数点です。


(2)Zone

　以下の属性をもとに変換をおこないます。

- ContentPos　(始点座標)
- ContentSize　(TargetZoneに表示するコンテントの大きさ)

このモードでは、TargetZoneの大きさが変わると、表示されるコンテントの大きさ、
形状が変わります。コンテントの表示範囲は変わりません。


<h2>
＜3＞属性の同期 SynchronizeProp 
</h2>

　このクラスは、属性TargetPosPerContent と ContentSize の間の同期を
常に保ち、矛盾が発生しないようにします。この機能を、
『属性の同期』SynchronizeProp と呼称します。
　
　『属性の同期』は、以下のように動作します。

<h3>
(1)属性設定時の同期
</h3>

　PosAndRate モードでは通常、属性 ContentPos と TargetPosPerContent を
指定します。しかし、TargetPosPerContent の代わりに ContentSize を指定する
こともできます。
　同様に、Zone モードでも、TargetPosPerContent を指定することができます。

　クラスユーザーが TargetPosPerContent を設定すると、このクラスは
 ContentSize を『属性設定同期待ち』状態にします。
  TargetZone を指定する操作が行われたとき、ContentSizeが　
『属性設定同期待ち』なら、このクラスは TargetZoneとTargetPosPerContentから、
ContentSizeを算出・設定します。このとき、ContentSizeの『属性設定同期待ち』
は解除されます。

　TargetZone を指定する操作において、TargetZone.Sizeが0の場合、TargetZone
 にNULLが指定された場合は、上記の同期処理は行われません。この場合は、
 『属性設定同期待ち』は解除されず、ContentSize はそれまでの値を保持します。

　上記の動作は、クラスユーザーが ContentSize を指定した場合でも同様です。ContentSizeを指定した場合は、TargetPosPerContent が『属性設定同期待ち』状態になります。

<h3>
(2)属性取得時の同期
</h3>

　PosAndRate モードで、クラスユーザーが TargetZone を指定する操作を行うと、
このクラスは TargetZoneとTargetPosPerContentから、ContentSizeを算出・
設定します。
  
  但し、TargetZone を指定する操作において、TargetZone.Sizeが0の場合、
TargetZone にNULLが指定された場合は、上記の同期処理は行われません。
  この場合は、ContentSize はそれまでの値を保持します。

　上記の動作は、Zone モードでも同様です。このクラスは、TargetZoneと
ContentSizeから、TargetPosPerContent を算出・設定します。



<h2>
＜4＞プロパティのキャッシュ PropCache
</h2>

　前述の通り、このクラスは、ユーザーが「TargetZoneを指定する操作」を
行うたびに『属性の同期』SynchronizeProp を行います。
　但し、指定された TargetZone の Size が前回と同じなら、
属性の同期 SynchronizeProp を行いません。これを、『プロパティのキャッシュ』
PropCache と呼称します。
　PropCache により、(1)属性を設定し、(2)直前に指定した属性を取得 したとき、
(1)で設定した値と(2)で取得した値が等しいことが保証されます。

<h3>
【補足】プロパティのキャッシュ PropCache を行わなかった場合
</h3>
　プロパティのキャッシュ PropCache を行わなかった場合は、PosAndRateモードで
 ContentSize を設定し、直後に ContentSize を取得しても、設定した値と異なる
 値が取得されることがあります。原因は、ContentSizeからTargetPosPerContent
  を求める演算、およびその逆の演算で、端数による誤差が生じるためです。

　プロパティのキャッシュを行わない場合の動作は以下のようになります。

(1)ContentSizeを設定

　OuDia は、 ContentSizeとTargetZone のSizeから、TargetPosPerContent を
算出し、更新する。

(2)ContentSize を取得

　属性の同期処理が実行される。
　OuDiaは、TargetPosPerContentと TargetZone の Size から、ContentSize を
算出し、更新する。

　(1)と(2)の処理はいずれも、端数誤差の発生の可能性があります。これが
積み重なるため、(1)で設定した ContentSize と (2)で取得した ContentSize 
が不一致になる可能性があります。

*/
class CconvContentPosToTarget
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/** TargetPosへの変換モード */
	enum EMode
	{
		/**
			以下の属性をもとに、ContentPos と TargetPos の間の変換を行います。

		- ContentPos　(始点座標)(TargetPosの左上に描画されるContentの、ContentPos座標)
		- TargetPosPerContent(拡大率)
		*/
		EModePosAndRate ,	
		/**
			以下の属性をもとに、ContentPos と TargetPos の間の変換を行います。

			- ContentPos　(始点座標)
			- ContentSize　(TargetZoneに表示するコンテントの大きさ)
		*/
		EModeZone ,		
	};
	/** プロパティの同期 の状態 */
	enum ESynchronizeState
	{
		/// 属性設定同期待ち なし
		ESynchronizeState_None ,	
		/// m_dTargetPosPerContent が属性設定同期待ち。
		ESynchronizeState_TargetPosPerContent ,	
		/// m_iContentSize が属性設定同期待ち。
		ESynchronizeState_ContentSize ,	
	};
	
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		TargetPosへの変換モード 
	*/
	EMode	m_eMode ;
	/**
		始点座標。
		
		TargetPosの左上に描画されるContentの、ContentPos座標。

		既定値=0 
	*/
	DcdPos	m_iContentPos ;
	
	/**
		拡大率。コンテント座標１あたりの、TargetPos の数。

		既定値=1。
	*/
	double m_dTargetPosPerContent ;
	
	/**
		TargetZoneに表示するコンテントの大きさ。

		既定値=1。
	*/
	DcdSize	m_iContentSize ;

	///@}
private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/** 
		プロパティの同期 の状態 
	*/
	ESynchronizeState	m_eSynchronizeState ;
	/**	
		プロパティのキャッシュを実施するための、TargetZone.Size の前回値。
		初期値は0。
	*/
	DcdSize m_iTargetSize_Prev ;
	///@}

protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**	
		TargetPosPerContent の値から、ContentSize を導出します。
	@param dTargetPosPerContent 
		TargetPosPerContent の値を指定してください。
	@param pTargetZone
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		NULLは指定できません。
	@return 
		ContentSize の値を返します。
		dTargetPosPerContent・pTargetZone->getSize() のどちらかが0なら、
		戻り値は 0 です。
	*/
	DcdSize TargetPosPerContentToContentSize( 
		double dTargetPosPerContent , 
		const CdDcdZone* pTargetZone ) ;

	/**	
		ContentSize の値から、 TargetPosPerContent を導出します。
	@param dTargetPosPerContent 
		ContentSize の値を指定してください。
	@param pTargetZone
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		NULLは指定できません。
	@return 
		TargetPosPerContent の値を返します。
		iContentSize・pTargetZone->getSize() のどちらかが0なら、
		戻り値は 0 です。
	*/
	double TargetPosPerContentFromContentSize( 
		DcdSize iContentSize , 
		const CdDcdZone* pTargetZone ) ;
	/**	
		プロパティの同期
	*/
	void synchronizeProp( const CdDcdZone* pTargetZone ) ;
	///@}
	
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/** m_eMode を EModePosAndRate として初期化します。*/
	CconvContentPosToTarget() ;

	/** m_eMode を指定して初期化します。*/
	CconvContentPosToTarget( 
		EMode	eMode ) ;
	/**
		m_eMode を EModePosAndRate として初期化します。
	@param iContentPos [in]
		TargetPosの左上に描画されるContentの、ContentPos座標。
	@param dTargetPosPerContent [in]
		拡大率。コンテント座標１あたりの、TargetPos の数。
	*/
	CconvContentPosToTarget( 
		DcdPos	iContentPos ,
		double dTargetPosPerContent ) ;
	/** 
		m_eMode を EModeZone として初期化します。
	@param zoneContent[in]
		TargetZoneに表示するコンテントの始点と大きさ。
		このコンストラクタは、
		zoneContent.getPos() を m_iContentPosに、
		zoneContent.getSize() を、m_iContentSize に
		初期化します。
	*/
	CconvContentPosToTarget( 
		const CdDcdZone&	zoneContent ) ;
public:
	// ********************************
	///@name CconvContentPosToTarget-属性
	// ********************************
	///@{
	EMode	getMode()const ;
	void setMode( EMode	value ) ;

	DcdPos	getContentPos()const ;
	void setContentPos( DcdPos value ) ;

	double getTargetPosPerContent()const ;
	DcdSize	getContentSize()const ;
	///@}
	
	// ********************************
	///@name CconvContentPosToTarget-TargetPosPerContent,ContentSize 取得・設定
	// ********************************
	///@{
	/**
		拡大率を取得することができます。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定
		してください。
		m_eMode=EModePosAndRate のときは、この値は省略することができます。
		m_eMode=EModeZone のときは必須です。
	@return
		拡大率。コンテント座標１あたりの、TargetPos の数。

	*/
	double getTargetPosPerContent( 
		const CdDcdZone* pTargetZone ) ;

	/**
		拡大率を設定することができます。
	@param value[in]
		拡大率。コンテント座標１あたりの、TargetPos の数。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModePosAndRate のときは、この値は省略することができます。
		m_eMode=EModeZone のときは必須です。
	*/
	void setTargetPosPerContent( double value , 
		const CdDcdZone* pTargetZone ) ;

	/**
		TargetZoneに表示するコンテントの大きさを取得することができます。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModeZone のときは、この値は省略することができます。
		m_eMode=EModePosAndRate のときは必須です。
	@return
		TargetZoneに表示するコンテントの大きさ。
	*/
	DcdSize getContentSize( const CdDcdZone* pTargetZone ) ;

	/**
		TargetZoneに表示するコンテントの大きさを設定することができます。
	@param value[in]
		TargetZoneに表示するコンテントの大きさ。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModeZone のときは、この値は省略することができます。
		m_eMode=EModePosAndRate のときは必須です。
	*/
	void setContentSize( DcdSize value , const CdDcdZone* pTargetZone ) ;

	/**
		TargetZoneに表示するコンテントの始点と拡大率を設定することができます。
	@param posContentPos [in]
		TargetPosの左上に描画されるContentの、ContentPos座標。
	@param dTargetPosPerContentX [in]
		拡大率。コンテント座標１あたりの、TargetPos の数。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode= EModePosAndRate のときは、この値は省略することができます。
		m_eMode= EModeZone のときは必須です。
	*/
	void setContentPosAndRate( 
		DcdPos posContentPos , 
		double dTargetPosPerContent ,
		const CdDcdZone* pTargetZone ) ;

	/** 
		TargetZoneに表示するコンテントの始点と大きさを取得することができます。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModeZone のときは、この値は省略することができます。
		m_eMode=EModePosAndRate のときは必須です。
	@return
		TargetZoneに表示するコンテントの位置と大きさ。
	*/
	CdDcdZone getContentZone( const CdDcdZone* pTargetZone ) ;

	/**
		TargetZoneに表示するコンテントの始点と大きさを設定することができます。
	@param zoneContent[in]
		TargetZoneに表示するコンテントの始点と大きさ。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModeZone のときは、この値は省略することができます。
		m_eMode=EModePosAndRate のときは必須です。
	*/
	void setContentZone( const CdDcdZone& zoneContent , 
		const CdDcdZone* pTargetZone ) ;


	///@}
	// ********************************
	///@name CconvContentPosToTarget-座標変換
	// ********************************
	///@{
	/**
		ContentPos 上の座標を、TargetZone 上の座標に変換します。
	@param posContent [in]
		変換対象の座標を指定してください。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	*/
	DcdPos	ContentPosToTarget( 
		DcdPos posContent , const CdDcdZone& aTargetZone ) ;

	/**
		ContentPos 上の座標を、TargetZone 上の座標に変換します。
	@param posContent [in]
		変換対象の座標を指定してください。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	*/
	CdDcdZone	ContentZoneToTarget( 
		const CdDcdZone& zoneContent , const CdDcdZone& aTargetZone ) ;

	/**
		TargetZone 上の座標を、ContentPos に変換します。
	@param posTarget[in]
		変換対象の座標を指定してください。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	*/
	DcdPos	ContentPosFromTarget( 
		DcdPos posTarget , const CdDcdZone& aTargetZone ) ;

	/**
		TargetZone 上の座標を、ContentPos に変換します。
	@param zoneTarget [in]
		変換対象の座標を指定してください。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	*/
	CdDcdZone	ContentZoneFromTarget( 
		const CdDcdZone& zoneTarget , const CdDcdZone& aTargetZone ) ;

	///@}
};

} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib

#endif /*DcDraw_DcdCd_Pos_CconvDcdPosOnZone_h*/
