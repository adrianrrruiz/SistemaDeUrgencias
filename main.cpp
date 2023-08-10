#include <iostream>
#include "include\\Paciente.h"
#include "include\\Medico.h"
#include "include\\CentroMedico.h"
#include <fstream>
#include <sstream>

using namespace std;

void leerArchivo(CentroMedico &centro_medico);

int main() {
    CentroMedico centro_medico;
    leerArchivo(centro_medico);

    for(Medico medico : centro_medico.medicos_disponibles){
        cout << medico.nombre << endl;
    }

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

void leerArchivo(CentroMedico &centro_medico){
       int x = 0;

    ifstream inputFile("files\\informacion.txt");

    if (!inputFile) {
        cerr << "Error al abrir el archivo." << endl;
    }

    string linea;
    while (getline(inputFile, linea)) {
        if (linea == "@") {
            if (getline(inputFile, linea)) {
                istringstream iss(linea);
                string Nombre;
		int ID;
                int edad;

                getline(iss, Nombre, ',');
                iss >> ID;
                iss.ignore();
                iss >> edad;

		Medico medico = {Nombre,ID,edad};
		centro_medico.agregarNuevoMedico(medico);

                getline(inputFile, linea);
                while (linea != "@") {
                    istringstream issPaciente(linea);
                    string nombre;
                    string ID;
                    int edad;
                    int triage;

                    getline(issPaciente, nombre, ',');
		    getline(issPaciente, ID, ',');
                    issPaciente >> edad;
                    issPaciente.ignore();
                    issPaciente >> triage;

		    Paciente paciente ={nombre,ID,edad,triage};
		    centro_medico.medicos_disponibles[x].agregarNuevoPaciente(paciente);

                    getline(inputFile, linea);
                }

                x++;
            }
        }
    }

    inputFile.close();
}
