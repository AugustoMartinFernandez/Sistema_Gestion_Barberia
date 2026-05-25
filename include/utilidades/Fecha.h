#pragma once
#include <string>

class Fecha {
private:
    int _dia, _mes, _anio;

    // Método privado para validar internamente
    bool esBisiesto(int anio) const;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    // Setters con validación
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Métodos de utilidad
    void setCurrentDate();
    std::string toString() const; // Devuelve "DD/MM/AAAA"
    bool esValida() const;        // Verifica si la fecha actual es real
};
