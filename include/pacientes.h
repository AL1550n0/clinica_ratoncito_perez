#ifndef PACIENTES_H
#define PACIENTES_H

struct Paciente {
    char nombre[50];
    char dui[10];
    char fechaNacimiento[11];
    char comentarios[100];
};

void menuPacientes();
void agregarPaciente();
void buscarPaciente();
void editarPaciente();
void mostrarTodosPacientes();

#endif
