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
//	CDcdDiagram2.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdDiagram2_h
#define  CDcdDiagram2_h

#include "CDcdDiagram.h"
#include "DcDraw\CDcdText.h"

namespace ViewDiagram{

// ****************************************************************
//	CDcdDiagram2
// ****************************************************************
/**
	@brief
	【概要】
	『ダイヤグラムエンティティクラス群』の属性をもとに、 IfDcdTarget 
	オブジェクトに『ダイヤグラム』を描画します。
	
	このクラスは、
	- ダイヤグラムのグラフ部分
	- 上側の時の表示
	- 左側の駅名表示

	を、IfDcdTarget オブジェクトの領域の全面に描画します。

	このうちの『ダイヤグラムのグラフ部分』は、CDcdDiagramを
	使って描画します。このクラスのオブジェクトは、 CDcdDiagram を包含します。
	包含している CDcdDiagram の属性は、このクラスのメソッドから設定することが
	できます。
	
	
	このクラスのオブジェクトは、『ダイヤグラムダイヤ』 CentDedDgrDia 
	オブジェクトと関連をもちます。
	
	<H4>
	【使い方】
	</H4>
	  通常、このクラスのオブジェクトは、ダイヤグラムを表示する
	ウインドウが包含することになります。

	１．  このクラスのオブジェクトを生成する前に、
	 CentDedDgrDia オブジェクトを生成し、 CentDedDgrDia::readCentDedDia() で
	CentDedDia の内容を読み込ませておいて下さい。
	
	２．  このクラスのオブジェクトを生成してください。コンストラクタでは、
	１．で生成した CentDedDgrDia オブジェクトを指定します。これにより、
	生成したオブジェクトは、 CentDedDgrDia オブジェクトとの関連を確立します
	（ setCentDedDgrDia() で、あとから関連を確立することもできます。

	３．  表示に関する各種属性を指定して下さい。
	コンストラクタで CdDedDispProp オブジェクトを引数に渡すか、
	readCdDedDispProp() を使うと、表示に関する属性を一度に設定することが
	できます。
	
	４．  表示に関する属性のうち、CdDedDispProp に格納されない属性
		CDcdDiagram::m_posPosDgr,
		CDcdDiagram::m_dDcdPerDgrX,
		CDcdDiagram::m_dDcdPerDgrY
		CDcdDiagram::m_idxVlineMode , 
		CDcdDiagram::m_bDisplayRessyasenKudari , 
		CDcdDiagram::m_bDisplayRessyasenNobori ,
		CDcdDiagram::m_eStopMarkDraw
		CDcdDiagram2::m_bHideIppanekiEkimei
	を指定して下さい。
	
	５．  あとは、 IfDcDraw::DcDraw() メソッドで、ダイヤグラムを描画することが
	できます。
	
*/
class CDcdDiagram2 : public IfDcDraw 
{
public:
	// ********************************
	///@name 定数
	// ********************************
	///@{
	/** 
	@return
		既定の 『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数 
		を返します。
	*/
	static double DEFAULT_DCD_PER_DGR_X()
	{	return CDcdDiagram::DEFAULT_DCD_PER_DGR_X() ;}; 
	/** 
	@see DEFAULT_DCD_PER_DGR_X 
	*/
	static double DEFAULT_DCD_PER_DGR_Y()
	{	return CDcdDiagram::DEFAULT_DCD_PER_DGR_Y() ;};
	///@}
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	///@}
private:
	// ********************************
	///@name 属性-CdDedDispProp から読み込み可能
	// ********************************
	///@{
	/**
	 	ダイヤ画面駅名フォント。
		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaEkimeiFont ;

	/**
		 ダイヤ画面時刻フォント。
		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaJikokuFont ;

	
	/**
		 ダイヤ画面文字色。
		規定値は、黒。
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp をもとに
		readCdDedDispProp() で決まります。
	 */
	CdColorProp	m_colorDiaMojiColor ;

	/**
		駅名欄の幅を保持します。
		単位は、全角での文字数です。
		つまり、駅名欄の幅は、
	
			文字の高さ × m_iEkimeiLength 
		
		となります。
		デフォルト値は 6 とします。最小値は 1 です。
	 */
	int m_iEkimeiLength ;


