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
        rlutil::locate(27, 18); cout << " E s t a s  e n:  M e n u - S e r v i c i o s";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19); cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20); cout << "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21); cout << "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22); cout << "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23); cout << "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24); cout << "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25); cout << "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26); cout << "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27); cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 20); cout << "1- Crear Nuevo Servicio" << endl;
        rlutil::locate(32, 22); cout << "2- Editar Servicio" << endl;
        rlutil::locate(32, 24); cout << "3- Dar de baja / Reactivar Servicio" << endl;
        rlutil::locate(32, 26); cout << "4- Listado de Servicios" << endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29); cout << " Opcion 0 (cero) Para Salir Al Menu Principal..." << endl;
        rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout << "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: { CrearNuevoServicio(); break; }
            case 2: { EditarServicio(); break; }
            case 3: { GestionarEstado(); break; }
            case 4: { ListarServicios(); break; }
            case 0: {
                MenuManager volver;
                volver.MenuPrincipal();
                break;
            }
            default:
                system("cls");
                cout << "Opcion invalida. Ingresa un numero valido para acceder." << endl;
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
    rlutil::locate(27, 19); cout << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23); cout << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21); cout << "A l t a  D e  N u e v o  S e r v i c i o";

    cout << endl << endl;

    ServiciosManager manager;
    manager.crearServicio();
}

void MenuServicios::EditarServicio() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23); cout << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 18); cout << " E d i t a r  S e r v i c i o";

    cout << endl << endl;

    ServiciosManager manager;
    manager.editarServicio();
}

void MenuServicios::GestionarEstado() const {
    system("cls");
    LogoConstante();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(27, 18); cout << " E s t a s  e n:  S u b M e n u - E s t a d o  S e r v.";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 19); cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 20); cout << "บ                                                    บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout << "บ                                                    บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 22); cout << "บ                                                    บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 23); cout << "บ                                                    บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 24); cout << "บ                                                    บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 25); cout << "บ                                                    บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 26); cout << "บ                                                    บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 27); cout <<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

    cout << endl << endl;

    ServiciosManager manager;
    manager.gestionarEstadoServicio();
}

void MenuServicios::ListarServicios() const {
    system("cls");
    LogoConstante();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout << "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22); cout << "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23); cout << "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21); cout << "E s t a s  e n:  L i s t a d o  D e  S e r v i c i o s";

    cout << endl << endl;

    ServiciosManager manager;
    manager.listarServicios();
}
