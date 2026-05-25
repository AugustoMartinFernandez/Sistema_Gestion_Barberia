#pragma once
#include <string>

class Hora {
private:
    int _segundo, _minuto, _hora;

public:
    Hora();
    Hora(int hora, int minuto, int segundo = 0);

    // Setters
    void setSegundo(int segundo);
    void setMinuto(int minuto);
    void setHora(int hora);

    // Getters
    int getSegundo() const;
    int getMinuto() const;
    int getHora() const;

    // Métodos de utilidad
    void setCurrentTime();
    std::string toString() const; // Devuelve "HH:MM:SS"
    bool esValida() const;        // Valida que la hora sea real (0-23, 0-59)
};
