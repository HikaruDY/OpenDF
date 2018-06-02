@echo off
REM //OpenDF :: An open source implementation of DFramework.]
REM //	(C)2018 OpenDF Project
REM //
REM //	Read LICENSE file for licenses and copyrights information before using this file.
REM //

setlocal
call "%~dp0\Config" || GOTO ERROR

set DIR_TESTS=%~dp0\..\Tests
set CC_TestCommonInclude=/I"%DIR_TESTS%"

:MAIN
pushd "%DIR_TESTS%"
set PATH=%DIR_BIN%;%PATH%

IF NOT "%~1" == "" CALL :TEST %~1 && GOTO EOF || GOTO ERROR


:TEST_ALL
FOR /F "tokens=* delims=\ " %%D IN (
	'dir /B /A:D'
) DO (
	CALL :TEST "%%~D" || GOTO ERROR
)
GOTO EOF


:TEST
IF NOT EXIST "%~1\_Test_.cpp" (
	echo No specified test "%~1" found.
	GOTO ERROR
)

pushd "%~1"
	echo Test of %~1:
	%CC% %CFLAGSX% %CFLAGS% %CC_TestCommonInclude% _Test_.cpp || GOTO ERROR
	%LD% %LDFLAGSX% *.obj "%DIR_LIB%\OpenDF.lib" || GOTO ERROR
	_Test_
popd
GOTO RETURN

:ERROR
exit /b 1
:EOF
endlocal
exit /b 0
:RETURN
