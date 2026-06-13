#pragma once
#include <string>
#include "Turno.h"

class ArchivoTurnos{
private:
    std::string _nombreArchivo;

public:
    ArchivoTurnos();
    ArchivoTurnos(std::string nombreArchivo);

// Dar de alta Clientes
bool guardar(Turno reg);
// Modificacion/Baja de Clientes
bool guardar(Turno reg, int pos);
// Leer Clientes
Turno leer(int pos);
// Buscar Clientes por ID
int buscar(int idTurno);
// Medimos el tamaño del cliente
int cantidadRegistros();
};
