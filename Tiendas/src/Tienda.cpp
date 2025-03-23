//
// Created by santiago on 18/03/2025.
//
#include "Venta.h"
#include <iostream>
#include "Tienda.h"
Tienda:: Tienda(){
    inicializarDatos();
}
void Tienda::inicializarDatos() {

    Producto *producto1 = new Producto();
    Producto *producto2 = new Producto();
    Producto *producto3 = new Producto();
    Producto *producto4 = new Producto();

    producto1->setProducto("Colgate");
    producto1->setCodigo(1);
    producto1->setPrecio(3000);
    producto1->setStock(5);

    producto2->setProducto("Jabon Palmolive");
    producto2->setCodigo(2);
    producto2->setPrecio(2500);
    producto2->setStock(10);

    producto3->setProducto("Cereal Zucaritas");
    producto3->setCodigo(3);
    producto3->setPrecio(14000);
    producto3->setStock(7);

    producto4->setProducto("Doritos");
    producto4->setCodigo(4);
    producto4->setPrecio(3500);
    producto4->setStock(20);

    inventario.push_back(producto1);
    inventario.push_back(producto2);
    inventario.push_back(producto3);
    inventario.push_back(producto4);


    Cliente *cliente1 = new Cliente();
    Cliente *cliente2 = new Cliente();
    Cliente *cliente3 = new Cliente();
    Cliente *cliente4 = new Cliente();

    cliente1->setCliente("Paola Ceballos");
    cliente1->setId(112);

    cliente2->setCliente("Andres Quintana");
    cliente2->setId(124);

    cliente3->setCliente("Sebastian Diaz");
    cliente3->setId(231);

    cliente4->setCliente("Beatriz Ortiz");
    cliente4->setId(501);

    clientes.push_back(cliente1);
    clientes.push_back(cliente2);
    clientes.push_back(cliente3);
    clientes.push_back(cliente4);



}
void Tienda::agregarProducto(string nombre,int codigo, float precio, int stockInicial){
    inventario.push_back(new Producto(nombre, codigo, precio, stockInicial));
    cout << "Se agrego correctamente al inventario\n";

}
void Tienda::agregarCliente(int id, string nombreCli){
    clientes.push_back(new Cliente(id, nombreCli));
    cout << "Se agrego el cliente Correctamente\n";
}
void Tienda::registrarVenta(int idCliente) {
    Cliente* cliente = buscarCliente(idCliente);
    if (cliente == nullptr) {
        cout << "No se encontró el cliente!\n";
        return;
    }

    cout << "\n===== Productos Disponibles =====\n";
    listarProductos();

    int codigoProducto, cantidad;
    cout << "Ingrese el código del producto: ";
    cin >> codigoProducto;

    Producto* producto = buscarProducto(codigoProducto);
    if (producto == nullptr) {
        cout << "Producto no encontrado!\n";
        return;
    }

    cout << "Ingrese la cantidad a comprar: ";
    cin >> cantidad;

    if (producto->getStock() < cantidad) {
        cout << "Stock insuficiente!\n";
        return;
    }

    // Descontar del stock
    producto->descontarStock(cantidad);

    // Crear la venta y agregar el producto
    Venta* nuevaVenta = new Venta(cliente);
    nuevaVenta->agregarProducto(producto, cantidad);

    // Guardar la venta en la tienda y en el historial del cliente
    ventas.push_back(nuevaVenta);
    cliente->agregarCompra(nuevaVenta);

    cout << "Venta registrada con éxito!\n";
}

void Tienda::reabastecerProducto(int codigoProducto, int cantidad){
    Producto* producto = buscarProducto(codigoProducto);
    if (producto) {
        producto->agregarStock(cantidad);
        cout << " Se reabastecio correctamente.\n";
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
        cout << "Precio: " <<  inventario[i]->getPrecio()<< endl;
        cout << "Stock: " <<  inventario[i]->getStock()<< endl;
        cont++;
        cout << endl;
    }
}
void Tienda::listarClientes() {
    int cont = 0;
    for (int i = 0; i < clientes.size(); i++){
        cout << "Cliente #" << cont << endl;
        cout << "Codigo: "<< clientes[i]->getId()<<endl;
        cout << "Nombre Completo: " << clientes[i]->getCliente()<<endl;
        cont++;
        cout << endl;
    }
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
        clientes.clear();
    }
    for (int i = 0; i < inventario.size(); i++) {
        delete inventario[i];
        inventario.clear();
    }
    for (int i = 0; i < ventas.size(); i++) {
        delete ventas[i];
        ventas.clear();
    }
    cout << "LLame al destructor, elimine todo y termine" << endl;
}