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
//	CDcdDiagram.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdDiagram_h
#define  CDcdDiagram_h

#include "DcDraw/IfDcDraw.h"
#include "DcdCd/DcDrawProp/CdFontProp.h"
#include "DcdCd/Pos/CconvDcdPosOnZoneXy.h"
#include "DcDraw\CconvContentPosToDcdTarget.h"
#include "..\entDgr\CentDedDgrDia.h"
#include "..\DedRosenFileData\CdDedDispProp.h"

namespace ViewDiagram{
	using namespace DcDrawLib::DcDraw;
	using namespace entDgr;
	using namespace DedRosenFileData;
// ****************************************************************
//	CDcdDiagram
// ****************************************************************
/**
	@brief
	【概要】
	『ダイヤグラムエンティティクラス群』の属性をもとに、 IfDcdTarget 
	オブジェクトに『ダイヤグラム』を描画します。
	
	このクラスは、ダイヤグラムのグラフ部分だけを描画します。枠外の時表示・
	駅名表示は描画しません。
	
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
	
	４．  表示に関する属性のうち、CdDedDispProp に格納されない属性	を指定して下さい。


		- CDcdDiagram::m_CconvContentPosToDcdTarget::m_CconvContentPosToTargetXy
			- m_convX::m_iContentPos
			- m_convX::m_dTargetPosPerContent
			- m_convY::m_iContentPos
			- m_convY::m_dTargetPosPerContent
		- CDcdDiagram::m_idxVlineMode , 
		- CDcdDiagram::m_bDisplayRessyasenKudari , 
		- CDcdDiagram::m_bDisplayRessyasenNobori 
		- CDcdDiagram::m_eStopMarkDraw
	
	５．  IfDcDraw::DcDraw() メソッドで、ダイヤグラムを描画することが
	できます。
	
 */
class CDcdDiagram : public IfDcDraw 
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	// ****************************************************************
	//	VLINE
	// ****************************************************************
	/**
	 @brief
		縦罫の間隔の設定内容を保持する構造体です。
	 */
	struct VLINE
	{
		/**
			縦罫の間隔。この線は、点線となります。
		
			この値は、単位は、『ダイヤグラムエンティティX座標』、
			すなわち秒です。
			つまり、この値が６０*２なら、thisが描画するダイヤは
			「２分目ダイヤ」となります。
			この値は、60分の約数でなくてはなりません。
		 */
		int m_iVlinePitch ;
		
		/**
			縦罫うち、実線の間隔。
		
			この値は、単位は、『ダイヤグラムエンティティX座標』、
			すなわち秒です。
			この値は、60分の約数でなくてはなりません。また、
			m_iVlinePitch の倍数でなくてはなりません。
		 */
		int m_iVlineMiddlePitch ;
		
		/**
			縦罫のうち、太線の間隔。
		
			この値は、単位は、『ダイヤグラムエンティティX座標』、
			すなわち秒です。
			この値は、60分の約数でなくてはなりません。また、
			m_iVlinePitch の倍数でなくてはなりません。
		 */
		int m_iVlineBoldPitch ;
		
		
	};



	/**
		ダイヤグラムビューに停車記号を表示するか否かを
		表す列挙です。
	*/
	enum EStopMarkDraw
	{
		/**
			停車駅明示=OFF
			
			停車駅明示を行いません。
		*/
		EStopMarkDraw_Nothing ,
		/**
			停車駅明示=ON

			短時間停車の駅に、停車駅を示す記号(○)を描画します。
		*/
		EStopMarkDraw_DrawOnBriefStop ,
	};
	
public:
	// ********************************
	///@name CDcdDiagram-定数
	// ********************************
	///@{
	/** 
	@return
		既定の 『ダイヤグラム座標』の1に対応する、『DcDraw座標(論理座標)』の数 
		を返します。
	*/
	static double DEFAULT_DCD_PER_DGR_X(){	return 0.05 ;}; 
	/** @see DEFAULT_DCD_PER_DGR_X */
	static double DEFAULT_DCD_PER_DGR_Y(){	return 0.05 ;};
	///@}
private:
	// ********************************
	///@name 定数
	// ********************************
	///@{
	/**
		縦罫の間隔の設定の選択肢。
		this は、この変数に格納されている設定内容から１つを選択して利用します。
	 */
	static const VLINE	m_arVline[8] ;
	///@}
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		『ダイヤグラムダイヤ』オブジェクトとの関連です。
	
