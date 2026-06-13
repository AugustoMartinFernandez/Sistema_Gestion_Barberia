#include <iostream>
using namespace std;
#include "MenuTurnos.h"
#include "MenuManager.h"
#include "Logo.h"
#include "facha.h"
#include "Turno.h"
#include "ArchivoTurnos.h"
#include "ArchivoClientes.h"
#include "BarberoArchivo.h"
#include "ArchivoConfiguracion.h"

void MenuTurnos::InterfazMenuTurnos () const {
    int opcion;
    do {
        system("cls");
        LogoConstante();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18); cout << " E s t a s  e n:  M e n u - T u r n o s";
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
        rlutil::locate(32, 20); cout << "1- Crear Turno" << endl;
        rlutil::locate(32, 22); cout << "2- Editar Turno" << endl;
        rlutil::locate(32, 24); cout << "3- Borrar Turno Programado" << endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29); cout << " Opcion 0 (cero) Para Salir al Menu-Principal..." << endl;
        rlutil::setColor(rlutil::RED);  rlutil::locate(32, 30); cout << "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE); cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: CrearTurno(); break;
            case 2: EditarTurno(); break;
            case 3: BorrarTurno(); break;
            case 0: break;
            default: cout << "Opcion invalida."; system("pause");
        }
    } while (opcion != 0);
}

void MenuTurnos::CrearTurno() const {
    cout << endl << "--- AGENDAR NUEVO TURNO ---" << endl;
    Turno t;
    t.cargar(); // Pide datos de cliente, barbero, servicio, fecha y hora

    // 1. Validar existencia de Cliente
    ArchivoClientes arcCli;
    if (arcCli.buscar(t.getIdCliente()) == -1) {
        cout << "\n[ERROR] El ID de Cliente ingresado no existe." << endl;
        system("pause"); return;
    }

    // 2. Validar existencia de Barbero
    BarberoArchivo arcBar;
    if (arcBar.buscar(t.getIdBarbero()) == -1) {
        cout << "\n[ERROR] El ID de Barbero ingresado no existe." << endl;
        system("pause"); return;
    }

    // 3. Asignar ID autoincremental y guardar
    ArchivoConfiguracion config;
    t.setId(config.getProximoIdTurno());

    ArchivoTurnos arcTurno;
    if (arcTurno.guardar(t)) {
        cout << "\n[EXITO] Turno agendado con ID: " << t.getId() << endl;
    } else {
        cout << "\n[ERROR] No se pudo guardar el turno." << endl;
    }
    system("pause");
}

void MenuTurnos::EditarTurno() const {
    cout << "Funcionalidad de Edicion en desarrollo..." << endl;
    system("pause");
}

void MenuTurnos::BorrarTurno() const {
    cout << "Funcionalidad de Borrado en desarrollo..." << endl;
    system("pause");
}
