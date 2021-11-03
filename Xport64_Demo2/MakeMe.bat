@echo off
set ROOT=c:/ultra
call %ROOT%\setupgcc.bat
call %ROOT%\setuplib.bat
make

echo.
::move /-y *.o "bin\objects\" >nul
::move /-y *.out "bin\objects\" >nul
::move /-y *.n64 "bin\" >nul
::move /-y src\scenes\level00\*.n64 "bin\" >nul
echo.

pause
