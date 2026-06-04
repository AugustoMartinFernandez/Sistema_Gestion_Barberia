#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente() {
    // No hace falta poner nada aca adentro por ahora.
    // Al instanciar un Cliente , heredamos el constructor de Persona
}

void Cliente::cargar() {
    Persona::cargar();
}

void Cliente::mostrar() const {
    // VERIFICO QUE SE MUESTREN SOLO CLIENTES ACTIVOS
    if (_activo) {
        Persona::mostrar();
        cout << "-------------------------" << endl;
    }
}
