#pragma once

class TurnosManager{

private:
    bool entidadesValidasYActivas(int idCliente, int idBarbero, int idServicio);

public:

    void crearTurno();
    void listarTurnos();
    int buscarClientePorNombreApellido();
    void editarTurno();
    void borrarTurno();
    void listarTurnosResumido();
    void listarTurnosPorEstado();

};
