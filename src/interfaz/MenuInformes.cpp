#include <iostream>
using namespace std;
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

struct conteoClientes {
    int idCliente;
    int cantidadVisitas;
};

void MenuInformes::InterfazMenuinformes ()const
{
    int opcion;

    do
    {
        system("cls");
        LogoConstante ();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(27, 18);
        cout<< " E s t a s  e n:  M e n u   I n f o r m e s";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19);
        cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27);
        cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 21);
        cout<<"1-  Informes Financieros (Recaudacion, etc.) "<<endl;
        rlutil::locate(32, 25);
        cout<<"2-  Informes de gestion de clientes y agenda "<<endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29);
        cout<<"Opcion 0 (cero) Para Salir Del Programa..."<<endl;
        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 30);
        cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            InformesFinancieros ();
            break;
        }
        case 2:
        {
            InformesGestionClientes ();
            break;
        }
        case 0:
        {
            MenuManager volver;
            volver.MenuPrincipal ();
            break;
        }

        default:
            system ("cls");
            cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
            cout<<" 0 (cero) para volver al menu principal."<<endl;
            cout<<endl<<endl;
            system ("pause");
            system ("cls");
        }

    }
    while ( opcion != 0);

}



void  MenuInformes::InformesFinancieros ()const
{
    int opcion;

    do
    {
        system("cls"); // limpia pantalla ;
        LogoConstante ();   //logo por defecto , aparece en todos los menus (barberia pacheco)
        rlutil::locate(27, 18);
        cout<< " E s t a s  e n:  S u b M e n u - I n f . F i n a n c i e r o s ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19);
        cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27);
        cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";


        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 20);
        cout<<"1-  Recaudacion (Diaria, Mensual, Anual.) "<<endl;
        rlutil::locate(32, 22);
        cout<<"2-  Servicio mas caro que supere $5000 "<<endl;
        rlutil::locate(32, 24);
        cout<<"3-  Barbero que mas cortes hizo"<<endl;
        rlutil::locate(32, 26);
        cout<<"4-  Metodos de pago utilizados "<<endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29);
        cout<<"Opcion 0 (cero) Para Salir Del Programa..."<<endl;
        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 30);
        cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {

        } break;

        case 2:
        {
            Servicio serv;
            ArchivoServicios archserv;
            float maximo;
            int idmaximo;
            bool bandera = true;
            for (int i = 0; i < archserv.cantidadRegistros(); i++)
            {
                serv = archserv.leer(i);
                if  (bandera == 1 && serv.getPrecio() > 5000)
                {
                    maximo = serv.getPrecio();
                    idmaximo = serv.getId();
                    bandera = 0;
                }

                else if ( bandera == 0 && serv.getPrecio() > maximo)
                {
                    maximo = serv.getPrecio();
                    idmaximo = serv.getId();
                }
            }
            if (bandera == 1)
            {
                cout << "No hay servicio con precio mayor a $5000" << endl;
            }
            else
            {
                cout << "ID de servicio mas caro: " << idmaximo << endl;
                cout << "Valor: $" << maximo << endl;
            }
            cout << endl;
            system ("pause");
        }
        break;

        case 3:
        {
        } break;

        case 4:
        {     } break;
        case 0:
        {
            InterfazMenuinformes ();
            break;
        }

        default:
            system ("cls");
            cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
            cout<<" 0 (cero) para volver al Menu Informes..."<<endl;
            cout<<endl<<endl;
            system ("pause");
            system ("cls");
        }
    }
    while(opcion != 0);

}


void MenuInformes::InformesGestionClientes ()const
{
    int opcion;



    do
    {
        system("cls"); // limpia pantalla ;
        LogoConstante ();  //logo del programa
        rlutil::locate(27, 18);
        cout<< " E s t a s  e n:  S u b M e n u - I n f . G e s t i o n C l i e n t";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 19);
        cout<< "ษออออออออออออออออออออออออออออออออออออออออออออออออออออป";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 20);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 21);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 22);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 23);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 24);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::BLUE);
        rlutil::locate(27, 25);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(27, 26);
        cout<< "บ                                                    บ";
        rlutil::setColor(rlutil::RED);
        rlutil::locate(27, 27);
        cout<<  "ศออออออออออออออออออออออออออออออออออออออออออออออออออออผ";


        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(32, 20);
        cout<<"1-  Clientes Frecuentes"<<endl;
        rlutil::locate(32, 24);
        cout<< "2- Turnos realizados y cancelados"<<endl;



        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(32, 29);
        cout<<"Opcion 0 (cero) Para Salir Del Programa..."<<endl;
        rlutil::setColor(rlutil::RED);
        rlutil::locate(32, 30);
        cout<< "Eleccion: #  ";
        rlutil::setColor(rlutil::BLUE);
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:{
            informeClientesFrecuentes();
            break;
        }
        case 2:{
            informeEstadisticasTurnos();
            break;
        }
        case 0:{
            InterfazMenuinformes();
            break;
        }

        default:
            system ("cls");
            cout<< "Opcion invalida. Ingresa un numero valido para acceder."<<endl;
            cout<<" 0 (cero) para volver al Menu Informes..."<<endl;
            cout<<endl<<endl;
            system ("pause");
            system ("cls");

        }
    }
    while ( opcion != 0);

}

