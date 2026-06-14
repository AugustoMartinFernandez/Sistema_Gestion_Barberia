#pragma once
#include <string>
#include "Turno.h"

class ArchivoTurnos{
private:
    std::string _nombreArchivo;

public:
    ArchivoTurnos();
    ArchivoTurnos(std::string nombreArchivo);

    // Dar de alta Turnos
    bool guardar(Turno reg);

    // Modificacion/Baja de Turnos
    bool guardar(Turno reg, int pos);

    // Leer Turnos
    Turno leer(int pos);

    // Buscar Turnos por ID
    int buscar(int idTurno);

    // Cantidad de registros guardados
    int cantidadRegistros();
};
