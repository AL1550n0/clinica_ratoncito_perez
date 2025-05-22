#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/inventario.h"  

using namespace std;

void menuInventario() {
    int opcion;
    do {
        cout << "\n=== GESTIÓN DE INVENTARIO ===\n";
        cout << "1. Agregar Medicamento\n";
        cout << "2. Buscar Medicamento\n";
        cout << "3. Editar Medicamento\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: agregarMedicamento(); break;
            case 2: buscarMedicamento(); break;
            case 3: editarMedicamento(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void agregarMedicamento() {
    Medicamento m;
    ofstream archivo("data/inventario.dat", ios::binary | ios::app);

    if (!archivo) {
        cout << "No se pudo abrir el archivo de inventario.\n";
        return;
    }

    cout << "\nNombre del medicamento: ";
    cin.getline(m.nombre, 50);
    cout << "Cantidad: ";
    cin >> m.cantidad;
    cout << "Precio: ";
    cin >> m.precio;
    cin.ignore();

    archivo.write(reinterpret_cast<char*>(&m), sizeof(Medicamento));
    archivo.close();
    cout << "Medicamento agregado exitosamente.\n";
}

void buscarMedicamento() {
    ifstream archivo("data/inventario.dat", ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo de inventario.\n";
        return;
    }

    char nombreBuscado[50];
    cout << "\nNombre del medicamento a buscar: ";
    cin.getline(nombreBuscado, 50);

    Medicamento m;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&m), sizeof(Medicamento))) {
        if (strcmp(m.nombre, nombreBuscado) == 0) {
            cout << "\n--- MEDICAMENTO ENCONTRADO ---\n";
            cout << "Nombre: " << m.nombre << "\n";
            cout << "Cantidad: " << m.cantidad << "\n";
            cout << "Precio: $" << m.precio << "\n";

            if (m.cantidad < 5) {
                cout << "¡Advertencia! El stock está bajo.\n";
            }

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Medicamento no encontrado.\n";
    }

    archivo.close();
}

void editarMedicamento() {
    fstream archivo("data/inventario.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No se pudo abrir el archivo de inventario.\n";
        return;
    }

    char nombreBuscado[50];
    cout << "\nNombre del medicamento a editar: ";
    cin.getline(nombreBuscado, 50);

    Medicamento m;
    bool encontrado = false;
    streampos posicion;

    while (archivo.read(reinterpret_cast<char*>(&m), sizeof(Medicamento))) {
        if (strcmp(m.nombre, nombreBuscado) == 0) {
            encontrado = true;
            posicion = archivo.tellg() - static_cast<streampos>(sizeof(Medicamento));
            break;
        }
    }

    if (encontrado) {
        cout << "\nIngrese los nuevos datos:\n";
        cout << "Nombre: "; cin.getline(m.nombre, 50);
        cout << "Cantidad: "; cin >> m.cantidad;
        cout << "Precio: "; cin >> m.precio;
        cin.ignore();

        archivo.seekp(posicion);
        archivo.write(reinterpret_cast<char*>(&m), sizeof(Medicamento));
        cout << "Medicamento actualizado correctamente.\n";
    } else {
        cout << "Medicamento no encontrado.\n";
    }

    archivo.close();
}

void restarStock(const char* nombre, int cantidadUsada) {
    fstream archivo("data/inventario.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No se pudo abrir el archivo de inventario.\n";
        return;
    }

    Medicamento m;
    bool encontrado = false;
    streampos posicion;

    while (archivo.read(reinterpret_cast<char*>(&m), sizeof(Medicamento))) {
        if (strcmp(m.nombre, nombre) == 0) {
            encontrado = true;
            posicion = archivo.tellg() - static_cast<streampos>(sizeof(Medicamento));
            break;
        }
    }

    if (encontrado) {
        if (m.cantidad >= cantidadUsada) {
            m.cantidad -= cantidadUsada;
            archivo.seekp(posicion);
            archivo.write(reinterpret_cast<char*>(&m), sizeof(Medicamento));
            cout << "Stock actualizado.\n";

            if (m.cantidad < 5) {
                cout << "¡Advertencia! El stock del medicamento '" << m.nombre << "' es bajo.\n";
            }

        } else {
            cout << "No hay suficiente stock disponible.\n";
        }
    } else {
        cout << "Medicamento no encontrado.\n";
    }

    archivo.close();
}
