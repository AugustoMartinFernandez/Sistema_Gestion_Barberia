#pragma once
#include "Persona.h"
#include "Fecha.h"
#include "Hora.h"
using namespace std;

class MenuManager {
public:
// menus
 void MenuCliente() const;
 void MenuBarberos()const;
 void MenuTurnos()const;
 void MuestroInformes()const;

 //sub menus  :
 void SubMenuInfFinancieros()const;
 void SubMenuInfGestionClientes () const;

//principal
void MenuPrincipal () const;

// logos:
void LogoPorDefecto ()const;
void MuestroLogo()const;

};
