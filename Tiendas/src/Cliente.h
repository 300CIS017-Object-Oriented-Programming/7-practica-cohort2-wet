//
// Created by santiago on 18/03/2025.
//

#ifndef TIENDAS_CLIENTE_H
#define TIENDAS_CLIENTE_H

#include "Producto.h"
#include <vector>
class Venta;

using namespace std;

class Cliente {
    private:
        int id;
        string nombreCliente;
        vector<Venta *>compras;
    public:
        Cliente() = default;
        Cliente(int id, string nombreCliente);
        void agregarCompra(Venta* venta);
        void mostrarHistorialCompras();
        string getCliente();
        void setCliente(string);
        int getId();
        void setId(int);

};


#endif //TIENDAS_CLIENTE_H
