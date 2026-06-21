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

void MenuCliente::InterfazMenuCliente() const {
    int opcion;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " E s t a s  e n:  M e n u   C l i e n t e s";

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 19); cout << "====================================================";
        rlutil::locate(27, 20); cout << "|                                                  |";
        rlutil::locate(27, 21); cout << "|                                                  |";
        rlutil::locate(27, 22); cout << "|                                                  |";
        rlutil::locate(27, 23); cout << "|                                                  |";
        rlutil::locate(27, 24); cout << "|                                                  |";
        rlutil::locate(27, 25); cout << "|                                                  |";
        rlutil::locate(27, 26); cout << "|                                                  |";
        rlutil::locate(27, 27); cout << "====================================================";

        rlutil::locate(32, 20);
        cout << "1- Crear Nuevo Cliente";

        rlutil::locate(32, 21);
        cout << "2- Editar Cliente";

        rlutil::locate(32, 22);
        cout << "3- Dar de baja / Reactivar Cliente";

        rlutil::locate(32, 23);
        cout << "4- Listado de Clientes";

        rlutil::locate(32, 24);
        cout << "5- Buscar Cliente por ID";

        rlutil::locate(32, 26);
        cout << "0- Volver al Menu Principal";

        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 29);
        cout << "Eleccion: #  ";

        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            CrearNuevoCliente();
            break;

        case 2:
            EditarCliente();
            break;

        case 3:
            Dardebaja_Reactivarcliente();
            break;

        case 4:
            Listadeclientes();
            break;

        case 5:
            BuscarClientePorID();
            break;

        case 0:
        {
            MenuManager volver;
            volver.MenuPrincipal();
            break;
        }

        default:
            system("cls");
            rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida. Ingresa un numero valido para acceder." << endl;

            rlutil::setColor(rlutil::WHITE);
            cout << "0 (cero) para volver al menu principal." << endl;
            cout << endl << endl;

            system("pause");
            system("cls");
        }
    } while (opcion != 0);
}

void MenuCliente::CrearNuevoCliente() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout << "==========================================================";
    rlutil::locate(27, 20); cout << "|                                                        |";
    rlutil::locate(27, 21); cout << "|                                                        |";
    rlutil::locate(27, 22); cout << "|                                                        |";
    rlutil::locate(27, 23); cout << "==========================================================";

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "A l t a  D e  N u e v o  C l i e n t e";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.crearNuevoCliente();
}

void MenuCliente::EditarCliente() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout << "==========================================================";
    rlutil::locate(27, 20); cout << "|                                                        |";
    rlutil::locate(27, 21); cout << "|                                                        |";
    rlutil::locate(27, 22); cout << "|                                                        |";
    rlutil::locate(27, 23); cout << "==========================================================";

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "E d i t a r  C l i e n t e";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.editarCliente();
}

void MenuCliente::Dardebaja_Reactivarcliente() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(27, 18);
    cout << " E s t a s  e n:  E s t a d o  C l i e n t e s";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout << "====================================================";
    rlutil::locate(27, 20); cout << "|                                                  |";
    rlutil::locate(27, 21); cout << "|                                                  |";
    rlutil::locate(27, 22); cout << "|                                                  |";
    rlutil::locate(27, 23); cout << "|                                                  |";
    rlutil::locate(27, 24); cout << "|                                                  |";
    rlutil::locate(27, 25); cout << "|                                                  |";
    rlutil::locate(27, 26); cout << "|                                                  |";
    rlutil::locate(27, 27); cout << "====================================================";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.gestionarEstadoCliente();
}

void MenuCliente::Listadeclientes() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout << "==========================================================";
    rlutil::locate(27, 20); cout << "|                                                        |";
    rlutil::locate(27, 21); cout << "|                                                        |";
    rlutil::locate(27, 22); cout << "|                                                        |";
    rlutil::locate(27, 23); cout << "==========================================================";

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "L i s t a d o  D e  C l i e n t e s";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.listarClientes();
}

void MenuCliente::BuscarClientePorID() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout << "==========================================================";
    rlutil::locate(27, 20); cout << "|                                                        |";
    rlutil::locate(27, 21); cout << "|                                                        |";
    rlutil::locate(27, 22); cout << "|                                                        |";
    rlutil::locate(27, 23); cout << "==========================================================";

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "B u s c a r  C l i e n t e  P o r  I D";

    cout << endl << endl;

    ClientesManager clienteManager;
    clienteManager.buscarClientePorID();
}
