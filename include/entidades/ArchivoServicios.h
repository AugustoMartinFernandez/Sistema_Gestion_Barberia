#pragma once
#include <string>
#include "Servicio.h"

class ArchivoServicios{
private:
    std::string _nombreArchivo;

public:
    ArchivoServicios();
    ArchivoServicios(std::string nombreArchivo);

    // Dar de alta Servicios
    bool guardar(Servicio reg);
    // Modificacion/Baja de Servicios
    bool guardar(Servicio reg, int pos);
    // Leer Servicios
    Servicio leer(int pos);
    // Buscar Servicios por ID
    int buscar(int idServicio);
    // Cantidad de registros guardados
    int cantidadRegistros();
};
