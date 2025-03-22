//
// Created by santiago on 18/03/2025.
//

#include "Cliente.h"
#include "Venta.h"
using namespace std;

Cliente::Cliente(int id, string nombreCliente){
    this->id = id;
    this->nombreCliente = nombreCliente;
}

void Cliente::agregarCompra(Venta *venta) {
    compras.push_back(venta);
}

void Cliente::mostrarHistorialCompras() {
    cout << "Cliente: " << getCliente()<< endl;
    cout << "Historial de compras: "<< endl;
    for(int i = 0; i < compras.size(); i++){
        compras[i]->mostrarDetalleVenta();
    }
}

string Cliente::getCliente() {
    return this->nombreCliente;
}
int Cliente::getId() {
    return this->id;
}
void Cliente::setCliente(string nombreCliente) {
    this->nombreCliente = nombreCliente;
}

void Cliente::setId(int id) {
    this->id = id;
}