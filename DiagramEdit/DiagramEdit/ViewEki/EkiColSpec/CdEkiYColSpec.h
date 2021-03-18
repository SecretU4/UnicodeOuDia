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
// $Id: CdEkiYColSpec.h 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
/** @file */
#pragma once
#ifndef ViewEki_CdEkiYColSpec_h
#define ViewEki_CdEkiYColSpec_h

namespace ViewEki{ namespace EkiColSpec{
/**
@brief
  駅ビューの CWndDcdGridEki において、グリッドのY列に表示
  すべき内容を記述した、単純データクラスです。

  この値は NULL 状態を持ちます。
*/
class CdEkiYColSpec
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/** 列の種類 */
	enum EColumnType
	{
		/**	ヘッダ列 */
		ColumnType_Head = 0 ,
		/**	駅列 */
		ColumnType_Eki ,
		/**	新規追加位置 */
		ColumnType_NewEki ,

		/**	NULL状態を示します */
		ColumnType_NULL = -1 
	};
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/** 列の種類 */
	EColumnType	m_eColumnType ;
	
	/** 
		駅Index 。
		m_eColumnType が ColumnType_Eki の場合は、
		0 以上駅数未満の駅 Index を表します。
		
		その他の場合は意味を持ちません。
		既定値は -1 です。
	*/
	int m_iEkiIndex ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	@param eColumnType 
		列の種類 
	@param iEkiIndex 
		駅Index 
	*/
	CdEkiYColSpec( 
		EColumnType eColumnType , 
		int iEkiIndex ) 
		: m_eColumnType( eColumnType )
		, m_iEkiIndex( iEkiIndex ){}
	CdEkiYColSpec( 
		EColumnType eColumnType ) 
		: m_eColumnType( eColumnType )
		, m_iEkiIndex( -1 ){}

	CdEkiYColSpec()
		: m_eColumnType( ColumnType_NULL ) 
		, m_iEkiIndex( -1 ){}
	
public:
	// ********************************
	///@name CdEkiYColSpec-属性
	// ********************************
	EColumnType	getColumnType()const{	return m_eColumnType ;};
	int getEkiIndex()const{	return m_iEkiIndex ;};

	/**
		値を設定します。
	@param eColumnType 
		列の種類 
	@param iEkiIndex 
		駅Index 
	*/
	void set( EColumnType eColumnType , 
		int iEkiIndex ) 
	{
		m_eColumnType = eColumnType ;
		m_iEkiIndex = iEkiIndex ;
	}

	bool isNull()const{	return m_eColumnType == ColumnType_NULL ;};
	/* 
		this をNULL状態にします。
	*/
	void setNull(){	*this = CdEkiYColSpec() ;};	

	/**
		他のオブジェクトとの間で、属性が同一か否かを判定します。
	@param value
		比較対象を指定してください。
	@return
		属性が同一であれば true 
	*/
	bool isEqualTo( const CdEkiYColSpec& value )const
	{
		bool bRv = false ;
		if ( m_eColumnType == value.m_eColumnType )
		{
			//	ColumnType_Eki 列の場合は、
			//	m_iEkiIndex の一致を必要とします。
			if ( m_eColumnType == ColumnType_Eki )
			{
				bRv = ( m_iEkiIndex == value.m_iEkiIndex ) ;
			}
			else
			{
				bRv = true ;
			}
		}
		return bRv ;
	}
	bool operator==(const CdEkiYColSpec& value )const
	{	return isEqualTo( value ) ;}
	bool operator!=(const CdEkiYColSpec& value )const
	{	return !isEqualTo( value ) ;}
};
} } //namespace EkiColSpec namespace ViewEki

#endif/*ViewEki_CdEkiYColSpec_h*/
