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
//	CEnumToString
//	$Id: CEnumToString.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
/** @file */
#ifndef  CEnumToString_h
#define  CEnumToString_h
#include <string>
#include <map>

// ****************************************************************
//	CEnumToString
// ****************************************************************
/**
@brief
	�񋓎q-������Ԃ̕ϊ���񋟂��܂��B

	�񋓎q��������̈�����̕ϊ��Ȃ� std::map �Ŏ�����܂��B
	�������A map �ɂ͗������̕ϊ����ł��܂���B
	���̃N���X�́A map �̒l����L�[���t��������@�\��ǉ����Ă��܂��B

@param _EnumType 
	�񋓌^���w�肵�Ă��������B

�y�g�����z

1.  �񋓎q�ƑΉ����镶����� add() �Œǉ����Ă��������B

2.  �Ȍ�́AstringOf()�EfromString() �����p�ł��܂��B

(��)
@code
enum ERessyahoukou
{
	//	���� 
	Ressyahoukou_Kudari = 0 ,
	//	��� 
	Ressyahoukou_Nobori ,
};


const CEnumToString<ERessyahoukou>& getEnumToString()
{
	static CEnumToString<ERessyahoukou> aEnumToString ;
	if ( aEnumToString.size() == 0 )
	{
		aEnumToString.add( Ressyahoukou_Kudari , "Kudari" ) ;
		aEnumToString.add( Ressyahoukou_Nobori , "Nobori" ) ;
	}
	return aEnumToString ;
};
	string strValue = getERessyahoukouToString().stringOf( 
				Ressyahoukou_Kudari ) ;

@endcode


*/
template <class _EnumType > class CEnumToString
{
public:
	typedef typename _EnumType EnumType ;
private:
	/**
		
	*/
	std::map< _EnumType , std::string >	m_Map ;
public:
	/**
	@return
		�o�^�����񋓎q�̐���Ԃ��܂��B
	*/
	int size()const
	{
		return (int)m_Map.size() ;
	};

	/**
		�񋓎q�ƑΉ����镶�����ǉ����Ă��������B
	@param eValue [in]
		�񋓎q���w�肵�Ă��������B
	@param strValue [in]
		��������w�肵�Ă��������B
	*/
	void add( EnumType eValue , const std::string& strValue ) 
	{
		m_Map[eValue] = strValue ;
	};
	/**
		�񋓎q�ɑΉ����镶�����Ԃ��܂��B
	@param eValue [in]
		�񋓎q���w�肵�Ă��������B
	@return
		�Ή����镶�����Ԃ��܂��B
		eValue �� add() �œo�^����Ă��Ȃ��ꍇ�́A�󕶎����Ԃ��܂��B
	*/
	std::string stringOf( EnumType eValue )const 
	{
		std::string strValue ;
		std::map< _EnumType , std::string >::const_iterator ite = m_Map.find( eValue ) ;
		if ( ite != m_Map.end() )
		{
			strValue = ite->second ;
		}
		return strValue ;
	};
	/**
		stringOf() �̋t�ϊ����s���܂��B
	@param strValue [in]
		��������w�肵�Ă��������B
	@param peValue [out]
		���̊֐��͂��̃A�h���X�ɁA�Ή�����񋓎q���������݂܂��B
		�ϊ��Ɏ��s�����ꍇ�́A���̃A�h���X�͕ύX����܂���B
	@return
		�ϊ��ɐ��������� 0 �A�G���[�Ȃ畉�̐��ł��B
		-	-1 ; //	�Ή�����񋓎q���o�^����Ă��܂���B
	*/
	int fromString( const std::string& strValue , EnumType* peValue )const 
	{
		int iRv = 0 ;
	
		std::map< _EnumType , std::string >::const_iterator ite ;
		for ( ite = m_Map.begin() ; ite != m_Map.end() ; ite ++ )
		{
			if ( ite->second == strValue )
			{
				break ;
			}
		}
		if ( ite == m_Map.end() )
		{
			iRv = -1 ;
		}
		else
		{
			*peValue = ite->first ;
		}
		return iRv ;
	}
};
#endif //CEnumToString_h
