#ifndef BARBEROARCHIVO_H_INCLUDED
#define BARBEROARCHIVO_H_INCLUDED
#include "Barbero.h"
#include <iostream>
#include <string>
class BarberoArchivo{


private:
      std::string _nombre;
public:
    BarberoArchivo(std::string nombre="barberos.dat");
    bool cargarBarbero(Barbero reg);
    int cantidadRegistros();
    Barbero leer(int pos);
    int buscar(int idBarbero);
    bool modificarBarbero(Barbero barb, int pos);
};

#endif // BARBEROARCHIVO_H_INCLUDED
