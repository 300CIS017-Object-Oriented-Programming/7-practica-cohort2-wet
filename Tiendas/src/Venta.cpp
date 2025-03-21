//
// Created by santiago on 18/03/2025.
//

#include "Venta.h"
#include "Producto.h"
using namespace std;
Venta::Venta(Cliente* cliente) {
    this->cliente = cliente;
}
void Venta::agregarProductosvendido(Producto* venta){
    productosVendidos.push_back(venta);
}
float Venta::calcularTotal(){
    int suma = 0;
    for(int i = 0; i < productosVendidos.size(); i++){
       suma+=productosVendidos[i]->getPrecio();
    }
    return suma;
}
void Venta::mostrarDetalleVenta(){
    cout << "Nombre del cliente: " << cliente->getCliente() << endl;
    for(int i = 0 ; i < productosVendidos.size(); i++){
        cout << " Producto: " << productosVendidos[i]->getProducto() << " Precio: "
        << productosVendidos[i]->getPrecio() << endl;
    }
    cout << "Total de venta: " << calcularTotal() << endl;
}