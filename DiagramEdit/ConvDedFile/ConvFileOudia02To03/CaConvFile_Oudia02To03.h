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
// CaConvFile_Oudia02To03.h: CaConvFile_Oudia02To03 クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CACONVFILE_OUDIA02TO03_H__C6796EB2_3AB2_477C_8B68_CDF1F244CB53__INCLUDED_)
#define AFX_CACONVFILE_OUDIA02TO03_H__C6796EB2_3AB2_477C_8B68_CDF1F244CB53__INCLUDED_
/** @file */
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IfConvFile.h"
/**
@brief
	ConvFile2Dll のクラス
*/
class CaConvFile_Oudia02To03 : public IfConvFile  
{
public:
	CaConvFile_Oudia02To03();
	virtual ~CaConvFile_Oudia02To03();
public:
	// ********************************
	///@name IfConvFile
	// ********************************
	///@{
	/**
		LeftFormat から RightFormat への変換を行います。
	@param pLeftFormat [in]
		LeftFormat のデータを指定してください。
	@param pRightFormat [out]
		この関数は変換が成功したら、
		このバッファに、RightFormat のデータを書き込みます。
	@param pErrorInfoString [out] 
		この関数は変換が失敗したら、
		このバッファにエラーの内容を示す文字列を
		書き込みます。
		但し、すべての ConvFile クラスがこの機能をサポートしているわけでは
		ありません。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	pLeftFormat は正しい LeftFormat ではありません。
	*/
	virtual int LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) ; 

	/**
		LeftFormat が変換可能なフォーマットであるか否かを
		判定します。
		
		この関数は LeftFormat のデータの特徴に対して簡単な検査を
		行います。
		この関数が成功しても、 LeftToRight() が成功するとは
		限りません。
	@param pLeftFormat [in]
		LeftFormat のデータを指定してください。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	0 以上 ;	//	変換可能なフォーマットです。
		-	-1 ;	//	pLeftFormat は正しい LeftFormat ではありません。
	*/
	virtual int isLeftFormat( 
		const IfByteBuffer* pLeftFormat)  ; 

	/**
	@return 
		- true ;	//	RightToLeft(),isRightFormat() メソッドをサポートしています。
		- false ;	//	RightToLeft(),isRightFormat() メソッドをサポートしていません。
	*/
	virtual bool RightToLeftIsSupported(); 

	/**
		RightFormat から LeftFormat への変換を行います。
	@param pRightFormat [in]
		RightFormat のデータを指定してください。
	@param pLeftFormat [out]
		この関数は変換が成功したら、
		このバッファに、LeftFormat のデータを書き込みます。
	@param pErrorInfoString [out] 
		この関数は変換が失敗したら、
		このバッファにエラーの内容を示す文字列を
		書き込みます。
		但し、すべての ConvFile クラスがこの機能をサポートしているわけでは
		ありません。
		不要であればNULLでもかまいません。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	pLeftFormat は正しい LeftFormat ではありません。
		-	-2 ;	//	このメソッドはサポートされていません。
	*/
	virtual int RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) ; 

	/**
		RightFormat が変換可能なフォーマットであるか否かを
		判定します。
		
		この関数は RightFormat のデータの特徴に対して簡単な検査を
		行います。
		この関数が成功しても、 LeftFromRight() が成功するとは
		限りません。
	@param pRightFormat [in]
		RightFormat のデータを指定してください。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	0 以上 ;	//	変換可能なフォーマットです。
		-	-1 ;	//	pRightFormat は正しい RightFormat ではありません。
		-	-2 ;	//	このメソッドはサポートされていません。
	*/
	virtual int isRightFormat( 
		const IfByteBuffer* pRightFormat ) ; 
	///@}

};

#endif // !defined(AFX_CACONVFILE_OUDIA02TO03_H__C6796EB2_3AB2_477C_8B68_CDF1F244CB53__INCLUDED_)
