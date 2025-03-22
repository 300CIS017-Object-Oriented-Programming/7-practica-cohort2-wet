//
// Created by santiago on 18/03/2025.
//

#include "Producto.h"
Producto::Producto(string nombre, int codigo, float precio, int stock){
    this->nombre = nombre;
    this->codigo = codigo;
    this->precio = precio;
    this->stock = stock;
}
bool Producto:: descontarStock(int cantidad){
    bool flag = false;
    if(stock >= cantidad){
        stock-=cantidad;
        flag = true;
    }
    return flag;
}
void Producto::agregarStock(int cantidad){
    if(cantidad > 0) {
        this->stock += cantidad;
        cout<<"Total: " << this->stock << " a " << this->nombre << endl;
    }
}
string Producto::getProducto() {
    return this->nombre;
}

void Producto::setProducto(string nombre) {
    this-> nombre = nombre;
}
float Producto::getPrecio() {
    return this->precio;
}

void Producto::setPrecio(float precio){
    this->precio = precio;
}
int Producto::getCodigo(){
    return this->codigo;
}
void Producto::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Producto:: getStock(){
 return this-> stock;
}

void Producto::setStock(int stock) {
    this->stock = stock;
}
