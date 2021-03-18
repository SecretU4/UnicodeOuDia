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


(��: 

	OuDia - ��Ԏ����\�����ƂɁA�_�C���O������`�悷��Win32�A�v���P�[�V
�����B

Copyright (C) 2006-2017 take-okm 

���̃v���O�����̓t���[�\�t�g�E�F�A�ł��B���Ȃ��͂�����A�t���[�\�t�g�E�F�A��
�c�ɂ���Ĕ��s���ꂽGNU ��ʌ��O���p������(�o�[�W����3���A����ȍ~�̃o�[�W��
���̂����ǂꂩ)����߂�����̉��ōĔЕz�܂��͉��� ���邱�Ƃ��ł��܂��B

���̃v���O�����͗L�p�ł��邱�Ƃ�����ĔЕz����܂����A*�S���̖��ۏ� *�ł��B
���Ɖ\���̕ۏ؂����ړI�ւ̓K�����́A���O�Ɏ����ꂽ���̂� �܂߁A�S������
���܂���B�ڂ�����GNU ��ʌ��O���p���������������������B

���Ȃ��͂��̃v���O�����Ƌ��ɁAGNU ��ʌ��O���p�������̃R�s�[���ꕔ �󂯎��
�Ă���͂��ł��B�����󂯎���Ă��Ȃ���΁A<http://www.gnu.org/licenses/> ��
�������������B

)

  �����āA���ʂȗ�O�Ƃ��āAtake-okm �͂��̃v���O�����̃R�[�h�� 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  ���邢�� "MFC Version 9.0" �Ɠ������C�Z���X���K�p���ꂽ
  "MFC Version 9.0" �̉��ς��ꂽ�o�[�W����)�ƃ����N���A
  �����N���ꂽ���҂��܂ތ������앨��Еz���鋖��^���܂��B
  ���Ȃ��� "MFC" �ȊO�Ŏg���Ă��邷�ׂ�
  �̃R�[�h�Ɋւ��Ă͑S�ʓI��GNU��ʌ��O���p�����_�񏑂ɏ]��Ȃ����
  �Ȃ�܂���B���Ȃ������̃t�@�C�������ς����Ȃ�΁A���Ȃ��͂��̗�O
  �����Ȃ��̃o�[�W�����̃t�@�C���Ɉ��������݂��邱�Ƃ��ł��܂����A��
  ������`���͂���܂���B������O��݂������Ȃ���΁A���̗�O������
  ���Ȃ��̃o�[�W��������͍폜���Ă��������B)
*/
/*
// ****************************************************************
//	CVerticalTextElementBuilder.cpp
// ****************************************************************
*/
#include "DcDraw\CVerticalTextElementBuilder.h"
#include "LogMsg\logmsg.h"
#include "Str\Str.h"

namespace DcDrawLib{
namespace DcDraw{
	using namespace OuLib::Str;
	using namespace std ;



bool CVerticalTextElementBuilder::isSpace( const string& aStr )
{
	const char* const kyoukai[] = {
		" " , "�@" ,
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}

bool CVerticalTextElementBuilder::isDelimiter( const string& aStr )
{
	const char* const kyoukai[] = {
		"," , "�C" ,
		"." , "�D" ,
		      "�B" , 
		      "�A" , 
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}


	// ********************************
	//@name CVerticalTextElementBuilder-����
	// ********************************
void CVerticalTextElementBuilder::scan( 
		const std::string& aStr , 
		Mui<CVerticalTextElement>* muCVerticalTextElement ,
		bool bTwoDegiLateral  ) 
{
	int iRv = 0 ;

	//	���̃R���e�i������܂ŕێ����Ă����v�f�͔j�����܂��B
	muCVerticalTextElement->erase( 0 , INT_MAX ) ;

	CStrCharSizeMb	aCStrCharSizeMb( aStr ) ;
	for ( int bidx = 0 ; 
			bidx < aCStrCharSizeMb.ByteLength() ; 
			bidx = aCStrCharSizeMb.BidxNextChar( bidx ) )
	{
		LogMsgL( 3 , "CDcdTextboxV3::StringToMojiretsuyouso"
			"bidx=%d CsizeOfBidx=%d" , bidx , aCStrCharSizeMb.CsizeOfBidx( bidx ) ) ;

		string strChar = aStr.substr( bidx , 
			aCStrCharSizeMb.CsizeOfBidx( bidx ) ) ;
		CVerticalTextElement	aElementPrev ;
		if ( muCVerticalTextElement->size() > 0 )
		{
			aElementPrev = muCVerticalTextElement->get( INT_MAX ) ;
		}
		//strChar = ����̕����B
		//aElementPrev = ���O�̕�����v�f

		if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 1 )
		{
			//	����̕����͂P�o�C�g����

			string strCharPrev ;
			if ( !aElementPrev.isNull() ){
				strCharPrev = aElementPrev.getString().substr( 
					aElementPrev.getString().size() - 1 , 1 ) ;
			}
			//strCharPrev = ���O�̕�����v�f�̖����̕���

			if ( !isSpace( strChar ) && 
				!aElementPrev.isNull() && 
				aElementPrev.getType() == aElementPrev.V_HANKAKU &&
				!isDelimiter( strCharPrev ) && !isSpace( strCharPrev ) )
			{
				//	����̕����͋󔒈ȊO�̂P�o�C�g�����ŁA
				//	( ���O�̕�����v�f�� V_HANKAKU �A
				//	���A���O�̕�����v�f����؂蕶����󔒂ŏI����Ă��Ȃ�
				//	) 
				//	�ꍇ�́A���O�̕�����v�f�ɕ�����ǉ����܂��B
				//
				aElementPrev.setString( aElementPrev.getString() + strChar );
				muCVerticalTextElement->set( aElementPrev , INT_MAX ) ;
			}
			else
			{
				//	������v�f��ǉ����܂��B
				CVerticalTextElement	aElement( strChar , CVerticalTextElement::V_HANKAKU ) ;

				muCVerticalTextElement->insert( aElement ) ;
			}
		}
		else if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 2 )
		{
			//	����̕����͂Q�o�C�g�����ł���ꍇ�́A������v�f��ǉ����܂��B

			//	����̕����͂Q�o�C�g�̋�؂蕶���ŁA
			//	( ���O�̕�����v�f�� V_ZENKAKU 
			//	) 
			//	�ꍇ�́A���O�̕�����v�f�ɕ�����ǉ����܂��B
			//
			if ( isDelimiter( strChar ) && 
				!aElementPrev.isNull() && 
				aElementPrev.getType() == CVerticalTextElement::V_ZENKAKU )
			{
				aElementPrev.setString( aElementPrev.getString() + strChar );
				muCVerticalTextElement->set( aElementPrev , INT_MAX ) ;

			}
			else
			{
				//	�V����������v�f��ǉ����܂��B
				CVerticalTextElement aElement( strChar , CVerticalTextElement::V_ZENKAKU ) ;
				muCVerticalTextElement->insert( aElement ) ;

			}
		}

	}
	//muCVerticalTextElement = ������� V_ZENKAKU �� V_HANKAKU �̂Q��
	//	�v�f�ɕ������܂����B
	//	V_ZENKAKU �́A�����Ƃ��đS�p�����P�ł��B
	//	�A���A[�S�p����][�S�p��؂蕶��]
	//	�́A[�S�p����+�S�p��؂蕶��]�̂P�̗v�f�ɂȂ��Ă��܂��B
	//	V_HANKAKU �́A�A���������p�������P�̗v�f�Ƃ��܂��B

	// --------------------------------
	//	2���ȉ��̔��p�������������ɂ���
	// --------------------------------
	if ( bTwoDegiLateral  )
	{
		// --------------------------------	
		int idxMojiretsuyouso ;
		for ( idxMojiretsuyouso = 0 ; 
				idxMojiretsuyouso < muCVerticalTextElement->size() ;
				idxMojiretsuyouso ++ )
		{
			//	����̕�����v�f�����p�p�����P�������Q���� 
			//	AND 
			//	( 
			//		( �O�̕�����v�f�����݂��Ȃ�)
			//		OR
			//		( �O�̕�����v�f���i�󔒈ȊO�̔��p������̗v�f�j�łȂ�)
			//	) 
			//	
			//	�̏ꍇ�́A���������ɔ��p�p������1�����E2�����ŕ��ׂ܂��B
			CVerticalTextElement aElementPrev ;
			if ( idxMojiretsuyouso > 0 )
			{
				aElementPrev = muCVerticalTextElement->get( idxMojiretsuyouso - 1 ) ;
			}
			CVerticalTextElement aElement = muCVerticalTextElement->get( idxMojiretsuyouso ) ;
			string strCurr = aElement.getString() ;
			if ( aElement.getType() == CVerticalTextElement::V_HANKAKU )
			{
				if ( 
					( strCurr.size() == 1 && isdigit( (unsigned char)strCurr[0] ) ) || 
					( strCurr.size() == 2 && isdigit( (unsigned char)strCurr[0] ) && isdigit( (unsigned char)strCurr[1] ) ) 
				){

					if ( aElementPrev.isNull() || 
						!(  
							aElementPrev.getType() == CVerticalTextElement::V_HANKAKU && 
							!isSpace( aElementPrev.getString() ) 
						) 
					){
						aElement.setType( CVerticalTextElement::H_HANKAKU ) ;
						muCVerticalTextElement->set( aElement , idxMojiretsuyouso ) ;
					}
				}
					
			}

		}
	}	

};

} //namespace DcDraw
} //namespace DcDrawLib





