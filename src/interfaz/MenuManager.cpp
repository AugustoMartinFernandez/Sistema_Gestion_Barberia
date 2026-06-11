#include <iostream>
#include "MenuManager.h"
#include "Fecha.h"
#include "Hora.h"
#include "facha.h"

#include "Cliente.h"
#include "ArchivoConfiguracion.h"
#include "ArchivoClientes.h"
using namespace std;

void MenuManager::LogoPorDefecto ()const {

Fecha fecha;
Hora hora;

rlutil::setColor(rlutil::YELLOW);
 rlutil::locate(27, 3);   cout<< "���������������������������������������ͻ";
rlutil::locate(27, 4);    cout<< "�                                       �";
rlutil::locate(27, 5);    cout<< "�                                       �";
rlutil::locate(27, 6);    cout<< "�                                       �";
rlutil::locate(27, 7);    cout<< "�                                       �";
rlutil::locate(27, 8);    cout<< "�                                       �";
rlutil::locate(27, 9);    cout<< "�                                       �";
rlutil::locate(27, 10);   cout<< "���������������������������������������ͼ";

  rlutil::locate(32, 4);   cout << "=== Barberia Pacheco ==="<<endl;
    rlutil::locate(32, 6); cout << "--- Fecha: " <<fecha.toString()<<endl;
   rlutil::locate(32, 8);  cout << "--- Hora: " <<hora.toString()<<endl;
  rlutil::locate(32, 9);  cout <<"--------------------------"<<endl;
}

