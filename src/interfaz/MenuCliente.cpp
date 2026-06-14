#include <iostream>
using namespace std;
#include "MenuCliente.h"
#include "MenuManager.h"


#include "Cliente.h"
#include "ArchivoConfiguracion.h"
#include "ArchivoClientes.h"

#include "facha.h"
#include "Logo.h"


void MenuCliente::InterfazMenuCliente () const {

int opcion;

 do {
system("cls"); // limpia pantalla ;
  LogoConstante ();   //logo por defecto , aparece en todos los menuss(barberia pacheco)
rlutil::setColor(rlutil::YELLOW);
rlutil::locate(27, 18); cout<< " E s t a s  e n:  M e n u - C l i e n t e s";
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

 rlutil::locate(32, 20);       cout<<"1- Crear Nuevo Cliente "<<endl;
 rlutil::locate(32, 22);       cout<<"2- Editar Cliente  "<<endl;
 rlutil::locate(32, 24);       cout<<"3- Dar de baja / Reactivar cliente "<<endl;
 rlutil::locate(32, 26);        cout<<"4- Listado de  clientes "<<endl;

    rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 28);cout<< " Opcion 0 (cero) Para Salir Al Menu Principal..."<<endl;
 rlutil::setColor(rlutil::RED);  rlutil::locate(32, 29); cout<< "Eleccion: #  ";
  rlutil::setColor(rlutil::BLUE);cin>>opcion;
                                  cin.ignore(); // LIMPIEZA DEL BUFFER:  para que cin.getline() funcione despues

        switch (opcion)
        {
        case 1:
       {
           CrearNuevoCliente(); break;
       }

        case 2:
        {
            EditarCliente(); break;
        }
    case 3:
        {
          Dardebaja_Reactivarcliente(); break;
        }
    case 4:
        {
            Listadeclientes(); break;

        }
        case 0:
            {
                MenuManager volver;
                  volver.MenuPrincipal (); break;
          }

        default: system ("cls");
     cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
    cout<<" 0 (cero) para volver al menu principal."<<endl;
    cout<<endl<<endl;  system ("pause");
     system ("cls");
    }
}
while ( opcion != 0);
}



void MenuCliente::CrearNuevoCliente() const {

system ("cls");

              LogoConstante ();   //logo por defecto , aparece en todos los menuss(barberia pacheco)


rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 19);   cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 20);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 21);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 22);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 23);   cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
rlutil::setColor(rlutil::YELLOW);
rlutil::locate(29, 21); cout<<"A l t a  D e  N u e v o  C l i e n t e";
   //  cout << endl << "--- ALTA DE NUEVO CLIENTE ---" << endl;

            Cliente cli;
             rlutil::setColor(rlutil::YELLOW);
                  rlutil::locate(3, 24);  cli.cargar();      //

            ArchivoConfiguracion config;
            int nuevoId = config.getProximoIdCliente();
            cli.setId(nuevoId);

            ArchivoClientes reg;

            if(reg.guardar(cli))
            {
               rlutil::setColor(rlutil::GREEN);
                  rlutil::locate(3, 30);  cout << "\n[EXITO] Cliente guardado correctamente con el ID: " << nuevoId << endl;
            }
            else
            {
                 rlutil::setColor(rlutil::WHITE);
                  rlutil::locate(3, 30);
                cout << "\n[ERROR] No se pudo guardar el cliente en el disco." << endl;
            }
            system("pause");


}
void MenuCliente::EditarCliente() const {


    system ("cls");

              LogoConstante ();   //logo por defecto , aparece en todos los menuss(barberia pacheco)




int buscarId,pos,cantidad;
    ArchivoClientes reg;
        Cliente cli;

            bool hayClientesActivos = false;
            cantidad = reg.cantidadRegistros();

            if(cantidad == 0)
            {
                 system ("cls");

              LogoConstante ();

                rlutil::setColor(rlutil::WHITE);

            cout <<endl<<endl<<"No hay clientes en el archivo a modificar." <<endl;
             rlutil::setColor(rlutil::YELLOW);
            cout << "Por favor, dirijase a la opcion 1 del menu para dar de alta un nuevo cliente." << endl;
            }
            else
            {
                for(int i=0; i<cantidad; i++)
                {
                    Cliente escaneo = reg.leer(i);
                    if(escaneo.getActivo() == true)
                    {
                        hayClientesActivos = true;
                        break;
                    }
                }
                if(hayClientesActivos == false)
                {
                     system ("cls");

              LogoConstante ();
              rlutil::setColor(rlutil::WHITE);
                    cout <<endl<<endl<< "No hay clientes activos en el sistema para modificar." << endl;
                }
                else
                {
                    rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 19);   cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 20);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 21);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 22);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 23);   cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
