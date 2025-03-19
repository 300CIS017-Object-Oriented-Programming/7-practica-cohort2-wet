//
// Created by santiago on 18/03/2025.
//

#include "Producto.h"
Producto::Producto(string nombre, int num, int precio, int stock){
    this->nombre = nombre;
    this->num = num;
    this->precio = precio;
    this->stock = stock;
}
bool Producto:: descontarStock(int cantidad){

}
void Producto::agregarStock(int cantidad){

}
string Producto::getProducto() {
    return this->nombre;
}

void Producto::setProducto(string nombre) {
    this-> nombre = nombre;
}
