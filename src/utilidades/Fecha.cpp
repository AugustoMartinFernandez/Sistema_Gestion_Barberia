#include "Fecha.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

Fecha::Fecha() {
    setCurrentDate(); // Por defecto, que sea la fecha actual
}

Fecha::Fecha(int dia, int mes, int anio) : _dia(dia), _mes(mes), _anio(anio) {}

// Getters y Setters
void Fecha::setDia(int dia) { _dia = dia; }
void Fecha::setMes(int mes) { _mes = mes; }
void Fecha::setAnio(int anio) { _anio = anio; }

int Fecha::getDia() const { return _dia; }
int Fecha::getMes() const { return _mes; }
int Fecha::getAnio() const { return _anio; }

//  Lógica de Sistema
void Fecha::setCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&now_c);

    _dia = localTime->tm_mday;
    _mes = localTime->tm_mon + 1;      // tm_mon va de 0 a 11
    _anio = localTime->tm_year + 1900; // tm_year son años desde 1900
}

std::string Fecha::toString() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << _dia << "/"
       << std::setfill('0') << std::setw(2) << _mes << "/"
       << _anio;
    return ss.str();
}

bool Fecha::esBisiesto(int anio) const {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool Fecha::esValida() const {
    if (_anio < 1900 || _anio > 2100) return false;
    if (_mes < 1 || _mes > 12) return false;

    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (esBisiesto(_anio)) diasMes[1] = 29;

    if (_dia < 1 || _dia > diasMes[_mes - 1]) return false;

    return true;
}
