#include <iostream>
#include "MenuManager.h"
#include "Persona.h"
#include "Fecha.h"
#include "Hora.h"
#include "facha.h"

using namespace std;
// include barberos.h, persona, cliente, informes, turnos.

void MenuManager::LogoPorDefecto ()const {

Fecha fecha;
Hora hora;

rlutil::setColor(rlutil::BLUE);
 //rlutil::locate(12, 5); cout <<"-------------------------------"<<endl;
 //rlutil::locate(48, 5); cout <<"-------------------------------"<<endl;
 rlutil::locate(27, 3);   cout<< "ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
rlutil::locate(27, 4);    cout<< "º                                       º";
rlutil::locate(27, 5);    cout<< "º                                       º";
rlutil::locate(27, 6);    cout<< "º                                       º";
rlutil::locate(27, 7);    cout<< "º                                       º";
rlutil::locate(27, 8);    cout<< "º                                       º";
rlutil::locate(27, 9);    cout<< "º                                       º";
rlutil::locate(27, 10);   cout<< "ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";

  rlutil::locate(32, 4);   cout << "=== Barberia Pacheco ==="<<endl;
    rlutil::locate(32, 6); cout << "--- Fecha: " <<fecha.toString()<<endl;
   rlutil::locate(32, 8);  cout << "--- Hora: " <<hora.toString()<<endl;
  rlutil::locate(32, 9);  cout <<"--------------------------"<<endl;
}

void MenuManager::MuestroLogo ()const {
cout<< R"(
    ===================================================================================

  ÛÛÛÛÛÛ»  ÛÛÛÛÛ» ÛÛÛÛÛÛ» ÛÛÛÛÛÛ» ÛÛÛÛÛÛÛ»ÛÛÛÛÛÛ» ÛÛ» ÛÛÛÛÛ»
  ÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»ÛÛºÛÛÉÍÍÛÛ»
  ÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛºÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÉ¼ÛÛÛÛÛ»  ÛÛÛÛÛÛÉ¼ÛÛºÛÛÛÛÛÛÛº
  ÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛºÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍ¼  ÛÛÉÍÍÛÛ»ÛÛºÛÛÉÍÍÛÛº
  ÛÛÛÛÛÛÉ¼ÛÛº  ÛÛºÛÛº  ÛÛºÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛ»ÛÛº  ÛÛºÛÛºÛÛº  ÛÛº
  ÈÍÍÍÍÍ¼ ÈÍ¼  ÈÍ¼ÈÍ¼  ÈÍ¼ÈÍÍÍÍÍ¼ ÈÍÍÍÍÍÍ¼ÈÍ¼  ÈÍ¼ÈÍ¼ÈÍ¼  ÈÍ¼

          ÛÛÛÛÛÛ»  ÛÛÛÛÛ»  ÛÛÛÛÛÛ»ÛÛ»  ÛÛ»ÛÛÛÛÛÛÛ» ÛÛÛÛÛÛ» ÛÛÛÛÛÛ»
          ÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍÍÍ¼ÛÛº  ÛÛºÛÛÉÍÍÍÍ¼ÛÛÉÍÍÍÍ¼ÛÛÉÍÍÍÛÛ»
          ÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛºÛÛº     ÛÛÛÛÛÛÛºÛÛÛÛÛ»  ÛÛº     ÛÛº   ÛÛº
          ÛÛÉÍÍÍ¼ ÛÛÉÍÍÛÛºÛÛº     ÛÛÉÍÍÛÛºÛÛÉÍÍ¼  ÛÛº     ÛÛº   ÛÛº
          ÛÛº     ÛÛº  ÛÛºÈÛÛÛÛÛÛ»ÛÛº  ÛÛºÛÛÛÛÛÛÛ»ÈÛÛÛÛÛÛ»ÈÛÛÛÛÛÛÉ¼
          ÈÍ¼     ÈÍ¼  ÈÍ¼ ÈÍÍÍÍÍ¼ÈÍ¼  ÈÍ¼ÈÍÍÍÍÍÍ¼ ÈÍÍÍÍÍ¼ ÈÍÍÍÍÍ¼

                                     _        _
                                    \ \     / /
                                     \ \   / /
                                      \ \_/ /
                                       \   /
                                        ) (
                                       / _ \
                                      / / \ \
                                     /_/   \_\

      =================================================================================
    )"<<endl;

    rlutil::anykey("Cargando Sistema ...");// presiona una tecla para continuar
    system("cls"); // limpia pantalla ;
}

