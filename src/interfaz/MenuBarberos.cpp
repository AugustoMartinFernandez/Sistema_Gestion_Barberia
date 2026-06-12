#include <iostream>
using namespace std;
#include "MenuBarberos.h"
#include "Logo.h"
#include "MenuManager.h"
#include "facha.h"


void MenuBarbero::InterfazMenuBarbero ()const{
 int opcion;


   do {
        system("cls");
        LogoConstante ();
rlutil::setColor(rlutil::YELLOW);
rlutil::locate(27, 18); cout<< " E s t a s  e n:  M e n u-B a r b e r o s";
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
//rlutil::locate(32, 26);
 rlutil::locate(32, 20);    cout<<"1- จSos un Barbero nuevo? "<<endl;
  rlutil::locate(32, 22);   cout<<"2- Editar Informacion de Barbero. "<<endl;
  rlutil::locate(32, 24);   cout<<"3- Borrar Informacion. "<<endl;
    //  cout<<"4-  "<<endl;

     rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 29);cout<< " Opcion 0 (cero) Para Salir Del Programa..."<<endl;
 rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout<< "Eleccion: #  ";
  rlutil::setColor(rlutil::BLUE);cin>>opcion;
                                   cin.ignore();

switch (opcion){
 case 1:   {  void BarberoNuevo();
          break;     }

  case 2: {  void EditarInformacion();
           break;   }

  case 3:  {  void BorrarInformacion();
                break;       }

  case 0: {
            MenuManager volver;
            volver.MenuPrincipal ();
            break;
          }


 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

} while ( opcion != 0);

}





void MenuBarbero::BarberoNuevo()const{

}
void MenuBarbero::EditarInformacion()const{

}
void MenuBarbero::BorrarInformacion()const{

}
