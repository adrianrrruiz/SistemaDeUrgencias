#include "CentroMedico.h"
using namespace std;

void CentroMedico::agregarNuevoMedico(const Medico& medico) {
    medicos_disponibles.push_back(medico);
}

void CentroMedico::agregarPacienteAConsultorio(const Paciente& paciente, int id_medico) {
    for (auto& medico : medicos_disponibles) {
        if (medico.id_medico == id_medico) {
            medico.lista_pacientes.push_back(paciente);
            break;
        }
    }
}

