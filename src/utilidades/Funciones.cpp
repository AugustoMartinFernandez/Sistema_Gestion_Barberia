#include <iostream>
#include "Funciones.h"
#include "Barbero.h"
#include "BarberoArchivo.h"
#include "ArchivoConfiguracion.h"
using namespace std;


void agregarBarbero(){
            cout << endl << "--- ALTA DE NUEVO BARBERO ---" << endl;
            Barbero barb;
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
