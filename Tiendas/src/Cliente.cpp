//
// Created by santiago on 18/03/2025.
//

#include "Cliente.h"
#include <iostream>


using namespace std;

Cliente::Cliente(int id, string nombreCliente){
    this->id = id;
    this->nombreCliente = nombreCliente;
}

void Cliente::agregarCompra(Venta *venta) {
    
}