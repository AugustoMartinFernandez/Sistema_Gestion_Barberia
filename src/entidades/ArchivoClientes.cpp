#include "ArchivoClientes.h"
#include <cstdio>

// Constructor por defecto
ArchivoClientes::ArchivoClientes(){
    _nombreArchivo = "Clientes.dat";
}
// Constructor con parametro
ArchivoClientes::ArchivoClientes(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

// Dar de alta Clientes
bool ArchivoClientes::guardar(Cliente reg){
    FILE *ptr = fopen(_nombreArchivo.c_str(), "ab");
    if(ptr == nullptr){
        return false;
    }
    // Guardamos y capturamos el resultado
    bool escribio = fwrite(&reg, sizeof(Cliente), 1, ptr);
    // Cerramos el archivo
    fclose(ptr);
    // Devolvemos el resultado de la escritura
    return escribio;
}
// Modificacion/Baja de Clientes
bool ArchivoClientes::guardar(Cliente reg, int pos){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }
    fseek(pFile, pos * sizeof(Cliente),SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(Cliente),1,pFile);
    fclose(pFile);
    return escribio;
}
// Leer Clientes
Cliente ArchivoClientes::leer(int pos){
     Cliente aux; // Creo una variable objeto para guardar aqui los datos leidos
     FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
     if(nullptr == pFile){
        return aux; // Si falla por alguna razon, devuelve el archivo en blanco
     }
     fseek(pFile, pos * sizeof(Cliente), SEEK_SET);
     fread(&aux,sizeof(Cliente),1,pFile);
     fclose(pFile);
     return aux;
}
// Buscar Clientes por ID
int ArchivoClientes::buscar(int idCliente){
    int total = cantidadRegistros();
    for(int i = 0; i < total; i++){
        Cliente aux = leer(i);
        if(aux.getId() == idCliente){
            return i;
        }

    }
     return -1;
}
// Cantidad de registros guardados
int ArchivoClientes::cantidadRegistros(){
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
    return tamanio / sizeof(Cliente);
}
