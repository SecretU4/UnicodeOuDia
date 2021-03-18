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
//	CaMuiSelect.h
//	$Id: CaMuiSelect.h 344 2016-08-14 06:31:32Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  Mu_CaMuiSelect_h
#define  Mu_CaMuiSelect_h
#include "./Mu.h"
#include <vector>
#include <algorithm>

/**
  CaMuiSelect �̎����A���S���Y����I�����邱�Ƃ��ł��܂��B

<h4>0</h4>

�v�f�̑I���� CaMuiSelect::m_contSelect �ɑ΂���
�L���b�V���͂���܂���B
CaMuiSelect::size()�ECaMuiSelect::indexToAdapteeIndex()�E
CaMuiSelect::indexFromAdapteeIndex() �́A
m_contSelect ���X�L�������܂��B

CaMuiSelectTest::run()�̎��s����(Debug �o�[�W����)=13�b�B

<h4>1</h4>
indexToAdapteeIndex() �̌��ʂ̃L���b�V�����A
�����o�ϐ� CaMuiSelect::m_AdapteeIndexCache ��
�ێ�����悤�ɂȂ�܂��B
CaMuiSelect::m_AdapteeIndexCache �� mutable �ɂȂ�܂��B

CaMuiSelectTest::run()�̎��s����(Debug �o�[�W����)=9�b�B
*/
#define CaMuiSelect_ALGORITHM	1

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU


// ****************************************************************
//	CaMuiSelect.h
// ****************************************************************
/**
@brief
  �A�_�v�^�N���X�ł��B
  �R���e�i�̈ꕔ�̗v�f��I�������`�́A�����R���e�i�C���^�[�t�F�[�X��
�쐬���܂��B

  ���̃N���X�́A����ΏۂƂȂ鑼�̃R���e�i(Adaptee)�̗v�f����A
�ꕔ��I�����������R���e�i��񋟂��܂��B
  �N���X���[�U�[�́A���̃N���X����� Adaptee �R���e�i�̈ꕔ�v�f��
�Q�Ƃ��邱�Ƃ��ł��܂��B
  Adaptee�R���e�i���I�u�W�F�N�g��ێ����Ă���A���̃I�u�W�F�N�g��
�|�C���^��Q�ƂɃA�N�Z�X�ł���ꍇ�́AAdaptee �R���e�i�̈ꕔ�v�f��
�΂��āA������s�����Ƃ��ł��܂��B

  ���̃N���X�́A�ȉ��̃C���^�[�t�F�[�X���T�|�[�g�����R���e�i��
Adaptee �Ƃ��đ��삷�邱�Ƃ��ł��܂��B
  �A���A���̂����̂��ׂĂ��T�|�[�g���Ă���K�v�͂���܂���B

  - Mu<ElementType1>   (�K�{)
  - Mui<ElementType1>  (�C��)
  - const Mu<const ElementType1*>�@(�C��)
  - Mu<ElementType1*>�@(�C��)

  Mui<ElementType1> ���w�肳�ꂽ�ꍇ�́AMu<ElementType1> ��
�w�肳�ꂽ���ƂɂȂ�܂��B
  
  	 
  CaMuiSelect �́A��������́A�P�̗v�f���I������Ȃ���Ԃł��B
  �C���X�^���X�𐶐�������A setSelect() �ŁA�v�f��I�����Ă��������B

<h3>
�y��1�zMu<ElementType1> ���T�|�[�g���Ă���R���e�i
</h3>

  Mu<string> ���T�|�[�g����R���e�i�ɁA�ȉ��̗v�f���i�[�����
�����Ƃ��܂��B(string �́Astd::string �̂��Ƃ��w���܂�)
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;
  
  ���̃R���e�i�� Mu<string>�C���^�[�t�F�[�X�ɑ΂��āA
 CaMuiSelect<string> �A�_�v�^��ݒ肵����A�v�f0,4,6��I�����邱�Ƃ�
���A CaMuiSelect�� Mu<string> �C���^�[�t�F�[�X�́A�ȉ��̂R��
�v�f��Ԃ��܂��B

  { "zero" , "four" , "six" } ;
  
 
 
<h3>
�y��2�zMui<ElementType1> ���T�|�[�g���Ă���R���e�i�ւ̒ǉ�
</h3>

  Mui<string> ���T�|�[�g����R���e�i�ɁA�ȉ��̗v�f���i�[�����
�����Ƃ��܂��B
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;

  ���̃R���e�i�� Mui<string>�C���^�[�t�F�[�X�ɑ΂��āA 
CaMuiSelect<string> �A�_�v�^��ݒ肵����A�v�f0,4,6��I�����邱�Ƃ�
���ACaMuiSelect�� Mui<string> �C���^�[�t�F�[�X�́A�ȉ��̂R��
�v�f��Ԃ��܂��B

  { "zero" , "four" , "six" } ;

  �����ŁACaMuiSelect �� insert() ���\�b�h���g���A0�Ԗڂɗv�f
 "newzero" ��}������ƁACaMuiSelect �́A�ȉ���4�̗v�f��Ԃ��悤��
�Ȃ�܂��B

  { "newzero" , "zero" , "four" , "six" } ;

  ����ΏۃR���e�i(m_pAdaptee)�̓��e�́A�ȉ��̂悤�ɂȂ�܂��B

  { "newzero" , "zero" , "one" , "two" , "three" , "four" , 
    "five" , "six" , "seven" } ;
  

  �܂��ACaMuiSelect�̗v�f�I���󋵂́A{0,1,5,7} �ƂȂ�܂��B



<h3>
�y��3�zMui<ElementType1> ���T�|�[�g���Ă���R���e�i����̍폜
</h3>

  Mui<string> ���T�|�[�g����R���e�i�ɁA�ȉ��̗v�f���i�[����Ă����Ƃ��܂��B
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;

  ���̃R���e�i�� Mui<string>�C���^�[�t�F�[�X�ɑ΂��āA CaMuiSelect<string> 
�A�_�v�^��ݒ肵����A�v�f0,4,6��I�����邱�Ƃɂ��A CaMuiSelect�� 
Mui<string> �C���^�[�t�F�[�X�́A�ȉ��̂R�̗v�f��Ԃ��܂��B

  { "zero" , "four" , "six" } ;

  �����ŁACaMuiSelect �� erase() ���\�b�h���g���A0�Ԗڂ���2�̗v�f��
�폜����ƁACaMuiSelect �́A�ȉ��̗v�f��Ԃ��悤�ɂȂ�܂��B

  {  "six" } ;

  ����ΏۃR���e�i(m_pAdaptee)�̓��e�́A�ȉ��̂悤�ɂȂ�܂��B

  { "one" , "two" , "three" , "five" , "six" , "seven" } ;
  

  �܂��ACaMuiSelect�̗v�f�I���󋵂́A{ 4 } �ƂȂ�܂��B


<h3>
�y��4�zMu<ElementType1*> �E const Mu<const ElementType1*> ���T�|�[�g
���Ă���R���e�i
</h3>

  Mui<string> ���T�|�[�g����R���e�i�ɁA�ȉ��̗v�f���i�[����Ă���A
���A���̃R���e�i�� Mu<string*> ���T�|�[�g���Ă����Ƃ��܂��B
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;

  ���̃R���e�i�� Mui<string*> �C���^�[�t�F�[�X�ɑ΂��āA
 CaMuiSelect<string> �A�_�v�^��ݒ肵����A�v�f0,4,6��I�����邱�Ƃɂ��A
 CaMuiSelect�� Mui<string> �C���^�[�t�F�[�X�́A�ȉ��̂R�̗v�f��Ԃ��܂��B

  { "zero" , "four" , "six" } ;

  CaMuiSelect �� getMuPtr() ���\�b�h�ŁA Mu<string*> �C���^�[�t�F�[�X���擾����
���Ƃ��ł��܂��B���� Mu<string*> �C���^�[�t�F�[�X�ł��A��L�̗v�f���擾����
���Ƃ��ł��܂��B

  ����ɁA���� Mu<string*> ���g���ƁA�i�[����Ă��� string �I�u�W�F�N�g��
�����o�֐����Ăяo������A�����o�ϐ��𒼐ڑ��삷�邱�Ƃ��ł��܂��B
  ��L��3�̗v�f�ɑ΂��āA string::erase() ���\�b�h���g�p���āA�擪��1������
�폜���邱�Ƃ��ł��܂��B

  { "ero" , "our" , "ix" } ;

  ����ΏۃR���e�i(m_pAdaptee)�̓��e�́A�ȉ��̂悤�ɂȂ�܂��B

  { "ero" , "one" , "two" , "three" , "our" , "five" , 
    "ix" , "seven" } ;

@note
  CMuiCopied �� Adaptee �Ƃ��Ă��̃N���X���g�p����ꍇ�́A
�ȉ��̂悤�ȃR���X�g���N�^�Ăяo���ŁA�C���X�^���X�𐶐����Ă��������B

@code
	CMuiCopied<CBase> aCont ;

	//	aCont �ɗv�f��ǉ�

	CaMuiSelect<CBase>	aSelect( &aCont , aCont.getMuPtr() ) ;
@endcode


@param ElementType1
  	�i�[����v�f�̌^���w�肵�Ă��������B
  	���̃N���X�́A Mu< ElementType1 > �C���^�[�t�F�[�X��
  	�T�|�[�g���܂��B
 */
