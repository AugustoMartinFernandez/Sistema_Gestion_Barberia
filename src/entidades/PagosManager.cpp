#include <iostream>
using namespace std;
#include "PagosManager.h"
#include "Pago.h"
#include "ArchivoPagos.h"
#include "ArchivoTurnos.h"
#include "ArchivoConfiguracion.h"




void PagosManager::registrarPago(){

    ArchivoPagos archivoPagos;
    ArchivoTurnos archivoTurnos;
    ArchivoConfiguracion config;

    Pago pago;
    int idTurno;

    cout << "---- REGISTRAR PAGO ----" << endl;

    cout << "Ingrese ID del turno: ";
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

    int nuevoId = config.getProximoIdPago();

    pago.setId(nuevoId);
    pago.setIdTurno(idTurno);


    //hasta conectar con Servicio
    float monto;
    cout << "Ingrese monto a pagar: $";
    cin >> monto;
    pago.setMonto(monto);

    pago.cargar();

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
