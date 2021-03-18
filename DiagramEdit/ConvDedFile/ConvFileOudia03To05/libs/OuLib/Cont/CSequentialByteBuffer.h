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
 * �y�T�v�z
 * 	  �L���[�`���Ńo�C�g�f�[�^��ۑ�����A�o�b�t�@����������N���X�ł��B
 *
 * �y�g�����z
 *
 * �P�D  �R���X�g���N�^�ŁA�I�u�W�F�N�g�𐶐����Ă��������B
 * 	  �e���v���[�g�����́A�o�b�t�@�̒P�ʃo�C�g���ł��Bthis�́A
 * 	�f�[�^�����̃o�C�g�����܂邽�тɁA�o�b�t�@���g�����܂��B
 *
 * �Q�D  ����Ȍ�́A�S�����o�֐����g�p�ł��܂��BWrite()�Ńo�b�t�@�ւ�
 * 	�f�[�^���������݁ARead�ł̓o�b�t�@����f�[�^��ǂݍ��ނ��Ƃ��ł��܂��B
 * 	Read() �́A�Ǎ��ɐ��������f�[�^���o�b�t�@�����菜���܂��B
 */
template < int iExpandSize = 8192 >
class CSequentialByteBuffer: public IfSequentialByteBuffer
{
// --------------------------------
//	�����f�[�^
// --------------------------------
 private:
	/**
	 *	�o�b�t�@�̒P�ʃo�C�g�����̃f�[�^��
	 *	�ێ�����\���̂ł��B
	 *	���̍\���̂̓`�F�C�����`�����܂��B
	 */
	struct NODE
	{
		/**
		 *	�o�b�t�@�{�̂ł��B
		 */
		char		m_abyBuffer[ iExpandSize ] ;
		
		/**
		 * 	m_byBuffer �̂����A�L���ȃf�[�^�����݂���擪�̓Y�����B
		 */
		int			m_iPos ;
		/**
		 * 	m_byBuffer �̂����A
		 * 	�L���ȃf�[�^�̃o�C�g���B
		 */
		int			m_iSize ;
		
		/**
		 * 	���̃m�[�h�ւ̃|�C���^�ł��B
		 * 	�Ȃ��ꍇ��NULL�ɂȂ�܂��B
		 */
		NODE*		m_pNext ;
	};
	/**
	 * 	�擪�̃m�[�h�ւ̃|�C���^�ł�
	 * 	�m�[�h���P���Ȃ��ꍇ��NULL�ł�
	 */
	NODE*			m_pnodeFirst ;
	
	/**
	 *
	 *	�����̃m�[�h�ւ̃|�C���^�ł�
	 *	�m�[�h���P���Ȃ��ꍇ��NULL�ł�
	 */
	NODE*			m_pnodeLast ;
	
// ********************************
//	�R���X�g���N�^
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
	 * 	�o�b�t�@�Ƀf�[�^���������݂܂��B
	 * @param pData  [in]
	 * 	�������ރf�[�^�̐擪�A�h���X���w�肵�Ă�������
	 * @param sizeData [in]
	 * 	�������ރf�[�^�̃T�C�Y���w�肵�Ă��������B
	 * @return
	 * 	�������݂ɐ��������o�C�g����Ԃ��܂��B
	 * 	-	-1:	���������m�ۂł��܂���B
	 */
	int Write( const char* pData , int sizeData ) 
	{
		int	iRv = 0 ;
		while ( iRv >= 0 && sizeData > 0 ){
			if ( iRv >= 0 ){
				if ( m_pnodeLast == NULL ){
					//	���݃o�b�t�@����̏ꍇ�́A�o�b�t�@��NODE��
					//	�V���ɍ쐬���A
					//	�擪�E�����Ƃ��ēo�^���܂��B
					NODE*	pNode = new NODE ;
					if ( pNode == NULL ){
						iRv = -1 ;	//	-1:	���������m�ۂł��܂���B
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
					//	������NODE����̏ꍇ�́A
					//	�V����NODE���쐬���A�����ɒǉ����܂��B
					NODE*	pNode = new NODE ;
					if ( pNode == NULL ){
						iRv = -1 ;	//	-1:	���������m�ۂł��܂���B
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
				//	������NODE�Ƀf�[�^����������
				int	iLastPos = m_pnodeLast->m_iPos + m_pnodeLast->m_iSize ;
				int sizeDataWriteNext = sizeData ;
				if ( sizeDataWriteNext > iExpandSize - iLastPos ){
					sizeDataWriteNext = iExpandSize - iLastPos ;
				}
				//sizeDataWriteNext =  �����̃m�[�h�ɏ������߂�o�C�g��
				
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
	 * 	�o�b�t�@����f�[�^��ǂݍ��݂܂��B
	 * 	�ǂݍ��񂾃f�[�^�́A�o�b�t�@�����菜����܂��B
	 * @param pData  [out]
	 * 	���̊֐��́A���̃A�h���X�ɓǂݍ��񂾃f�[�^���������݂܂��B
	 * 	�s�v�Ȃ�i�f�[�^�̓ǂݎ̂Ă��s���ꍇ�jNULL��n���Ă����܂��܂���B
	 * @param sizeData [in]
	 * 	�ǂݍ��ލő�o�C�g���ipData�̃o�b�t�@�T�C�Y�j���w�肵�Ă�������
	 * @return
	 * 	�Ǎ��ɐ��������o�C�g����Ԃ��܂��B
	 */
	int Read( char* pData , int sizeData ) 
	{
		int iRv = 0 ;	

		NODE*	pNode = NULL ;
		for ( pNode = m_pnodeFirst ; 
				pNode != NULL && iRv >= 0 && sizeData > 0 ;
				pNode = pNode->m_pNext ){
			if ( iRv >= 0 ){
				//	NODE����f�[�^��ǂݍ���
				int sizeDataReadNext = sizeData ;
				if ( sizeDataReadNext > pNode->m_iSize ){
					sizeDataReadNext = pNode->m_iSize ;
				}
				//sizeDataReadNext =  �擪�̂̃m�[�h����ǂݍ��߂�o�C�g��
				
				//	���[�U�[�o�b�t�@�ɃR�s�[
				if ( pData != NULL ){
					memcpy( pData  , 
						&pNode->m_abyBuffer[ pNode->m_iPos ]
						, sizeDataReadNext ) ;
					pData +=  sizeDataReadNext ;
				}
				sizeData -= sizeDataReadNext ;
				iRv += sizeDataReadNext ;
				
				//	�ǂݍ��񂾃f�[�^���m�[�h����폜
				pNode->m_iPos  += sizeDataReadNext ;
				pNode->m_iSize -= sizeDataReadNext ;

			}
		}
		
		//	��̃m�[�h�͍폜
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
	 * 	�o�b�t�@�̐擪����f�[�^��ǂݍ��݂܂����A
	 * 	�ǂݍ��񂾃f�[�^���o�b�t�@�����菜���܂���
	 * @param pData  [out]
	 * 	���̊֐��́A���̃A�h���X�ɓǂݍ��񂾃f�[�^���������݂܂��B
	 * 	�s�v�Ȃ�NULL��n���Ă����܂��܂���B
	 * @param sizeData [in]
	 * 	�ǂݍ��ލő�o�C�g���ipData�̃o�b�t�@�T�C�Y�j���w�肵�Ă�������
	 * @return
	 * 	�Ǎ��ɐ��������o�C�g����Ԃ��܂��B
	 */
	int Peek( char* pData , int sizeData )const 
	{
		int iRv = 0 ;	

		NODE*	pNode = NULL ;
		for ( pNode = m_pnodeFirst ; 
				pNode != NULL && iRv >= 0 && sizeData > 0 ;
				pNode = pNode->m_pNext ){
			if ( iRv >= 0 ){
				//	NODE����f�[�^��ǂݍ���
				int sizeDataReadNext = sizeData ;
				if ( sizeDataReadNext > pNode->m_iSize ){
					sizeDataReadNext = pNode->m_iSize ;
				}
				//sizeDataReadNext =  �擪�̂̃m�[�h����ǂݍ��߂�o�C�g��
				
				//	���[�U�[�o�b�t�@�ɃR�s�[
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
	 * 	���݃o�b�t�@�ɂ���o�C�g����Ԃ��܂��B
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
	 * 	�o�b�t�@�̃f�[�^��j�����܂��B
	 */
	void Clear() 
	{
		//	��̃m�[�h�͍폜
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
//	�f�t�H���g�̃o�b�t�@�̃V�m�j��
// --------------------------------
typedef CSequentialByteBuffer<>	CSequentialByteBuf ;



#endif /*CSequentialByteBuffer_h*/
