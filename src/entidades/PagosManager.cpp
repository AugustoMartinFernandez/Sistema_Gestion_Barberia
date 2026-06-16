#include <iostream>
using namespace std;
#include "PagosManager.h"
#include "Pago.h"
#include "ArchivoPagos.h"
#include "ArchivoTurnos.h"
#include "ArchivoConfiguracion.h"
#include "ArchivoServicios.h"
#include "Servicio.h"
#include "TurnosManager.h"
#include "Cliente.h"
#include "ArchivoClientes.h"

void PagosManager::registrarPago(){

    ArchivoPagos archivoPagos;
    ArchivoTurnos archivoTurnos;
    ArchivoConfiguracion config;
    ArchivoServicios archivoServicios;
    ArchivoClientes archivoClientes;

    Pago pago;
    int idTurno;

    cout << "---- REGISTRAR PAGO ----" << endl;

    cout << "TURNOS DISPONIBLES" << endl;
    TurnosManager turnosManager;
    turnosManager.listarTurnosResumido();
    cout << "=============================\n" << endl;

    cout << endl;
    cout << "---- CARGA DEL TURNO ----" << endl;
    cout << "Ingrese ID del turno a cobrar: ";
    cin >> idTurno;

    int posTurno = archivoTurnos.buscar(idTurno);

    if(posTurno == -1){
        cout << "No existe un turno con ese ID." << endl;
        system("pause");
        return;
    }

    int posPago = archivoPagos.buscarPorTurno(idTurno);

    if(posPago != -1){
        cout << "Ese turno ya tiene un pago registrado." << endl;
        system("pause");
        return;
    }

    Turno turnoRealizado = archivoTurnos.leer(posTurno);

    // Cláusula de guarda que agregamos antes: Turno anulado
    if (turnoRealizado.getActivo() == false) {
        cout << "No se puede cobrar un turno anulado." << endl;
        system("pause");
        return;
    }

    int posServicio = archivoServicios.buscar(turnoRealizado.getIdServicio());

    if(posServicio == -1){
        cout << "El servicio asociado a este turno ya no existe en archivo." << endl;
        system("pause");
        return;
    }

    Servicio servicioBrindado = archivoServicios.leer(posServicio);

    // Obtenemos al cliente para evaluar sus puntos
    int posCliente = archivoClientes.buscar(turnoRealizado.getIdCliente());
    Cliente clienteRealizado = archivoClientes.leer(posCliente);

    float montoFinal = servicioBrindado.getPrecio();
    int puntosServicio = servicioBrindado.getPuntosQueOtorga();
    bool esCanje = false;

    // Logica de canje
    if (clienteRealizado.getPuntosAcumulados() >= 10) {
        int opcionCanje;
        cout << "\nEl cliente tiene " << clienteRealizado.getPuntosAcumulados() << " puntos acumulados." << endl;
        cout << "Desea canjear 10 puntos por este servicio GRATIS? (1-Si, 0-No): ";
        cin >> opcionCanje;

        if (opcionCanje == 1) {
            esCanje = true;
            montoFinal = 0; // El servicio sale gratis
        }
    }

    cout << "\nServicio realizado: " << servicioBrindado.getDescripcion() << endl;
    cout << "Monto a cobrar: $" << montoFinal << endl << endl;

    int nuevoId = config.getProximoIdPago();

    pago.setId(nuevoId);
    pago.setIdTurno(idTurno);
    pago.setMonto(montoFinal);

    cin.ignore();
    pago.cargar();

    if(archivoPagos.guardar(pago)){
        cout << endl;
        cout << "Pago guardado correctamente con ID: " << nuevoId << endl;

        // ACTUALIZACION DE PUNTOS EN EL ARCHIVO DEL CLIENTE
        if (esCanje) {
            clienteRealizado.restarPuntos(10);
            cout << "Se restaron 10 puntos por el canje." << endl;
        } else {
            clienteRealizado.sumarPuntos(puntosServicio);
            cout << "El cliente ha ganado " << puntosServicio << " puntos." << endl;
        }
        archivoClientes.guardar(clienteRealizado, posCliente);
    }
    else{
        cout << endl;
        cout << "Error al guardar el pago." << endl;
    }

    system("pause");
}

void PagosManager::listarPagos(){

    ArchivoPagos archivo;
    int total = archivo.cantidadRegistros();

    cout << "---- LISTADO DE PAGOS ----" << endl;

    if(total == 0){
        cout << "No hay pagos registrados." << endl;
        system("pause");
        return;
    }

    for(int i = 0; i < total; i++){

        Pago pago = archivo.leer(i);

        if(pago.getActivo()){
            pago.mostrar();
        }
    }

    system("pause");
}


void PagosManager::buscarPago(){

    ArchivoPagos archivo;
    int idPago;

    cout << "---- BUSCAR PAGO ----" << endl;
    cout << "Ingrese ID del pago: ";
    cin >> idPago;

    int pos = archivo.buscar(idPago);

    if(pos == -1){
        cout << "No existe un pago con ese ID." << endl;
        system("pause");
        return;
    }

    Pago pago = archivo.leer(pos);

    if(pago.getActivo()){
        pago.mostrar();
    }
    else{
        cout << "El pago existe, pero esta anulado." << endl;
    }

    system("pause");
}



void PagosManager::anularPago(){

    ArchivoPagos archivo;
    int idPago;

    cout << "---- ANULAR PAGO ----" << endl;
    cout << "Ingrese ID del pago: ";
    cin >> idPago;

    int pos = archivo.buscar(idPago);

    if(pos == -1){
        cout << "No existe un pago con ese ID." << endl;
        system("pause");
        return;
    }

    Pago pago = archivo.leer(pos);

    if (pago.getActivo() == false) {
        cout << "Este pago ya se encuentra anulado." << endl;
        system("pause");
        return;
    }

    pago.setActivo(false);

    if(archivo.guardar(pago, pos)){
        cout << "Pago anulado correctamente." << endl;

        // Retroceso de puntos por anulacion
        ArchivoTurnos archivoTurnos;
        ArchivoServicios archivoServicios;
        ArchivoClientes archivoClientes;

        Turno turnoAsociado = archivoTurnos.leer(archivoTurnos.buscar(pago.getIdTurno()));
        int posCliente = archivoClientes.buscar(turnoAsociado.getIdCliente());
        Cliente clienteAsociado = archivoClientes.leer(posCliente);

        if (pago.getMonto() == 0) {
            // Era un canje. Al anular, le devolvemos sus 10 puntos
            clienteAsociado.sumarPuntos(10);
            cout << "Se devolvieron 10 puntos al cliente." << endl;
        } else {
            // Era un pago normal. Al anular, le restamos los puntos que habia ganado
            Servicio servicioAsociado = archivoServicios.leer(archivoServicios.buscar(turnoAsociado.getIdServicio()));
            clienteAsociado.restarPuntos(servicioAsociado.getPuntosQueOtorga());
            cout << "Se restaron los puntos otorgados por este pago." << endl;
        }

        archivoClientes.guardar(clienteAsociado, posCliente);
    }
    else{
        cout << "Error al anular el pago." << endl;
    }

    system("pause");
}
