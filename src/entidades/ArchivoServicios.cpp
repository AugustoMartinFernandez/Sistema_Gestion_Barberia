#include "ArchivoServicios.h"
#include <cstdio>

// Constructor por defecto
ArchivoServicios::ArchivoServicios(){
    _nombreArchivo = "Servicios.dat";
}
// Constructor con parametro
ArchivoServicios::ArchivoServicios(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoServicios::guardar(Servicio reg){
    FILE *ptr = fopen(_nombreArchivo.c_str(), "ab");
    if(ptr == nullptr){
        return false;
    }
    // Guardamos y capturamos el resultado
    bool escribio = fwrite(&reg, sizeof(Servicio), 1, ptr);
    fclose(ptr);
    // Devolvemos el resultado de la escritura
    return escribio;
}

bool ArchivoServicios::guardar(Servicio reg, int pos){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, pos * sizeof(Servicio),SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(Servicio),1,pFile);
    fclose(pFile);
    return escribio;
}

Servicio ArchivoServicios::leer(int pos){
     Servicio aux; // Creo una variable objeto para guardar aqui los datos leidos
     FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
     if(nullptr == pFile){
        return aux; // Si falla por alguna razon, devuelve el archivo en blanco
     }
     fseek(pFile, pos * sizeof(Servicio), SEEK_SET);
     fread(&aux,sizeof(Servicio),1,pFile);
     fclose(pFile);
     return aux;
}

int ArchivoServicios::buscar(int idServicio){
    int total = cantidadRegistros();
    for(int i = 0; i < total; i++){
        Servicio aux = leer(i);
        if(aux.getId() == idServicio){
            return i;
        }

    }
     return -1;
}
// Cantidad de registros guardados
int ArchivoServicios::cantidadRegistros(){
    int tamanio;
    FILE *ptr = fopen(_nombreArchivo.c_str(), "rb");
    if(ptr == nullptr){
        return 0;
    }
    fseek(ptr,0,SEEK_END);
    tamanio = ftell(ptr);
    fclose(ptr);
    // Devolvemos el resultado de la escritura
    return tamanio / sizeof(Servicio);
}
