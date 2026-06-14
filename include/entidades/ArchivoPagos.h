#pragma once
#include <string>
#include "Pago.h"

class ArchivoPagos{
private:
    std::string _nombreArchivo;

public:
    ArchivoPagos();
    ArchivoPagos(std::string nombreArchivo);

    // Dar de alta
    bool guardar(Pago reg);

    // Modificacion/Baja
    bool guardar(Pago reg, int pos);

    // Leer
    Pago leer(int pos);

    // Buscar por ID de pago
    int buscar(int idPago);

    // Buscar pago por ID de turno
    int buscarPorTurno(int idTurno);

    // Medimos el tamaño
    int cantidadRegistros();
};
