//
// Created by santiago on 18/03/2025.
//

#include "Tienda.h"
void Tienda::agregrarProducto(string nombre,int codigo, float precio, int stockInicial){
    Producto nuevoproducto(nombre,codigo,precio, stockInicial);
    inventario.push_back(nuevoproducto);
    cout << "Se agrego correctamente al inventario\n";
}
void Tienda::registrarVenta(int idCliente){
    Cliente cliente


}
void Tienda::reabastecerProducto(string codigoProducto, int cantidad){

}
Producto* Tienda::buscarProducto(string codigo){}
Cliente* Tienda::buscarCliente(int idCliente){
    for(int i = 0; i < clientes.size();i++){
        if( clientes[i].getId() == idCliente){
            return &clientes[i];
        }
    }
    cout << "No se encontro"


}
void Tienda::listarProductos(){
    int cont = 1;
    for(int i = 0; i < inventario.size(); i++) {
        cout << "Producto #" << cont << endl;
        cout << "Codigo: " << producto.getCodigo()<< endl;
        cout << "Producto: " << producto.getProducto()<< endl;
        cout << " Precio: " << producto.getPrecio()<< endl;
        cout << "Stock: " << producto.getStock()<< endl;
    }
    cont++;
}
void Tienda::mostrarVentas(){}
float Tienda::calcularValorInventario(){

}