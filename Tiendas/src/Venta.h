//
// Created by santiago on 18/03/2025.
//

#ifndef TIENDAS_VENTA_H
#define TIENDAS_VENTA_H
#include <vector>
#include "Producto.h"
#include "Cliente.h"

using namespace std;
class Venta {
    private:
        int id;
        Cliente* cliente;
        vector<Producto*>productosVendidos;
    public:
        Venta() = default;
        Venta(Cliente* cliente);
        void agregarProductosvendido(Producto* venta);
        float calcularTotal();
        void mostrarDetalleVenta();
};


#endif //TIENDAS_VENTA_H
