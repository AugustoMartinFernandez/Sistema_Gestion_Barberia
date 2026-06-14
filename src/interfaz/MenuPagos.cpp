#include <iostream>
#include "MenuPagos.h"
#include "Logo.h"
#include "facha.h"
#include "PagosManager.h"
#include "MenuManager.h"
using namespace std;


void MenuPagos::InterfazMenuPagos() const{
    int opcion;

    do{
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18); cout << " E s t a s  e n:  M e n u   P a g o s";
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
        rlutil::locate(32, 20); cout << "1- Registrar Pago" << endl;
        rlutil::locate(32, 22); cout << "2- Listar Pagos" << endl;
        rlutil::locate(32, 24); cout << "3- Buscar Pago" << endl;
        rlutil::locate(32, 26); cout << "4- Anular Pago" << endl;


        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29); cout << " Opcion 0 (cero) Para Salir al Menu-Principal..." << endl;

        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 30); cout << "Eleccion: # ";

        rlutil::setColor(rlutil::BLUE);
        cin >> opcion;
        cin.ignore();

        switch(opcion){

        case 1:
            RegistrarPago();
            break;

        case 2:
            ListarPagos();
            break;

        case 3:
            BuscarPago();
            break;

        case 4:
            AnularPago();
            break;

        case 0:{
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
            break;
        }

    }while(opcion != 0);
}

void MenuPagos::RegistrarPago() const{
    PagosManager manager;
    manager.registrarPago();
}

void MenuPagos::ListarPagos() const{
    PagosManager manager;
    manager.listarPagos();
}

void MenuPagos::BuscarPago() const{
    PagosManager manager;
    manager.buscarPago();
}

void MenuPagos::AnularPago() const{
    PagosManager manager;
    manager.anularPago();
}