rlutil::setColor(rlutil::YELLOW);
rlutil::locate(29, 18); cout<<" E d i t  D e  C l i e n t e";
                   //  cout << "--- MODIFICAR CLIENTES ---" <<endl;
          rlutil::locate(29, 20);          cout << "Ingrese ID del Cliente a modificar: "<<endl;
          rlutil::setColor(rlutil::YELLOW);
           rlutil::locate(29, 21);          cin >> buscarId;

                    while(buscarId <= 0)
                    {
                        cout <<endl<<endl<<endl<<endl<< "ID Invalido. Intente nuevamente: ";
                        cin >> buscarId;
                    }

                    pos = reg.buscar(buscarId);
                    if(pos >= 0)
                    {
                        cli = reg.leer(pos);
                        if(cli.getActivo()==true)
                        {
                            system ("cls");

              LogoConstante ();   //logo por defecto , aparece en todos los menuss(barberia pacheco)

                                 rlutil::setColor(rlutil::WHITE);
                            cout<<endl<<endl<< "F i c h a  A c t u a l  d e l  C l i e n t e:" << endl<<endl;
                             rlutil::setColor(rlutil::YELLOW);
                            cli.mostrar();
                            cout<< "I n g r e s e  l o s  n u e v o s  d a t o s:" << endl;
                            cin.ignore();
                            cli.cargar();
                            if(reg.guardar(cli,pos))
                            {
                                 rlutil::setColor(rlutil::GREEN);
                                cout << "\nCliente modificado correctamente." << endl;
                            }
                            else
                            {
                                 rlutil::setColor(rlutil::RED);
                                cout << "\nNo se pudo guardar la modificacion en el archivo." << endl;
                            }
                        }
                        else
                        {
                              rlutil::setColor(rlutil::RED);
                            cout << "\nNo se puede modificar un cliente dado de baja" <<endl;
                        }
                    }
                    else
                    {
                         rlutil::setColor(rlutil::WHITE);
                        cout <<endl<<endl<< "\nEl ID ingresado no existe en el archivo." << endl;
                    }
                }
            }

        system("pause");


}
void MenuCliente::Dardebaja_Reactivarcliente() const {
                int subOpcion;
             system ("cls");

              LogoConstante ();   //logo por defecto , aparece en todos los menuss(barberia pacheco)
rlutil::setColor(rlutil::YELLOW);
rlutil::locate(27, 18); cout<< " E s t a s  e n:  S u b M e n u - E s t a d o  C l i e n t e s";
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


   rlutil::locate(32, 20);
 rlutil::locate(32, 22);
 rlutil::locate(32, 24);
 rlutil::locate(32, 26);
  rlutil::setColor(rlutil::YELLOW);
   rlutil::locate(32, 22);          cout << "1- Dar de baja a un cliente" << endl;
   rlutil::locate(32, 24);         cout << "2- Reactivar a un cliente" << endl;

             rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 28);cout<< " Opcion 0 (cero) Para Salir Al Menu Clientes..."<<endl;
 rlutil::setColor(rlutil::RED);  rlutil::locate(32, 29); cout<< "Eleccion: #  ";
  rlutil::setColor(rlutil::BLUE);cin>>subOpcion;

        if (subOpcion == 0 ) {
             return;
        }
            while(subOpcion != 1 && subOpcion != 2){
                cout << "Opcion invalida. Ingrese 1 para Baja o 2 para Reactivar: ";
                cin >> subOpcion;
            }

            int buscarId, pos, confirmacion, cantidad;
            ArchivoClientes reg;
            Cliente cli;
            bool hayClientesObjetivo = false;

            cantidad = reg.cantidadRegistros();
            if(cantidad == 0){
                cout << "\nEl archivo esta vacio. No hay clientes para operar." <<endl;
                cout << "Por favor, dirijase a la opcion 1 del menu para dar de alta un nuevo cliente." << endl;
            }else{
                // SUBOPCION 1: LOGICA DE BAJA L๏ฟฝGICA
                if(subOpcion == 1){

                    for(int i =0; i < cantidad; i++ ){
                        Cliente escaneo = reg.leer(i);
                        if(escaneo.getActivo() == true){
                            hayClientesObjetivo = true;
                            break;
                        }
                    }
                    if(hayClientesObjetivo == false){
                        cout << "\nNo hay clientes activos en el sistema para dar de baja." << endl;
                    }else{
                        system ("cls");

                        LogoConstante ();
                        rlutil::setColor(rlutil::WHITE);
 rlutil::locate(27, 19); cout<<"ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 20);  cout<<"บ                                                       บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27,21);   cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
                     rlutil::setColor(rlutil::YELLOW);
   rlutil::locate(27, 18);
     cout << "E s t a s  e n: D a r  d e  B a j a";            // Opcion 1 dar de baja un cliente.
                  rlutil::setColor(rlutil::WHITE);
                  rlutil::locate(30, 20);      cout << "Ingrese ID del Cliente a dar de baja: ";rlutil::setColor(rlutil::BLUE);cin >> buscarId;


                        while(buscarId <= 0)
                        {
                            rlutil::setColor(rlutil::RED);
                            cout <<endl<<endl<<endl<<"ID Invalido. Intente nuevamente: ";
                            cin >> buscarId;
                        }
                        pos = reg.buscar(buscarId);
                        if(pos >= 0){
                            cli = reg.leer(pos);
                            if(cli.getActivo()==true){
                                    rlutil::setColor(rlutil::WHITE);
                        cout <<endl<< "Ficha actual del cliente:" <<endl;
                        rlutil::setColor(rlutil::YELLOW);
                             cout<<endl;
                             cli.mostrar();

                                do
                                {
                                     cout <<"\nEsta seguro que desea dar de baja a este cliente? (1=Si, 0=No): ";
                                    cin >> confirmacion;
                                    if(confirmacion != 1 || confirmacion != 0) /// lE CAMBIE  && por ||
                                    {
                                       cout<< "Error. Ingrese 1=Si y 0 =No." << endl;
                                    }
                                }
                                while(confirmacion != 1 && confirmacion != 0);

                                if(confirmacion == 1){
                                    cli.setActivo(false);
                                    if(reg.guardar(cli,pos)){

                    rlutil::setColor(rlutil::GREEN);
                                     cout <<endl<< "\nCliente dado de Baja Exitosamente." << endl;
                                    }else{
                                         rlutil::setColor(rlutil::RED);

                                        cout<<endl << "\nError al guardar la baja en el archivo." << endl;
                                    }
                                }
                                else{
                                        system ("cls");

                                        LogoConstante ();
                                        rlutil::setColor(rlutil::GREEN);

                                    cout<<endl<<endl<< "\nOperacion cancelada. No se dio de Baja al cliente." << endl;
                                }
                            }
                            else{

                                   system ("cls");

                                        LogoConstante ();
                               rlutil::setColor(rlutil::RED);
                                    cout<<endl<<endl<< "\nError: Ese ID especifico ya pertenece a un cliente dado de baja." << endl;
                            }
                        }
                        else{
                                 system ("cls");
                         LogoConstante ();
                                rlutil::setColor(rlutil::WHITE);

                            cout <<endl<<endl<<"\nEl ID ingresado no existe en el archivo." << endl;
                        }
                    }
                }
                    // Subopcion 2: Logica de Reactivacion
                else if(subOpcion == 2){
                   for(int i =0; i < cantidad; i++){
                    Cliente escaneo = reg.leer(i);
                    if(escaneo.getActivo() == false){
                        hayClientesObjetivo = true;
                        break;
                    }
                   }
                   if(hayClientesObjetivo == false){
                         rlutil::setColor(rlutil::WHITE);
                    cout << "\nNo hay clientes dados de baja en el sistema para reactivar." << endl;
                   }else{

                        system ("cls");
                        LogoConstante ();
      rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 19); cout<<"ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 20); cout<<"บ                                                       บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27,21);  cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
       rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(27, 18);   cout << "E s t a s  e n: R e A c t i v a r  C l i e n t e";
        rlutil::setColor(rlutil::WHITE);
       rlutil::locate(30, 20);
                        cout << "Ingrese ID del Cliente a Reactivar: ";rlutil::setColor(rlutil::BLUE);cin >> buscarId;

                        while(buscarId <= 0)
                        {
                             rlutil::setColor(rlutil::RED);
                            cout<<endl<< "ID Invalido. Intente nuevamente: ";
                           rlutil::setColor(rlutil::YELLOW); cin >> buscarId;
                        }
                        pos = reg.buscar(buscarId);
                        if(pos >= 0){
                            cli = reg.leer(pos);
                            if(cli.getActivo() == false){
                                cli.setActivo(true);
                                 rlutil::setColor(rlutil::WHITE);
                                cout <<endl<<endl<<"Ficha del cliente a reactivar:" << endl;
                               cout<<endl;
                                rlutil::setColor(rlutil::YELLOW);
                                cli.mostrar();

                                do
                                {
                                     rlutil::setColor(rlutil::YELLOW);
                                    cout<< "\nEsta seguro que desea reactivar a este cliente? (1=Si, 0=No): ";
                                    cin >> confirmacion;
                                    if(confirmacion != 1 && confirmacion != 0)
                                    {
                                rlutil::setColor(rlutil::RED);  cout <<endl<< "Error. Ingrese 1=Si y 0 = No." << endl;
                                    }
                                }
                                while(confirmacion != 1 && confirmacion != 0);

                                if(confirmacion == 1){
                                    if(reg.guardar(cli,pos)){

                                            system ("cls");

                                           LogoConstante ();
                                             rlutil::setColor(rlutil::GREEN);
                                        cout <<endl<<endl<< "\nCliente Reactivado Exitosamente." << endl;
                                    }else{
                                        rlutil::setColor(rlutil::RED);
                                        cout << "\nError al guardar la reactivacion en el archivo." << endl;
                                    }
                                }
                                else{
                                    // Si cancela, lo volvemos a desactivar/false (por si acaso, no se guarda)
                                    cli.setActivo(false);
                                    system ("cls");

                                       LogoConstante ();
                                    rlutil::setColor(rlutil::GREEN);
                                    cout <<endl<<endl<< "\nOperacion cancelada. El cliente sigue dado de baja." << endl;
                                }
                            }
                            else{
                                    system ("cls");

                                       LogoConstante ();
                                        rlutil::setColor(rlutil::RED);
                                cout <<endl<<endl<< "\nError: Ese ID especifico pertenece a un cliente que ya esta activo." << endl;
                            }
                        }
                        else
                        {
                             system ("cls");

                                       LogoConstante ();
                                        rlutil::setColor(rlutil::YELLOW);
                            cout <<endl<<endl<< "\nEl ID ingresado no existe en el archivo." << endl;
                        }
                   }
                }
            }

            cout <<endl<<endl;
             rlutil::setColor(rlutil::YELLOW);
            rlutil::anykey("Presione una tecla para volver al Menu Cliente...");


}
void MenuCliente::Listadeclientes() const {

system ("cls");

              LogoConstante ();   //logo por defecto , aparece en todos los menuss(barberia pacheco)


rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 19);   cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
 rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 20);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::RED);