void MenuManager::MuestroLogo ()const {
cout<< R"(
    ===================================================================================

  �����ۻ  ����ۻ �����ۻ �����ۻ ������ۻ�����ۻ �ۻ ����ۻ
  ������ۻ������ۻ������ۻ������ۻ������ͼ������ۻ�ۺ������ۻ
  ������ɼ������ۺ������ɼ������ɼ����ۻ  ������ɼ�ۺ������ۺ
  ������ۻ������ۺ������ۻ������ۻ����ͼ  ������ۻ�ۺ������ۺ
  ������ɼ�ۺ  �ۺ�ۺ  �ۺ������ɼ������ۻ�ۺ  �ۺ�ۺ�ۺ  �ۺ
  �����ͼ �ͼ  �ͼ�ͼ  �ͼ�����ͼ ������ͼ�ͼ  �ͼ�ͼ�ͼ  �ͼ

          �����ۻ  ����ۻ  �����ۻ�ۻ  �ۻ������ۻ �����ۻ �����ۻ
          ������ۻ������ۻ������ͼ�ۺ  �ۺ������ͼ������ͼ�������ۻ
          ������ɼ������ۺ�ۺ     ������ۺ����ۻ  �ۺ     �ۺ   �ۺ
          �����ͼ ������ۺ�ۺ     ������ۺ����ͼ  �ۺ     �ۺ   �ۺ
          �ۺ     �ۺ  �ۺ������ۻ�ۺ  �ۺ������ۻ������ۻ�������ɼ
          �ͼ     �ͼ  �ͼ �����ͼ�ͼ  �ͼ������ͼ �����ͼ �����ͼ

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
 
  
  int opcion;

  rlutil::setColor(rlutil::YELLOW);  /// cAmbia el color del logo / editar dps.  .
 MuestroLogo();



  do {
    system("cls"); // limpia pantalla ;
   LogoPorDefecto ();
  rlutil::setColor(rlutil::RED);
   rlutil::setColor(rlutil::WHITE);
  rlutil::setColor(rlutil::BLUE);

rlutil::setColor(rlutil::RED); rlutil::locate(35, 12); cout<< "Menu Princial";

rlutil::setColor(rlutil::WHITE);


 rlutil::locate(16, 13);      cout << "�� ��";
rlutil::locate(16, 14);       cout << "� � � ";
rlutil::locate(16, 15);       cout << "          ";
rlutil::locate(16, 16);       cout << "�����";
rlutil::locate(16, 17);       cout << "� ��";
rlutil::locate(16, 18);       cout << "� ";
rlutil::locate(16, 19);       cout << "�����";
rlutil::locate(16, 20);       cout << "        " ;
rlutil::locate(16, 21);       cout << "�� �";
rlutil::locate(16, 22);       cout << "� �� ";
rlutil::locate(16, 23);       cout << "            ";
rlutil::locate(16, 24);       cout << "�   �";
rlutil::locate(16, 25);       cout << "����� ";
rlutil::locate(16, 26);




 rlutil::locate(27, 13);   cout<< "����������������������������������������������������ͻ";
rlutil::locate(27, 14);    cout<< "�                                                    �";
rlutil::locate(27, 15);    cout<< "�                                                    �";
rlutil::locate(27, 16);    cout<< "�                                                    �";
rlutil::locate(27, 17);    cout<< "�                                                    �";
rlutil::locate(27, 18);    cout<< "�                                                    �";
rlutil::locate(27, 19);    cout<< "�                                                    �";
rlutil::locate(27, 20);    cout<< "�                                                    �";
rlutil::locate(27, 21);    cout<< "�                                                    �";
rlutil::locate(27, 22);    cout<< "�                                                    �";
rlutil::locate(27, 23);    cout<< "�                                                    �";
rlutil::locate(27, 24);    cout<< "�                                                    �";
rlutil::locate(27, 25);    cout<< "�                                                    �";
rlutil::locate(27, 26);   cout<<  "����������������������������������������������������ͼ";

rlutil::setColor(rlutil::BLUE);
rlutil::locate(32, 15);cout << "[ 1 ] Turnos (Agendar un turno, borrar turnos)"<<endl;
rlutil::setColor(rlutil::RED);
rlutil::locate(32, 18);cout << "[ 2 ] Acceder al menu  Para clientes"<<endl;
 rlutil::setColor(rlutil::WHITE);
rlutil::locate(32, 21);cout << "[ 3 ] Acceder al menu Barberos  "<<endl;
 rlutil::setColor(rlutil::BLUE);
rlutil::locate(32, 24);cout << "[ 4 ] Informes..."<<endl<<endl;
rlutil::setColor(rlutil::RED);


rlutil::setColor(rlutil::RED);
 rlutil::locate(32, 27);cout<< "Elegir una opcion,  0 (cero)  para salir"<<endl;
 rlutil::setColor(rlutil::WHITE);  rlutil::locate(32, 28); cout<< "Opcion: # ";
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
   }(while opcion != 0);
}


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
            break;
        }
        case 2:
        {
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
        break;
        }
    case 3:
        {
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
                // SUBOPCION 1: LOGICA DE BAJA L�GICA
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
            break;
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

                    // Solo mostramos si est� activo
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

void MenuManager::MenuBarberos()const
{
    system("cls"); // limpia pantalla ;
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

    cout<<"1- �Sos un Barbero nuevo? "<<endl;
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

void MenuManager::MenuTurnos()const
{
    system("cls"); // limpia pantalla ;
    int opcion;
    Fecha fecha;
    Hora hora;

void MenuManager::MenuTurnos()const{
     
   MenuManager manager;
   int opcion;



  //  do {
   system("cls"); // limpia pantalla ;
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
     
    /*
    */
}



 void MenuManager::MuestroInformes()const{
      
   MenuManager manager;

   int opcion;

 do {
 system("cls"); // limpia pantalla ;
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
   } (while opcion != 0);
    */
}


void MenuManager::SubMenuInfFinancieros ()const
{
    system("cls"); // limpia pantalla ;
    Fecha fecha;
    Hora hora;
    int opcion;

 void MenuManager::SubMenuInfFinancieros ()const {
       system("cls"); // limpia pantalla ;
   MenuManager  manager;

   int opcion;


  do {
     system("cls"); // limpia pantalla ;
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
    }(while opcion != 0);
     */
}

void MenuManager::SubMenuInfGestionClientes () const
{
    system("cls"); // limpia pantalla ;
    Fecha fecha;
    Hora hora;
    int opcion;

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
