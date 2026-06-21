#include <iostream>
using namespace std;

#include "TurnosManager.h"
#include "Turno.h"
#include "ArchivoTurnos.h"
#include "ArchivoConfiguracion.h"
#include "ArchivoClientes.h"
#include "Cliente.h"
#include "BarberoArchivo.h"
#include "ArchivoServicios.h"
#include "ServiciosManager.h"
#include "ClientesManager.h"
#include "BarberosManager.h"
#include <cstring>

bool TurnosManager::entidadesValidasYActivas(int idCliente, int idBarbero, int idServicio){
    ArchivoClientes arcCli;
    BarberoArchivo arcBar("barberos.dat");
    ArchivoServicios arcSer;

    // Cliente
    int posCli = arcCli.buscar(idCliente);
    if(posCli == -1){
        cout << "El cliente no existe" << endl;
        return false;
    }
    if(arcCli.leer(posCli).getActivo() == false){
        cout << "El cliente existe pero esta dado de baja." <<endl;
        return false;
    }

    // Barbero
    int posbar = arcBar.buscar(idBarbero);
    if(posbar == -1){
        cout << "El Barbero no existe" <<endl;
        return false;
    }

    if(arcBar.leer(posbar).getActivo() == false){
        cout << "El Barbero existe pero esta dado de baja." <<endl;
        return false;
    }

    // Servicio
    int posSer = arcSer.buscar(idServicio);
    if(posSer == -1){
        cout << "El Servicio no existe." <<endl;
        return false;
    }
    if(arcSer.leer(posSer).getActivo() == false){
        cout << "El Servicio existe pero esta dado de baja." <<endl;
        return false;
    }
    return true; // Si los tres existen y estan activos
}

void TurnosManager::crearTurno(){

    Turno turno;
    ArchivoTurnos archivo;
    ArchivoConfiguracion config;
    int opcion;

    cout << "---- CREAR TURNO ----" << endl;
    cout << "1 - Continuar" << endl;
    cout << "0 - Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    if(opcion == 0){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    int nuevoId = config.getProximoIdTurno();

    system("cls");
    cout << "---- CREAR TURNO ----" << endl;

    cout << "CLIENTES DISPONIBLES" << endl;
    ClientesManager clientesManager;
    clientesManager.listarClientesResumido();
    cout << "=============================\n" << endl;

    cout << "BARBEROS DISPONIBLES" << endl;
    BarberosManager barberosManager;
    barberosManager.listarBarberosResumido();

    cout << "=============================\n" << endl;
    cout << "SERVICIOS DISPONIBLES" << endl;
    ServiciosManager serviciosManager;
    serviciosManager.listarServiciosResumido();

    cout << endl;
    cout << "---- CARGA DEL TURNO ----" << endl;

    turno.cargar();
    turno.setId(nuevoId);

    ArchivoClientes arcCli;
    BarberoArchivo arcBar("barberos.dat");
    ArchivoServicios arcSer;

    if(!entidadesValidasYActivas(turno.getIdCliente(), turno.getIdBarbero(), turno.getIdServicio())){
        system("pause");
        return;
    }

    cout << endl;
    cout << "Desea guardar el turno?" << endl;
    cout << "1 - Si" << endl;
    cout << "0 - Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    if(opcion == 0){
        cout << "Operacion cancelada. No se guardo el turno." << endl;
        system("pause");
        return;
    }

    if(archivo.guardar(turno)){
        cout << endl;
        cout << "Turno guardado correctamente." << endl;
    }
    else{
        cout << endl;
        cout << "Error al guardar el turno." << endl;
    }

    system("pause");
}


void TurnosManager::listarTurnos(){

    ArchivoTurnos archivo;
    int total = archivo.cantidadRegistros();


    cout << "---- LISTADO DE TURNOS ----" << endl;

    if(total == 0){
        cout << "No hay turnos registrados." << endl;
        system("pause");
        return;
    }
    for(int i = 0; i < total; i++){

        Turno turno = archivo.leer(i);

        if(turno.getActivo()){
            turno.mostrar();
        }
    }
    system("pause");
}

