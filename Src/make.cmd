@echo off
REM //OpenDF :: An open source implementation of DFramework.]
REM //	(C)2018 OpenDF Project
REM //
REM //	Read LICENSE file for licenses and copyrights information before using this file.
REM //

REM // OpenDF Makefile for Windows
REM //	When type 'make' in Linux: Ignore this file by default, will run native 'make' command and load 'Makefile' instead.

setlocal
call "%~dp0\Config.cmd"

:MAIN
pushd "%~dp0"


:CLEAN
REM //Init Output / TEMP Directory
rmdir /s /q "%DIR_BIN%" 2>nul
rmdir /s /q "%DIR_LIB%" 2>nul
rmdir /s /q "%DIR_TEMP%" 2>nul
IF EXIST "%DIR_TEMP%" echo Failed to delete "%DIR_TEMP%" & GOTO ERROR

IF /I "%~1" == "clean" GOTO EOF


:BUILD
REM //Generate Output / TEMP Directory
mkdir "%DIR_BIN%"
mkdir "%DIR_LIB%"
mkdir "%DIR_TEMP%"
IF NOT EXIST "%DIR_TEMP%" echo Failed to make "%DIR_TEMP%" & GOTO ERROR


REM //Generate OpenDF_Build.h / DF_BUILD
cl /nologo /E "%DIR_COMMON%\OpenDF_Build_Generator.h" > "%DIR_INCLUDE%\OpenDF_Build_Generated.h"
cl /nologo /E "%DIR_COMMON%\OpenDF_Include_Generator.h" /I"%DIR_INCLUDE%" > "%DIR_INCLUDE%\OpenDF_Include_Generated.h"


REM //Generate Res file
set ODF_RC_FILE=%DIR_TEMP%\OpenDF_%TARGET_CPU%.res
rc /NoLogo /I"%DIR_INCLUDE%" /DODF_RC_TARGET=%TARGET_CPU% /Fo"%ODF_RC_FILE%" "%DIR_COMMON%\OpenDF.rc"

REM //Compile all *.cpp, *.c files
FOR /F "tokens=* delims=\ " %%F IN (
	'dir /B /S ODFSourceFiles.cpp ODFSourceFiles.c'
) DO (
	call :CC "%%F" || GOTO ERROR
)


REM //Link all generated *.obj files.
call :LD || GOTO ERROR


GOTO EOF

:CC [FilePath] [ParentDirName]
	set FILEPATH=%~dp1
	FOR /F "tokens=* delims=\ " %%X IN ("%FILEPATH:~0,-1%") DO (set DIRNAME=%%~nxX)
	%CC% %CFLAGSX% %CFLAGS% %COUTFILE%"%DIR_TEMP%\%DIRNAME%_-_%~n1.obj" "%~1" || GOTO ERROR_SUB
GOTO RETURN

:LD
	pushd "%DIR_TEMP%"
	%LD% %LDFLAGSX% %LDFLAGS% *.obj %LDOUTFILE%"%FILE_OPENDF%" %ODF_RC_FILE% || GOTO ERROR_SUB
	move /y "*.dll" "%DIR_BIN%\" || GOTO ERROR
	move /y "*.lib" "%DIR_LIB%\" || GOTO ERROR
	popd
GOTO RETURN

:EOF
call :FINALIZE
exit /b 0
GOTO RETURN
:ERROR
call :FINALIZE
echo Build failed.
exit /b 1
GOTO RETURN
:FINALIZE
popd
endlocal
GOTO RETURN
:ERROR_SUB
exit /b 1
:RETURN
