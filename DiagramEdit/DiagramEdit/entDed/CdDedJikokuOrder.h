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
//$Id: CdDedJikokuOrder.h 373 2016-08-20 21:59:57Z okm $
// ****************************************************************
/** @file */


#ifndef CdDedJikokuOrder_h
#define CdDedJikokuOrder_h

namespace entDed{

// ****************************************************************
//	CdDedJikokuOrder
// ****************************************************************

/**
@brief
    CdDedJikokuOrder �́A�w�����̗v�f����肷��l�ł��B

����́A�����\�̊e��ɕ\�����ׂ����e�̎�ނ������l�ł�����܂��B
�ȉ��̑�������Ȃ�܂��B

 - �wOrder
 - �\�����e{���E��}

���̃N���X�́ANULL��Ԃ������Ƃ��ł��܂��B
*/
class CdDedJikokuOrder
{
public:
	/** �w�����̗v�f��\���񋓂ł��B */
	enum EEkiJikokuItem
	{
		EkiJikokuItem_Chaku = 0 ,	///<������
		EkiJikokuItem_Hatsu = 1 ,	///<������
	};
private:
	/**
		����Order�B
		���̒l�����̐��̏ꍇ�́ANULL��ԂƂȂ�܂��B
	*/
	int m_iEkiOrder ;
	/**
		�w�����̗v�f
	*/
	EEkiJikokuItem m_eEkiJikokuItem  ;
public:
	/**
		NULL ��Ԃŏ��������܂��B
	*/
	CdDedJikokuOrder() 
		: m_iEkiOrder( -1 )
		, m_eEkiJikokuItem( EkiJikokuItem_Chaku ){};

	/** 
	@param iEkiOrder [in]
		�wOrder 
	@param eEkiJikokuItem [in]
		�w�����̗v�f
	*/
	CdDedJikokuOrder( int iEkiOrder , EEkiJikokuItem eEkiJikokuItem ) 
		: m_iEkiOrder( iEkiOrder ) 
		, m_eEkiJikokuItem( eEkiJikokuItem ) 
	{};


	bool getIsNull()const{	return m_iEkiOrder < 0 ;};
	void setIsNull()
	{	
		m_iEkiOrder = -1 ; 
		m_eEkiJikokuItem = EkiJikokuItem_Chaku ;
	};

	int getEkiOrder()const{	return m_iEkiOrder ;};
	EEkiJikokuItem getEkiJikokuItem()const{	return m_eEkiJikokuItem ;};

	/** 
	@param iEkiOrder [in]
		�wOrder 
	@param eEkiJikokuItem [in]
		�w�����̗v�f��\����
	*/
	void setEkiOrder( int iEkiOrder , EEkiJikokuItem eEkiJikokuItem )
	{
		m_iEkiOrder = iEkiOrder ;
		m_eEkiJikokuItem = eEkiJikokuItem ;
	};

	/**
		EEkiJikokuItem �̒��E���𔽓]���܂��B
	@param eEkiJikokuItem [in]
		���]������ EkiJikokuItem ���w�肵�Ă��������B
	@return
		- eEkiJikokuItem �� EkiJikokuItem_Chaku �Ȃ�AEkiJikokuItem_Hatsu�B
		- eEkiJikokuItem �� EkiJikokuItem_Hatsu �Ȃ�AEkiJikokuItem_Chaku�B
		- ����ȊO�̏ꍇ�́AeEkiJikokuItem �����̂܂ܕԂ��܂��B
	*/
	static EEkiJikokuItem EkiJikokuItemInvert( 
		EEkiJikokuItem eEkiJikokuItem )
	{
		EEkiJikokuItem	eRv = eEkiJikokuItem ;
		if ( eRv == EkiJikokuItem_Chaku )
		{
			eRv = EkiJikokuItem_Hatsu ;
		}
		else if ( eRv == EkiJikokuItem_Hatsu )
		{
			eRv = EkiJikokuItem_Chaku ;
		}
		return eRv ;
	}

	/**
		m_eEkiJikokuItem �̒��E���𔽓]���܂��B

		- m_eEkiJikokuItem �� EkiJikokuItem_Chaku �Ȃ�AEkiJikokuItem_Hatsu�B
		- m_eEkiJikokuItem �� EkiJikokuItem_Hatsu �Ȃ�AEkiJikokuItem_Chaku�B
		- ����ȊO�̏ꍇ�́AeEkiJikokuItem �����̂܂ܕԂ��܂��B
	*/
	void EkiJikokuItemInvert( void )
	{
		m_eEkiJikokuItem = EkiJikokuItemInvert( m_eEkiJikokuItem ) ;
	}

	bool isEqualTo( const CdDedJikokuOrder& value )const
	{
		return ( m_iEkiOrder == value.m_iEkiOrder && 
				m_eEkiJikokuItem == value.m_eEkiJikokuItem ) 
			|| ( getIsNull() && value.getIsNull() );
	};

	bool operator==(  const CdDedJikokuOrder& value )const
	{	return isEqualTo( value ) ;	}
	bool operator!=(  const CdDedJikokuOrder& value )const
	{	return !isEqualTo( value ) ;	}
};

} //namespace entDed

#endif /*CdDedJikokuOrder_h*/
