#include <iostream>
#include "../include/utilidades.h"

using namespace std;

void mostrarMenu() {
    cout << "=== Clínica Dental Ratoncito Pérez ===" << endl;
    cout << "1. Gestión de Pacientes" << endl;
    cout << "2. Gestión de Inventario" << endl;
    cout << "3. Gestión de Tratamientos" << endl;
    cout << "4. Gestión de Citas" << endl;
    cout << "0. Salir" << endl;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
