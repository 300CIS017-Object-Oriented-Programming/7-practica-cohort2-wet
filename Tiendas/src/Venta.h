//
// Created by santiago on 18/03/2025.
//
#ifndef TIENDAS_VENTA_H
#define TIENDAS_VENTA_H

#include <vector>

#include "Producto.h"

class Cliente;

using namespace std;

class Venta {
private:
    int idVenta;
    Cliente *cliente;
    vector<Producto *> productosVendidos;

public:
    Venta();
    Venta(Cliente *cliente);
    void agregarProductoVendido(Producto* producto);
    float calcularTotal();
    void mostrarDetalleVenta();

};

#endif // TIENDAS_VENTA_H

