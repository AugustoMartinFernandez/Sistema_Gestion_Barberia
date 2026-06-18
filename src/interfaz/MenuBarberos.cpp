#include <iostream>
#include "MenuBarberos.h"
#include "Logo.h"
#include "MenuManager.h"
#include "facha.h"
#include "BarberosManager.h"

using namespace std;

void MenuBarbero::InterfazMenuBarbero() const {
    int opcion;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " E s t a s  e n:  M e n u   B a r b e r o s";

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
        cout << "1- Cargar Nuevo Barbero";

        rlutil::locate(32, 21);
        cout << "2- Editar Informacion de Barbero";

        rlutil::locate(32, 22);
        cout << "3- Dar de baja / Reactivar Barbero";

        rlutil::locate(32, 23);
        cout << "4- Lista de Barberos";

        rlutil::locate(32, 24);
        cout << "5- Buscar Barbero por ID";

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
            BarberoNuevo();
            break;

        case 2:
            EditarInformacion();
            break;

        case 3:
            GestionarEstado();
            break;

        case 4:
            ListarBarberos();
            break;

        case 5:
            BuscarBarberoPorID();
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

void MenuBarbero::BarberoNuevo() const {
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
    cout << "A l t a  D e  N u e v o  B a r b e r o";

    cout << endl << endl;

    BarberosManager manager;
    manager.crearBarbero();
}

void MenuBarbero::EditarInformacion() const {
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
    cout << "E d i t a r  B a r b e r o";

    cout << endl << endl;

    BarberosManager manager;
    manager.editarBarbero();
}

void MenuBarbero::GestionarEstado() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(27, 18);
    cout << " E s t a s  e n:  E s t a d o  B a r b e r o";

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

    BarberosManager manager;
    manager.gestionarEstadoBarbero();
}

void MenuBarbero::ListarBarberos() const {
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
    cout << "L i s t a d o  D e  B a r b e r o s";

    cout << endl << endl;

    BarberosManager manager;
    manager.listarBarberos();
}

void MenuBarbero::BuscarBarberoPorID() const {
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
    cout << "B u s c a r  B a r b e r o  P o r  I D";

    cout << endl << endl;

    BarberosManager manager;
    manager.buscarBarberoPorID();
}
