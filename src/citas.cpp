#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/citas.h"
using namespace std;

void menuCitas() {
    int opcion;
    do {
        cout << "\n=== GESTIÓN DE CITAS ===\n";
        cout << "1. Agregar cita\n";
        cout << "2. Buscar cita\n";
        cout << "3. Editar cita\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: agregarCita(); break;
            case 2: buscarCita(); break;
            case 3: editarCita(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}


void agregarCita() {
    Cita c;
    cin.ignore();
    cout << "DUI (8 digitos): ";
    cin.getline(c.dui, 10);
    cout << "Nombre del paciente: ";
    cin.getline(c.nombrePaciente, 50);
    cout << "Tratamiento: ";
    cin.getline(c.tratamiento, 50);
    cout << "Fecha (DD/MM/AAAA): ";
    cin.getline(c.fecha, 11);
    cout << "Hora (HH:MM): ";
    cin.getline(c.hora, 6);

    ifstream file("bin/citas.dat", ios::binary);
    Cita temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Cita))) {
        if (strcmp(temp.fecha, c.fecha) == 0 && strcmp(temp.hora, c.hora) == 0) {
            cout << "Ya existe una cita registrada en esa fecha y hora.\n";
            file.close();
            return;
        }
    }
    file.close();

    ofstream out("bin/citas.dat", ios::binary | ios::app);
    out.write(reinterpret_cast<char*>(&c), sizeof(Cita));
    out.close();
    cout << "Cita registrada con exito.\n";
}

void buscarCita() {
    char dui[10];
    cin.ignore();
    cout << "Ingrese el DUI del paciente: ";
    cin.getline(dui, 10);

    ifstream file("bin/citas.dat", ios::binary);
    Cita c;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&c), sizeof(Cita))) {
        if (strcmp(c.dui, dui) == 0) {
            cout << "DUI: " << c.dui << ", Paciente: " << c.nombrePaciente << ", Tratamiento: " << c.tratamiento
                << ", Fecha: " << c.fecha << ", Hora: " << c.hora << endl;
            found = true;
        }
    }
    file.close();
    if (!found) cout << "No se encontro ninguna cita con ese DUI.\n";
}

void editarCita() {
    char dui[10];
    cin.ignore();
    cout << "Ingrese el DUI del paciente para editar la cita: ";
    cin.getline(dui, 10);

    fstream archivo("bin/citas.dat", ios::binary | ios::in | ios::out);
    Cita c;
    bool found = false;
    while (archivo.read(reinterpret_cast<char*>(&c), sizeof(Cita))) {
        if (strcmp(c.dui, dui) == 0) {
            cout << "Nuevo tratamiento: ";
            cin.getline(c.tratamiento, 50);
            cout << "Nueva fecha: ";
            cin.getline(c.fecha, 11);
            cout << "Nueva hora: ";
            cin.getline(c.hora, 6);

            archivo.seekp(-static_cast<int>(sizeof(Cita)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&c), sizeof(Cita));
            cout << "Cita actualizada correctamente.\n";
            found = true;
            break;
        }
    }
    archivo.close();
    if (!found) cout << "Cita no encontrada.\n";
}
