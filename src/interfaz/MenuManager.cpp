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

void MenuManager::MenuPrincipal () const {
    int opcion;
    do {
        system("cls");
        LogoConstante();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18); cout<< " E s t a s  e n:  M e n u - P r i n c i p a l";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19); cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21); cout<<"บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22); cout<<"บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23); cout<<"บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26); cout<<"บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27); cout<<"บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 28); cout<<"บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 29); cout<< "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 20); cout << "[ 1 ] Turnos" << endl;
        rlutil::locate(32, 22); cout << "[ 2 ] Acceder al menu Para clientes" << endl;
        rlutil::locate(32, 24); cout << "[ 3 ] Acceder al menu Barberos" << endl;
        rlutil::locate(32, 26); cout << "[ 4 ] Informes" << endl;
        rlutil::locate(32, 28); cout << "[ 5 ] Pagos" << endl;
        rlutil::locate(32, 30); cout << "[ 6 ] Servicios" << endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 30); cout << " Opcion 0 (cero) Para Salir..." << endl;
        rlutil::setColor(rlutil::RED); rlutil::locate(32, 31); cout << "Eleccion: # ";
        rlutil::setColor(rlutil::BLUE); cin >> opcion;

        switch (opcion) {
            case 1: { MenuTurnos turn; turn.InterfazMenuTurnos(); break; }
            case 2: { MenuCliente client; client.InterfazMenuCliente(); break; }
            case 3: { MenuBarbero barbe; barbe.InterfazMenuBarbero(); break; }
            case 4: { MenuInformes infor; infor.InterfazMenuinformes(); break; }
            case 5: { MenuPagos pago; pago.InterfazMenuPagos(); break; }
            case 6: { MenuServicios servi; servi.InterfazMenuServicios(); break; }
            case 0: {
                system("cls");
                cout << "Gracias por utilizar el programa..." << endl;
                break;
            }
            default:
                system("cls");
                cout << "Opcion invalida." << endl;
                system("pause");
        }
    } while (opcion != 0);
}

void MenuManager::Creditos() const {
    cout << "Sistema gestion Barberia - Equipo 2026";
}
