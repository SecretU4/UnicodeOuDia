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
//	CSequentialByteBuffer.h
// ****************************************************************
*/
/** @file */
#ifndef  CSequentialByteBuffer_h
#define  CSequentialByteBuffer_h

#include <memory.h>
#include <stdlib.h>
#include "container/IfSequentialByteBuffer.h"

// ****************************************************************
//	CSequentialByteBuffer
// ****************************************************************
/**
 * @brief
 * 【概要】
 * 	  キュー形式でバイトデータを保存する、バッファを実現するクラスです。
 *
 * 【使い方】
 *
 * １．  コンストラクタで、オブジェクトを生成してください。
 * 	  テンプレート引数は、バッファの単位バイト数です。thisは、
 * 	データがこのバイト数溜まるたびに、バッファを拡張します。
 *
 * ２．  これ以後は、全メンバ関数が使用できます。Write()でバッファへの
 * 	データを書き込み、Readではバッファからデータを読み込むことができます。
 * 	Read() は、読込に成功したデータをバッファから取り除きます。
 */
template < int iExpandSize = 8192 >
class CSequentialByteBuffer: public IfSequentialByteBuffer
{
// --------------------------------
//	内部データ
// --------------------------------
 private:
	/**
	 *	バッファの単位バイト数分のデータを
	 *	保持する構造体です。
	 *	この構造体はチェインを形成します。
	 */
	struct NODE
	{
		/**
		 *	バッファ本体です。
		 */
		char		m_abyBuffer[ iExpandSize ] ;
		
		/**
		 * 	m_byBuffer のうち、有効なデータが存在する先頭の添え字。
		 */
		int			m_iPos ;
		/**
		 * 	m_byBuffer のうち、
		 * 	有効なデータのバイト数。
		 */
		int			m_iSize ;
		
		/**
		 * 	次のノードへのポインタです。
		 * 	ない場合はNULLになります。
		 */
		NODE*		m_pNext ;
	};
	/**
	 * 	先頭のノードへのポインタです
	 * 	ノードが１つもない場合はNULLです
	 */
	NODE*			m_pnodeFirst ;
	
	/**
	 *
	 *	末尾のノードへのポインタです
	 *	ノードが１つもない場合はNULLです
	 */
	NODE*			m_pnodeLast ;
	
// ********************************
//	コンストラクタ
// ********************************
 public:
	CSequentialByteBuffer() : m_pnodeFirst( NULL ) , m_pnodeLast( NULL ) 
	{
	};
	~CSequentialByteBuffer() 
	{
		Clear() ;
	};
	CSequentialByteBuffer( const CSequentialByteBuffer<iExpandSize>& src ) 
		: m_pnodeFirst( NULL ) , m_pnodeLast( NULL ) 
	{
		NODE*	pNode = NULL ;
		for ( pNode = src.m_pnodeFirst ; 
				pNode != NULL ; 
				pNode = pNode->m_pNext ){
			Write( &pNode->m_abyBuffer[ pNode->m_iPos ] , 
				pNode->m_iSize ) ;
		}
		
		
	};
	CSequentialByteBuffer& operator=
					( const CSequentialByteBuffer<iExpandSize>& src )
	{
		Clear() ;
		NODE*	pNode = NULL ;
		for ( pNode = src.m_pnodeFirst ; 
				pNode != NULL ; 
				pNode = pNode->m_pNext ){
			Write( &pNode->m_abyBuffer[ pNode->m_iPos ] , 
				pNode->m_iSize ) ;
		}
		

		return ( *this ) ;
	};
// ********************************
//	IfSequentialByteBuffer
// ********************************
 public:
	/**
	 * 	バッファにデータを書き込みます。
	 * @param pData  [in]
	 * 	書き込むデータの先頭アドレスを指定してください
	 * @param sizeData [in]
	 * 	書き込むデータのサイズを指定してください。
	 * @return
	 * 	書き込みに成功したバイト数を返します。
	 * 	-	-1:	メモリが確保できません。
	 */
	int Write( const char* pData , int sizeData ) 
	{
		int	iRv = 0 ;
		while ( iRv >= 0 && sizeData > 0 ){
			if ( iRv >= 0 ){
				if ( m_pnodeLast == NULL ){
					//	現在バッファが空の場合は、バッファのNODEを
					//	新たに作成し、
					//	先頭・末尾として登録します。
					NODE*	pNode = new NODE ;
					if ( pNode == NULL ){
						iRv = -1 ;	//	-1:	メモリが確保できません。
					}	else	{
						pNode->m_iPos = 0 ;
						pNode->m_iSize = 0 ;
						pNode->m_pNext = NULL ;
						m_pnodeFirst = m_pnodeLast = pNode ;
					}
				}
			}
			if ( iRv >= 0 ){
				int	iLastPos = m_pnodeLast->m_iPos + m_pnodeLast->m_iSize ;
				if ( iExpandSize - iLastPos  == 0 ){
					//	末尾のNODEが空の場合は、
					//	新しいNODEを作成し、末尾に追加します。
					NODE*	pNode = new NODE ;
					if ( pNode == NULL ){
						iRv = -1 ;	//	-1:	メモリが確保できません。
					}	else	{
						pNode->m_iPos = 0 ;
						pNode->m_iSize = 0 ;
						pNode->m_pNext = NULL ;
						m_pnodeLast->m_pNext = pNode ;
						m_pnodeLast = pNode ;
					}
				}
				
			}
			if ( iRv >= 0 ){
				//	末尾のNODEにデータを書き込み
				int	iLastPos = m_pnodeLast->m_iPos + m_pnodeLast->m_iSize ;
				int sizeDataWriteNext = sizeData ;
				if ( sizeDataWriteNext > iExpandSize - iLastPos ){
					sizeDataWriteNext = iExpandSize - iLastPos ;
				}
				//sizeDataWriteNext =  末尾のノードに書き込めるバイト数
				
				memcpy( &m_pnodeLast->m_abyBuffer[ iLastPos ]
					, pData , sizeDataWriteNext ) ;
				pData += sizeDataWriteNext ;
				sizeData -= sizeDataWriteNext ;
				iRv += sizeDataWriteNext ;

				m_pnodeLast->m_iSize += sizeDataWriteNext ;
			}
			
		}
		return ( iRv ) ;
	};
	