	///@}
	// ********************************
	///@name 属性-CdDedDispProp にはないもの
	// ********************************
	///@{
	/**
		一般駅の駅名表示を隠す指定です。
		- false ;	//	すべての駅名を表示します。(default)
		- true ;	//	一般駅の駅名を表示しません。
	*/
	bool m_bHideIppanekiEkimei ;
	///@}
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		『ダイヤグラムエンティティクラス群』の属性をもとに、 IfDcdTarget 
		オブジェクトに『ダイヤグラム』を描画します。
		
		このクラスは、ダイヤグラムのグラフ部分だけを描画します。
		枠外の時表示・	駅名表示は描画しません。
	
		このオブジェクトの破棄の責務は、this にあります。
		このオブジェクトは、コンストラクタで生成・デストラクタで破棄します。
	 */
	CDcdDiagram*	m_pCDcdDiagram ;
	///@}	

protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
	 @return
		細い罫線の、線の属性を返します。
	 */
	CdDcdFreeLineProp	getCdLinePropNormal()const;
	/**
	 @return
		太い罫線の、線の属性を返します。
	 */
	CdDcdFreeLineProp	getCdLinePropBold()const;


	/**
	 @return
		時の表示を行うための、
		DcDraw オブジェクトを生成して返します。
	 */
	CDcdText	getCDcdTextJikoku()const ;
	/**
	 @return
		駅名の表示を行うための、
		DcDraw オブジェクトを生成して返します。
	 */
	CDcdText	getCDcdTextEkimei()const ;


