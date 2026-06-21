#include <iostream>
#include "ArchivoClientes.h"
#include "ClientesManager.h"
#include "Cliente.h"
#include "ArchivoConfiguracion.h"

using namespace std;

void ClientesManager::crearNuevoCliente() const
{
    Cliente cli;
    cli.cargar();

    ArchivoConfiguracion config;
    int nuevoId = config.getProximoIdCliente();
    cli.setId(nuevoId);

    ArchivoClientes reg;

    if(reg.guardar(cli))
    {
        cout << "\n[EXITO] Cliente guardado correctamente con el ID: " << nuevoId << endl;
    }
    else
    {
        cout << "\n[ERROR] No se pudo guardar el cliente en el disco." << endl;
    }
    system("pause");
}

void ClientesManager::editarCliente() const
{
    int buscarId,pos,cantidad;
    ArchivoClientes reg;
    Cliente cli;

    bool hayClientesActivos = false;
    cantidad = reg.cantidadRegistros();

    if(cantidad == 0)
    {
        cout <<endl<<endl<<"No hay clientes en el archivo a modificar." <<endl;
        cout << "Por favor, dirijase a la opcion 1 del menu para dar de alta un nuevo cliente." << endl;
    }
    else
    {
        for(int i=0; i<cantidad; i++)
        {
            Cliente escaneo = reg.leer(i);
            if(escaneo.getActivo() == true)
            {
                hayClientesActivos = true;
                break;
            }
        }
        if(hayClientesActivos == false)
        {
            cout << "\nNo hay clientes activos en el sistema para modificar." << endl;
        }
        else
        {
            cout << "Ingrese ID del Cliente a modificar: "<<endl;
            cin >> buscarId;

            while(buscarId <= 0)
            {
                cout<<"ID Invalido. Intente nuevamente: ";
                cin >> buscarId;
            }

            pos = reg.buscar(buscarId);
            if(pos >= 0)
            {
                cli = reg.leer(pos);
                if(cli.getActivo()==true)
                {
                    cout<<endl<<endl<< "Ficha Actual del Cliente" << endl<<endl;
                    cli.mostrar();
                    cout<< "Ingrese los nuevos datos:" << endl;
                    cin.ignore();
                    cli.cargar();
                    if(reg.guardar(cli,pos))
                    {
                        cout << "\nCliente modificado correctamente." << endl;
                    }
                    else
                    {
                        cout << "\nNo se pudo guardar la modificacion en el archivo." << endl;
                    }
                }
                else
                {
                    cout << "\nNo se puede modificar un cliente dado de baja" <<endl;
                }
            }
            else
            {
                cout <<endl<<endl<< "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }
    system("pause");
}

void ClientesManager::gestionarEstadoCliente() const
{
    int subOpcion;

    cout << "---- GESTIONAR ESTADO DE CLIENTES ----" << endl;
    cout << "1 - Dar de baja a un cliente" << endl;
    cout << "2 - Reactivar a un cliente" << endl;
    cout << "0 - Cancelar y salir" << endl;
    cout << "Eleccion: ";
    cin >> subOpcion;

    if (subOpcion == 0) {
        return;
    }

    while(subOpcion != 1 && subOpcion != 2) {
        cout << "Opcion invalida. Ingrese 1 para Baja o 2 para Reactivar: ";
        cin >> subOpcion;
    }

    int buscarId, pos, confirmacion, cantidad;
    ArchivoClientes reg;
    Cliente cli;
    bool hayClientesObjetivo = false;

    cantidad = reg.cantidadRegistros();
    if(cantidad == 0) {
        cout << "\nEl archivo esta vacio. No hay clientes para operar." << endl;
        cout << "Por favor, dirijase a la opcion de alta para crear un nuevo cliente." << endl;
        system("pause");
        return;
    }

    // SUBOPCION 1: LOGICA DE BAJA LOGICA
    if(subOpcion == 1) {
        for(int i = 0; i < cantidad; i++) {
            Cliente escaneo = reg.leer(i);
            if(escaneo.getActivo() == true) {
                hayClientesObjetivo = true;
                break;
            }
        }

        if(hayClientesObjetivo == false) {
            cout << "\nNo hay clientes activos en el sistema para dar de baja." << endl;
        } else {
            cout << "\n--- DAR DE BAJA CLIENTE ---" << endl;
            cout << "Ingrese ID del Cliente a dar de baja: ";
            cin >> buscarId;

            while(buscarId <= 0) {
                cout << "ID Invalido. Intente nuevamente: ";
                cin >> buscarId;
            }

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                cli = reg.leer(pos);
                if(cli.getActivo() == true) {
                    cout << "\nFicha actual del cliente:" << endl;
                    cli.mostrar();

                    do {
                        cout << "\nEsta seguro que desea dar de baja a este cliente? (1=Si, 0=No): ";
                        cin >> confirmacion;
                        if(confirmacion != 1 && confirmacion != 0) {
                            cout << "Error. Ingrese 1=Si y 0=No." << endl;
                        }
                    } while(confirmacion != 1 && confirmacion != 0);

                    if(confirmacion == 1) {
                        cli.setActivo(false);
                        if(reg.guardar(cli, pos)) {
                            cout << "\nCliente dado de Baja Exitosamente." << endl;
                        } else {
                            cout << "\nError al guardar la baja en el archivo." << endl;
                        }
                    } else {
                        cout << "\nOperacion cancelada. No se dio de Baja al cliente." << endl;
                    }
                } else {
                    cout << "\nError: Ese ID especifico ya pertenece a un cliente dado de baja." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }
    // SUBOPCION 2: LOGICA DE REACTIVACION
    else if(subOpcion == 2) {
        for(int i = 0; i < cantidad; i++) {
            Cliente escaneo = reg.leer(i);
            if(escaneo.getActivo() == false) {
                hayClientesObjetivo = true;
                break;
            }
        }

        if(hayClientesObjetivo == false) {
            cout << "\nNo hay clientes dados de baja en el sistema para reactivar." << endl;
        } else {
            cout << "\n--- REACTIVAR CLIENTE ---" << endl;
            cout << "Ingrese ID del Cliente a Reactivar: ";
            cin >> buscarId;

            while(buscarId <= 0) {
                cout << "ID Invalido. Intente nuevamente: ";
                cin >> buscarId;
            }

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                cli = reg.leer(pos);
                if(cli.getActivo() == false) {
                    cli.setActivo(true);
                    cout << "\nFicha del cliente a reactivar:" << endl;
                    cli.mostrar();

                    do {
                        cout << "\nEsta seguro que desea reactivar a este cliente? (1=Si, 0=No): ";
                        cin >> confirmacion;
                        if(confirmacion != 1 && confirmacion != 0) {
                            cout << "Error. Ingrese 1=Si y 0=No." << endl;
                        }
                    } while(confirmacion != 1 && confirmacion != 0);

                    if(confirmacion == 1) {
                        if(reg.guardar(cli, pos)) {
                            cout << "\nCliente Reactivado Exitosamente." << endl;
                        } else {
                            cout << "\nError al guardar la reactivacion en el archivo." << endl;
                        }
                    } else {
                        cli.setActivo(false);
                        cout << "\nOperacion cancelada. El cliente sigue dado de baja." << endl;
                    }
                } else {
                    cout << "\nError: Ese ID especifico pertenece a un cliente que ya esta activo." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }

    cout << endl;
    system("pause");
}

void ClientesManager::listarClientes() const // <-- AGREGADO EL CONST ACA
{
    ArchivoClientes reg;
    int total = reg.cantidadRegistros();
    bool hayClientesActivos = false;

    cout << "---- LISTADO DE CLIENTES ----" << endl;

    if(total > 0)
    {
        for(int i = 0; i < total; i++)
        {
            Cliente leidos = reg.leer(i);
            if(leidos.getActivo() == true)
            {
                cout << endl;
                leidos.mostrar();
                hayClientesActivos = true;
            }
        }
        if(hayClientesActivos == false)
        {
            cout << "\nNo hay clientes activos registrados." << endl;
        }
    }
    else
    {
        cout << "\nEl archivo de clientes esta vacio." << endl;
    }
    cout << endl;
    system("pause");
}

void ClientesManager::listarClientesResumido() const{

    ArchivoClientes archivo;
    int total = archivo.cantidadRegistros();

    for(int i = 0; i < total; i++){

        Cliente cliente = archivo.leer(i);

        if(cliente.getActivo()){
            cout << "ID: " << cliente.getId()
                 << " | " << cliente.getNombre()
                 << " " << cliente.getApellido()
                 << endl;
        }
    }
}


void ClientesManager::buscarClientePorID() const{

    int idBuscado;

    cout << "Ingrese ID del cliente: ";
    cin >> idBuscado;

    while(idBuscado <= 0){
        cout << "ID invalido. Intente nuevamente: ";
        cin >> idBuscado;
    }

    ArchivoClientes archivo;

    int cantidad = archivo.cantidadRegistros();

    for(int i = 0; i < cantidad; i++) {

        Cliente cliente = archivo.leer(i);

        if(cliente.getId() == idBuscado && cliente.getActivo()) {

            cout << "\nCliente encontrado:\n" << endl;
            cliente.mostrar();
            system("pause");
            return;
        }
    }

    cout << "\nNo se encontro un cliente activo con ese ID." << endl;
    system("pause");
}