template < class ElementType1 > class CaMuiSelect : 
	public Mui< ElementType1 > 
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mu<ElementType1>�C���^�[�t�F�[�X�ł��B
		
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
		�������Ȃ��Ă͂Ȃ�܂���B
		
		m_pAdapteeMui �ɗL���ȃC���^�[�t�F�[�X������ꍇ�́A
		���̃C���^�[�t�F�[�X���L���ɂȂ�܂��B
	*/
	Mu<ElementType1>*	m_pAdapteeMu ;

	/**
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i�́A 
		Mui<ElementType1>�C���^�[�t�F�[�X�ł��B

		����Ώۂ����̃C���^�[�t�F�[�X���T�|�[�g���Ă��Ȃ��ꍇ�́A
		NULL �Ƃ��邱�Ƃ��ł��܂��B
		�A���A���̃N���X�� set(),insert(),erase() ���\�b�h���g�p���邽�߂ɂ́A
		���̃C���^�[�t�F�[�X���Z�b�g����K�v������܂��B

		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
		�������Ȃ��Ă͂Ȃ�܂���B
		
		�܂��Athis�Ƃ̊֘A���L���ȊԂɁAthis�̃��\�b�h�ȊO�̕��@�ŁA
		���̃R���e�i�̗v�f����ς��Ȃ��ł��������B
		���̃N���X�́Am_pAdaptee �̗v�f���ƁAthis->m_contSelect�� �v�f����
		�قȂ�ƁA���������삵�Ȃ��Ȃ�܂��B
		�����Am_pAdapteeMui �̗v�f�����A�ς����ꍇ�́AsetAdaptee() �ŁA
		�֘A���Đݒ肵�Ă��������B
	*/
	Mui<ElementType1>*	m_pAdapteeMui ;

	/**
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mu<const ElementType1*> �C���^�[�t�F�[�X�ł��B
		
		����Ώۂ����̃C���^�[�t�F�[�X���T�|�[�g���Ă��Ȃ��ꍇ�́A
		NULL �Ƃ��邱�Ƃ��ł��܂��B
		�A���AgetMuPtr() �ɂ��C���^�[�t�F�[�X���g�p����ꍇ�́A
		m_pAdapteeMuConstPtr,m_pAdapteeMuPtr �̂����ꂩ��
		�K�v�ł��B

		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
		�������Ȃ��Ă͂Ȃ�܂���B

		m_pAdapteeMuPtr ���L���ȏꍇ�́A���̃C���^�[�t�F�[�X�̎w�肪�Ȃ��Ă�
		Mu<const ElementType1*> �C���^�[�t�F�[�X���g�p���邱�Ƃ��ł��܂��B
	*/
	Mu<const ElementType1*>* m_pAdapteeMuConstPtr ;
	
	/**
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mu<ElementType1*> �C���^�[�t�F�[�X�ł��B
		
		����Ώۂ����̃C���^�[�t�F�[�X���T�|�[�g���Ă��Ȃ��ꍇ�́A
		NULL �Ƃ��邱�Ƃ��ł��܂��B
		�A���AgetMuPtr() �ɂ��C���^�[�t�F�[�X�ŁA
		�R���e�i���̗v�f�̔�const�|�C���^���擾����ꍇ�́A
		m_pAdapteeMuPtr ���K�v�ł��B

		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
		�������Ȃ��Ă͂Ȃ�܂���B
	*/
	Mu<ElementType1*>* m_pAdapteeMuPtr ;
	///@}
private:
	// ********************************
	///@name ���
	// ********************************
	///@{

	/**
	@brief
		���ݑI������Ă���v�f�ւ́A Mu<ElementType*> 
		�C���^�[�t�F�[�X���������܂��B

	 m_pAdapteeMuPtr �ɁA�L���ȃC���^�[�t�F�[�X���ݒ肳��Ă���
	�K�v������܂��B

	*/
	class XMuConstPtr : public Mu<const ElementType1*>
	{
	public:
		// ********************************
		///@name Mu
		// ********************************
		///@{
		/**
		@return
	 		�R���e�i�Ɋi�[����Ă���f�[�^�̌���Ԃ��܂��B
		 	
	 		�I������Ă���f�[�^�̌���Ԃ��܂��B
		@attention
			 CaMuiSelect �� m_pAdapteeMuPtr�Em_pAdapteeMu �̂ǂ���ɂ�
			 �L���ȃC���^�[�t�F�[�X���ݒ肳��Ă��Ȃ�
			�ꍇ�A���̃��\�b�h�͓��삵�܂���B
		*/
		virtual int	size()const
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuConstPtr) ) ;

			int iRv = pOuter->size() ;
			return iRv ;
		} ;
		

		/**
 		  �R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
 		�v�f��Ԃ��܂��B
		 @param idx [in]
	 		�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 		�͈͂͂O�ȏ� size() �����ł��B
			INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 @return
	 		�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
		@attention
			 CaMuiSelect �� m_pAdapteeMuPtr�Em_pAdapteeMu �̂ǂ���ɂ�
			 �L���ȃC���^�[�t�F�[�X���ݒ肳��Ă��Ȃ�
			�ꍇ�A���̃��\�b�h�͓��삵�܂���B
		*/
		virtual const ElementType1* get( int idx )const 
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuConstPtr) ) ;

			if ( idx == INT_MAX )
			{
				idx = size() -1 ; 
			}

			const ElementType1* pRv = NULL ;
			int iAdapteeIndex = pOuter->indexToAdapteeIndex( idx ) ;
			if ( iAdapteeIndex >= 0 )
			{
				if ( pOuter->m_pAdapteeMuConstPtr != NULL )
				{
					pRv = pOuter->m_pAdapteeMuConstPtr->get( iAdapteeIndex ) ;
				}
				else if ( pOuter->m_pAdapteeMuPtr != NULL )
				{
					pRv = pOuter->m_pAdapteeMuPtr->get( iAdapteeIndex ) ;
				}
			}
			return ( pRv ) ;
		};
		///@}

	} ;
	friend class XMuConstPtr ;
	XMuConstPtr m_XMuConstPtr ;



	/**
	@brief
		���ݑI������Ă���v�f�ւ́A Mu<ElementType*> 
		�C���^�[�t�F�[�X���������܂��B

	 m_pAdapteeMuPtr �ɁA�L���ȃC���^�[�t�F�[�X���ݒ肳��Ă���
	�K�v������܂��B

	*/
	class XMuPtr : public Mu<ElementType1*>
	{
	public:
		// ********************************
		///@name Mu
		// ********************************
		///@{
		/**
		 @return
	 		�R���e�i�Ɋi�[����Ă���f�[�^�̌���Ԃ��܂��B
		 	
	 		�I������Ă���f�[�^�̌���Ԃ��܂��B
		@attention
			 m_pAdapteeMuPtr �ɁA�L���ȃC���^�[�t�F�[�X���ݒ肳��Ă��Ȃ�
			�ꍇ�A���̃��\�b�h�͓��삵�܂���B
		*/
		virtual int	size()const
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuPtr) ) ;
			int iRv = pOuter->size() ;
			return iRv ;
		} ;
		

		/**
 		  �R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
 		�v�f��Ԃ��܂��B
		 @param idx [in]
	 		�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 		�͈͂͂O�ȏ� size() �����ł��B
			INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 @return
	 		�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
		@attention
			 m_pAdapteeMu �ɁA�L���ȃC���^�[�t�F�[�X���ݒ肳��Ă��Ȃ�
			�ꍇ�A���̃��\�b�h�͓��삵�܂���B
		*/
		virtual ElementType1* get( int idx )const 
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuPtr) ) ;

			if ( idx == INT_MAX )
			{
				idx = size() -1 ; 
			}



			ElementType1* pRv = NULL ;
			int iAdapteeIndex = pOuter->indexToAdapteeIndex( idx ) ;
			if ( iAdapteeIndex >= 0 )
			{
				pRv = pOuter->m_pAdapteeMuPtr->get( iAdapteeIndex ) ;
			}
			return ( pRv ) ;
		};
		///@}

	} ;
	friend class XMuPtr ;
	XMuPtr m_XMuPtr ;

	///@}

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		����Ώۂ̃R���e�i m_pAdaptee �̒��ŁA�e�v�f�̑I���󋵁B
		true �� �I���Afalse �͔�I���ł��B����l�́A false �ł��B
		���̔z��̗v�f���́A m_pAdaptee->size() �Ɠ������Ȃ�܂��B
	*/
	std::vector<bool> m_contSelect ;
	///@}
