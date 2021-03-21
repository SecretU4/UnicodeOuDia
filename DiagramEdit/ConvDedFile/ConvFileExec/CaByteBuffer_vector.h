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
//	CaByteBuffer_vector.h
// ****************************************************************
/** @file */
#ifndef  CaByteBuffer_vector_h
#define  CaByteBuffer_vector_h

#include "IfByteBuffer.h"

// ****************************************************************
//	CaByteBuffer_vector
// ****************************************************************
/**
@brief
  std::vector<char> または std::vector<unsigned char> を
   IfByteBuffer インターフェースで操作するためのアダプタクラスです。

@param vectorT 
  std::vector<char> または std::vector<unsigned char> を
  指定してください。
	
*/
template< class vectorT > class CaByteBuffer_vector : public IfByteBuffer 
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	vectorT*	m_pVector ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CaByteBuffer_vector( vectorT* pVector )
		: m_pVector( pVector )
	{
	};


public:
	// ********************************
	///@name IfByteBuffer	
	// ********************************
	///@{
	/**
		バッファのサイズを変更します。
		この関数を呼び出すと、バッファ内にそれまで保持していた
		データは破棄されます。
	@param iBytes [in] 
		バッファのバイト数を指定してください。
	@return 
		成功したら 0 以上、エラーなら負の数です。
		-	-1;	//	メモリが確保できません。
	*/
	virtual int size_reset( int iBytes ) 
	{
		m_pVector->resize( iBytes ) ;
		return 0 ;
	};

	/**
	@return 
		バッファのバイト数を返します。
	*/
	virtual int size()const 
	{
		return m_pVector->size() ;
	};

	/**
		バッファの指定の位置にデータを書き込みます。
	@param pData [in]
		データの先頭アドレスを指定してください。
	@param iPos [in]
		バッファ上の、データを書き込む位置を、バイトインデクスで指定してください。
	@param iBytes [in]
		書き込むバイト数を指定してください。
	@return 
		書き込んだバイト数を返します。
		負の数はエラーです。
	*/
	virtual int write( const char* pData , int iPos , int iBytes ) 
	{
		if ( iBytes > (int)m_pVector->size() - iPos ) 
		{
			iBytes = (int)m_pVector->size() - iPos ; 
		}
		if ( iBytes < 0 )
		{
			iBytes = 0 ;
		}
		if ( iBytes > 0 )
		{
			memcpy( &(*m_pVector)[iPos] , pData , iBytes ) ;
		}
		return iBytes ;
	};


	/**
		バッファの指定の位置からデータを読み込みます。
	@param pData [out]
		この関数はこのアドレスに、読み込んだデータを書き込みます。
	@param iPos [in]
		バッファ上の、データを読み出す位置を、
		バイトインデクスで指定してください。
	@param iBytes [in]
		読み込むバイト数を指定してください。
	@return 
		読み込むんだバイト数を返します。
		負の数はエラーです。
	*/
	virtual int read( char* pData , int iPos , int iBytes )const
	{
		if ( iBytes > (int)m_pVector->size() - iPos ) 
		{
			iBytes = (int)m_pVector->size() - iPos ; 
		}
		if ( iBytes < 0 )
		{
			iBytes = 0 ;
		}
		if ( iBytes > 0 )
		{
			memcpy( pData , &(*m_pVector)[iPos] , iBytes ) ;
		}
		return iBytes ;
	};

	///@}
};


#endif //CaByteBuffer_vector_h