void MenuManager::MenuPrincipal () const {
 system("cls"); // limpia pantalla ;
  Fecha fecha;
    Hora hora;
  int opcion;

  rlutil::setColor(rlutil::YELLOW);  /// cAmbia el color del logo / editar dps.  .
 MuestroLogo();



  do {
   LogoPorDefecto ();


rlutil::setColor(rlutil::RED);
  rlutil::locate(12, 13) ; cout <<"-------------------------------"<<endl;
  rlutil::locate(48, 13) ; cout <<"-------------------------------"<<endl;

rlutil::locate(32, 15);cout << "[ 1 ] Turnos (Agendar un turno, borrar turnos)"<<endl;

rlutil::locate(32, 18);cout << "[ 2 ] Acceder al menu  Para clientes"<<endl;

rlutil::locate(32, 21);cout << "[ 3 ] Acceder al menu Barberos  "<<endl;

rlutil::locate(32, 24);cout << "[ 4 ] Informes..."<<endl<<endl;
rlutil::locate(12, 27);cout <<"-------------------------------"<<endl;
rlutil::locate(48, 27);cout <<"-------------------------------"<<endl;

rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 29);cout<< "Elegir una opcion,  0 (cero)  para salir"<<endl;
 rlutil::locate(32, 31); cout<< "Opcion: # ";  //cin>>opcion;
  rlutil::setColor(rlutil::BLUE);cin>>opcion;



switch (opcion) {
case 1:  MenuTurnos ();  break;

 case 2: MenuCliente (); break;

    case 3: MenuBarberos (); break;

        case 4: MuestroInformes (); break;

            case 0: system("cls");
        cout<< "Gracias por utilizar el programa... "; break;

default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para salir del Programa..."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}
 } while ( opcion != 0);
 // system("cls"); // probar;
  }


void MenuManager::MenuCliente()const{
     system("cls"); // limpia pantalla ;
   MenuManager manager;

  int opcion;

// do {
  LogoPorDefecto ();  //logo por defecto , aparece en todos los menuss(barberia pacheco)


     cout<<"1- Crear Nuevo Cliente "<<endl;
     cout<<"2- Editar Cliente  "<<endl;
     cout<<"3- Borrar cliente "<<endl;
     cout<<"4- Listado de  clientes "<<endl;
      cout <<"-------------------------------"<<endl;
     cout << "Presionar La tecla 0 (cero) para volver";
     cout << " al menu principal"<<endl;
     cout << "Opcion: # ";
     cin>> opcion;

/*
switch (opcion){
 case 1: //manager.NuevoCliente (); break;
     // Agregar la funcion para crear nuevo cliente

  case 2:
  case 3:
 case 4:
 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

} while ( opcion != 0);
*/
  }

 void MenuManager::MenuBarberos()const{
      system("cls"); // limpia pantalla ;

   MenuManager manager;
   int opcion;


   // do {
LogoPorDefecto ();  //logo por defecto , aparece en todos los menus (barberia pacheco)
     cout<<"1- ¨Sos un Barbero nuevo? "<<endl;
     cout<<"2- Editar Informacion de Barbero. "<<endl;
     cout<<"3- Borrar Informacion. "<<endl;
     cout<<"4-  "<<endl;
     cout <<"-------------------------------"<<endl;
     cout << "Presionar La tecla 0 (cero) para volver";
     cout << " al menu principal"<<endl;
     cout << "Opcion: # ";
     cin>> opcion;
/*
switch (opcion){
 case 1: // manager.CrearBarbero (); break; // Agregar funcion crear barbero
  case 2:
  case 3:
 case 4:
 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

} while ( opcion != 0);
  }
  */
 }

