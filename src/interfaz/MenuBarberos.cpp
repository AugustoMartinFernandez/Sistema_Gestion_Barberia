#include <iostream>
#include "MenuBarberos.h"
#include "Logo.h"
#include "MenuManager.h"
#include "facha.h"
#include "BarberosManager.h"
using namespace std;

void MenuBarbero::InterfazMenuBarbero () const {
    int opcion;

    do {
        system("cls");
        LogoConstante ();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18); cout<< " E s t a s  e n:  M e n u - B a r b e r o s";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19); cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26); cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27); cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 20); cout<<"1- ฟSos un Barbero nuevo? " << endl;
        rlutil::locate(32, 22); cout<<"2- Editar Informacion de Barbero. " << endl;
        rlutil::locate(32, 24); cout<<"3- Dar de baja / Reactivar barbero " << endl;
        rlutil::locate(32, 26); cout<<"4- Lista de Barberos. " << endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29); cout<< " Opcion 0 (cero) Para Salir Del Programa..." << endl;
        rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin >> opcion;
        cin.ignore(); // Limpieza del buffer fundamental para que los cargar() funcionen

        switch (opcion) {
            case 1: { BarberoNuevo(); break; }
            case 2: { EditarInformacion(); break; }
            case 3: { GestionarEstado(); break; }
            case 4: { ListarBarberos(); break; }
            case 0: {
                MenuManager volver;
                volver.MenuPrincipal ();
                break;
            }
            default:
                system ("cls");
                cout << "Opcion invalida. Ingresa un numero valido para acceder." << endl;
                cout << "0 (cero) para volver al menu principal." << endl;
                cout << endl << endl;
                system ("pause");
                system ("cls");
        }
    } while ( opcion != 0);
}

void MenuBarbero::BarberoNuevo() const {
    system ("cls");
    LogoConstante ();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23); cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21); cout<<"A l t a  D e  N u e v o  B a r b e r o";

    cout << endl << endl;

    BarberosManager manager;
    manager.crearBarbero();
}

void MenuBarbero::EditarInformacion() const {
    system ("cls");
    LogoConstante ();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23); cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 18); cout<<" E d i t a r  B a r b e r o";

    cout << endl << endl;

    BarberosManager manager;
    manager.editarBarbero();
}

void MenuBarbero::GestionarEstado() const {
    system ("cls");
    LogoConstante ();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(27, 18); cout<< " E s t a s  e n:  S u b M e n u - E s t a d o  B a r b e r o";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 19); cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 20); cout<< "บ                                                    บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout<< "บ                                                    บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 22); cout<< "บ                                                    บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 23); cout<< "บ                                                    บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 24); cout<< "บ                                                    บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 25); cout<< "บ                                                    บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 26); cout<< "บ                                                    บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 27); cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

    cout << endl << endl;

    BarberosManager manager;
    manager.gestionarEstadoBarbero();
}

void MenuBarbero::ListarBarberos () const {
    system ("cls");
    LogoConstante ();

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 19); cout<< "ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 20); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::RED);
    rlutil::locate(27, 21); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(27, 22); cout<< "บ                                                          บ";
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(27, 23); cout<< "ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(29, 21); cout<<"E s t a s  e n:  L i s t a d o  D e  B a r b e r o s";

    cout << endl << endl;

    BarberosManager manager;
    manager.listarBarberos();
}
