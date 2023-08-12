#include <iostream>
#include "include\\Paciente.h"
#include "include\\Medico.h"
#include "include\\CentroMedico.h"
#include <fstream>
#include <sstream>

using namespace std;

void leerMedicos(CentroMedico &centroMedico);
void leerPacientes(CentroMedico &centroMedico);

int main() {
    CentroMedico centro_medico;
    leerPacientes(centro_medico);
    leerMedicos(centro_medico);

    int opcion;

    cout << "===== Bienvenido al SISTEMA DE URGENCIAS =====\n";
    cout << "1. Agregar nuevo medico\n";
    cout << "2. Agregar paciente a consultorio\n";
    cout << "3. Salir\n";
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
            cout << "Programa finalizado\n"; 
            break;
        default:
            cout << "Opcion invalida\n"; 
    }
    return 0;
}

void leerMedicos(CentroMedico &centroMedico){
    ifstream file("files\\medicos.txt");
    string linea, nombre;
    int ID, edad;

    if(file){
        while(!file.eof()){
            getline(file, linea);
            istringstream isMedico(linea);
            getline(isMedico, nombre, ',');
            isMedico >> ID;
            isMedico.ignore();
            isMedico >> edad;
            Medico medico = {nombre,ID,edad};
            centroMedico.agregarNuevoMedico(medico);
        }
    }else{
        cout << "No se pudo leer el archivo!\n";
    }
}

void leerPacientes(CentroMedico &centroMedico){
    ifstream file("files\\pacientes.txt");
    string linea, nombre, ID;
    int edad, triage;

    if(file){
        while(!file.eof()){
            getline(file, linea);
            istringstream isPaciente(linea);
            getline(isPaciente, nombre, ',');
            getline(isPaciente, ID, ',');
            isPaciente >> edad;
            isPaciente.ignore();
            isPaciente >> triage;
            Paciente paciente = {nombre,ID,edad,triage};
            if(paciente.triage == 1 || paciente.triage == 2 || paciente.triage == 3){
                //Añadir a cola de prioridad
            }else if(paciente.triage == 4 || paciente.triage == 5){
                //Añadir a la lista de pacientes de algún médico
            }
        }
    }else {
        cout << "No se pudo leer el archivo!\n";
    }
}
