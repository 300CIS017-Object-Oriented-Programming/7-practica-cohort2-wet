//
// Created by santiago on 18/03/2025.
//

#ifndef TIENDAS_TIENDA_H
#define TIENDAS_TIENDA_H

#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

using namespace std;

class Tienda {
    private:
        Cliente cliente;
        Producto producto;
        Venta venta;
        vector<Producto>inventario;
        vector<Cliente>clientes;
    public:
        void agregrarProducto(string nombre,int codigo, float precio, int stockInicial);
        void registrarVenta(int idCliente);
        void reabastecerProducto(string codigoProducto, int cantidad);
        Producto* buscarProducto(string codigo);
        Cliente* buscarCliente(int idCliente);
        void listarProductos();
        void mostrarVentas();
        float calcularValorInventario();
};


#endif //TIENDAS_TIENDA_H
