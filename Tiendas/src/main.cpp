#include <iostream>
#include "Tienda.h"

using namespace std;
void menuProductos( Tienda &Tienda) {
    int opcion;
    do {
        cout << "\n===== MENU PRODUCTOS =====\n";
        cout << "1. Agregar nuevo producto\n";
        cout << "2. Buscar producto por codigo\n";
        cout << "3. Listar todos los productos\n";
        cout << "4. Reabastecer producto\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "6. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string name;
                int code,stock;
                float prize;
                cout << "\n==== Agregar producto =====\n";
                cout << "Nombre: ";
                cin >> name;
                cout << "Codigo: ";
                cin >> code;
                cout <<"Precio: ";
                cin >> prize;
                cout <<"Cantidad: ";
                cin >> stock;
                Tienda.agregarProducto(name, code, prize, stock);
                break;

            }
            case 2: {
                cout << "\n==== Buscar producto por codigo =====\n";
                int cod;
                cout << "Ingresa el codigo: ";
                cin >> cod;
                Producto* encontrado = Tienda.buscarProducto(cod);
                if (encontrado) {
                    cout << "Producto encontrado: " << encontrado->getProducto() << endl;
                } else {
                    cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 3:
                cout << "\n==== Lista de productos =====\n";

                Tienda.listarProductos();
                break;
            case 4: {
                cout << "\n==== Rebastecer Producto =====\n";
                int cod, cant;
                cout << "Ingresa el codigo del prodcto: ";
                cin >> cod;
                cout << "Ingresa la cantidad del producto: ";
                cin >> cant;
                Tienda.reabastecerProducto(cod, cant);

            }
            case 5: {
                cout << "\n==== Total dinero del Inventario =====\n";
                cout <<"Este es el dinero total de todos los productos: $ " << Tienda.calcularValorInventario();
                break;
            }
            case 6:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 6);
}
void menuClientes(Tienda &tienda) {
    int opcion;
    do {
        cout << "\n===== MENU CLIENTES =====\n";
        cout << "1. Registrar nuevo cliente\n";
        cout << "2. Buscar cliente por ID\n";
        cout << "3. Listar todos los clientes\n";
        cout << "4. Mostrar historial de compras\n";
        cout << "5. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n==== Agregar Cliente =====\n";
                int idCl;
                string name;
                cout << "Ingrese ID del cliente: ";
                cin >> idCl;
                cin.ignore();
                cout << "Ingrese nombre del cliente: ";
                getline(cin, name);
                tienda.agregarCliente(idCl, name);
                break;
            }
            case 2: {
                cout << "\n==== Buscar Cliente por ID =====\n";
                int id;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                Cliente *cliente = tienda.buscarCliente(id);
                if (cliente) {
                    cout << "Cliente encontrado: " << cliente->getCliente() << endl;
                } else {
                    cout << "Cliente no encontrado.\n";
                }
                break;
            }
            case 3:
                cout << "\n==== Lista de Clientes =====\n";
                tienda.listarClientes();
                break;
            case 4: {
                cout << "\n==== Mostrar Historial de compras =====\n";
                int id;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                Cliente *cliente = tienda.buscarCliente(id);
                if (cliente) {
                    cliente->mostrarHistorialCompras();
                } else {
                    cout << "Cliente no encontrado.\n";
                }
                break;

            }
            case 5:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);
}
void menuVentas(Tienda &tienda) {
    int opcion;
    do {
        cout << "\n===== MENU VENTAS =====\n";
        cout << "1. Registrar nueva venta\n";
        cout << "2. Ver historial de ventas\n";
        cout << "3. Mostrar detalles de una venta\n";
        cout << "4. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                Cliente *cliente = tienda.buscarCliente(id);
                if (cliente) {
                    cout << "\n===== Productos Disponibles =====\n";
                    tienda.listarProductos();
                    int codigoItem;
                    cout << "Ingrese el codigo del producto: ";
                    cin >> codigoItem;
                    Producto *producto = tienda.buscarProducto(codigoItem);
                    if (producto) {
                        int cantidadProducto;
                        cout << "Ingrese la cantidad del producto: ";
                        cin >> cantidadProducto;
                        if (producto->getStock() >= cantidadProducto) {
                            producto->descontarStock(cantidadProducto);
                            tienda.registrarVenta(id);
                            cout << "Venta registrada con exito!\n";
                        } else {
                            cout << "Stock insuficiente!\n";
                        }
                    } else {
                        cout << "Producto no encontrado!\n";
                    }
                } else {
                    cout << "No se encuentra ningun cliente con ese ccdigo!!\n";
                }
                break;
            }
            case 2: {
                cout << "\n===== Historial de Ventas =====\n";
                tienda.mostrarVentas();
                break;
            }

            case 3:{
                cout << "\n===== Detalles de Ventas =====\n";
                int idCl;
                cout << "Ingresa en id del cliente: ";
                cin >> idCl;
                Cliente *cliente = tienda.buscarCliente(idCl);
                if (cliente) {
                    cout << "Este es el Historial de compras del cliente\n";
                    cliente->mostrarHistorialCompras();
                } else {
                    cout << "No se encuentra el cliente";
                }
                break;
            }
                case 4:
                cout << "Volviendo al menu principal...\n";
                break;

            default:
                cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 4);
}


void menuPrincipal(Tienda &tienda) {
    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Gestion de Clientes\n";
        cout << "2. Gestion de Productos\n";
        cout << "3. Gestion de Ventas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuClientes(tienda);
                break;
            case 2:
                menuProductos(tienda);
                break;
            case 3:
                menuVentas(tienda);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 4);
}
int main(){
    Tienda tienda;
    menuPrincipal(tienda);
    return 0; 
}