		this は、このオブジェクトからダイヤグラムの情報を取得し、
		描画を行います。
	
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this の破棄が完了するまで
		生存しなくてはなりません。
	
		コンストラクタで決まります。
	 */
	CentDedDgrDia*	m_pCentDedDgrDia ;
	
	///@}

private:
	// ********************************
	///@name 属性-CdDedDispProp から読み込み可能
	// ********************************
	///@{
	/**
		 ダイヤ画面列車フォント。
		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp をもとに
		readCdDedDispProp() で決まります。
	 */
	CdFontProp	m_fontpropDiaRessyaFont ;

	/**
		 ダイヤ画面背景色。
		規定値は、白。
	
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp をもとに
		readCdDedDispProp() で決まります。
	 */
	CdColorProp	m_colorDiaHaikeiColor ;

	/**
		 ダイヤ画面縦横軸色。
		規定値は、黒。
	
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp をもとに
		readCdDedDispProp() で決まります。
	 */
	CdColorProp	m_colorDiaJikuColor ;

	/**
		 ダイヤ画面列車番号表示
		- true ;	//	ダイヤ画面に列車番号を表示する
		- false ;	//	ダイヤ画面に列車番号を表示しない
	
		規定値は、true。
	
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp をもとに
		readCdDedDispProp() で決まります。
	 */
	bool	m_bDisplayRessyabangou ;
	/**
		 ダイヤ画面列車名表示
		- true ;	//	ダイヤ画面に列車名を表示する
		- false ;	//	ダイヤ画面に列車名を表示しない
	
		規定値は、true。
	
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp をもとに
		readCdDedDispProp() で決まります。
	 */
	bool	m_bDisplayRessyamei ;
	
	
	///@}
	// ********************************
	///@name 属性-CdDedDispProp にはないもの
	// ********************************
	///@{
	/**
		『ダイヤグラムエンティティ座標』 を ContentPos 、
		IfDcdTarget を TargetPos とした
		双方の座標変換を行います。
	*/
	CconvContentPosToDcdTarget m_CconvContentPosToDcdTarget ;

	/**
		縦罫の間隔のモード。
		この値は、 m_arVline[] のインデクスとなります。
		既定値は 1 (２分目ダイヤ)とします。
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp には含まれていません。
	 */
	int	m_idxVlineMode ;

	/**
		下り列車の
		列車線を表示するか否かを指定します。
		- true ;	//	列車線を表示する
		- false ;	//	列車線を表示しない
		
		既定値は true 
	
		この値は、 
		CDedRosenFileData::m_CdDedDispProp には含まれていません。
	 */
	bool m_bDisplayRessyasenKudari ;

	/**
		上り列車の
		列車線を表示するか否かを指定します。
	 @see m_bDisplayRessyasenKudari
	 */
	bool m_bDisplayRessyasenNobori ;

	/**
		ダイヤグラムビューに停車記号を表示するか否かを
		表す列挙です。
	*/
	EStopMarkDraw	m_eStopMarkDraw ;
	///@}
protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		属性の正規化を行います。
		対象となるのは、以下の属性です。

		- m_dwDcdPerDgrX	0.0001〜10
		- m_dwDcdPerDgrY	0.0001〜10
	*/
	void adjustProp() ;


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
	CDcdDiagram( 
		CentDedDgrDia*	pCentDedDgrDia , 
		const CdDedDispProp& aCdDedDispProp ) ;
	CDcdDiagram() ; 
	virtual ~CDcdDiagram() ;
	
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
	 	その大きさをpCdDcdSizeXyに書き込んだ場合は真です。
	 	そうでない場合は、偽です。
	
		【オーバライド】
		サポートされません。偽を返します。
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
	CDcdDiagram& setCentDedDgrDia( CentDedDgrDia* value ) ;
	///@}

public:
	// ********************************
	///@name CDcdDiagram-属性-CdDedDispProp から読み込み可能
	// ********************************
	///@{
	CdFontProp	getDiaRessyaFont()const ;
	CDcdDiagram& setDiaRessyaFont( const CdFontProp& value ) ;
	CdColorProp	getDiaHaikeiColor()const ;
	CDcdDiagram& setDiaHaikeiColor( CdColorProp value ) ;

