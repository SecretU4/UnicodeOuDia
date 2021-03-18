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
//	CdFilenameStr.h
// ****************************************************************
*/
/** @file */
#ifndef  CdFilenameStr_h
#define  CdFilenameStr_h

#include <string>
#include <vector>

// ****************************************************************
//	CdFilenameStr
// ****************************************************************
/** @brief
* �y�T�v�z
* 	  �h���C�u�E�f�B���N�g���E�t�@�C�����܂񂾕������ێ����܂��B
* 	  �����̊e�v�f����͂��A�t���p�X���Ƃ̊Ԃ̕ϊ����s�����Ƃ��ł��܂��B
* 
* �y�g�����P�|�t���p�X������̍\���v�f���擾�z
*
* �P�D �t���p�X��������\���v�f�ɕ�������ꍇ�́A���̃I�u�W�F�N�g�𐶐����A
*	�t���p�X������� setFullpathFilename() �œn���Ă��������B
*	  setFullpathFileName() �́A�n���ꂽ�t���p�X�t�@�C��������͂��āA
*	�\���v�f�ɕ������A�v�f��this�̑����ɐݒ肵�܂��B
*
* �Q�D  setFullpathFilename() ���I��������A�������Q�Ƃ��邱�Ƃɂ��A
*	�t���p�X������̍\���v�f���擾�ł��܂��B
*
* @b �t���p�X�t�@�C��������g���q���擾�����
* @code
	CdFilenameStr	aCdFilenameStr ;
	aCdFilenameStr.setFullpathFilename( "c:\\windows\\system32\\readme.txt" ) ;
	string	strExt = aCdFilenameStr.Extension() ;
	//strExt = "txt" �ƂȂ�܂��B
* @endcode
*
* �y�g�����Q�|�t���p�X��������\�z����z
*
* �P�D �t���p�X��������\�z����ꍇ�́A���̃I�u�W�F�N�g�̊e�����ɁA
*	�\���v�f��ݒ肵�Ă��������B
*
* �Q�D  ���̌�A FullpathFilename() ���Ăяo���Ă��������BFullpathFilename() ��
*	���������ƂɁA�t���p�X�t�@�C������Ґ����ĕԂ��܂��B
*/
class CdFilenameStr
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**
	*	�f�B���N�g�����i�[���邽�߂̃R���e�i�ł��B
	* 	�f�B���N�g���́A�Y�����̏����������珇�Ɋi�[����܂��B
	*/
	typedef std::vector<std::string>	ContstrDir ;
// ********************************
/// @name	����
// ********************************
///@{
 private:
	/**
	* 	�h���C�u�����ł��B ":" �͊܂݂܂���B
	* 	�h���C�u�������Ȃ��ꍇ�́A�󕶎���ł��B
	*
	*	��:
	*	 "C:\Windows\System32\readme.txt" �̏ꍇ�́A
	*	���̑����� "C" �ƂȂ�܂��B
	*/
	std::string					m_strDrive ;
	
	/**
	*	�f�B���N�g�����A�i�[���Ă��܂��B
	* 	�f�B���N�g���́A�Y�����̏����������珇�Ɋi�[����܂��B
	*
	*	��:
	*	 "C:\Windows\System32\readme.txt" �̏ꍇ�́A
	*	���̑�����
	*
	* -		[0]="Windows"
	* -		[1]="System32"
	*
	*	�ƂȂ�܂��B
	*/
	ContstrDir			m_contstrDir ;
	
	/**
	* 	�x�[�X�t�@�C�����ł��B
	* 	�g���q���܂݂܂���B
	*
	*
	*	��:
	*	 "C:\Windows\System32\readme.txt" �̏ꍇ�́A
	*	���̑����� "readme" �ƂȂ�܂��B
	*/
	std::string					m_strBaseFilename ;
	
	/**
	* 	�g���q�ł��B"."�͊܂݂܂���B�Ȃ��ꍇ�́A�󕶎���ł��B
	*
	*	��:
	*	 "C:\Windows\System32\readme.txt" �̏ꍇ�́A
	*	���̑����� "txt" �ƂȂ�܂��B
	*/
	std::string					m_strExtension ;
	
	/**
	* 	���̃p�X�̃f�B���N�g������Ύw��ł���΋U�A���΃p�X�Ȃ�^�ł��B
	*
	*	��:
	*	 "C:\Windows\System32\readme.txt" �̏ꍇ�́A
	*	���̑����� true �ƂȂ�܂��B
	*/
	bool						m_bIsRelativePath ;
	
	/**
	* 	���̃p�X���A�t�@�C�����̂���`���ł���Ȃ�^�ł��B
	* 	���̏ꍇ�́A��ԉE�� '\' �̉E���̓t�@�C�����Ƃ݂Ȃ���܂��B
	* 	���̃p�X���A�t�@�C�����̂Ȃ��`���ł���΋U�ł��B
	* 	���̏ꍇ�́A��ԉE�� '\' �̉E�����f�B���N�g���Ƃ݂Ȃ��܂��B
	*
	*	�R���X�g���N�^�E�܂��� setIsValidFilename() �ɂ��A���炩���ߖ����I��
	*	�ݒ肪�K�v�ȑ����ł��B
	*/
	bool						m_bIsValidFilename ;
///@}

// ********************************
//	�R���X�g���N�^�E�f�X�g���N�^
// ********************************
 public:
	CdFilenameStr() ;
	/**
	* @param strFilename [in]
	* 	�t���p�X���i�h���C�u�E�f�B���N�g���E�t�@�C��������������������j
	* 	���w�肵�Ă��������B
	* @param bIsValidFilename [in]
	* 	���̃p�X���A�t�@�C�����̂���`���ł���Ȃ�^�ł��B
	* 	���̏ꍇ�́A��ԉE�� '\' �̉E���̓t�@�C�����Ƃ݂Ȃ���܂��B
	* 	���̃p�X���A�t�@�C�����̂Ȃ��`���ł���΋U�ł��B
	* 	���̏ꍇ�́A��ԉE�� '\' �̉E�����f�B���N�g���Ƃ݂Ȃ��܂��B
	*/
	CdFilenameStr( std::string strFilename , bool bIsValidFilename = true ) ;

// ********************************
//	CdFilenameStr
// ********************************
 public:
	// ********************************
	///	@name ����
	// ********************************
	///@{

	/**
	* 	�h���C�u�����ł��B
	* 	�h���C�u�������Ȃ��ꍇ�́A�󕶎���ł��B
	*/
	std::string			Drive() const ;
	CdFilenameStr& 		setDrive( const std::string& ev ) ;
	
	/**
	* 	�f�B���N�g����Ԃ��܂��B
	* 	�f�B���N�g���́A�Y�����̏����������珇�Ɋi�[����Ă��܂��B
	*/
	ContstrDir		Dirs()const  ;
	CdFilenameStr& 	setDirs( const ContstrDir& ev ) ;
	
	/**
	* @return
	* 	�f�B���N�g���̐��i�K���j��Ԃ��܂��B
	*/
	int DirCount()const ;
	
	/**
	* 	�f�B���N�g����Ԃ��܂��B
	* @param index [in]
	* 	�f�B���N�g���̊K���iDirs�̓Y���j���A�O�ȏ�DirCount()�����̐���
	*	�w�肵�Ă��������B
	* @return
	* 	�f�B���N�g����Ԃ��܂��B
	*/
	std::string DirAt( int idx )const ;
	
	/**
	* 	�f�B���N�g���𖖔��ɒǉ����܂��B
	* @param ev [in]
	* 	�ǉ�����f�B���N�g���̖��O���w�肵�Ă��������B
	*/
	CdFilenameStr& 	addDirLast( const std::string& ev ) ;
	
	/**
	* 	�f�B���N�g�����w��̈ʒu�ɒǉ����܂��B
	* @param index [in]
	* 	�ǉ�����ꏊ���A�O�ȏ�DirCount()�ȉ��̐��Ŏw�肵�Ă��������B
	* @param ev [in]
	* 	�ǉ�����f�B���N�g���̖��O���w�肵�Ă��������B
	*/
	CdFilenameStr& 	addDirAt( int index , const std::string& ev ) ;
	
	/**
	* 	�f�B���N�g���̖������폜���܂��B
	*/
	CdFilenameStr& 	delDirLast() ;
	/**
	* 	�f�B���N�g�����폜���܂��B
	* @param index [in]
	* 	�폜����f�B���N�g�����A�O�ȏ�DirCount()�����̐��Ŏw�肵�Ă��������B
	*/
	CdFilenameStr& 	delDirAt( int index ) ;
	
	
	/**
	* 	�x�[�X�t�@�C�����ł��B
	* 	�g���q���܂݂܂���B
	*/
	std::string				BaseFilename() const ;
	CdFilenameStr& 			setBaseFilename( const std::string& ev ) ;
	
	/**
	* 	�g���q�ł��B
	*/
	std::string					Extension() const ;
	CdFilenameStr& 				setExtension( const std::string& ev ) ;
	
	/**
	* 	���̃p�X����΃p�X�ł���΋U�A���΃p�X�Ȃ�^�ł��B
	*/
	bool						IsRelativePath() const ;
	CdFilenameStr&				setIsRelativePath( bool ev ) ;
	
	/**
	* 	���̃p�X���A�t�@�C�����̂���`���ł���Ȃ�^�ł��B
	* 	���̏ꍇ�́A�t���p�X���������͂���ꍇ�ɁA
	* 	��ԉE�� "\" �̉E�����t�@�C�����Ƃ݂Ȃ���܂��B
	* 	���̃p�X���A�t�@�C�����̂Ȃ��`���ł���΋U�ł��B
	* 	���̏ꍇ�́A�t���p�X���������͂���ꍇ�ɁA
	* 	��ԉE�� "\" �̉E�����f�B���N�g���Ƃ݂Ȃ��܂��B
	*/
	bool						IsValidFilename() const ;
	CdFilenameStr&				setIsValidFilename( bool ev ) ;
	
	/**
	* @return
	* 	�x�[�X�t�@�C�����Ɗg���q�����������t�@�C������Ԃ��܂��B
	*/
	std::string 				Filename() const ;

	/**
	* @param ev [in]
	* 	�x�[�X�t�@�C�����Ɗg���q�����������t�@�C�������w�肵�Ă��������B
	* @return
	* 	���̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	CdFilenameStr& 				setFilename( std::string ev ) ;
	
	///@}
	
	// ********************************
	///	@name ����
	// ********************************
	///@{
	
	/**
	* @return
	* 	�t���p�X�t�@�C�������擾���邱�Ƃ��ł��܂��B
	* 	�����̊e�v�f���������āA�t���p�X��������쐬���܂��B
	* 
	* 	m_bIsValidFilename ���^�̏ꍇ�́A�t�@�C�����������Ă��Ȃ��Ă��A
	* 	�f�B���N�g�����̂��Ƃ� '\' �����܂��B
	* 	m_bIsValidFilename ���U�̏ꍇ�́A
	* 	�f�B���N�g�����̂��Ƃ� '\' �����܂���B�܂��A�t�@�C������
	* 	�o�͂���܂���B
	*/
	std::string 				FullpathFilename() const ;
	
	/**
	* 	�t���p�X�t�@�C��������͂��邱�Ƃ��ł��܂��B
	* @param strFilename [in]
	* 	�t���p�X���i�h���C�u�E�f�B���N�g���E�t�@�C��������������������j
	* 	���w�肵�Ă��������B
	* @param bIsValidFilename [in]
	* 	���̃p�X���A�t�@�C�����̂���`���ł���Ȃ�^�ł��B
	* 	���̏ꍇ�́A��ԉE�� '\' �̉E���̓t�@�C�����Ƃ݂Ȃ���܂��B
	* 	���̃p�X���A�t�@�C�����̂Ȃ��`���ł���΋U�ł��B
	* 	���̏ꍇ�́A��ԉE�� '\' �̉E�����f�B���N�g���Ƃ݂Ȃ��܂��B
	* 	�w�肵�Ȃ��ꍇ�́A���݂̃��[�h���ێ����܂��B
	* @return
	* 	���̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	CdFilenameStr& setFullpathFilename( std::string ev , 
										bool bIsValidFilename ) ;
	/** @overload */
	CdFilenameStr& setFullpathFilename( std::string ev ) ;

	/**
	* 	�f�B���N�g�����Aev�ɂ��������đ��Έړ����܂��B
	* 
	* 	   ev �̃f�B���N�g�������Ύw��Ȃ�Athis�̃f�B���N�g����
	* 	 ev �̃f�B���N�g���ɂ��������đ��Έړ����܂��B
	* 	   ev �̃f�B���N�g������Ύw��Ȃ�A this �̃f�B���N�g����
	* 	ev �ɒu�������܂��B
	* 	   ev �Ƀf�B���N�g���ȊO�̗v�f���܂܂�Ă���ꍇ�A
	* 	this �̂��̂� ev �̂��̂ɒu�������܂��B
	* @param ev [in]
	* 	�ړ�����w�肵�Ă��������B
	*/
	CdFilenameStr& ChangeDir( const CdFilenameStr& ev ) ;
	
	/**
	* 	  �f�B���N�g�����Aev����̑��Ύw��ɕϊ����܂��B
	* 	 this�Eev�̃f�B���N�g���́A��Ύw��łȂ��Ă͂Ȃ�܂���B
	* 	�ǂ��炩�����Ύw��ł���ꍇ�́A���̊֐��͎��s���܂��B
	* 	 this�Ƀf�B���N�g���ȊO�̗v�f���w�肳��Ă����ꍇ�A�����
	* 	�ێ�����܂��B
	* 	  ev �Ƀf�B���N�g���ȊO�̗v�f���w�肳��Ă���
	* 	 this �ɑΉ�����v�f���w�肳��Ă��Ȃ��ꍇ�́A
	* 	 ev �̂��̂� this �ɃR�s�[���܂��B
	* @param ev [in]
	* 	�ړ������w�肵�Ă��������B
	* @return
	* 	-	0:����
	* 	-	-1 ;	// 	 �h���C�u���قȂ邽�߁A���΃p�X�ɂ͂ł��܂���B
	* 	-	-2 ;	//	 this�����΃p�X�ł�
	* 	-	-3 ;	//	 ev�����΃p�X�ł�
	*/
	int ChangeToRelativeDir( const CdFilenameStr& ev ) ;
	
	///@}
	
	// ********************************
	//	���Z�q
	// ********************************
	
	/** FullpathFilename() �Ɠ����ł� */
	operator std::string()const{	return FullpathFilename() ; } ;
};

#endif /*CdFilenameStr_h*/

