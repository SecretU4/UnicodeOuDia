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
// $Id: CMuiCopied.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
/** @file */
#ifndef Mu_CMuiCopied_h
#define Mu_CMuiCopied_h

#include "./Mui.h"
#include <deque>


// ****************************************************************
// CMuiCopied
// ****************************************************************
/**
@brief
	�N���X�C���X�^���X�̃R�s�[��ێ�����R���e�i�ł��B

	�N���X�C���X�^���X�̃R�s�[��ێ�����R���e�i�ł��B
	��U�R���e�i�ɒǉ������C���X�^���X�̃R�s�[�ɑ΂��ẮA
	getMuPtr() �ŃR�s�[�C���X�^���X�ւ̃|�C���^���擾���邱�Ƃ��ł��܂��B
	����ɂ��A�R�s�[�C���X�^���X�ɑ΂��Ē��ڃ��\�b�h���Ăяo���A
	���̏�Ԃ�ύX���邱�Ƃ��ł��܂��B

	���̃N���X�́A�����I�ɂ̓C���X�^���X���R�s�[�R���X�g���N�^��new�ɂ�蕡�����A
	���̃R�s�[�̃|�C���^��ێ����܂��Bnew�ŕ��������C���X�^���X��delete���A���̃N���X��
	�s���܂��B 
	�R���e�i�ŕێ�����̂̓|�C���^�Ȃ̂ŁA���Ԃւ̗v�f�̒ǉ��E�폜��
	��r�I�Z���Ԃōs���܂��B

@param ElementType
	�R���e�i�Ɋi�[����v�f�̌^���w�肵�Ă��������B
@param ContType
	ElementType* ��ێ�����STL�R���e�i���w�肵�Ă��������B
	�K��ł� std::deque �ł����A std::vector ���g�����Ƃ��ł��܂��B
*/
template < class ElementType , class ContType =std::deque<ElementType*> >
class CMuiCopied : public Mui<ElementType>
{
private:
	// ********************************
	///@name �W��
	// ********************************
	/**
		ElementType �� new �Ő��������C���X�^���X��ێ�����R���e�i�ł��B
		���̃R���e�i���ێ�����C���X�^���X�̔j���̐Ӗ��� this �ɂ���܂��B
	*/
	ContType	m_Cont ;

private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	// ********************************
	//	"Mu< ElementType* >" �E�E�E getMuPtr()
	// ********************************
	/**
	 @brief
		CaMup::getMuPtr() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
		���������N���X�ł��B
	 */
	class XMuPtr : public Mu< ElementType* >
	{
	public:
		virtual int	size()const
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuPtr) ) ;
			return pOuter->m_Cont.size() ; 
		} ;
		virtual ElementType* get( int idx )const 
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuPtr) ) ;
			if ( idx == INT_MAX )
			{
				idx = pOuter->m_Cont.size() - 1 ;
			}
			ElementType*	pRv = pOuter->m_Cont[idx] ;
			return ( pRv ) ;
		};
	}	m_xMuPtr ;
	friend class XMuPtr ;
	//*******************************
	// 	"Mu< const ElementType* >" �E�E�E getMuConstPtr() 
	//*******************************
	/**
	 @brief
		CaMup::getMuConstPtr() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
		���������N���X�ł��B
	 */
	class XMuConstPtr : public Mu< const ElementType* >
	{
	public:
		virtual int	size()const
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuConstPtr) ) ;
			return pOuter->m_Cont.size() ; 
		} ;
		virtual const ElementType* get( int idx )const 
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuConstPtr) ) ;
			if ( idx == INT_MAX )
			{
				idx = pOuter->m_Cont.size() - 1 ;
			}
			ElementType*	pRv = pOuter->m_Cont[idx] ;
			return ( pRv ) ;
		};
	}	m_xMuConstPtr ;
	friend class XMuConstPtr ;


	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CMuiCopied(){} ; 
	CMuiCopied( const CMuiCopied<ElementType,ContType>& value )
	{
		//	�v�f�𕡐�
		for ( int idx = 0 ; idx < value.size() ; idx ++ )
		{
			m_Cont.push_back( new ElementType( value.get( idx ) ) ) ;
		}
	};

	CMuiCopied& operator=( const CMuiCopied<ElementType,ContType>& value ) 
	{
		//	���ׂĂ̗v�f��j��
		while ( m_Cont.size() > 0 )
		{
			ElementType* p = m_Cont.back() ;
			delete p ;
			m_Cont.pop_back() ;
		}

		//	�v�f�𕡐�
		for ( int idx = 0 ; idx < value.size() ; idx ++ )
		{
			m_Cont.push_back( new ElementType( value.get( idx ) ) ) ;
		}
		return *this ;
	};
	virtual ~CMuiCopied()
	{
		//	���ׂĂ̗v�f��j��
		while ( m_Cont.size() > 0 )
		{
			ElementType* p = m_Cont.back() ;
			delete p ;
			m_Cont.pop_back() ;
		}
	} ; 
