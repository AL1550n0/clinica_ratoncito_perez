#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/tratamientos.h"
#include "../include/pacientes.h"
#include "../include/inventario.h"

using namespace std;



void menuTratamientos() {
    int opcion;
    do {
        cout << "\n=== GESTIÓN DE TRATAMIENTOS ===\n";
        cout << "1. Agregar Tratamiento\n";
        cout << "2. Buscar Tratamiento\n";
        cout << "3. Editar Tratamiento\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: agregarTratamiento(); break;
            case 2: buscarTratamiento(); break;
            case 3: editarTratamiento(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void agregarTratamiento() {
    Tratamiento t;
    cout << "\n--- AGREGAR TRATAMIENTO ---\n";
    cout << "DUI del paciente: "; cin.getline(t.duiPaciente, 10);
    cout << "Nombre del medicamento: "; cin.getline(t.nombreMedicamento, 50);
    cout << "Dosis (mg/unidades): "; cin >> t.dosis;
    cout << "Periodo (días): "; cin >> t.periodo;
    cin.ignore();

    // Validación de paciente y medicamento
    ifstream pacientesFile("data/pacientes.dat", ios::binary);
    bool pacienteExiste = false;
    Paciente p;

    while (pacientesFile.read(reinterpret_cast<char*>(&p), sizeof(Paciente))) {
        if (strcmp(p.dui, t.duiPaciente) == 0) {
            pacienteExiste = true;
            break;
        }
    }
    pacientesFile.close();

    if (!pacienteExiste) {
        cout << "Error: Paciente no encontrado.\n";
        return;
    }

    ifstream inventarioFile("data/inventario.dat", ios::binary);
    bool medicamentoExiste = false;
    Medicamento m;

    while (inventarioFile.read(reinterpret_cast<char*>(&m), sizeof(Medicamento))) {
        if (strcmp(m.nombre, t.nombreMedicamento) == 0) {
            medicamentoExiste = true;
            break;
        }
    }
    inventarioFile.close();

    if (!medicamentoExiste) {
        cout << "Error: Medicamento no encontrado.\n";
        return;
    }

    // Guardar tratamiento
    ofstream archivo("data/tratamientos.dat", ios::binary | ios::app);
    if (!archivo) {
        cout << "No se pudo abrir el archivo de tratamientos.\n";
        return;
    }
    archivo.write(reinterpret_cast<char*>(&t), sizeof(Tratamiento));
    archivo.close();
    cout << "Tratamiento registrado exitosamente.\n";
}

void buscarTratamiento() {
    ifstream archivo("data/tratamientos.dat", ios::binary);
    if (!archivo) {
        cout << "No se pudo acceder al archivo de tratamientos.\n";
        return;
    }

    char duiBuscado[10];
    cout << "\n--- BUSCAR TRATAMIENTO ---\n";
    cout << "Ingrese el DUI del paciente: ";
    cin.getline(duiBuscado, 10);

    Tratamiento t;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&t), sizeof(Tratamiento))) {
        if (strcmp(t.duiPaciente, duiBuscado) == 0) {
            cout << "\n--- TRATAMIENTO ENCONTRADO ---\n";
            cout << "DUI Paciente: " << t.duiPaciente << "\n";
            cout << "Medicamento: " << t.nombreMedicamento << "\n";
            cout << "Dosis: " << t.dosis << " mg/unidades\n";
            cout << "Periodo: " << t.periodo << " días\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontró tratamiento para este paciente.\n";
    }

    archivo.close();
}

void editarTratamiento() {
    fstream archivo("data/tratamientos.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No se pudo abrir el archivo de tratamientos.\n";
        return;
    }

    char duiBuscado[10];
    cout << "\n--- EDITAR TRATAMIENTO ---\n";
    cout << "Ingrese el DUI del paciente: ";
    cin.getline(duiBuscado, 10);

    Tratamiento t;
    bool encontrado = false;
    streampos posicion;

    while (archivo.read(reinterpret_cast<char*>(&t), sizeof(Tratamiento))) {
        if (strcmp(t.duiPaciente, duiBuscado) == 0) {
            encontrado = true;
            posicion = archivo.tellg() - static_cast<streampos>(sizeof(Tratamiento));
            break;
        }
    }

    if (encontrado) {
        cout << "\nIngrese los nuevos datos:\n";
        cout << "Nombre del medicamento: "; cin.getline(t.nombreMedicamento, 50);
        cout << "Dosis (mg/unidades): "; cin >> t.dosis;
        cout << "Periodo (días): "; cin >> t.periodo;
        cin.ignore();

        archivo.seekp(posicion);
        archivo.write(reinterpret_cast<char*>(&t), sizeof(Tratamiento));
        cout << "Tratamiento actualizado correctamente.\n";
    } else {
        cout << "Tratamiento no encontrado.\n";
    }

    archivo.close();
}
