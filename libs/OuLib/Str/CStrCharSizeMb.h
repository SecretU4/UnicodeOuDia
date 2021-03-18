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
//	CStrCharSizeMb.h
// ****************************************************************
*/

/** @file CStrCharSizeMb.h */

#ifndef  CStrCharSizeMb_h
#define  CStrCharSizeMb_h
#include <string>
#include <vector>

namespace OuLib{
namespace Str{

// ****************************************************************
//	CStrCharSizeMb
// ****************************************************************
/**
 *	@brief 
 *	 �y�T�v�z
 *		�^����ꂽ�}���`�o�C�g������̊e���������o�C�g�ł��邩�𒲂ׁA
 *		�e�[�u���ɕێ����܂��B
 *		���̃e�[�u�����g���A�o�C�g�P�ʂ̃C���f�N�X�ƕ����P�ʂ̃C���f�N�X��
 *		�ϊ��E�w��̕����̃o�C�g���̒����Ȃǂ̃T�[�r�X��񋟂��܂��B
 *	
 *	�P�D	�o�C�g�P�ʂ̃C���f�N�X(string �� char* ��[]�̓Y��)��
 *		�����P�ʂ̃C���f�N�X�i2�o�C�g�������P�o�C�g�������P�����Ɛ������Ƃ����
 *		�擪���牽�����ڂɂȂ邩�j�̑��ݕϊ�
 *
 *	�Q�D  �w��̃C���f�N�X�i�o�C�g�P�ʃC���f�N�X�E�����P�ʃC���f�N�X������
 *		�T�|�[�g�j�̕����͉��o�C�g�������𒲂ׂ�
 *
 *	�R�D  �o�C�g�P�ʃC���f�N�X���A���̕����ɐi�߂�i�P�o�C�g�����Ȃ�{�P�A�Q
 *		�o�C�g�����Ȃ�{�Q�j�B
 *		����ɂ��A��������̕������T�[�`���郋�[�v�������ł��܂��B
 *
 *	  ���̃N���X�ł́A�����o�֐����ȂǂɁA�ȉ��̗�����g�p���Ă��܂��B
 *	
 *	-	Bidx...  ��������̕����́A�擪����̃o�C�g�P�ʂ̃C���f�N�X�i�O�N�_�j�B
 *		    �i��F"���sa�s" �� "�s" �� 5 �ƂȂ�܂��B�j
 *	-	Cidx...  ��������̕����́A�擪����̕����P�ʂ̃C���f�N�X�i�O�N�_�j�B
 *			2�o�C�g�������P�o�C�g�������P�����Ɛ����܂�
 *		    �i��F"���sa�s" �� "�s" �� 3 �ƂȂ�܂��B�j
 *	-	Csize...  ��������̕����́A�o�C�g���B
 *		    �i��F"���sa�s" �� "�s" �� 2 �ƂȂ�܂��B�j
 *	
 *	
 *	�y�g�����z
 *	
 *	�P�D  �R���X�g���N�^�� scan() �ŁA��������w�肵�Ă��������B
 *		this �́A���̕�����̊e�����̃o�C�g������͂��A�e�[�u�����쐬���܂��B
 *		����Ȍ�A���̃e�[�u���͎��� scan() �܂ŗL���ł��B
 *	
 *	�Q�D  ���Ƃ́A���ׂẴ����o�֐����g�p�\�ł��B
 *
 * @b �����P�ʂŕ\�����s����
 * @code
 	string	aStr( "���sa�s" ) ; 
	CStrCharSizeMb	aStrCharSize( aStr ) ;
 	{
 		for ( int idx = 0 ; idx < aStrCharSize.ByteLength() ; ){
 			cout << aStr.substr( idx , aStrCharSize.CsizeOfBidx( idx ) ) << " " ;
 			idx = aStrCharSize.BidxNextChar( idx ) ;
 		}
 		cout << endl ;
	}
 @endcode
*/
class CStrCharSizeMb
{
// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	 * @brief ������̊e�����̃o�C�g���ɂ��Ƃ������e�[�u���ł�
	 *
	 *	�R���X�g���N�^�E�܂��͍ŋ߂� scan() �Ŏw�肳�ꂽ������̊e������
	 *	Bidx ��ێ����܂��B
	 *	�z��̗v�f���́A�i������̕������i�Q�o�C�g�������P�Ɛ����āj�{�P�j
	 *	�ƂȂ�A�����ɂ́A '\0' �� Bidx �����܂��B
	 *	������Ԃ� [0] �� 0 �������ݒ肳�ꂽ��Ԃł��B
	 *
	 *	��F"���sa�s" �� scan() �ɓn���ƁA�z���	
	 *	-	[0]=0	//	��	
	 *	-	[1]=2	//	�s	
	 *	-	[2]=4	//	a	
	 *	-	[3]=5	//	�s
	 *	-	[4]=7	//	"\0"
	 *
	 *	�ƂȂ�܂��B
	 */
	std::vector<int>	m_ariBidx ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 */
	CStrCharSizeMb() ;
	
	/**
	 * @param ev [in]
	 *	���̕������ scan() �ɓn���A�e�[�u�����\�����܂��B
	 */
	CStrCharSizeMb( const std::string& ev ) ;
	
// ********************************
//	CStrCharSizeMb
// ********************************
 public:
	/**
	 * @param ev [in]
	 *	���̕�������X�L�������āA�e�[�u�����\�����܂��B
	 *	����܂ł̃e�[�u���̓��e�͔j�����܂��B
	 */
	CStrCharSizeMb& scan( const std::string& ev ) ;
	
	/**
	 * @return
	 * 	�X�L��������������́A�o�C�g�P�ʂł̒�����Ԃ��܂��B
	 * 	    �i��F"���sa�s" �Ȃ� 7 �ƂȂ�܂��B�j
	 */
	int ByteLength()const ;
	
	/**
	 * @return
	 * 	�X�L��������������́A�����P�ʂł̒�����Ԃ��܂��B
	 * 	    �i��F"���sa�s" �Ȃ� 4 �ƂȂ�܂��B�j
	 */
	int CharLength()const ;
	
	/**
	 * 	�o�C�g�P�ʂ̃C���f�N�X���當���P�ʂ̃C���f�N�X�ɕϊ����܂�
	 * @param iBidx [in]
	 * 	�o�C�g�P�ʂ̃C���f�N�X���w�肵�Ă��������B
	 * @param piOffset [out]
	 * 	���̊֐��́AiBidx �́A�����̐擪����̃I�t�Z�b�g���������݂܂��B
	 *	���̒l��0�ł���΁AiBidx �͕����̐擪�o�C�g���w���C���f�N�X�ł��B
	 *	1�Ȃ�A iBidx �͕�����2�o�C�g�ڂ��w���Ă��邱�Ƃ��Ӗ����܂��B
	 *	�s�v�ł���΁ANULL���w�肵�Ă����܂��܂���B
	 * @return
	 * 	�����P�ʂ̃C���f�N�X��Ԃ��܂��B
	 * 	- iBidx �����̐�	: -1��Ԃ��܂��B
	 *		���̏ꍇ�A*piOffset��0�ł��B
	 * 	- iBidx �� ByteLength() �ȏ� : CharLength() ��Ԃ��܂��B
	 *		���̏ꍇ�A*piOffset��0�ł��B
	 * 	- iBidx ��������1�o�C�g�ڈȊO���w���Ă���ꍇ�ł��A���̕�����
	 *		�����P�ʂ̃C���f�N�X��Ԃ��܂��B
	 *	
	 * 	�i��F"���sa�s" )
	 *	iBidx �� 5('�s') ���w�肷��ƁA�߂�l�� 3 �E*piOffset��0�ƂȂ�܂��B
	 * 	6('�s'�̂Q�o�C�g��)���w�肷��ƁA�߂�l�� 3 �E*piOffset��1�ƂȂ�܂��B
	 */
	int CidxOfBidx( int iBidx , int* piOffset = NULL )const ;
	
	/**
	 * 	�����P�ʂ̃C���f�N�X����o�C�g�P�ʂ̃C���f�N�X�ɕϊ����܂�
	 * @param iCidx [in]
	 * 	�����P�ʂ̃C���f�N�X���w�肵�Ă��������B
	 * @return 
	 * 	�o�C�g�P�ʂ̃C���f�N�X��Ԃ��܂��B
	 * 	    �i��F"���sa�s" �Ȃ� iCidx �� 3('�s') ���w�肷��ƁA�߂�l�� 5 ��
	 * 		�Ȃ�܂��B�j
	 * 	- iCidx �����̐�	: -1��Ԃ��܂��B
	 * 	- iCidx �� CharLength() �ȏ� : ByteLength() ��Ԃ��܂��B
	 */
	int BidxOfCidx( int iCidx )const ;
	
	/**
	 * 	�o�C�g�P�ʂ̃C���f�N�X�Ŏw�肳�ꂽ�����̃o�C�g���𒲂ׂ܂��B
	 * @param iBidx [in]
	 * 	�o�C�g�P�ʂ̃C���f�N�X���w�肵�Ă��������B
	 * @return
	 * 	�����̃o�C�g����Ԃ��܂��B
	 * 	    �i��F"���sa�s" �Ȃ� iBidx �� 5('�s') ���w�肷��ƁA�߂�l�� 2 ��
	 * 		�Ȃ�܂��B6���w�肷���0��Ԃ��܂��B�j
	 * 	- iBidx �����̐�/�����̂Q�o�C�g��/ByteLength() �ȏ� : 0��Ԃ��܂��B
	 */
	int CsizeOfBidx( int iBidx )const ;
	
	/**
	 * 	�����P�ʂ̃C���f�N�X�Ŏw�肳�ꂽ�����̃o�C�g���𒲂ׂ܂��B
	 * @param iCidx [in]
	 * 	�����P�ʂ̃C���f�N�X���w�肵�Ă��������B
	 * @return
	 * 	�����̃o�C�g����Ԃ��܂��B
	 * 	    �i��F"���sa�s" �Ȃ� iCidx �� 3('�s') ���w�肷��ƁA�߂�l�� 2 ��
	 * 		�Ȃ�܂��B�j
	 * 	- iCidx �����̐�/CharLength() �ȏ� : 0��Ԃ��܂��B
	 */
	int CsizeOfCidx( int iCidx )const ;
	
	/**
	 * 	�o�C�g�P�ʂ̃C���f�N�X�Ŏw�肳�ꂽ�����̂P�������̕����́A
	 * 	�o�C�g�P�ʃC���f�N�X�𒲂ׂ܂��B
	 * 	�����̎w��ɂ��A�Q�����ȏ���E���邢�͑O�̕����̃C���f�N�X��
	 * 	���߂邱�Ƃ��ł��܂��B
	 * @param iBidx [in]
	 * 	�o�C�g�P�ʂ̃C���f�N�X���w�肵�Ă��������B
	 * @param iCharOffset [in]
	 * 	�����P�ʂł̃I�t�Z�b�g���w�肵�Ă��������B
	 * 	+1 �Ȃ�AiBidx �� 1�������A -1 �Ȃ�P�����O���w�肵�����Ƃ�
	 * 	�Ȃ�܂��B
	 * @return
	 * 	iCharOffset ���������ړ�������̕����́A
	 * 	�o�C�g�P�ʂ̃C���f�N�X��Ԃ��܂��B
	 * 	    �i��F"���sa�s" �Ȃ� iBidx �� 2('�s') ,iCharOffset �� 1 ��
	 * 		�w�肷��ƁA�߂�l�� 4 'a' �ƂȂ�܂��B�j
	 * 	- �ړ��悪�擪�������O�ɂȂ�: -1��Ԃ��܂��B
	 * 	- �ړ��悪�����񖖔��ɒB���� : ByteLength() ��Ԃ��܂��B
	 */
	int BidxNextChar( int iBidx , int iCharOffset = 1 )const ;

	/**
	 * 	�Ō�̕����́A�����P�ʂ̃C���f�N�X��Ԃ��܂��B
	 * @return
	 * 	�����P�ʂ̃C���f�N�X��Ԃ��܂��B
	 * 	    �i��F"���sa�s" �Ȃ�  3 �ƂȂ�܂��B�j
	 * 	�󕶎���̏ꍇ��-1��Ԃ��܂��B
	 */
	int CidxLast()const ;
	
	/**
	 * 	�Ō�̕����́A�o�C�g�P�ʂ̃C���f�N�X��Ԃ��܂��B
	 * @return
	 * 	�o�C�g�P�ʂ̃C���f�N�X��Ԃ��܂�
	 * 	    �i��F"���sa�s" �Ȃ�  5 �ƂȂ�܂��B�j�B
	 * 	�󕶎���̏ꍇ��-1��Ԃ��܂��B
	 */
	int BidxLast()const ;

	/**
	 * 	���p�����E�S�p���������݂���������̂Ȃ���
	 *	�S�p�������A���p�����ɕϊ����܂��B
	 * @param strEv [in]
	 *  �ϊ���������
	 * @param piResult [out]
	 *	���̊֐��́A���������� 0 �ȏ�A�G���[�Ȃ畉�̐����������݂܂��B
	 *	�s�v�Ȃ� NULL �ł����܂��܂���B
	 *  - 1 ;	//	�ϊ��ɐ������܂����B
	 *  - 0 ;	//	�ϊ��̕K�v�ȑS�p�����́A�ЂƂ�����܂���ł����B
	 *	- -1 ;	//	���p�ɕϊ��ł��Ȃ��S�p����������܂����B
	 *
	 * @return
	 * 	�ϊ���̕�����
	 *
	 * @attention  
	 *	���̊֐��́A�ϊ���������ɁA���p�����ɕϊ��s�\�ȑS�p������
	 *	�܂܂�Ă����ꍇ( *piResult == -1 �̏ꍇ)�A
	 *	�����񒆂̕ϊ��\�ȑS�p���������ׂĕϊ����A�ϊ��s�\�ȑS�p������
	 *	���̂܂܎c�����������Ԃ��܂��B
	 * @attention  
	 *	���_���̃J�^�J�i�́A���p�J�^�J�i�{���p���_�̑g�ݍ��킹�Ƃ��܂��B
	 *	(��) 
	 *	"�K" �� "��" �ƂȂ�܂��B
	 */
	static std::string strToSingleByte( const std::string& strEv , 
						int* piResult = NULL ) ;

	/**
	 * 	���p�����E�S�p���������݂����������
	 *	���p�������A�S�p�����ɕϊ����܂��B
	 * @param strEv [in]
	 *  �ϊ���������
	 * @param piResult [out]
	 *	���̊֐��́A���������� 0 �ȏ�A�G���[�Ȃ畉�̐����������݂܂��B
	 *	�s�v�Ȃ� NULL �ł����܂��܂���B
	 *  - 1 ;	//	�ϊ��ɐ������܂����B
	 *  - 0 ;	//	�ϊ��̕K�v�ȑS�p�����́A�ЂƂ�����܂���ł����B
	 *	- -1 ;	//	�S�p�ɕϊ��ł��Ȃ����p����������܂����B
	 *
	 * @return
	 * 	�ϊ���̕�����
	 *
	 * @attention  
	 *	���̊֐��́A�ϊ���������ɁA�S�p�ɕϊ��s�\�Ȕ��p������
	 *	�܂܂�Ă����ꍇ( *piResult == -1 �̏ꍇ)�A
	 *	�����񒆂̕ϊ��\�Ȕ��p���������ׂĕϊ����A�ϊ��s�\�Ȕ��p������
	 *	���̂܂܎c�����������Ԃ��܂��B
	 * @attention  
	 *	���p�J�^�J�i�{���p���_�̑g�ݍ��킹�́A�P�̑S�p�����Ƃ��܂��B\n
	 *	(��) 
	 *	"��" �� "�K" �ƂȂ�܂�( "�J�J" ) �ɂ͂Ȃ�܂���B
	 */
	static std::string strToDoubleByte( const std::string& strEv , 
						int* piResult = NULL ) ;


};

} //namespace Str{
} //namespace OuLib{



#endif /*CStrCharSizeMb_h*/
