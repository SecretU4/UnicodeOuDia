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
//	CentDedEkiJikoku.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEkiJikoku_h
#define  CentDedEkiJikoku_h

#include "CdDedJikoku.h"


// ****************************************************************
//	CentDedEkiJikoku
// ****************************************************************
/**
 * @brief
 *	【概要】  DiagramEdit の、１列車の１駅における時刻を表します。
 *	属性として、『着時刻』『発時刻』と
 *	『駅扱』｛運行なし,経由なし,通過,停車｝
 *	を保持します。
 */
class CentDedEkiJikoku
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**
	 *	『駅扱』を表す列挙です。
	 */
	enum EEkiatsukai{
		/**
		 *	運行なし(規定値) 。
		 *
		 *	この場合、
		 *	着時刻 ( m_jikokuChakujikoku )・
		 *	発時刻 ( m_jikokuHatsujikoku )
		 *	は、『Null状態』となります。
		 */
		Ekiatsukai_None ,
		/**
		 *	 停車
		 *
		 *	この場合、
		 *	着時刻 ( m_jikokuChakujikoku )・
		 *	発時刻 ( m_jikokuHatsujikoku )
		 *	の少なくとも１つは、非『Null状態』でなくてはなりません。
		 */
		Ekiatsukai_Teisya ,
		/**
		 *	 通過
		 */
		Ekiatsukai_Tsuuka ,
		/** 
		 *	経由なし
		 *
		 *	この場合、
		 *	着時刻 ( m_jikokuChakujikoku )・
		 *	発時刻 ( m_jikokuHatsujikoku )
		 *	は、『Null状態』となります。
		 */
		Ekiatsukai_Keiyunasi ,
	};


// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	駅扱。
	 */
	EEkiatsukai	m_eEkiatsukai ;
	
	/**
	 *	着時刻。
	 *
	 *	m_eEkiatsukai が
	 *	運行なし ( Ekiatsukai_None ),
	 *	経由なし ( Ekiatsukai_Keiyunasi ) の場合は、
	 *	この値は意味を持ちません。
	 */
	CdDedJikoku	m_jikokuChakujikoku ;
	
	/**
	 *	発時刻。
	 *
	 *	m_eEkiatsukai が
	 *	運行なし ( Ekiatsukai_None ),
	 *	経由なし ( Ekiatsukai_Keiyunasi ) の場合は、
	 *	この値は意味を持ちません。
	 */
	CdDedJikoku	m_jikokuHatsujikoku ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param eEkiatsukai [in]
	 *	駅扱。
	 * @param jikokuChakujikoku [in]
	 *	着時刻。	\n
	 *	m_eEkiatsukai が
	 *	運行なし ( Ekiatsukai_None ),
	 *	経由なし ( Ekiatsukai_Keiyunasi ) の場合は、
	 *	この値は意味を持ちません。
	 * @param jikokuHatsujikoku [in]
	 *	発時刻。	\n
	 *	m_eEkiatsukai が
	 *	運行なし ( Ekiatsukai_None ),
	 *	経由なし ( Ekiatsukai_Keiyunasi ) の場合は、
	 *	この値は意味を持ちません。
	 */
	CentDedEkiJikoku( 
		EEkiatsukai	eEkiatsukai , 
		CdDedJikoku	jikokuChakujikoku , 
		CdDedJikoku	jikokuHatsujikoku ) 
	{
		set( eEkiatsukai , jikokuChakujikoku , jikokuHatsujikoku ) ;			
	};
	
	/** デフォルトコンストラクタ */
	CentDedEkiJikoku() :
		m_eEkiatsukai( Ekiatsukai_None ) {};
	

