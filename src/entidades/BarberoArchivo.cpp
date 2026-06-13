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

int BarberoArchivo::cantidadRegistros(){
    int tamanio;
    FILE *ptr = fopen(_nombre.c_str(), "rb");
    if(ptr == nullptr){
        return 0;
    }
    fseek(ptr,0,SEEK_END);
    tamanio = ftell(ptr);
    fclose(ptr);
    return tamanio / sizeof(Barbero);
}

Barbero BarberoArchivo::leer(int pos){
     Barbero aux; // Creo una variable objeto para guardar aqui los datos leidos
     FILE *pFile = fopen(_nombre.c_str(), "rb");
     if(nullptr == pFile){
        return aux; // Si falla por alguna razon, devuelve el archivo en blanco
     }
     fseek(pFile, pos * sizeof(Barbero), SEEK_SET);
     fread(&aux,sizeof(Barbero),1,pFile);
     fclose(pFile);
     return aux;
}
 //BUSCAR
int BarberoArchivo::buscar(int idBarbero){
    int total = cantidadRegistros();
    for(int i = 0; i < total; i++){
        Barbero aux = leer(i);
        if(aux.getId() == idBarbero){
            return i;
        }

    }
     return -1;
}
//MODIFICAR
bool BarberoArchivo::modificarBarbero(Barbero barb, int pos){
FILE *pFile = fopen(_nombre.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, pos * sizeof(Barbero),SEEK_SET);
    bool escribio = fwrite(&barb, sizeof(Barbero),1,pFile);
    fclose(pFile);
    return escribio;

}
