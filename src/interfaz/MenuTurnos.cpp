#include <iostream>
#include "MenuTurnos.h"
#include "MenuManager.h"
#include "TurnosManager.h"
#include "Logo.h"
#include "facha.h"

using namespace std;

void MenuTurnos::InterfazMenuTurnos() const {
    int opcion;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " E s t a s  e n:  M e n u   T u r n o s";

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
        cout << "1- Crear Nuevo Turno";

        rlutil::locate(32, 21);
        cout << "2- Editar Turno";

        rlutil::locate(32, 22);
        cout << "3- Borrar / Cancelar Turno";

        rlutil::locate(32, 23);
        cout << "4- Listado de Turnos";

        rlutil::locate(32, 24);
        cout << "5- Buscar Turnos por Estado";

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
            CrearTurno();
            break;

        case 2:
            EditarTurno();
            break;

        case 3:
            BorrarTurno();
            break;

        case 4:
            ListarTurnos();
            break;

        case 5:
            ListarTurnosPorEstado();
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

    } while(opcion != 0);
}

void MenuTurnos::CrearTurno() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "A l t a  D e  N u e v o  T u r n o";

    cout << endl << endl;

    TurnosManager manager;
    manager.crearTurno();
}

void MenuTurnos::EditarTurno() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "E d i t a r  T u r n o";

    cout << endl << endl;

    TurnosManager manager;
    manager.editarTurno();
}

void MenuTurnos::BorrarTurno() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "B o r r a r  /  C a n c e l a r  T u r n o";

    cout << endl << endl;

    TurnosManager manager;
    manager.borrarTurno();
}

void MenuTurnos::ListarTurnos() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "L i s t a d o  D e  T u r n o s";

    cout << endl << endl;

    TurnosManager manager;
    manager.listarTurnos();
}

void MenuTurnos::ListarTurnosPorEstado() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21);
    cout << "T u r n o s  P o r  E s t a d o";

    cout << endl << endl;

    TurnosManager manager;
    manager.listarTurnosPorEstado();
}
