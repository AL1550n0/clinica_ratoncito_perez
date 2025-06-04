#include <iostream>
#include "../include/pacientes.h"
#include "../include/inventario.h"
#include "../include/tratamientos.h"
#include "../include/citas.h"
#include "../include/menu.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    cout << "Bienvenido al Sistema Ratoncito Pérez ❤️\n";
    
    mostrarMenuPrincipal();
    
    cout << "\nPresiona ENTER para cerrar el programa...";
    cin.ignore();  
    cin.get();     

    return 0;
}
