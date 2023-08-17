#include <iostream>
#include "include\\Paciente.h"
#include "include\\Medico.h"
#include "include\\CentroMedico.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void leerMedicos(CentroMedico &centroMedico);
void leerPacientes(CentroMedico &centroMedico);
void menu(CentroMedico &centroMedico);

int main() {
    srand(time(NULL));
    CentroMedico centro_medico;
    leerMedicos(centro_medico);
    leerPacientes(centro_medico);
    
    menu(centro_medico);
    return 0;
}

void menu(CentroMedico &centroMedico){
    int opcion;
    
    do {
        system("cls");
        cout << "===== Bienvenido al SISTEMA DE URGENCIAS =====\n";
        cout << "1. Agregar nuevo medico\n";
        cout << "2. Agregar paciente a consultorio\n";
        cout << "3. Atender un paciente\n";
        cout << "4. Imprimir Atendidos\n";
        cout << "5. Cerrar\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int id_medico, edad;
                system("cls");
                cout << "===== AGREGAR NUEVO MEDICO =====\n";
                cout << "Ingrese el nombre del medico: ";
                cin.ignore();
                getline(cin, nombre);

                cout << "Ingrese el ID del medico: ";
                cin >> id_medico;

                cout << "Ingrese la edad del medico: ";
                cin >> edad;

                Medico medico(nombre, id_medico, edad);
                centroMedico.agregarNuevoMedico(medico);
                break;
            }
            case 2: {
                string nombre, doc_identificacion;
                int edad, triage, id_medico;
                system("cls");
                cout << "===== AGREGAR PACIENTE A CONSULTORIO =====\n";
                cout << "Ingrese el nombre del paciente: ";
                cin.ignore();
                getline(cin, nombre);

                cout << "Ingrese el documento de identificacion del paciente: ";
                getline(cin, doc_identificacion);

                cout << "Ingrese la edad del paciente: ";
                cin >> edad;

                cout << "Ingrese el triage del paciente (1-5): ";
                cin >> triage;

                Paciente paciente(nombre, doc_identificacion, edad, triage);
                if(triage<4){
                    centroMedico.agregarPacientePrioritario(paciente);
                }
                else{
                    cout << "Ingrese el ID del medico asignado: ";
                    cin >> id_medico;
                    centroMedico.agregarPacienteAConsultorio(paciente, id_medico);
                }
                break;
            }
            case 3:{
                int TP, ID;
                Paciente pacienteProximoAtender;
                system("cls");
                cout << "===== ATENDER PACIENTE =====\n";
                cout << "Que tipo de paciente desea atender?\n"; 
                cout << "1: Prioritario\n";
                cout << "2: No prioritario\n";
                cout << "Ingrese una opcion: ";
                cin >> TP;

                switch(TP){

                    case 1:{
                        pacienteProximoAtender=centroMedico.atenderPacientePrioritario();
                        cout << "===== SIGUIENTE PACIENTE A ATENDER =====\n"; 
                        centroMedico.imprimirPaciente(pacienteProximoAtender);
                        system("pause");
                        break;
                    }
                    
                    case 2:{                                                
                        cout << "Escriba la identificacion del medico que atendera al paciente: ";
                        cin >> ID;
                        bool existeMedico = false;
                        for(Medico medico: centroMedico.medicos_disponibles){
                            if(medico.id_medico == ID){
                                existeMedico = true;
                            }
                        }
                        if(existeMedico){
                            pacienteProximoAtender = centroMedico.siguientePaciente(ID);
                        }
                        
                        if(pacienteProximoAtender.edad == -1 || existeMedico == false){
                            cout<< "----- El medico no tiene pacientes en su lista de espera -----\n";
                            system("pause");
                        }
                        else{
                            cout << "===== PACIENTE ATENDIDO" << " =====" << endl;
                            centroMedico.imprimirPaciente(pacienteProximoAtender);
                            system("pause");
                        }
                        break;   
                    }
                    
                    default:
                    cout << "Opcion invalida\n"; 
                }
                break;
            }
            case 4:
                centroMedico.imprimirAtendidos();
                system("pause");
            case 5:
                break;
            default:
                cout << "Opcion invalida\n"; 
        }
    }while(opcion !=5);
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
        file.close();
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
             int num = rand() % centroMedico.medicos_disponibles.size();
            getline(file, linea);
            istringstream isPaciente(linea);
            getline(isPaciente, nombre, ',');
            getline(isPaciente, ID, ',');
            isPaciente >> edad;
            isPaciente.ignore();
            isPaciente >> triage;
            Paciente paciente = {nombre,ID,edad,triage};
            if(paciente.triage == 1 || paciente.triage == 2 || paciente.triage == 3){
                centroMedico.agregarPacientePrioritario(paciente);//Añadir a cola de prioridad
            }else if(paciente.triage == 4 || paciente.triage == 5){
                centroMedico.medicos_disponibles[num].agregarNuevoPaciente(paciente);
            }
        }
        file.close();
    }else {
        cout << "No se pudo leer el archivo!\n";
    }
}
