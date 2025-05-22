#ifndef CITAS_H
#define CITAS_H

struct Cita {
    char duiPaciente[10];
    char tratamiento[50];
    char fecha[11];
    char hora[6];
};

void agregarCita();
void buscarCita();
void editarCita();

#endif
