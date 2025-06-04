#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/pacientes.h"
#include <windows.h>
<<<<<<< HEAD
#include <limits>

using namespace std;

void menuPacientes();
void agregarPaciente();
void buscarPaciente();
void editarPaciente();
void mostrarTodosPacientes(); // Opcional para depuración
=======
using namespace std;



int main() {
    SetConsoleOutputCP(6500)
    menuPacientes(); 
    return 0;
}
>>>>>>> 2f6fe130eab62bb5a7a37fe2c35154ecbd40a915

void menuPacientes() {
    int opcion;
    do {
        cout << "\n=== CLÍNICA RATONCITO PÉREZ - GESTIÓN DE PACIENTES ===\n";
        cout << "1. Agregar Paciente\n";
        cout << "2. Buscar Paciente\n";
        cout << "3. Editar Paciente\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
<<<<<<< HEAD

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Por favor ingrese un número.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer tras leer int
=======
        cin >> opcion;
        cin.ignore();
>>>>>>> 2f6fe130eab62bb5a7a37fe2c35154ecbd40a915

        switch(opcion) {
            case 1: agregarPaciente(); break;
            case 2: buscarPaciente(); break;
            case 3: editarPaciente(); break;
            case 0: break;
            default: cout << "Opción inválida.\n"; break;
        }
    } while(opcion != 0);
}

void agregarPaciente() {
    Paciente p;
<<<<<<< HEAD
    memset(&p, 0, sizeof(Paciente));

    CreateDirectoryA("data", NULL);
=======
>>>>>>> 2f6fe130eab62bb5a7a37fe2c35154ecbd40a915
    ofstream archivo("data/pacientes.dat", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error al abrir el archivo de pacientes.\n";
        return;
    }

    cout << "\n--- AGREGAR PACIENTE ---\n";

    cout << "Nombre: ";
    cin.getline(p.nombre, 50);

    while (true) {
        cout << "DUI (sin guiones, 9 dígitos): ";
        cin.getline(p.dui, 10);

        if (strlen(p.dui) != 9) {
            cout << "Error: El DUI debe tener exactamente 9 dígitos.\n";
        } else {
            break;
        }
    }

    cout << "Fecha de Nacimiento (DD/MM/AAAA): ";
    cin.getline(p.fechaNacimiento, 11);

    cout << "Comentarios de Salud: ";
    cin.getline(p.comentarios, 100);

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
    memset(duiBuscado, 0, sizeof(duiBuscado));

    cout << "\n--- BUSCAR PACIENTE ---\n";

    cout << "Ingrese el DUI del paciente (sin guiones): ";
    cin.getline(duiBuscado, 10);

    Paciente p;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (strncmp(p.dui, duiBuscado, 9) == 0) {
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
    memset(duiBuscado, 0, sizeof(duiBuscado));

    cout << "\n--- EDITAR PACIENTE ---\n";
    cout << "Ingrese el DUI del paciente a editar (sin guiones): ";
    cin.getline(duiBuscado, 10);

    Paciente p;
    bool encontrado = false;
    streampos posicion;

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (strncmp(p.dui, duiBuscado, 9) == 0) {
            encontrado = true;
            posicion = archivo.tellg() - static_cast<streampos>(sizeof(Paciente));
            break;
        }
    }

    if (encontrado) {
        cout << "\nDatos actuales del paciente:\n";
        cout << "Nombre: " << p.nombre << "\n";
        cout << "DUI: " << p.dui << "\n";
        cout << "Fecha de Nacimiento: " << p.fechaNacimiento << "\n";
        cout << "Comentarios: " << p.comentarios << "\n";

        cout << "\nIngrese los nuevos datos del paciente:\n";

        cout << "Nombre: ";
        cin.getline(p.nombre, 50);

        cout << "Fecha de Nacimiento (DD/MM/AAAA): ";
        cin.getline(p.fechaNacimiento, 11);

        cout << "Comentarios de Salud: ";
        cin.getline(p.comentarios, 100);

        archivo.seekp(posicion);
        archivo.write(reinterpret_cast<char*>(&p), sizeof(Paciente));

        cout << "Datos del paciente actualizados correctamente.\n";
    } else {
        cout << "Paciente no encontrado con el DUI proporcionado.\n";
    }

    archivo.close();
}

// Opcional: mostrar todos los pacientes guardados (para pruebas)
void mostrarTodosPacientes() {
    ifstream archivo("data/pacientes.dat", ios::binary);
    if (!archivo) {
        cout << "No se pudo acceder al archivo de pacientes.\n";
        return;
    }

    Paciente p;
    int contador = 0;

    cout << "\n--- LISTA DE TODOS LOS PACIENTES ---\n";

    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        cout << "\nPaciente " << ++contador << ":\n";
        cout << "Nombre: " << p.nombre << "\n";
        cout << "DUI: " << p.dui << "\n";
        cout << "Fecha de Nacimiento: " << p.fechaNacimiento << "\n";
        cout << "Comentarios: " << p.comentarios << "\n";
    }

    if (contador == 0) {
        cout << "No hay pacientes registrados.\n";
    }

    archivo.close();
}
