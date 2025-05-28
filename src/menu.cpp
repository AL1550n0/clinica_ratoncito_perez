// Menu.cpp
#include <iostream>
#include "../include/menu.h"
#include "../include/pacientes.h"
#include "../include/inventario.h"
#include "../include/tratamientos.h"
#include "../include/citas.h"
using namespace std;

void mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "\n----- Menú Principal -----\n";
        cout << "1. Gestionar Pacientes\n";
        cout << "2. Gestionar Citas\n";
        cout << "3. Gestionar Tratamientos\n";
        cout << "4. Gestionar Medicamentos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuPacientes(); break;
            case 2: menuCitas(); break;
            case 3: menuTratamientos(); break;
            case 4: menuInventario(); break;
            case 5:  cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
}

void menuPacientes() {}

void menuCitas() {}

void menuTratamientos() {}

void menuInventario() {}
