#include <iostream>
#include "Turno.h"

using namespace std;

Turno::Turno(){

    _id = 0;
    _idCliente = 0;
    _idBarbero = 0;
    _idServicio = 0;

    _activo = false;
}

void Turno::setId(int id){
    _id = id;
}
void Turno::setIdCliente(int idCliente){
    _idCliente = idCliente;
}
void Turno::setIdBarbero(int idBarbero){
    _idBarbero = idBarbero;
}
void Turno::setIdServicio(int idServicio){
    _idServicio = idServicio;
}
void Turno::setFecha(Fecha fecha){
    _fecha = fecha;
}
void Turno::setHora(Hora hora){
    _hora = hora;
}
void Turno::setActivo(bool activo){
    _activo = activo;
}



int Turno::getId() const{
    return _id;
}
int Turno::getIdCliente() const{
    return _idCliente;
}
int Turno::getIdBarbero() const{
    return _idBarbero;
}
int Turno::getIdServicio() const{
    return _idServicio;
}
Fecha Turno::getFecha() const{
    return _fecha;
}
Hora Turno::getHora() const{
    return _hora;
}
bool Turno::getActivo() const{
    return _activo;
}




void Turno::cargar(){

    int dia, mes, anio;
    int hora, minuto;

    cout << "ID Cliente: ";
    cin >> _idCliente;
    while(_idCliente <= 0) {
        cout << "ID Invalido. Intente nuevamente: ";
        cin >> _idCliente;
    }

    cout << "ID Barbero: ";
    cin >> _idBarbero;
    while(_idBarbero <= 0) {
        cout << "ID Invalido. Intente nuevamente: ";
        cin >> _idBarbero;
    }

    cout << "ID Servicio: ";
    cin >> _idServicio;
    while(_idServicio <= 0) {
        cout << "ID Invalido. Intente nuevamente: ";
        cin >> _idServicio;
    }

    do {
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        _fecha.setDia(dia);
        _fecha.setMes(mes);
        _fecha.setAnio(anio);

        if(!_fecha.esValida()){
            cout << "Fecha invalida. Intente nuevamente." << endl;
        }

    } while(!_fecha.esValida());

    do {
        cout << "Hora: ";
        cin >> hora;
        cout << "Minutos: ";
        cin >> minuto;

        _hora.setHora(hora);
        _hora.setMinuto(minuto);
        _hora.setSegundo(0); // dejamos en 0 para redondear

        if(!_hora.esValida()){
            cout << "Hora invalida. Intente nuevamente." << endl;
        }

    } while(!_hora.esValida());

    _activo = true;
}

void Turno::mostrar() const{

    cout << "ID Turno: " << _id << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "ID Barbero: " << _idBarbero << endl;
    cout << "ID Servicio: " << _idServicio << endl;
    cout << "Fecha: " << _fecha.toString() << endl;

    cout << "Hora: " << _hora.toString() << endl;

    cout << "Estado: ";
    if(_activo){
        cout << "Activo";
    }
    else{
        cout << "Cancelado";
    }
    cout << "-------------------" << endl;

    cout << endl;
}
