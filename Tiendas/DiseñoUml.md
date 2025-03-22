## DISEÑO UML 
    classDiagram
    class Producto {
    - string nombre
      - int num
      - int precio
      - int stock
      + Producto(string nombre, int num, int precio, int stock)
      + bool descontarStock(int cantidad)
      + void agregarStock(int cantidad)
      }
    
          class Cliente{
              - int id;
              - string nombre
              - vector<Ventas>compras
              + void agregarCompra(Venta* venta)
              + void mostrarHistorialCompras()
          }
    
          class Venta {
              - int id;
              - Cliente cliente
              - vector<Producto>productosVendidos
              + Venta(Cliente* cliente)
              + void agregarProductoVendido(Producto* producto, int cantidad)
              + float calcularTotal()
              + void mostrarDetalleVenta()
          }
          class Tienda{
              - Cliente cliente;
              - Producto producto;
              - Venta venta;
              + void agregarProducto(string codigo, string nombre, float precio, int stockInicial)
              + void registrarVenta(int idCliente)
              + void reabastecerProducto(string codigoProducto, int cantidad)
              + Producto* buscarProducto(string codigo)
              + Cliente* buscarCliente(int idCliente)
              + void listarProductos()
              + void mostrarVentas()
              + float calcularValorInventario()
          }  
    
          Tienda o-- Producto
          Tienda o-- Venta
          Tienda o-- Cliente
          Cliente --> Venta
          Venta --> Producto
