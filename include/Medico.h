#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>
#include "Paciente.h"

using namespace std;

class Medico {
public:

    void agregarNuevoPaciente(const Paciente& paciente);
    Medico(const string& nombre, int id_medico, int edad);

    string nombre;
    int id_medico;
    int edad;
    vector<Paciente> lista_pacientes;
};

#endif  // MEDICO_H
