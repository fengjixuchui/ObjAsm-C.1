rem setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

REM Usual path: OBJASM_PATH="D:\ObjAsm"
REM It is stored in the registry:
REM   - HKEY_CURRENT_USER\Environment
REM   - HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment

REM ----------- For my own use -----------------
if "%COMPUTERNAME%"=="LWP-JKHC2Z2" (
  set ToolPath="C:\_MySoftware_"
  set Linker="C:\_MySoftware_\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.27.29110\bin\Hostx64\x64\link.exe"
  set LibraryCompiler="C:\_MySoftware_\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.27.29110\bin\Hostx64\x64\lib.exe"
) else (
  set ToolPath="%ProgramFiles(x86)%"
  set Linker="%ProgramFiles(x86)%\Microsoft Visual Studio 14.0\VC\bin\link.exe"
  set LibraryCompiler="%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64\lib.exe"
)

"%SystemRoot%\system32\reg.exe" Query "HKLM\Hardware\Description\System\CentralProcessor\0" | "%SystemRoot%\system32\find.exe" /i "x86" > NUL && set SYSTEM_BITNESS=32 || set SYSTEM_BITNESS=64

if %OS%==64BIT echo This is a 64bit operating system

set BldInf="%OBJASM_PATH%\Build\Tools\BuildInfo.cmd"
set Inc2RC="%OBJASM_PATH%\Build\Tools\Inc2RC.cmd"
set MidlCompiler="%ToolPath:"=%\Windows Kits\10\bin\10.0.18362.0\x64\midl.exe"
set UICCompiler="%WINKIT_PATH%\x86\UICC.exe"
set ResourceCompiler="%ToolPath:"=%\Windows Kits\10\bin\10.0.18362.0\x64\RC.EXE"
set EfiImageConverter="D:\EFI_Toolkit_2.0\build\tools\bin\fwimage"

if %SYSTEM_BITNESS%==32 (
  set Assembler="!OBJASM_PATH!\Build\Tools\UASM32.EXE"
) else (
  set Assembler="!OBJASM_PATH!\Build\Tools\UASM64.EXE"
)

set Debugger="%ToolPath:"=%\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"

exit /b 0