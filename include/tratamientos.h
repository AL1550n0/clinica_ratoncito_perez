#ifndef TRATAMIENTOS_H
#define TRATAMIENTOS_H
//.
struct Tratamiento {
    char duiPaciente[10];
    char medicamento[50];
    char dosis[30];
    char periodo[30];
};

void agregarTratamiento();
void buscarTratamiento();
void editarTratamiento();

#endif
