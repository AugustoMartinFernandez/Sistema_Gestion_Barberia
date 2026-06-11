#include <iostream>
#include <cstring>
#include "Persona.h"
#include "Barbero.h"
using namespace std;

Barbero::Barbero(){
    setEspecialidad("Sin Especialidad");
}

const char* Barbero::getEspecialidad() const {
    return _especialidad;
}

void Barbero::setEspecialidad(const char *especialidad){
    strncpy(_especialidad, especialidad, 49);
    _especialidad[49] = '\0';
}

void Barbero::cargar(){
    Persona::cargar();
    char EspecialidadAux[50];
    cout<<"Especialidad: ";
    cin.getline(EspecialidadAux, 50);
    setEspecialidad(EspecialidadAux);
}

void Barbero::mostrar() const {
    Persona::mostrar();
    cout<<"Especialidad: "<< _especialidad<<endl;
}
