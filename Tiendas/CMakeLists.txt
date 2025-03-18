cmake_minimum_required(VERSION 3.30)
project(Tiendas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tiendas main.cpp
        src/Producto.cpp
        src/Producto.h
        src/Venta.cpp
        src/Venta.h
        src/Cliente.cpp
        src/Cliente.h
        src/Tienda.cpp
        src/Tienda.h)
