#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente() {
    _puntosAcumulados = 0;
}

void Cliente::setPuntosAcumulados(int puntos) {
    if (puntos >= 0) {
        _puntosAcumulados = puntos;
    } else {
        _puntosAcumulados = 0;
    }
}

int Cliente::getPuntosAcumulados() const {
    return _puntosAcumulados;
}

void Cliente::sumarPuntos(int puntos) {
    if (puntos > 0) {
        _puntosAcumulados += puntos;
    }
}

void Cliente::restarPuntos(int puntos) {
    if (puntos > 0) {
        _puntosAcumulados -= puntos;
        // Nunca puede quedar en negativo
        if (_puntosAcumulados < 0) {
            _puntosAcumulados = 0;
        }
    }
}

void Cliente::cargar() {
    Persona::cargar();
}

void Cliente::mostrar() const {
    if (_activo) {
        Persona::mostrar();
        cout << "Puntos Acumulados: " << _puntosAcumulados << " pts" << endl;
        cout << "-------------------------" << endl;
    }
}
