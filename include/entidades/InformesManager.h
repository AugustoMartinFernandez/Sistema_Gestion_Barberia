#pragma once

struct conteoClientes {
    int idCliente;
    int cantidadVisitas;
};

// struct axuliare
//para servicios mas solicitados

struct conteoServicios {
int idServicio;
int cantidad;
};

//para ventas por servicio

struct ventasServicio {
  int idServicio;
  float totalfact;
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

    // informes gest. servicios

    void InformeServMasSolicitados ()const;
    void InformeVentPorServicio ()const;
};
