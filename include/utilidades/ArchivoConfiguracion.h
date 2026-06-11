#pragma once
#include <string>
class ArchivoConfiguracion{

private:
    int _ultimoIdCliente;
    int _ultimoIdBarbero;
    int _ultimoIdServicio;
    int _ultimoIdTurno;
    int _ultimoIdPago;

public:

    ArchivoConfiguracion();

    bool leerConfiguracion();
    bool guardarConfiguracion();

    int getProximoIdCliente();
    int getProximoIdBarbero();
    int getProximoIdServicio();
    int getProximoIdTurno();
    int getProximoIdPago();

};
