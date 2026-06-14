#include <iostream>
#include "MenuCliente.h"
#include "MenuManager.h"
#include "ClientesManager.h"
#include "Cliente.h"
#include "ArchivoConfiguracion.h"
#include "ArchivoClientes.h"
#include "facha.h"
#include "Logo.h"

using namespace std;

void MenuCliente::InterfazMenuCliente () const
{
    int opcion;

    do
    {
        system("cls"); // limpia pantalla ;
        LogoConstante ();   //logo por defecto , aparece en todos los menuss(barberia pacheco)
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout<< " E s t a s  e n:  M e n u   C l i e n t e s";
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
        rlutil::locate(32, 22);
        rlutil::locate(32, 24);
        rlutil::locate(32, 26);

        rlutil::locate(32, 20);
        cout<<"1- Crear Nuevo Cliente "<<endl;
        rlutil::locate(32, 22);
        cout<<"2- Editar Cliente  "<<endl;
        rlutil::locate(32, 24);
        cout<<"3- Dar de baja / Reactivar cliente "<<endl;
        rlutil::locate(32, 26);
        cout<<"4- Listado de  clientes "<<endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 28);
        cout<< " Opcion 0 (cero) Para Salir Al Menu Principal..."<<endl;
        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 29);
        cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin>>opcion;
        cin.ignore(); // LIMPIEZA DEL BUFFER:  para que cin.getline() funcione despues

        switch (opcion)
        {
        case 1: { CrearNuevoCliente(); break; }
        case 2: { EditarCliente(); break; }
        case 3: { Dardebaja_Reactivarcliente(); break; }
        case 4: { Listadeclientes(); break; }
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

void MenuCliente::CrearNuevoCliente() const
{
    system ("cls");
    LogoConstante ();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19);
    cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23);
    cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout<<"A l t a  D e  N u e v o  C l i e n t e";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.crearNuevoCliente();
}

void MenuCliente::EditarCliente() const
{
    system ("cls");
    LogoConstante ();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19);
    cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23);
    cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 18);
    cout<<" E d i t  D e  C l i e n t e";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.editarCliente();
}

void MenuCliente::Dardebaja_Reactivarcliente() const
{
    system ("cls");
    LogoConstante ();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(27, 18);
    cout<< " E s t a s  e n:  S u b m e n u - E s t a d o  C l i e n t e s";
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

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.gestionarEstadoCliente();
}

void MenuCliente::Listadeclientes() const
{
    system ("cls");
    LogoConstante ();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19);
    cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22);
    cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23);
    cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout<<"E s t a s  e n:  L i s t a d o  D e  C l i e n t e s";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.listarClientes();
}
