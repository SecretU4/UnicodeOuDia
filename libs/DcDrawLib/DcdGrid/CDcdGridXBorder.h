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
/** @file CDcdGridXBorder.h */
//$Id: CDcdGridXBorder.h 296 2016-06-11 05:40:21Z okm $
//////////////////////////////////////////////////////////////////////

#ifndef CDcdGridXBorder_h
#define CDcdGridXBorder_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DcDraw/IfDcDraw.h"
#include "NsOu/Ou.h"


namespace DcDrawLib{
namespace DcdGrid{
	using namespace OuLib::NsOu;
	using namespace DcDraw;

// ****************************************************************
//	CDcdGridXBorder
// ****************************************************************
/**
@brief
�y�T�v�z
	DcdGrid ��X��̊Ԃ̌r��(�c�r��)�̃I�u�W�F�N�g�ł��B
	IfDcDraw �I�u�W�F�N�g�Ɗ֘A������� ���� IfDcDraw �I�u�W�F�N�g���g����
	DcdGrid��X��̋��E����`�悵�܂��B

	CDcdGrid �́A�ʏ�� CDcdLine �I�u�W�F�N�g�𐶐����āA
	this �Ɗ֘A���� IfDcDraw �I�u�W�F�N�g�Ƃ��ēo�^���܂��

*/
class CDcdGridXBorder  
{
private:
	// ********************************
	/// @name 	CDcdGrid �Ɋ֌W���鑮��/�֘A
	// ********************************
	///@{

	/**
		this �ɑ΂��錻�݂̕`��I�u�W�F�N�g���w���|�C���^�ł��B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A���̊֘A���L���ȊԂ́A
		�������Ă��Ȃ��Ă͂Ȃ�܂���B
	
		�ʏ�́A CDcdGrid::OnCreateXColumn() ���C���X�^���X�𐶐��E�o�^���A
		 CDcdGrid::OnDeleteXColumn() ���C���X�^���X��o�^�����E�j�����܂��B
		
		�f�t�H���g��  CDcdGrid::OnCreateXColumn() �̎����́A
		CDcdLine �C���X�^���X�𐶐��E�o�^���܂��B
		���̂Ƃ��̑����́A�����P�̍��̎���
		�ƂȂ�܂��B
	 */
	Ou<IfDcDraw>			m_pIfDcDraw ;
	/**
		�_���T�C�Y�ŁA��̊O���i�E/���j�̋��E�̃T�C�Y��ێ����܂��B
		�������A m_bAutoColumnBorderSize ���^�Ȃ�A���̒l�͖����ł��B
		�f�t�H���g�ł͂P�ł��B
	 */
	DcdSize	m_iColumnBorderSize ;
	
	/**
		- true ;	m_pIfDcDraw �� getItemSize() ���Ԃ� @n
			�T�C�Y�����ƂɁA��̊O���i�E/���j�̋��E�̃T�C�Y�����肵�܂��B
	*/
	bool	m_bAutoColumnBorderSize ;

	///@}	

	// ********************************
	//	�R���X�g���N�^
	// ********************************
public:
	/**
	 @param [in] pCDcdGrid 
		���̃I�u�W�F�N�g��ێ�����O���b�h�I�u�W�F�N�g�ւ̃|�C���^�ł��B
	 */
	CDcdGridXBorder();
	virtual ~CDcdGridXBorder(){};
private:
	CDcdGridXBorder( const CDcdGridXBorder& ev ){} ;
	void operator=( CDcdGridXBorder& ev ) {};

public:
	// ********************************
	/// @name	CDcdGridXBorder �֘A
	// ********************************
	///@{
	virtual Ou<IfDcDraw> getIfDcDraw() ;
	virtual void setIfDcDraw( Ou<IfDcDraw> value ) ;
	///@}

	// ********************************
	/// @name	CDcdGridXBorder ����
	// ********************************
	///@{

	CDcdGridXBorder& setColumnBorderSize( DcdSize ev ){
		m_bAutoColumnBorderSize = false ;
		m_iColumnBorderSize = ev ;	return *this ; } ;
	bool	getAutoColumnBorderSize(){
		return m_bAutoColumnBorderSize ;	} ;

	CDcdGridXBorder& setAutoColumnBorderSize( bool ev ){
		m_bAutoColumnBorderSize = ev ;	return *this ; } ;
	///@}
	// ********************************
	/// @name	����
	// ********************************
	///@{
	/**
		�_���T�C�Y�ŁA���E�̃T�C�Y��Ԃ��܂��B
	 @param pIfDcdTarget [in]
		�`��ΏۂƂȂ�^�[�Q�b�g���w�肵�Ă��������B
	 @return
		���E�̃T�C�Y��Ԃ��܂��B
	 */
	virtual DcdSize	getColumnBorderSize( IfDcdTarget* pIfDcdTarget ) ;
	///@}
};

} //namespace DcdGrid
} //namespace DcDrawLib
#endif // CDcdGridXBorder_h