int TurnosManager::buscarClientePorNombreApellido(){

    ArchivoClientes archivoClientes;

    char nombre[30];
    char apellido[30];

    cout << "Nombre del cliente: ";
    cin.getline(nombre, 30);

    cout << "Apellido del cliente: ";
    cin.getline(apellido, 30);

    int totalClientes;

    totalClientes = archivoClientes.cantidadRegistros();

    for(int i = 0; i < totalClientes; i++){

        Cliente aux;

        aux = archivoClientes.leer(i);

        if(aux.getActivo()){

            int comparaNombre;
            int comparaApellido;

            comparaNombre = stricmp(aux.getNombre(), nombre);
            comparaApellido = stricmp(aux.getApellido(), apellido);

            if(comparaNombre == 0 && comparaApellido == 0){

                return aux.getId();
            }
        }
    }

    return -1;
}

void TurnosManager::editarTurno(){

    ArchivoTurnos archivo;
    int idTurno;

    cout << "---- EDITAR TURNO ----" << endl;
    cout << "Ingrese ID del turno: ";
    cin >> idTurno;

    int pos = archivo.buscar(idTurno);

    if(pos == -1){
        cout << "No existe un turno con ese ID." << endl;
        system("pause");
        return;
    }

    Turno turno = archivo.leer(pos);

    cout << endl;
    cout << "Turno actual:" << endl;
    turno.mostrar();

    cout << endl;
    cout << "Ingrese los nuevos datos del turno:" << endl;

    int idOriginal = turno.getId();

    turno.cargar();
    turno.setId(idOriginal);
    turno.setActivo(true);

    if(!entidadesValidasYActivas(turno.getIdCliente(), turno.getIdBarbero(), turno.getIdServicio())){
        system("pause");
    return;
    }

    if(archivo.guardar(turno, pos)){
        cout << "Turno modificado correctamente." << endl;
    }
    else{
        cout << "Error al modificar el turno." << endl;
    }

    system("pause");
}

void TurnosManager::borrarTurno(){

    ArchivoTurnos archivo;
    int idTurno;

    cout << "---- BORRAR TURNO ----" << endl;
    cout << "Ingrese ID del turno: ";
    cin >> idTurno;

    int pos = archivo.buscar(idTurno);

    if(pos == -1){
        cout << "No existe un turno con ese ID." << endl;
        system("pause");
        return;
    }

    Turno turno = archivo.leer(pos);

    turno.setActivo(false);

    if(archivo.guardar(turno, pos)){
        cout << "Turno eliminado correctamente." << endl;
    }
    else{
        cout << "Error al eliminar el turno." << endl;
    }

    system("pause");
}


void TurnosManager::listarTurnosResumido() {

    ArchivoTurnos archivoTurnos;
    ArchivoClientes archivoClientes;
    ArchivoServicios archivoServicios;

    int total = archivoTurnos.cantidadRegistros();

    for(int i = 0; i < total; i++){

        Turno turno = archivoTurnos.leer(i);

        if(!turno.getActivo()) continue;

        int posCli = archivoClientes.buscar(turno.getIdCliente());
        int posSer = archivoServicios.buscar(turno.getIdServicio());

        Cliente cliente = archivoClientes.leer(posCli);
        Servicio servicio = archivoServicios.leer(posSer);

        cout << "ID Turno: " << turno.getId()
             << " | Cliente: "
             << cliente.getNombre() << " "
             << cliente.getApellido()
             << " | Servicio: "
             << servicio.getDescripcion()
             << endl;
    }
}



void TurnosManager::listarTurnosPorEstado() {

    ArchivoTurnos archivo;

    int opcion;

    cout << "1 - Turnos Activos" << endl;
    cout << "0 - Turnos Cancelados" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    int total = archivo.cantidadRegistros();

    cout << endl;
    cout << "---- RESULTADOS ----" << endl;

    for(int i = 0; i < total; i++){

        Turno turno = archivo.leer(i);

        if(turno.getActivo() == opcion){
            turno.mostrar();
        }
    }

    system("pause");
}
