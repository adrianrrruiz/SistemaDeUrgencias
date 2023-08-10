#ifndef CENTROMEDICO_H
#define CENTROMEDICO_H

#include <vector>
#include "Medico.h"

using namespace std;

class CentroMedico {
public:
    void agregarNuevoMedico(const Medico& medico);
    void agregarPacienteAConsultorio(const Paciente& paciente, int id_medico);

private:
    vector<Medico> medicos_disponibles;
};

#endif  // CENTROMEDICO_H

