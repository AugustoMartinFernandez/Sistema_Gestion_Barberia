#pragma once
#include <cstring>

class Persona {
protected:
    int _id;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email[50];
    bool _activo;

public:
    Persona();

    // Setters
    void setId(int id);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);
    void setActivo(bool activo);

    // Getters
    int getId() const;
    const char* getNombre() const;
    const char* getApellido() const;
    const char* getTelefono() const;
    const char* getEmail() const;
    bool getActivo() const;

    // Métodos de interfaz
    virtual void cargar();
    virtual void mostrar() const;
};
