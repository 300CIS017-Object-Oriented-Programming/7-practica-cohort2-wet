#include "Venta.h"
#include "Cliente.h"
#include <iostream>

using namespace std;

// Constructor sin parámetros
Venta::Venta() {
    this->cliente = nullptr;
    this->idVenta = 0;
}

// Constructor con cliente
Venta::Venta(Cliente* cliente) {
    this->cliente = cliente;
    this->idVenta = idVenta;
}


void Venta::agregarProductoVendido(Producto* producto) {
    productosVendidos.push_back(producto);

}


float Venta::calcularTotal() {
    float suma = 0;
    for (int i = 0; i < productosVendidos.size(); i++) {
        suma += productosVendidos[i]->getPrecio();
    }
    return suma;
}


void Venta::mostrarDetalleVenta() {
    cout << " - Cliente: " << cliente->getCliente() << endl;
    cout << "Productos vendidos:\n";
    for (int i = 0; i < productosVendidos.size(); i++) {
        cout << "- " << productosVendidos[i]->getProducto() << " ($" << productosVendidos[i]->getPrecio() << ")\n";
    }
    cout << "Total de venta: $" << calcularTotal() << endl;
}