	///@}	
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	
	/**
	 @param pCentDedDgrDia [in]
		『ダイヤグラムダイヤ』オブジェクトです。
		\n this は、このオブジェクトからダイヤグラムの情報を取得し、
		描画を行います。
		\n このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this の破棄が完了するまで
		生存しなくてはなりません。
	 @param aCdDedDispProp [in]
		このコンストラクタは、 CdDedDispProp オブジェクトの属性から、
		ダイヤグラムの各部の色やフォントの属性を決定します。
	 @see setCdDedDispProp() 
	 */
	CDcdDiagram2( 
		CentDedDgrDia*	pCentDedDgrDia , 
		const CdDedDispProp& aCdDedDispProp ) ;
	/**
		このコンストラクタを使った場合は、
		 setCentDedDgrDia() で、 CentDedDgrDia オブジェクトとの関連を
		確立しなくてはなりません。
	 */
	CDcdDiagram2() ; 
	virtual ~CDcdDiagram2() ;
	
public:
	// ********************************
	///@name IfDcDraw
	// ********************************
	///@{
	/**
	 	描画を要求します。
	 	この関数は、 pIfDcdTarget に、描画を行います。
	 @param pIfDcdTarget  [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 @return
	 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
	
		【オーバライド】
		ダイヤグラムの描画を行います。
	 */
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 	このオブジェクトが描画するアイテムの大きさが決まっている場合は、
	 	その大きさを調べることができます。
	 	関数呼び出し元が複数の IfDcDraw オブジェクトを描画する場合には、
	 	関数呼び出し元は、この関数でアイテムの大きさを調べて、
	 	適切なレイアウトを考えてから、DcDraw() を実行することができます。
	 @param pIfDcdTarget [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 @param pCdDcdSizeXy [out]
	 	このオブジェクトの描画するアイテムの大きさが決まっている場合は、
	 	この関数はこのアドレスに、そのアイテムのサイズを返します。
	 	このオブジェクトの描画するアイテムの大きさが決まっていない場合は、
	 	この値は不定です。
	 @return
	 	このオブジェクトの描画するアイテムの大きさが決まっていて、
	 	その大きさを *pCdDcdSizeXyに書き込んだ場合は真です。
	 	そうでない場合は、偽です。
	
		【オーバライド】
		このクラスではサポートしません。falseを返します。
	 */
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	
	///@}
public:
	// ********************************
	///@name CDcdDiagram-関連
	// ********************************
	///@{
	CentDedDgrDia*	getCentDedDgrDia() ;
	CDcdDiagram2& setCentDedDgrDia( CentDedDgrDia* value ) ;
	///@}

public:
	// ********************************
	///@name CDcdDiagram-属性-CdDedDispProp から読み込み可能
	// ********************************
	///@{
	CdFontProp	getDiaRessyaFont()const ;
	CDcdDiagram2& setDiaRessyaFont( const CdFontProp& value ) ;
	CdColorProp	getDiaHaikeiColor()const ;
	CDcdDiagram2& setDiaHaikeiColor( CdColorProp value ) ;
	CdColorProp	getDiaJikuColor()const ;
	CDcdDiagram2& setDiaJikuColor( CdColorProp value ) ;

	///@}
public:
	// ********************************
	///@name CDcdDiagram-属性-CdDedDispProp にはないもの
	// ********************************
	///@{
	bool	getDisplayRessyabangou()const ;
	CDcdDiagram2& setDisplayRessyabangou( bool value ) ;
	bool	getDisplayRessyamei()const ;
	CDcdDiagram2& setDisplayRessyamei( bool value ) ;
	/**
	@return
		ダイヤグラムエンティティ座標をDcDraw座標に変換する
		オブジェクトを返します。
	*/
	CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()
	{
		return m_pCDcdDiagram->getCconvContentPosToDcdTarget() ;
	};
	/**
	@return
		ダイヤグラムエンティティ座標をDcDraw座標に変換する
		オブジェクトを返します。
	*/
	const CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()const
	{
		return m_pCDcdDiagram->getCconvContentPosToDcdTarget() ;
	};

	/**
	@return
		TargetPosの左上に描画される『ダイヤグラム座標』。 
	*/
	CdDcdPosXy	getPosDgr()const
	{	return m_pCDcdDiagram->getPosDgr() ;};

	/**
	TargetPosの左上に描画される『ダイヤグラム座標』を指定します。
		
	@param posPosDgr [in]
		TargetPosの左上に描画される『ダイヤグラム座標』。
	*/
	void setPosDgr( CdDcdPosXy posPosDgr )
	{	m_pCDcdDiagram->setPosDgr( posPosDgr ) ;};

	/**
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数を取得します。
	@param pIfDcdTarger [in]
		描画対象を指定してください。
	@return 
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数。
	*/
	double getDcdPerDgrX( IfDcdTarget* pIfDcdTarget ) ;

	/**
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数を設定します。
	@param pIfDcdTarger [in]
		描画対象を指定してください。
	@param dDcdPerDgr [in] 
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数。
	*/
	void setDcdPerDgrX(  IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) ;

	/**
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数を取得します。
	@param pIfDcdTarger [in]
		描画対象を指定してください。
	@return 
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数。
	*/
	double getDcdPerDgrY( IfDcdTarget* pIfDcdTarget ) ;

	/**
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数を設定します。
	@param pIfDcdTarger [in]
		描画対象を指定してください。
	@param dDcdPerDgr [in] 
		『ダイヤグラム座標』の1に対応する、
		『DcDraw座標(論理座標)』の数。
	*/
	void setDcdPerDgrY( IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) ;



	int	getVlineMode()const ;
	CDcdDiagram2& setVlineMode( int value ) ;
	
	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		の値を取得します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari ;	//	下り列車 (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	上り列車 (m_bDisplayRessyasenNobori)
	 @return 
		- true ;	//	列車線を表示する
		- false ;	//	列車線を表示しない
	 */
	bool getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const ;
	
	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		の値を設定します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari ;	//	下り列車 (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	上り列車 (m_bDisplayRessyasenNobori)
	 @param value [in]
		- true ;	//	列車線を表示する
		- false ;	//	列車線を表示しない
	 */
	CDcdDiagram2& setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) ;
	
	CDcdDiagram::EStopMarkDraw	getStopMarkDraw()const
	{	return m_pCDcdDiagram->getStopMarkDraw() ;};
	void setStopMarkDraw( CDcdDiagram::EStopMarkDraw	value )
	{	m_pCDcdDiagram->setStopMarkDraw( value ) ;};
	
	/**
	 @return
		縦罫の間隔。
	
		この値は、単位は、『ダイヤグラムエンティティX座標』、
		すなわち秒です。
		つまり、この値が６０*２なら、thisが描画するダイヤは
		「２分目ダイヤ」となります。
		m_idxVlineMode から導出されます。
	 */
	int getVlinePitch()const ;
	
