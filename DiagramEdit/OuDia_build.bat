rem OuDia �r���h
setlocal

rem ****************************************************************
rem �r���h���ݒ�
rem ****************************************************************

rem TODO: vcvars32.bat �̃p�X���A���g���̊��ɍ��킹�ĕύX���Ă��������B
call "%VS90COMNTOOLS%vsvars32"


rem  --------------------------------
rem TODO: �r���h�\����ݒ肵�Ă��������B
rem �ʏ�� Release �� Release_Static �ł�
SET CONFIGURATIONNAME=Release_Static


rem  --------------------------------
rem TODO: HTML Help Workshop �Ɋ܂܂�� hhc.exe �̃p�X���A
rem ���g���̊��ɍ��킹�ĕύX���Ă��������B

rem SET HHC="C:\Program Files\HTML Help Workshop\hhc"
SET HHC="D:\Program Files (x86)\HTML Help Workshop\hhc"


rem  --------------------------------
rem TODO: �R���o�[�^DLL�̃r���h���s��Ȃ��ꍇ�́A���̍s�� rem ���폜���Ă��������B
rem set CONVFILEDLL_NOT_BUILD=1


rem  --------------------------------
rem TODO: �r���h���̃R�}���h���w�肵�Ă��������B�ʏ�� /build �ł����A
rem �󋵂ɂ���āA /rebuild /clean ��I���ł��܂��B

set COMMAND=/build





rem ****************************************************************
rem (1)�@�R���o�[�^DLL
rem ****************************************************************

if "%CONVFILEDLL_NOT_BUILD%"=="1" goto CONVFILE_END

pushd ConvDedFile\ConvFileOudia02To03
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��\ConvDedFile\ConvFileOudia02To03

devenv ConvFileOudia02To03.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��


pushd ConvDedFile\ConvFileOudia03To05
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��\ConvDedFile\ConvFileOudia03To05

devenv ConvFileOudia03To05.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��

pushd ConvDedFile\ConvFileOudia05To06
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��\ConvDedFile\ConvFileOudia05To06

devenv ConvFileOudia05To06.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��

pushd ConvDedFile\ConvFileOudia06To101
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��\ConvDedFile\ConvFileOudia06To101

devenv ConvFileOudia06To101.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��



pushd ConvDedFile\ConvFileOudia101To102
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��\ConvDedFile\ConvFileOudia101To102

devenv ConvFileOudia101To102.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��


:CONVFILE_END

rem  --------------------------------
rem (2)�@�}�j���A���� .chm
rem  --------------------------------

pushd manual

call %HHC% oudia.hhp
copy oudia.chm ..\%CONFIGURATIONNAME%


popd 


rem  --------------------------------
rem (3)�����[�X�Ń\�t�g
rem  --------------------------------

pushd .
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��

devenv DiagramEdit.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��

rem  --------------------------------
rem (4)�C���X�g�[��
rem  --------------------------------

rem �Z�b�g�A�b�v�Ɋ܂߂�K�v�̂���t�@�C���̂����A
rem src\DiagramEdit\Release_Static �ɐ�������Ă���t�@�C����
rem src\DiagramEdit\DiagramEdit_setup\CollectedOnBuild �ɃR�s�[����

pushd DiagramEdit_setup
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��\DiagramEdit_setup
mkdir CollectedOnBuild
copy /Y ..\%CONFIGURATIONNAME%\*.dll CollectedOnBuild
copy /Y ..\%CONFIGURATIONNAME%\*.chm CollectedOnBuild
popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��



pushd .
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��

devenv DiagramEdit.sln %COMMAND% "%CONFIGURATIONNAME%" /project DiagramEdit_setup

popd
rem �J�����g�f�B���N�g��=���̃o�b�`�t�@�C���̃f�B���N�g��


