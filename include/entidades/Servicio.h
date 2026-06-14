#pragma once

class Servicio {
private:
    int _id;
    char _descripcion[50];
    float _precio;
    bool _activo;

public:
    Servicio();

    // Setters
    void setId(int id);
    void setDescripcion(const char* descripcion);
    void setPrecio(float precio);
    void setActivo(bool activo);

    // Getters
    int getId() const;
    const char* getDescripcion() const;
    float getPrecio() const;
    bool getActivo() const;

    // Metodos principales
    void cargar();
    void mostrar() const;
};