	/**
	 @return
		縦罫うち、実線の間隔。
	
		この値は、単位は、『ダイヤグラムエンティティX座標』、
		すなわち秒です。
		この値は、60分の約数でなくてはなりません。また、
		m_iVlinePitch の倍数でなくてはなりません。
	 */
	int getVlineMiddlePitch()const ; 

	/**
	 @return
		縦罫のうち、太線の間隔。
	
		この値は、単位は、『ダイヤグラムエンティティX座標』、
		すなわち秒です。
		この値は、60分の約数でなくてはなりません。また、
		m_iVlinePitch の倍数でなくてはなりません。
		m_idxVlineMode から導出されます。
	 */
	int getVlineBoldPitch()const ;
	
	
	/**
		このクラスがサポートする、
		縦罫の間隔の設定の選択肢を取得することができます。
	 @param pContVLINE [out]
		この関数はこのコンテナに、縦罫の間隔の設定を書き込みます。
		コンテナがそれまで保持していた要素は破棄します。
		このコンテナのインデクスは、m_idxVlineMode に対応します。
		不要であれば NULL でもかまいません。
	 @return
		選択肢の数を返します。	
	 */
	int getVlineChoices( Mui<CDcdDiagram::VLINE>* pContVLINE )const ;

	///@}

public:
	// ********************************
	///@name CDcdDiagram-操作
	// ********************************
	///@{
	/**
		CdDedDispProp オブジェクトの属性から、 
		ダイヤグラムの各部の色やフォントの属性を決定します。
		このメソッドが設定するメソッドは、以下のものです。
	
		- CDcdDiagram
			- CdFontProp	m_fontpropDiaRessyaFont ;
			- CdColorProp	m_colorDiaHaikeiColor ;
			- CdColorProp	m_colorDiaRessyaColor ;
			- CdColorProp	m_colorDiaJikuColor ;
			- bool	m_bDisplayRessyabangou ;
			- bool	m_bDisplayRessyamei ;
			- int m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
			- int m_iDiaRessyajouhouHyoujiEkiOrderNobori ;
	
		- CDcdDiagram2
			- CdFontProp	m_fontpropDiaEkimeiFont ;
			- CdFontProp	m_fontpropDiaJikokuFont ;
			- CdColorProp	m_colorDiaMojiColor ;
			- int m_iEkimeiLength
		
	 @param value [in]
		CdDedDispProp オブジェクトを指定して下さい。
	 */	
	CDcdDiagram2& readCdDedDispProp( const CdDedDispProp& value ) ;

	/**
		このクラスが描画を行う領域の座標を、
	 	『ダイヤグラムエンティティ座標系』で取得します。
		この値は、m_posDgr・m_dwDcdPerDgrX・m_dwDcdPerDgrY から
		導出されます。
	@param pIfDcdTarger [in]
		描画対象を指定してください。
	@return 
		このクラスが描画を行う領域の座標を
		『ダイヤグラムエンティティ座標系』で返します。
	@attention
		pIfDcdTarget へのダイヤグラム表示が不可能な場合、
		戻り値のgetX().getSize() , getY().getSize() のいずれかが
		0になります。
	*/
	CdDcdZoneXy	getZone_Dgr( IfDcdTarget* pIfDcdTarget )const ;

	/**
		このクラスが描画を行う領域の座標を、
	 	『ダイヤグラムエンティティ座標系』で設定します。
		この値は、m_posDgr・m_dwDcdPerDgrX・m_dwDcdPerDgrY に
		換算のうえで設定されます。
	@param pIfDcdTarger [in]
		描画対象を指定してください。
	@param value [in]
		このクラスが描画を行う領域の座標を
		『ダイヤグラムエンティティ座標系』で指定してください。

		ダイヤグラムが pIfDcdTarget 内に描画できない場合は、
		setZone_Dgr() は動作しません。
	*/
	CDcdDiagram2& setZone_Dgr( 
		IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& value ) ;

