//
// Created by santiago on 18/03/2025.
//

#ifndef TIENDAS_PRODUCTO_H
#define TIENDAS_PRODUCTO_H
#include <iostream>
#include <string>
using namespace std;
class Producto {
private:
    Producto(string nombre, int num, int precio, int stock);

    string nombre;
    int num;
    int precio;
    int stock;
public:
    Producto();
    Producto(string, int, int, int, int);
    bool descontarStock(int cantidad);
    void agregarStock(int cantidad);
    string getProducto();
    void setProducto(string nombre);
};


#endif //TIENDAS_PRODUCTO_H
