#pragma once
#include <string>
#include "Turno.h"

class ArchivoTurnos{
private:
    std::string _nombreArchivo;

public:
ArchivoTurnos();
ArchivoTurnos(std::string nombreArchivo);

// Dar de alta
bool guardar(Turno reg);

// Modificacion/Baja
bool guardar(Turno reg, int pos);

// Leer
Turno leer(int pos);

// Buscar por ID
int buscar(int idTurno);

// Medimos el tamaño
int cantidadRegistros();
};