	/**
		ウインドウサイズ変更時の動作を取得します。
	@return 
		- false:表示範囲を変更(OuDia Ver.1.00.04 より後)
		- true: 表示範囲を変更しない(OuDia Ver.1.00.04 互換)
	*/
	bool getKeepZoneDgrOnSize()const
	{
		return m_pCDcdDiagram->getKeepZoneDgrOnSize() ;
	}

	/**
		ウインドウサイズ変更時の動作を設定します。
	@return 
		- false:表示範囲を変更(OuDia Ver.1.00.04 より後)
		- true: 表示範囲を変更しない(OuDia Ver.1.00.04 互換)
	*/
	void setKeepZoneDgrOnSize( bool bRv )
	{
		m_pCDcdDiagram->setKeepZoneDgrOnSize( bRv ) ;
	}

	/**
		指定の座標位置を通っている列車線を探します。
		
	 @param pIfDcdTarget [in]
		描画対象を指定して下さい。
	 @param aCdDcdPosXy [in]
		列車線を探す座標を指定して下さい。
	 @param iMerginPixels [in]
		この関数は、指定の座標と列車線との距離が
		このピクセル数以下であれば、
		座標位置を列車線が通っているとみなします。
		0 なら、列車線が座標位置を完全に通っている場合のみ
		該当列車線とみなします。
	 @param pERessyahoukou [out]
		この関数は、列車線が見つかった場合は、
		列車線の方向を書き込みます。
	 @param piRessyaIdx [out]
		この関数は、列車線が見つかった場合は、
		列車Indexを書き込みます。
	 @param piRessyasenIdx [out]
		この関数は、列車線が見つかった場合は、
		列車線Indexを書き込みます。
	 @return
		-	1 ;	//	列車線がみつかりました。
		-	0 ;	//	列車線がみつかりません。
	 */
	virtual int calcCentDedDgrRessyasenOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy , 
		int iMerginPixels , 
		ERessyahoukou *pERessyahoukou , 
		int *piRessyaIdx , 
		int *piRessyasenIdx ) ;
 
	/**
		指定の座標位置に対応する 駅Order を返します。
		
		この関数は、指定の座標位置 posY_Dcd から、
		指定の列車方向 eRessyahoukou の反対方向にある
		駅の駅Orderを返します。
		
		(eRessyahoukou が Ressyahoukou_Kudari なら posY_Dcd の上、
		eRessyahoukou が Ressyahoukou_Nobori なら posY_Dcd の下の
		駅Orderを返します)
		
	 @param pIfDcdTarget [in]
		描画対象を指定して下さい。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
	 @param posY_Dcd [in]
		Y座標の位置を指定してください。
		座標系は、 IfDcdTarget 上のものです。
	 @return
		成功したら、駅Order を返します。
		対応する 駅Order がない場合は、-1 です。
		posY_Dcdが 描画対象の範囲にない場合は、 -1 です。
	 */
	virtual int calcEkiOrderOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		ERessyahoukou eRessyahoukou ,
		DcdPos posY_Dcd ) ; 

	/**
		指定の座標位置に対応する 駅Index を返します。
		
		この関数は、指定の座標位置 posY_Dcd の下にある
		駅の駅Indexを返します。
		
	 @param pIfDcdTarget [in]
		描画対象を指定して下さい。
	 @param posY_Dcd [in]
		Y座標の位置を指定してください。
		座標系は、 IfDcdTarget 上のものです。
	 @return
		成功したら、駅Index を返します。
		対応する 駅Index がない場合は、-1 です。
		posY_Dcdが 描画対象の範囲にない場合は、 -1 です。
	 */
	virtual int calcEkiIndexOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		DcdPos posY_Dcd ) ; 

	///@}

