#include <iostream>
#include "MenuManager.h"
#include "facha.h"
#include "Logo.h"
#include "MenuCliente.h"
#include "MenuBarberos.h"
#include "MenuTurnos.h"
#include "MenuInformes.h"
#include "MenuPagos.h"
#include "MenuServicios.h"

using namespace std;

void MenuManager::MenuPrincipal() const {
    int opcion;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " E s t a s  e n:  M e n u   P r i n c i p a l";

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 19); cout << "====================================================";
        rlutil::locate(27, 20); cout << "|                                                  |";
        rlutil::locate(27, 21); cout << "|                                                  |";
        rlutil::locate(27, 22); cout << "|                                                  |";
        rlutil::locate(27, 23); cout << "|                                                  |";
        rlutil::locate(27, 24); cout << "|                                                  |";
        rlutil::locate(27, 25); cout << "|                                                  |";
        rlutil::locate(27, 26); cout << "|                                                  |";
        rlutil::locate(27, 27); cout << "|                                                  |";
        rlutil::locate(27, 28); cout << "|                                                  |";
        rlutil::locate(27, 29); cout << "====================================================";

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 20);
        cout << "1- Turnos";

        rlutil::locate(32, 21);
        cout << "2- Clientes";

        rlutil::locate(32, 22);
        cout << "3- Barberos";

        rlutil::locate(32, 23);
        cout << "4- Servicios";

        rlutil::locate(32, 24);
        cout << "5- Pagos";

        rlutil::locate(32, 25);
        cout << "6- Informes";

        rlutil::locate(32, 27);
        cout << "0- Salir del sistema";

        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 31);
        cout << "Eleccion: # ";

        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            MenuTurnos turnos;
            turnos.InterfazMenuTurnos();
            break;
        }

        case 2:
        {
            MenuCliente clientes;
            clientes.InterfazMenuCliente();
            break;
        }

        case 3:
        {
            MenuBarbero barberos;
            barberos.InterfazMenuBarbero();
            break;
        }

        case 4:
        {
            MenuServicios servicios;
            servicios.InterfazMenuServicios();
            break;
        }

        case 5:
        {
            MenuPagos pagos;
            pagos.InterfazMenuPagos();
            break;
        }

        case 6:
        {
            MenuInformes informes;
            informes.InterfazMenuinformes();
            break;
        }

        case 0:
            system("cls");
            rlutil::setColor(rlutil::WHITE);
            cout << "Gracias por utilizar el programa..." << endl;
            break;

        default:
            system("cls");
            rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida." << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            break;
        }

    } while (opcion != 0);
}

void MenuManager::Creditos() const {
    cout << "Sistema gestion Barberia - Equipo 42 TUP 2026" << endl;
}