private:
	#if ( CaMuiSelect_ALGORITHM >= 1 )
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
	@brief
		CaMuiSelect::indexToAdapteeIndex() �̌��ʂ�
		�L���b�V����ێ�����N���X�ł��B

	  �O���� CaMuiSelect �� m_contSelect�̓��e�EAdaptee�̗v�f����
	�ύX���ꂽ�Ƃ��́Athis �̃L���b�V���̓��e�͖����ɂȂ�܂��B
	  ���̏ꍇ�ACaMuiSelect �́A invalidate() ���Ăяo���āA
	�L���b�V���������ɂȂ������Ƃ�this �ɒm�点�Ȃ��Ă͂Ȃ�܂���B
	�@CaMuiSelect �� insert(),erase(),setSelect() ���Ăяo���ꂽ�Ƃ����A
	 ����ɊY�����܂��B
	*/
	class CAdapteeIndexCache
	{
	public:
		CAdapteeIndexCache() : m_bIsValid( false ){}
	private:
		/**
			- true: this ���L�� 
		*/
		bool m_bIsValid ;

		/**
			indexToAdapteeIndex() �̌��ʂ̃L���b�V���ł��B
			this�̃C���f�N�X��Y���AAdaptee�̃C���f�N�X��v�f�Ɏ���
			�z��ł��B
			
			this �������ȂƂ��ɁAgetAdapteeIndex() ���Ăяo������
			�X�V����܂��B
		*/
		std::vector<int> m_contAdapteeIndex ;
	private:
		/**
			this �������̏ꍇ�́A
			m_contAdapteeIndex �𐶐����A�L���ɂ��܂��B
			this ���L���ȏꍇ�́A�������܂���B
		*/
		void update()
		{
			if ( !m_bIsValid )
			{
				CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_AdapteeIndexCache) ) ;

				m_contAdapteeIndex.clear() ;
				for ( int i = 0 ; i < (int)pOuter->m_contSelect.size() ; i ++ )
				{
					if ( pOuter->m_contSelect[i] )
					{
						m_contAdapteeIndex.push_back( i ) ; 
					}
				}

				m_bIsValid = true ;
			}
		}
	public:
		/**
		@return 
			indexToAdapteeIndex() �̌��ʂ̃L���b�V���ł��B
			this�̃C���f�N�X��Y���AAdaptee�̃C���f�N�X��v�f�Ɏ���
			�z��ł��B

			this�������̏ꍇ�Am_contAdapteeIndex ���X�V���āA
			this��L���ɂ��܂��B
		*/
		const std::vector<int>& getAdapteeIndex()
		{
			update() ;
			return m_contAdapteeIndex ;
		};
		/**
			�L���b�V���𖳌��ɂ��܂��B
		*/
		void invalidate()
		{
			m_bIsValid = false ;
		};

	} ;
	friend class CAdapteeIndexCache ;
	mutable CAdapteeIndexCache m_AdapteeIndexCache ;

	///@}
	#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/



protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		m_contSelect ���Am_pAdaptee �̗v�f���ɂ��킹�ď��������܂��B
		�v�f�̑I����Ԃ́A���ׂ� ��I�� �ƂȂ�܂��B
	*/
	void initSelect()
	{
		m_contSelect.resize( (unsigned)( m_pAdapteeMu->size() ) ) ;
		fill( m_contSelect.begin() , m_contSelect.end() , false ) ;
	}

	///@}


	
 public:
	// ********************************
	///@name Mu
	// ********************************
	///@{
	/**
	 @return
	 	�R���e�i�Ɋi�[����Ă���f�[�^�̌���Ԃ��܂��B
	 	
	 	�I������Ă���f�[�^�̌���Ԃ��܂��B
	*/
	virtual int	size()const
	{
#if ( CaMuiSelect_ALGORITHM >= 1 )
		return (int)m_AdapteeIndexCache.getAdapteeIndex().size() ;
#else /*( CaMuiSelect_ALGORITHM >= 1 )*/
		int iRv = 0 ; 

		for ( int idx = 0 ; idx < (int)m_contSelect.size() ; idx ++ )
		{
			if ( m_contSelect[idx] )
			{
				iRv ++ ;
			}
		}
		return iRv ;
#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
	} ;


	

	/**
 	  �R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
 	�v�f��Ԃ��܂��B

	@param idx [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
	*/
	virtual ElementType1 get( int idx )const 
	{
		if ( idx == INT_MAX )
		{
			idx = size() -1 ; 
		}

		int iAdapteeIndex = indexToAdapteeIndex( idx ) ;
		if ( iAdapteeIndex >= 0 )
		{
			return ( m_pAdapteeMu->get( iAdapteeIndex ) ) ;
		}
		return ( *( (ElementType1*)NULL ) ) ;
	};
	///@}
