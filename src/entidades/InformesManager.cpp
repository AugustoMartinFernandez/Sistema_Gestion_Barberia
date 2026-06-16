#include <iostream>
#include <cstring>
using namespace std;
#include "InformesManager.h"
#include "ArchivoClientes.h"
#include "Cliente.h"
#include "ArchivoTurnos.h"
#include "Turno.h"
#include "ArchivoPagos.h"
#include "Pago.h"
#include "BarberoArchivo.h"
#include "Barbero.h"
#include "facha.h"
#include "Fecha.h"

void InformesManager::informeClientesFrecuentes() const {
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

    // El recuento de visitas (Con acceso directo optimizado)
    int totalTurnos = archTurnos.cantidadRegistros();

    for(int i=0; i < totalTurnos; i++){
        Turno turnoActual = archTurnos.leer(i);
        if(turnoActual.getActivo()){
            int posPago = archPagos.buscarPorTurno(turnoActual.getId());
            if(posPago != -1){

                // Buscamos la posicion directamente sin usar bucle anidado
                int posCli = archClientes.buscar(turnoActual.getIdCliente());
                if(posCli != -1){
                    vecConteo[posCli].cantidadVisitas++;
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

void InformesManager::informeEstadisticasTurnos() const {
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

    //Presentacion visual
    cout << "Total de turnos agendados historicamente: " << totalTurnos << endl << endl;

    rlutil::setColor(rlutil::GREEN);
    cout << "Realizados (Cobrados) : " << realizados << endl;

    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Pendientes: " << pendientes << endl;

    rlutil::setColor(rlutil::RED);
    cout << "Cancelados: " << cancelados << endl;

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");
}

void InformesManager::informeBarbero() const {
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- BARBERO (CON MAS CORTES) ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

    BarberoArchivo archBarberos;
    ArchivoTurnos archTurnos;
    ArchivoPagos archPagos;

    int totalBarberos = archBarberos.cantidadRegistros();
    if (totalBarberos == 0) {
        cout << "No hay barberos registrados." << endl;
        system("pause");
        return;
    }

    // Pedimos memoria dinamica un arreglo de enteros simples
    int* cortesPorBarbero = new int[totalBarberos];

    //Limpiamos la memoria
    for(int i=0; i < totalBarberos; i++){
        cortesPorBarbero[i] = 0;
    }

    //El motor de recuento cruzando Turnos y Pagos
    int totalTurnos = archTurnos.cantidadRegistros();
    for(int i=0; i < totalTurnos; i++){
        Turno turnoActual = archTurnos.leer(i);

        if(turnoActual.getActivo()){
            int posPago = archPagos.buscarPorTurno(turnoActual.getId());
            if(posPago != -1){ // Si esta pagado

                // Buscamos la posicion de ese barbero en su archivo
                int posBarbero = archBarberos.buscar(turnoActual.getIdBarbero());

                if (posBarbero != -1) {
                    // Sumamos 1 a esa posicion exacta en el vector
                    cortesPorBarbero[posBarbero]++;
                }
            }
        }
    }

    //Buscar quien tiene el numero mas grande
    int maxCortes = 0;
    int posMax = 0;

    for(int i=0; i < totalBarberos; i++){
        if(cortesPorBarbero[i] > maxCortes){
            maxCortes = cortesPorBarbero[i];
            posMax = i;
        }
    }

    //Mostrar al ganador
    if (maxCortes > 0) {
        Barbero ganador = archBarberos.leer(posMax);
        cout << "El barbero cracks es: " << ganador.getNombre() << " " << ganador.getApellido() << endl;
        cout << "Total de cortes realizados y cobrados: " << maxCortes << endl;
    } else {
        cout << "Todavia no se registraron cortes cobrados por ningun barbero." << endl;
    }

    //LA REGLA
    delete[] cortesPorBarbero;

    cout << endl;
    system("pause");
}

void InformesManager::informeMetodosPago() const {
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- METODOS DE PAGO UTILIZADOS ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

    ArchivoPagos archPagos;
    int totalPagos = archPagos.cantidadRegistros();

    if(totalPagos == 0){
        cout << "No hay pagos registrados." << endl;
        system("pause");
        return;
    }

    //Contadores simples
    int cantEfectivo = 0, cantTarjeta = 0, cantTransferencia = 0, cantOtro = 0, cantCanje = 0;

    //Motor de lectura y clasificacion
    for(int i = 0; i < totalPagos; i++){
        Pago pagoActual = archPagos.leer(i);

        if(pagoActual.getActivo()){

            if (strcmp(pagoActual.getMetodoPago(), "Efectivo") == 0) {
                cantEfectivo++;
            }
            else if (strcmp(pagoActual.getMetodoPago(), "Tarjeta") == 0) {
                cantTarjeta++;
            }
            else if (strcmp(pagoActual.getMetodoPago(), "Transferencia") == 0) {
                cantTransferencia++;
            }
            else if (strcmp(pagoActual.getMetodoPago(), "Otro") == 0) {
                cantOtro++;
            }
            else if (strcmp(pagoActual.getMetodoPago(), "Canje Puntos") == 0) {
                cantCanje++;
            }
        }
    }

    //Mostrar resultados
    cout << "Efectivo:                   " << cantEfectivo << " pagos." << endl;
    cout << "Tarjeta de Debito/Credito:  " << cantTarjeta << " pagos." << endl;
    cout << "Transferencia:              " << cantTransferencia << " pagos." << endl;
    cout << "Otro:                       " << cantOtro << " pagos." << endl;
    cout << "Canjes de Puntos Gratis:    " << cantCanje << " pagos." << endl;

    cout << endl;
    system("pause");
}

void InformesManager::recaudacionPorDia() const
{
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- RECAUDACION POR DIA ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

    ArchivoPagos archivo;
    Pago pago;

    int dia, mes, anio;
    float total = 0;
    int cantidadPagos = 0;

    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese anio: ";
    cin >> anio;

    for(int i = 0; i < archivo.cantidadRegistros(); i++)
    {
        pago = archivo.leer(i);

        if(pago.getActivo() == true)
        {
            Fecha fechaPago = pago.getFechaPago();

            if(fechaPago.getDia() == dia &&
               fechaPago.getMes() == mes &&
               fechaPago.getAnio() == anio)
            {
                total += pago.getMonto();
                cantidadPagos++;
            }
        }
    }

    cout << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << "Recaudacion del dia " << dia << "/" << mes << "/" << anio << ": $" << total << endl;
    cout << "Cantidad de pagos encontrados: " << cantidadPagos << endl;
    rlutil::setColor(rlutil::WHITE);

    system("pause");
}

void InformesManager::recaudacionPorMes() const
{
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- RECAUDACION POR MES ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

    ArchivoPagos archivo;
    Pago pago;

    int mes, anio;
    float total = 0;
    int cantidadPagos = 0;

    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese anio: ";
    cin >> anio;

    for(int i = 0; i < archivo.cantidadRegistros(); i++)
    {
        pago = archivo.leer(i);

        if(pago.getActivo() == true)
        {
            Fecha fechaPago = pago.getFechaPago();

            if(fechaPago.getMes() == mes &&
               fechaPago.getAnio() == anio)
            {
                total += pago.getMonto();
                cantidadPagos++;
            }
        }
    }

    cout << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << "Recaudacion del mes " << mes << "/" << anio << ": $" << total << endl;
    cout << "Cantidad de pagos encontrados: " << cantidadPagos << endl;
    rlutil::setColor(rlutil::WHITE);

    system("pause");
}

void InformesManager::recaudacionPorAnio() const
{
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- RECAUDACION POR ANIO ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

    ArchivoPagos archivo;
    Pago pago;

    int anio;
    float total = 0;
    int cantidadPagos = 0;

    cout << "Ingrese anio: ";
    cin >> anio;

    for(int i = 0; i < archivo.cantidadRegistros(); i++)
    {
        pago = archivo.leer(i);

        if(pago.getActivo() == true)
        {
            Fecha fechaPago = pago.getFechaPago();

            if(fechaPago.getAnio() == anio)
            {
                total += pago.getMonto();
                cantidadPagos++;
            }
        }
    }

    cout << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << "Recaudacion del anio " << anio << ": $" << total << endl;
    cout << "Cantidad de pagos encontrados: " << cantidadPagos << endl;
    rlutil::setColor(rlutil::WHITE);

    system("pause");
}
