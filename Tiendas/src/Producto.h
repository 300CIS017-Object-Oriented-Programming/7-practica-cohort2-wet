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
    string nombre;
    int codigo;
    int precio;
    int stock;
public:
    Producto() = default;
    Producto(string, int, float, int);
    bool descontarStock(int cantidad);
    void agregarStock(int cantidad);
    string getProducto();
    void setProducto(string nombre);
    float getPrecio();
    void setPrecio(float precio);
    int getCodigo();
    void setCodigo(int codigo);
    int getStock();
    void setStock(int stock);
};


#endif //TIENDAS_PRODUCTO_H
