#include <iostream>
#include "Persona.h"
#include "Fecha.h"
#include "Hora.h"
using namespace std;

int main() {
    Fecha fecha;
    Hora hora;
    Persona persona;

    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout << "=== Cargar Persona ===" <<endl;
    persona.cargar();
    cout << endl;
    persona.mostrar();
    return 0;
}
