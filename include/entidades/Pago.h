#pragma once
#include "Fecha.h"
#include "Hora.h"

class Pago{

private:
    int _id;
    int _idTurno;
    float _monto;

    Fecha _fechaPago;
    Hora _horaPago;

    char _metodoPago[20]; // aca pusismos int, pero era un char
    bool _activo;  // seria activo en el primer informe (aprobado/Anulado) si no se entiende lo cambiamos

public:
    Pago();

    void setId(int id);
    void setIdTurno(int idTurno);
    void setMonto(float monto);
    void setFechaPago(Fecha fechaPago);
    void setHoraPago(Hora horaPago);
    void setMetodoPago(const char* metodoPago);
    void setActivo(bool activo);

    int getId() const;
    int getIdTurno() const;
    float getMonto() const;
    Fecha getFechaPago() const;
    Hora getHoraPago() const;
    const char* getMetodoPago() const;
    bool getActivo() const;

    void cargar();
    void mostrar() const;
};
