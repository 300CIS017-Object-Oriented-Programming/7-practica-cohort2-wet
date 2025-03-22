#include <iostream>
using namespace std;
void menuProductos() {
    int opcion;
    do {
        cout << "\n===== MENU PRODUCTOS =====\n";
        cout << "1. Agregar nuevo producto\n";
        cout << "2. Buscar producto por código\n";
        cout << "3. Listar todos los productos\n";
        cout << "4. Reabastecer producto\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "6. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int codigo;
                float precio;
                int stock;
                break;

            }
            case 2: {

                break;
            }
            case 3:
                break;
            case 4: {

            }
            case 5: {

                break;
            }
            case 6:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 6);
}
void menuClientes() {
    int opcion;
    do {
        cout << "\n===== MENU CLIENTES =====\n";
        cout << "1. Registrar nuevo cliente\n";
        cout << "2. Buscar cliente por ID\n";
        cout << "3. Listar todos los clientes\n";
        cout << "4. Mostrar historial de compras\n";
        cout << "5. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                string nombre;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                cin.ignore();
                cout << "Ingrese nombre del cliente: ";
                getline(cin, nombre);
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                break;
            }
            case 3:
                break;
            case 4: {
                int id;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                break;
            }
            case 5:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 5);
}
void menuVentas() {
    int opcion;
    do {
        cout << "\n===== MENU VENTAS =====\n";
        cout << "1. Registrar nueva venta\n";
        cout << "2. Ver historial de ventas\n";
        cout << "3. Mostrar detalles de una venta\n";
        cout << "4. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion){
            case 1:
                int idCliente;
                cout << "Ingrese ID del cliente: ";
                cin >> idCliente;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 4);
}

void menuPrincipal() {
    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Gestión de Clientes\n";
        cout << "2. Gestión de Productos\n";
        cout << "3. Gestión de Ventas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuProductos();
                break;
            case 3:
                menuVentas();
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 4);
}
int main(){
    menuPrincipal();
    return 0; 
}