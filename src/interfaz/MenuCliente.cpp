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

 rlutil::locate(32, 20);       cout<<"1- Crear Nuevo Cliente "<<endl;
 rlutil::locate(32, 22);       cout<<"2- Editar Cliente  "<<endl;
 rlutil::locate(32, 24);       cout<<"3- Dar de baja / Reactivar cliente "<<endl;
 rlutil::locate(32, 26);        cout<<"4- Listado de  clientes "<<endl;

    rlutil::setColor(rlutil::WHITE);
 rlutil::locate(32, 29);cout<< " Opcion 0 (cero) Para Salir Del Programa..."<<endl;
 rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout<< "Eleccion: #  ";
  rlutil::setColor(rlutil::BLUE);cin>>opcion;
                                  cin.ignore(); // LIMPIEZA DEL BUFFER:  para que cin.getline() funcione despues

        switch (opcion)
        {
        case 1:

         CrearNuevoCliente(); break;

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

    cout << endl << "--- ALTA DE NUEVO CLIENTE ---" << endl;
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


}
void MenuCliente::EditarCliente() const {

int buscarId,pos,cantidad;
    ArchivoClientes reg;
        Cliente cli;

            bool hayClientesActivos = false;
            cantidad = reg.cantidadRegistros();

            if(cantidad == 0)
            {
            cout << "No hay clientes en el archivo a modificar." <<endl;
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
                    cout << "No hay clientes activos en el sistema para modificar." << endl;
                }
                else
                {
                    cout << "--- MODIFICAR CLIENTES ---" <<endl;
                    cout << "Ingrese ID del Cliente a modificar: "<<endl;
                    cin >> buscarId;

                    while(buscarId <= 0)
                    {
                        cout << "ID Invalido. Intente nuevamente: ";
                        cin >> buscarId;
                    }

                    pos = reg.buscar(buscarId);
                    if(pos >= 0)
                    {
                        cli = reg.leer(pos);
                        if(cli.getActivo()==true)
                        {
                            cout<< "Ficha actual del cliente:" << endl;
                            cli.mostrar();
                            cout<< "Ingrese los nuevos datos:" << endl;
                            cin.ignore();
                            cli.cargar();
                            if(reg.guardar(cli,pos))
                            {
                                cout << "\nCliente modificado correctamente." << endl;
                            }
                            else
                            {
                                cout << "\nNo se pudo guardar la modificacion en el archivo." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nNo se puede modificar un cliente dado de baja" <<endl;
                        }
                    }
                    else
                    {
                        cout << "\nEl ID ingresado no existe en el archivo." << endl;
                    }
                }
            }

        system("pause");


}
void MenuCliente::Dardebaja_Reactivarcliente() const {
                int subOpcion;
            cout << "--- ESTADO DE CLIENTES ---" << endl;
            cout << "1- Dar de baja a un cliente" << endl;
            cout << "2- Reactivar a un cliente" << endl;
            cout << "Opcion: # ";
            cin >> subOpcion;

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
                        cout << "\n--- DAR DE BAJA ---" << endl;
                        cout << "Ingrese ID del Cliente a dar de baja: ";
                        cin >> buscarId;

                        while(buscarId <= 0)
                        {
                            cout << "ID Invalido. Intente nuevamente: ";
                            cin >> buscarId;
                        }
                        pos = reg.buscar(buscarId);
                        if(pos >= 0){
                            cli = reg.leer(pos);
                            if(cli.getActivo()==true){
                                cout << "Ficha actual del cliente:" << endl;
                                cli.mostrar();

                                do
                                {
                                    cout << "\nEsta seguro que desea dar de baja a este cliente? (1=Si, 0=No): ";
                                    cin >> confirmacion;
                                    if(confirmacion != 1 && confirmacion != 0)
                                    {
                                        cout << "Error. Ingrese 1=Si y 0 = No." << endl;
                                    }
                                }
                                while(confirmacion != 1 && confirmacion != 0);

                                if(confirmacion == 1){
                                    cli.setActivo(false);
                                    if(reg.guardar(cli,pos)){
                                        cout << "\nCliente dado de Baja Exitosamente." << endl;
                                    }else{
                                        cout << "\nError al guardar la baja en el archivo." << endl;
                                    }
                                }
                                else{
                                    cout << "\nOperacion cancelada. No se dio de Baja al cliente." << endl;
                                }
                            }
                            else{
                                cout << "\nError: Ese ID especifico ya pertenece a un cliente dado de baja." << endl;
                            }
                        }
                        else{
                            cout << "\nEl ID ingresado no existe en el archivo." << endl;
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
                    cout << "\nNo hay clientes dados de baja en el sistema para reactivar." << endl;
                   }else{
                        cout << "\n--- REACTIVAR CLIENTE ---" << endl;
                        cout << "Ingrese ID del Cliente a reactivar: ";
                        cin >> buscarId;

                        while(buscarId <= 0)
                        {
                            cout << "ID Invalido. Intente nuevamente: ";
                            cin >> buscarId;
                        }
                        pos = reg.buscar(buscarId);
                        if(pos >= 0){
                            cli = reg.leer(pos);
                            if(cli.getActivo() == false){
                                cli.setActivo(true);
                                cout << "Ficha del cliente a reactivar:" << endl;
                                cli.mostrar();

                                do
                                {
                                    cout << "\nEsta seguro que desea reactivar a este cliente? (1=Si, 0=No): ";
                                    cin >> confirmacion;
                                    if(confirmacion != 1 && confirmacion != 0)
                                    {
                                        cout << "Error. Ingrese 1=Si y 0 = No." << endl;
                                    }
                                }
                                while(confirmacion != 1 && confirmacion != 0);

                                if(confirmacion == 1){
                                    if(reg.guardar(cli,pos)){
                                        cout << "\nCliente Reactivado Exitosamente." << endl;
                                    }else{
                                        cout << "\nError al guardar la reactivacion en el archivo." << endl;
                                    }
                                }
                                else{
                                    // Si cancela, lo volvemos a desactivar/false (por si acaso, no se guarda)
                                    cli.setActivo(false);
                                    cout << "\nOperacion cancelada. El cliente sigue dado de baja." << endl;
                                }
                            }
                            else{
                                cout << "\nError: Ese ID especifico pertenece a un cliente que ya esta activo." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nEl ID ingresado no existe en el archivo." << endl;
                        }
                   }
                }
            }
            system("pause");


}
void MenuCliente::Listadeclientes() const {


  cout << endl << "--- LISTADO DE CLIENTES ---" << endl;
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


}
