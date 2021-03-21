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
//	CWjkStateMachine.h
// ****************************************************************
*/
/** @file */
#ifndef  ViewJikokuhyou_CWjkStateMachine_h
#define  ViewJikokuhyou_CWjkStateMachine_h

#include "NsOu\Ou.h"
#include "NsMu\CMup_vector.h"
#include "NsMu\CaMuCast.h"

#include "ViewJikokuhyou\WndJikokuhyou\CWjkState.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{

// ****************************************************************
//	CWjkStateMachine
// ****************************************************************
/**
@brief
  CWndJikokuhyou の状態機械を表すクラスです。

　このクラスは、状態を表す CWjkState オブジェクトの
 コンテナとして働きます。

  また、このクラスはカレント状態を保持します。状態遷移時の
入場・退場動作の呼び出しも行います。

  
【使い方】

(1)  add() で、CWndJikokuhyou オブジェクトを追加してください。

(2)  setCurrentStateIdx() で、初期のカレント状態を指定してください。

(3)  getCurrentState() で、カレント状態の CWjkState オブジェクトへのポインタを取得することができます。
  このポインタに対してメソッドを呼び出すことにより、状態遷移に応じた処理を行わせることができます。

(4)  setCurrentStateIdx() で、状態遷移先を指定することにより、カレント状態を遷移させることができます。

*/
class CWjkStateMachine 
{
private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	/**
		『カレント状態』を表します。
	
		『カレント状態』は、 m_CStateCont コンテナのインデクスで示します。
		-1 は、どの状態にも属していない状態です。
	 */
	int m_iCurrentStateIdx ;
	///@}
	// ********************************
	///@name	集約
	// ********************************
	///@{
	/**
		『状態』オブジェクトへのポインタを保持するコンテナです。
	
		add() でオブジェクトを追加することができます。
	 */
	CMup_vector< Ou< CWjkState > >	m_CStateCont ;

	/**
		m_CStateCont のアダプタです。
	
		Mu インターフェースを提供します。
	 */
	CaMuCast< CWjkState* , Ou< CWjkState > >
		m_CStateContGet ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWjkStateMachine() ;

	// ********************************
	///@name	CWjkStateMachine-属性
	// ********************************
	///@{
	int getCurrentStateIdx() ;

	/**
		『カレント状態』を変更します。
	
		この関数は、以下の順で処理を行います。
	
		-# 新しい『カレント状態』の CWjkState オブジェ
		クトに対して、 CWjkState::canEnter() を
		呼び出して、入場可能か否かを調べる。
			入場不可能なら、後続の処理は行わない。
		-# それまでの『カレント状態』の CWjkState 
		オブジェクトに対して、 CWjkState::onExit() を
		呼び出して、退場動作を行わせる。
		-# カレント状態を示す m_iCurrentStateIdx を更新。
		-# 新しい『カレント状態』の CWjkState 
		オブジェクトに対して、CWjkState::onEnter() を
		呼び出して、入場動作を行わせる。
	
		引数 value と m_iCurrentStateIdx が等しい場合でも、
		CWjkState::onExit() , 
		CWjkState::onEnter() の呼び出しは行います。
		
	@param value [in]
		次の『カレント状態』を指定してください。
		『カレント状態』は、 m_CStateCont コンテナのインデクスで示します。
	@return
		状態遷移が成功したら 0 以上、遷移できなければ負の数です。
		遷移先の状態の canEnter() が負の数を返した場合は、
		その数を返して、状態遷移は失敗します。
	*/
	int setCurrentStateIdx( int value ) ;
	///@}

	// ********************************
	///@name	CWjkStateMachine-集約 
	// ********************************
	///@{
	Mu< CWjkState* >*	getCStateContGet()
	{	return &m_CStateContGet ;};
	///@}

	// ********************************
	///@name	CWjkStateMachine-操作 
	// ********************************
	///@{
	/**
		状態を追加します。
	*/
	void add( Ou< CWjkState > pState ) ;
	
	/**
	@return 
		カレント状態のオブジェクトを返します。
		 m_iCurrentStateIdx == -1 の場合は NULL を返します。

		この関数の戻り値は、 getCStateContGet( getCurrentStateIdx() ) 
		と等価です。
	*/
	CWjkState* getCurrentState() ;


	///@}
};

} } // namespace WndJikokuhyou namespace ViewJikokuhyou

#endif //ViewJikokuhyou_CWjkStateMachine_h
