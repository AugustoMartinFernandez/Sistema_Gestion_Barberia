#include <iostream>
#include "MenuManager.h"
#include "Fecha.h"  //  borrar
#include "Hora.h"   //borrar
#include "facha.h"
#include "Logo.h"

#include "MenuCliente.h"
#include "MenuBarberos.h"
#include  "MenuTurnos.h"
#include "MenuInformes.h"

#include "Cliente.h"
#include "ArchivoConfiguracion.h"
#include "ArchivoClientes.h"
#include "Funciones.h"
using namespace std;
/*
void MenuManager::LogoPorDefecto ()const {

Fecha fecha;
Hora hora;

rlutil::setColor(rlutil::YELLOW);
 rlutil::locate(2, 1);   cout<<"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
 rlutil::locate(2, 2);   cout<<"                                                                º";
 rlutil::locate(2, 3);   cout<<"                                                                º";
rlutil::locate(2, 4);    cout<<"                                                                º";
rlutil::locate(2, 5);    cout<<"                                                                º";
rlutil::locate(2, 6);    cout<<"                                                                º";
rlutil::locate(2, 7);    cout<<"                                                                º";
rlutil::locate(2, 8);    cout<<"                                                                º";
rlutil::locate(2, 9);    cout<<"                                                                º";
rlutil::locate(2, 10);   cout<<"                                                                º";
rlutil::locate(2, 11);   cout<<"                                                                º";
rlutil::locate(2, 12);   cout<<"                                                                º";
rlutil::locate(2, 13);       cout<< "                                                                º";
 rlutil::locate(2, 14);      cout<< "                                                                º";
 rlutil::locate(2, 15);      cout<< "                                                                º";
 rlutil::locate(2, 16);      cout<< "ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";

  rlutil::locate(70, 6); cout << "--- Fecha: " <<fecha.toString()<<endl;
   rlutil::locate(70, 8);  cout << "--- Hora: " <<hora.toString()<<endl;





 rlutil::locate(11, 2); cout<< R"(
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
          )";
}

//  cout<< R"(    )";

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

*/

void MenuManager::MenuPrincipal () const {


  int opcion;
  do {
        system("cls"); // limpia pantalla ;
   LogoConstante();
   rlutil::setColor(rlutil::YELLOW);
rlutil::locate(27, 18); cout<< " E s t a s  e n:  M e n u-P r i n c i p a l";
rlutil::setColor(rlutil::BLUE);
 rlutil::locate(27, 19);   cout<< "ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
 rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 20);    cout<< "º                                                    º";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 21);    cout<< "º                                                    º";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 22);    cout<< "º                                                    º";
 rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 23);    cout<< "º                                                    º";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 24);    cout<< "º                                                    º";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 25);    cout<< "º                                                    º";
rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 26);    cout<< "º                                                    º";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 27);   cout<<  "ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";

rlutil::setColor(rlutil::YELLOW);
rlutil::locate(32, 20);cout << "[ 1 ] Turnos (Agendar un turno, borrar turnos)"<<endl;

rlutil::locate(32, 22);cout << "[ 2 ] Acceder al menu  Para clientes"<<endl;

rlutil::locate(32, 24);cout << "[ 3 ] Acceder al menu Barberos  "<<endl;

rlutil::locate(32, 26);cout << "[ 4 ] Informes"<<endl<<endl;

// rlutil::locate(32, 28);cout << "[ 5 ] Creditos..."<<endl<<endl;



rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 29);cout<< " Opcion 0 (cero) Para Salir Del Programa..."<<endl;
 rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout<< "Eleccion: #  ";
  rlutil::setColor(rlutil::BLUE);cin>>opcion;




switch (opcion) {
case 1:  {
            MenuTurnos turn;
             turn.InterfazMenuTurnos();
             break;
         }

 case 2: {
            MenuCliente client;
          client.InterfazMenuCliente ();
            break;
            }

    case 3:  {
               MenuBarbero barbe;
               barbe.InterfazMenuBarbero ();
               break;
              }
        case 4:  {
                MenuInformes infor;
                infor.InterfazMenuinformes ();
                break;

                  }

          case 5: {
               Creditos ();
               break;
          }
            case 0:  { system("cls");
            rlutil::setColor(rlutil::LIGHTBLUE);
            rlutil::locate(27, 5);
        cout<< "Gracias por utilizar el programa... "<<endl<<endl; break;
                  }

default: system ("cls");
    cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para salir del Programa..."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
}

 } while ( opcion != 0);

  }

