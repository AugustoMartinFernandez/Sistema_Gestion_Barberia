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
#include "ArchivoServicios.h"


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


void InformesManager::InformeServMasSolicitados ()const{
  system("cls");
  // LogoConstante ();
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- SERVICIOS MAS SOLICITADOS ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

 ArchivoServicios archServicios;
    ArchivoTurnos archTurnos;
    ArchivoPagos archPagos;

int totalServicios = archServicios.cantidadRegistros();

    if (totalServicios == 0) {
    cout << "No hay servicios registrados en el sistema." << endl;
     system ("pause");
     return;

     }
     //aarreglo dinamico con un stuct x cada serv
 conteoServicios *vectServicios = new conteoServicios [totalServicios];

    //inicializar: asignar id y cantidad 0
    for (int i=0; i< totalServicios; i++){
        Servicio ser = archServicios.leer (i);
        vectServicios[i].idServicio = ser.getId ();
        vectServicios [i].cantidad = 0;
    }
// recorremos con el for , turnos act, q esten pagados

int totalTurnos = archTurnos.cantidadRegistros ();
      for ( int i=0; i<totalTurnos; i++){
        Turno turnoActual = archTurnos.leer (i);
        //  if que verifica si el turno actual esta ON
        if  (turnoActual.getActivo ()){
            int posPago = archPagos.buscarPorTurno (turnoActual.getId());

           if ( posPago != -1) {
            // servicio realizado.
            int idServ = turnoActual.getIdServicio();
            int posServ = archServicios.buscar (idServ);

            if (posServ != -1 ){
                vectServicios [posServ].cantidad++;
               }
        }
        }
      }

    //ordenar de mayor a menor cant

for (int i=0; i<totalServicios -1; i++) {
        int posMax = i;
      for (int j =i+1; j<totalServicios; j++){

    if (vectServicios [j].cantidad >vectServicios[posMax].cantidad)
        posMax = j;
      }
    conteoServicios aux = vectServicios [i];
    vectServicios [i] = vectServicios [posMax];
    vectServicios [posMax] = aux;
    }
// mostrar rankiing ( todos o  > 0 )

bool haydatos = false;
cout<< "Ranking de Servicios (por cantidad de turnos realizados):"<<endl<<endl;
 for (int i=0; i <totalServicios; i++) {

    if (vectServicios[i].cantidad >0) {
        haydatos = true;
        Servicio vicio = archServicios.leer(archServicios.buscar(vectServicios[i].idServicio));
     cout << i + 1 << " . "<< vicio.getDescripcion ()
     << " - "<< vectServicios [i].cantidad << " Turnos."<<endl;
    }
 }
if (haydatos == false) {
    cout << "Por el momento no hay servicios con turnos Realizados."<<endl;

}

 delete[] vectServicios;
 system ("pause");
 }
void InformesManager::InformeVentPorServicio ()const{
      system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "--- VENTAS POR SERVICIO ---" << endl << endl;
    rlutil::setColor(rlutil::WHITE);

 ArchivoServicios archServ;
    ArchivoTurnos archTurn;
    ArchivoPagos archPag;

 int totalServicios = archServ.cantidadRegistros();
 if (totalServicios == 0 ) {
    cout << "No hay servicios registrados."<<endl;
    system ("pause");
    return;
 }
 // array dinamico = acumula montos
ventasServicio *vectVentas = new ventasServicio[totalServicios];

//inicializar
for ( int i =0; i< totalServicios; i++) {
    Servicio ser = archServ.leer (i);
    vectVentas [i].idServicio = ser.getId();
    vectVentas [i].totalfact =0.0f;
}
 // recoremos todos los pagos activos.
int totalpagos = archPag.cantidadRegistros ();

 for  (int i=0; i<totalpagos; i++) {
    Pago PagAct = archPag.leer (i);
    if (PagAct.getActivo()){
           // obtener el turno relacionado a este pago
         int posTurno = archTurn.buscar (PagAct.getIdTurno());

         // El int no es -1, significa que es 0 o mayor.
         if (posTurno != -1) {
            Turno turn  = archTurn.leer (posTurno);
            int idServ= turn.getIdServicio ();
            int posServ= archServ.buscar (idServ);

            if (posServ != -1) {
                vectVentas [posServ].totalfact +=PagAct.getMonto ();
            }
         }
    }
 }

 // ordenamiento de mayor a menor fact.

for (int i=0; i < totalServicios -1; i++) {
    int posMax = i;

       for (int j = i +1; j< totalServicios; j++){

            if (vectVentas[j].totalfact > vectVentas[posMax].totalfact)
                   posMax = j;
            }
            ventasServicio aux = vectVentas [i];
            vectVentas [i] = vectVentas [posMax];
            vectVentas [posMax] = aux;
       }
   // resultados
bool haydatos = false;
cout<< "Ingresos generados por cada Servicio: "<<endl<<endl;

for (int i=0; i<totalServicios; i++) {

    if (vectVentas [i].totalfact > 0.0f) {
        haydatos = true;
        Servicio ser = archServ.leer (archServ.buscar(vectVentas[i].idServicio));
        cout << i + 1 << " . "<<ser.getDescripcion () <<" - $"<< vectVentas [i].totalfact<<endl;

    }
}
 if ( haydatos == false) {
    cout << "No hay pagos registrados para calcular ventas por servicio."<<endl;

 }

 delete [] vectVentas;
 system ("pause") ;

}