	CdColorProp	getDiaJikuColor()const ;
	CDcdDiagram& setDiaJikuColor( CdColorProp value ) ;
	
	///@}
public:
	// ********************************
	///@name CDcdDiagram-属性-CdDedDispProp にはないもの
	// ********************************
	///@{
	bool	getDisplayRessyabangou()const ;
	CDcdDiagram& setDisplayRessyabangou( bool value ) ;
	bool	getDisplayRessyamei()const ;
	CDcdDiagram& setDisplayRessyamei( bool value ) ;
	/**
	@return
		ダイヤグラムエンティティ座標をDcDraw座標に変換する
		オブジェクトを返します。
	@note
		以下のメソッドは、m_CconvContentPosToDcdTarget に対する
		ラッパー関数です。@n
		getPosDgr(),setPosDgr(),getDcdPerDgrX(),setDcdPerDgrX(),
		getDcdPerDgrY(),setDcdPerDgrY(),getZone_Dgr(),setZone_Dgr(),
		getKeepZoneDgrOnSize(),setKeepZoneDgrOnSize(),
		XDgrToDcd(),YDgrToDcd(),XDgrFromDcd(),YDgrFromDcd(),
		DgrToDcd(),DgrFromDcd()
	*/
	CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()
	{
		return &m_CconvContentPosToDcdTarget ;
	};

	/**
	@return
		ダイヤグラムエンティティ座標をDcDraw座標に変換する
		オブジェクトを返します。
	*/
	const CconvContentPosToDcdTarget* getCconvContentPosToDcdTarget()const
	{
		return &m_CconvContentPosToDcdTarget ;
	};

	/**
	@return
		TargetPosの左上に描画される『ダイヤグラム座標』。 
	*/
	CdDcdPosXy	getPosDgr()const ;

	/**
	TargetPosの左上に描画される『ダイヤグラム座標』を指定します。
		
	@param posPosDgr [in]
		TargetPosの左上に描画される『ダイヤグラム座標』。
	*/
	void setPosDgr( CdDcdPosXy posPosDgr );

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
	CDcdDiagram& setVlineMode( int value ) ;

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
	CDcdDiagram& setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) ;

	EStopMarkDraw	getStopMarkDraw()const{	return m_eStopMarkDraw ;};
	void setStopMarkDraw( EStopMarkDraw	value )
	{	m_eStopMarkDraw = value ;};


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
		\n不要であれば NULL でもかまいません。
	 @return
		選択肢の数を返します。	
	 */
	int getVlineChoices( Mui<VLINE>* pContVLINE )const ;

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
		- CdFontProp	m_fontpropDiaRessyaFont ;
		- COLORREF	m_colorDiaHaikeiColor ;
		- COLORREF	m_colorDiaRessyaColor ;
		- COLORREF	m_colorDiaJikuColor ;
		
	 @param value [in]
		CdDedDispProp オブジェクトを指定して下さい。
	*/	
	CDcdDiagram& readCdDedDispProp( const CdDedDispProp& value ) ;
	
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
	CdDcdZoneXy	getZone_Dgr( IfDcdTarget* pIfDcdTarger ) ;

	/**
		このクラスが描画を行う領域の座標を、
	 	『ダイヤグラムエンティティ座標系』で設定します。
		この値は、m_posDgr・m_dwDcdPerDgrX・m_dwDcdPerDgrY に
		換算のうえで設定されます。
	@param pIfDcdTarger [in]
		描画対象を指定してください。
	@param
		このクラスが描画を行う領域の座標を
		『ダイヤグラムエンティティ座標系』で指定してください。
	*/
	void setZone_Dgr( IfDcdTarget* pIfDcdTarger , const CdDcdZoneXy& value ) ;
	
	/**
		ウインドウサイズ変更時の動作を取得します。
	@return 
		- false:表示範囲を変更(OuDia Ver.1.00.04 より後)
		- true: 表示範囲を変更しない(OuDia Ver.1.00.04 互換)
	*/
	bool getKeepZoneDgrOnSize()const;

	/**
		ウインドウサイズ変更時の動作を設定します。
	@return 
		- false:表示範囲を変更(OuDia Ver.1.00.04 より後)
		- true: 表示範囲を変更しない(OuDia Ver.1.00.04 互換)
	*/
	void setKeepZoneDgrOnSize( bool bRv );
	
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
	
};
} //namespace ViewDiagram

#endif /*CDcdDiagram_h*/



