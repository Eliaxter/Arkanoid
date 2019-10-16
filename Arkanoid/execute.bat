@echo off

echo Comenzando copia

copy %1 %2

xcopy %1 /E %2

echo Finalizado el Copiado