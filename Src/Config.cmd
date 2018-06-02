@echo off
REM //OpenDF :: An open source implementation of DFramework.]
REM //	(C)2018 OpenDF Project
REM //
REM //	Read LICENSE file for licenses and copyrights information before using this file.
REM //

:DIR
set DIR_ROOT=%~dp0\..
set DIR_SRC=%DIR_ROOT%\Src
set DIR_TEMP=%DIR_SRC%\TEMP
set DIR_COMMON=%DIR_SRC%\Common

set DIR_BIN=%DIR_ROOT%\Bin
set DIR_LIB=%DIR_ROOT%\Lib
set DIR_INCLUDE=%DIR_ROOT%\Include

set FILE_OPENDF=OpenDF.dll

:CONFIG
set CC=cl
set LD=link

set CFLAGSX=/nologo /c
set LDFLAGSX=/nologo

set COUTFILE=/Fo
set LDOUTFILE=/Out:

set CFLAGS=/Ox /I"%DIR_INCLUDE%"
set LDFLAGS=/DLL /Subsystem:Windows /Def:"%DIR_COMMON%\OpenDF.def"



:DETECT_CPU
REM //Detect Target CPU
set TestCPP=%DIR_TEMP%\DetectTargetCPU.cpp
copy /y "%DIR_COMMON%\DetectTargetCPU.cpp.odf" "%TestCPP%" >nul || GOTO ERROR
%CC% %CFLAGSX% /P /Fi"%DIR_TEMP%\TargetCPU.cmd" "%TestCPP%" >nul || GOTO ERROR
del /f /q "%TestCPP%" >nul || GOTO ERROR
call "%DIR_TEMP%\TargetCPU.cmd" 2>nul

set DIR_BIN=%DIR_BIN%\%TARGET_CPU%
set DIR_LIB=%DIR_LIB%\%TARGET_CPU%

