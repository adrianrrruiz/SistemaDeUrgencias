#ifndef CENTROMEDICO_H
#define CENTROMEDICO_H

#include <vector>
#include <queue>
#include <iostream>
#include "Medico.h"
#include "Paciente.h"

using namespace std;

class CentroMedico {
public:
    void agregarNuevoMedico(const Medico& medico);
    void agregarPacienteAConsultorio(const Paciente& paciente, int id_medico);
    Paciente siguientePaciente(int id_medico);
    void agregarPacientePrioritario(const Paciente& paciente);
    Paciente atenderPacientePrioritario();
    void imprimirAtendidos();
    vector<Medico> medicos_disponibles;
    queue<Paciente> atendidos;
    priority_queue<Paciente> cola_de_prioridad;
};

#endif  // CENTROMEDICO_H

