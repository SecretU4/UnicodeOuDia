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
// ****************************************************************
//	$Id: CConvCsvDocument.cpp 285 2016-06-05 08:10:51Z okm $
// ****************************************************************
/** @file */
#include "CConvCsvDocument.h"

namespace OuLib{
namespace Str{
namespace CsvDocument{

using std::string ;


// ****************************************************************
//	CCsvDecoder
// ****************************************************************
/**
@brief
	CSV�t�@�C���̓��e�����߂��� CdCsvDocument �I�u�W�F�N�g��
	�\������ۂ̏�ԋ@�B�ł��B

�y�g�����z

1.  �C���X�^���X�𐶐����Ă��������B

2.  CSV�t�@�C���̓��e�� addChar() ���\�b�h�ŉ��߂����Ă��������B

3.  CSV�t�@�C���̓��e�����ׂ� addChar() �ɓn������́A addEof() ��
�Ăяo���Ă��������B
�@���̏�Ԃ� CdCsvDocument �̍\�����I�����܂��BgetCdCsvDocument() ��
 �\�������h�L�������g���擾���邱�Ƃ��ł��܂��B

4.  �V����CSV�t�@�C�������߂�����ꍇ�́A
�@�V�����C���X�^���X�𐶐����Ȃ��Ă͂Ȃ�܂���B
*/
class CCsvDecoder
{
public:
	// ********************************
	///@name �C���i�[�^�C�v
	// ********************************
	///@{
	enum EState
	{
		/**
			���p���̊O��
		*/
		EState_OuterQuote ,
		/**
			���p���̓���
		*/
		EState_InnerQuote ,
		/**
			���p���̓����́A1�ڂ̈��p���̒���
		*/
		EState_QuoteInnerQuote ,
	};
	///@}
private:
	// ********************************
	///@name ��� 
	// ********************************
	///@{
	/**
		���݂̏��
	*/
	EState m_EState ;
	/**
		���ݍ\�����̃h�L�������g
	*/
	CdCsvDocument	m_CdCsvDocument ;
	/**
		���ݍ\�����̍s
	*/
	CdCsvRow	m_CdCsvRow ;
	/**
		���ݍ\�����̃Z���̕�����
	*/
	std::string	m_strCellData ;
	///@}
private:
	// --------------------------------
	///@name addChar() �̉����֐�
	// --------------------------------
	///@{
	void addChar_EState_OuterQuote( char ch ) ;
	void addChar_EState_InnerQuote( char ch ) ;
	void addChar_EState_QuoteInnerQuote( char ch ) ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CCsvDecoder()
		: m_EState( EState_OuterQuote ) 
	{
	};
	// ********************************
	///@name ��� 
	// ********************************
	///@{
	CdCsvDocument	getCdCsvDocument()
	{	return m_CdCsvDocument ;};
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		CSV�t�@�C���̓��e�����߂����܂��B
	@param ch [in]
		�t�@�C���̓��e�̃L�����N�^���w�肵�Ă��������B
	*/
	void addChar( char ch ) ;
	/**
		CSV�t�@�C���̉��߂��I�������܂��B
	@return
		-	0 ;	//	����
		-	-1 ;	//	���p�������Ă��܂���
	//	
	*/
	int addEof() ;
	///@}
};
void CCsvDecoder::addChar_EState_OuterQuote( char ch ) 
{
			if ( ch == '\n' )
			{
				if ( m_strCellData.size() > 0 
						|| m_CdCsvRow.getCellCont()->size() )
				{
					m_CdCsvRow.getCellCont()->insert( CdCsvCell( m_strCellData ) , INT_MAX ) ;
					m_strCellData.erase() ;
				}
				{
					m_CdCsvDocument.getRowCont()->insert( m_CdCsvRow ) ;
					m_CdCsvRow.getCellCont()->erase( 0 , INT_MAX ) ;

				}

			}
			else if ( ch == ',' )
			{
				{
					m_CdCsvRow.getCellCont()->insert( CdCsvCell( m_strCellData ) , INT_MAX ) ;
					m_strCellData.erase() ;
				}
			}
			else if ( ch == '\"' )
			{
				m_EState = EState_InnerQuote ;
			}
			else
			{
				m_strCellData += ch ;
			}
}
void CCsvDecoder::addChar_EState_InnerQuote( char ch ) 
{
			if ( ch == '\n' )
			{
				m_strCellData += ch ;
			}
			else if ( ch == ',' )
			{
				m_strCellData += ch ;
			}
			else if ( ch == '\"' )
			{
				m_EState = EState_QuoteInnerQuote ;
			}
			else
			{
				m_strCellData += ch ;
			}
}
void CCsvDecoder::addChar_EState_QuoteInnerQuote( char ch ) 
{
			if ( ch == '\n' )
			{
				m_EState = EState_OuterQuote ;
				addChar_EState_OuterQuote( ch ) ; 
			}
			else if ( ch == ',' )
			{
				m_EState = EState_OuterQuote ;
				addChar_EState_OuterQuote( ch ) ; 
			}
			else if ( ch == '\"' )
			{
				m_strCellData += ch ;
				m_EState = EState_InnerQuote ;
			}
			else
			{
				m_EState = EState_OuterQuote ;
				addChar_EState_OuterQuote( ch ) ; 
			}
}

void CCsvDecoder::addChar( char ch ) 
{
	switch( m_EState )
	{
	case EState_OuterQuote :
		//	���p���̊O��
		{
			addChar_EState_OuterQuote( ch ) ;
		}
		break ;
	case EState_InnerQuote :
		//	���p���̓���
		{
			addChar_EState_InnerQuote( ch ) ;
		}
		break ;
	case EState_QuoteInnerQuote :
		//	���p���̓����́A1�ڂ̈��p���̒���
		{
			addChar_EState_QuoteInnerQuote( ch ) ;
		}
		break ;
	}
}
int CCsvDecoder::addEof() 
{
	int iRv = 0 ;
	switch( m_EState )
	{
	case EState_OuterQuote :
	case EState_QuoteInnerQuote :
		//	���p���̓����́A1�ڂ̈��p���̒���
		{
			if ( m_strCellData.size() > 0 
						|| m_CdCsvRow.getCellCont()->size() )
			{
				m_CdCsvRow.getCellCont()->insert( CdCsvCell( m_strCellData ) , INT_MAX ) ;
				m_strCellData.erase() ;
			}
			if ( m_CdCsvRow.getCellCont()->size() > 0 
					|| m_CdCsvRow.getCellCont()->size() > 0 )
			{
				m_CdCsvDocument.getRowCont()->insert( m_CdCsvRow ) ;
				m_CdCsvRow.getCellCont()->erase( 0 , INT_MAX ) ;

			}
		}
		break ;
	case EState_InnerQuote :
		//	���p���̓���
		{
			iRv = -1 ;	//	���p�������Ă��܂���
		}
		break ;
	}

	return iRv ;
}

// ****************************************************************
	// --------------------------------
	//@name �����֐�
	// --------------------------------
std::string CConvCsvDocument::encodeCell( const CdCsvCell& aCdCsvCell ) 
{
	string strCell = aCdCsvCell.getData() ;
	string strRv ;

	bool bMustQuote = false ;
	for ( int idx = 0 ; idx < (int)strCell.size() ; idx ++ )
	{
		if ( strCell[idx] == '\n' )
		{
			bMustQuote = true ;
			strRv += strCell[idx] ;
		}
		else if ( strCell[idx] == '\"' )
		{
			bMustQuote = true ;
			strRv += "\"\"" ;
		}
		else
		{
			strRv += strCell[idx] ;
		}
	}
	if ( bMustQuote )
	{
		strRv = string( "\"" ) + strRv + "\"" ;
	}

	return strRv ;
}
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CConvCsvDocument::CConvCsvDocument(void)
{
}

CConvCsvDocument::~CConvCsvDocument(void)
{
}
	// ********************************
	//@name	CConvCsvDocument
	// ********************************
string CConvCsvDocument::encode( const CdCsvDocument* pCdCsvDocument ) 
{
	string strRv ;

	const Mu< const CdCsvRow& >* pRowCont = pCdCsvDocument->getRowCont() ;
	for ( int idxRow = 0 ; 
			idxRow < pRowCont->size() ;
			idxRow ++ )
	{
		CdCsvRow	aCdCsvRow = pRowCont->get( idxRow ) ;


		string strRow ;
		const Mu< CdCsvCell >* pCellCont = aCdCsvRow.getCellCont() ;
		for ( int idxCell = 0 ; idxCell < pCellCont->size() ; idxCell ++ )
		{
			if ( idxCell > 0 )
			{
				strRow += ',' ;
			}

			string strCell ;
			CdCsvCell	aCdCsvCell = pCellCont->get( idxCell ) ;
			strCell = encodeCell( aCdCsvCell ) ;

			strRow += strCell ;
		}

		strRv += strRow ;
		strRv += '\n' ;
	}
	return strRv ;
}
int CConvCsvDocument::decode( CdCsvDocument* pCdCsvDocument 
		, const string& strCsvText ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 )
	{
		CCsvDecoder	aCCsvDecoder ;
		for ( int idxChar = 0 ; idxChar < (int)strCsvText.size() ; idxChar ++ )
		{
			aCCsvDecoder.addChar( strCsvText[idxChar] ) ;
		}
		int iResult = aCCsvDecoder.addEof() ;
		//-	-1 ;	//	���p�������Ă��܂���
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
		else
		{
			*pCdCsvDocument = aCCsvDecoder.getCdCsvDocument() ;
		}
	}
	return iRv ;
}


} //namespace CsvDocument{
} //namespace Str{
} //namespace OuLib{

