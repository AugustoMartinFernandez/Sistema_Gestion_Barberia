#include "ArchivoConfiguracion.h"
#include <cstdio>

ArchivoConfiguracion::ArchivoConfiguracion(){
    _ultimoIdCliente = 0;
    _ultimoIdBarbero = 0;
    _ultimoIdServicio = 0;
    _ultimoIdTurno = 0;
    _ultimoIdPago = 0;
}
bool ArchivoConfiguracion::leerConfiguracion(){
    FILE *pFile = fopen("Config.dat", "rb");
    if(pFile == nullptr){
        return false;
    }
    bool leyo = fread(this,sizeof(ArchivoConfiguracion),1,pFile);
    fclose(pFile);
    return leyo;
}
bool ArchivoConfiguracion::guardarConfiguracion(){
    FILE *pFile = fopen("Config.dat", "wb");
    if(pFile == nullptr){
        return false;
    }
    bool escribio = fwrite(this,sizeof(ArchivoConfiguracion),1,pFile);
    fclose(pFile);
    return escribio;
}
int ArchivoConfiguracion::getProximoIdCliente(){
    // Traemos los ultimos numeros guardados en el disco duro a la memoria
    leerConfiguracion();
    // Le sumamos 1 a nuestra variable de clientes para generar el nuevo ID.
    _ultimoIdCliente++;
    // Guardamos ese nuevo numero en el disco duro.
    guardarConfiguracion();
    // Se lo entregamos al menu para que se lo asigne a barbero, cliente etc
    return _ultimoIdCliente;
}
int ArchivoConfiguracion::getProximoIdBarbero(){
    leerConfiguracion();
    _ultimoIdBarbero++;
    guardarConfiguracion();
    return _ultimoIdBarbero;
}
int ArchivoConfiguracion::getProximoIdServicio(){
    leerConfiguracion();
    _ultimoIdServicio++;
    guardarConfiguracion();
    return _ultimoIdServicio;
}
int ArchivoConfiguracion::getProximoIdTurno(){
    leerConfiguracion();
    _ultimoIdTurno++;
    guardarConfiguracion();
    return _ultimoIdTurno;
}
int ArchivoConfiguracion::getProximoIdPago(){
    leerConfiguracion();
    _ultimoIdPago++;
    guardarConfiguracion();
    return _ultimoIdPago;
}
