#include <iostream>
#include "BarberosManager.h"
#include "Barbero.h"
#include "BarberoArchivo.h"
#include "ArchivoConfiguracion.h"

using namespace std;

void BarberosManager::crearBarbero() const {
    Barbero barb;
    barb.cargar();

    ArchivoConfiguracion config;
    int nuevoId = config.getProximoIdBarbero();
    barb.setId(nuevoId);

    BarberoArchivo reg("barberos.dat");

    if(reg.cargarBarbero(barb)) {
        cout << "\n[EXITO] Barbero guardado correctamente con el ID: " << nuevoId << endl;
    } else {
        cout << "\n[ERROR] No se pudo guardar el barbero en el disco." << endl;
    }

    cout << endl;
    system("pause");
}

void BarberosManager::editarBarbero() const {
    int buscarId, pos, cantidad;
    BarberoArchivo reg("barberos.dat");
    Barbero barb;

    bool hayBarberoActivo = false;
    cantidad = reg.cantidadRegistros();

    if(cantidad == 0) {
        cout << "\nNo hay barberos en el archivo a modificar." << endl;
        cout << "Por favor, dirijase a la opcion 1 del menu para dar de alta un nuevo barbero." << endl;
    } else {
        for(int i = 0; i < cantidad; i++) {
            Barbero escaneo = reg.leer(i);
            if(escaneo.getActivo() == true) {
                hayBarberoActivo = true;
                break;
            }
        }

        if(hayBarberoActivo == false) {
            cout << "\nNo hay barberos activos en el sistema para modificar." << endl;
        } else {
            cout << "\n--- MODIFICAR BARBERO ---" << endl;
            cout << "Ingrese el ID del barbero a modificar: ";
            cin >> buscarId;

            while(buscarId <= 0) {
                cout << "ID Invalido. Intente nuevamente: ";
                cin >> buscarId;
            }

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                barb = reg.leer(pos);
                if(barb.getActivo() == true) {
                    cout << "\nFicha actual del barbero:" << endl;
                    barb.mostrar();

                    cout << "\nIngrese los nuevos datos:" << endl;
                    cin.ignore();
                    barb.cargar();
                    barb.setId(buscarId);

                    if(reg.modificarBarbero(barb, pos)) {
                        cout << "\nBarbero modificado correctamente." << endl;
                    } else {
                        cout << "\nNo se pudo guardar la modificacion en el archivo." << endl;
                    }
                } else {
                    cout << "\nNo se puede modificar un barbero dado de baja." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }

    cout << endl;
    system("pause");
}

void BarberosManager::gestionarEstadoBarbero() const {
    int subOpcion;

    cout << "---- GESTIONAR ESTADO DE BARBEROS ----" << endl;
    cout << "1 - Dar de baja a un barbero" << endl;
    cout << "2 - Reactivar a un barbero" << endl;
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
    BarberoArchivo reg("barberos.dat");
    Barbero barb;
    bool hayBarberosObjetivo = false;

    cantidad = reg.cantidadRegistros();
    if(cantidad == 0) {
        cout << "\nEl archivo esta vacio. No hay barberos para operar." << endl;
        system("pause");
        return;
    }

    // SUBOPCION 1: BAJA LOGICA
    if(subOpcion == 1) {
        for(int i = 0; i < cantidad; i++) {
            Barbero escaneo = reg.leer(i);
            if(escaneo.getActivo() == true) {
                hayBarberosObjetivo = true;
                break;
            }
        }

        if(hayBarberosObjetivo == false) {
            cout << "\nNo hay barberos activos en el sistema para dar de baja." << endl;
        } else {
            cout << "\n--- DAR DE BAJA BARBERO ---" << endl;
            cout << "Ingrese ID del Barbero a dar de baja: ";
            cin >> buscarId;

            while(buscarId <= 0) {
                cout << "ID Invalido. Intente nuevamente: ";
                cin >> buscarId;
            }

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                barb = reg.leer(pos);
                if(barb.getActivo() == true) {
                    cout << "\nFicha actual del barbero:" << endl;
                    barb.mostrar();

                    do {
                        cout << "\nEsta seguro que desea dar de baja a este barbero? (1=Si, 0=No): ";
                        cin >> confirmacion;
                        if(confirmacion != 1 && confirmacion != 0) {
                            cout << "Error. Ingrese 1=Si y 0=No." << endl;
                        }
                    } while(confirmacion != 1 && confirmacion != 0);

                    if(confirmacion == 1) {
                        barb.setActivo(false);
                        if(reg.modificarBarbero(barb, pos)) {
                            cout << "\nBarbero dado de Baja Exitosamente." << endl;
                        } else {
                            cout << "\nError al guardar la baja en el archivo." << endl;
                        }
                    } else {
                        cout << "\nOperacion cancelada. No se dio de Baja al barbero." << endl;
                    }
                } else {
                    cout << "\nError: Ese ID especifico ya pertenece a un barbero dado de baja." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }
    // SUBOPCION 2: REACTIVACION
    else if(subOpcion == 2) {
        for(int i = 0; i < cantidad; i++) {
            Barbero escaneo = reg.leer(i);
            if(escaneo.getActivo() == false) {
                hayBarberosObjetivo = true;
                break;
            }
        }

        if(hayBarberosObjetivo == false) {
            cout << "\nNo hay barberos dados de baja en el sistema para reactivar." << endl;
        } else {
            cout << "\n--- REACTIVAR BARBERO ---" << endl;
            cout << "Ingrese ID del Barbero a Reactivar: ";
            cin >> buscarId;

            while(buscarId <= 0) {
                cout << "ID Invalido. Intente nuevamente: ";
                cin >> buscarId;
            }

            pos = reg.buscar(buscarId);
            if(pos >= 0) {
                barb = reg.leer(pos);
                if(barb.getActivo() == false) {
                    barb.setActivo(true);
                    cout << "\nFicha del barbero a reactivar:" << endl;
                    barb.mostrar();

                    do {
                        cout << "\nEsta seguro que desea reactivar a este barbero? (1=Si, 0=No): ";
                        cin >> confirmacion;
                        if(confirmacion != 1 && confirmacion != 0) {
                            cout << "Error. Ingrese 1=Si y 0=No." << endl;
                        }
                    } while(confirmacion != 1 && confirmacion != 0);

                    if(confirmacion == 1) {
                        if(reg.modificarBarbero(barb, pos)) {
                            cout << "\nBarbero Reactivado Exitosamente." << endl;
                        } else {
                            cout << "\nError al guardar la reactivacion en el archivo." << endl;
                        }
                    } else {
                        barb.setActivo(false);
                        cout << "\nOperacion cancelada. El barbero sigue dado de baja." << endl;
                    }
                } else {
                    cout << "\nError: Ese ID especifico pertenece a un barbero que ya esta activo." << endl;
                }
            } else {
                cout << "\nEl ID ingresado no existe en el archivo." << endl;
            }
        }
    }

    cout << endl;
    system("pause");
}

void BarberosManager::listarBarberos() const {
    BarberoArchivo reg("barberos.dat");
    int total = reg.cantidadRegistros();
    bool hayBarberosActivos = false;

    cout << "---- LISTADO DE BARBEROS ----" << endl;

    if(total > 0) {
        for(int i = 0; i < total; i++) {
            Barbero leidos = reg.leer(i);

            // Solo mostramos si esta activo
            if(leidos.getActivo() == true) {
                cout << endl;
                leidos.mostrar();
                cout << "-------------------------" << endl;
                hayBarberosActivos = true;
            }
        }

        if(hayBarberosActivos == false) {
            cout << "\nNo hay barberos activos registrados." << endl;
        }
    } else {
        cout << "\nEl archivo de barberos esta vacio." << endl;
    }

    cout << endl;
    system("pause");
}
