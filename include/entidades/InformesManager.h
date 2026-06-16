#pragma once

struct conteoClientes {
    int idCliente;
    int cantidadVisitas;
};

class InformesManager {
public:
    void informeClientesFrecuentes() const;
    void informeEstadisticasTurnos() const;
    void informeBarbero() const;
    void informeMetodosPago() const;
    void recaudacionPorDia() const;
    void recaudacionPorMes() const;
    void recaudacionPorAnio() const;
};
