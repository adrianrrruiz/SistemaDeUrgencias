#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

using namespace std;

class Paciente {
public:
    Paciente(const string& nombre, const string& doc_identificacion, int edad, int triage);

    string nombre;
    string doc_identificacion;
    int edad;
    int triage;

    bool operator<(const Paciente& otroPaciente) {
        return triage < otroPaciente.triage; //Ordena ascendentemente
    }
};

#endif  // PACIENTE_H