void MenuManager::Creditos() const {

  cout<< "aca van los creditos xd";
  }

/*
void MenuManager::MenuCliente()const{

   MenuManager manager;

  int opcion;

 do {
system("cls"); // limpia pantalla ;
  LogoPorDefecto ();  //logo por defecto , aparece en todos los menuss(barberia pacheco)


        cout<<"1- Crear Nuevo Cliente "<<endl;
        cout<<"2- Editar Cliente  "<<endl;
        cout<<"3- Dar de baja / Reactivar cliente "<<endl;
        cout<<"4- Listado de  clientes "<<endl;
        cout <<"-------------------------------"<<endl;
        cout << "Presionar La tecla 0 (cero) para volver";
        cout << " al menu principal"<<endl;
        cout << "Opcion: # ";
        cin>> opcion;
        cin.ignore(); // LIMPIEZA DEL BUFFER:  para que cin.getline() funcione despues

        switch (opcion)
        {
        case 1:
        {
           /* cout << endl << "--- ALTA DE NUEVO CLIENTE ---" << endl;
            Cliente cli;
            cli.cargar();

            ArchivoConfiguracion config;
            int nuevoId = config.getProximoIdCliente();
            cli.setId(nuevoId);

            ArchivoClientes reg;

            if(reg.guardar(cli))
            {
                cout << "\n[EXITO] Cliente guardado correctamente con el ID: " << nuevoId << endl;
            }
            else
            {
                cout << "\n[ERROR] No se pudo guardar el cliente en el disco." << endl;
            }
            system("pause");
            break;

        }
        case 2:
        {

        }
    case 3:
        {

        }
    case 4:
        {


            cout << endl << "--- LISTADO DE CLIENTES ---" << endl;
            ArchivoClientes reg;
            int total = reg.cantidadRegistros();
            bool hayClientesActivos = false; // ESTA ES NUESTRA BANDERA

            if(total > 0)
            {
                for(int i = 0; i < total; i++)
                {
                    Cliente leidos = reg.leer(i);

                    // Solo mostramos si estï¿½ activo
                    if(leidos.getActivo() == true)
                    {
                        leidos.mostrar();
                        hayClientesActivos = true; // Si encontramos uno, la bandera cambia
                    }
                }

                // Al terminar el ciclo, si la bandera nunca cambio, avisamos
                if(hayClientesActivos == false)
                {
                    cout << "No hay clientes activos registrados." << endl;
                }
            }
            else
            {
                cout << "El archivo de clientes esta vacio." << endl;
            }

            system("pause");
            break;

        }
    }
}
while ( opcion != 0);
}
 */


void MenuManager::MenuBarberos()const
{
    system("cls"); // limpia pantalla ;
    Fecha fecha;
    Hora hora;
    int opcion;
  do {
    cout <<"-------------------------------"<<endl;
    cout << "=== Barberia Pacheco ==="<<endl;
    cout << "--- Fecha: " <<fecha.toString()<<endl;
    cout << "--- Hora: " <<hora.toString()<<endl;
    cout <<endl;
    cout <<"-------------------------------"<<endl;
    cout<<"1- ¨Sos un Barbero nuevo? "<<endl;
    cout<<"2- Editar Informacion de Barbero. "<<endl;
    cout<<"3- Borrar Informacion. "<<endl;
    cout<<"4-  "<<endl;
    cout <<"-------------------------------"<<endl;
    cout << "Presionar La tecla 0 (cero) para volver";
    cout << " al menu principal"<<endl;
    cout << "Opcion: # ";
    cin>> opcion;

    switch (opcion){
     case 1:  agregarBarbero(); break; // Agregar funcion crear barbero
     case 2:break;
     case 3:break;
     case 4:break;
    }
    system ("pause");
    system("cls");

    } while ( opcion != 0);
      }






/*
void MenuManager::MenuTurnos()const{

   // MenuManager manager;
   int opcion;

 // do {
   system("cls"); // limpia pantalla ;
  // LogoPorDefecto ();  //logo por defecto , aparece en todos los menus (barberia pacheco)

     cout<<"1- Crear Turno  "<<endl;
     cout<<"2- Editar Turno  "<<endl;
     cout<<"3- Borrar Turno Programado "<<endl;
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

 case 0: MenuPrincipal ();

 default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
    }

} (while opcion != 0);

*/











