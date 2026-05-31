#include <iostream>
#include "MenuManager.h"
#include "Persona.h"
#include "Fecha.h"
#include "Hora.h"
using namespace std;
// include barberos.h, persona, cliente, informes, turnos.


void MenuManager::MenuPrincipal () const {
 system("cls"); // limpia pantalla ;
  Fecha fecha;
    Hora hora;

  int opcion;

  // LOGO IMPROVISADO  ( EDITAR LUEGO
cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;
    system("pause");// presiona una tecla para continuar
    system("cls"); // limpia pantalla ;


  do {
cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;
cout << " [1] "<<endl;
cout << "Turnos (Agendar un turno, borrar turnos)"<<endl;
cout << " [2] "<<endl;
cout << "Acceder al menu  Para clientes"<<endl;
cout << " [3] "<<endl;
cout << "Acceder al menu Barberos  "<<endl;
cout << " [4] "<<endl;
cout << "Informes..."<<endl<<endl;
cout <<"-------------------------------"<<endl;
cout<< "Elegir una opcion, 0 para salir" ;
  cout<<endl<< "Opcion:# ";
 cin>>opcion;


switch (opcion) {
case 1:  MenuTurnos ();  break;

 case 2: MenuCliente (); break;

    case 3: MenuBarberos (); break;

        case 4: MuestroInformes (); break;

            case 0: system("cls");
        cout<< "Gracias por utilizar el programa... "; break;

default:  cout<< "Opcion invalida pa.";
}
 } while ( opcion != 0);
 // system("cls"); // probar;
  }


void MenuManager::MenuCliente()const{
     system("cls"); // limpia pantalla ;
  MenuManager manager;
  Fecha fecha;
    Hora hora;
   int opcion;

 cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;
   // do {

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
 case 1: //manager.NuevoCliente ();
     // Agregar la funcion para crear nuevo cliente
  case 2:
  case 3:
 case 4:
}

} while ( opcion != 0);
*/
  }

 void MenuManager::MenuBarberos()const{
      system("cls"); // limpia pantalla ;
   MenuManager barb;
   Fecha fecha;
    Hora hora;
   int opcion;

 cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;

   // do {

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
 case 1: // barb.CrearBarbero (); break; // Agregar funcion crear barbero
  case 2:
  case 3:
 case 4:
}

} while ( opcion != 0);
  }
  */
 }

void MenuManager::MenuTurnos()const{
     system("cls"); // limpia pantalla ;
   MenuManager turn;
   int opcion;
   Fecha fecha;
   Hora hora;

  cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;

  //  do {
     cout<<"1- Crear Cliente "<<endl;
     cout<<"2- Editar Cliente  "<<endl;
     cout<<"3- Borrar cliente "<<endl;
     cout<<"4- Listar El total de clintes "<<endl;
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
}

} while ( opcion != 0);

  }
  */
 }

 void MenuManager::MuestroInformes()const{
      system("cls"); // limpia pantalla ;
   MenuManager infor;
   Fecha fecha;
   Hora hora;
   int opcion;

   cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;

 //  do {
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
 default: cout << "Opcion invalida"
}

} while ( opcion != 0);
*/
  }


 void MenuManager::SubMenuInfFinancieros ()const {
       system("cls"); // limpia pantalla ;
   MenuManager infor;
   Fecha fecha;
   Hora hora;
   int opcion;

   cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;

 //  do {
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
 default: cout << "Opcion invalida";
}

} while ( opcion != 0);
*/
 }

 void MenuManager::SubMenuInfGestionClientes () const{
       system("cls"); // limpia pantalla ;
   MenuManager infor;
   Fecha fecha;
   Hora hora;
   int opcion;

   cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;

  // do {
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
 default: cout << "Opcion invalida";
}
} while ( opcion != 0);
*/
 }
