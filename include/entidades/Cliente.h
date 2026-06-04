#pragma once
#include "Persona.h"

class Cliente: public Persona{

public:

    Cliente();

    void cargar() override;
    void mostrar() const override;
};
