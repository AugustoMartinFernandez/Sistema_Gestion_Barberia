#include <iostream>
#include "Pago.h"
#include <cstring>

using namespace std;

Pago::Pago(){
    _id = 0;
    _idTurno = 0;
    _monto = 0;
    strcpy(_metodoPago, "Sin metodo");
    _activo = false;
}

void Pago::setId(int id){
    _id = id;
}
void Pago::setIdTurno(int idTurno){
    _idTurno = idTurno;
}
void Pago::setMonto(float monto){
    _monto = monto;
}
void Pago::setFechaPago(Fecha fechaPago){
    _fechaPago = fechaPago;
}
void Pago::setHoraPago(Hora horaPago){
    _horaPago = horaPago;
}
void Pago::setMetodoPago(const char* metodoPago){
    strncpy(_metodoPago, metodoPago, 19);
    _metodoPago[19] = '\0';
}
void Pago::setActivo(bool activo){
    _activo = activo;
}


int Pago::getId() const{
    return _id;
}
int Pago::getIdTurno() const{
    return _idTurno;
}
float Pago::getMonto() const{
    return _monto;
}
Fecha Pago::getFechaPago() const{
    return _fechaPago;
}
Hora Pago::getHoraPago() const{
    return _horaPago;
}
const char* Pago::getMetodoPago() const{
    return _metodoPago;
}
bool Pago::getActivo() const{
    return _activo;
}

void Pago::cargar(){
    if (_monto == 0) {
        setMetodoPago("Canje Puntos");
        cout << "Metodo de pago: Canje Puntos" << endl;
    } else {
        int opcionMetodo = 0;
        bool opcionValida = false;

        cout << endl;
        cout << "--- SELECCIONE METODO DE PAGO ---" << endl;
        cout << "1. Efectivo" << endl;
        cout << "2. Tarjeta de Debito/Credito" << endl;
        cout << "3. Transferencia (MercadoPago)" << endl;
        cout << "4. Otro" << endl;

        while (!opcionValida) {
            cout << "Opcion: ";
            cin >> opcionMetodo;

            switch(opcionMetodo) {
                case 1:
                    setMetodoPago("Efectivo");
                    opcionValida = true;
                    break;
                case 2:
                    setMetodoPago("Tarjeta");
                    opcionValida = true;
                    break;
                case 3:
                    setMetodoPago("Transferencia");
                    opcionValida = true;
                    break;
                case 4:
                    setMetodoPago("Otro");
                    opcionValida = true;
                    break;
                default:
                    cout << "Opcion invalida. Intente de nuevo." << endl;
                    break;
            }
        }
    }

    _fechaPago.setCurrentDate();
    _horaPago.setCurrentTime();

    _activo = true;
}



void Pago::mostrar() const{

    if(_activo){
        cout << "ID Pago: " << _id << endl;
        cout << "ID Turno: " << _idTurno << endl;
        cout << "Monto: $" << _monto << endl;
        cout << "Fecha de pago: " << _fechaPago.toString() << endl;
        cout << "Hora de pago: " << _horaPago.toString() << endl;
        cout << "Metodo de pago: " << _metodoPago << endl;
        cout << "-------------------------" << endl;
    }
}
