#include <iostream>
#include "../include/pacientes.h"
#include "../include/inventario.h"
#include "../include/tratamientos.h"
#include "../include/citas.h"
#include "../include/utilidades.h"
#include "../include/menu.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    cout << "Bienvenido al sistema Ratoncito Pérez 🐭\n\n";

    // Mostrar menú principal
    mostrarMenuPrincipal(); 
    return 0;
}
