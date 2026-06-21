#include <iostream>
#include "MenuPagos.h"
#include "MenuManager.h"
#include "PagosManager.h"
#include "Logo.h"
#include "facha.h"

using namespace std;

void MenuPagos::InterfazMenuPagos() const {
    int opcion;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " E s t a s  e n:  M e n u   P a g o s";

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

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 20);
        cout << "1- Registrar Pago";

        rlutil::locate(32, 21);
        cout << "2- Buscar Pago por ID";

        rlutil::locate(32, 22);
        cout << "3- Listado de Pagos";

        rlutil::locate(32, 23);
        cout << "4- Anular Pago";

        rlutil::locate(32, 26);
        cout << "0- Volver al Menu Principal";

        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 29);
        cout << "Eleccion: #  ";

        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
        case 1:
            RegistrarPago();
            break;

        case 2:
            BuscarPago();
            break;

        case 3:
            ListarPagos();
            break;

        case 4:
            AnularPago();
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
            cout << endl;
            system("pause");
            break;
        }

    } while(opcion != 0);
}

void MenuPagos::RegistrarPago() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "R e g i s t r a r  P a g o";

    cout << endl << endl;

    PagosManager manager;
    manager.registrarPago();
}

void MenuPagos::BuscarPago() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "B u s c a r  P a g o  P o r  I D";

    cout << endl << endl;

    PagosManager manager;
    manager.buscarPago();
}

void MenuPagos::ListarPagos() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "L i s t a d o  D e  P a g o s";

    cout << endl << endl;

    PagosManager manager;
    manager.listarPagos();
}

void MenuPagos::AnularPago() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "A n u l a r  P a g o";

    cout << endl << endl;

    PagosManager manager;
    manager.anularPago();
}
