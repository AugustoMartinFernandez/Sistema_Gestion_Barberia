#include "ArchivoTurnos.h"
#include <cstdio>

// Constructor por defecto
ArchivoTurnos::ArchivoTurnos(){
    _nombreArchivo = "Turnos.dat";
}

// Constructor con parametro
ArchivoTurnos::ArchivoTurnos(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}


// Dar de alta Turnos
bool ArchivoTurnos::guardar(Turno reg){
    FILE *ptr = fopen(_nombreArchivo.c_str(), "ab");
    if(ptr == nullptr){
        return false;
    }
    // Guardamos y capturamos el resultado
    bool escribio = fwrite(&reg, sizeof(Turno), 1, ptr);
    // Cerramos el archivo
    fclose(ptr);
    // Devolvemos el resultado de la escritura
    return escribio;
}

// Modificacion/Baja de Turnos
bool ArchivoTurnos::guardar(Turno reg, int pos){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, pos * sizeof(Turno),SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(Turno),1,pFile);
    fclose(pFile);
    return escribio;
}

// Leer Turnos
Turno ArchivoTurnos::leer(int pos){
     Turno aux; // Creo una variable objeto para guardar aqui los datos leidos
     FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
     if(nullptr == pFile){
        return aux; // Si falla por alguna razon, devuelve el archivo en blanco
     }
     fseek(pFile, pos * sizeof(Turno), SEEK_SET);
     fread(&aux,sizeof(Turno),1,pFile);
     fclose(pFile);
     return aux;
}

// Buscar Turnos por ID
int ArchivoTurnos::buscar(int idTurno){
    int total = cantidadRegistros();
    for(int i = 0; i < total; i++){
        Turno aux = leer(i);
        if(aux.getId() == idTurno){
            return i;
        }

    }
     return -1;
}

// Cantidad de registros guardados
int ArchivoTurnos::cantidadRegistros(){
    int tamanio;
    FILE *ptr = fopen(_nombreArchivo.c_str(), "rb");
    if(ptr == nullptr){
        return 0;
    }
    fseek(ptr,0,SEEK_END);
    tamanio = ftell(ptr);
    // Cerramos el archivo
    fclose(ptr);
    // Devolvemos el resultado de la escritura
    return tamanio / sizeof(Turno);
}
