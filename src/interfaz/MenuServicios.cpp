#include <iostream>
#include "MenuServicios.h"
#include "MenuManager.h"
#include "ServiciosManager.h"
#include "Logo.h"
#include "facha.h"

using namespace std;

void MenuServicios::InterfazMenuServicios() const {
    int opcion;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " E s t a s  e n:  M e n u   S e r v i c i o s";

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
        cout << "1- Crear Nuevo Servicio";

        rlutil::locate(32, 21);
        cout << "2- Editar Servicio";

        rlutil::locate(32, 22);
        cout << "3- Dar de baja / Reactivar Servicio";

        rlutil::locate(32, 23);
        cout << "4- Listado de Servicios";

        rlutil::locate(32, 24);
        cout << "5- Buscar Servicio por ID";

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
            CrearNuevoServicio();
            break;

        case 2:
            EditarServicio();
            break;

        case 3:
            GestionarEstado();
            break;

        case 4:
            ListarServicios();
            break;

        case 5:
            BuscarServicioPorID();
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

void MenuServicios::CrearNuevoServicio() const {
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
    cout << "A l t a  D e  N u e v o  S e r v i c i o";

    cout << endl << endl;

    ServiciosManager manager;
    manager.crearServicio();
}

void MenuServicios::EditarServicio() const {
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
    cout << "E d i t a r  S e r v i c i o";

    cout << endl << endl;

    ServiciosManager manager;
    manager.editarServicio();
}

void MenuServicios::GestionarEstado() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(27, 18);
    cout << " E s t a s  e n:  E s t a d o  S e r v i c i o";

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

    ServiciosManager manager;
    manager.gestionarEstadoServicio();
}

void MenuServicios::ListarServicios() const {
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
    cout << "L i s t a d o  D e  S e r v i c i o s";

    cout << endl << endl;

    ServiciosManager manager;
    manager.listarServicios();
}

void MenuServicios::BuscarServicioPorID() const {
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
    cout << "B u s c a r  S e r v i c i o  P o r  I D";

    cout << endl << endl;

    ServiciosManager manager;
    manager.buscarServicioPorID();
}