// ********************************
//	CentDedEkiJikoku
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	EEkiatsukai	getEkiatsukai()const{	return m_eEkiatsukai ;};

	/**
	 *	駅扱を設定します。
	 *	- 	Ekiatsukai_None ・または Ekiatsukai_Keiyunasi を設定すると、
	 *		着・発時刻はどちらも Null 時刻となります。
	 */
	CentDedEkiJikoku& setEkiatsukai( EEkiatsukai value ){
		m_eEkiatsukai = value ;
		if ( m_eEkiatsukai == Ekiatsukai_None ||
			m_eEkiatsukai == Ekiatsukai_Keiyunasi  ){
			m_jikokuChakujikoku.setNull() ;
			m_jikokuHatsujikoku.setNull() ;
		}
		return *this ; 
	} ;
	
	/**
	 *	着時刻を参照することができます。
	 * @param bHatsuIfNull [in]
	 *	- true ; 着時刻が Null 時刻で、発時刻が Null 時刻でない場合は、
	 *		発時刻を返します。
	 *	- false ; 着時刻が Null 時刻なら、発時刻に関わらず
	 *		 Null 時刻を返します。
	 * @return
	 *		着時刻を返します。
	 */
	CdDedJikoku	getChakujikoku( bool bHatsuIfNull = false )const{
		if ( bHatsuIfNull && m_jikokuChakujikoku.isNull() ){
			return m_jikokuHatsujikoku ;
		}
		return m_jikokuChakujikoku ;
	};

	/**
	 *	着時刻を設定します。
	 *	- 	m_eEkiatsukai == Ekiatsukai_Teisya の駅に対して
	 *		着・発両方に Null 時刻を設定すると、this の
	 *		m_eEkiatsukai = Ekiatsukai_None となります。
	 *	- 	m_eEkiatsukai == Ekiatsukai_None ・
	 *		または Ekiatsukai_Keiyunasi の駅に対して
	 *		着・発のいずれかに 非Null 時刻を設定すると、this の
	 *		m_eEkiatsukai = Ekiatsukai_Teisya となります。
	 */
	CentDedEkiJikoku& setChakujikoku( const CdDedJikoku& value ){
		m_jikokuChakujikoku = value ; 
		if ( m_eEkiatsukai == Ekiatsukai_Teisya && 
				m_jikokuChakujikoku.isNull() && 
			 	m_jikokuHatsujikoku.isNull() ){
			m_eEkiatsukai = Ekiatsukai_None ;
		}	else if ( 
			( m_eEkiatsukai == Ekiatsukai_None ||  
			  m_eEkiatsukai == Ekiatsukai_Keiyunasi ) && 
			( !m_jikokuChakujikoku.isNull() ||
			  ! m_jikokuHatsujikoku.isNull() )   ){
			m_eEkiatsukai = Ekiatsukai_Teisya ;
		}
			
		return *this ;
	};

	/**
	 *	発時刻を参照することができます。
	 * @param bChakuIfNull [in]
	 *	- true ; 発時刻が Null 時刻で、着時刻が Null 時刻でない場合は、
	 *		着時刻を返します。
	 *	- false ; 発時刻が Null 時刻なら、着時刻に関わらず
	 *		 Null 時刻を返します。
	 * @return
	 *		発時刻を返します。
	 */
	CdDedJikoku	getHatsujikoku( bool bChakuIfNull = false )const{
		if ( bChakuIfNull && m_jikokuHatsujikoku.isNull() ){
			return m_jikokuChakujikoku ;
		}
		return m_jikokuHatsujikoku ;
	};

	/**
	 *	発時刻を設定します。
	 *	- 	m_eEkiatsukai == Ekiatsukai_Teisya の駅に対して
	 *		着・発両方に Null 時刻を設定すると、this の
	 *		m_eEkiatsukai = Ekiatsukai_None となります。
	 *	- 	m_eEkiatsukai == Ekiatsukai_None ・
	 *		または Ekiatsukai_Keiyunasi の駅に対して
	 *		着・発のいずれかに 非Null 時刻を設定すると、this の
	 *		m_eEkiatsukai = Ekiatsukai_Teisya となります。
	 */
	CentDedEkiJikoku& setHatsujikoku( const CdDedJikoku& value )
	{
		m_jikokuHatsujikoku = value ; 
		if ( m_eEkiatsukai == Ekiatsukai_Teisya && 
				m_jikokuChakujikoku.isNull() && 
			 	m_jikokuHatsujikoku.isNull() ){
			m_eEkiatsukai = Ekiatsukai_None ;
		}	else if ( 
			( m_eEkiatsukai == Ekiatsukai_None ||  
			  m_eEkiatsukai == Ekiatsukai_Keiyunasi ) && 
			( !m_jikokuChakujikoku.isNull() ||
			  ! m_jikokuHatsujikoku.isNull() )   ){
			m_eEkiatsukai = Ekiatsukai_Teisya ;
		}
		return *this ;
	};

	/**
	 * @param eEkiatsukai [in]
	 *	駅扱。
	 * @param jikokuChakujikoku [in]
	 *	着時刻。	\n
	 *	m_eEkiatsukai が
	 *	着時刻 ( Ekiatsukai_None ),
	 *	発時刻 ( Ekiatsukai_Keiyunasi ) の場合は、
	 *	この値は意味を持ちません。
	 * @param jikokuHatsujikoku [in]
	 *	発時刻。	\n
	 *	m_eEkiatsukai が
	 *	着時刻 ( Ekiatsukai_None ),
	 *	発時刻 ( Ekiatsukai_Keiyunasi ) の場合は、
	 *	この値は意味を持ちません。
	 *
	 *	- 	Ekiatsukai_None ・または Ekiatsukai_Keiyunasi を設定すると、
	 *		着・発時刻はどちらも Null 時刻となります。
	 *	- 	Ekiatsukai_Teisya ・着・発時刻がどちらも Null 時刻の場合、
	 *		m_eEkiatsukai = Ekiatsukai_None となります。
	 */
	CentDedEkiJikoku& set( 
		EEkiatsukai	eEkiatsukai , 
		CdDedJikoku	jikokuChakujikoku , 
		CdDedJikoku	jikokuHatsujikoku )
	{
		m_eEkiatsukai = eEkiatsukai ; 
		m_jikokuChakujikoku =  jikokuChakujikoku ;
		m_jikokuHatsujikoku =  jikokuHatsujikoku ;


		if ( m_eEkiatsukai == Ekiatsukai_None ||
			m_eEkiatsukai == Ekiatsukai_Keiyunasi  ){
			m_jikokuChakujikoku.setNull() ;
			m_jikokuHatsujikoku.setNull() ;
		}	else if ( m_eEkiatsukai == Ekiatsukai_Teisya && 
				m_jikokuChakujikoku.isNull() && 
			 	m_jikokuHatsujikoku.isNull() ){
			m_eEkiatsukai = Ekiatsukai_None ;
		}
		return ( *this ) ;
	};

	///@}
};




#endif /*CentDedEkiJikoku_h*/