void MenuInformes::informeClientesFrecuentes() const {
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- TOP 5 CLIENTES FRECUENTES ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

    // Instanciamos los Archivos
    ArchivoClientes archClientes;
    ArchivoTurnos archTurnos;
    ArchivoPagos archPagos;

    // Saber el tamanio
    int totalClientes = archClientes.cantidadRegistros();
    if(totalClientes == 0){
        cout << "No hay clientes registrados en el sistema."<<endl;
        system("pause");
        return;
    }

    // Pedimos memoria dinamica
    conteoClientes *vecConteo = new conteoClientes[totalClientes];

    for(int i=0; i < totalClientes; i++){
        Cliente cli = archClientes.leer(i);
        vecConteo[i].idCliente = cli.getId();
        vecConteo[i].cantidadVisitas = 0;
    }

    // El recuento de visitas
    int totalTurnos = archTurnos.cantidadRegistros();

    for(int i=0; i < totalTurnos; i++){
        Turno turnoActual = archTurnos.leer(i);
        if(turnoActual.getActivo()){
            int posPago = archPagos.buscarPorTurno(turnoActual.getId());
            if(posPago != -1){
                // Bucle
                for(int j=0; j < totalClientes; j++){
                    if(vecConteo[j].idCliente == turnoActual.getIdCliente()){
                        vecConteo[j].cantidadVisitas++;
                        break;
                    }
                }
            }
        }
    }

    // Ordenamiento por Seleccion (De Mayor a Menor)
    for (int i = 0; i < totalClientes - 1; i++) {
        int posMax = i;
        for (int j = i + 1; j < totalClientes; j++) {
            if (vecConteo[j].cantidadVisitas > vecConteo[posMax].cantidadVisitas) {
                posMax = j;
            }
        }
        // Intercambio de structs completos
        conteoClientes aux = vecConteo[i];
        vecConteo[i] = vecConteo[posMax];
        vecConteo[posMax] = aux;
    }

    // Mostrar el Top 5
    int limite = (totalClientes < 5) ? totalClientes : 5;
    bool hayVisitas = false;

    for (int i = 0; i < limite; i++) {
        if (vecConteo[i].cantidadVisitas > 0) {
            hayVisitas = true;
            // Buscar los datos reales usando el ID guardado
            int posCli = archClientes.buscar(vecConteo[i].idCliente);
            if (posCli != -1) {
                Cliente cliReal = archClientes.leer(posCli);
                cout << i + 1 << ". " << cliReal.getNombre() << " " << cliReal.getApellido()
                     << " -> " << vecConteo[i].cantidadVisitas << " visitas concretadas." << endl;
            }
        }
    }

    if (!hayVisitas) {
        cout << "No hay clientes con visitas registradas y pagadas todavia." << endl;
    }

    //Liberar memoria
    delete[] vecConteo;

    cout << endl;
    system("pause");
}

void MenuInformes::informeEstadisticasTurnos() const {
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- ESTADISTICAS DE TURNOS ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

    // Instanciar los archivos necesarios
    ArchivoTurnos archTurnos;
    ArchivoPagos archPagos;

    int totalTurnos = archTurnos.cantidadRegistros();

    // Filtro por si la barberia es nueva y no hay turnos
    if (totalTurnos == 0) {
        cout << "No hay turnos registrados en el sistema todavia." << endl;
        system("pause");
        return;
    }

    // Crear los contadores
    int realizados = 0;
    int cancelados = 0;
    int pendientes = 0;

    // El motor de lectura y clasificacion
    for (int i = 0; i < totalTurnos; i++) {
        Turno turnoActual = archTurnos.leer(i);

        // Regla 1 Esta dado de baja
        if (turnoActual.getActivo() == false) {
            cancelados++;
        }
        // Regla 2 y 3 Esta activo, hay que ver si se pago
        else {
            int posPago = archPagos.buscarPorTurno(turnoActual.getId());

            if (posPago != -1) {
                realizados++; // Existe el pago
            } else {
                pendientes++; // No existe el pago
            }
        }
    }

    // 4. Calcular los porcentajes (multiplicamos por 100.0f para no perder los decimales)
    float pctRealizados = (realizados * 100.0f) / totalTurnos;
    float pctCancelados = (cancelados * 100.0f) / totalTurnos;
    float pctPendientes = (pendientes * 100.0f) / totalTurnos;

    // 5. Presentacion visual
    cout << "Total de turnos agendados historicamente: " << totalTurnos << endl << endl;

    rlutil::setColor(rlutil::GREEN);
    cout << "-> Realizados (Cobrados) : " << realizados << " (" << pctRealizados << "%)" << endl;

    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "-> Pendientes (Por venir): " << pendientes << " (" << pctPendientes << "%)" << endl;

    rlutil::setColor(rlutil::RED);
    cout << "-> Cancelados (Baja)     : " << cancelados << " (" << pctCancelados << "%)" << endl;

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");
}


