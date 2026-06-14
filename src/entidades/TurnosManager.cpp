#include <iostream>
using namespace std;

#include "TurnosManager.h"
#include "Turno.h"
#include "ArchivoTurnos.h"
#include "ArchivoConfiguracion.h"
#include "ArchivoClientes.h"
#include "Cliente.h"
#include <cstring>

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

    if(opcion == 0){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    int nuevoId = config.getProximoIdTurno();
    turno.setId(nuevoId);

    cout << endl;
    cout << "---- CREAR TURNO ----" << endl;

    turno.cargar();

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




// para llamar cuando queramos editar un turno o eliminar un turno

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

            comparaNombre = strcmp(aux.getNombre(), nombre);
            comparaApellido = strcmp(aux.getApellido(), apellido);

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
