#include <iostream>
#include "MenuInformes.h"
#include "Logo.h"
#include "MenuManager.h"
#include "facha.h"
#include "Servicio.h"
#include "ArchivoServicios.h"
#include "ArchivoClientes.h"
#include "Cliente.h"
#include "ArchivoTurnos.h"
#include "Turno.h"
#include "ArchivoPagos.h"
#include "Pago.h"
#include "BarberoArchivo.h"
#include "Barbero.h"
#include "InformesManager.h"

using namespace std;

void MenuInformes::InterfazMenuinformes() const {
    int opcion;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " E s t a s  e n:  M e n u   I n f o r m e s";

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

        rlutil::locate(32, 21);
        cout << "1- Informes Financieros";

        rlutil::locate(32, 22);
        cout << "2- Informes de Gestion";

        rlutil::locate(32, 25);
        cout << "0- Volver al Menu Principal";

        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 29);
        cout << "Eleccion: #  ";

        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            InformesFinancieros();
            break;

        case 2:
            InformesGestionClientes();
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

    } while (opcion != 0);
}

void MenuInformes::InformesFinancieros() const {
    int opcion;
    InformesManager manager;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " S u b m e n u:  I n f o r m e s   F i n a n c i e r o s";

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
        cout << "1- Recaudacion";

        rlutil::locate(32, 21);
        cout << "2- Servicio mas caro (+$5000)";

        rlutil::locate(32, 22);
        cout << "3- Barbero que mas cortes hizo";

        rlutil::locate(32, 23);
        cout << "4- Metodos de pago utilizados";

        rlutil::locate(32, 26);
        cout << "0- Volver al Menu Informes";

        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 29);
        cout << "Eleccion: #  ";

        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
        {
            int opcionRec;

            do {
                system("cls");
                LogoConstante();

                rlutil::setColor(rlutil::YELLOW);
                rlutil::locate(27, 18);
                cout << " S u b m e n u:  R e c a u d a c i o n";

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
                cout << "1- Recaudacion por dia";

                rlutil::locate(32, 21);
                cout << "2- Recaudacion por mes";

                rlutil::locate(32, 22);
                cout << "3- Recaudacion por anio";

                rlutil::locate(32, 25);
                cout << "0- Volver";

                rlutil::setColor(rlutil::RED);
                rlutil::locate(32, 29);
                cout << "Eleccion: #  ";

                rlutil::setColor(rlutil::WHITE);
                cin >> opcionRec;
                cin.ignore();

                switch(opcionRec) {
                case 1:
                    manager.recaudacionPorDia();
                    break;

                case 2:
                    manager.recaudacionPorMes();
                    break;

                case 3:
                    manager.recaudacionPorAnio();
                    break;

                case 0:
                    break;

                default:
                    system("cls");
                    rlutil::setColor(rlutil::RED);
                    cout << "Opcion invalida." << endl;
                    rlutil::setColor(rlutil::WHITE);
                    system("pause");
                    break;
                }

            } while (opcionRec != 0);

            break;
        }

        case 2:
        {
            system("cls");
            LogoConstante();

            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(29, 21);
            cout << "S e r v i c i o  M a s  C a r o";

            cout << endl << endl;

            Servicio serv;
            ArchivoServicios archserv;
            float maximo = 0;
            int idmaximo = 0;
            bool encontrado = false;

            for (int i = 0; i < archserv.cantidadRegistros(); i++) {
                serv = archserv.leer(i);

                if (serv.getPrecio() > 5000 && !encontrado) {
                    maximo = serv.getPrecio();
                    idmaximo = serv.getId();
                    encontrado = true;
                }
                else if (serv.getPrecio() > 5000 && serv.getPrecio() > maximo) {
                    maximo = serv.getPrecio();
                    idmaximo = serv.getId();
                }
            }

            rlutil::setColor(rlutil::WHITE);

            if (!encontrado) {
                cout << "No hay servicio con precio mayor a $5000" << endl;
            }
            else {
                cout << "ID de servicio mas caro: " << idmaximo << endl;
                cout << "Valor: $" << maximo << endl;
            }

            cout << endl;
            system("pause");
            break;
        }

        case 3:
            manager.informeBarbero();
            break;

        case 4:
            manager.informeMetodosPago();
            break;

        case 0:
            break;

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

void MenuInformes::InformesGestionClientes() const {
    int opcion;
    InformesManager manager;

    do {
        system("cls");
        LogoConstante();

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout << " S u b m e n u:  I n f o r m e s   D e   G e s t i o n";

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
        cout << "1- Clientes frecuentes";

        rlutil::locate(32, 21);
        cout << "2- Turnos realizados y cancelados";

        rlutil::locate(32, 22);
        cout << "3- Servicios mas solicitados";

        rlutil::locate(32, 23);
        cout << "4- Cantidad de turnos por barbero";

        rlutil::locate(32, 26);
        cout << "0- Volver al Menu Informes";

        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 29);
        cout << "Eleccion: #  ";

        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            manager.informeClientesFrecuentes();
            break;

        case 2:
            manager.informeEstadisticasTurnos();
            break;

        case 3:
            cout << endl << "Informe pendiente de implementar: Servicios mas solicitados." << endl;
            system("pause");
            break;

        case 4:
            cout << endl << "Informe pendiente de implementar: Cantidad de turnos por barbero." << endl;
            system("pause");
            break;

        case 0:
            break;

        default:
            system("cls");
            rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida. Ingresa un numero valido para acceder." << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl;
            system("pause");
            break;
        }

    } while (opcion != 0);
}
