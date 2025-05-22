#ifndef INVENTARIO_H
#define INVENTARIO_H

struct Medicamento {
    char nombre[50];
    int cantidad;
    float precio;
};

// Menú de opciones
void menuInventario();

// Funciones principales
void agregarMedicamento();
void buscarMedicamento();
void editarMedicamento();
void restarStock(const char* nombre, int cantidadUsada);

#endif
