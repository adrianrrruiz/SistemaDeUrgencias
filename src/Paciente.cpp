#include "..\\include\\Paciente.h"
using namespace std;

Paciente::Paciente(const string& nombre, const string& doc_identificacion, int edad, int triage)
    : nombre(nombre), doc_identificacion(doc_identificacion), edad(edad), triage(triage) {}

Paciente::Paciente(){}

