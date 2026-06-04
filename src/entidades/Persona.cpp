#include "Persona.h"
#include <iostream>
#include <cstring>

using namespace std;

Persona::Persona() {
    _id = 0;
    strcpy(_nombre, "Sin Nombre");
    strcpy(_apellido, "Sin Apellido");
    strcpy(_domicilio, "Sin Domicilio");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _activo = false;
}

// Setters
void Persona::setId(int id) {
     _id = id;
}
void Persona::setNombre(const char* nombre) {
    strncpy(_nombre, nombre, 29);
     _nombre[29] = '\0';
}
void Persona::setApellido(const char* apellido) {
     strncpy(_apellido, apellido, 29);
    _apellido[29] = '\0';
}
void Persona::setDomicilio(const char* domicilio){
    strncpy(_domicilio, domicilio, 49);
    _domicilio[49] = '\0';
}
void Persona::setTelefono(const char* telefono) {
    strncpy(_telefono, telefono, 19);
    _telefono[19] = '\0';
}
void Persona::setEmail(const char* email) {
     strncpy(_email, email, 49);
     _email[49] = '\0';
}
void Persona::setActivo(bool activo){
    _activo = activo;
}

// Getters
int Persona::getId() const { return _id; }
const char* Persona::getNombre() const { return _nombre; }
const char* Persona::getApellido() const { return _apellido; }
const char* Persona::getDomicilio() const { return _domicilio;}
const char* Persona::getTelefono() const { return _telefono; }
const char* Persona::getEmail() const { return _email; }
bool Persona::getActivo() const {return _activo;}


void Persona::cargar(){
    char nombreAux[30];
    char apellidoAux[30];
    char domicilioAux[50];
    char telefonoAux[20];
    char emailAux[50];

    cout << "Nombre: ";
    cin.getline(nombreAux, 30);
    setNombre(nombreAux);

    cout << "Apellido: ";
    cin.getline(apellidoAux, 30);
    setApellido(apellidoAux);

    cout << "Domicilio: ";
    cin.getline(domicilioAux, 50);
    setDomicilio(domicilioAux);

    cout << "Telefono: ";
    cin.getline(telefonoAux, 20);
    setTelefono(telefonoAux);

    cout << "Email: ";
    cin.getline(emailAux, 50);
    setEmail(emailAux);
    setActivo(true);
}

void Persona::mostrar() const {
    if (_activo) {
        cout << "ID: " << _id << endl;
        cout << "Nombre Completo: " << _apellido << ", " << _nombre << endl;
        cout << "Domicilio: " << _domicilio <<endl;
        cout << "Telefono: " << _telefono << endl;
        cout << "Email: " << _email << endl;
    }
}
