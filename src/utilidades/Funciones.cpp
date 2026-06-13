#include <iostream>
#include "Funciones.h"
#include "Barbero.h"
#include "BarberoArchivo.h"
#include "ArchivoConfiguracion.h"
using namespace std;


void agregarBarbero(){
            cout << endl << "--- ALTA DE NUEVO BARBERO ---" << endl;
            Barbero barb;
            cin.ignore();
            barb.cargar();

            ArchivoConfiguracion config;
            int nuevoId = config.getProximoIdBarbero();
            barb.setId(nuevoId);

            BarberoArchivo reg;

            if(reg.cargarBarbero(barb))
            {
                cout << "\n[EXITO] Barbero guardado correctamente con el ID: " << nuevoId << endl;
            }
            else
            {
                cout << "\n[ERROR] No se pudo guardar el barbero en el disco." << endl;
            }
}

void modificarBarbero()
{int buscarId,pos,cantidad;
            BarberoArchivo reg;
            Barbero barb;

            bool hayBarberoActivo = false;
            cantidad = reg.cantidadRegistros();

            if(cantidad == 0)
            {
                cout << "No hay barberos en el archivo a modificar." <<endl;
                cout << "Por favor, dirijase a la opcion 1 del menu para dar de alta un nuevo barbero." << endl;
            }
            else
            {
                for(int i=0; i<cantidad; i++)
                {
                    Barbero escaneo = reg.leer(i);
                    if(escaneo.getActivo() == true)
                    {
                        hayBarberoActivo = true;
                        break;
                    }
                }
                if(hayBarberoActivo == false)
                {
                    cout << "No hay barberos activos en el sistema para modificar." << endl;
                }
                else
                {
                    cout << "--- MODIFICAR BARBEROS ---" <<endl;
                    cout << "Ingrese el ID del barbero a modificar: "<<endl;
                    cin >> buscarId;

                    while(buscarId <= 0)
                    {
                        cout << "ID Invalido. Intente nuevamente: ";
                        cin >> buscarId;
                    }

                    pos = reg.buscar(buscarId);
                    if(pos >= 0)
                    {
                        barb = reg.leer(pos);
                        if(barb.getActivo()==true)
                        {
                            cout<< "Ficha actual del barbero:" << endl;
                            barb.mostrar();
                            cout<< "Ingrese los nuevos datos:" << endl;
                            cin.ignore();
                            barb.cargar();
                            barb.setId(buscarId);
                            if(reg.modificarBarbero(barb, pos))
                            {
                                cout << "\nBarbero modificado correctamente." << endl;
                            }
                            else
                            {
                                cout << "\nNo se pudo guardar la modificacion en el archivo." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nNo se puede modificar un barbero  dado de baja" <<endl;
                        }
                    }
                    else
                    {
                        cout << "\nEl ID ingresado no existe en el archivo." << endl;
                    }
                }
            }
}
// LISTAR BARBEROS
void listarBarbero(){
cout << endl << "--- LISTADO DE BARBEROS ---" << endl;
            BarberoArchivo reg;
            int total = reg.cantidadRegistros();
            bool hayBarberosActivos = false; // ESTA ES NUESTRA BANDERA

            if(total > 0)
            {
                for(int i = 0; i < total; i++)
                {
                    Barbero leidos = reg.leer(i);

                    // Solo mostramos si está activo
                    if(leidos.getActivo() == true)
                    {
                        leidos.mostrar();
                        cout << endl << "-------------------------" << endl << endl;
                        hayBarberosActivos = true; // Si encontramos uno, la bandera cambia
                    }
                }

                // Al terminar el ciclo, si la bandera nunca cambio, avisamos
                if(hayBarberosActivos == false)
                {
                    cout << "No hay barberos activos registrados." << endl;
                }
            }
            else
            {
                cout << "El archivo de barberos esta vacio." << endl;
            }
}
