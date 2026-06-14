#include <iostream>
using namespace std;
#include "MenuTurnos.h"
#include "Logo.h"
#include "facha.h"
#include "TurnosManager.h"




void  MenuTurnos::InterfazMenuTurnos ()const{
int opcion;

  do {
   system("cls"); // limpia pantalla ;
   LogoConstante ();  //logo por defecto , aparece en todos los menus
      rlutil::setColor(rlutil::YELLOW);
rlutil::locate(27, 18); cout<< " E s t a s  e n:  M e n u-T u r n o s";
rlutil::setColor(rlutil::BLUE);
 rlutil::locate(27, 19);   cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 20);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 21);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 22);    cout<< "บ                                                    บ";
 rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 23);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 24);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 25);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 26);    cout<< "บ                                                    บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 27);   cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

  rlutil::setColor(rlutil::YELLOW);
rlutil::locate(32, 20);
rlutil::locate(32, 22);
rlutil::locate(32, 24);
rlutil::locate(32, 26);

   rlutil::setColor(rlutil::YELLOW);
rlutil::locate(32, 20); cout << "1- Crear Turno" << endl;
rlutil::locate(32, 22); cout << "2- Editar Turno" << endl;
rlutil::locate(32, 24); cout << "3- Borrar Turno Programado" << endl;
rlutil::locate(32, 26); cout << "4- Listar Turnos" << endl;

rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 29);cout<< " Opcion 0 (cero) Para Salir al Menu-Principal..."<<endl;
 rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout<< "Eleccion: #  ";
  rlutil::setColor(rlutil::BLUE);cin>>opcion;
                               cin.ignore();

switch (opcion){
 case 1: {
            CrearTurno();
            break;
 }

  case 2: {
            EditarTurno();
            break;
  }

  case 3:{
            BorrarTurno();
            break;
  }

 case 4:{
            ListarTurnos();
            break;
 }

 case 0:  {  MenuManager volver;
    volver.MenuPrincipal ();
    break;
     }

 default: system ("cls");
        system("cls");
        cout << "Opcion invalida. Ingresa un numero valido para acceder." << endl;
        cout << "0 (cero) para volver al menu principal." << endl;
        system("pause");
        system("cls");
        break;
    }

}
while (opcion != 0);


}

void MenuTurnos::CrearTurno ()const{
    TurnosManager manager;
    manager.crearTurno();
}
void  MenuTurnos::EditarTurno()const{
    TurnosManager manager;
    manager.editarTurno();
}
void  MenuTurnos::BorrarTurno ()const{
    TurnosManager manager;
    manager.borrarTurno();
}
void MenuTurnos::ListarTurnos()const{
    TurnosManager manager;
    manager.listarTurnos();
}