	/**
	 * 	バッファからデータを読み込みます。
	 * 	読み込んだデータは、バッファから取り除かれます。
	 * @param pData  [out]
	 * 	この関数は、このアドレスに読み込んだデータを書き込みます。
	 * 	不要なら（データの読み捨てを行う場合）NULLを渡してもかまいません。
	 * @param sizeData [in]
	 * 	読み込む最大バイト数（pDataのバッファサイズ）を指定してください
	 * @return
	 * 	読込に成功したバイト数を返します。
	 */
	int Read( char* pData , int sizeData ) 
	{
		int iRv = 0 ;	

		NODE*	pNode = NULL ;
		for ( pNode = m_pnodeFirst ; 
				pNode != NULL && iRv >= 0 && sizeData > 0 ;
				pNode = pNode->m_pNext ){
			if ( iRv >= 0 ){
				//	NODEからデータを読み込み
				int sizeDataReadNext = sizeData ;
				if ( sizeDataReadNext > pNode->m_iSize ){
					sizeDataReadNext = pNode->m_iSize ;
				}
				//sizeDataReadNext =  先頭ののノードから読み込めるバイト数
				
				//	ユーザーバッファにコピー
				if ( pData != NULL ){
					memcpy( pData  , 
						&pNode->m_abyBuffer[ pNode->m_iPos ]
						, sizeDataReadNext ) ;
					pData +=  sizeDataReadNext ;
				}
				sizeData -= sizeDataReadNext ;
				iRv += sizeDataReadNext ;
				
				//	読み込んだデータをノードから削除
				pNode->m_iPos  += sizeDataReadNext ;
				pNode->m_iSize -= sizeDataReadNext ;

			}
		}
		
		//	空のノードは削除
		while ( m_pnodeFirst != NULL && m_pnodeFirst->m_iSize == 0 ){
					NODE*	pNodeToDelete = m_pnodeFirst ;
					m_pnodeFirst = m_pnodeFirst->m_pNext ;
					delete pNodeToDelete ;
		}
		if ( m_pnodeFirst == NULL ){
			m_pnodeLast = NULL ;
		}
		
		return ( iRv ) ;
	}
	
	/**
	 * 	バッファの先頭からデータを読み込みますが、
	 * 	読み込んだデータをバッファから取り除きません
	 * @param pData  [out]
	 * 	この関数は、このアドレスに読み込んだデータを書き込みます。
	 * 	不要ならNULLを渡してもかまいません。
	 * @param sizeData [in]
	 * 	読み込む最大バイト数（pDataのバッファサイズ）を指定してください
	 * @return
	 * 	読込に成功したバイト数を返します。
	 */
	int Peek( char* pData , int sizeData )const 
	{
		int iRv = 0 ;	

		NODE*	pNode = NULL ;
		for ( pNode = m_pnodeFirst ; 
				pNode != NULL && iRv >= 0 && sizeData > 0 ;
				pNode = pNode->m_pNext ){
			if ( iRv >= 0 ){
				//	NODEからデータを読み込み
				int sizeDataReadNext = sizeData ;
				if ( sizeDataReadNext > pNode->m_iSize ){
					sizeDataReadNext = pNode->m_iSize ;
				}
				//sizeDataReadNext =  先頭ののノードから読み込めるバイト数
				
				//	ユーザーバッファにコピー
				if ( pData != NULL ){
					memcpy( pData  , 
						&pNode->m_abyBuffer[ pNode->m_iPos ]
						, sizeDataReadNext ) ;
					pData +=  sizeDataReadNext ;
				}
				sizeData -= sizeDataReadNext ;
				iRv += sizeDataReadNext ;
			}
		}
		
		return ( iRv ) ;
	}
	
	/**
	 * @return
	 * 	現在バッファにあるバイト数を返します。
	 */
	int Size()const 
	{
		int	iRv = 0 ;
		NODE*	pNode = NULL ;
		for ( pNode = m_pnodeFirst ; 
				pNode != NULL ; 
				pNode = pNode->m_pNext ){
			iRv += pNode->m_iSize ;
		}
		return ( iRv ) ;
	}
	
	/**
	 * 	バッファのデータを破棄します。
	 */
	void Clear() 
	{
		//	空のノードは削除
		while ( m_pnodeFirst != NULL  ){
					NODE*	pNodeToDelete = m_pnodeFirst ;
					m_pnodeFirst = m_pnodeFirst->m_pNext ;
					delete pNodeToDelete ;
			
		}
		if ( m_pnodeFirst == NULL ){
			m_pnodeLast = NULL ;
		}
	}
};

// --------------------------------
//	デフォルトのバッファのシノニム
// --------------------------------
typedef CSequentialByteBuffer<>	CSequentialByteBuf ;



#endif /*CSequentialByteBuffer_h*/
