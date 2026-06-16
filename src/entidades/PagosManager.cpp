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

void PagosManager::registrarPago(){

    ArchivoPagos archivoPagos;
    ArchivoTurnos archivoTurnos;
    ArchivoConfiguracion config;
    ArchivoServicios archivoServicios;

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

    // Cobro
    Turno turnoRealizado = archivoTurnos.leer(posTurno);
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
    float montoAutocalculado = servicioBrindado.getPrecio();

    cout << "\nServicio realizado: " << servicioBrindado.getDescripcion() << endl;
    cout << "Monto a cobrar (Precio Oficial): $" << montoAutocalculado << endl << endl;

    int nuevoId = config.getProximoIdPago();

    pago.setId(nuevoId);
    pago.setIdTurno(idTurno);

    // el precio automaticamente
    pago.setMonto(montoAutocalculado);
    cin.ignore();
    pago.cargar(); // Aca la clase Pago solo pide el metodo de pago, fecha y hora.

    if(archivoPagos.guardar(pago)){
        cout << endl;
        cout << "Pago guardado correctamente con ID: " << nuevoId << endl;
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

    pago.setActivo(false);

    if(archivo.guardar(pago, pos)){
        cout << "Pago anulado correctamente." << endl;
    }
    else{
        cout << "Error al anular el pago." << endl;
    }

    system("pause");
}
