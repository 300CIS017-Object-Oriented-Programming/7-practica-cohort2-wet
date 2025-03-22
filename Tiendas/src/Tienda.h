//
// Created by santiago on 18/03/2025.
//

#ifndef TIENDAS_TIENDA_H
#define TIENDAS_TIENDA_H
#include <iostream>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

using namespace std;

class Tienda {
    private:
        vector<Producto *>inventario;
        vector<Cliente *>clientes;
        vector<Venta *>ventas;
    public:

        Tienda();
        ~Tienda();
        void inicializarDatos();
        void agregarProducto(string nombre,int codigo, float precio, int stockInicial);
        void registrarVenta(int idCliente);
        void reabastecerProducto(int codigoProducto, int cantidad);
        Producto* buscarProducto(int codigo);
        Cliente* buscarCliente(int idCliente);
        void listarProductos();
        void mostrarVentas();
        float calcularValorInventario();
};


#endif //TIENDAS_TIENDA_H
