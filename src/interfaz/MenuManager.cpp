#include <iostream>
#include "MenuManager.h"
#include "Persona.h"
#include "Fecha.h"
#include "Hora.h"
// include barberos.h, persona, cliente, informes, turnos.

void MenuPrincipal() {
  Fecha fecha;
    Hora hora;

  int opcion;

    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    system("pause");// presiona una tecla para continuar
    system("cls"); // limpia pantalla ;


  do {

cout << "=== Barberia Pacheco ==="<<endl;
cout << " [1] "<<endl;
cout << "Turnos (Agendar un turno, borrar turnos)"<<endl;
cout << " [2] "<<endl;
cout << "Acceder al menu  Para clientes"<<endl;
cout << " [3] "<<endl;
cout << "Acceder al menu Barberos  "<<endl;
cout << " [4] "<<endl;
cout << "Informes..."<<endl<<endl;
  cout<<  "Elegir una opcion 1,2,3,4 o 0 para salir" ;
  cout<<endl<< "Opcion: ";
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
 } while ( opcion != 0)
 // system("cls"); // probar;
 }

void MenuManager::MenuCliente(){
  MenuManager manager;
  Fecha fecha;
    Hora hora;
   int opcion;

    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl<<endl ;

    do {
     cout<<"1- Crear Cliente "<<endl;
     cout<<"2- Editar Cliente  "<<endl;
     cout<<"3- Borrar cliente "<<endl;
     cout<<"4- Listar El total de clintes "<<endl;
     cout << "Presionar La tecla 0 (cero) para volver"<<;
     cout << " al menu principal"<<endl;
     cout << "Opcion: # ";
     cin>> opcion;

switch (opcion){
 case 1: //manager.NuevoCliente ();
     // Agregar la funcion para crear nuevo cliente
  case 2:
  case 3:
 case 4:
}

} while ( opcion != 0)

  }

 void MenuManager::MenuBarberos(){
   MenuManager barb;
   Fecha fecha;
    Hora hora;
   int opcion;

    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl<<endl ;

    do {
     cout<<"1- Crear Cliente "<<endl;
     cout<<"2- Editar Cliente  "<<endl;
     cout<<"3- Borrar cliente "<<endl;
     cout<<"4- Listar El total de clintes "<<endl;
     cout << "Presionar La tecla 0 (cero) para volver"<<;
     cout << " al menu principal"<<endl;
     cout << "Opcion: # ";
     cin>> opcion;

switch (opcion){
 case 1: // barb.CrearBarbero (); break; // Agregar funcion crear barbero
  case 2:
  case 3:
 case 4:
}

} while ( opcion != 0)

  }
 }

void MenuManager::MenuTurnos(){
   MenuManager turn;
   int opcion;

    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl<<endl ;

    do {
     cout<<"1- Crear Cliente "<<endl;
     cout<<"2- Editar Cliente  "<<endl;
     cout<<"3- Borrar cliente "<<endl;
     cout<<"4- Listar El total de clintes "<<endl;
     cout << "Presionar La tecla 0 (cero) para volver"<<;
     cout << " al menu principal"<<endl;
     cout << "Opcion: # ";
     cin>> opcion;

switch (opcion){
 case 1:
  case 2:
  case 3:
 case 4:
}

} while ( opcion != 0)

  }
 }

 void MenuManager::MuestroInformes(){
   MenuManager infor;
   int opcion;

    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl<<endl ;

    do {
     cout<<"1- Crear Cliente "<<endl;
     cout<<"2- Editar Cliente  "<<endl;
     cout<<"3- Borrar cliente "<<endl;
     cout<<"4- Listar El total de clintes "<<endl;
     cout << "Presionar La tecla 0 (cero) para volver"<<;
     cout << " al menu principal"<<endl;
     cout << "Opcion: # ";
     cin>> opcion;

switch (opcion){
 case 1:
  case 2:
  case 3:
 case 4:
}

} while ( opcion != 0)

  }
 }
