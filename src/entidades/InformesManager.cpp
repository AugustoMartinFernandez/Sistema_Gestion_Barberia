#include <iostream>
#include "InformesManager.h"
#include "ArchivoPagos.h"
#include "Pago.h"
#include "Fecha.h"

using namespace std;

void InformesManager::recaudacionPorDia() const
{
    ArchivoPagos archivo;
    Pago pago;

    int dia, mes, anio;
    float total = 0;
    int cantidadPagos = 0;

    cout << "Ingrese dia: ";
    cin >> dia;

    cout << "Ingrese mes: ";
    cin >> mes;

    cout << "Ingrese anio: ";
    cin >> anio;

    for(int i = 0; i < archivo.cantidadRegistros(); i++)
    {
        pago = archivo.leer(i);

        if(pago.getActivo() == true)
        {
            Fecha fechaPago = pago.getFechaPago();

            if(fechaPago.getDia() == dia &&
               fechaPago.getMes() == mes &&
               fechaPago.getAnio() == anio)
            {
                total += pago.getMonto();
                cantidadPagos++;
            }
        }
    }

    cout << endl;
    cout << "Recaudacion del dia " << dia << "/" << mes << "/" << anio << ": $" << total << endl;
    cout << "Cantidad de pagos encontrados: " << cantidadPagos << endl;

    system("pause");
}

void InformesManager::recaudacionPorMes() const
{
    ArchivoPagos archivo;
    Pago pago;

    int mes, anio;
    float total = 0;
    int cantidadPagos = 0;

    cout << "Ingrese mes: ";
    cin >> mes;

    cout << "Ingrese anio: ";
    cin >> anio;

    for(int i = 0; i < archivo.cantidadRegistros(); i++)
    {
        pago = archivo.leer(i);

        if(pago.getActivo() == true)
        {
            Fecha fechaPago = pago.getFechaPago();

            if(fechaPago.getMes() == mes &&
               fechaPago.getAnio() == anio)
            {
                total += pago.getMonto();
                cantidadPagos++;
            }
        }
    }

    cout << endl;
    cout << "Recaudacion del mes " << mes << "/" << anio << ": $" << total << endl;
    cout << "Cantidad de pagos encontrados: " << cantidadPagos << endl;

    system("pause");
}

void InformesManager::recaudacionPorAnio() const
{
    ArchivoPagos archivo;
    Pago pago;

    int anio;
    float total = 0;
    int cantidadPagos = 0;

    cout << "Ingrese anio: ";
    cin >> anio;

    for(int i = 0; i < archivo.cantidadRegistros(); i++)
    {
        pago = archivo.leer(i);

        if(pago.getActivo() == true)
        {
            Fecha fechaPago = pago.getFechaPago();

            if(fechaPago.getAnio() == anio)
            {
                total += pago.getMonto();
                cantidadPagos++;
            }
        }
    }

    cout << endl;
    cout << "Recaudacion del anio " << anio << ": $" << total << endl;
    cout << "Cantidad de pagos encontrados: " << cantidadPagos << endl;

    system("pause");
}
