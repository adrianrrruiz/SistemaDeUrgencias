#include "..\\include\\CentroMedico.h"
using namespace std;

void CentroMedico::agregarNuevoMedico(const Medico& medico) {
    medicos_disponibles.push_back(medico);
}

void CentroMedico::agregarPacienteAConsultorio(const Paciente& paciente, int id_medico) {
    for (auto& medico : medicos_disponibles) {
        if (medico.id_medico == id_medico) {
            medico.agregarNuevoPaciente(paciente);
            break;
        }
    }
}

Paciente CentroMedico::siguientePaciente(int id_medico){   
    Paciente pacienteAtendido;
    for (auto& medico : medicos_disponibles) {
        if (medico.id_medico == id_medico) {
            if(medico.lista_pacientes.size() > 0){
                pacienteAtendido = medico.lista_pacientes.front();
                atendidos.push(pacienteAtendido);
                medico.lista_pacientes.pop();
                return pacienteAtendido;
            }
            else{
                pacienteAtendido.edad = -1;
                return pacienteAtendido;
            }
        }
    }
}

void CentroMedico::agregarPacientePrioritario(const Paciente& paciente){
    cola_de_prioridad.push(paciente);
}

Paciente CentroMedico::atenderPacientePrioritario(){
    atendidos.push(cola_de_prioridad.top());
    cola_de_prioridad.pop();
    return cola_de_prioridad.top();
}

void CentroMedico::imprimirAtendidos(){
    int pacienteNum = 1;
    queue<Paciente> aux = atendidos;
    while (!aux.empty()){
        Paciente paciente = aux.front();
        cout << "\n\n===== PACIENTE #" << pacienteNum << " =====" << endl; 
        cout << "Nombre: " << paciente.nombre << endl;
        cout << "No. Identificacion: " << paciente.doc_identificacion << endl;
        cout << "Edad: " << paciente.edad << endl;
        cout << "Clasificacion en el triage: " << paciente.triage << endl;
        aux.pop();
        pacienteNum++;
    }
}

void CentroMedico::imprimirPaciente(const Paciente& paciente){
        cout << "Nombre: " << paciente.nombre << endl;
        cout << "No. Identificacion: " << paciente.doc_identificacion << endl;
        cout << "Edad: " << paciente.edad << endl;
        cout << "Clasificacion en el triage: " << paciente.triage << endl;
}