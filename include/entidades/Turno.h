#pragma once
#include "Fecha.h"
#include "Hora.h"

class Turno{
private:
    int _id;
    int _idCliente;
    int _idBarbero;
    int _idServicio; // servicio va a ser dependiendo del servicio un numero listado en las opciones

    Fecha _fecha;
    Hora _hora;

    bool _activo;

public:
    Turno();

    void setId(int id);
    void setIdCliente(int idCliente);
    void setIdBarbero(int idBarbero);
    void setIdServicio(int idServicio);
    void setFecha(Fecha fecha);
    void setHora(Hora hora);
    void setActivo(bool activo);

    int getId() const;
    int getIdCliente() const;
    int getIdBarbero() const;
    int getIdServicio() const;
    Fecha getFecha() const;
    Hora getHora() const;
    bool getActivo() const;

    void cargar();
    void mostrar() const;


};
