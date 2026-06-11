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
};

#endif // BARBEROARCHIVO_H_INCLUDED
