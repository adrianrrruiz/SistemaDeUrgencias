#ifndef CENTROMEDICO_H
#define CENTROMEDICO_H

#include <vector>
#include <queue>
#include <iostream>
#include "Medico.h"

using namespace std;

class CentroMedico {
public:
    void agregarNuevoMedico(const Medico& medico);
    void agregarPacienteAConsultorio(const Paciente& paciente, int id_medico);
    void imprimirAtendidos();
    vector<Medico> medicos_disponibles;
    queue<Paciente> atendidos;
};

#endif  // CENTROMEDICO_H

