#pragma once
#include "Persona.h"

 //Barbero hereda de persona todas las propiedades y metodos
class Barbero: public Persona{
    private:
        // int _idBarbero; --> Esto no va, hereda de persona
        char _especialidad[50];

    public:
        Barbero();
        //agregar setters y getters, mostrar todas las propiedades y mover a cpp esto
        const char *getEspecialidad() const;
        void setEspecialidad(const char *especialidad);
        void cargar() override;
        void mostrar() const override;
};
