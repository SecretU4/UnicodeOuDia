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
//	CentDedRessya_EkijikokuModifyOperation2.h
// ****************************************************************
#ifndef  CentDedRessya_EkijikokuModifyOperation2_h
#define  CentDedRessya_EkijikokuModifyOperation2_h
/** @file */

#include "CentDedRessya.h"

namespace entDed{

// ****************************************************************
//	CentDedRessya_EkijikokuModifyOperation2
// ****************************************************************
/**
 * @brief
 *	列車に対する『駅時刻の変更』操作の内容です。
 *
 *	このクラスのオブジェクトに『駅時刻の変更』の内容を設定して
 *	CentDedRessya_EkijikokuModifyOperation2::execute() を実行することにより、
 *	駅時刻の変更を実行することができます。
 */
class CentDedRessya_EkijikokuModifyOperation2
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**
	 	駅時刻に対する操作の内容を表す列挙です。
	 */
	enum EOperation 
	{
		/**
			駅時刻を変更しません。
		*/
		OperationNop ,
		
		/**
			駅時刻の繰上げ・繰下げ。
		
			変更対象の駅時刻を、
			 m_iSeconds 秒繰下げます（負の数なら
			繰上げとなります）

			このとき、変更対象の駅時刻以降の時刻は繰上げ・繰下げと
			なります。
		*/
		OperationModify ,
		/**
			駅時刻のコピー。
		
			変更対象の駅時刻を、
			『時刻Order』がm_iJikokuOrderCopySrc の時刻 + m_iSeconds 
			とします。
		*/
		OperationCopy ,
		/**
		
			変更対象の駅時刻を、
			指定なしに変更します。
		*/
		OperationToNull ,
	};
// ********************************
///@name	属性
// ********************************
///@{
 private:
	/**
	 	駅扱を変更します。
	 	この変数が true の場合、駅扱の値は、 m_eEkiatsukai で指定します。
	 */
	bool m_bSetEkiatsukai ;
	/**
		駅扱
	  @see m_bSetEkiatsukai を参照してください。
	 
	 	m_bSetEkiatsukai が偽の場合は、この変数は意味を持ちません。
	 */
	CentDedEkiJikoku::EEkiatsukai m_eEkiatsukai ;


	/**
		時刻変更の方法。
	*/
	EOperation m_eOperation ;

	/**
		駅時刻の繰下げ・もしくは駅時刻のコピー時の秒数。
	 @see m_eOperation
	*/
	int	m_iSeconds ;

	/**
		駅時刻のコピーの場合は、コピー元の駅時刻Order。
	 @see m_eOperation
	*/
	CdDedJikokuOrder m_iJikokuOrderCopySrc ;

///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	CentDedRessya_EkijikokuModifyOperation2() : 
		m_bSetEkiatsukai( false ) ,
		m_eEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ,
		m_eOperation( OperationNop ) , 
		m_iSeconds( 0 ) ,
		m_iJikokuOrderCopySrc( 0 , CdDedJikokuOrder::EkiJikokuItem_Chaku ){} ;
		
// ********************************
//	CentDedRessya_EkijikokuModifyOperation2
// ********************************
 public:
	// ********************************
	///@name CentDedRessya_EkijikokuModifyOperation2-属性
	// ********************************
	///@{
	bool getSetEkiatsukai()const{ return m_bSetEkiatsukai ;};
	CentDedRessya_EkijikokuModifyOperation2& setSetEkiatsukai( bool value )
	{	m_bSetEkiatsukai = value ; return *this ; } ;
	CentDedEkiJikoku::EEkiatsukai getEkiatsukai()const
	{	return m_eEkiatsukai ; } ;
	CentDedRessya_EkijikokuModifyOperation2& setEkiatsukai( 
			CentDedEkiJikoku::EEkiatsukai value )
	{	m_eEkiatsukai = value ; return *this ; } ;

	EOperation getOperation()const{ return m_eOperation ;};
	CentDedRessya_EkijikokuModifyOperation2& setOperation( 
			EOperation value ){
		m_eOperation = value ; return *this ; } ;
	int getSeconds()const{ return m_iSeconds ;};
	CentDedRessya_EkijikokuModifyOperation2& setSeconds( int value )
	{	m_iSeconds = value ; return *this ; } ;
	CdDedJikokuOrder getJikokuOrderCopySrc()const{ return m_iJikokuOrderCopySrc ;};
	CentDedRessya_EkijikokuModifyOperation2& setJikokuOrderCopySrc( 
		const CdDedJikokuOrder& value )
	{	m_iJikokuOrderCopySrc = value ; return *this ; 	} ;

	/**
	@return
		- true:	this がNULL状態です。
		
		NULL状態は、 m_bSetEkiatsukai == false & m_eOperation == OperationNop
		であることを示します。
	*/
	bool isNull()const{	return !m_bSetEkiatsukai && m_eOperation == OperationNop ;};

	/**
		this を NULL 状態にします。
	*/
	void setNull(){	m_bSetEkiatsukai = false ;	m_eOperation = OperationNop ;};

	///@}
	// ********************************
	///@name CentDedRessya_EkijikokuModifyOperation2-操作
	// ********************************
	///@{
	/**
		指定の『列車』に対して、この属性が保持している『駅時刻の変更』
		を行います。
	
		このとき、『着時刻』・『発時刻』が変更されたら、
		以後の駅時刻をすべて繰り下げます。
	
	
	 @param pCentDedRessya [in,out]
		この『列車』に対して、この属性が保持している『駅時刻の変更』
		を行います。
	 @param aJikokuOrder [in]
		『時刻Order』を指定してください。
		範囲は 0 以上 getCentEkiJikokuCount() * 2 未満です。
	 @return 
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	aJikokuOrder が範囲外です。
	*/
	virtual int execute( CentDedRessya* pCentDedRessya , CdDedJikokuOrder aJikokuOrder ) ;
	///@}
};

} //namespace entDed

#endif /*CentDedRessya_EkijikokuModifyOperation2_h*/