public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	
	/**
	 @return
	 	�R���e�i�Ɋi�[����Ă���v�f�̌���Ԃ��܂��B
	*/
	virtual int	size()const{	return m_Cont.size() ;};
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
	 	�v�f�̃R�s�[��Ԃ��܂��B
	 @param iIndex [in]
	 	0 ����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂� 0 �ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
	*/
	virtual ElementType get( int iIndex )const
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = m_Cont.size() - 1 ;
		}
		ElementType* p = m_Cont[iIndex] ;
		return *p ;
	};
	///@}
public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f�̃R�s�[��ǉ����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int insert( const ElementType& element , int iIndex = INT_MAX ) 
	{
		int iRv = 0 ;
		if ( iIndex == INT_MAX )
		{
			iIndex = m_Cont.size() ;
		}
		// --------------------------------	
		if ( !( 0 <= iIndex && iIndex <= (int)m_Cont.size() ) )
		{
			iRv = -1 ;	//	�C���f�N�X���͈͊O�ł��B
		}
		else
		{
			m_Cont.insert( 
				m_Cont.begin() + iIndex , 
				new ElementType( element ) ) ;
		}
		// --------------------------------	
		return iRv ;
	}
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
	 	�v�f���폜���܂��B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param iSize [in]
	 	�폜����v�f�̐����w�肵�Ă��������B
	 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
	 @attention
		iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) 
	{
		int iRv = 0 ;
		if ( iIndex == INT_MAX && iSize != INT_MAX )
		{
			iIndex = m_Cont.size() - iSize ;
		}
		else if ( iIndex != INT_MAX && iSize == INT_MAX )
		{
			iSize = m_Cont.size() - iIndex ;
		}
		// --------------------------------	
		if ( !( 0 <= iIndex && iIndex + iSize <= (int)m_Cont.size() ) )
		{
			iRv = -1 ;	//	�C���f�N�X���͈͊O�ł��B
		}
		else
		{
			//	�w��̗v�f��j��
			while ( iSize > 0 )
			{
				iSize -- ;
				ElementType* p = m_Cont[iIndex+iSize] ;
				delete p ;
				m_Cont.erase( m_Cont.begin() + iIndex + iSize );
			}
		}
		// --------------------------------	
		return iRv ;
	}
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f���㏑�����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int set( const ElementType& element , int iIndex ) 
	{
		int iRv = 0 ;
		if ( iIndex == INT_MAX )
		{
			iIndex = m_Cont.size() - 1 ;
		}
		// --------------------------------	
		if ( !( 0 <= iIndex && iIndex < (int)m_Cont.size() ) )
		{
			iRv = -1 ;	//	�C���f�N�X���͈͊O�ł��B
		}
		else
		{
			//	�w��̗v�f��j��
			ElementType* p = m_Cont[iIndex] ;
			delete p ;
			m_Cont[iIndex] = new ElementType( element ) ;
		}
		// --------------------------------	
		return iRv ;
	}
	///@}
public:
	// ********************************
	///@name CMuiCopied
	// ********************************
	///@{
	/**
		�C���X�^���X�𒼐ڑ��삷�邽�߂� Mu �C���^�[�t�F�[�X��Ԃ��܂��B
	*/
	virtual Mu<ElementType*>* getMuPtr()
	{	return &m_xMuPtr ;};
	
	/**
		�C���X�^���X�𒼐ڑ��삷�邽�߂� Mu �C���^�[�t�F�[�X��Ԃ��܂��B
	*/
	virtual const Mu<const ElementType*>* getMuPtr()const 
	{	return &m_xMuConstPtr ;};
	
	
	///@}
};



#endif //Mu_CMuiCopied_h

