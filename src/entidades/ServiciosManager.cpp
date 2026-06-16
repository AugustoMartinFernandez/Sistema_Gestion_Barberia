#include <iostream>
#include "ServiciosManager.h"
#include "Servicio.h"
#include "ArchivoServicios.h"
#include "ArchivoConfiguracion.h"

using namespace std;

void ServiciosManager::crearServicio() const {
    Servicio ser;
    ser.cargar();

    ArchivoConfiguracion config;
    int nuevoId = config.getProximoIdServicio();
    ser.setId(nuevoId);

    ArchivoServicios reg;

    if(reg.guardar(ser)) {
        cout << "\n[EXITO] Servicio guardado correctamente con el ID: " << nuevoId << endl;
    } else {
        cout << "\n[ERROR] No se pudo guardar el servicio en el disco." << endl;
    }

    cout << endl;
    system("pause");
}

void ServiciosManager::editarServicio() const {
    int buscarId, pos, cantidad;
    ArchivoServicios reg;
    Servicio ser;

    bool hayServicioActivo = false;
    cantidad = reg.cantidadRegistros();

    if(cantidad == 0) {
        cout << "\nNo hay servicios en el archivo a modificar." << endl;
    } else {
        for(int i = 0; i < cantidad; i++) {
            Servicio escaneo = reg.leer(i);
            if(escaneo.getActivo() == true) {
                hayServicioActivo = true;
                break;
            }
        }

        if(hayServicioActivo == false) {
            cout << "\nNo hay servicios activos en el sistema para modificar." << endl;
        } else {
            cout << "\n--- MODIFICAR SERVICIO ---" << endl;
            cout << "Ingrese el ID del servicio a modificar: ";
            cin >> buscarId;

            while(buscarId <= 0) {
                cout << "ID Invalido. Intente nuevamente: ";
                cin >> buscarId;
            }

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                ser = reg.leer(pos);
                if(ser.getActivo() == true) {
                    cout << "\nDatos actuales del servicio:" << endl;
                    ser.mostrar();

                    cout << "\nIngrese los nuevos datos:" << endl;
                    cin.ignore();
                    ser.cargar();
                    ser.setId(buscarId); // Blindamos el ID para no pisarlo

                    if(reg.guardar(ser, pos)) {
                        cout << "\nServicio modificado correctamente." << endl;
                    } else {
                        cout << "\nNo se pudo guardar la modificacion en el archivo." << endl;
                    }
                } else {
                    cout << "\nNo se puede modificar un servicio dado de baja." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }

    cout << endl;
    system("pause");
}

void ServiciosManager::gestionarEstadoServicio() const {
    int subOpcion;

    cout << "---- GESTIONAR ESTADO DE SERVICIOS ----" << endl;
    cout << "1 - Dar de baja a un servicio" << endl;
    cout << "2 - Reactivar a un servicio" << endl;
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
    ArchivoServicios reg;
    Servicio ser;
    bool hayServicioObjetivo = false;

    cantidad = reg.cantidadRegistros();
    if(cantidad == 0) {
        cout << "\nEl archivo esta vacio. No hay servicios para operar." << endl;
        system("pause");
        return;
    }

    // SUBOPCION 1: BAJA LOGICA
    if(subOpcion == 1) {
        for(int i = 0; i < cantidad; i++) {
            Servicio escaneo = reg.leer(i);
            if(escaneo.getActivo() == true) {
                hayServicioObjetivo = true;
                break;
            }
        }

        if(hayServicioObjetivo == false) {
            cout << "\nNo hay servicios activos en el sistema para dar de baja." << endl;
        } else {
            cout << "\n--- DAR DE BAJA SERVICIO ---" << endl;
            cout << "Ingrese ID del Servicio a dar de baja: ";
            cin >> buscarId;

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                ser = reg.leer(pos);
                if(ser.getActivo() == true) {
                    cout << "\nDatos actuales del servicio:" << endl;
                    ser.mostrar();

                    do {
                        cout << "\nEsta seguro que desea dar de baja este servicio? (1=Si, 0=No): ";
                        cin >> confirmacion;
                    } while(confirmacion != 1 && confirmacion != 0);

                    if(confirmacion == 1) {
                        ser.setActivo(false);
                        if(reg.guardar(ser, pos)) {
                            cout << "\nServicio dado de Baja Exitosamente." << endl;
                        } else {
                            cout << "\nError al guardar la baja en el archivo." << endl;
                        }
                    } else {
                        cout << "\nOperacion cancelada." << endl;
                    }
                } else {
                    cout << "\nError: Ese ID ya pertenece a un servicio dado de baja." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }
    // SUBOPCION 2: REACTIVACION
    else if(subOpcion == 2) {
        for(int i = 0; i < cantidad; i++) {
            Servicio escaneo = reg.leer(i);
            if(escaneo.getActivo() == false) {
                hayServicioObjetivo = true;
                break;
            }
        }

        if(hayServicioObjetivo == false) {
            cout << "\nNo hay servicios dados de baja en el sistema para reactivar." << endl;
        } else {
            cout << "\n--- REACTIVAR SERVICIO ---" << endl;
            cout << "Ingrese ID del Servicio a Reactivar: ";
            cin >> buscarId;

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                ser = reg.leer(pos);
                if(ser.getActivo() == false) {
                    ser.setActivo(true);
                    cout << "\nDatos del servicio a reactivar:" << endl;
                    ser.mostrar();

                    do {
                        cout << "\nEsta seguro que desea reactivar este servicio? (1=Si, 0=No): ";
                        cin >> confirmacion;
                    } while(confirmacion != 1 && confirmacion != 0);

                    if(confirmacion == 1) {
                        if(reg.guardar(ser, pos)) {
                            cout << "\nServicio Reactivado Exitosamente." << endl;
                        } else {
                            cout << "\nError al guardar la reactivacion en el archivo." << endl;
                        }
                    } else {
                        cout << "\nOperacion cancelada." << endl;
                    }
                } else {
                    cout << "\nError: Ese ID pertenece a un servicio que ya esta activo." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe." << endl;
            }
        }
    }

    cout << endl;
    system("pause");
}

void ServiciosManager::listarServicios() const {
    ArchivoServicios reg;
    int total = reg.cantidadRegistros();
    bool hayServiciosActivos = false;

    cout << "---- LISTADO DE SERVICIOS ----" << endl;

    if(total > 0) {
        for(int i = 0; i < total; i++) {
            Servicio leido = reg.leer(i);

            if(leido.getActivo() == true) {
                cout << endl;
                leido.mostrar();
                hayServiciosActivos = true;
            }
        }

        if(hayServiciosActivos == false) {
            cout << "\nNo hay servicios activos registrados." << endl;
        }
    } else {
        cout << "\nEl archivo de servicios esta vacio." << endl;
    }

    cout << endl;
    system("pause");
}


void ServiciosManager::listarServiciosResumido() const{

    ArchivoServicios archivo;
    int total = archivo.cantidadRegistros();

    for(int i = 0; i < total; i++){

        Servicio servicio = archivo.leer(i);

        if(servicio.getActivo()){
            cout << "ID: " << servicio.getId()
                 << " | " << servicio.getDescripcion()
                 << " | $" << servicio.getPrecio()
                 << endl;
        }
    }
}