public:
	// ********************************
	///@name CDcdDiagram-ダイヤグラム座標と、IfDcdTarget 上の座標を変換
	// ********************************
	///@{
	/**
		『ダイヤグラムエンティティ座標系』
		の X 座標の位置を、
		IfDcdTarget 
		の座標に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual DcdPos XDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		『ダイヤグラムエンティティ座標系』
		の Y 座標の位置を、
		IfDcdTarget の座標
		に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual DcdPos YDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		IfDcdTarget 
		の X 座標の位置を、
		『ダイヤグラムエンティティ座標系』
		の座標に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual DcdPos XDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		IfDcdTarget の座標
		の Y 座標の位置を、
		『ダイヤグラムエンティティ座標系』
		に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual DcdPos YDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) ;

	/**
		『ダイヤグラムエンティティ座標系』
		の X 座標の領域を、
		IfDcdTarget 
		の座標に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdZone XDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		『ダイヤグラムエンティティ座標系』
		の Y 座標の領域を
		IfDcdTarget の座標
		に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdZone YDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		IfDcdTarget 
		の X 座標の領域を、
		『ダイヤグラムエンティティ座標系』
		の座標に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdZone XDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		IfDcdTarget の座標
		の Y 座標の領域を、
		『ダイヤグラムエンティティ座標系』
		に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdZone YDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) ;

	/**
		『ダイヤグラムエンティティ座標系』
		の点を
		IfDcdTarget 
		の座標に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdPosXy DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) ;

	/**
		IfDcdTarget の座標
		の点を
		『ダイヤグラムエンティティ座標系』
		に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param posSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdPosXy DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) ;


	/**
		『ダイヤグラムエンティティ座標系』
		の矩形領域を、
		IfDcdTarget 
		の座標に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param zoneSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdZoneXy DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) ;

	/**
		IfDcdTarget の座標
		の矩形領域を、
		『ダイヤグラムエンティティ座標系』
		に変換します。
	 @param pIfDcdTarget [in]
		描画対象の IfDcdTarget オブジェクトを指定して下さい。
	 @param zoneSrc [in]
		変換前の座標を指定して下さい。	
	 @return
		変換後の座標を返します。
	 */
	virtual CdDcdZoneXy DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) ;
	///@}
public:
	// ********************************
	///@name CDcdDiagram2-属性
	// ********************************
	///@{
	CdFontProp	getDiaEkimeiFont()const ;
	CDcdDiagram2& setDiaEkimeiFont( const CdFontProp& value ) ;
	CdFontProp	getDiaJikokuFont()const ;
	CDcdDiagram2& setDiaJikokuFont( const CdFontProp& value ) ;
	CdColorProp	getDiaMojiColor()const ;
	CDcdDiagram2& setDiaMojiColor( CdColorProp value ) ;
	int getEkimeiLength(){	return m_iEkimeiLength ;};
	CDcdDiagram2& setEkimeiLength( int value ) ;
	bool getHideIppanekiEkimei()const ;
	CDcdDiagram2& setHideIppanekiEkimei( bool value )  ;

	///@}
public:
	// ********************************
	///@name CDcdDiagram2-操作
	// ********************************
	///@{
	/**
		 指定された IfDcdTarget オブジェクトの領域の中で、
		ダイヤグラムを描画する領域の大きさを求めます。
		単位は、 IfDcdTarget 上の座標です。
	 @param pIfDcdTarget [in]
		元になる描画領域を指定してください。
	 @return
		ダイヤグラムの描画領域を返します。
		この値の X,Y いずれかのサイズが0以下の場合、
		ダイヤグラムの描画はできません。
	 */
	virtual CdDcdZoneXy calcDiagramZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const ;
	/**
		 指定された IfDcdTarget オブジェクトの領域の中で、
		駅を描画する領域(左)の大きさを求めます。
		単位は、 IfDcdTarget 上の座標です。
	 @param pIfDcdTarget [in]
		元になる描画領域を指定してください。
	 @return
		ダイヤグラムの描画領域を返します。
		この値の X,Y いずれかのサイズが0以下の場合、
		ダイヤグラムの描画はできません。
	 */
	virtual CdDcdZoneXy calcEkimeiZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const ;
	
	/**
		 指定された IfDcdTarget オブジェクトの領域の中で、
		時刻を描画する領域(上)の大きさを求めます。
		単位は、 IfDcdTarget 上の座標です。
	 @param pIfDcdTarget [in]
		元になる描画領域を指定してください。
	 @return
		ダイヤグラムの描画領域を返します。
		この値の X,Y いずれかのサイズが0以下の場合、
		ダイヤグラムの描画はできません。
	 */
	virtual CdDcdZoneXy calcJikokuZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const ;

	///@}
	
};
} //namespace ViewDiagram

#endif /*CDcdDiagram2_h*/



