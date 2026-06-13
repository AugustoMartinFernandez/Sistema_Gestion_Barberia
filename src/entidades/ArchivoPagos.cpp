#include "ArchivoPagos.h"
#include <cstdio>


// Constructor por defecto
ArchivoPagos::ArchivoPagos(){
    _nombreArchivo = "Pagos.dat";
}


// Constructor con parametro
ArchivoPagos::ArchivoPagos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}




// Dar de alta Pagos
bool ArchivoPagos::guardar(Pago reg){
    FILE *ptr = fopen(_nombreArchivo.c_str(), "ab");
    if(ptr == nullptr){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Pago), 1, ptr);

    fclose(ptr);

    return escribio;
}




// Modificacion/Baja de Pagos
bool ArchivoPagos::guardar(Pago reg, int pos){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(Pago), SEEK_SET);

    bool escribio = fwrite(&reg, sizeof(Pago), 1, pFile);

    fclose(pFile);

    return escribio;
}



// Leer Pagos
Pago ArchivoPagos::leer(int pos){
    Pago aux;

    if(pos < 0){
        return aux;
    }

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return aux;
    }

    fseek(pFile, pos * sizeof(Pago), SEEK_SET);

    fread(&aux, sizeof(Pago), 1, pFile);

    fclose(pFile);

    return aux;
}




// Buscar Pagos por ID
int ArchivoPagos::buscar(int idPago){
    int total = cantidadRegistros();

    for(int i = 0; i < total; i++){
        Pago aux = leer(i);

        if(aux.getId() == idPago){
            return i;
        }
    }

    return -1;
}




// Buscar Pago por ID de Turno
int ArchivoPagos::buscarPorTurno(int idTurno){
    int total = cantidadRegistros();

    for(int i = 0; i < total; i++){
        Pago aux = leer(i);

        if(aux.getIdTurno() == idTurno && aux.getActivo()){
            return i;
        }
    }

    return -1;
}




// Cantidad de registros guardados
int ArchivoPagos::cantidadRegistros(){
    int tamanio;

    FILE *ptr = fopen(_nombreArchivo.c_str(), "rb");
    if(ptr == nullptr){
        return 0;
    }

    fseek(ptr, 0, SEEK_END);

    tamanio = ftell(ptr);

    fclose(ptr);

    return tamanio / sizeof(Pago);
}
