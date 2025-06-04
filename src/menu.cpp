#include "../include/menu.h"
#include <iostream>
using namespace std;

void mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "\n╔══════════════════════════════════╗" << endl;
        cout << "║     CLINICA RATONCITO PEREZ      ║" << endl;
        cout << "╠══════════════════════════════════╣" << endl;
        cout << "║  1. Gestión de Pacientes         ║" << endl;
        cout << "║  2. Gestión de Inventario        ║" << endl;
        cout << "║  3. Gestión de Tratamientos      ║" << endl;
        cout << "║  4. Gestión de Citas             ║" << endl;
        cout << "║  5. Salir                        ║" << endl;
        cout << "╚══════════════════════════════════╝" << endl;
        cout << "\nSeleccione una opción (1-5): ";
        cin >> opcion;
        cin.ignore(); // limpia el ENTER del buffer

        switch (opcion) {
            case 1:
                menuPacientes();
                break;
            case 2:
                menuInventario();
                break;
            case 3:
                menuTratamientos();
                break;
            case 4:
                menuCitas();
                break;
            case 5:
                cout << "\nGracias por usar el sistema ❤️" << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }

    } while (opcion != 5);
}
