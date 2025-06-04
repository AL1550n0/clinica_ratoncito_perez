#ifndef TRATAMIENTOS_H
#define TRATAMIENTOS_H
struct Tratamiento {
    char duiPaciente[10];
    char nombreMedicamento[50];
    float dosis;
    int periodo;
};

void agregarTratamiento();
void buscarTratamiento();
void editarTratamiento();

#endif
