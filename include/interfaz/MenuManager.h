#pragma once
#include "Persona.h"
#include "Fecha.h"
#include "Hora.h"
using namespace std;

class MenuManager {
public:

 void MenuCliente() const;
 void MenuBarberos()const;
 void MenuTurnos()const;

 void MuestroInformes()const;
 void SubMenuInfFinancieros()const;
 void SubMenuInfGestionClientes () const;

//
void MenuPrincipal () const;

};
