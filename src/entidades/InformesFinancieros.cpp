#include <iostream>
using namespace std;
#include "InformesFinancieros.h"
#include "ArchivoTurnos.h"
#include "Fecha.h"
#include "InformeFinanciero.h"
#include "ArchivoTurnos.h"
#include "ArchivoServicios.h"
#include "Turno.h"
#include "Fecha.h"
#include "Servicio.h"
#include <iostream>

#include <iomanip> // verificar



void InformesFinancieros::RecaudacionDiaria ()const{

ArchivoTurnos archiTurnos;
ArchivoServicios archiServ;
int dia, mes , anio;
float total = 0.0f;

cout<< "  - - - - Recaudacion DIARIA  - - - - \n";
cout << "Ingrese Fecha (dd - mm - anio): ";
cin>> dia;
cin>>mes;
cin>>anio;

int cantidad = archiTurnos.cantidadRegistros ();

if (cantidad == 0 ) {
   cout<< "No hubo turnos registrados. "<<endl;
   return;
}

for (int i=0; i< cantidad; i++) {
    Turno t = archiTurnos.leer (i);

    if (t.getActivo()== false) continue; //verificamos que
          // solo turnos activvoss realizados

        Fecha f = t.getFecha ();
    if ( f.getDia()== dia && f.getMes()== mes && f.getAnio()== anio ){

        //precio del serv
        int idServicio = t.getIdServicio ();
        int posServicio = archiServ.buscar (idServicio);

        if (posServicio != -1) {
            Servicio s = archiServ.leer (posServicio);
            total += s.getPrecio ();
        }
    }
}
 cout<< std::fixed << std::setprecision (2);
 cout<<  "Recaudacion del "<<dia<< "/"<< mes << "/"<<anio
     << ": $ "<<total <<endl;
}

void InformesFinancieros::RecaudacionMensual ()const {
ArchivoTurnos architurnos;
ArchivoServicios archiservicio;

int mes, anio;
int diasMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

cout<< " - - - - - Recaudacion MENSUAL  - - - - "<<endl;
cout<< "Ingrese mes y anio (mes - anio) ";
cin>>mes;
cin>>anio;

   if (mes < 1 || mes > 12) {
        cout << " Error, Mes inválido."<<endl;
        return;
 }

 int dias = diasMeses [mes- 1];
 float* recaudacion = new float [dias] ();

  if (recaudacion == NULL) {
    cout << "Error De asignacion de Memoria"<<endl;
     return;
      }

float totalMes = 0.0f;

   int cant = architurnos.cantidadRegistros ();
   if  (cant == 0) {
    cout << "No hay Turnos registrados ..."<<endl;
    delete [] recaudacion;
    return;
   }

   for (int i = 0; i< cant; i++){
    Turno t= architurnos.leer (i);
    if (t.getActivo ()== false) continue;

    Fecha f= t.getFecha ();

    if (f.getMes ()== mes && f.getAnio()== anio){
        int dia = f.getDia ();
        if (dia >= 1 && dia <= dias ) {

            int idServicio = t.getIdServicio ();
            int posServicio = archiservicio.buscar (idServicio);

            if (posServicio != -1) {
                Servicio s = archiservicio.leer (posServicio);
                recaudacion [dia -1] += s.getPrecio ();
                totalMes += s.getPrecio ();  //acumula el total del mes;
          }
        }
      }
   }

  cout<< std::fixed << std::setprecision (2);
  cout<< "Recaudacion del mes"<< mes << "/"<<anio<<endl;

  for (int i = 0; i < dias; i++) {
    cout<< "Dia #"<< (i + 1)<< ": $ "<< recaudacion [i]<<endl;
  }
  cout<< " - - - - - - - - - - - "
  cout << "Total del Mes: $ "<< totalMes<<endl;

   int SinVentas =0;

   for (int i=0; i< dias; i++){

         if  (recaudacion [i]== 0 ) SinVentas++;
   }
   cout<< "Dias Sin recaudacion: "<<SinVentas <<endl;

   delete []recaudacion;
}



 void InformesFinancieros::RecaudacionAnual ()const {
     ArchivoTurnos architurnos;
     ArchivoServicios archiservicios;

     int anio;
     float total =0.0f;

      cout<< "--- RECAUDACIÓN ANUAL ---"<<endl;
   cout<< "Ingrese año (aaaa): ";
    cin>>anio;

     int cant = architurnos.cantidadRegistros ();
     if (cant == 0 ){
        cout << "No hay Turnos registrados hasta el momento..."<<endl;
        return;
     }

     for (int i=0; i<cant; i++){

        Turno t= architurnos.leer (i);
        if (t.getActivo()) continue;


        Fecha f = t.getFecha ();
        if (f.getAnio()== anio ){

            int idServicio =t.getIdServicio ();
            int posServicio = archiservicios.buscar (idServicio);

            if (posServicio != -1) {
                Servicio s = archiservicios.leer (posServicio);
                total += s.getPrecio ();
            }
        }
     }

     cout<< std::fixed<< std::setprecision (2);
     cout << "Recaudacion del anio "<<anio << ": $ "<< total<<endl;

}

void InformesFinancieros::ServicioSupere5mil ()const;

void InformesFinancieros::BarberoMasCortes () const;

void InformesFinancieros::MetodosPagoUtilizados ()const;
