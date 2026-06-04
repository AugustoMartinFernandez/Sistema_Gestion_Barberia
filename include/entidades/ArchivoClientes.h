#pragma once
#include <string>
#include "Cliente.h"

class ArchivoClientes{
private:
    std::string _nombreArchivo;

public:
ArchivoClientes();
ArchivoClientes(std::string nombreArchivo);

// Dar de alta Clientes
bool guardar(Cliente reg);
// Modificacion/Baja de Clientes
bool guardar(Cliente reg, int pos);
// Leer Clientes
Cliente leer(int pos);
// Buscar Clientes por ID
int buscar(int idCliente);
// Medimos el tamaño del cliente
int cantidadRegistros();
};
