@echo off
g++ p%1\p%1.cpp -o test.exe 
if errorlevel 1 goto quit
test.exe
del test.exe
:quit
