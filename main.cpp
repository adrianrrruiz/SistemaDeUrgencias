#include <iostream>
#include "include\\Paciente.h"
#include "include\\Medico.h"
#include "include\\CentroMedico.h"

using namespace std;

int main() {
    CentroMedico centro_medico;

    int opcion;

    cout << "Opciones:" << endl;
    cout << "1. Agregar nuevo medico" << endl;
    cout << "2. Agregar paciente a consultorio" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            string nombre;
            int id_medico, edad;

            cout << "Ingrese el nombre del medico: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese el ID del medico: ";
            cin >> id_medico;

            cout << "Ingrese la edad del medico: ";
            cin >> edad;

            Medico medico(nombre, id_medico, edad);
            centro_medico.agregarNuevoMedico(medico);
            break;
        }
        case 2: {
            string nombre, doc_identificacion;
            int edad, triage, id_medico;

            cout << "Ingrese el nombre del paciente: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese el documento de identificacion del paciente: ";
            getline(cin, doc_identificacion);

            cout << "Ingrese la edad del paciente: ";
            cin >> edad;

            cout << "Ingrese el triage del paciente (1-5): ";
            cin >> triage;

            cout << "Ingrese el ID del medico asignado: ";
            cin >> id_medico;

            Paciente paciente(nombre, doc_identificacion, edad, triage);
            centro_medico.agregarPacienteAConsultorio(paciente, id_medico);
            break;
        }
        case 3:
            cout << "Programa finalizado" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
    return 0;
}

