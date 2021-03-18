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
//	dir\Directries.h
// ****************************************************************
*/
/** @file
* @brief
* �y�T�v�z
*	  �f�B���N�g�����̃t�@�C����f�B���N�g���̈ꗗ���擾����֐���
*	���^���Ă��܂��B
*/
#ifndef  Directries_h
#define  Directries_h
#include <string>
#include <deque>

namespace OuLib{
namespace Dir{


// ****************************************************************
//	IfDirCallback
// ****************************************************************
/**
 * @brief
 *	findDir() �E findFile() �֐��ɓo�^����R�[���o�b�N�C���^�[�t�F�[�X�ł��B
 */
class IfDirCallback
{
 public:
	/**
		���������t�@�C�����E�f�B���N�g�������A�ďo���ɒʒm���܂��B
	 @param strName [in]
		���������t�@�C�����E�f�B���N�g����
	 */
	virtual void OnNameFound( const std::string& strName ) = 0 ;
};



// ****************************************************************
///@name �t�@�C��/�f�B���N�g������
// ****************************************************************
///@{
/**
 	����������ɍ��v����f�B���N�g�������������܂��B

	�ʏ�̃f�B���N�g�������ɂ� Dirnames() ���g�p�ł��܂��B

 	�f�B���N�g�����̎w��ɂ́A*��?�̃��C���h�J�[�h��
 	�g�p���邱�Ƃ��ł��܂��B
 	���C���h�J�[�h�́A������������̍ŉ��ʂ�
 	�f�B���N�g�����ɂ����A�g�p�\�ł�
 		�i��F"c:\windows\*" "c:\windows\???" "c:\user\s*" �j 
	
	���̊֐��́A�f�B���N�g�����݂��閈�ɁA�o�^���ꂽ IfDirCallback 
	�C���^�[�t�F�[�X�̊֐� IfDirCallback::OnNameFound() ���Ăяo���܂��B
 @param strSearch [in]
 	�@������������w�肵�Ă��������B
 @param bSubdirectrySearch [in]
 	�@�^�Ȃ�A�T�u�f�B���N�g���������ΏۂɊ܂߂܂��B
 @param pIfDirCallback [in]
	  ���̊֐��́A�f�B���N�g���������邲�ƂɁA
	 pIfDirCallback->OnNameFound() �ŁA�����������O��ʒm���܂��B
	 NULL �͎w��ł��܂���B
 @return
 	  ����������A�O�ȏ�i�����������O�̐��j�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�p�����[�^���s���ł�\n
			strSearch �̖����� "."  , ".." ���w�肷�邱�Ƃ͂ł��܂���B
 @attention
 	 strSearch �̖����� "." ( �J�����g�f�B���N�g�� ) , ".." (�e�f�B���N�g��) ��
	�w�肷�邱�Ƃ͂ł��܂���B���̏ꍇ�́A -1 ��Ԃ��܂��B
	  �J�����g�f�B���N�g���̐e�f�B���N�g���̃T�u�f�B���N�g�����w�肷��ꍇ�́A"..\*"
	���w�肵�Ă��������B
 */
int findDir( const std::string& strSearch , 
						bool bSubdirectrySearch , 
						IfDirCallback* pIfDirCallback ) ;

/**
 	����������ɍ��v����t�@�C�������������܂��B

	�ʏ�̃f�B���N�g�������ɂ� Filenames() ���g�p�ł��܂��B

 	�t�@�C�����̎w��ɂ́A*��?�̃��C���h�J�[�h��
 	�g�p���邱�Ƃ��ł��܂��B
 	���C���h�J�[�h�́A������������̍ŉ��ʂ�
 	�t�@�C�����ɂ����A�g�p�\�ł�
 		�i��F"c:\windows\*" "c:\windows\???" "c:\user\s*" �j 
	
	���̊֐��́A�t�@�C�����݂��閈�ɁA�o�^���ꂽ IfDirCallback 
	�C���^�[�t�F�[�X�̊֐� IfDirCallback::OnNameFound() ���Ăяo���܂��B
	���������B* @param strSearch [in]
 	�@������������w�肵�Ă��������B
 @param bSubdirectrySearch [in]
 	�@�^�Ȃ�A�T�u�f�B���N�g���������ΏۂɊ܂߂܂��B
 @param pIfDirCallback [in]
	  ���̊֐��́A�t�@�C���������邲�ƂɁA
	 pIfDirCallback->OnNameFound() �ŁA�����������O��ʒm���܂��B
	 NULL �͎w��ł��܂���B
 @return
 	  ����������A�O�ȏ�i�����������O�̐��j�A�G���[�Ȃ�s�̐��ł��B
 */
int  findFile( const std::string& strSearch , 
						bool bSubdirectrySearch ,
						IfDirCallback* pIfDirCallback ) ;

///@}
// ****************************************************************
///@name �f�B���N�g���쐬
// ****************************************************************
///@{
/**
	�T�u�f�B���N�g�����쐬���܂��B
	�����i�̃T�u�f�B���N�g������x�ɍ쐬���邱�Ƃ��ł��܂��B
@param strDir [in]
	�f�B���N�g�����w�肵�Ă��������B
	������ "\" �́A�����Ă��Ȃ��Ă����܂��܂���B
@return
	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	-	1 ;	//	�f�B���N�g���̍쐬�ɐ������܂����B
	-	0 ;	//	�f�B���N�g���͊��ɑ��݂��Ă��܂����B
	-	-1 ;	//	�f�B���N�g���̍쐬�Ɏ��s���܂����B
*/
int mkdirs( const std::string& strDir ) ;

/** 
	�w�肳�ꂽ�f�B���N�g������ł���΁A���̃f�B���N�g�����폜���܂��B 
	�w�肳�ꂽ�f�B���N�g���̃T�u�f�B���N�g�����̋�̃f�B���N�g�������ׂ� 
	�폜���܂��B 

	�������w�肵�Ȃ��ꍇ�́A�J�����g�f�B���N�g�����w�肵�����̂Ƃ݂Ȃ��܂��B 

@param strDir [in] 
	�폜����f�B���N�g�����w�肵�Ă��������B
@param pErrorStream [in]
@return 
	-	0 ;	//	�f�B���N�g���͍폜�ł��܂����B 
	-	-1 ;	//	strDir�̍폜�Ɏ��s���܂����B 
	-	-2 ;	//	���̃f�B���N�g���ɂ̓t�@�C��������܂��B 
	-	-3 ;	//	�T�u�f�B���N�g���̍폜�Ɏ��s���܂����B 
*/ 
int rmempdir( const std::string& strDir , FILE* pErrorStream ) ;

///@}
// ****************************************************************
//	CDirCallback_StrContainer< class StrContainerType >
// ****************************************************************
/**
 @brief
	findDir() �E findFile() �֐��Ō��������t�@�C�����A
	STL�R���e�i�ɒǉ�����R�[���o�b�N�N���X�ł��B

�y�g�����z

  Dirnames() , Filenames() �֐����Q�l�ɂ��Ă��������B

 @param StrContainerType
	std::string ���i�[����STL�R���e�i���w�肵�Ă��������B@n
	(��) std::deque< std::string > std::vector< std::string >
*/
template< class StrContainerType >
class CDirCallback_StrContainer : public IfDirCallback
{
 private:
	// ********************************
	/// @name �֘A	
	// ********************************
	///@{
	/**
		findDir() �E findFile() �֐��Ō��������t�@�C�����A
		�ǉ�����STL�R���e�i�B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��͕�炷���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă�
		�Ȃ�܂���B
	 */
	StrContainerType*	m_pStrContainerType ;
	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	 @param pStrContainerType [in]
		findDir() �E findFile() �֐��Ō��������t�@�C�����A
		�ǉ�����STL�R���e�i�B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă�
		�Ȃ�܂���B
	 */
	CDirCallback_StrContainer( StrContainerType* pStrContainerType )
		: m_pStrContainerType( pStrContainerType ){};
 public:
	// ********************************
	///@name IfDirCallback	
	// ********************************
	///@{
	/**
		���������t�@�C�����E�f�B���N�g�������A�ďo���ɒʒm���܂��B
	 @param strName [in]
		���������t�@�C�����E�f�B���N�g����
	
	 [�I�[�o���C�h]
		m_pStrContainerType ���w���R���e�i�ɁCpush_back()���\�b�h��
		���O��ǉ����܂��B
	 */
	virtual void OnNameFound( const std::string& strName ) 
	{
		m_pStrContainerType->push_back( strName ) ;
	};
	///@}
};

// ****************************************************************
///@name �t�@�C��/�f�B���N�g������
// ****************************************************************
///@{

/**
 	Dirnames() Filenames() ���t�@�C�����̈ꗗ���i�[����R���e�i
 */
typedef std::deque<std::string> ContFilenames ;

/**
 	����������ɍ��v����f�B���N�g�������������A
 	���̈ꗗ�̃R���e�i��Ԃ��܂��B
 	�f�B���N�g�����̎w��ɂ́A*��?�̃��C���h�J�[�h��
 	�g�p���邱�Ƃ��ł��܂��B
 	���C���h�J�[�h�́A������������̍ŉ��ʂ�
 	�f�B���N�g�����ɂ����A�g�p�\�ł�
 		�i��F"c:\windows\*" "c:\windows\???" "c:\user\s*" �j 
@param strSearch
 	�@������������w�肵�Ă��������B
@param bSubdirectrySearch
 	�@�^�Ȃ�A�T�u�f�B���N�g���������ΏۂɊ܂߂܂��B
@return
 	  ����������ɍ��v����f�B���N�g�������i�[����
 	stl�R���e�i�ł��B
@attention
 	 strSearch �̖����� "." ( �J�����g�f�B���N�g�� ) , ".." (�e�f�B���N�g��) ��
	�w�肷�邱�Ƃ͂ł��܂���B���̏ꍇ�́A �߂�l�̃R���e�i��
	�v�f���� 0 �ɂȂ�܂��B
 */
inline ContFilenames Dirnames( const std::string& strSearch , 
						bool bSubdirectrySearch )
{
	ContFilenames	aContFilename ;
	CDirCallback_StrContainer<ContFilenames>	aCallback( &aContFilename ) ;
	findDir( strSearch , bSubdirectrySearch , &aCallback ); 
	return ( aContFilename ) ;
}

/**
 	����������ɍ��v����t�@�C�������������A
 	���̈ꗗ�̃R���e�i��Ԃ��܂��B
 	�t�@�C�����̎w��ɂ́A*��?�̃��C���h�J�[�h��
 	�g�p���邱�Ƃ��ł��܂��B
 	���C���h�J�[�h�́A������������̍ŉ��ʂ�
 	�t�@�C�����ɂ����A�g�p�\�ł�
 		�i��F"c:\windows\*" "c:\windows\???" "c:\user\s*" �j 
@param strSearch
 	�@������������w�肵�Ă��������B
@param bSubdirectrySearch
 	�@�^�Ȃ�A�T�u�f�B���N�g���������ΏۂɊ܂߂܂��B
@return
 	  ����������ɍ��v����t�@�C�������i�[����
 	stl�R���e�i�ł��B
 */
inline ContFilenames Filenames( const std::string& strSearch , 
						bool bSubdirectrySearch )
{
	ContFilenames	aContFilename ;
	CDirCallback_StrContainer<ContFilenames>	aCallback( &aContFilename ) ;
	findFile( strSearch , bSubdirectrySearch , &aCallback ); 
	return ( aContFilename ) ;
}
///@}


} //namespace Dir{
} //namespace OuLib{

#endif /*Directries_h*/

