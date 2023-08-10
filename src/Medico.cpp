#include "..\\include\\Medico.h"
using namespace std;

void Medico::agregarNuevoPaciente(const Paciente& paciente) {
    lista_pacientes.push_back(paciente);
}

Medico::Medico(const string& nombre, int id_medico, int edad)
    : nombre(nombre), id_medico(id_medico), edad(edad) {}

