//
// Created by santiago on 18/03/2025.
//

#ifndef TIENDAS_CLIENTE_H
#define TIENDAS_CLIENTE_H
#include "Venta.h"
#include "Producto.h"

using namespace std;

class Cliente {
    private:
        int id;
        string nombreCliente;
        vector<Venta*>compras;
    public:
        Cliente() = default;
        Cliente(int id, string nombreCliente);
        void agregarCompra(Venta* venta);
        void mostrarHistorialCompras();
        string getCliente();
        int getId();
};


#endif //TIENDAS_CLIENTE_H
