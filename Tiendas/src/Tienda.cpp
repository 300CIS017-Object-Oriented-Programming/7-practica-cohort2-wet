//
// Created by santiago on 18/03/2025.
//
#include "Venta.h"
#include <iostream>
#include "Tienda.h"
void Tienda::agregarProducto(string nombre,int codigo, float precio, int stockInicial){
    inventario.push_back(new Producto(nombre, codigo, precio, stockInicial));
    cout << "Se agrego correctamente al inventario\n";
}
void Tienda::registrarVenta(int idCliente) {
    Cliente* cliente= buscarCliente(idCliente);
    if (cliente == nullptr) {
        cout << "No se encontró el usuario!\n";
        return;
    }
    Venta* nuevaVenta = new Venta(cliente);
    cliente->agregarCompra(nuevaVenta);
    ventas.push_back(nuevaVenta);
}
void Tienda::reabastecerProducto(int codigoProducto, int cantidad){
    Producto* producto = buscarProducto(codigoProducto);
    if (producto) {
        producto->agregarStock(cantidad);
        cout << "Se reabasteció correctamente.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}
Producto* Tienda::buscarProducto(int codigo){
    for(int i = 0; i < inventario.size();i++){
        if( inventario[i]->getCodigo() == codigo){
            return inventario[i];
        }
    }
    cout << "No se encontro el producto\n";
    return nullptr;
}
Cliente* Tienda::buscarCliente(int idCliente){
    for(int i = 0; i < clientes.size();i++){
        if( clientes[i]->getId() == idCliente){
            return clientes[i];
        }
    }
    cout << "No se encontro el Usuario\n";
    return nullptr;
}
void Tienda::listarProductos(){
    int cont = 1;
    for(int i = 0; i < inventario.size(); i++) {
        cout << "Producto #" << cont << endl;
        cout << "Codigo: " << inventario[i]->getCodigo()<< endl;
        cout << "Producto: " << inventario[i]->getProducto()<< endl;
        cout << " Precio: " <<  inventario[i]->getPrecio()<< endl;
        cout << "Stock: " <<  inventario[i]->getStock()<< endl;
    }
    cont++;
}
void Tienda::mostrarVentas(){
    for(int i = 0; i < ventas.size();i++){
        cout << "Estas son las ventas: " << endl;
        ventas[i]->mostrarDetalleVenta();
    }
}
float Tienda::calcularValorInventario(){
    float suma = 0;
    for (int i = 0; i < inventario.size(); i++){
        suma+=inventario[i]->getPrecio();
    }
    return suma;
}
Tienda::~Tienda() {
    for (int i = 0; i < clientes.size(); i++) {
        delete clientes[i];
    }
    for (int i = 0; i < inventario.size(); i++) {
        delete inventario[i];
    }
    for (int i = 0; i < ventas.size(); i++) {
        delete ventas[i];
    }
    cout << "LLame al destructor, elimine todo y termine" << endl;
}