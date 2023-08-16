#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

using namespace std;

class Paciente {
public:
    Paciente(const string& nombre, const string& doc_identificacion, int edad, int triage);
    Paciente();
    string nombre;
    string doc_identificacion;
    int edad;
    int triage;

    bool operator<(const Paciente& otroPaciente) const {
        return triage > otroPaciente.triage; //Ordena ascendentemente
    }
};

#endif  // PACIENTE_H
