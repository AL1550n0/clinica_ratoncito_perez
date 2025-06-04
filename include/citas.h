#ifndef CITAS_H
#define CITAS_H

struct Cita {
    char dui[10];
    char nombrePaciente[50];
    char tratamiento[50];
    char fecha[11]; // DD/MM/AAAA
    char hora[6];   // HH:MM
};

void agregarCita();
void buscarCita();
void editarCita();

#endif
