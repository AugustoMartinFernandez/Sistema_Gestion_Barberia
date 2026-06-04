#include "Hora.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

Hora::Hora() {
    setCurrentTime(); // Por defecto, la hora actual
}

Hora::Hora(int hora, int minuto, int segundo)
    : _hora(hora), _minuto(minuto), _segundo(segundo) {}

// --- Getters y Setters ---
void Hora::setSegundo(int segundo) { _segundo = segundo; }
void Hora::setMinuto(int minuto) { _minuto = minuto; }
void Hora::setHora(int hora) { _hora = hora; }

int Hora::getSegundo() const { return _segundo; }
int Hora::getMinuto() const { return _minuto; }
int Hora::getHora() const { return _hora; }

// --- Lógica de Sistema ---
void Hora::setCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&now_c);

    _hora = localTime->tm_hour;
    _minuto = localTime->tm_min;
    _segundo = localTime->tm_sec;
}

std::string Hora::toString() const {
    std::stringstream ss;
    // Formato profesional: 09:05:01 en lugar de 9:5:1
    ss << std::setfill('0') << std::setw(2) << _hora << ":"
       << std::setfill('0') << std::setw(2) << _minuto << ":"
       << std::setfill('0') << std::setw(2) << _segundo;
    return ss.str();
}

bool Hora::esValida() const {
    if (_hora < 0 || _hora > 23) return false;
    if (_minuto < 0 || _minuto > 59) return false;
    if (_segundo < 0 || _segundo > 59) return false;
    return true;
}
