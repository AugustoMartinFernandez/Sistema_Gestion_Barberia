#pragma once
#include "Persona.h"

class Cliente: public Persona{

private:
    int _puntosAcumulados;

public:

    Cliente();

    int getPuntosAcumulados() const;
    void setPuntosAcumulados(int puntos);
    void sumarPuntos(int puntos);
    void restarPuntos(int puntos);

    void cargar() override;
    void mostrar() const override;

};
