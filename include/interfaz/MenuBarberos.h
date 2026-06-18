#pragma once
#include "MenuManager.h"

class MenuBarbero {
public:
    void InterfazMenuBarbero() const;
    void BarberoNuevo() const;
    void EditarInformacion() const;
    void GestionarEstado() const; // para dar de baja/reactivar
    void ListarBarberos() const;
    void BuscarBarberoPorID() const;
};
