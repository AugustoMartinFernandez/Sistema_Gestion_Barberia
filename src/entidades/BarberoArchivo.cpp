#include <iostream>
#include "BarberoArchivo.h"
#include "Barbero.h"
using namespace std;

BarberoArchivo::BarberoArchivo(std::string nombre)
{
  _nombre = nombre;
}

bool BarberoArchivo::cargarBarbero(Barbero reg)
{
  FILE *p = fopen(_nombre.c_str(), "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&reg, sizeof(Barbero), 1, p);
  fclose(p);
  return pudoEscribir;
}
