rem OuDia ビルド
setlocal

rem ****************************************************************
rem ビルド環境設定
rem ****************************************************************

rem TODO: vcvars32.bat のパスを、お使いの環境に合わせて変更してください。
call "%VS90COMNTOOLS%vsvars32"


rem  --------------------------------
rem TODO: ビルド構成を設定してください。
rem 通常は Release か Release_Static です
SET CONFIGURATIONNAME=Release_Static


rem  --------------------------------
rem TODO: HTML Help Workshop に含まれる hhc.exe のパスを、
rem お使いの環境に合わせて変更してください。

rem SET HHC="C:\Program Files\HTML Help Workshop\hhc"
SET HHC="D:\Program Files (x86)\HTML Help Workshop\hhc"


rem  --------------------------------
rem TODO: コンバータDLLのビルドを行わない場合は、下の行の rem を削除してください。
rem set CONVFILEDLL_NOT_BUILD=1


rem  --------------------------------
rem TODO: ビルド時のコマンドを指定してください。通常は /build ですが、
rem 状況によって、 /rebuild /clean を選択できます。

set COMMAND=/build





rem ****************************************************************
rem (1)　コンバータDLL
rem ****************************************************************

if "%CONVFILEDLL_NOT_BUILD%"=="1" goto CONVFILE_END

pushd ConvDedFile\ConvFileOudia02To03
rem カレントディレクトリ=このバッチファイルのディレクトリ\ConvDedFile\ConvFileOudia02To03

devenv ConvFileOudia02To03.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem カレントディレクトリ=このバッチファイルのディレクトリ


pushd ConvDedFile\ConvFileOudia03To05
rem カレントディレクトリ=このバッチファイルのディレクトリ\ConvDedFile\ConvFileOudia03To05

devenv ConvFileOudia03To05.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem カレントディレクトリ=このバッチファイルのディレクトリ

pushd ConvDedFile\ConvFileOudia05To06
rem カレントディレクトリ=このバッチファイルのディレクトリ\ConvDedFile\ConvFileOudia05To06

devenv ConvFileOudia05To06.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem カレントディレクトリ=このバッチファイルのディレクトリ

pushd ConvDedFile\ConvFileOudia06To101
rem カレントディレクトリ=このバッチファイルのディレクトリ\ConvDedFile\ConvFileOudia06To101

devenv ConvFileOudia06To101.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem カレントディレクトリ=このバッチファイルのディレクトリ



pushd ConvDedFile\ConvFileOudia101To102
rem カレントディレクトリ=このバッチファイルのディレクトリ\ConvDedFile\ConvFileOudia101To102

devenv ConvFileOudia101To102.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem カレントディレクトリ=このバッチファイルのディレクトリ


:CONVFILE_END

rem  --------------------------------
rem (2)　マニュアルの .chm
rem  --------------------------------

pushd manual

call %HHC% oudia.hhp
copy oudia.chm ..\%CONFIGURATIONNAME%


popd 


rem  --------------------------------
rem (3)リリース版ソフト
rem  --------------------------------

pushd .
rem カレントディレクトリ=このバッチファイルのディレクトリ

devenv DiagramEdit.sln %COMMAND% "%CONFIGURATIONNAME%" 

popd
rem カレントディレクトリ=このバッチファイルのディレクトリ

rem  --------------------------------
rem (4)インストーラ
rem  --------------------------------

rem セットアップに含める必要のあるファイルのうち、
rem src\DiagramEdit\Release_Static に生成されているファイルを
rem src\DiagramEdit\DiagramEdit_setup\CollectedOnBuild にコピーする

pushd DiagramEdit_setup
rem カレントディレクトリ=このバッチファイルのディレクトリ\DiagramEdit_setup
mkdir CollectedOnBuild
copy /Y ..\%CONFIGURATIONNAME%\*.dll CollectedOnBuild
copy /Y ..\%CONFIGURATIONNAME%\*.chm CollectedOnBuild
popd
rem カレントディレクトリ=このバッチファイルのディレクトリ



pushd .
rem カレントディレクトリ=このバッチファイルのディレクトリ

devenv DiagramEdit.sln %COMMAND% "%CONFIGURATIONNAME%" /project DiagramEdit_setup

popd
rem カレントディレクトリ=このバッチファイルのディレクトリ


