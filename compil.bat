@echo off
echo Compilando Clinica Ratoncito Perez...
C:\TDM-GCC-64\bin\g++.EXE -Wall -Wextra -O2 src\main.cpp src\menu.cpp src\pacientes.cpp src\inventario.cpp src\tratamientos.cpp src\citas.cpp -I.\include -o "Clinica_Ratoncito_Perez.exe"

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ✓ Compilación exitosa!
    echo ✓ Ejecutable creado: Clinica_Ratoncito_Perez.exe
    echo.
    echo Presiona cualquier tecla para ejecutar el programa...
    pause >nul
    "Clínica_Ratoncito_Perez.exe"
) else (
    echo.
    echo ✗ Error en la compilación
    echo Revisa los errores mostrados arriba
    pause
)