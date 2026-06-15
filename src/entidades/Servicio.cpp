#include <iostream>
#include <cstring>
#include "Servicio.h"

using namespace std;

// Constructor por defecto
Servicio::Servicio() {
    _id = 0;
    strcpy(_descripcion, "Sin descripcion");
    _precio = 0.0f;
    _activo = false;
    _puntosQueOtorga = 0;
}

void Servicio::setId(int id) {
    _id = id;
}

void Servicio::setDescripcion(const char* descripcion) {
    strncpy(_descripcion, descripcion, 49);
    _descripcion[49] = '\0'; // Aseguramos que siempre termine con el caracter nulo
}

void Servicio::setPrecio(float precio) {
    _precio = precio;
}

void Servicio::setActivo(bool activo) {
    _activo = activo;
}
void Servicio::setPuntosQueOtorga(int puntos) {
    _puntosQueOtorga = puntos;
}

int Servicio::getId() const {
    return _id;
}

const char* Servicio::getDescripcion() const {
    return _descripcion;
}

float Servicio::getPrecio() const {
    return _precio;
}

bool Servicio::getActivo() const {
    return _activo;
}
int Servicio::getPuntosQueOtorga() const {
    return _puntosQueOtorga;
}

void Servicio::cargar() {
    char descAux[50];

    cout << endl << "Descripcion del servicio (ej. Corte Clasico): ";
    cin.getline(descAux, 50);
    setDescripcion(descAux);

    cout << endl << "Precio del servicio: $";
    cin >> _precio;

    cout << "Puntos que otorga: ";
    cin >> _puntosQueOtorga;

    _activo = true;
}

void Servicio::mostrar() const {
    if (_activo) {
        cout << "ID Servicio: " << _id << endl;
        cout << "Descripcion: " << _descripcion << endl;
        cout << "Precio     : $" << _precio << endl;
        cout << "Puntos     : +" << _puntosQueOtorga << " pts" << endl;
        cout << "-------------------------" << endl;
    }
}
