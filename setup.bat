@echo off

REM Get the directory of this .bat file
set "BATDIR=%~dp0"

REM Remove trailing backslash if needed
if "%BATDIR:~-1%"=="\" set "BATDIR=%BATDIR:~0,-1%"

REM Set Turbo C++ root relative to the BAT file location
set "TC=%BATDIR%\TC"

REM Setup environment variables
set "PATH=%TC%\BIN;%PATH%"
set "INCLUDE=%TC%\INCLUDE"
set "LIB=%TC%\LIB"