void MenuManager::MenuTurnos()const{
     system("cls"); // limpia pantalla ;
   MenuManager manager;
   int opcion;



  //  do {
  LogoPorDefecto ();  //logo por defecto , aparece en todos los menus (barberia pacheco)
     cout<<"1- Crear Cliente "<<endl;
     cout<<"2- Editar Cliente  "<<endl;
     cout<<"3- Borrar cliente "<<endl;
     cout<<"4- Listar El total de clintes "<<endl;
     cout <<"-------------------------------"<<endl;
     cout << "Presionar La tecla 0 (cero) para volver";
     cout << " al menu principal"<<endl;
     cout << "Opcion: # ";
     cin>> opcion;
/*
switch (opcion){
 case 1:
  case 2:
  case 3:
 case 4:
 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

} while ( opcion != 0);

  }
  */
 }

 void MenuManager::MuestroInformes()const{
      system("cls"); // limpia pantalla ;
   MenuManager manager;

   int opcion;

//  do {
  LogoPorDefecto ();  //logo por defecto , aparece en todos los menus (barberia pacheco)

cout <<"-------------------------------"<<endl;
     cout<<"1-  Informes Financieros (Recaudacion, etc.) "<<endl;
     cout<<"2-  Informes de gestion de clientes y agenda "<<endl;
 cout <<"-------------------------------"<<endl;

     cout << "Presionar La tecla 0 (cero) para volver";
     cout << " al menu principal"<<endl;
     cout << "Opcion:# ";
     cin>> opcion;
/*
switch (opcion){
 case 1: SubMenuInfFinancieros (); break;
  case 2:SubMenuInfGestionClientes (); break;
  case 0: MenuPrincipal (); break;
 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

} while ( opcion != 0);
*/
  }


 void MenuManager::SubMenuInfFinancieros ()const {
       system("cls"); // limpia pantalla ;
   MenuManager  manager;

   int opcion;


 //  do {
 LogoPorDefecto ();  //logo por defecto , aparece en todos los menus (barberia pacheco)
 cout <<"-------------------------------"<<endl;
     cout<<"1-  Recaudacion (Diaria, Mensual, Anual.) "<<endl;
     cout<<"2-  Servicios Mas solicitados "<<endl;
     cout<<"3-  Barbero que mas cortes hizo"<<endl;
     cout<<"4-  Metodos de pago utilizados "<<endl;
 cout <<"-------------------------------"<<endl;

     cout << "Presionar La tecla 0 (cero) para volver";
     cout << " al sub Menu Informes... "<<endl;
     cout << "Opcion:# ";
     cin>> opcion;
/*
switch (opcion){
case 1:
case 2:
case 3:
case 4:
  case 0: MuestroInformes (); break;
 default:system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al Menu Informes..."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

} while ( opcion != 0);
*/
 }

 void MenuManager::SubMenuInfGestionClientes () const{
       system("cls"); // limpia pantalla ;
   MenuManager manager;

   int opcion;



  // do {
  LogoPorDefecto ();  //logo por defecto , aparece en todos los menus (barberia pacheco)
  cout <<"-------------------------------"<<endl;
     cout<<"1-  Clientes Frecuentes"<<endl;
     cout<< "2- Turnos realizados y cancelados"<<endl;

 cout <<"-------------------------------"<<endl;

     cout << "Presionar La tecla 0 (cero) para volver";
     cout << " al Sub Menu de Informes... "<<endl;
     cout << "Opcion:# ";
     cin>> opcion;
/*
switch (opcion){
 case 1:
  case 2:
  case 0: MuestroInformes(); break;

 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al Menu Informes..."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}
} while ( opcion != 0);
*/
 }