public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
 	  �R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
 	�v�f��ǉ����܂��B

	@param element [in]
	 	�v�f���w�肵�Ă��������B
	@param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�

	@note
		�v�f��ǉ������ꍇ�A���̗v�f�͍ŏ�����I����ԂɂȂ�܂��B

	@note
		�v�f0(�I��v�f���P���Ȃ�)�̃R���e�i�֒ǉ����s�����ꍇ�A
		���̗v�f�́AiIndex �̎w��ɂ���āAm_pAdaptee(�I��ΏۃR���e�i)�̈ȉ��̈ʒu�ɒǉ�����܂��B
		- 0 : �v�f�́Am_pAdaptee(�I��ΏۃR���e�i)�̐擪�ɒǉ�����܂��B
		- INT_MAX : �v�f�́Am_pAdaptee(�I��ΏۃR���e�i)�̖����ɒǉ�����܂��B
	@attention
		 m_pAdapteeMui �ɁA�L���ȃC���^�[�t�F�[�X���ݒ肳��Ă��Ȃ�
		�ꍇ�A���̃��\�b�h�͓��삵�܂���B
	*/
	virtual int insert( const ElementType1& element , int iIndex = INT_MAX ) 
	{
		int iRv = 0 ; 
		int iContSize = size() ;
		// --------------------------------
		//	�p�����[�^�̌���
		// --------------------------------
		if ( iContSize == 0 && iIndex == INT_MAX )
		{
			//	�R���e�i�v�f0(�I��v�f���P���Ȃ�)�ŁA
			//	�w�肪 INT_MAX �̏ꍇ�́Am_pAdaptee(�I��ΏۃR���e�i)��
			//	�����ɒǉ�����܂��B
		}
		else
		{
			if ( iIndex == INT_MAX )
			{
				iIndex =iContSize ;
			}
			if ( !( 0 <= iIndex && iIndex <=iContSize ) )
			{
				iRv = -1 ;	//	�������s���ł��B
			}
		}
		

		// --------------------------------
		//	m_pAdaptee �ւ̑���
		//	m_contSelect �ւ̑���
		// --------------------------------
		if ( iRv >= 0 )
		{ 
			int iAdapteeIndex = -1 ;

			//	�I��v�f���S���Ȃ��R���e�i�ւ̒ǉ�
			if ( iContSize == 0 )	
			{
				if ( iIndex == INT_MAX )
				{
					//	- INT_MAX : �v�f�́Am_pAdaptee(�I��ΏۃR���e�i)�̖����ɒǉ�����܂��B
					iAdapteeIndex = m_pAdapteeMui->size() ;
				}
				else
				{
					//	- 0 : �v�f�́Am_pAdaptee(�I��ΏۃR���e�i)�̐擪�ɒǉ�����܂��B
					iAdapteeIndex = 0 ; 
				}
			}
			//	�I��v�f������R���e�i�́A�����v�f�ւ̒ǉ��́A
			//	�����̎��̈ʒu�ɒǉ����܂��B
			else if ( iIndex == iContSize )
			{
				iAdapteeIndex =indexToAdapteeIndex( iContSize - 1 ) + 1 ;
			}
			//	���̑��̈ʒu�ւ̒ǉ��́A
			//	�w��̗v�f�̒��O�ɒǉ����܂��B
			else
			{
				iAdapteeIndex = indexToAdapteeIndex( iIndex ) ;
			}

			m_pAdapteeMui->insert( element , iAdapteeIndex ) ; 
			m_contSelect.insert( m_contSelect.begin() + iAdapteeIndex , true ) ;

			#if ( CaMuiSelect_ALGORITHM >= 1 )
			//	m_contSelect�̓��e�EAdaptee�̗v�f�����ύX�����ƁA
			//	m_AdapteeIndexCache �͖����ɂȂ�܂��B
			//	insert(),erase(),setSelect() ���삪����ɂ�����܂��B
			m_AdapteeIndexCache.invalidate() ;
			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}


		return ( iRv ) ; 
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
	@attention
		 m_pAdapteeMui �ɁA�L���ȃC���^�[�t�F�[�X���ݒ肳��Ă��Ȃ�
		�ꍇ�A���̃��\�b�h�͓��삵�܂���B
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) 
	{
		int iRv = 0 ; 
		int iContSize = size() ;
		// --------------------------------
		//	�p�����[�^�̌���
		// --------------------------------
		if ( iRv >= 0 )
		{
			if ( iIndex == INT_MAX && iSize == INT_MAX )
			{
				iRv = -1 ;	//	iIndex ���s��
			}
		}
		if ( iRv >= 0 )
		{
			if ( iIndex == INT_MAX )
			{
				iIndex = iContSize- iSize ;
			}
			if ( iSize == INT_MAX )
			{
				iSize = iContSize- iIndex ;
			}
			if ( !( 0 <= iIndex && iIndex + iSize <= iContSize ) )
			{
				iRv = -1 ;	//	iIndex ���s��
			}
		}
		// --------------------------------
		//	m_pAdaptee �ւ̑���
		//	m_contSelect �ւ̑���
		// --------------------------------

		if ( iRv >= 0 )
		{ 
			for ( int i = iSize - 1  ; iRv >= 0 && i >= 0  ; i -- )
			{
				int iAdapteeIndex = indexToAdapteeIndex( iIndex+i ) ;
				m_pAdapteeMui->erase( iAdapteeIndex ) ; 
				m_contSelect.erase( m_contSelect.begin() + iAdapteeIndex ) ;
			}


			#if ( CaMuiSelect_ALGORITHM >= 1 )
			//	m_contSelect�̓��e�EAdaptee�̗v�f�����ύX�����ƁA
			//	m_AdapteeIndexCache �͖����ɂȂ�܂��B
			//	insert(),erase(),setSelect() ���삪����ɂ�����܂��B
			m_AdapteeIndexCache.invalidate() ;
			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}
		return ( iRv ) ; 
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
	@attention
		 m_pAdapteeMui �ɁA�L���ȃC���^�[�t�F�[�X���ݒ肳��Ă��Ȃ�
		�ꍇ�A���̃��\�b�h�͓��삵�܂���B
	*/
	virtual int set( const ElementType1& element , int iIndex ) 
	{
		int iRv = 0 ; 
		int iContSize = size() ;
		// --------------------------------
		//	�p�����[�^�̌���
		// --------------------------------
		if ( iRv >= 0 )
		{
			if ( iIndex == INT_MAX )
			{
				iIndex = iContSize- 1 ;
			}
			if ( !( 0 <= iIndex && iIndex < iContSize ) )
			{
				iRv = -1 ;	//	iIndex ���s��
			}
		}
		// --------------------------------
		//	m_pAdaptee �ւ̑���
		//	m_contSelect �ւ̑���
		// --------------------------------

		if ( iRv >= 0 )
		{ 
			{
				int iAdapteeIndex = indexToAdapteeIndex( iIndex ) ;
				m_pAdapteeMui->set( element , iAdapteeIndex ) ; 
			}
		}
		return ( iRv ) ; 
	}
	///@}
	
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		�f�t�H���g�R���X�g���N�^
	*/
	CaMuiSelect() : 
		m_pAdapteeMu( NULL ) , 
		m_pAdapteeMui( NULL ) , 
		m_pAdapteeMuConstPtr( NULL ) ,  
		m_pAdapteeMuPtr( NULL ) 
	{
	};

	/**
	@param pAdapteeMu [in]
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mu<ElementType1>�C���^�[�t�F�[�X�ł��B
	*/
	CaMuiSelect( Mu<ElementType1>* pAdapteeMu ) : 
		m_pAdapteeMu( pAdapteeMu ) , 
		m_pAdapteeMui( NULL ) , 
		m_pAdapteeMuConstPtr( NULL ) ,  
		m_pAdapteeMuPtr( NULL ) 
	{
		initSelect() ;
	};
	/**
	@param pAdapteeMui [in]
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mui<ElementType1>�C���^�[�t�F�[�X�ł��B
	*/
	CaMuiSelect( Mui<ElementType1>* pAdapteeMui ) : 
		m_pAdapteeMu( pAdapteeMui ) ,
		m_pAdapteeMui( pAdapteeMui ) ,
		m_pAdapteeMuConstPtr( NULL ) ,  
		m_pAdapteeMuPtr( NULL ) 
	{
		initSelect() ;
	};
	/**
	@param pAdapteeMu [in]
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mu<ElementType1>�C���^�[�t�F�[�X�ł��B
	@param pAdapteeMuConstPtr [in]
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		const Mu<const ElementType1*>* �C���^�[�t�F�[�X�ł��B
		
	*/
	CaMuiSelect( Mu<ElementType1>* pAdapteeMu , 
		const Mu<const ElementType1*>* pAdapteeMuConstPtr ) : 
		m_pAdapteeMu( pAdapteeMu ) ,
		m_pAdapteeMui( NULL ) , 
		m_pAdapteeMuConstPtr( pAdapteeMuConstPtr ) 
		m_pAdapteeMuPtr( NULL ) 
	{
		initSelect() ;
	};
	/**
	@param pAdapteeMui [in]
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mui<ElementType1>�C���^�[�t�F�[�X�ł��B
	@param pAdapteeMuPtr [in]
		����ΏۃI�u�W�F�N�g�ƂȂ�R���e�i(Adaptee)�́A 
		Mu<ElementType1*>* �C���^�[�t�F�[�X�ł��B
		
	*/
	CaMuiSelect( Mui<ElementType1>* pAdapteeMui , 
		Mu<ElementType1*>* pAdapteeMuPtr ) : 
		m_pAdapteeMu( pAdapteeMui ) ,
		m_pAdapteeMui( pAdapteeMui ) , 
		m_pAdapteeMuConstPtr( NULL ) ,
		m_pAdapteeMuPtr( pAdapteeMuPtr ) 
	{
		initSelect() ;
	};
	
private:
	//	�R�s�[�͋֎~
	CaMuiSelect( const CaMuiSelect& value )
	{
		assert( false ) ;
	}
	CaMuiSelect& operator=( const CaMuiSelect& value )
	{
		assert( false ) ;
		return *this ;
	}
public:
	// ********************************
	///@name CaMuiSelect-�֘A
	// ********************************
	///@{
	Mu<ElementType1>*	getAdapteeMu(){	return m_pAdapteeMu ;};
	const Mu<ElementType1>*	getAdapteeMu()const{	return m_pAdapteeMu ;};
	Mui<ElementType1>*	getAdapteeMui(){	return m_pAdapteeMui ;};
	const Mui<ElementType1>*	getAdapteeMui()const{	return m_pAdapteeMui ;};

	const Mu<const ElementType1*>*	getAdapteeMuConstPtr()const{	return m_pAdapteeMuConstPtr ;};
	Mu<ElementType1*>*	getAdapteeMuPtr()const{	return m_pAdapteeMuPtr ;};
	
	/**
	����Ώۂ̃R���e�i��ύX���܂��B
	���̂Ƃ��A���ׂĂ̗v�f�͔�I���ƂȂ�܂��B
	*/
	CaMuiSelect<ElementType1>& setAdaptee( Mu<ElementType1>* pAdapteeMu ) 
	{
		m_pAdapteeMu =  pAdapteeMu ; 
		m_pAdapteeMui =  NULL ;
		m_pAdapteeMuConstPtr = NULL ;  
		m_pAdapteeMuPtr = NULL ;

		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/

		initSelect() ;
		return *this ;
	};


	/**
	����Ώۂ̃R���e�i��ύX���܂��B
	���̂Ƃ��A���ׂĂ̗v�f�͔�I���ƂȂ�܂��B
	*/
	CaMuiSelect<ElementType1>& setAdaptee( Mui<ElementType1>* pAdapteeMui ) 
	{
		m_pAdapteeMu =  pAdapteeMui ;
		m_pAdapteeMui =  pAdapteeMui ;
		m_pAdapteeMuConstPtr = NULL ;  
		m_pAdapteeMuPtr =  NULL ;
		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		initSelect() ;
		return *this ;
	};

	/**
	����Ώۂ̃R���e�i��ύX���܂��B
	���̂Ƃ��A���ׂĂ̗v�f�͔�I���ƂȂ�܂��B
	*/
	CaMuiSelect<ElementType1>& setAdaptee( 
			Mu<ElementType1>* pAdapteeMu , 
			const Mu<const ElementType1*>* pAdapteeMuConstPtr ) 
	{
		m_pAdapteeMu = pAdapteeMu ;
		m_pAdapteeMui =  NULL ; 
		m_pAdapteeMuConstPtr = pAdapteeMuConstPtr ; 
		m_pAdapteeMuPtr = NULL ;
		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		initSelect() ;
		return *this ;
	};
	/**
	����Ώۂ̃R���e�i��ύX���܂��B
	���̂Ƃ��A���ׂĂ̗v�f�͔�I���ƂȂ�܂��B
	*/
	CaMuiSelect<ElementType1>& setAdaptee(  
		Mui<ElementType1>* pAdapteeMui , 
		Mu<ElementType1*>* pAdapteeMuPtr ) 
	{
		m_pAdapteeMu = pAdapteeMui ;
		m_pAdapteeMui = pAdapteeMui ; 
		m_pAdapteeMuConstPtr =  NULL ;
		m_pAdapteeMuPtr = pAdapteeMuPtr ; 
		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		initSelect() ;
		return *this ;
	};

	///@}
	// ********************************
	///@name CaMuiSelect-���
	// ********************************
	///@{
	/**
	@return
		���ݑI������Ă���v�f�ւ́A Mu<const ElementType*> 
		�C���^�[�t�F�[�X��Ԃ��܂��B
		�A���A m_pAdapteeMuConstPtr �ɁA�L���ȃC���^�[�t�F�[�X���ݒ�
		����Ă���K�v������܂��B
	@attention
		 m_pAdapteeMuPtr�Em_pAdapteeMuConstPtr �̂����ꂩ�ɁA
		 �L���ȃC���^�[�t�F�[�X���ݒ肳��Ă���K�v������܂��B
	*/
	const Mu<const ElementType1*>* getMuPtr()const 
	{
		if ( m_pAdapteeMuPtr == NULL && m_pAdapteeMuConstPtr == NULL )
		{
			return NULL ;
		}
		return &m_XMuConstPtr ;
	}
	
	/**
	@return
		���ݑI������Ă���v�f�ւ́A Mu<ElementType*> 
		�C���^�[�t�F�[�X��Ԃ��܂��B
		�A���A m_pAdapteeMuPtr �ɁA�L���ȃC���^�[�t�F�[�X���ݒ�
		����Ă���K�v������܂��B
	@attention
		 m_pAdapteeMu �ɁA
		 �L���ȃC���^�[�t�F�[�X���ݒ肳��Ă���K�v������܂��B
	*/
	Mu<ElementType1*>* getMuPtr() 
	{
		if ( m_pAdapteeMuPtr == NULL )
		{
			return NULL ;
		}
		return &m_XMuPtr ;
	}
	
	///@}
	// ********************************
	///@name CaMuiSelect-����
	// ********************************
	///@{
	/**
	  �v�f�̑I����Ԃ��擾���܂��B
	@param idx [in]
		0����n�܂�C���f�N�X�ԍ����w�肵�Ă��������B
	@return
		true �� �I���Afalse �͔�I���ł��B
	*/
	virtual bool getSelect( int idx )const
	{
		bool bRv = false ;
		if ( 0 <= idx && idx < (int)m_contSelect.size() )
		{
			bRv = m_contSelect[idx] ;
		}
		return bRv ;
	}
	/**
	  �v�f�̑I����Ԃ�ݒ肵�܂��B
	@param idx
		0����n�܂�C���f�N�X�ԍ����w�肵�Ă��������B
	@param bSelect
		true �� �I���Afalse �͔�I���ł��B
	*/
	virtual CaMuiSelect<ElementType1>& setSelect( int idx , bool bSelect )
	{
		if ( 0 <= idx && idx < (int)m_contSelect.size() )
		{
			 m_contSelect[idx] = bSelect;

			#if ( CaMuiSelect_ALGORITHM >= 1 )

				//	m_contSelect�̓��e�EAdaptee�̗v�f�����ύX�����ƁA
				//	m_contAdapteeIndex �̓��e�͖����ɂȂ�܂��B
				//	���̏ꍇ�́A�L���b�V���𖾎��I�ɖ����ɂ���K�v������܂��B
				//	insert(),erase(),setSelect() ���삪����ɂ�����܂��B
				m_AdapteeIndexCache.invalidate() ; 

			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}

		return *this ;
	}

	/**
	  ���ׂĂ̗v�f�̑I����Ԃ�ݒ肵�܂��B
	@param bSelect
		true �� �I���Afalse �͔�I���ł��B
	*/
	virtual CaMuiSelect<ElementType1>& setSelectAll( bool bSelect )
	{
		for ( int idx = 0 ; idx < (int)m_contSelect.size() ; idx ++ )
		{
			 m_contSelect[idx] = bSelect;

			#if ( CaMuiSelect_ALGORITHM >= 1 )

				//	m_contSelect�̓��e�EAdaptee�̗v�f�����ύX�����ƁA
				//	m_contAdapteeIndex �̓��e�͖����ɂȂ�܂��B
				//	���̏ꍇ�́A�L���b�V���𖾎��I�ɖ����ɂ���K�v������܂��B
				//	insert(),erase(),setSelect() ���삪����ɂ�����܂��B
				m_AdapteeIndexCache.invalidate() ; 

			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}

		return *this ;
	}


	///@}


	// ********************************
	///@name CaMuiSelect-����
	// ********************************
	///@{
	/**
	  this �̃C���f�N�X�ɑΉ�����v�f�́Am_pAdapteeMu ���ł̃C���f�N�X��
	�Ԃ��܂��B
	@param iThisIndex
		this ��ł̃C���f�N�X���w�肵�Ă��������B
	@return 
		m_Adaptee ���ł̃C���f�N�X��Ԃ��܂��B
		�Ή�����v�f���Ȃ��ꍇ�́A-1 �ł��B

		m_Adaptee ��   { "zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" } @n
		m_contSelect ��{ true  , false , false , false    , true   , false  , true  , false }  @n
		�̏ꍇ�A  indexToAdapteeIndex(0)=0,indexToAdapteeIndex(1)=4,indexToAdapteeIndex(2)=6 �ƂȂ�܂��B

		
	*/
	int indexToAdapteeIndex( int iThisIndex )const 
	{
#if ( CaMuiSelect_ALGORITHM >= 1 )
		int iRv = -1 ;
		const std::vector<int>& contAdapteeIndex = m_AdapteeIndexCache.getAdapteeIndex() ;
		if ( 0 <= iThisIndex && iThisIndex < (int)contAdapteeIndex.size() )
		{
			iRv = contAdapteeIndex[iThisIndex] ;
		}
		return iRv ;
#else /*( CaMuiSelect_ALGORITHM >= 1 )*/
		int iRv = -1;
		int iSelectedCount = 0 ; 
		if ( 0 <= iThisIndex )
		{
			for ( int iAdapteeIndex = 0 ; iRv == -1 && iAdapteeIndex < (int)m_contSelect.size() ; iAdapteeIndex ++ )
			{
				if ( m_contSelect[iAdapteeIndex] )
				{
					iSelectedCount ++ ;
				}
				if ( iSelectedCount > iThisIndex )
				{
					iRv = iAdapteeIndex ;
				}
			}
		}
		return iRv ;
#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
	}
	/**
	  m_Adaptee ���̃C���f�N�X���A�ɑΉ�����v�f�́A
	this �̃C���f�N�X��Ԃ��܂��B
	@param iAdapteeIndex
		this ��ł̃C���f�N�X���w�肵�Ă��������B
	@return 
		m_Adaptee ���ł̃C���f�N�X��Ԃ��܂��B
		�Ή�����v�f���Ȃ��ꍇ�́A-1 �ł��B

		m_Adaptee ��   { "zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" } @n
		m_contSelect ��{ true  , false , false , false    , true   , false  , true  , false }  @n
		�̏ꍇ�A  indexFromAdapteeIndex(0)=0,indexFromAdapteeIndex(4)=2 ,indexFromAdapteeIndex(6)=3 �ƂȂ�܂��B
		���̑��̈����ŌĂяo���ꂽ�ꍇ�́A�߂�l�� -1 �ƂȂ�܂��B
	*/
	int indexFromAdapteeIndex( int iAdapteeIndex )const 
	{
#if ( CaMuiSelect_ALGORITHM >= 1 )
		int iRv = -1 ;
		const std::vector<int>& contAdapteeIndex = m_AdapteeIndexCache.getAdapteeIndex() ;
		if ( 0 <= iAdapteeIndex && iAdapteeIndex < (int)m_contSelect.size() && m_contSelect[iAdapteeIndex] )
		{

			//for ( int iThisIndex = 0 ; iRv == -1 && iThisIndex < (int)contAdapteeIndex.size() ; iThisIndex ++ )
			//{
			//	if ( contAdapteeIndex[iThisIndex] == iAdapteeIndex )
			//	{
			//		iRv = iThisIndex ;
			//	}
			//}

			std::vector<int>::const_iterator ite = std::lower_bound( 
				contAdapteeIndex.begin() , 
				contAdapteeIndex.end() ,
				iAdapteeIndex ) ;
			iRv = std::distance( contAdapteeIndex.begin() , ite ) ;

		}
		return iRv ;
#else /*( CaMuiSelect_ALGORITHM >= 1 )*/
		int iRv = -1 ;
		int iSelectedCount = 0 ; 
		if ( 0 <= iAdapteeIndex && iAdapteeIndex < (int)m_contSelect.size() && m_contSelect[iAdapteeIndex] )
		{
			int idx = 0 ;
			for (  idx = 0 ; idx < (int)m_contSelect.size() && idx < iAdapteeIndex ; idx ++ )
			{
				if ( m_contSelect[idx] )
				{
					iSelectedCount ++ ;
				}
			}
			//iSelectedCount = iAdapteeIndex �ȑO�ŁAtrue �̐��B

			iRv = iSelectedCount ;
		}
		return iRv ;
#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
	}
	///@}
};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib

#endif /*Mu_CaMuiSelect_h*/


