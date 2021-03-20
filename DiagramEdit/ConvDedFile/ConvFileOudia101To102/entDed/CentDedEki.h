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
//	CentDedEki.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEki_h
#define  CentDedEki_h

#include <string>

// ****************************************************************
//	CentDedEki
// ****************************************************************
/**
 * @brief
 *	【概要】  DiagramEdit の、路線にある駅ひとつを表します。
 *	属性として、『駅名』・『駅時刻形式』・『駅規模』を保持します。
 *
 */
class CentDedEki
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/**
	 *	『駅時刻形式』を表す列挙です。
	 */
	enum EEkijikokukeisiki
	{
		/**
		 *	発時刻のみの表示。(規定値)
		 *
		 *	(ただし、終着駅では着時刻のみを表示します)
		 */
		Jikokukeisiki_Hatsu = 0 ,
		
		/**
		 *	発着表示。
		 *
		 *	下り・上りとも、発着両方の時刻を表示。
		 *	(始発駅・終着駅でも発着両方を表示)
		 */
		Jikokukeisiki_Hatsuchaku ,

		/**
		 *	下り着表示。
		 *
		 *	-	下り列車では、着時刻のみの表示。
		 *	-	上り列車では、発時刻のみの表示。
		 *	(ただし、終着駅では着時刻のみを表示します)
		 */
		Jikokukeisiki_KudariChaku ,
		
		/**
		 *	上り着表示。
		 *
		 *	-	下り列車では、発時刻のみの表示。
		 *	(ただし、終着駅では着時刻のみを表示します)
		 *	-	上り列車では、着時刻のみの表示。
		 */
		Jikokukeisiki_NoboriChaku ,
		
	};
	
	/**
	 *	『駅規模』を表す列挙です。
	 */
	enum EEkikibo
	{
		/**
		 *	一般駅。(規定値)
		 */
		Ekikibo_Ippan = 0 ,
		/**
		 *	主要駅。
		 *
		 *	主要駅では、ダイヤグラムの罫線が太線になります。
		 */
		Ekikibo_Syuyou ,
	};
	
	/**
		ダイヤグラム列車情報表示
	*/
	enum EDiagramRessyajouhouHyouji
	{
		/**
			始発駅の場合には表示(既定値)
		*/
		DiagramRessyajouhouHyouji_Origin ,
		/**
			常に表示する。
		*/
		DiagramRessyajouhouHyouji_Anytime ,
		/**
			表示しない。
		*/
		DiagramRessyajouhouHyouji_Not ,
	};

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	 *	駅名
	 *
	 *	規定値は、空文字列。
	 */
	std::string	m_strEkimei ;
	
	/**
	 *	駅時刻形式。
	 *
	 *	規定値は、 Jikokukeisiki_Hatsuhyouji 
	 */
	EEkijikokukeisiki	m_eEkijikokukeisiki ;
	
	/**
	 *	『駅規模』を表す列挙です。
	 *
	 *	規定値は、 Ekikibo_Ippan 
	 */
	EEkikibo	m_eEkikibo ;
	
	/**
	 *	境界線あり。
	 *
	 *  この属性が true の駅では、時刻表画面の
	 *	下り方向の下に、太い境界線を描画します。
	 *  この属性は、駅ビューと時刻表ビューに適用されます。
	 */
	bool m_bKyoukaisen ;

	/**
		ダイヤグラム列車情報表示（下り）
	
		既定値は DiagramRessyajouhouHyouji_Origin です。
	*/	
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiKudari ;
	
	/**
		ダイヤグラム列車情報表示（上り）
	
		この属性が true の駅では、ダイヤグラムビューにおいて、
		下り列車の列車情報を描画します。

		既定値は DiagramRessyajouhouHyouji_Origin です。
	*/
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiNobori ;

	
	
	///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	CentDedEki() :
		m_eEkijikokukeisiki( Jikokukeisiki_Hatsu ) ,
		m_eEkikibo( Ekikibo_Ippan ) ,
		m_bKyoukaisen( false ) ,
		m_eDiagramRessyajouhouHyoujiKudari( DiagramRessyajouhouHyouji_Origin ) ,
		m_eDiagramRessyajouhouHyoujiNobori( DiagramRessyajouhouHyouji_Origin ) 
		{};
	
	/**
	 * @param strEkimei [in]
	 *	駅名
	 * @param eEkijikokukeisiki [in]
	 *	駅時刻形式。
	 * @param eEkikibo [in]
	 *	『駅規模』を表す列挙です。
	 * @param bKyoukaisen [in]
	 *	境界線あり。
	 *  この属性が true の駅では、時刻表画面の
	 *	下り方向の下に、太い境界線を描画します。
	 *  この属性は、駅ビューと時刻表ビューに適用されます。
	 */
	CentDedEki( const std::string& strEkimei , 
			EEkijikokukeisiki	eEkijikokukeisiki ,
			EEkikibo	eEkikibo , 
			bool bKyoukaisen , 
			EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiKudari 
				= DiagramRessyajouhouHyouji_Origin ,
			EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiNobori 
				= DiagramRessyajouhouHyouji_Origin ) :
		m_strEkimei( strEkimei ) ,
		m_eEkijikokukeisiki( eEkijikokukeisiki ) ,
		m_eEkikibo( eEkikibo ) ,
		m_bKyoukaisen( bKyoukaisen ) ,
		m_eDiagramRessyajouhouHyoujiKudari( eDiagramRessyajouhouHyoujiKudari ) ,
		m_eDiagramRessyajouhouHyoujiNobori( eDiagramRessyajouhouHyoujiNobori ) 
		{};
		
	
	virtual ~CentDedEki(){} ;

// ********************************
//	CentDedEki
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	std::string	getEkimei()const{	return m_strEkimei ;};
	void setEkimei( const std::string& value ){
		m_strEkimei = value ; } ;
	EEkijikokukeisiki	getEkijikokukeisiki()const{
		return 	m_eEkijikokukeisiki ;};
	void setEkijikokukeisiki( EEkijikokukeisiki	value ){
		m_eEkijikokukeisiki = value ; } ;
	EEkikibo	getEkikibo()const{	return 	m_eEkikibo ;};
	void setEkikibo( EEkikibo value ){
		m_eEkikibo = value ; } ;
	bool getKyoukaisen()const{	return m_bKyoukaisen ; };
	void setKyoukaisen( bool value ){	m_bKyoukaisen = value ; } ;

	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiKudari()const
	{	return m_eDiagramRessyajouhouHyoujiKudari ;};
	void setDiagramRessyajouhouHyoujiKudari( EDiagramRessyajouhouHyouji value )
	{	m_eDiagramRessyajouhouHyoujiKudari = value ;};
	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiNobori()const
	{	return m_eDiagramRessyajouhouHyoujiNobori ;};
	void setDiagramRessyajouhouHyoujiNobori( EDiagramRessyajouhouHyouji value )
	{	m_eDiagramRessyajouhouHyoujiNobori = value ;};

	///@}
	
	// ********************************
	///@name 操作
	// ********************************
	///@{
	///@}
};
#endif /*CentDedEki_h*/