rlutil::locate(27, 21);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::WHITE);
rlutil::locate(27, 22);   cout<< "บ                                                         บ";
rlutil::setColor(rlutil::BLUE);
rlutil::locate(27, 23);   cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
rlutil::setColor(rlutil::YELLOW);
rlutil::locate(29, 21); cout<<"E s t a s  e n:  L i s t a d o  D e  C l i e n t e s";

            ArchivoClientes reg;
            int total = reg.cantidadRegistros();
            bool hayClientesActivos = false; // ESTA ES NUESTRA BANDERA

            if(total > 0)
            {
                for(int i = 0; i < total; i++)
                {
                Cliente leidos = reg.leer(i);

                    // Solo mostramos si est๏ฟฝ activo
                    if(leidos.getActivo() == true)
                    {

                     rlutil::setColor(rlutil::YELLOW);
                     cout<<endl<<endl;
                      leidos.mostrar();
                        hayClientesActivos = true; // Si encontramos uno, la bandera cambia
                    }
                }

                // Al terminar el ciclo, si la bandera nunca cambio, avisamos
                if(hayClientesActivos == false)
                {
                rlutil::locate(3, 24);     cout << "No hay clientes activos registrados." << endl;
                }
            }
            else
            {
              rlutil::locate(3, 24);   cout << "El archivo de clientes esta vacio." << endl;
            }

        cout <<endl<<endl;
         rlutil::setColor(rlutil::YELLOW);
          rlutil::anykey("Presione cualquier tecla para volver al menu Cliente...");


}
