#include <iostream>
using namespace std;
#include "MenuInformes.h"
#include "Logo.h"
#include "MenuManager.h"
#include "facha.h"
#include "Servicio.h"
#include "ArchivoServicios.h"
#include "Pago.h"
#include "Fecha.h"
#include "InformesManager.h"

void MenuInformes::InterfazMenuinformes ()const
{
    int opcion;

    do
    {
        system("cls");
        LogoConstante ();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout<< " E s t a s  e n:  M e n u   I n f o r m e s";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19);
        cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27);
        cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 21);
        cout<<"1-  Informes Financieros (Recaudacion, etc.) "<<endl;
        rlutil::locate(32, 25);
        cout<<"2-  Informes de gestion de clientes y agenda "<<endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29);
        cout<<"Opcion 0 (cero) Para Salir Del Programa..."<<endl;
        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 30);
        cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            InformesFinancieros ();
            break;
        }
        case 2:
        {
            InformesGestionClientes ();
            break;
        }
        case 0:
        {
            MenuManager volver;
            volver.MenuPrincipal ();
            break;
        }

        default:
            system ("cls");
            cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
            cout<<" 0 (cero) para volver al menu principal."<<endl;
            cout<<endl<<endl;
            system ("pause");
            system ("cls");
        }

    }
    while ( opcion != 0);

}



void  MenuInformes::InformesFinancieros ()const
{
    int opcion;

    do
    {
        system("cls"); // limpia pantalla ;
        LogoConstante ();   //logo por defecto , aparece en todos los menus (barberia pacheco)
        rlutil::locate(27, 18);
        cout<< " E s t a s  e n:  S u b M e n u - I n f . F i n a n c i e r o s ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19);
        cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27);
        cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";


        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 20);
        cout<<"1-  Recaudacion (Diaria, Mensual, Anual.) "<<endl;
        rlutil::locate(32, 22);
        cout<<"2-  Servicio mas caro que supere $5000 "<<endl;
        rlutil::locate(32, 24);
        cout<<"3-  Barbero que mas cortes hizo"<<endl;
        rlutil::locate(32, 26);
        cout<<"4-  Metodos de pago utilizados "<<endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29);
        cout<<"Opcion 0 (cero) Para Salir Del Programa..."<<endl;
        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 30);
        cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
case 1:
{
    int opcionRec;
    InformesManager manager;

    cout << "---- RECAUDACION ----" << endl;
    cout << "1 - Recaudacion por dia" << endl;
    cout << "2 - Recaudacion por mes" << endl;
    cout << "3 - Recaudacion por anio" << endl;
    cout << "0 - Volver" << endl;
    cout << "Opcion: ";
    cin >> opcionRec;

    switch(opcionRec)
    {
        case 1:
            manager.recaudacionPorDia();
            break;

        case 2:
            manager.recaudacionPorMes();
            break;

        case 3:
            manager.recaudacionPorAnio();
            break;

        case 0:
            break;

        default:
            cout << "Opcion invalida." << endl;
            system("pause");
            break;
    }

} break;

        case 2:
        {
            Servicio serv;
            ArchivoServicios archserv;
            float maximo;
            int idmaximo;
            bool bandera = true;
            for (int i = 0; i < archserv.cantidadRegistros(); i++)
            {
                serv = archserv.leer(i);
                if  (bandera == 1 && serv.getPrecio() > 5000)
                {
                    maximo = serv.getPrecio();
                    idmaximo = serv.getId();
                    bandera = 0;
                }

                else if ( bandera == 0 && serv.getPrecio() > maximo)
                {
                    maximo = serv.getPrecio();
                    idmaximo = serv.getId();
                }
            }
            if (bandera == 1)
            {
                cout << "No hay servicio con precio mayor a $5000" << endl;
            }
            else
            {
                cout << "ID de servicio mas caro: " << idmaximo << endl;
                cout << "Valor: $" << maximo << endl;
            }
            cout << endl;
            system ("pause");
        }
        break;

        case 3:
        {
        } break;

        case 4:
        {     } break;
        case 0:
        {
            InterfazMenuinformes ();
            break;
        }

        default:
            system ("cls");
            cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
            cout<<" 0 (cero) para volver al Menu Informes..."<<endl;
            cout<<endl<<endl;
            system ("pause");
            system ("cls");
        }
    }
    while(opcion != 0);

}


void MenuInformes::InformesGestionClientes ()const
{
    int opcion;



    do
    {
        system("cls"); // limpia pantalla ;
        LogoConstante ();  //logo del programa
        rlutil::locate(27, 18);
        cout<< " E s t a s  e n:  S u b M e n u - I n f . G e s t i o n C l i e n t";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19);
        cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27);
        cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";


        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 20);
        cout<<"1-  Clientes Frecuentes"<<endl;
        rlutil::locate(32, 24);
        cout<< "2- Turnos realizados y cancelados"<<endl;



        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29);
        cout<<"Opcion 0 (cero) Para Salir Del Programa..."<<endl;
        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 30);
        cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        case 2:
        case 0:
        {
            InterfazMenuinformes();
            break;
        }

        default:
            system ("cls");
            cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
            cout<<" 0 (cero) para volver al Menu Informes..."<<endl;
            cout<<endl<<endl;
            system ("pause");
            system ("cls");

        }
    }
    while ( opcion != 0);

}


