#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/pacientes.h"
#include <windows.h>
#include <limits>
using namespace std;


void menuPacientes() {
    int opcion;
    do {
        cout << "\n=== CLÍNICA RATONCITO PÉREZ - GESTIÓN DE PACIENTES ===\n";
        cout << "1. Agregar Paciente\n";
        cout << "2. Buscar Paciente\n";
        cout << "3. Editar Paciente\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opcion) {
            case 1: agregarPaciente(); break;
            case 2: buscarPaciente(); break;
            case 3: editarPaciente(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while(opcion != 0);
}

void agregarPaciente() {
    Paciente p;
    // Crear la carpeta "data" si no existe
    CreateDirectoryA("data", NULL);
    ofstream archivo("data/pacientes.dat", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error al abrir el archivo de pacientes.\n";
        return;
    }

    cout << "\n--- CLÍNICA RATONCITO PÉREZ - AGREGAR PACIENTE ---\n";
    cout << "Nombre: "; cin.getline(p.nombre, 50);
    cout << "DUI: "; cin.getline(p.dui, 10);
    cout << "Fecha de Nacimiento (DD/MM/AAAA): "; cin.getline(p.fechaNacimiento, 11);
    cout << "Comentarios de Salud: "; cin.getline(p.comentarios, 100);

    archivo.write(reinterpret_cast<char*>(&p), sizeof(Paciente));
    archivo.close();
    cout << "Paciente registrado exitosamente.\n";
}

void buscarPaciente() {
    ifstream archivo("data/pacientes.dat", ios::binary);
    if (!archivo) {
        cout << "No se pudo acceder al archivo de pacientes.\n";
        return;
    }

    char duiBuscado[10];
    cout << "\n--- CLÍNICA RATONCITO PÉREZ - BUSCAR PACIENTE ---\n";
    cout << "Ingrese el DUI del paciente: ";
    cin.getline(duiBuscado, 10);

    Paciente p;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (strcmp(p.dui, duiBuscado) == 0) {
            cout << "\n--- PACIENTE ENCONTRADO ---\n";
            cout << "Nombre: " << p.nombre << "\n";
            cout << "DUI: " << p.dui << "\n";
            cout << "Fecha de Nacimiento: " << p.fechaNacimiento << "\n";
            cout << "Comentarios de Salud: " << p.comentarios << "\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró ningún paciente con ese DUI.\n";
    }

    archivo.close();
}

void editarPaciente() {
    fstream archivo("data/pacientes.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No se pudo abrir el archivo de pacientes para edición.\n";
        return;
    }

    char duiBuscado[10];
    cout << "\n--- CLÍNICA RATONCITO PÉREZ - EDITAR PACIENTE ---\n";
    cout << "Ingrese el DUI del paciente a editar: ";
    cin.getline(duiBuscado, 10);

    Paciente p;
    bool encontrado = false;
    streampos posicion;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (strcmp(p.dui, duiBuscado) == 0) {
            encontrado = true;
            posicion = archivo.tellg() - static_cast<streampos>(sizeof(Paciente));
            break;
        }
    }

    if (encontrado) {
        cout << "\nIngrese los nuevos datos del paciente:\n";
        cout << "Nombre: "; cin.getline(p.nombre, 50);
        cout << "Fecha de Nacimiento (DD/MM/AAAA): "; cin.getline(p.fechaNacimiento, 11);
        cout << "Comentarios de Salud: "; cin.getline(p.comentarios, 100);

        archivo.seekp(posicion);
        archivo.write(reinterpret_cast<char*>(&p), sizeof(Paciente));
        cout << "Datos del paciente actualizados correctamente.\n";
    } else {
        cout << "Paciente no encontrado con el DUI proporcionado.\n";
    }

    archivo.close();
}
