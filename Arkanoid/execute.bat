@echo off

echo Comenzando copia

copy %1 %2 /Y

xcopy %3 %2 /s /Y

echo Finalizado el Copiado